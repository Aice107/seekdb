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

#include "sql/engine/file/ob_file_reader.h"
#include "sql/engine/file/ob_file_scan_utils.h"
#include "sql/engine/file/ob_file_json_utils.h"
#include "sql/engine/file/ob_file_parquet_reader.h"
#include "lib/charset/ob_charset.h"

#include <glob.h>
#include <limits.h>
#include <stdlib.h>

namespace oceanbase
{
namespace sql
{

using namespace common;

namespace
{

class ObFileSqlCsvReader : public ObFileSqlReader
{
public:
  ObFileSqlCsvReader() : scanner_(), schema_(NULL), projection_(NULL), options_(), opened_(false) {}
  virtual ~ObFileSqlCsvReader() { close(); }
  virtual int open(const ObFileSqlReadParam &param) override
  {
    int ret = OB_SUCCESS;
    close();
    options_ = param.csv_options_;
    schema_ = param.schema_;
    projection_ = param.projection_;
    if (OB_ISNULL(schema_) || OB_ISNULL(projection_) || param.path_.empty()) {
      ret = OB_INVALID_ARGUMENT;
    } else if (OB_FAIL(scanner_.open(param.path_, options_))) {
    } else {
      opened_ = true;
      if (options_.has_header_) {
        // the header is consumed by the schema inference, skip it again at execution
        ObSEArray<ObFileSqlCell, 16> header;
        if (OB_FAIL(scanner_.next_record(header))) {
          if (OB_ITER_END == ret) {
            ret = OB_INVALID_ARGUMENT;
          }
        }
      }
    }
    return ret;
  }
  virtual int next_row(ObIArray<ObFileSqlCell> &cells) override
  {
    int ret = OB_SUCCESS;
    ObSEArray<ObFileSqlCell, 16> record;
    cells.reuse();
    if (!opened_) {
      ret = OB_NOT_INIT;
    } else if (OB_FAIL(scanner_.next_record(record))) {
    } else if (record.count() != schema_->count()) {
      ret = OB_INVALID_ARGUMENT;
      LOG_WARN("bad csv row: column count mismatch", "line", scanner_.get_record_line_no(),
               "expected", schema_->count(), "actual", record.count());
    } else {
      for (int64_t i = 0; OB_SUCC(ret) && i < projection_->count(); ++i) {
        const int64_t col = projection_->at(i);
        if (col < 0 || col >= record.count()) {
          ret = OB_INVALID_ARGUMENT;
        } else {
          ObFileSqlCell cell = record.at(col);
          const ObString text(cell.len_, cell.ptr_);
          if (!cell.quoted_
              && (text.empty()
                  || (options_.null_str_set_ && 0 == text.compare(options_.null_str_)))) {
            cell.null_ = true;
            cell.len_ = 0;
          }
          if (OB_FAIL(cells.push_back(cell))) {
          }
        }
      }
    }
    return ret;
  }
  virtual int rescan() override
  {
    int ret = OB_SUCCESS;
    if (!opened_) {
      ret = OB_NOT_INIT;
    } else if (OB_FAIL(scanner_.rescan())) {
    } else if (options_.has_header_) {
      ObSEArray<ObFileSqlCell, 16> header;
      if (OB_FAIL(scanner_.next_record(header))) {
        if (OB_ITER_END == ret) {
          ret = OB_INVALID_ARGUMENT;
        }
      }
    }
    return ret;
  }
  virtual void close() override
  {
    scanner_.close();
    opened_ = false;
  }
private:
  ObFileSqlCsvScanner scanner_;
  const ObIArray<ObFileSqlColumnSchema> *schema_;
  const ObIArray<int64_t> *projection_;
  ObFileSqlCsvOptions options_;
  bool opened_;
};

class ObFileSqlJsonlReader : public ObFileSqlReader
{
public:
  ObFileSqlJsonlReader()
    : reader_(), schema_(NULL), projection_(NULL), arena_(), opened_(false), line_no_(0) {}
  virtual ~ObFileSqlJsonlReader() { close(); }
  virtual int open(const ObFileSqlReadParam &param) override
  {
    int ret = OB_SUCCESS;
    close();
    schema_ = param.schema_;
    projection_ = param.projection_;
    if (OB_ISNULL(schema_) || OB_ISNULL(projection_) || param.path_.empty()) {
      ret = OB_INVALID_ARGUMENT;
    } else if (OB_FAIL(reader_.open(param.path_))) {
    } else {
      opened_ = true;
    }
    return ret;
  }
  virtual int next_row(ObIArray<ObFileSqlCell> &cells) override
  {
    int ret = OB_SUCCESS;
    ObString line;
    cells.reuse();
    if (!opened_) {
      ret = OB_NOT_INIT;
    } else {
      while (OB_SUCC(ret)) {
        ret = reader_.next_line(line);
        if (OB_ITER_END == ret) {
          break;
        } else if (OB_FAIL(ret)) {
        } else if (line.empty() || ob_file_sql_trim(line).empty()) {
          continue;
        } else {
          line_no_ = reader_.get_line_no() - 1;
          break;
        }
      }
      if (OB_ITER_END == ret) {
        // no more data
      } else if (OB_FAIL(ret)) {
      } else {
        rapidjson::Document doc;
        doc.Parse(line.ptr(), line.length());
        if (doc.HasParseError() || !doc.IsObject()) {
          ret = OB_INVALID_ARGUMENT;
          LOG_WARN("invalid json line", K(line_no_));
        } else {
          arena_.reuse();
          for (int64_t i = 0; OB_SUCC(ret) && i < projection_->count(); ++i) {
            const int64_t col = projection_->at(i);
            if (col < 0 || col >= schema_->count()) {
              ret = OB_INVALID_ARGUMENT;
            } else {
              const ObString &name = schema_->at(col).name_;
              ObFileSqlCell cell;
              bool found = false;
              for (rapidjson::Value::ConstMemberIterator it = doc.MemberBegin();
                   OB_SUCC(ret) && !found && it != doc.MemberEnd(); ++it) {
                ObString key(static_cast<int32_t>(it->name.GetStringLength()),
                             const_cast<char *>(it->name.GetString()));
                if (!ObCharset::case_insensitive_equal(name, key)) {
                  continue;
                }
                found = true;
                if (it->value.IsNull()) {
                  cell.null_ = true;
                } else if (it->value.IsObject() || it->value.IsArray()) {
                  ret = OB_INVALID_ARGUMENT;
                  LOG_WARN("nested json value is not supported", K(line_no_), K(name));
                } else {
                  ObString text;
                  ObFileSqlType json_type = OB_FILE_SQL_TYPE_NULL;
                  if (!ob_file_sql_json_scalar_to_text(it->value, arena_, text, json_type)) {
                    ret = OB_ALLOCATE_MEMORY_FAILED;
                  } else {
                    cell.ptr_ = text.ptr();
                    cell.len_ = text.length();
                  }
                }
              }
              // a missing field is NULL
              if (OB_SUCC(ret) && !found) {
                cell = ObFileSqlCell();
                cell.null_ = true;
              }
              if (OB_SUCC(ret) && OB_FAIL(cells.push_back(cell))) {
              }
            }
          }
        }
      }
    }
    return ret;
  }
  virtual int rescan() override
  {
    int ret = OB_SUCCESS;
    if (!opened_) {
      ret = OB_NOT_INIT;
    } else {
      ret = reader_.rescan();
    }
    return ret;
  }
  virtual void close() override
  {
    reader_.close();
    opened_ = false;
  }
private:
  ObFileSqlLineReader reader_;
  const ObIArray<ObFileSqlColumnSchema> *schema_;
  const ObIArray<int64_t> *projection_;
  ObArenaAllocator arena_;
  bool opened_;
  int64_t line_no_;
};

class ObFileSqlGlobReader : public ObFileSqlReader
{
public:
  ObFileSqlGlobReader()
    : alloc_arena_(), files_(), idx_(0), opened_(false), has_output_(false) {}
  virtual ~ObFileSqlGlobReader() { close(); }
  virtual int open(const ObFileSqlReadParam &param) override
  {
    int ret = OB_SUCCESS;
    close();
    has_output_ = (OB_NOT_NULL(param.projection_) && param.projection_->count() > 0);
    glob_t matches;
    MEMSET(&matches, 0, sizeof(matches));
    char pattern[PATH_MAX + 1];
    if (param.path_.empty() || param.path_.length() > PATH_MAX) {
      ret = OB_INVALID_ARGUMENT;
    } else {
      MEMCPY(pattern, param.path_.ptr(), param.path_.length());
      pattern[param.path_.length()] = '\0';
      const int glob_ret = ::glob(pattern, 0, NULL, &matches);
      if (0 != glob_ret && GLOB_NOMATCH != glob_ret) {
        ret = OB_INVALID_ARGUMENT;
      } else {
        for (size_t i = 0; OB_SUCC(ret) && i < matches.gl_pathc; ++i) {
          ObString file;
          if (OB_FAIL(ob_write_string(alloc_arena_, ObString(matches.gl_pathv[i]), file))) {
          } else if (OB_FAIL(files_.push_back(file))) {
          }
        }
        idx_ = 0;
        opened_ = true;
      }
    }
    ::globfree(&matches);
    return ret;
  }
  virtual int next_row(ObIArray<ObFileSqlCell> &cells) override
  {
    int ret = OB_SUCCESS;
    cells.reuse();
    if (!opened_) {
      ret = OB_NOT_INIT;
    } else if (idx_ >= files_.count()) {
      ret = OB_ITER_END;
    } else {
      if (has_output_) {
        ObFileSqlCell cell;
        cell.ptr_ = files_.at(idx_).ptr();
        cell.len_ = files_.at(idx_).length();
        ret = cells.push_back(cell);
      }
      ++idx_;
    }
    return ret;
  }
  virtual int rescan() override
  {
    idx_ = 0;
    return opened_ ? OB_SUCCESS : OB_NOT_INIT;
  }
  virtual void close() override
  {
    files_.reset();
    alloc_arena_.reset();
    idx_ = 0;
    opened_ = false;
  }
private:
  ObArenaAllocator alloc_arena_;
  ObSEArray<ObString, 32> files_;
  int64_t idx_;
  bool opened_;
  bool has_output_;
};

class ObFileSqlDescribeReader : public ObFileSqlReader
{
public:
  ObFileSqlDescribeReader() : alloc_(), schema_(NULL), idx_(0), opened_(false) {}
  virtual ~ObFileSqlDescribeReader() { close(); }
  virtual int open(const ObFileSqlReadParam &param) override
  {
    int ret = OB_SUCCESS;
    close();
    schema_ = param.schema_;
    if (OB_ISNULL(schema_)) {
      ret = OB_INVALID_ARGUMENT;
    } else {
      idx_ = 0;
      opened_ = true;
    }
    return ret;
  }
  virtual int next_row(ObIArray<ObFileSqlCell> &cells) override
  {
    int ret = OB_SUCCESS;
    cells.reuse();
    if (!opened_) {
      ret = OB_NOT_INIT;
    } else if (idx_ >= schema_->count()) {
      ret = OB_ITER_END;
    } else {
      // column_name / column_type / null / key / default / extra
      const ObFileSqlColumnSchema &column = schema_->at(idx_);
      ObFileSqlCell cell_name;
      cell_name.ptr_ = column.name_.ptr();
      cell_name.len_ = column.name_.length();
      ObString type_text = ObString::make_string(ob_file_sql_type_name(column.type_));
      ObFileSqlCell cell_type;
      cell_type.ptr_ = type_text.ptr();
      cell_type.len_ = type_text.length();
      ObString null_text = ObString::make_string(column.nullable_ ? "YES" : "NO");
      ObFileSqlCell cell_null;
      cell_null.ptr_ = null_text.ptr();
      cell_null.len_ = null_text.length();
      ObFileSqlCell cell_empty;
      cell_empty.null_ = true;
      if (OB_FAIL(cells.push_back(cell_name))) {
      } else if (OB_FAIL(cells.push_back(cell_type))) {
      } else if (OB_FAIL(cells.push_back(cell_null))) {
      } else if (OB_FAIL(cells.push_back(cell_empty))) {
      } else if (OB_FAIL(cells.push_back(cell_empty))) {
      } else if (OB_FAIL(cells.push_back(cell_empty))) {
      } else {
        ++idx_;
      }
    }
    return ret;
  }
  virtual int rescan() override
  {
    idx_ = 0;
    return opened_ ? OB_SUCCESS : OB_NOT_INIT;
  }
  virtual void close() override
  {
    schema_ = NULL;
    idx_ = 0;
    opened_ = false;
  }
private:
  ObArenaAllocator alloc_;
  const ObIArray<ObFileSqlColumnSchema> *schema_;
  int64_t idx_;
  bool opened_;
};

} // anonymous namespace

int ob_file_sql_create_reader(const ObFileSqlFormat format, ObIAllocator &alloc,
                              ObFileSqlReader *&reader)
{
  int ret = OB_SUCCESS;
  reader = NULL;
  void *mem = NULL;
  switch (format) {
    case OB_FILE_SQL_CSV: {
      if (OB_ISNULL(mem = alloc.alloc(sizeof(ObFileSqlCsvReader)))) {
        ret = OB_ALLOCATE_MEMORY_FAILED;
      } else {
        reader = new (mem) ObFileSqlCsvReader();
      }
      break;
    }
    case OB_FILE_SQL_JSONL: {
      if (OB_ISNULL(mem = alloc.alloc(sizeof(ObFileSqlJsonlReader)))) {
        ret = OB_ALLOCATE_MEMORY_FAILED;
      } else {
        reader = new (mem) ObFileSqlJsonlReader();
      }
      break;
    }
    case OB_FILE_SQL_PARQUET:
      ret = ob_parquet_create_reader(alloc, reader);
      break;
    case OB_FILE_SQL_GLOB: {
      if (OB_ISNULL(mem = alloc.alloc(sizeof(ObFileSqlGlobReader)))) {
        ret = OB_ALLOCATE_MEMORY_FAILED;
      } else {
        reader = new (mem) ObFileSqlGlobReader();
      }
      break;
    }
    case OB_FILE_SQL_DESCRIBE: {
      if (OB_ISNULL(mem = alloc.alloc(sizeof(ObFileSqlDescribeReader)))) {
        ret = OB_ALLOCATE_MEMORY_FAILED;
      } else {
        reader = new (mem) ObFileSqlDescribeReader();
      }
      break;
    }
    default:
      ret = OB_NOT_SUPPORTED;
      break;
  }
  return ret;
}

} // namespace sql
} // namespace oceanbase
