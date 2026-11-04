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

#include "sql/engine/basic/ob_file_table_op.h"
#include "sql/engine/file/ob_file_reader.h"
#include "sql/engine/ob_exec_context.h"

namespace oceanbase
{
using namespace common;
namespace sql
{

OB_SERIALIZE_MEMBER_INHERIT(ObFileTableSpec,
                            ObOpSpec,
                            file_path_,
                            format_,
                            field_term_,
                            line_term_,
                            enclose_,
                            escape_,
                            has_header_,
                            null_str_,
                            null_str_set_,
                            column_names_,
                            column_types_,
                            column_nullable_,
                            file_size_,
                            file_mtime_,
                            file_inode_,
                            est_rows_,
                            column_exprs_,
                            column_idxs_);

ObFileTableOp::ObFileTableOp(ObExecContext &exec_ctx, const ObOpSpec &spec, ObOpInput *input)
  : ObOperator(exec_ctx, spec, input),
    reader_(NULL),
    schema_(),
    projection_(),
    cells_(),
    batch_alloc_()
{
}

int ObFileTableOp::init_schema()
{
  int ret = OB_SUCCESS;
  schema_.reuse();
  projection_.reuse();
  if (MY_SPEC.column_names_.count() != MY_SPEC.column_types_.count()
      || MY_SPEC.column_names_.count() != MY_SPEC.column_nullable_.count()) {
    ret = OB_ERR_UNEXPECTED;
  }
  for (int64_t i = 0; OB_SUCC(ret) && i < MY_SPEC.column_names_.count(); ++i) {
    ObFileSqlColumnSchema column;
    column.name_ = MY_SPEC.column_names_.at(i);
    column.type_ = static_cast<ObFileSqlType>(MY_SPEC.column_types_.at(i));
    column.nullable_ = (0 != MY_SPEC.column_nullable_.at(i));
    if (OB_FAIL(schema_.push_back(column))) {
    }
  }
  for (int64_t i = 0; OB_SUCC(ret) && i < MY_SPEC.column_idxs_.count(); ++i) {
    if (OB_FAIL(projection_.push_back(MY_SPEC.column_idxs_.at(i)))) {
    }
  }
  return ret;
}

int ObFileTableOp::open_reader()
{
  int ret = OB_SUCCESS;
  const ObFileSqlFormat format = static_cast<ObFileSqlFormat>(MY_SPEC.format_);
  if (OB_SUCC(ret) && OB_FILE_SQL_GLOB != format) {
    ObFileSqlFileInfo info;
    if (OB_FAIL(ob_file_sql_stat_file(MY_SPEC.file_path_, info))) {
      LOG_WARN("failed to stat file sql file", K(ret), K(MY_SPEC.file_path_));
    } else if (MY_SPEC.file_size_ >= 0
               && (info.size_ != MY_SPEC.file_size_ || info.mtime_ != MY_SPEC.file_mtime_)) {
      // the file changed after the schema was inferred: refuse to return stale results
      ret = OB_INVALID_DATA;
      LOG_USER_ERROR(OB_INVALID_DATA, "file changed since schema inference");
      LOG_WARN("file changed since schema inference", K(MY_SPEC.file_path_),
               "expected_size", MY_SPEC.file_size_, "actual_size", info.size_,
               "expected_mtime", MY_SPEC.file_mtime_, "actual_mtime", info.mtime_);
    }
  }
  if (OB_SUCC(ret) && OB_ISNULL(reader_)) {
    ObFileSqlReadParam param;
    param.path_ = MY_SPEC.file_path_;
    param.format_ = format;
    param.csv_options_.field_term_ = MY_SPEC.field_term_;
    param.csv_options_.line_term_ = MY_SPEC.line_term_;
    param.csv_options_.enclose_ = MY_SPEC.enclose_;
    param.csv_options_.escape_ = MY_SPEC.escape_;
    param.csv_options_.has_header_ = MY_SPEC.has_header_;
    param.csv_options_.null_str_ = MY_SPEC.null_str_;
    param.csv_options_.null_str_set_ = MY_SPEC.null_str_set_;
    param.schema_ = &schema_;
    param.projection_ = &projection_;
    if (OB_FAIL(ob_file_sql_create_reader(format, ctx_.get_allocator(), reader_))) {
    } else if (OB_ISNULL(reader_)) {
      ret = OB_ERR_UNEXPECTED;
    } else if (OB_FAIL(reader_->open(param))) {
      LOG_WARN("failed to open file sql reader", K(ret), K(MY_SPEC.file_path_), K(format));
    }
  }
  return ret;
}

void ObFileTableOp::release_reader()
{
  if (NULL != reader_) {
    reader_->close();
    reader_->~ObFileSqlReader();
    reader_ = NULL;
  }
}

int ObFileTableOp::inner_open()
{
  int ret = OB_SUCCESS;
  batch_alloc_.reuse();
  if (OB_FAIL(init_schema())) {
  } else if (OB_FAIL(open_reader())) {
  }
  return ret;
}

int ObFileTableOp::inner_rescan()
{
  int ret = OB_SUCCESS;
  if (OB_FAIL(ObOperator::inner_rescan())) {
  } else if (OB_ISNULL(reader_)) {
    if (OB_FAIL(open_reader())) {
    }
  } else if (OB_FAIL(reader_->rescan())) {
  }
  batch_alloc_.reuse();
  return ret;
}

int ObFileTableOp::inner_close()
{
  release_reader();
  batch_alloc_.reset();
  schema_.reset();
  projection_.reset();
  cells_.reset();
  return OB_SUCCESS;
}

int ObFileTableOp::convert_cell(ObExpr *expr, ObDatum &datum, const ObFileSqlCell &cell,
                                const int32_t file_type)
{
  int ret = OB_SUCCESS;
  if (OB_ISNULL(expr)) {
    ret = OB_ERR_UNEXPECTED;
  } else if (cell.null_) {
    datum.set_null();
  } else {
    const ObString text(cell.len_, cell.ptr_);
    switch (file_type) {
      case ObVarcharType: {
        char *buf = static_cast<char *>(batch_alloc_.alloc(text.length() + 1));
        if (OB_ISNULL(buf)) {
          ret = OB_ALLOCATE_MEMORY_FAILED;
        } else {
          if (text.length() > 0) {
            MEMCPY(buf, text.ptr(), text.length());
          }
          buf[text.length()] = '\0';
          datum.set_string(buf, static_cast<uint32_t>(text.length()));
        }
        break;
      }
      case ObIntType: {
        int64_t value = 0;
        if (!ob_file_sql_parse_int(ob_file_sql_trim(text), value)) {
          ret = OB_INVALID_DATA;
          LOG_WARN("invalid integer cell", K(text));
        } else {
          datum.set_int(value);
        }
        break;
      }
      case ObDoubleType: {
        double value = 0;
        if (!ob_file_sql_parse_double(ob_file_sql_trim(text), value)) {
          ret = OB_INVALID_DATA;
          LOG_WARN("invalid double cell", K(text));
        } else {
          datum.set_double(value);
        }
        break;
      }
      case ObTinyIntType:
      case ObSmallIntType:
      case ObMediumIntType:
      case ObInt32Type: {
        bool bool_value = false;
        int64_t int_value = 0;
        if (ob_file_sql_is_bool(ob_file_sql_trim(text), bool_value)) {
          datum.set_int(bool_value ? 1 : 0);
        } else if (ob_file_sql_parse_int(ob_file_sql_trim(text), int_value)) {
          datum.set_int(int_value);
        } else {
          ret = OB_INVALID_DATA;
          LOG_WARN("invalid boolean cell", K(text));
        }
        break;
      }
      case ObDateType: {
        int32_t days = 0;
        if (!ob_file_sql_parse_date(ob_file_sql_trim(text), days)) {
          ret = OB_INVALID_DATA;
          LOG_WARN("invalid date cell", K(text));
        } else {
          datum.set_date(days);
        }
        break;
      }
      case ObDateTimeType: {
        int64_t usec = 0;
        if (!ob_file_sql_parse_datetime(ob_file_sql_trim(text), usec)) {
          ret = OB_INVALID_DATA;
          LOG_WARN("invalid datetime cell", K(text));
        } else {
          datum.set_datetime(usec);
        }
        break;
      }
      default:
        ret = OB_NOT_SUPPORTED;
        LOG_WARN("unsupported file table column type", K(file_type));
        break;
    }
  }
  return ret;
}

int ObFileTableOp::inner_get_next_row()
{
  int ret = OB_SUCCESS;
  clear_evaluated_flag();
  batch_alloc_.reuse();
  cells_.reuse();
  if (OB_FAIL(reader_->next_row(cells_))) {
  } else if (OB_UNLIKELY(cells_.count() != MY_SPEC.column_exprs_.count())) {
    ret = OB_ERR_UNEXPECTED;
    LOG_WARN("column count mismatch", K(cells_.count()), K(MY_SPEC.column_exprs_.count()));
  } else {
    for (int64_t i = 0; OB_SUCC(ret) && i < MY_SPEC.column_exprs_.count(); ++i) {
      ObExpr *expr = MY_SPEC.column_exprs_.at(i);
      const int64_t file_idx = MY_SPEC.column_idxs_.at(i);
      if (OB_ISNULL(expr)) {
        ret = OB_ERR_UNEXPECTED;
      } else if (file_idx < 0 || file_idx >= MY_SPEC.column_types_.count()) {
        ret = OB_ERR_UNEXPECTED;
      } else {
        // locate_datum_for_write resets the datum pointer to the reserved frame buffer
        ObDatum &datum = expr->locate_datum_for_write(eval_ctx_);
        if (OB_FAIL(convert_cell(expr, datum, cells_.at(i),
                                 MY_SPEC.column_types_.at(file_idx)))) {
        }
      }
    }
  }
  return ret;
}

int ObFileTableOp::inner_get_next_batch(const int64_t max_row_cnt)
{
  int ret = OB_SUCCESS;
  clear_evaluated_flag();
  clear_datum_eval_flag();
  batch_alloc_.reuse();
  int64_t capacity = max_row_cnt;
  if (capacity > MY_SPEC.max_batch_size_) {
    capacity = MY_SPEC.max_batch_size_;
  }
  if (capacity <= 0) {
    capacity = 1;
  }
  int64_t count = 0;
  bool iter_end = false;
  // reset the datum pointers of the reserved batch buffers before writing fixed width values
  for (int64_t i = 0; OB_SUCC(ret) && i < MY_SPEC.column_exprs_.count(); ++i) {
    ObExpr *expr = MY_SPEC.column_exprs_.at(i);
    if (OB_ISNULL(expr)) {
      ret = OB_ERR_UNEXPECTED;
    } else if (expr->is_batch_result()) {
      expr->locate_datums_for_update(eval_ctx_, capacity);
    }
  }
  for (; OB_SUCC(ret) && count < capacity; ++count) {
    cells_.reuse();
    ret = reader_->next_row(cells_);
    if (OB_ITER_END == ret) {
      iter_end = true;
      ret = OB_SUCCESS;
      break;
    } else if (OB_FAIL(ret)) {
      break;
    } else if (OB_UNLIKELY(cells_.count() != MY_SPEC.column_exprs_.count())) {
      ret = OB_ERR_UNEXPECTED;
      LOG_WARN("column count mismatch", K(cells_.count()), K(MY_SPEC.column_exprs_.count()));
    } else {
      for (int64_t i = 0; OB_SUCC(ret) && i < MY_SPEC.column_exprs_.count(); ++i) {
        ObExpr *expr = MY_SPEC.column_exprs_.at(i);
        const int64_t file_idx = MY_SPEC.column_idxs_.at(i);
        if (OB_ISNULL(expr)) {
          ret = OB_ERR_UNEXPECTED;
        } else if (file_idx < 0 || file_idx >= MY_SPEC.column_types_.count()) {
          ret = OB_ERR_UNEXPECTED;
        } else {
          ObDatum &datum = expr->is_batch_result()
                               ? expr->locate_batch_datums(eval_ctx_)[count]
                               : expr->locate_datum_for_write(eval_ctx_);
          if (OB_FAIL(convert_cell(expr, datum, cells_.at(i),
                                   MY_SPEC.column_types_.at(file_idx)))) {
          }
        }
      }
    }
  }
  if (OB_SUCC(ret)) {
    brs_.size_ = count;
    brs_.end_ = iter_end;
  }
  return ret;
}

} // namespace sql
} // namespace oceanbase
