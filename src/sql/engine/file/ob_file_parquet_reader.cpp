/*
 * Copyright (c) 2025 OceanBase.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define USING_LOG_PREFIX SQL_ENG

#include "sql/engine/file/ob_file_parquet_reader.h"
#include "sql/engine/file/ob_file_reader.h"

#include <errno.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace oceanbase
{
namespace sql
{

using namespace common;

namespace
{

// ---------------------------------------------------------------------------
// thrift compact protocol
// ---------------------------------------------------------------------------
const int32_t THRIFT_BOOL_TRUE = 1;
const int32_t THRIFT_BOOL_FALSE = 2;
const int32_t THRIFT_BYTE = 3;
const int32_t THRIFT_I16 = 4;
const int32_t THRIFT_I32 = 5;
const int32_t THRIFT_I64 = 6;
const int32_t THRIFT_DOUBLE = 7;
const int32_t THRIFT_BINARY = 8;
const int32_t THRIFT_LIST = 9;
const int32_t THRIFT_SET = 10;
const int32_t THRIFT_MAP = 11;
const int32_t THRIFT_STRUCT = 12;

class ThriftCompactReader
{
public:
  ThriftCompactReader(const char *buf, const int64_t len)
    : buf_(buf), len_(len), pos_(0), ok_(true), last_field_id_(0) {}
  bool ok() const { return ok_; }
  bool eof() const { return pos_ >= len_; }
  int64_t pos() const { return pos_; }
  const char *buf() const { return buf_; }
  void fail() { ok_ = false; }
  // every thrift struct restarts the field id delta state, the parent state must be restored
  void start_struct() { last_field_id_ = 0; }
  int64_t save_field_id() const { return last_field_id_; }
  void restore_field_id(const int64_t id) { last_field_id_ = id; }
  uint8_t read_byte()
  {
    if (pos_ >= len_) {
      ok_ = false;
      return 0;
    }
    return static_cast<uint8_t>(buf_[pos_++]);
  }
  uint64_t read_uvarint()
  {
    uint64_t result = 0;
    int32_t shift = 0;
    while (ok_ && shift < 64) {
      const uint8_t b = read_byte();
      result |= static_cast<uint64_t>(b & 0x7f) << shift;
      if (0 == (b & 0x80)) {
        break;
      }
      shift += 7;
    }
    return result;
  }
  int64_t read_zigzag()
  {
    const uint64_t v = read_uvarint();
    return static_cast<int64_t>((v >> 1) ^ (~(v & 1) + 1));
  }
  bool read_binary(ObString &s)
  {
    const uint64_t n = read_uvarint();
    if (!ok_ || n > static_cast<uint64_t>(len_ - pos_)) {
      ok_ = false;
    } else {
      s.assign_ptr(buf_ + pos_, static_cast<int32_t>(n));
      pos_ += static_cast<int64_t>(n);
    }
    return ok_;
  }
  // Read a struct field header. Returns false on STOP or error.
  bool read_field_header(int64_t &field_id, int32_t &type)
  {
    bool ret = true;
    const uint8_t h = read_byte();
    if (!ok_ || 0 == h) {
      ret = false;
    } else {
      type = h & 0x0f;
      const int32_t delta = (h >> 4) & 0x0f;
      if (0 == delta) {
        field_id = read_zigzag();
      } else {
        field_id = last_field_id_ + delta;
      }
      last_field_id_ = field_id;
      if (!ok_) {
        ret = false;
      }
    }
    return ret;
  }
  bool skip(int32_t type)
  {
    bool ret = true;
    switch (type) {
      case THRIFT_BOOL_TRUE:
      case THRIFT_BOOL_FALSE:
        break;
      case THRIFT_BYTE:
        read_byte();
        break;
      case THRIFT_I16:
      case THRIFT_I32:
      case THRIFT_I64:
        read_zigzag();
        break;
      case THRIFT_DOUBLE:
        pos_ += 8;
        break;
      case THRIFT_BINARY: {
        const uint64_t n = read_uvarint();
        pos_ += static_cast<int64_t>(n);
        break;
      }
      case THRIFT_LIST:
      case THRIFT_SET: {
        const uint8_t h = read_byte();
        int32_t elem_type = h & 0x0f;
        uint64_t n = (h >> 4) & 0x0f;
        if (15 == n) {
          n = read_uvarint();
        }
        if (THRIFT_BOOL_TRUE == elem_type || THRIFT_BOOL_FALSE == elem_type) {
          pos_ += static_cast<int64_t>(n);
        } else {
          for (uint64_t i = 0; ok_ && i < n; ++i) {
            if (!skip(elem_type)) {
              break;
            }
          }
        }
        break;
      }
      case THRIFT_MAP: {
        const uint64_t n = read_uvarint();
        if (n > 0) {
          const uint8_t h = read_byte();
          const int32_t kt = (h >> 4) & 0x0f;
          const int32_t vt = h & 0x0f;
          for (uint64_t i = 0; ok_ && i < n; ++i) {
            skip(kt);
            skip(vt);
          }
        }
        break;
      }
      case THRIFT_STRUCT: {
        const int64_t saved = last_field_id_;
        last_field_id_ = 0;
        int64_t fid = 0;
        int32_t t = 0;
        while (ok_ && read_field_header(fid, t)) {
          skip(t);
        }
        last_field_id_ = saved;
        break;
      }
      default:
        ok_ = false;
        ret = false;
        break;
    }
    if (pos_ > len_) {
      ok_ = false;
      ret = false;
    }
    return ret;
  }
  bool read_list_header(int32_t &elem_type, uint64_t &n)
  {
    const uint8_t h = read_byte();
    elem_type = h & 0x0f;
    n = (h >> 4) & 0x0f;
    if (15 == n) {
      n = read_uvarint();
    }
    return ok_;
  }
private:
  const char *buf_;
  int64_t len_;
  int64_t pos_;
  bool ok_;
  int64_t last_field_id_;
};

struct ThriftStructScope
{
  explicit ThriftStructScope(ThriftCompactReader &r) : r_(r), saved_(r.save_field_id())
  {
    r_.start_struct();
  }
  ~ThriftStructScope() { r_.restore_field_id(saved_); }
  ThriftCompactReader &r_;
  int64_t saved_;
};

// ---------------------------------------------------------------------------
// snappy raw block decompression
// ---------------------------------------------------------------------------
int snappy_uncompress(const char *src, const int64_t src_len, char *dst,
                      const int64_t dst_len, int64_t &written)
{
  int ret = OB_SUCCESS;
  int64_t ip = 0;
  int64_t op = 0;
  uint64_t expected = 0;
  int32_t shift = 0;
  written = 0;
  while (ip < src_len) {
    const uint8_t b = static_cast<uint8_t>(src[ip++]);
    expected |= static_cast<uint64_t>(b & 0x7f) << shift;
    if (0 == (b & 0x80)) {
      break;
    }
    shift += 7;
  }
  if (expected > static_cast<uint64_t>(dst_len)) {
    ret = OB_INVALID_DATA;
  }
  while (OB_SUCC(ret) && ip < src_len) {
    const uint8_t tag = static_cast<uint8_t>(src[ip++]);
    const int32_t kind = tag & 0x03;
    if (0 == kind) {
      uint64_t len = (tag >> 2) + 1;
      if (len > 60) {
        const int32_t extra = static_cast<int32_t>(len - 60);
        uint64_t v = 0;
        for (int32_t i = 0; OB_SUCC(ret) && i < extra; ++i) {
          if (ip >= src_len) {
            ret = OB_INVALID_DATA;
          } else {
            v |= static_cast<uint64_t>(static_cast<uint8_t>(src[ip++])) << (8 * i);
          }
        }
        len = v + 1;
      }
      if (OB_FAIL(ret)) {
      } else if (ip + static_cast<int64_t>(len) > src_len
                 || op + static_cast<int64_t>(len) > dst_len) {
        ret = OB_INVALID_DATA;
      } else {
        MEMCPY(dst + op, src + ip, len);
        ip += static_cast<int64_t>(len);
        op += static_cast<int64_t>(len);
      }
    } else {
      uint64_t len = 0;
      uint64_t offset = 0;
      if (1 == kind) {
        len = ((tag >> 2) & 0x07) + 4;
        if (ip >= src_len) {
          ret = OB_INVALID_DATA;
        } else {
          offset = (static_cast<uint64_t>(tag) >> 5 << 8) | static_cast<uint8_t>(src[ip++]);
        }
      } else if (2 == kind) {
        len = (tag >> 2) + 1;
        if (ip + 2 > src_len) {
          ret = OB_INVALID_DATA;
        } else {
          offset = static_cast<uint8_t>(src[ip]) | (static_cast<uint8_t>(src[ip + 1]) << 8);
          ip += 2;
        }
      } else {
        len = (tag >> 2) + 1;
        if (ip + 4 > src_len) {
          ret = OB_INVALID_DATA;
        } else {
          offset = static_cast<uint8_t>(src[ip]) | (static_cast<uint8_t>(src[ip + 1]) << 8)
                   | (static_cast<uint8_t>(src[ip + 2]) << 16)
                   | (static_cast<uint64_t>(static_cast<uint8_t>(src[ip + 3])) << 24);
          ip += 4;
        }
      }
      if (OB_FAIL(ret)) {
      } else if (0 == offset || offset > static_cast<uint64_t>(op)
                 || op + static_cast<int64_t>(len) > dst_len) {
        ret = OB_INVALID_DATA;
      } else {
        for (uint64_t i = 0; i < len; ++i) {
          dst[op] = dst[op - offset];
          ++op;
        }
      }
    }
  }
  if (OB_SUCC(ret) && op != static_cast<int64_t>(expected)) {
    ret = OB_INVALID_DATA;
  }
  if (OB_SUCC(ret)) {
    written = op;
  }
  return ret;
}

// ---------------------------------------------------------------------------
// parquet metadata
// ---------------------------------------------------------------------------
const int32_t PARQUET_PHYSICAL_BOOLEAN = 0;
const int32_t PARQUET_PHYSICAL_INT32 = 1;
const int32_t PARQUET_PHYSICAL_INT64 = 2;
const int32_t PARQUET_PHYSICAL_INT96 = 3;
const int32_t PARQUET_PHYSICAL_FLOAT = 4;
const int32_t PARQUET_PHYSICAL_DOUBLE = 5;
const int32_t PARQUET_PHYSICAL_BYTE_ARRAY = 6;
const int32_t PARQUET_PHYSICAL_FIXED_LEN = 7;

const int32_t PARQUET_REP_REQUIRED = 0;
const int32_t PARQUET_REP_OPTIONAL = 1;
const int32_t PARQUET_REP_REPEATED = 2;

const int32_t PARQUET_CODEC_UNCOMPRESSED = 0;
const int32_t PARQUET_CODEC_SNAPPY = 1;

const int32_t PARQUET_ENC_PLAIN = 0;
const int32_t PARQUET_ENC_PLAIN_DICTIONARY = 2;
const int32_t PARQUET_ENC_RLE = 3;
const int32_t PARQUET_ENC_DICTIONARY = 8;

const int32_t PARQUET_CONVERTED_UTF8 = 0;
const int32_t PARQUET_CONVERTED_DECIMAL = 5;
const int32_t PARQUET_CONVERTED_DATE = 6;
const int32_t PARQUET_CONVERTED_TIME_MILLIS = 7;
const int32_t PARQUET_CONVERTED_TIMESTAMP_MILLIS = 9;
const int32_t PARQUET_CONVERTED_TIMESTAMP_MICROS = 10;

struct ParquetLeafColumn
{
  ParquetLeafColumn()
    : name_(), physical_type_(-1), repetition_type_(PARQUET_REP_REQUIRED),
      converted_type_(-1), type_length_(0), scale_(0), precision_(0), max_def_level_(0) {}
  ObString name_;
  int32_t physical_type_;
  int32_t repetition_type_;
  int32_t converted_type_;
  int32_t type_length_;
  int32_t scale_;
  int32_t precision_;
  int32_t max_def_level_;
};

struct ParquetColumnChunkMeta
{
  ParquetColumnChunkMeta()
    : physical_type_(-1), codec_(-1), num_values_(0), data_page_offset_(0),
      dictionary_page_offset_(-1), total_compressed_size_(0), file_offset_(0) {}
  int32_t physical_type_;
  int32_t codec_;
  int64_t num_values_;
  int64_t data_page_offset_;
  int64_t dictionary_page_offset_;
  int64_t total_compressed_size_;
  int64_t file_offset_;
};

struct ParquetRowGroupMeta
{
  ParquetRowGroupMeta() : num_rows_(0), file_offset_(0), columns_() {}
  int64_t num_rows_;
  int64_t file_offset_;
  ObSEArray<ParquetColumnChunkMeta, 16> columns_;
};

struct ParquetFileMeta
{
  ParquetFileMeta() : leaves_(), row_groups_(), num_rows_(0), nested_(false), repeated_(false) {}
  ObSEArray<ParquetLeafColumn, 16> leaves_;
  ObSEArray<ParquetRowGroupMeta, 16> row_groups_;
  int64_t num_rows_;
  bool nested_;
  bool repeated_;
};

int parse_schema_element(ThriftCompactReader &r, ParquetLeafColumn &leaf, int64_t &num_children)
{
  int ret = OB_SUCCESS;
  ThriftStructScope struct_scope(r);
  int32_t physical_type = -1;
  int32_t repetition_type = PARQUET_REP_REQUIRED;
  int32_t converted_type = -1;
  ObString name;
  int64_t last = 0;
  int64_t fid = 0;
  int32_t type = 0;
  num_children = 0;
  while (OB_SUCC(ret) && r.ok() && r.read_field_header(fid, type)) {
    switch (fid) {
      case 1: physical_type = static_cast<int32_t>(r.read_zigzag()); break;
      case 2: leaf.type_length_ = static_cast<int32_t>(r.read_zigzag()); break;
      case 3: repetition_type = static_cast<int32_t>(r.read_zigzag()); break;
      case 4: r.read_binary(name); break;
      case 5: num_children = r.read_zigzag(); break;
      case 6: converted_type = static_cast<int32_t>(r.read_zigzag()); break;
      case 7: leaf.scale_ = static_cast<int32_t>(r.read_zigzag()); break;
      case 8: leaf.precision_ = static_cast<int32_t>(r.read_zigzag()); break;
      default: r.skip(type); break;
    }
  }
  if (!r.ok()) {
    ret = OB_INVALID_DATA;
  } else {
    leaf.physical_type_ = physical_type;
    leaf.repetition_type_ = repetition_type;
    leaf.converted_type_ = converted_type;
    leaf.name_ = name;
  }
  return ret;
}

int parse_column_meta_data(ThriftCompactReader &r, ParquetColumnChunkMeta &meta)
{
  int ret = OB_SUCCESS;
  ThriftStructScope struct_scope(r);
  int64_t last = 0;
  int64_t fid = 0;
  int32_t type = 0;
  while (OB_SUCC(ret) && r.ok() && r.read_field_header(fid, type)) {
    switch (fid) {
      case 1: meta.physical_type_ = static_cast<int32_t>(r.read_zigzag()); break;
      case 4: meta.codec_ = static_cast<int32_t>(r.read_zigzag()); break;
      case 5: meta.num_values_ = r.read_zigzag(); break;
      case 7: meta.total_compressed_size_ = r.read_zigzag(); break;
      case 9: meta.data_page_offset_ = r.read_zigzag(); break;
      case 11: meta.dictionary_page_offset_ = r.read_zigzag(); break;
      default: r.skip(type); break;
    }
  }
  if (!r.ok()) {
    ret = OB_INVALID_DATA;
  }
  return ret;
}

int parse_column_chunk(ThriftCompactReader &r, ParquetColumnChunkMeta &meta)
{
  int ret = OB_SUCCESS;
  ThriftStructScope struct_scope(r);
  int64_t last = 0;
  int64_t fid = 0;
  int32_t type = 0;
  while (OB_SUCC(ret) && r.ok() && r.read_field_header(fid, type)) {
    if (3 == fid && THRIFT_STRUCT == type) {
      if (OB_FAIL(parse_column_meta_data(r, meta))) {
      }
    } else if (2 == fid && THRIFT_I64 == type) {
      meta.file_offset_ = r.read_zigzag();
    } else {
      r.skip(type);
    }
  }
  if (!r.ok()) {
    ret = OB_INVALID_DATA;
  }
  return ret;
}

int parse_row_group(ThriftCompactReader &r, ParquetRowGroupMeta &rg)
{
  int ret = OB_SUCCESS;
  ThriftStructScope struct_scope(r);
  int64_t last = 0;
  int64_t fid = 0;
  int32_t type = 0;
  while (OB_SUCC(ret) && r.ok() && r.read_field_header(fid, type)) {
    if (1 == fid && THRIFT_LIST == type) {
      int32_t elem_type = 0;
      uint64_t n = 0;
      if (!r.read_list_header(elem_type, n)) {
        ret = OB_INVALID_DATA;
      } else {
        for (uint64_t i = 0; OB_SUCC(ret) && i < n; ++i) {
          ParquetColumnChunkMeta meta;
          if (OB_FAIL(parse_column_chunk(r, meta))) {
          } else if (OB_FAIL(rg.columns_.push_back(meta))) {
          }
        }
      }
    } else if (3 == fid && THRIFT_I64 == type) {
      rg.num_rows_ = r.read_zigzag();
    } else if (5 == fid && THRIFT_I64 == type) {
      rg.file_offset_ = r.read_zigzag();
    } else {
      r.skip(type);
    }
  }
  if (!r.ok()) {
    ret = OB_INVALID_DATA;
  }
  return ret;
}

// Parse the FileMetaData struct (footer already read into %buf).
int parse_file_meta(const char *buf, const int64_t len, ObIAllocator &alloc, ParquetFileMeta &meta)
{
  int ret = OB_SUCCESS;
  ThriftCompactReader r(buf, len);
  ThriftStructScope struct_scope(r);
  int64_t last = 0;
  int64_t fid = 0;
  int32_t type = 0;
  int64_t schema_element_index = 0;
  while (OB_SUCC(ret) && r.ok() && r.read_field_header(fid, type)) {
    if (2 == fid && THRIFT_LIST == type) {
      int32_t elem_type = 0;
      uint64_t n = 0;
      if (!r.read_list_header(elem_type, n)) {
        ret = OB_INVALID_DATA;
      } else {
        for (uint64_t i = 0; OB_SUCC(ret) && i < n; ++i) {
          ParquetLeafColumn leaf;
          int64_t num_children = 0;
          if (OB_FAIL(parse_schema_element(r, leaf, num_children))) {
          } else if (0 == schema_element_index) {
            // root element, ignore
          } else if (num_children > 0) {
            meta.nested_ = true;
          } else {
            if (PARQUET_REP_REPEATED == leaf.repetition_type_) {
              meta.repeated_ = true;
            }
            leaf.max_def_level_ = (PARQUET_REP_OPTIONAL == leaf.repetition_type_) ? 1 : 0;
            ObString name;
            if (OB_FAIL(ob_write_string(alloc, leaf.name_, name))) {
            } else {
              leaf.name_ = name;
              if (OB_FAIL(meta.leaves_.push_back(leaf))) {
              }
            }
          }
          ++schema_element_index;
        }
      }
    } else if (3 == fid && THRIFT_I64 == type) {
      meta.num_rows_ = r.read_zigzag();
    } else if (4 == fid && THRIFT_LIST == type) {
      int32_t elem_type = 0;
      uint64_t n = 0;
      if (!r.read_list_header(elem_type, n)) {
        ret = OB_INVALID_DATA;
      } else {
        for (uint64_t i = 0; OB_SUCC(ret) && i < n; ++i) {
          ParquetRowGroupMeta rg;
          if (OB_FAIL(parse_row_group(r, rg))) {
          } else if (OB_FAIL(meta.row_groups_.push_back(rg))) {
          }
        }
      }
    } else {
      r.skip(type);
    }
  }
  if (OB_FAIL(ret)) {
  } else if (!r.ok()) {
    ret = OB_INVALID_DATA;
  } else if (meta.nested_ || meta.repeated_) {
    ret = OB_NOT_SUPPORTED;
    LOG_USER_ERROR(OB_NOT_SUPPORTED, "nested or repeated parquet column");
  } else if (meta.leaves_.empty()) {
    ret = OB_INVALID_DATA;
  }
  return ret;
}

// ---------------------------------------------------------------------------
// helpers
// ---------------------------------------------------------------------------
int read_exact(FILE *fp, const int64_t offset, char *buf, const int64_t len)
{
  int ret = OB_SUCCESS;
  if (0 != ::fseek(fp, static_cast<long>(offset), SEEK_SET)) {
    ret = OB_IO_ERROR;
  } else if (len > 0 && len != static_cast<int64_t>(::fread(buf, 1, len, fp))) {
    ret = OB_IO_ERROR;
  }
  return ret;
}

// days -> YYYY-MM-DD
void civil_from_days(const int64_t z_in, int64_t &y, int64_t &m, int64_t &d)
{
  int64_t z = z_in + 719468;
  const int64_t era = (z >= 0 ? z : z - 146096) / 146097;
  const int64_t doe = z - era * 146097;
  const int64_t yoe = (doe - doe / 1460 + doe / 36524 - doe / 146096) / 365;
  y = yoe + era * 400;
  const int64_t doy = doe - (365 * yoe + yoe / 4 - yoe / 100);
  const int64_t mp = (5 * doy + 2) / 153;
  d = doy - (153 * mp + 2) / 5 + 1;
  m = mp + (mp < 10 ? 3 : -9);
  y += (m <= 2);
}

int append_date_text(ObIAllocator &alloc, const int32_t days, ObString &text)
{
  int ret = OB_SUCCESS;
  int64_t y = 0;
  int64_t m = 0;
  int64_t d = 0;
  char tmp[16];
  civil_from_days(days, y, m, d);
  const int64_t n = snprintf(tmp, sizeof(tmp), "%04lld-%02lld-%02lld",
                             static_cast<long long>(y), static_cast<long long>(m),
                             static_cast<long long>(d));
  char *buf = static_cast<char *>(alloc.alloc(n + 1));
  if (OB_ISNULL(buf)) {
    ret = OB_ALLOCATE_MEMORY_FAILED;
  } else {
    MEMCPY(buf, tmp, n + 1);
    text.assign_ptr(buf, static_cast<int32_t>(n));
  }
  return ret;
}

int append_datetime_text(ObIAllocator &alloc, const int64_t usec, ObString &text)
{
  int ret = OB_SUCCESS;
  int64_t days = usec / 86400000000LL;
  int64_t rest = usec % 86400000000LL;
  if (rest < 0) {
    rest += 86400000000LL;
    --days;
  }
  int64_t y = 0;
  int64_t m = 0;
  int64_t d = 0;
  civil_from_days(days, y, m, d);
  const int64_t hh = rest / 3600000000LL;
  rest %= 3600000000LL;
  const int64_t mm = rest / 60000000LL;
  rest %= 60000000LL;
  const int64_t ss = rest / 1000000LL;
  const int64_t frac = rest % 1000000LL;
  char tmp[40];
  int64_t n = 0;
  if (0 == frac) {
    n = snprintf(tmp, sizeof(tmp), "%04lld-%02lld-%02lld %02lld:%02lld:%02lld",
                 static_cast<long long>(y), static_cast<long long>(m), static_cast<long long>(d),
                 static_cast<long long>(hh), static_cast<long long>(mm), static_cast<long long>(ss));
  } else {
    n = snprintf(tmp, sizeof(tmp), "%04lld-%02lld-%02lld %02lld:%02lld:%02lld.%06lld",
                 static_cast<long long>(y), static_cast<long long>(m), static_cast<long long>(d),
                 static_cast<long long>(hh), static_cast<long long>(mm), static_cast<long long>(ss),
                 static_cast<long long>(frac));
  }
  char *buf = static_cast<char *>(alloc.alloc(n + 1));
  if (OB_ISNULL(buf)) {
    ret = OB_ALLOCATE_MEMORY_FAILED;
  } else {
    MEMCPY(buf, tmp, n + 1);
    text.assign_ptr(buf, static_cast<int32_t>(n));
  }
  return ret;
}

int append_int_text(ObIAllocator &alloc, const int64_t value, ObString &text)
{
  int ret = OB_SUCCESS;
  char tmp[32];
  const int64_t n = snprintf(tmp, sizeof(tmp), "%lld", static_cast<long long>(value));
  char *buf = static_cast<char *>(alloc.alloc(n + 1));
  if (OB_ISNULL(buf)) {
    ret = OB_ALLOCATE_MEMORY_FAILED;
  } else {
    MEMCPY(buf, tmp, n + 1);
    text.assign_ptr(buf, static_cast<int32_t>(n));
  }
  return ret;
}

int append_double_text(ObIAllocator &alloc, const double value, ObString &text)
{
  int ret = OB_SUCCESS;
  char tmp[64];
  const int64_t n = snprintf(tmp, sizeof(tmp), "%.17g", value);
  char *buf = static_cast<char *>(alloc.alloc(n + 1));
  if (OB_ISNULL(buf)) {
    ret = OB_ALLOCATE_MEMORY_FAILED;
  } else {
    MEMCPY(buf, tmp, n + 1);
    text.assign_ptr(buf, static_cast<int32_t>(n));
  }
  return ret;
}

int append_bytes_text(ObIAllocator &alloc, const char *ptr, const int64_t len, ObString &text)
{
  int ret = OB_SUCCESS;
  char *buf = static_cast<char *>(alloc.alloc(len + 1));
  if (OB_ISNULL(buf)) {
    ret = OB_ALLOCATE_MEMORY_FAILED;
  } else {
    if (len > 0) {
      MEMCPY(buf, ptr, len);
    }
    buf[len] = '\0';
    text.assign_ptr(buf, static_cast<int32_t>(len));
  }
  return ret;
}

// Convert one physical PLAIN value to its text representation.
int plain_value_to_text(const ParquetLeafColumn &leaf, const char *ptr, const int64_t avail,
                        int64_t &consumed, ObIAllocator &alloc, ObString &text)
{
  int ret = OB_SUCCESS;
  consumed = 0;
  switch (leaf.physical_type_) {
    case PARQUET_PHYSICAL_BOOLEAN: {
      if (avail < 1) {
        ret = OB_INVALID_DATA;
      } else {
        consumed = 1;
        if (OB_FAIL(append_bytes_text(alloc, (ptr[0] & 1) ? "true" : "false",
                                      (ptr[0] & 1) ? 4 : 5, text))) {
        }
      }
      break;
    }
    case PARQUET_PHYSICAL_INT32: {
      if (avail < 4) {
        ret = OB_INVALID_DATA;
      } else {
        int32_t v = 0;
        MEMCPY(&v, ptr, 4);
        consumed = 4;
        if (PARQUET_CONVERTED_DATE == leaf.converted_type_) {
          if (OB_FAIL(append_date_text(alloc, v, text))) {
          }
        } else if (PARQUET_CONVERTED_TIME_MILLIS == leaf.converted_type_) {
          char tmp[32];
          const int64_t n = snprintf(tmp, sizeof(tmp), "%02d:%02d:%02d.%03d",
                                     static_cast<int>(v / 3600000),
                                     static_cast<int>((v / 60000) % 60),
                                     static_cast<int>((v / 1000) % 60),
                                     static_cast<int>(v % 1000));
          if (OB_FAIL(append_bytes_text(alloc, tmp, n, text))) {
          }
        } else if (OB_FAIL(append_int_text(alloc, v, text))) {
        }
      }
      break;
    }
    case PARQUET_PHYSICAL_INT64: {
      if (avail < 8) {
        ret = OB_INVALID_DATA;
      } else {
        int64_t v = 0;
        MEMCPY(&v, ptr, 8);
        consumed = 8;
        if (PARQUET_CONVERTED_TIMESTAMP_MILLIS == leaf.converted_type_) {
          if (OB_FAIL(append_datetime_text(alloc, v * 1000L, text))) {
          }
        } else if (PARQUET_CONVERTED_TIMESTAMP_MICROS == leaf.converted_type_) {
          if (OB_FAIL(append_datetime_text(alloc, v, text))) {
          }
        } else if (OB_FAIL(append_int_text(alloc, v, text))) {
        }
      }
      break;
    }
    case PARQUET_PHYSICAL_INT96: {
      if (avail < 12) {
        ret = OB_INVALID_DATA;
      } else {
        int64_t nanos = 0;
        int32_t julian_day = 0;
        MEMCPY(&nanos, ptr, 8);
        MEMCPY(&julian_day, ptr + 8, 4);
        consumed = 12;
        // 2440588 == julian day of 1970-01-01
        const int64_t days = static_cast<int64_t>(julian_day) - 2440588;
        const int64_t usec = days * 86400000000LL + nanos / 1000;
        if (OB_FAIL(append_datetime_text(alloc, usec, text))) {
        }
      }
      break;
    }
    case PARQUET_PHYSICAL_FLOAT: {
      if (avail < 4) {
        ret = OB_INVALID_DATA;
      } else {
        float v = 0;
        MEMCPY(&v, ptr, 4);
        consumed = 4;
        if (OB_FAIL(append_double_text(alloc, static_cast<double>(v), text))) {
        }
      }
      break;
    }
    case PARQUET_PHYSICAL_DOUBLE: {
      if (avail < 8) {
        ret = OB_INVALID_DATA;
      } else {
        double v = 0;
        MEMCPY(&v, ptr, 8);
        consumed = 8;
        if (OB_FAIL(append_double_text(alloc, v, text))) {
        }
      }
      break;
    }
    case PARQUET_PHYSICAL_BYTE_ARRAY: {
      if (avail < 4) {
        ret = OB_INVALID_DATA;
      } else {
        int32_t n = 0;
        MEMCPY(&n, ptr, 4);
        if (n < 0 || static_cast<int64_t>(n) + 4 > avail) {
          ret = OB_INVALID_DATA;
        } else {
          consumed = 4 + static_cast<int64_t>(n);
          if (OB_FAIL(append_bytes_text(alloc, ptr + 4, n, text))) {
          }
        }
      }
      break;
    }
    case PARQUET_PHYSICAL_FIXED_LEN: {
      if (leaf.type_length_ <= 0 || avail < leaf.type_length_) {
        ret = OB_INVALID_DATA;
      } else {
        consumed = leaf.type_length_;
        if (OB_FAIL(append_bytes_text(alloc, ptr, leaf.type_length_, text))) {
        }
      }
      break;
    }
    default:
      ret = OB_NOT_SUPPORTED;
      break;
  }
  return ret;
}

// RLE / bit-packed hybrid decoding.
int decode_rle_hybrid(const char *buf, const int64_t len, const int32_t bit_width,
                      const int64_t num_values, ObIArray<uint32_t> &values, int64_t &consumed)
{
  int ret = OB_SUCCESS;
  int64_t pos = 0;
  consumed = 0;
  if (bit_width < 0 || bit_width > 32) {
    ret = OB_INVALID_DATA;
  }
  while (OB_SUCC(ret) && values.count() < num_values) {
    if (pos >= len) {
      ret = OB_INVALID_DATA;
    } else {
      uint64_t header = 0;
      int32_t shift = 0;
      while (pos < len) {
        const uint8_t b = static_cast<uint8_t>(buf[pos++]);
        header |= static_cast<uint64_t>(b & 0x7f) << shift;
        if (0 == (b & 0x80)) {
          break;
        }
        shift += 7;
      }
      if (header & 1) {
        // bit-packed run: (header >> 1) groups of 8 values
        const uint64_t groups = header >> 1;
        const uint64_t count = groups * 8;
        const int64_t bits = static_cast<int64_t>(count) * bit_width;
        const int64_t bytes = (bits + 7) / 8;
        if (pos + bytes > len) {
          ret = OB_INVALID_DATA;
        } else {
          const char *run = buf + pos;
          for (uint64_t i = 0; OB_SUCC(ret) && i < count && values.count() < num_values; ++i) {
            uint32_t v = 0;
            for (int32_t b = 0; b < bit_width; ++b) {
              const int64_t bit = static_cast<int64_t>(i) * bit_width + b;
              const uint32_t bit_val = (static_cast<uint8_t>(run[bit / 8]) >> (bit % 8)) & 1;
              v |= bit_val << b;
            }
            if (OB_FAIL(values.push_back(v))) {
            }
          }
          pos += bytes;
        }
      } else {
        const uint64_t count = header >> 1;
        const int64_t bytes = (bit_width + 7) / 8;
        if (pos + bytes > len) {
          ret = OB_INVALID_DATA;
        } else {
          uint32_t v = 0;
          for (int32_t b = 0; b < bytes; ++b) {
            v |= static_cast<uint32_t>(static_cast<uint8_t>(buf[pos + b])) << (8 * b);
          }
          pos += bytes;
          for (uint64_t i = 0; OB_SUCC(ret) && i < count && values.count() < num_values; ++i) {
            if (OB_FAIL(values.push_back(v))) {
            }
          }
        }
      }
    }
  }
  if (OB_SUCC(ret)) {
    consumed = pos;
  }
  return ret;
}

int32_t bit_width_for_max(const uint32_t max_value)
{
  int32_t width = 0;
  uint32_t v = max_value;
  while (v > 0) {
    ++width;
    v >>= 1;
  }
  return width;
}

int decode_dictionary_values(const ParquetLeafColumn &leaf, const char *buf, const int64_t len,
                             const int64_t count, ObIAllocator &alloc,
                             ObSEArray<ObString, 64> &dict)
{
  int ret = OB_SUCCESS;
  int64_t pos = 0;
  for (int64_t i = 0; OB_SUCC(ret) && i < count; ++i) {
    ObString text;
    int64_t consumed = 0;
    if (pos >= len) {
      ret = OB_INVALID_DATA;
    } else if (OB_FAIL(plain_value_to_text(leaf, buf + pos, len - pos, consumed, alloc, text))) {
    } else if (consumed <= 0) {
      ret = OB_INVALID_DATA;
    } else {
      pos += consumed;
      if (OB_FAIL(dict.push_back(text))) {
      }
    }
  }
  return ret;
}

int decode_data_values(const ParquetLeafColumn &leaf, const char *buf, const int64_t len,
                       const int64_t count, const int32_t encoding, ObIAllocator &alloc,
                       const ObIArray<ObString> &dict, ObIArray<ObString> &out)
{
  int ret = OB_SUCCESS;
  if (PARQUET_ENC_PLAIN == encoding) {
    int64_t pos = 0;
    for (int64_t i = 0; OB_SUCC(ret) && i < count; ++i) {
      ObString text;
      int64_t consumed = 0;
      if (pos >= len) {
        ret = OB_INVALID_DATA;
      } else if (OB_FAIL(plain_value_to_text(leaf, buf + pos, len - pos, consumed, alloc, text))) {
      } else if (consumed <= 0) {
        ret = OB_INVALID_DATA;
      } else {
        pos += consumed;
        if (OB_FAIL(out.push_back(text))) {
        }
      }
    }
  } else if (PARQUET_ENC_PLAIN_DICTIONARY == encoding || PARQUET_ENC_DICTIONARY == encoding) {
    if (dict.empty()) {
      ret = OB_INVALID_DATA;
    } else if (len < 1) {
      ret = OB_INVALID_DATA;
    } else {
      const int32_t bit_width = static_cast<uint8_t>(buf[0]);
      ObSEArray<uint32_t, 256> indices;
      int64_t consumed = 0;
      if (bit_width > 32) {
        ret = OB_INVALID_DATA;
      } else if (OB_FAIL(decode_rle_hybrid(buf + 1, len - 1, bit_width, count, indices, consumed))) {
      } else {
        for (int64_t i = 0; OB_SUCC(ret) && i < count; ++i) {
          if (indices.at(i) >= static_cast<uint32_t>(dict.count())) {
            ret = OB_INVALID_DATA;
          } else if (OB_FAIL(out.push_back(dict.at(indices.at(i))))) {
          }
        }
      }
    }
  } else if (PARQUET_ENC_RLE == encoding && PARQUET_PHYSICAL_BOOLEAN == leaf.physical_type_) {
    // RLE encoded booleans (1 bit width, no leading width byte)
    ObSEArray<uint32_t, 256> bits;
    int64_t consumed = 0;
    if (OB_FAIL(decode_rle_hybrid(buf, len, 1, count, bits, consumed))) {
    } else {
      for (int64_t i = 0; OB_SUCC(ret) && i < count; ++i) {
        ObString text;
        if (OB_FAIL(append_bytes_text(alloc, bits.at(i) ? "true" : "false",
                                      bits.at(i) ? 4 : 5, text))) {
        } else if (OB_FAIL(out.push_back(text))) {
        }
      }
    }
  } else {
    ret = OB_NOT_SUPPORTED;
    LOG_WARN("unsupported parquet value encoding", K(encoding), K(leaf.physical_type_));
  }
  return ret;
}

int decode_boolean_plain(const char *buf, const int64_t len, const int64_t count,
                         ObIAllocator &alloc, ObIArray<ObString> &out)
{
  int ret = OB_SUCCESS;
  for (int64_t i = 0; OB_SUCC(ret) && i < count; ++i) {
    const int64_t byte_idx = i / 8;
    if (byte_idx >= len) {
      ret = OB_INVALID_DATA;
    } else {
      const bool set = (static_cast<uint8_t>(buf[byte_idx]) >> (i % 8)) & 1;
      ObString text;
      if (OB_FAIL(append_bytes_text(alloc, set ? "true" : "false", set ? 4 : 5, text))) {
      } else if (OB_FAIL(out.push_back(text))) {
      }
    }
  }
  return ret;
}

struct PageHeader
{
  PageHeader()
    : type_(-1), uncompressed_size_(0), compressed_size_(0), num_values_(0), encoding_(-1),
      num_nulls_(0), def_levels_byte_length_(0), rep_levels_byte_length_(0), is_compressed_(true),
      dictionary_num_values_(0) {}
  int32_t type_;
  int32_t uncompressed_size_;
  int32_t compressed_size_;
  int64_t num_values_;
  int32_t encoding_;
  int64_t num_nulls_;
  int32_t def_levels_byte_length_;
  int32_t rep_levels_byte_length_;
  bool is_compressed_;
  int64_t dictionary_num_values_;
};

int parse_data_page_header(ThriftCompactReader &r, PageHeader &ph)
{
  int ret = OB_SUCCESS;
  ThriftStructScope struct_scope(r);
  int64_t last = 0;
  int64_t fid = 0;
  int32_t type = 0;
  while (OB_SUCC(ret) && r.ok() && r.read_field_header(fid, type)) {
    switch (fid) {
      case 1: ph.num_values_ = r.read_zigzag(); break;
      case 2: ph.encoding_ = static_cast<int32_t>(r.read_zigzag()); break;
      default: r.skip(type); break;
    }
  }
  if (!r.ok()) {
    ret = OB_INVALID_DATA;
  }
  return ret;
}

int parse_dictionary_page_header(ThriftCompactReader &r, PageHeader &ph)
{
  int ret = OB_SUCCESS;
  ThriftStructScope struct_scope(r);
  int64_t last = 0;
  int64_t fid = 0;
  int32_t type = 0;
  while (OB_SUCC(ret) && r.ok() && r.read_field_header(fid, type)) {
    switch (fid) {
      case 1: ph.dictionary_num_values_ = r.read_zigzag(); break;
      case 2: ph.encoding_ = static_cast<int32_t>(r.read_zigzag()); break;
      default: r.skip(type); break;
    }
  }
  if (!r.ok()) {
    ret = OB_INVALID_DATA;
  }
  return ret;
}

int parse_data_page_header_v2(ThriftCompactReader &r, PageHeader &ph)
{
  int ret = OB_SUCCESS;
  ThriftStructScope struct_scope(r);
  int64_t last = 0;
  int64_t fid = 0;
  int32_t type = 0;
  while (OB_SUCC(ret) && r.ok() && r.read_field_header(fid, type)) {
    switch (fid) {
      case 1: ph.num_values_ = r.read_zigzag(); break;
      case 2: ph.num_nulls_ = r.read_zigzag(); break;
      case 3: (void)r.read_zigzag(); break;
      case 4: ph.encoding_ = static_cast<int32_t>(r.read_zigzag()); break;
      case 5: ph.def_levels_byte_length_ = static_cast<int32_t>(r.read_zigzag()); break;
      case 6: ph.rep_levels_byte_length_ = static_cast<int32_t>(r.read_zigzag()); break;
      case 7: ph.is_compressed_ = (THRIFT_BOOL_FALSE != type); break;
      default: r.skip(type); break;
    }
  }
  if (!r.ok()) {
    ret = OB_INVALID_DATA;
  }
  return ret;
}

int parse_page_header(ThriftCompactReader &r, PageHeader &ph)
{
  int ret = OB_SUCCESS;
  ThriftStructScope struct_scope(r);
  int64_t last = 0;
  int64_t fid = 0;
  int32_t type = 0;
  while (OB_SUCC(ret) && r.ok() && r.read_field_header(fid, type)) {
    switch (fid) {
      case 1: ph.type_ = static_cast<int32_t>(r.read_zigzag()); break;
      case 2: ph.uncompressed_size_ = static_cast<int32_t>(r.read_zigzag()); break;
      case 3: ph.compressed_size_ = static_cast<int32_t>(r.read_zigzag()); break;
      case 5: ret = parse_data_page_header(r, ph); break;
      case 7: ret = parse_dictionary_page_header(r, ph); break;
      case 8: ret = parse_data_page_header_v2(r, ph); break;
      default: r.skip(type); break;
    }
  }
  if (OB_FAIL(ret)) {
  } else if (!r.ok()) {
    ret = OB_INVALID_DATA;
  } else if (ph.type_ < 0 || ph.compressed_size_ < 0 || ph.uncompressed_size_ < 0) {
    ret = OB_INVALID_DATA;
  }
  return ret;
}

// Decode the definition levels of a data page into %def_levels.
int decode_def_levels(const char *buf, const int64_t len, const int32_t max_def_level,
                      const int64_t num_values, ObIArray<uint32_t> &def_levels, int64_t &consumed)
{
  int ret = OB_SUCCESS;
  consumed = 0;
  if (max_def_level <= 0) {
    if (OB_FAIL(def_levels.prepare_allocate(num_values))) {
    } else {
      for (int64_t i = 0; i < num_values; ++i) {
        def_levels.at(i) = 0;
      }
    }
  } else if (OB_ISNULL(buf) || len < 1) {
    ret = OB_INVALID_DATA;
  } else {
    // parquet levels are encoded with the RLE/bit-packed hybrid encoding where the bit
    // width is implied by the maximum level (unlike dictionary indices, which store it
    // as the first byte)
    const int32_t bit_width = bit_width_for_max(static_cast<uint32_t>(max_def_level));
    if (bit_width <= 0 || bit_width > 8) {
      ret = OB_INVALID_DATA;
    } else if (OB_FAIL(decode_rle_hybrid(buf, len, bit_width, num_values,
                                         def_levels, consumed))) {
    }
  }
  return ret;
}

int decompress_page(const int32_t codec, const char *src, const int64_t src_len,
                    char *dst, const int64_t dst_len, int64_t &written)
{
  int ret = OB_SUCCESS;
  written = 0;
  if (PARQUET_CODEC_UNCOMPRESSED == codec) {
    if (src_len > dst_len) {
      ret = OB_INVALID_DATA;
    } else {
      MEMCPY(dst, src, src_len);
      written = src_len;
    }
  } else if (PARQUET_CODEC_SNAPPY == codec) {
    ret = snappy_uncompress(src, src_len, dst, dst_len, written);
  } else {
    ret = OB_NOT_SUPPORTED;
    LOG_WARN("unsupported parquet compression codec", K(codec));
  }
  return ret;
}

} // anonymous namespace

// ---------------------------------------------------------------------------
// schema inference
// ---------------------------------------------------------------------------
int ob_parquet_read_schema(const ObString &path,
                           ObIAllocator &alloc,
                           ObIArray<ObFileSqlColumnSchema> &columns,
                           int64_t &num_rows)
{
  int ret = OB_SUCCESS;
  num_rows = 0;
  char path_buf[PATH_MAX + 1];
  FILE *fp = NULL;
  char *footer = NULL;
  if (path.empty() || path.length() > PATH_MAX) {
    ret = OB_INVALID_ARGUMENT;
  } else {
    MEMCPY(path_buf, path.ptr(), path.length());
    path_buf[path.length()] = '\0';
    if (NULL == (fp = ::fopen(path_buf, "rb"))) {
      ret = (ENOENT == errno) ? OB_FILE_NOT_EXIST : OB_IO_ERROR;
    } else if (0 != ::fseek(fp, 0, SEEK_END)) {
      ret = OB_IO_ERROR;
    } else {
      const int64_t file_size = ::ftell(fp);
      if (file_size < 12) {
        ret = OB_INVALID_DATA;
      } else {
        char head[4];
        char tail[8];
        if (OB_FAIL(read_exact(fp, 0, head, 4))) {
        } else if (0 != MEMCMP(head, "PAR1", 4)) {
          ret = OB_INVALID_DATA;
        } else if (OB_FAIL(read_exact(fp, file_size - 8, tail, 8))) {
        } else {
          uint32_t footer_len = 0;
          MEMCPY(&footer_len, tail, 4);
          const int64_t footer_pos = file_size - 8 - static_cast<int64_t>(footer_len);
          if (0 != MEMCMP(tail + 4, "PAR1", 4) || footer_len <= 0 || footer_pos <= 4) {
            ret = OB_INVALID_DATA;
          } else if (NULL == (footer = static_cast<char *>(alloc.alloc(footer_len)))) {
            ret = OB_ALLOCATE_MEMORY_FAILED;
          } else if (OB_FAIL(read_exact(fp, footer_pos, footer, footer_len))) {
          } else {
            ParquetFileMeta meta;
            ObArenaAllocator meta_alloc;
            if (OB_FAIL(parse_file_meta(footer, footer_len, meta_alloc, meta))) {
              LOG_WARN("failed to parse parquet footer", K(ret));
            } else {
              for (int64_t i = 0; OB_SUCC(ret) && i < meta.leaves_.count(); ++i) {
                ObFileSqlColumnSchema column;
                const ParquetLeafColumn &leaf = meta.leaves_.at(i);
                ObString name;
                if (OB_FAIL(ob_write_string(alloc, leaf.name_, name))) {
                } else {
                  column.name_ = name;
                  column.nullable_ = (PARQUET_REP_OPTIONAL == leaf.repetition_type_);
                  switch (leaf.physical_type_) {
                    case PARQUET_PHYSICAL_BOOLEAN:
                      column.type_ = OB_FILE_SQL_TYPE_BOOLEAN;
                      break;
                    case PARQUET_PHYSICAL_INT32:
                      column.type_ = (PARQUET_CONVERTED_DATE == leaf.converted_type_)
                                         ? OB_FILE_SQL_TYPE_DATE : OB_FILE_SQL_TYPE_BIGINT;
                      break;
                    case PARQUET_PHYSICAL_INT64:
                      column.type_ = (PARQUET_CONVERTED_TIMESTAMP_MILLIS == leaf.converted_type_
                                      || PARQUET_CONVERTED_TIMESTAMP_MICROS == leaf.converted_type_)
                                         ? OB_FILE_SQL_TYPE_DATETIME : OB_FILE_SQL_TYPE_BIGINT;
                      break;
                    case PARQUET_PHYSICAL_INT96:
                      column.type_ = OB_FILE_SQL_TYPE_DATETIME;
                      break;
                    case PARQUET_PHYSICAL_FLOAT:
                    case PARQUET_PHYSICAL_DOUBLE:
                      column.type_ = OB_FILE_SQL_TYPE_DOUBLE;
                      break;
                    case PARQUET_PHYSICAL_BYTE_ARRAY:
                    case PARQUET_PHYSICAL_FIXED_LEN:
                      column.type_ = OB_FILE_SQL_TYPE_VARCHAR;
                      break;
                    default:
                      ret = OB_NOT_SUPPORTED;
                      LOG_WARN("unsupported parquet physical type", K(leaf.physical_type_));
                      break;
                  }
                  if (OB_SUCC(ret) && OB_FAIL(columns.push_back(column))) {
                  }
                }
              }
              if (OB_SUCC(ret)) {
                num_rows = meta.num_rows_;
              }
            }
          }
        }
      }
    }
  }
  if (NULL != fp) {
    ::fclose(fp);
    fp = NULL;
  }
  return ret;
}

// ---------------------------------------------------------------------------
// streaming reader
// ---------------------------------------------------------------------------
namespace
{

class ObFileSqlParquetReader : public ObFileSqlReader
{
public:
  explicit ObFileSqlParquetReader(ObIAllocator &alloc)
    : alloc_(alloc), fp_(NULL), file_size_(0), footer_start_(0), path_(), meta_(), meta_alloc_(),
      projection_(), row_alloc_(), rg_index_(0), row_in_rg_(0), rg_loaded_(false),
      rg_rows_(0), column_data_(), column_nulls_(), opened_(false) {}
  virtual ~ObFileSqlParquetReader() { close(); }
  virtual int open(const ObFileSqlReadParam &param) override;
  virtual int next_row(ObIArray<ObFileSqlCell> &cells) override;
  virtual int rescan() override;
  virtual void close() override;
private:
  int load_row_group();
  int decode_column_chunk(const int32_t leaf_index, const ParquetRowGroupMeta &rg,
                          const ParquetColumnChunkMeta &meta, const int64_t num_rows,
                          ObIArray<ObString> &values, ObIArray<bool> &nulls);
  int read_page_header(const char *page_buf, const int64_t page_len, PageHeader &ph,
                       int64_t &header_size);
private:
  ObIAllocator &alloc_;
  FILE *fp_;
  int64_t file_size_;
  int64_t footer_start_;
  ObString path_;
  ParquetFileMeta meta_;
  ObArenaAllocator meta_alloc_;
  ObSEArray<int64_t, 8> projection_;
  ObArenaAllocator row_alloc_;
  int64_t rg_index_;
  int64_t row_in_rg_;
  bool rg_loaded_;
  int64_t rg_rows_;
  // decoded values of the current row group, one entry per projected column
  ObSEArray<ObSEArray<ObString, 256> *, 8> column_data_;
  ObSEArray<ObSEArray<bool, 256> *, 8> column_nulls_;
  bool opened_;
};

int ObFileSqlParquetReader::open(const ObFileSqlReadParam &param)
{
  int ret = OB_SUCCESS;
  char path_buf[PATH_MAX + 1];
  close();
  if (OB_ISNULL(param.schema_) || OB_ISNULL(param.projection_) || param.path_.empty()) {
    ret = OB_INVALID_ARGUMENT;
  } else if (param.path_.length() > PATH_MAX) {
    ret = OB_INVALID_ARGUMENT;
  } else {
    MEMCPY(path_buf, param.path_.ptr(), param.path_.length());
    path_buf[param.path_.length()] = '\0';
    path_ = param.path_;
    if (NULL == (fp_ = ::fopen(path_buf, "rb"))) {
      ret = (ENOENT == errno) ? OB_FILE_NOT_EXIST : OB_IO_ERROR;
    } else if (0 != ::fseek(fp_, 0, SEEK_END)) {
      ret = OB_IO_ERROR;
    } else if ((file_size_ = ::ftell(fp_)) < 12) {
      ret = OB_INVALID_DATA;
    } else {
      char tail[8];
      if (OB_FAIL(read_exact(fp_, file_size_ - 8, tail, 8))) {
      } else {
        uint32_t footer_len = 0;
        MEMCPY(&footer_len, tail, 4);
        const int64_t footer_pos = file_size_ - 8 - static_cast<int64_t>(footer_len);
        if (0 != MEMCMP(tail + 4, "PAR1", 4) || footer_len <= 0 || footer_pos <= 4) {
          ret = OB_INVALID_DATA;
        } else if (FALSE_IT(footer_start_ = footer_pos)) {
        } else {
          char *footer = static_cast<char *>(meta_alloc_.alloc(footer_len));
          if (OB_ISNULL(footer)) {
            ret = OB_ALLOCATE_MEMORY_FAILED;
          } else if (OB_FAIL(read_exact(fp_, footer_pos, footer, footer_len))) {
          } else if (OB_FAIL(parse_file_meta(footer, footer_len, meta_alloc_, meta_))) {
          } else if (param.schema_->count() != meta_.leaves_.count()) {
            // file changed since resolve time
            ret = OB_INVALID_DATA;
            LOG_WARN("parquet schema changed", K(param.schema_->count()), K(meta_.leaves_.count()));
          } else if (OB_FAIL(projection_.assign(*param.projection_))) {
          } else if (OB_FAIL(column_data_.prepare_allocate(projection_.count()))) {
          } else if (OB_FAIL(column_nulls_.prepare_allocate(projection_.count()))) {
          } else {
            for (int64_t i = 0; i < column_data_.count(); ++i) {
              column_data_.at(i) = NULL;
              column_nulls_.at(i) = NULL;
            }
            rg_index_ = 0;
            row_in_rg_ = 0;
            rg_loaded_ = false;
            opened_ = true;
          }
        }
      }
    }
  }
  return ret;
}

void ObFileSqlParquetReader::close()
{
  if (NULL != fp_) {
    ::fclose(fp_);
    fp_ = NULL;
  }
  for (int64_t i = 0; i < column_data_.count(); ++i) {
    if (NULL != column_data_.at(i)) {
      column_data_.at(i)->~ObSEArray<ObString, 256>();
      column_data_.at(i) = NULL;
    }
  }
  for (int64_t i = 0; i < column_nulls_.count(); ++i) {
    if (NULL != column_nulls_.at(i)) {
      column_nulls_.at(i)->~ObSEArray<bool, 256>();
      column_nulls_.at(i) = NULL;
    }
  }
  column_data_.reset();
  column_nulls_.reset();
  projection_.reset();
  row_alloc_.reset();
  meta_alloc_.reset();
  meta_.leaves_.reset();
  meta_.row_groups_.reset();
  meta_.num_rows_ = 0;
  meta_.nested_ = false;
  meta_.repeated_ = false;
  rg_index_ = 0;
  row_in_rg_ = 0;
  rg_loaded_ = false;
  rg_rows_ = 0;
  opened_ = false;
}

int ObFileSqlParquetReader::rescan()
{
  int ret = OB_SUCCESS;
  if (!opened_) {
    ret = OB_NOT_INIT;
  } else {
    rg_index_ = 0;
    row_in_rg_ = 0;
    rg_loaded_ = false;
    rg_rows_ = 0;
    row_alloc_.reuse();
  }
  return ret;
}

int ObFileSqlParquetReader::read_page_header(const char *page_buf, const int64_t page_len,
                                             PageHeader &ph, int64_t &header_size)
{
  int ret = OB_SUCCESS;
  ThriftCompactReader r(page_buf, page_len);
  if (OB_FAIL(parse_page_header(r, ph))) {
  } else {
    header_size = r.pos();
    if (header_size <= 0 || header_size + ph.compressed_size_ > page_len) {
      ret = OB_INVALID_DATA;
    }
  }
  return ret;
}

int ObFileSqlParquetReader::decode_column_chunk(const int32_t leaf_index,
                                                const ParquetRowGroupMeta &rg,
                                                const ParquetColumnChunkMeta &meta,
                                                const int64_t num_rows,
                                                ObIArray<ObString> &values,
                                                ObIArray<bool> &nulls)
{
  int ret = OB_SUCCESS;
  const ParquetLeafColumn &leaf = meta_.leaves_.at(leaf_index);
  int64_t chunk_start = meta.data_page_offset_;
  if (meta.dictionary_page_offset_ > 0 && meta.dictionary_page_offset_ < chunk_start) {
    chunk_start = meta.dictionary_page_offset_;
  }
  if (chunk_start < 4 || chunk_start >= file_size_) {
    ret = OB_INVALID_DATA;
  } else {
    // a column chunk is a sequence of pages: it ends where the next chunk of the same row
    // group starts, or at the footer. total_compressed_size excludes page headers, so it is
    // only used as a fallback.
    int64_t chunk_end = footer_start_ > chunk_start ? footer_start_ : file_size_;
    for (int64_t c = 0; c < rg.columns_.count(); ++c) {
      const ParquetColumnChunkMeta &other = rg.columns_.at(c);
      int64_t other_start = other.data_page_offset_;
      if (other.dictionary_page_offset_ > 0 && other.dictionary_page_offset_ < other_start) {
        other_start = other.dictionary_page_offset_;
      }
      if (other_start > chunk_start && other_start < chunk_end) {
        chunk_end = other_start;
      }
    }
    int64_t chunk_len = chunk_end - chunk_start;
    if (chunk_len <= 0) {
      chunk_len = meta.total_compressed_size_;
    }
    if (chunk_len <= 0 || chunk_start + chunk_len > file_size_) {
      chunk_len = file_size_ - chunk_start;
    }
    char *chunk = static_cast<char *>(row_alloc_.alloc(chunk_len));
    char *page_scratch = NULL;
    if (OB_ISNULL(chunk)) {
      ret = OB_ALLOCATE_MEMORY_FAILED;
    } else if (OB_FAIL(read_exact(fp_, chunk_start, chunk, chunk_len))) {
    } else {
      ObSEArray<ObString, 64> dictionary;
      ObSEArray<uint32_t, 256> def_levels;
      int64_t page_pos = 0;
      int64_t decoded = 0;
      while (OB_SUCC(ret) && decoded < num_rows) {
        if (page_pos >= chunk_len) {
          ret = OB_INVALID_DATA;
          break;
        }
        PageHeader ph;
        int64_t header_size = 0;
        if (OB_FAIL(read_page_header(chunk + page_pos, chunk_len - page_pos, ph, header_size))) {
        } else {
          const char *page_data = chunk + page_pos + header_size;
          const int64_t page_data_len = ph.compressed_size_;
          if (2 == ph.type_) {
            // dictionary page
            int64_t written = 0;
            if (OB_ISNULL(page_scratch = static_cast<char *>(row_alloc_.alloc(ph.uncompressed_size_)))) {
              ret = OB_ALLOCATE_MEMORY_FAILED;
            } else if (OB_FAIL(decompress_page(meta.codec_, page_data, page_data_len,
                                               page_scratch, ph.uncompressed_size_, written))) {
            } else if (OB_FAIL(decode_dictionary_values(leaf, page_scratch, written,
                                                        ph.dictionary_num_values_,
                                                        row_alloc_, dictionary))) {
            }
          } else if (0 == ph.type_ || 3 == ph.type_) {
            // data page v1 / v2
            const bool is_v2 = (3 == ph.type_);
            const char *values_ptr = NULL;
            int64_t values_len = 0;
            const char *levels_ptr = NULL;
            int64_t levels_len = 0;
            int64_t rep_len = 0;
            int64_t def_len = 0;
            if (is_v2) {
              rep_len = ph.rep_levels_byte_length_;
              def_len = ph.def_levels_byte_length_;
              if (rep_len < 0 || def_len < 0 || rep_len + def_len > page_data_len) {
                ret = OB_INVALID_DATA;
              } else {
                levels_ptr = page_data + rep_len;
                levels_len = def_len;
                values_ptr = page_data + rep_len + def_len;
                values_len = page_data_len - rep_len - def_len;
                if (rep_len > 0) {
                  // repeated columns are rejected at parse time
                  ret = OB_INVALID_DATA;
                }
              }
            } else {
              int64_t written = 0;
              if (OB_ISNULL(page_scratch = static_cast<char *>(row_alloc_.alloc(ph.uncompressed_size_)))) {
                ret = OB_ALLOCATE_MEMORY_FAILED;
              } else if (OB_FAIL(decompress_page(meta.codec_, page_data, page_data_len,
                                                 page_scratch, ph.uncompressed_size_, written))) {
              } else {
                int64_t pos = 0;
                if (leaf.max_def_level_ > 0) {
                  if (written < 4) {
                    ret = OB_INVALID_DATA;
                  } else {
                    uint32_t len = 0;
                    MEMCPY(&len, page_scratch, 4);
                    if (static_cast<int64_t>(len) + 4 > written) {
                      ret = OB_INVALID_DATA;
                    } else {
                      levels_ptr = page_scratch + 4;
                      levels_len = len;
                      pos = 4 + static_cast<int64_t>(len);
                    }
                  }
                }
                if (OB_SUCC(ret)) {
                  values_ptr = page_scratch + pos;
                  values_len = written - pos;
                }
              }
            }
            if (OB_FAIL(ret)) {
            } else {
              def_levels.reuse();
              int64_t consumed = 0;
              if (OB_FAIL(decode_def_levels(levels_ptr, levels_len, leaf.max_def_level_,
                                            ph.num_values_, def_levels, consumed))) {
              } else {
                // v2 pages may need to decompress the values section separately
                const char *data_ptr = values_ptr;
                int64_t data_len = values_len;
                if (is_v2 && ph.is_compressed_ && PARQUET_CODEC_UNCOMPRESSED != meta.codec_) {
                  const int64_t uncompressed_values_len =
                      ph.uncompressed_size_ - rep_len - def_len;
                  char *buf = static_cast<char *>(row_alloc_.alloc(uncompressed_values_len));
                  int64_t written = 0;
                  if (OB_ISNULL(buf)) {
                    ret = OB_ALLOCATE_MEMORY_FAILED;
                  } else if (OB_FAIL(decompress_page(meta.codec_, values_ptr, values_len,
                                                     buf, uncompressed_values_len, written))) {
                  } else {
                    data_ptr = buf;
                    data_len = written;
                  }
                }
                int64_t non_null = 0;
                for (int64_t i = 0; OB_SUCC(ret) && i < def_levels.count(); ++i) {
                  if (static_cast<int32_t>(def_levels.at(i)) == leaf.max_def_level_) {
                    ++non_null;
                  }
                }
                ObSEArray<ObString, 256> page_values;
                if (OB_FAIL(ret)) {
                } else if (OB_FAIL(decode_data_values(leaf, data_ptr, data_len, non_null,
                                                      ph.encoding_, row_alloc_, dictionary,
                                                      page_values))) {
                } else {
                  int64_t value_idx = 0;
                  for (int64_t i = 0; OB_SUCC(ret) && i < def_levels.count(); ++i) {
                    const bool is_null = (static_cast<int32_t>(def_levels.at(i)) != leaf.max_def_level_);
                    ObString text;
                    if (is_null) {
                      // nothing
                    } else if (value_idx >= page_values.count()) {
                      ret = OB_INVALID_DATA;
                    } else {
                      text = page_values.at(value_idx++);
                    }
                    if (OB_SUCC(ret)) {
                      if (OB_FAIL(values.push_back(text))) {
                      } else if (OB_FAIL(nulls.push_back(is_null))) {
                      }
                    }
                  }
                  decoded += def_levels.count();
                }
              }
            }
          } else if (1 == ph.type_) {
            // index page, skip
          } else {
            ret = OB_NOT_SUPPORTED;
            LOG_WARN("unsupported parquet page type", K(ph.type_));
          }
          page_pos += header_size + page_data_len;
        }
      }
      if (OB_SUCC(ret) && decoded < num_rows) {
        ret = OB_INVALID_DATA;
      }
    }
  }
  return ret;
}

int ObFileSqlParquetReader::load_row_group()
{
  int ret = OB_SUCCESS;
  row_alloc_.reuse();
  if (rg_index_ >= meta_.row_groups_.count()) {
    ret = OB_ITER_END;
  } else {
    const ParquetRowGroupMeta &rg = meta_.row_groups_.at(rg_index_);
    rg_rows_ = rg.num_rows_;
    if (rg.columns_.count() != meta_.leaves_.count()) {
      ret = OB_INVALID_DATA;
    } else {
      for (int64_t i = 0; OB_SUCC(ret) && i < projection_.count(); ++i) {
        const int64_t leaf_index = projection_.at(i);
        if (leaf_index < 0 || leaf_index >= meta_.leaves_.count()) {
          ret = OB_INVALID_ARGUMENT;
        } else {
          void *data_mem = row_alloc_.alloc(sizeof(ObSEArray<ObString, 256>));
          void *null_mem = row_alloc_.alloc(sizeof(ObSEArray<bool, 256>));
          if (OB_ISNULL(data_mem) || OB_ISNULL(null_mem)) {
            ret = OB_ALLOCATE_MEMORY_FAILED;
          } else {
            ObSEArray<ObString, 256> *values = new (data_mem) ObSEArray<ObString, 256>();
            ObSEArray<bool, 256> *nulls = new (null_mem) ObSEArray<bool, 256>();
            column_data_.at(i) = values;
            column_nulls_.at(i) = nulls;
            if (OB_FAIL(decode_column_chunk(static_cast<int32_t>(leaf_index), rg,
                                            rg.columns_.at(leaf_index), rg_rows_,
                                            *values, *nulls))) {
              LOG_WARN("failed to decode parquet column chunk", K(ret), K(leaf_index));
            }
          }
        }
      }
      if (OB_SUCC(ret)) {
        row_in_rg_ = 0;
        rg_loaded_ = true;
        ++rg_index_;
      }
    }
  }
  return ret;
}

int ObFileSqlParquetReader::next_row(ObIArray<ObFileSqlCell> &cells)
{
  int ret = OB_SUCCESS;
  cells.reuse();
  if (!opened_) {
    ret = OB_NOT_INIT;
  } else {
    while (OB_SUCC(ret)) {
      if (!rg_loaded_ || row_in_rg_ >= rg_rows_) {
        rg_loaded_ = false;
        ret = load_row_group();
        if (OB_ITER_END == ret) {
          // no more row groups
        } else if (OB_FAIL(ret)) {
        }
        continue;
      }
      if (OB_SUCC(ret)) {
        break;
      }
    }
    if (OB_SUCC(ret)) {
      for (int64_t i = 0; OB_SUCC(ret) && i < column_data_.count(); ++i) {
        ObFileSqlCell cell;
        if (row_in_rg_ >= column_data_.at(i)->count()) {
          ret = OB_INVALID_DATA;
        } else {
          cell.null_ = column_nulls_.at(i)->at(row_in_rg_);
          if (!cell.null_) {
            const ObString &text = column_data_.at(i)->at(row_in_rg_);
            cell.ptr_ = text.ptr();
            cell.len_ = text.length();
          }
          if (OB_FAIL(cells.push_back(cell))) {
          }
        }
      }
      ++row_in_rg_;
    }
  }
  return ret;
}

} // anonymous namespace

int ob_parquet_create_reader(ObIAllocator &alloc, ObFileSqlReader *&reader)
{
  int ret = OB_SUCCESS;
  reader = NULL;
  void *mem = alloc.alloc(sizeof(ObFileSqlParquetReader));
  if (OB_ISNULL(mem)) {
    ret = OB_ALLOCATE_MEMORY_FAILED;
  } else {
    reader = new (mem) ObFileSqlParquetReader(alloc);
  }
  return ret;
}

} // namespace sql
} // namespace oceanbase
