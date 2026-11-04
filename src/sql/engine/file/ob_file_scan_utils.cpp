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

#include "sql/engine/file/ob_file_scan_utils.h"
#include "sql/engine/file/ob_file_json_utils.h"
#include "sql/engine/file/ob_file_parquet_reader.h"
#include "lib/charset/ob_charset.h"

#include <errno.h>
#include <glob.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

namespace oceanbase
{
namespace sql
{

using namespace common;

static const int64_t FILE_SQL_READ_BUFFER_SIZE = 64L * 1024;
static const int64_t FILE_SQL_INITIAL_FIELD_CAP = 4096;
static const int64_t FILE_SQL_MAX_FIELD_LEN = 256L * 1024 * 1024;
static const int64_t FILE_SQL_USECS_PER_DAY = 86400000000LL;

const char *ob_file_sql_type_name(const ObFileSqlType type)
{
  const char *name = "VARCHAR";
  switch (type) {
    case OB_FILE_SQL_TYPE_NULL: name = "VARCHAR"; break;
    case OB_FILE_SQL_TYPE_BIGINT: name = "BIGINT"; break;
    case OB_FILE_SQL_TYPE_DOUBLE: name = "DOUBLE"; break;
    case OB_FILE_SQL_TYPE_BOOLEAN: name = "BOOLEAN"; break;
    case OB_FILE_SQL_TYPE_VARCHAR: name = "VARCHAR"; break;
    case OB_FILE_SQL_TYPE_DATE: name = "DATE"; break;
    case OB_FILE_SQL_TYPE_DATETIME: name = "DATETIME"; break;
    default: name = "VARCHAR"; break;
  }
  return name;
}

ObObjType ob_file_sql_obj_type(const ObFileSqlType type)
{
  ObObjType obj_type = ObVarcharType;
  switch (type) {
    case OB_FILE_SQL_TYPE_BIGINT: obj_type = ObIntType; break;
    case OB_FILE_SQL_TYPE_DOUBLE: obj_type = ObDoubleType; break;
    case OB_FILE_SQL_TYPE_BOOLEAN: obj_type = ObTinyIntType; break;
    case OB_FILE_SQL_TYPE_DATE: obj_type = ObDateType; break;
    case OB_FILE_SQL_TYPE_DATETIME: obj_type = ObDateTimeType; break;
    case OB_FILE_SQL_TYPE_NULL:
    case OB_FILE_SQL_TYPE_VARCHAR:
    default: obj_type = ObVarcharType; break;
  }
  return obj_type;
}

int ob_file_sql_stat_file(const ObString &path, ObFileSqlFileInfo &info)
{
  int ret = OB_SUCCESS;
  char path_buf[PATH_MAX + 1];
  struct stat st;
  info = ObFileSqlFileInfo();
  if (path.empty() || path.length() > PATH_MAX) {
    ret = OB_INVALID_ARGUMENT;
  } else {
    MEMCPY(path_buf, path.ptr(), path.length());
    path_buf[path.length()] = '\0';
    if (0 != ::stat(path_buf, &st)) {
      ret = (ENOENT == errno) ? OB_FILE_NOT_EXIST : OB_IO_ERROR;
    } else if (!S_ISREG(st.st_mode)) {
      ret = OB_INVALID_ARGUMENT;
    } else {
      info.size_ = static_cast<int64_t>(st.st_size);
      info.mtime_ = static_cast<int64_t>(st.st_mtime) * 1000000L
                    + static_cast<int64_t>(st.st_mtim.tv_nsec) / 1000L;
      info.inode_ = static_cast<int64_t>(st.st_ino);
    }
  }
  return ret;
}

ObString ob_file_sql_trim(const ObString &text)
{
  ObString result = text;
  int32_t begin = 0;
  int32_t end = text.length();
  while (begin < end && (text[begin] == ' ' || text[begin] == '\t' || text[begin] == '\r')) {
    ++begin;
  }
  while (end > begin && (text[end - 1] == ' ' || text[end - 1] == '\t' || text[end - 1] == '\r')) {
    --end;
  }
  result.assign_ptr(text.ptr() + begin, end - begin);
  return result;
}

bool ob_file_sql_parse_int(const ObString &text, int64_t &value)
{
  bool ok = !text.empty();
  int64_t i = 0;
  if (ok && ('-' == text.ptr()[0] || '+' == text.ptr()[0])) {
    i = 1;
    ok = text.length() > 1;
  }
  for (int64_t k = i; ok && k < text.length(); ++k) {
    ok = (text.ptr()[k] >= '0' && text.ptr()[k] <= '9');
  }
  if (ok) {
    char buf[64];
    if (text.length() >= static_cast<int32_t>(sizeof(buf))) {
      ok = false;
    } else {
      MEMCPY(buf, text.ptr(), text.length());
      buf[text.length()] = '\0';
      char *end_ptr = NULL;
      errno = 0;
      const long long parsed = ::strtoll(buf, &end_ptr, 10);
      if (ERANGE == errno || NULL == end_ptr || '\0' != *end_ptr) {
        ok = false;
      } else {
        value = static_cast<int64_t>(parsed);
      }
    }
  }
  return ok;
}

bool ob_file_sql_parse_double(const ObString &text, double &value)
{
  bool ok = !text.empty();
  bool has_digit = false;
  int64_t i = 0;
  if (ok && ('-' == text.ptr()[0] || '+' == text.ptr()[0])) {
    i = 1;
    ok = text.length() > 1;
  }
  bool has_dot = false;
  bool has_exp = false;
  for (int64_t k = i; ok && k < text.length(); ++k) {
    const char c = text.ptr()[k];
    if (c >= '0' && c <= '9') {
      has_digit = true;
    } else if ('.' == c && !has_dot && !has_exp) {
      has_dot = true;
    } else if (('e' == c || 'E' == c) && !has_exp && has_digit) {
      has_exp = true;
      if (k + 1 < text.length() && ('-' == text.ptr()[k + 1] || '+' == text.ptr()[k + 1])) {
        ++k;
      }
      if (k + 1 >= text.length()) {
        ok = false;
      }
    } else {
      ok = false;
    }
  }
  if (ok && has_digit) {
    char buf[512];
    if (text.length() >= static_cast<int32_t>(sizeof(buf))) {
      ok = false;
    } else {
      MEMCPY(buf, text.ptr(), text.length());
      buf[text.length()] = '\0';
      char *end_ptr = NULL;
      errno = 0;
      const double parsed = ::strtod(buf, &end_ptr);
      if (ERANGE == errno || NULL == end_ptr || '\0' != *end_ptr || !isfinite(parsed)) {
        ok = false;
      } else {
        value = parsed;
      }
    }
  } else {
    ok = false;
  }
  return ok;
}

bool ob_file_sql_is_bool(const ObString &text, bool &value)
{
  bool ok = true;
  if (0 == text.case_compare("true")) {
    value = true;
  } else if (0 == text.case_compare("false")) {
    value = false;
  } else {
    ok = false;
  }
  return ok;
}

static bool is_leap_year(const int32_t year)
{
  return (0 == year % 4 && 0 != year % 100) || 0 == year % 400;
}

static int32_t days_in_month(const int32_t year, const int32_t month)
{
  static const int32_t DAYS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int32_t days = (month >= 1 && month <= 12) ? DAYS[month - 1] : 0;
  if (2 == month && is_leap_year(year)) {
    days = 29;
  }
  return days;
}

// days since 1970-01-01 (Howard Hinnant's algorithm).
static int64_t days_from_civil(int64_t y, const int64_t m, const int64_t d)
{
  y -= m <= 2;
  const int64_t era = (y >= 0 ? y : y - 399) / 400;
  const int64_t yoe = y - era * 400;
  const int64_t doy = (153 * (m + (m > 2 ? -3 : 9)) + 2) / 5 + d - 1;
  const int64_t doe = yoe * 365 + yoe / 4 - yoe / 100 + doy;
  return era * 146097 + doe - 719468;
}

static bool parse_two_digits(const char *p, int32_t &value)
{
  bool ok = (p[0] >= '0' && p[0] <= '9' && p[1] >= '0' && p[1] <= '9');
  if (ok) {
    value = (p[0] - '0') * 10 + (p[1] - '0');
  }
  return ok;
}

static bool parse_four_digits(const char *p, int32_t &value)
{
  bool ok = true;
  value = 0;
  for (int32_t i = 0; ok && i < 4; ++i) {
    ok = (p[i] >= '0' && p[i] <= '9');
    if (ok) {
      value = value * 10 + (p[i] - '0');
    }
  }
  return ok;
}

// Strictly accept YYYY-MM-DD with a valid calendar date.
static bool parse_date_parts(const ObString &text, int32_t &year, int32_t &month, int32_t &day)
{
  bool ok = (10 == text.length());
  if (ok) {
    const char *p = text.ptr();
    ok = ('-' == p[4] && '-' == p[7]) && parse_four_digits(p, year)
         && parse_two_digits(p + 5, month) && parse_two_digits(p + 8, day);
    if (ok) {
      ok = (year >= 1 && year <= 9999 && month >= 1 && month <= 12 && day >= 1
            && day <= days_in_month(year, month));
    }
  }
  return ok;
}

// Strictly accept YYYY-MM-DD[ T]HH:MM:SS with optional fraction and valid ranges.
static bool parse_datetime_parts(const ObString &text, int32_t &days, int64_t &usec)
{
  bool ok = (text.length() >= 19 && text.length() <= 32);
  int32_t year = 0;
  int32_t month = 0;
  int32_t day = 0;
  if (ok) {
    ObString date_part;
    date_part.assign_ptr(text.ptr(), 10);
    ok = parse_date_parts(date_part, year, month, day);
  }
  if (ok) {
    const char *p = text.ptr();
    ok = (' ' == p[10] || 'T' == p[10] || 't' == p[10]);
  }
  int32_t hour = 0;
  int32_t minute = 0;
  int32_t second = 0;
  if (ok) {
    const char *p = text.ptr();
    ok = (':' == p[13] && ':' == p[16]) && parse_two_digits(p + 11, hour)
         && parse_two_digits(p + 14, minute) && parse_two_digits(p + 17, second);
    if (ok) {
      ok = (hour <= 23 && minute <= 59 && second <= 59);
    }
  }
  int64_t fraction = 0;
  if (ok && text.length() > 19) {
    if ('.' != text.ptr()[19]) {
      ok = false;
    } else {
      int32_t digits = 0;
      for (int32_t i = 20; ok && i < text.length(); ++i) {
        const char c = text.ptr()[i];
        ok = (c >= '0' && c <= '9');
        if (ok && digits < 6) {
          fraction = fraction * 10 + (c - '0');
          ++digits;
        }
      }
      while (digits < 6) {
        fraction *= 10;
        ++digits;
      }
    }
  }
  if (ok) {
    days = static_cast<int32_t>(days_from_civil(year, month, day));
    usec = static_cast<int64_t>(hour) * 3600000000LL + static_cast<int64_t>(minute) * 60000000LL
           + static_cast<int64_t>(second) * 1000000LL + fraction;
  }
  return ok;
}

bool ob_file_sql_parse_date(const ObString &text, int32_t &days)
{
  int32_t year = 0;
  int32_t month = 0;
  int32_t day = 0;
  bool ok = parse_date_parts(text, year, month, day);
  if (ok) {
    days = static_cast<int32_t>(days_from_civil(year, month, day));
  }
  return ok;
}

bool ob_file_sql_parse_datetime(const ObString &text, int64_t &value)
{
  int32_t days = 0;
  int64_t usec = 0;
  bool ok = parse_datetime_parts(text, days, usec);
  if (ok) {
    value = static_cast<int64_t>(days) * FILE_SQL_USECS_PER_DAY + usec;
  }
  return ok;
}

int ObFileSqlTypeInferrer::init(const int64_t column_cnt)
{
  int ret = OB_SUCCESS;
  if (column_cnt < 0) {
    ret = OB_INVALID_ARGUMENT;
  } else if (OB_FAIL(types_.prepare_allocate(column_cnt))
             || OB_FAIL(nullable_.prepare_allocate(column_cnt))
             || OB_FAIL(seen_.prepare_allocate(column_cnt))) {
  } else {
    for (int64_t i = 0; i < column_cnt; ++i) {
      types_.at(i) = OB_FILE_SQL_TYPE_NULL;
      nullable_.at(i) = false;
      seen_.at(i) = false;
    }
  }
  return ret;
}

void ObFileSqlTypeInferrer::add_null(const int64_t col)
{
  if (col >= 0 && col < nullable_.count()) {
    nullable_.at(col) = true;
  }
}

void ObFileSqlTypeInferrer::add_typed_value(const int64_t col, const ObFileSqlType type)
{
  if (col < 0 || col >= types_.count()) {
    return;
  }
  if (OB_FILE_SQL_TYPE_NULL == type) {
    nullable_.at(col) = true;
    return;
  }
  seen_.at(col) = true;
  ObFileSqlType merged = types_.at(col);
  if (OB_FILE_SQL_TYPE_NULL == merged) {
    merged = type;
  } else if (merged == type) {
    // no change
  } else if ((OB_FILE_SQL_TYPE_BIGINT == merged && OB_FILE_SQL_TYPE_DOUBLE == type)
             || (OB_FILE_SQL_TYPE_DOUBLE == merged && OB_FILE_SQL_TYPE_BIGINT == type)) {
    merged = OB_FILE_SQL_TYPE_DOUBLE;
  } else if ((OB_FILE_SQL_TYPE_DATE == merged && OB_FILE_SQL_TYPE_DATETIME == type)
             || (OB_FILE_SQL_TYPE_DATETIME == merged && OB_FILE_SQL_TYPE_DATE == type)) {
    merged = OB_FILE_SQL_TYPE_DATETIME;
  } else {
    merged = OB_FILE_SQL_TYPE_VARCHAR;
  }
  types_.at(col) = merged;
}

void ObFileSqlTypeInferrer::add_value(const int64_t col, const ObString &text)
{
  if (col < 0 || col >= types_.count()) {
    return;
  }
  const ObString trimmed = ob_file_sql_trim(text);
  if (trimmed.empty()) {
    nullable_.at(col) = true;
    return;
  }
  bool bool_value = false;
  int64_t int_value = 0;
  double double_value = 0;
  int32_t date_value = 0;
  int64_t datetime_value = 0;
  ObFileSqlType type = OB_FILE_SQL_TYPE_VARCHAR;
  if (ob_file_sql_is_bool(trimmed, bool_value)) {
    type = OB_FILE_SQL_TYPE_BOOLEAN;
  } else if (ob_file_sql_parse_int(trimmed, int_value)) {
    type = OB_FILE_SQL_TYPE_BIGINT;
  } else if (ob_file_sql_parse_double(trimmed, double_value)) {
    type = OB_FILE_SQL_TYPE_DOUBLE;
  } else if (ob_file_sql_parse_datetime(trimmed, datetime_value)) {
    type = OB_FILE_SQL_TYPE_DATETIME;
  } else if (ob_file_sql_parse_date(trimmed, date_value)) {
    type = OB_FILE_SQL_TYPE_DATE;
  } else {
    type = OB_FILE_SQL_TYPE_VARCHAR;
  }
  add_typed_value(col, type);
}

int ObFileSqlTypeInferrer::finalize(ObIArray<ObFileSqlColumnSchema> &columns) const
{
  int ret = OB_SUCCESS;
  if (columns.empty()) {
    ret = columns.prepare_allocate(types_.count());
  } else if (columns.count() != types_.count()) {
    ret = OB_ERR_UNEXPECTED;
  }
  if (OB_SUCC(ret)) {
    for (int64_t i = 0; OB_SUCC(ret) && i < columns.count(); ++i) {
      columns.at(i).type_ = seen_.at(i) ? types_.at(i) : OB_FILE_SQL_TYPE_VARCHAR;
      // a column without any value is still nullable
      columns.at(i).nullable_ = nullable_.at(i) || !seen_.at(i);
    }
  }
  return ret;
}

ObFileSqlCsvScanner::ObFileSqlCsvScanner()
  : fp_(NULL),
    buf_(NULL),
    buf_cap_(0),
    buf_pos_(0),
    buf_len_(0),
    eof_(false),
    options_(),
    arena_(),
    field_buf_(NULL),
    field_cap_(0),
    field_len_(0),
    line_no_(1),
    record_line_no_(1),
    opened_(false)
{
}

ObFileSqlCsvScanner::~ObFileSqlCsvScanner()
{
  close();
}

void ObFileSqlCsvScanner::close()
{
  if (NULL != fp_) {
    ::fclose(fp_);
    fp_ = NULL;
  }
  if (NULL != buf_) {
    ::free(buf_);
    buf_ = NULL;
  }
  buf_cap_ = 0;
  buf_pos_ = 0;
  buf_len_ = 0;
  field_buf_ = NULL;
  field_cap_ = 0;
  field_len_ = 0;
  arena_.reset();
  opened_ = false;
}

int ObFileSqlCsvScanner::open(const ObString &path, const ObFileSqlCsvOptions &options)
{
  int ret = OB_SUCCESS;
  char path_buf[PATH_MAX + 1];
  close();
  options_ = options;
  if (path.empty() || path.length() > PATH_MAX) {
    ret = OB_INVALID_ARGUMENT;
  } else {
    MEMCPY(path_buf, path.ptr(), path.length());
    path_buf[path.length()] = '\0';
    if (NULL == (fp_ = ::fopen(path_buf, "rb"))) {
      ret = (ENOENT == errno) ? OB_FILE_NOT_EXIST : OB_IO_ERROR;
    } else if (NULL == (buf_ = static_cast<char *>(::malloc(FILE_SQL_READ_BUFFER_SIZE)))) {
      ret = OB_ALLOCATE_MEMORY_FAILED;
    } else if (NULL == (field_buf_ = static_cast<char *>(arena_.alloc(FILE_SQL_INITIAL_FIELD_CAP)))) {
      ret = OB_ALLOCATE_MEMORY_FAILED;
    } else {
      buf_cap_ = FILE_SQL_READ_BUFFER_SIZE;
      field_cap_ = FILE_SQL_INITIAL_FIELD_CAP;
      buf_pos_ = 0;
      buf_len_ = static_cast<int64_t>(::fread(buf_, 1, buf_cap_, fp_));
      eof_ = (buf_len_ < buf_cap_);
      line_no_ = 1;
      record_line_no_ = 1;
      opened_ = true;
    }
  }
  return ret;
}

int ObFileSqlCsvScanner::rescan()
{
  int ret = OB_SUCCESS;
  if (!opened_ || NULL == fp_) {
    ret = OB_NOT_INIT;
  } else if (0 != ::fseek(fp_, 0, SEEK_SET)) {
    ret = OB_IO_ERROR;
  } else {
    buf_pos_ = 0;
    buf_len_ = static_cast<int64_t>(::fread(buf_, 1, buf_cap_, fp_));
    eof_ = (buf_len_ < buf_cap_);
    line_no_ = 1;
    record_line_no_ = 1;
    field_len_ = 0;
    arena_.reuse();
    if (NULL == (field_buf_ = static_cast<char *>(arena_.alloc(FILE_SQL_INITIAL_FIELD_CAP)))) {
      ret = OB_ALLOCATE_MEMORY_FAILED;
    } else {
      field_cap_ = FILE_SQL_INITIAL_FIELD_CAP;
    }
  }
  return ret;
}

int ObFileSqlCsvScanner::peek_raw_char(char &c, bool &eof)
{
  int ret = OB_SUCCESS;
  eof = false;
  if (buf_pos_ >= buf_len_) {
    if (eof_) {
      eof = true;
    } else if (NULL != fp_) {
      buf_pos_ = 0;
      buf_len_ = static_cast<int64_t>(::fread(buf_, 1, buf_cap_, fp_));
      if (0 == buf_len_) {
        eof_ = true;
        eof = true;
      } else {
        if (buf_len_ < buf_cap_) {
          eof_ = true;
        }
        c = buf_[buf_pos_];
      }
    } else {
      eof = true;
    }
  } else {
    c = buf_[buf_pos_];
  }
  return ret;
}

int ObFileSqlCsvScanner::read_raw_char(char &c, bool &eof)
{
  int ret = OB_SUCCESS;
  if (OB_FAIL(peek_raw_char(c, eof))) {
  } else if (!eof) {
    ++buf_pos_;
  }
  return ret;
}

// Compact the unconsumed bytes and read the next block. eof_ is set once the file is drained.
int ObFileSqlCsvScanner::refill()
{
  int ret = OB_SUCCESS;
  if (!opened_ || NULL == fp_) {
    ret = OB_NOT_INIT;
  } else if (eof_ && buf_pos_ >= buf_len_) {
    // nothing left
  } else {
    const int64_t remain = buf_len_ - buf_pos_;
    if (remain > 0 && buf_pos_ > 0) {
      MEMMOVE(buf_, buf_ + buf_pos_, remain);
    }
    buf_pos_ = 0;
    buf_len_ = remain;
    if (!eof_) {
      const int64_t want = buf_cap_ - buf_len_;
      const int64_t n = (want > 0) ? static_cast<int64_t>(::fread(buf_ + buf_len_, 1, want, fp_))
                                   : 0;
      if (n <= 0) {
        eof_ = true;
      } else {
        buf_len_ += n;
        if (n < want) {
          eof_ = true;
        }
      }
    }
  }
  return ret;
}

int ObFileSqlCsvScanner::append_to_field(const char *ptr, const int64_t len)
{
  int ret = OB_SUCCESS;
  if (len <= 0) {
    // nothing to do
  } else if (field_len_ + len > FILE_SQL_MAX_FIELD_LEN) {
    ret = OB_SIZE_OVERFLOW;
  } else if (field_len_ + len > field_cap_) {
    int64_t new_cap = field_cap_ * 2;
    while (new_cap < field_len_ + len) {
      new_cap *= 2;
    }
    char *new_buf = static_cast<char *>(arena_.alloc(new_cap));
    if (OB_ISNULL(new_buf)) {
      ret = OB_ALLOCATE_MEMORY_FAILED;
    } else {
      if (field_len_ > 0) {
        MEMCPY(new_buf, field_buf_, field_len_);
      }
      field_buf_ = new_buf;
      field_cap_ = new_cap;
    }
  }
  if (OB_SUCC(ret)) {
    MEMCPY(field_buf_ + field_len_, ptr, len);
    field_len_ += len;
  }
  return ret;
}

int ObFileSqlCsvScanner::next_record(ObIArray<ObFileSqlCell> &cells)
{
  int ret = OB_SUCCESS;
  if (!opened_) {
    ret = OB_NOT_INIT;
  } else {
    while (OB_SUCC(ret)) {
      cells.reuse();
      ret = read_record(cells);
      if (OB_SUCC(ret) && 1 == cells.count() && !cells.at(0).quoted_ && 0 == cells.at(0).len_) {
        // skip a blank line, it does not represent a data row
        continue;
      }
      break;
    }
  }
  return ret;
}

int ObFileSqlCsvScanner::read_record(ObIArray<ObFileSqlCell> &cells)
{
  int ret = OB_SUCCESS;
  bool in_quote = false;
  bool field_start = true;
  bool quoted_field = false;
  bool record_done = false;
  int64_t cell_begin = 0;
  field_len_ = 0;
  record_line_no_ = line_no_;
  while (OB_SUCC(ret) && !record_done) {
    if (buf_pos_ >= buf_len_) {
      if (OB_FAIL(refill())) {
        break;
      }
      if (buf_pos_ >= buf_len_) {
        // end of file
        if (field_start && 0 == field_len_ && 0 == cells.count()) {
          ret = OB_ITER_END;
        } else {
          ObFileSqlCell cell;
          cell.ptr_ = field_buf_ + cell_begin;
          cell.len_ = static_cast<int32_t>(field_len_ - cell_begin);
          cell.quoted_ = quoted_field;
          ret = cells.push_back(cell);
        }
        record_done = true;
        break;
      }
    }
    const char *p = buf_ + buf_pos_;
    const int64_t avail = buf_len_ - buf_pos_;
    if (in_quote) {
      // copy the run up to the next quote / escape character as a whole
      int64_t run = avail;
      const char *quote_pos = static_cast<const char *>(memchr(p, options_.enclose_, avail));
      const char *esc_pos = (options_.escape_ != options_.enclose_)
                                ? static_cast<const char *>(memchr(p, options_.escape_, avail))
                                : NULL;
      const char *hit = NULL;
      if (NULL == quote_pos) {
        hit = esc_pos;
      } else if (NULL == esc_pos) {
        hit = quote_pos;
      } else {
        hit = (quote_pos < esc_pos) ? quote_pos : esc_pos;
      }
      if (NULL != hit) {
        run = hit - p;
      }
      if (run > 0) {
        if (OB_FAIL(append_to_field(p, run))) {
        } else {
          // count embedded newlines for diagnostics
          const char *scan = p;
          const char *nl = NULL;
          while (NULL != (nl = static_cast<const char *>(memchr(scan, '\n', run - (scan - p))))) {
            ++line_no_;
            scan = nl + 1;
          }
          buf_pos_ += run;
        }
        continue;
      }
      const char c = p[0];
      if (c == options_.enclose_) {
        bool is_escaped = false;
        if (options_.escape_ == options_.enclose_) {
          // a doubled quote inside a quoted field is one literal quote
          if (buf_pos_ + 1 >= buf_len_ && OB_FAIL(refill())) {
            break;
          } else if (buf_pos_ + 1 < buf_len_ && buf_[buf_pos_ + 1] == options_.enclose_) {
            if (OB_FAIL(append_to_field(&c, 1))) {
            } else {
              buf_pos_ += 2;
              is_escaped = true;
            }
          }
        }
        if (OB_SUCC(ret) && !is_escaped) {
          in_quote = false;
          ++buf_pos_;
        }
      } else {
        // escape_ != enclose_: the escape character quotes the next character
        if (buf_pos_ + 1 >= buf_len_ && OB_FAIL(refill())) {
          break;
        } else if (buf_pos_ + 1 >= buf_len_) {
          ret = OB_INVALID_DATA;
        } else {
          const char next = buf_[buf_pos_ + 1];
          if ('\n' == next) {
            ++line_no_;
          }
          if (OB_FAIL(append_to_field(&next, 1))) {
          } else {
            buf_pos_ += 2;
          }
        }
      }
    } else {
      // copy a whole run of ordinary characters
      int64_t run = avail;
      for (int64_t i = 0; i < avail; ++i) {
        const char c = p[i];
        if (c == options_.field_term_ || '\r' == c || '\n' == c
            || (field_start && c == options_.enclose_)) {
          run = i;
          break;
        }
      }
      if (run > 0) {
        if (OB_FAIL(append_to_field(p, run))) {
        } else {
          buf_pos_ += run;
          field_start = false;
        }
        continue;
      }
      const char c = p[0];
      if (c == options_.enclose_ && field_start) {
        in_quote = true;
        quoted_field = true;
        field_start = false;
        ++buf_pos_;
      } else if (c == options_.field_term_) {
        ObFileSqlCell cell;
        cell.ptr_ = field_buf_ + cell_begin;
        cell.len_ = static_cast<int32_t>(field_len_ - cell_begin);
        cell.quoted_ = quoted_field;
        if (OB_FAIL(cells.push_back(cell))) {
        } else {
          cell_begin = field_len_;
          field_start = true;
          quoted_field = false;
          ++buf_pos_;
        }
      } else if ('\r' == c || '\n' == c) {
        if ('\n' == c) {
          ++line_no_;
        }
        ++buf_pos_;
        if ('\r' == c && buf_pos_ < buf_len_ && '\n' == buf_[buf_pos_]) {
          ++buf_pos_;
          ++line_no_;
        } else if ('\r' == c && buf_pos_ >= buf_len_) {
          // the \n of a CRLF pair may live in the next block; peek and drop it
          if (OB_FAIL(refill())) {
            break;
          }
          if (buf_pos_ < buf_len_ && '\n' == buf_[buf_pos_]) {
            ++buf_pos_;
            ++line_no_;
          }
        }
        ObFileSqlCell cell;
        cell.ptr_ = field_buf_ + cell_begin;
        cell.len_ = static_cast<int32_t>(field_len_ - cell_begin);
        cell.quoted_ = quoted_field;
        if (OB_SUCC(ret) && OB_FAIL(cells.push_back(cell))) {
        }
        record_done = true;
      } else {
        field_start = false;
        if (OB_FAIL(append_to_field(&c, 1))) {
        } else {
          ++buf_pos_;
        }
      }
    }
  }
  return ret;
}

ObFileSqlLineReader::ObFileSqlLineReader()
  : fp_(NULL),
    buf_(NULL),
    buf_cap_(0),
    buf_pos_(0),
    buf_len_(0),
    eof_(false),
    line_buf_(NULL),
    line_cap_(0),
    line_len_(0),
    line_no_(1),
    opened_(false)
{
}

ObFileSqlLineReader::~ObFileSqlLineReader()
{
  close();
}

void ObFileSqlLineReader::close()
{
  if (NULL != fp_) {
    ::fclose(fp_);
    fp_ = NULL;
  }
  if (NULL != buf_) {
    ::free(buf_);
    buf_ = NULL;
  }
  if (NULL != line_buf_) {
    ::free(line_buf_);
    line_buf_ = NULL;
  }
  buf_cap_ = 0;
  buf_pos_ = 0;
  buf_len_ = 0;
  line_cap_ = 0;
  line_len_ = 0;
  opened_ = false;
}

int ObFileSqlLineReader::open(const ObString &path)
{
  int ret = OB_SUCCESS;
  char path_buf[PATH_MAX + 1];
  close();
  if (path.empty() || path.length() > PATH_MAX) {
    ret = OB_INVALID_ARGUMENT;
  } else {
    MEMCPY(path_buf, path.ptr(), path.length());
    path_buf[path.length()] = '\0';
    if (NULL == (fp_ = ::fopen(path_buf, "rb"))) {
      ret = (ENOENT == errno) ? OB_FILE_NOT_EXIST : OB_IO_ERROR;
    } else if (NULL == (buf_ = static_cast<char *>(::malloc(FILE_SQL_READ_BUFFER_SIZE)))) {
      ret = OB_ALLOCATE_MEMORY_FAILED;
    } else if (NULL == (line_buf_ = static_cast<char *>(::malloc(FILE_SQL_INITIAL_FIELD_CAP)))) {
      ret = OB_ALLOCATE_MEMORY_FAILED;
    } else {
      buf_cap_ = FILE_SQL_READ_BUFFER_SIZE;
      line_cap_ = FILE_SQL_INITIAL_FIELD_CAP;
      buf_pos_ = 0;
      buf_len_ = static_cast<int64_t>(::fread(buf_, 1, buf_cap_, fp_));
      eof_ = (buf_len_ < buf_cap_);
      line_no_ = 1;
      line_len_ = 0;
      opened_ = true;
    }
  }
  return ret;
}

int ObFileSqlLineReader::rescan()
{
  int ret = OB_SUCCESS;
  if (!opened_ || NULL == fp_) {
    ret = OB_NOT_INIT;
  } else if (0 != ::fseek(fp_, 0, SEEK_SET)) {
    ret = OB_IO_ERROR;
  } else {
    buf_pos_ = 0;
    buf_len_ = static_cast<int64_t>(::fread(buf_, 1, buf_cap_, fp_));
    eof_ = (buf_len_ < buf_cap_);
    line_no_ = 1;
    line_len_ = 0;
  }
  return ret;
}

int ObFileSqlLineReader::read_raw_char(char &c, bool &eof)
{
  int ret = OB_SUCCESS;
  eof = false;
  if (buf_pos_ >= buf_len_) {
    if (eof_) {
      eof = true;
    } else {
      buf_pos_ = 0;
      buf_len_ = static_cast<int64_t>(::fread(buf_, 1, buf_cap_, fp_));
      if (0 == buf_len_) {
        eof_ = true;
        eof = true;
      } else {
        if (buf_len_ < buf_cap_) {
          eof_ = true;
        }
        c = buf_[buf_pos_++];
      }
    }
  } else {
    c = buf_[buf_pos_++];
  }
  return ret;
}

int ObFileSqlLineReader::next_line(ObString &line)
{
  int ret = OB_SUCCESS;
  bool eof = false;
  char c = 0;
  line.reset();
  line_len_ = 0;
  if (!opened_) {
    ret = OB_NOT_INIT;
  } else {
    while (OB_SUCC(ret)) {
      if (OB_FAIL(read_raw_char(c, eof))) {
      } else if (eof) {
        if (0 == line_len_) {
          ret = OB_ITER_END;
        }
        break;
      } else if ('\n' == c) {
        ++line_no_;
        break;
      } else {
        if ('\r' != c) {
          if (line_len_ >= FILE_SQL_MAX_FIELD_LEN) {
            ret = OB_SIZE_OVERFLOW;
          } else if (line_len_ + 1 > line_cap_) {
            const int64_t new_cap = line_cap_ * 2;
            char *new_buf = static_cast<char *>(::realloc(line_buf_, new_cap));
            if (NULL == new_buf) {
              ret = OB_ALLOCATE_MEMORY_FAILED;
            } else {
              line_buf_ = new_buf;
              line_cap_ = new_cap;
            }
          }
          if (OB_SUCC(ret)) {
            line_buf_[line_len_++] = c;
          }
        }
      }
    }
    if (OB_SUCC(ret)) {
      line.assign_ptr(line_buf_, static_cast<int32_t>(line_len_));
    }
  }
  return ret;
}

static int infer_csv_schema(const ObString &path,
                            const ObFileSqlCsvOptions &options,
                            ObIAllocator &alloc,
                            ObIArray<ObFileSqlColumnSchema> &columns,
                            int64_t &est_rows)
{
  int ret = OB_SUCCESS;
  ObFileSqlCsvScanner scanner;
  ObSEArray<ObFileSqlCell, 16> cells;
  ObFileSqlTypeInferrer inferrer;
  ObSEArray<ObString, 16> names;
  int64_t row_count = 0;
  if (OB_FAIL(scanner.open(path, options))) {
  } else if (OB_FAIL(scanner.next_record(cells))) {
    if (OB_ITER_END == ret) {
      ret = OB_INVALID_ARGUMENT;
    }
  } else if (cells.empty()) {
    ret = OB_INVALID_ARGUMENT;
  } else if (options.has_header_) {
    for (int64_t i = 0; OB_SUCC(ret) && i < cells.count(); ++i) {
      ObString name;
      ObString final_name;
      const ObString raw(cells.at(i).len_, cells.at(i).ptr_);
      if (OB_FAIL(ob_write_string(alloc, ob_file_sql_trim(raw), name))) {
      } else if (name.empty()) {
        ret = OB_INVALID_ARGUMENT;
      } else if (FALSE_IT(final_name = name)) {
      } else {
        // duplicate header names get a __N suffix (DuckDB style)
        int64_t dup = 1;
        bool conflict = true;
        while (OB_SUCC(ret) && conflict && dup < 1000) {
          conflict = false;
          for (int64_t k = 0; !conflict && k < names.count(); ++k) {
            conflict = (0 == names.at(k).case_compare(final_name));
          }
          if (conflict) {
            ObSqlString renamed;
            ++dup;
            if (OB_FAIL(renamed.append_fmt("%.*s__%ld", name.length(), name.ptr(), dup))) {
            } else if (OB_FAIL(ob_write_string(alloc, renamed.string(), final_name))) {
            }
          }
        }
        if (OB_SUCC(ret) && OB_FAIL(names.push_back(final_name))) {
        }
      }
    }
  } else {
    for (int64_t i = 0; OB_SUCC(ret) && i < cells.count(); ++i) {
      ObSqlString generated;
      ObString name;
      if (OB_FAIL(generated.append_fmt("column_%ld", i))) {
      } else if (OB_FAIL(ob_write_string(alloc, generated.string(), name))) {
      } else if (OB_FAIL(names.push_back(name))) {
      }
    }
  }
  if (OB_FAIL(ret)) {
  } else if (OB_FAIL(inferrer.init(names.count()))) {
  } else {
    do {
      cells.reuse();
      ret = scanner.next_record(cells);
      if (OB_ITER_END == ret) {
        ret = OB_SUCCESS;
        break;
      } else if (OB_FAIL(ret)) {
        // bad row diagnostics: row number and expected column count
        LOG_WARN("failed to read csv record", K(ret), "line", scanner.get_record_line_no());
        break;
      } else if (cells.count() != names.count()) {
        char row_info[256];
        const int64_t row_len = snprintf(row_info, sizeof(row_info),
                                         "csv row at line %ld (expected %ld columns, got %ld)",
                                         scanner.get_record_line_no(), names.count(),
                                         cells.count());
        (void)row_len;
        ret = OB_INVALID_ARGUMENT;
        LOG_WARN("bad csv row: column count mismatch", "line", scanner.get_record_line_no(),
                 "expected", names.count(), "actual", cells.count());
        LOG_USER_ERROR(OB_INVALID_ARGUMENT, row_info);
        break;
      } else {
        ++row_count;
        for (int64_t i = 0; OB_SUCC(ret) && i < cells.count(); ++i) {
          const ObString cell(cells.at(i).len_, cells.at(i).ptr_);
          if (!cells.at(i).quoted_
              && (cell.empty()
                  || (options.null_str_set_ && 0 == cell.compare(options.null_str_)))) {
            inferrer.add_null(i);
          } else {
            inferrer.add_value(i, cell);
          }
        }
      }
    } while (OB_SUCC(ret));
  }
  if (OB_FAIL(ret)) {
  } else if (OB_FAIL(inferrer.finalize(columns))) {
  } else {
    est_rows = row_count;
    for (int64_t i = 0; OB_SUCC(ret) && i < columns.count(); ++i) {
      columns.at(i).name_ = names.at(i);
    }
  }
  scanner.close();
  return ret;
}

static int infer_jsonl_schema(const ObString &path,
                              ObIAllocator &alloc,
                              ObIArray<ObFileSqlColumnSchema> &columns,
                              int64_t &est_rows)
{
  int ret = OB_SUCCESS;
  ObFileSqlLineReader reader;
  ObString line;
  ObSEArray<ObString, 16> names;
  ObFileSqlTypeInferrer inferrer;
  ObArenaAllocator value_alloc;
  int64_t row_count = 0;
  // pass 1: field union (first-seen order) and nested value rejection. Only key names are kept.
  if (OB_FAIL(reader.open(path))) {
  } else {
    while (OB_SUCC(ret)) {
      ret = reader.next_line(line);
      if (OB_ITER_END == ret) {
        ret = OB_SUCCESS;
        break;
      } else if (OB_FAIL(ret)) {
      } else if (line.empty() || ob_file_sql_trim(line).empty()) {
        // skip blank lines
      } else {
        rapidjson::Document doc;
        doc.Parse(line.ptr(), line.length());
        if (doc.HasParseError() || !doc.IsObject()) {
          ret = OB_INVALID_ARGUMENT;
          LOG_WARN("invalid json line", "line", reader.get_line_no() - 1);
        } else {
          for (rapidjson::Value::ConstMemberIterator it = doc.MemberBegin();
               OB_SUCC(ret) && it != doc.MemberEnd(); ++it) {
            if (it->value.IsObject() || it->value.IsArray()) {
              ret = OB_INVALID_ARGUMENT;
              LOG_WARN("nested json value is not supported", "line", reader.get_line_no() - 1);
            } else {
              ObString key(static_cast<int32_t>(it->name.GetStringLength()),
                           const_cast<char *>(it->name.GetString()));
              bool known = false;
              for (int64_t i = 0; !known && i < names.count(); ++i) {
                known = ObCharset::case_insensitive_equal(names.at(i), key);
              }
              if (!known) {
                ObString name;
                if (OB_FAIL(ob_write_string(alloc, key, name))) {
                } else if (OB_FAIL(names.push_back(name))) {
                }
              }
            }
          }
        }
      }
    }
    if (OB_FAIL(ret)) {
    } else if (names.empty()) {
      ret = OB_INVALID_ARGUMENT;
    } else if (OB_FAIL(inferrer.init(names.count()))) {
    } else if (OB_FAIL(reader.rescan())) {
    }
  }
  // pass 2: deterministic type inference across all rows (missing field => NULL)
  bool *seen = NULL;
  if (OB_FAIL(ret)) {
  } else if (OB_ISNULL(seen = static_cast<bool *>(value_alloc.alloc(sizeof(bool) * names.count())))) {
    ret = OB_ALLOCATE_MEMORY_FAILED;
  } else {
    while (OB_SUCC(ret)) {
      ret = reader.next_line(line);
      if (OB_ITER_END == ret) {
        ret = OB_SUCCESS;
        break;
      } else if (OB_FAIL(ret)) {
      } else if (line.empty() || ob_file_sql_trim(line).empty()) {
        // skip blank lines
      } else {
        rapidjson::Document doc;
        doc.Parse(line.ptr(), line.length());
        if (doc.HasParseError() || !doc.IsObject()) {
          ret = OB_INVALID_ARGUMENT;
        } else {
          ++row_count;
          for (int64_t i = 0; i < names.count(); ++i) {
            seen[i] = false;
          }
          for (rapidjson::Value::ConstMemberIterator it = doc.MemberBegin();
               OB_SUCC(ret) && it != doc.MemberEnd(); ++it) {
            ObString key(static_cast<int32_t>(it->name.GetStringLength()),
                         const_cast<char *>(it->name.GetString()));
            int64_t slot = -1;
            for (int64_t i = 0; -1 == slot && i < names.count(); ++i) {
              if (ObCharset::case_insensitive_equal(names.at(i), key)) {
                slot = i;
              }
            }
            if (OB_SUCC(ret) && slot >= 0) {
              ObString text;
              ObFileSqlType json_type = OB_FILE_SQL_TYPE_NULL;
              if (!ob_file_sql_json_scalar_to_text(it->value, value_alloc, text, json_type)) {
                ret = OB_ALLOCATE_MEMORY_FAILED;
              } else {
                seen[slot] = true;
                inferrer.add_typed_value(slot, json_type);
              }
            }
          }
          if (OB_SUCC(ret)) {
            for (int64_t i = 0; i < names.count(); ++i) {
              if (!seen[i]) {
                inferrer.add_null(i);
              }
            }
          }
          value_alloc.reuse();
          if (NULL == (seen = static_cast<bool *>(value_alloc.alloc(sizeof(bool) * names.count())))) {
            ret = OB_ALLOCATE_MEMORY_FAILED;
          }
        }
      }
    }
  }
  if (OB_SUCC(ret)) {
    if (OB_FAIL(inferrer.finalize(columns))) {
    } else {
      est_rows = row_count;
      for (int64_t i = 0; OB_SUCC(ret) && i < columns.count(); ++i) {
        columns.at(i).name_ = names.at(i);
      }
    }
  }
  reader.close();
  return ret;
}

int ob_file_sql_infer_schema(const ObString &path,
                             const ObFileSqlFormat format,
                             const ObFileSqlCsvOptions &csv_options,
                             ObIAllocator &alloc,
                             ObIArray<ObFileSqlColumnSchema> &columns,
                             int64_t &est_rows)
{
  int ret = OB_SUCCESS;
  est_rows = 0;
  columns.reuse();
  if (path.empty()) {
    ret = OB_INVALID_ARGUMENT;
  } else if (OB_FILE_SQL_CSV == format) {
    ret = infer_csv_schema(path, csv_options, alloc, columns, est_rows);
  } else if (OB_FILE_SQL_JSONL == format) {
    ret = infer_jsonl_schema(path, alloc, columns, est_rows);
  } else if (OB_FILE_SQL_PARQUET == format) {
    ret = ob_parquet_read_schema(path, alloc, columns, est_rows);
  } else if (OB_FILE_SQL_GLOB == format) {
    ObFileSqlColumnSchema column;
    column.type_ = OB_FILE_SQL_TYPE_VARCHAR;
    column.nullable_ = false;
    column.max_len_ = 1024;
    if (OB_FAIL(ob_write_string(alloc, ObString("file"), column.name_))) {
    } else if (OB_FAIL(columns.push_back(column))) {
    }
    if (OB_SUCC(ret)) {
      glob_t matches;
      MEMSET(&matches, 0, sizeof(matches));
      char pattern[PATH_MAX + 1];
      if (path.length() > PATH_MAX) {
        ret = OB_INVALID_ARGUMENT;
      } else {
        MEMCPY(pattern, path.ptr(), path.length());
        pattern[path.length()] = '\0';
        const int glob_ret = ::glob(pattern, 0, NULL, &matches);
        if (0 != glob_ret && GLOB_NOMATCH != glob_ret) {
          ret = OB_INVALID_ARGUMENT;
        } else {
          est_rows = static_cast<int64_t>(matches.gl_pathc);
        }
      }
      ::globfree(&matches);
    }
  } else {
    ret = OB_NOT_SUPPORTED;
  }
  if (OB_FAIL(ret)) {
    LOG_WARN("failed to infer file schema", K(ret), K(path), K(format));
  }
  return ret;
}

} // namespace sql
} // namespace oceanbase
