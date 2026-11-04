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

#ifndef OCEANBASE_SQL_ENGINE_FILE_OB_FILE_SCAN_UTILS_H_
#define OCEANBASE_SQL_ENGINE_FILE_OB_FILE_SCAN_UTILS_H_

#include "lib/string/ob_string.h"
#include "lib/container/ob_se_array.h"
#include "lib/allocator/ob_allocator.h"
#include "lib/allocator/page_arena.h"
#include "common/object/ob_obj_type.h"

namespace oceanbase
{
namespace sql
{

// File SQL table function formats.
enum ObFileSqlFormat : int32_t
{
  OB_FILE_SQL_CSV = 0,
  OB_FILE_SQL_JSONL = 1,
  OB_FILE_SQL_PARQUET = 2,
  OB_FILE_SQL_GLOB = 3,
  OB_FILE_SQL_DESCRIBE = 4,
};

// Deterministic set of inferred column types (see competition requirement).
enum ObFileSqlType : int32_t
{
  OB_FILE_SQL_TYPE_NULL = 0,
  OB_FILE_SQL_TYPE_BIGINT = 1,
  OB_FILE_SQL_TYPE_DOUBLE = 2,
  OB_FILE_SQL_TYPE_BOOLEAN = 3,
  OB_FILE_SQL_TYPE_VARCHAR = 4,
  OB_FILE_SQL_TYPE_DATE = 5,
  OB_FILE_SQL_TYPE_DATETIME = 6,
};

struct ObFileSqlCsvOptions
{
  ObFileSqlCsvOptions()
    : field_term_(','),
      line_term_('\n'),
      enclose_('"'),
      escape_('"'),
      has_header_(true),
      null_str_(),
      null_str_set_(false) {}
  char field_term_;
  char line_term_;
  char enclose_;
  char escape_;
  bool has_header_;
  common::ObString null_str_;
  bool null_str_set_;
  TO_STRING_KV(K_(field_term), K_(line_term), K_(enclose), K_(escape),
               K_(has_header), K_(null_str), K_(null_str_set));
};

struct ObFileSqlColumnSchema
{
  ObFileSqlColumnSchema() : name_(), type_(OB_FILE_SQL_TYPE_NULL), nullable_(true), max_len_(0) {}
  common::ObString name_;
  ObFileSqlType type_;
  bool nullable_;
  int64_t max_len_;
  TO_STRING_KV(K_(name), K_(type), K_(nullable), K_(max_len));
};

struct ObFileSqlFileInfo
{
  ObFileSqlFileInfo() : size_(-1), mtime_(-1), inode_(-1) {}
  bool is_valid() const { return size_ >= 0 && mtime_ >= 0; }
  int64_t size_;
  int64_t mtime_;
  int64_t inode_;
  TO_STRING_KV(K_(size), K_(mtime), K_(inode));
};

struct ObFileSqlCell
{
  ObFileSqlCell() : ptr_(NULL), len_(0), quoted_(false), null_(false) {}
  const char *ptr_;
  int32_t len_;
  bool quoted_;
  bool null_;
};

// Return the DuckDB style type name of an inferred type.
const char *ob_file_sql_type_name(const ObFileSqlType type);

// Map an inferred type to the storage ObObjType used by the executor.
common::ObObjType ob_file_sql_obj_type(const ObFileSqlType type);

// stat(2) wrapper used for file change detection.
int ob_file_sql_stat_file(const common::ObString &path, ObFileSqlFileInfo &info);

// Strict helpers shared by schema inference and value conversion.
bool ob_file_sql_parse_int(const common::ObString &text, int64_t &value);
bool ob_file_sql_parse_double(const common::ObString &text, double &value);
bool ob_file_sql_is_bool(const common::ObString &text, bool &value);
bool ob_file_sql_parse_date(const common::ObString &text, int32_t &days);
bool ob_file_sql_parse_datetime(const common::ObString &text, int64_t &value);

// Normalize a CSV cell: trim spaces for type inference / numeric conversion.
common::ObString ob_file_sql_trim(const common::ObString &text);

// Deterministic type inference with widening rules.
class ObFileSqlTypeInferrer
{
public:
  ObFileSqlTypeInferrer() : types_(), nullable_(), seen_() {}
  int init(const int64_t column_cnt);
  void add_null(const int64_t col);
  // classify the text value on its own (CSV semantics)
  void add_value(const int64_t col, const common::ObString &text);
  // add a value whose type is already known (JSON semantics)
  void add_typed_value(const int64_t col, const ObFileSqlType type);
  int finalize(common::ObIArray<ObFileSqlColumnSchema> &columns) const;
private:
  common::ObSEArray<ObFileSqlType, 16> types_;
  common::ObSEArray<bool, 16> nullable_;
  common::ObSEArray<bool, 16> seen_;
};

// Streaming CSV record scanner (64KB block buffered, records are materialized one at a time).
class ObFileSqlCsvScanner
{
public:
  ObFileSqlCsvScanner();
  ~ObFileSqlCsvScanner();
  // The cells returned by next_record() point into an internal arena that is reused per record.
  int open(const common::ObString &path, const ObFileSqlCsvOptions &options);
  // OB_ITER_END when the file is exhausted.
  int next_record(common::ObIArray<ObFileSqlCell> &cells);
  int rescan();
  void close();
  bool is_opened() const { return opened_; }
  int64_t get_line_no() const { return line_no_; }
  int64_t get_record_line_no() const { return record_line_no_; }
private:
  int read_raw_char(char &c, bool &eof);
  int peek_raw_char(char &c, bool &eof);
  int refill();
  int append_to_field(const char *ptr, const int64_t len);
  int read_record(common::ObIArray<ObFileSqlCell> &cells);
  void reset();
private:
  FILE *fp_;
  char *buf_;
  int64_t buf_cap_;
  int64_t buf_pos_;
  int64_t buf_len_;
  bool eof_;
  ObFileSqlCsvOptions options_;
  common::ObArenaAllocator arena_;
  char *field_buf_;
  int64_t field_cap_;
  int64_t field_len_;
  int64_t line_no_;
  int64_t record_line_no_;
  bool opened_;
  DISALLOW_COPY_AND_ASSIGN(ObFileSqlCsvScanner);
};

// Buffered line reader used by JSONL (streams, memory is bounded by the longest line).
class ObFileSqlLineReader
{
public:
  ObFileSqlLineReader();
  ~ObFileSqlLineReader();
  int open(const common::ObString &path);
  // OB_ITER_END at the end of the file. The returned line excludes the trailing CR/LF.
  int next_line(common::ObString &line);
  int rescan();
  void close();
  int64_t get_line_no() const { return line_no_; }
private:
  int read_raw_char(char &c, bool &eof);
private:
  FILE *fp_;
  char *buf_;
  int64_t buf_cap_;
  int64_t buf_pos_;
  int64_t buf_len_;
  bool eof_;
  char *line_buf_;
  int64_t line_cap_;
  int64_t line_len_;
  int64_t line_no_;
  bool opened_;
  DISALLOW_COPY_AND_ASSIGN(ObFileSqlLineReader);
};

// Infer the schema of a file. Full scan for CSV/JSONL (all rows are examined), footer only
// for parquet. Only column metadata is kept, no data row is materialized.
int ob_file_sql_infer_schema(const common::ObString &path,
                             const ObFileSqlFormat format,
                             const ObFileSqlCsvOptions &csv_options,
                             common::ObIAllocator &alloc,
                             common::ObIArray<ObFileSqlColumnSchema> &columns,
                             int64_t &est_rows);

} // namespace sql
} // namespace oceanbase

#endif // OCEANBASE_SQL_ENGINE_FILE_OB_FILE_SCAN_UTILS_H_
