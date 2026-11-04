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

#ifndef OCEANBASE_SQL_ENGINE_BASIC_OB_FILE_TABLE_OP_H_
#define OCEANBASE_SQL_ENGINE_BASIC_OB_FILE_TABLE_OP_H_

#include "sql/engine/ob_operator.h"
#include "sql/engine/file/ob_file_scan_utils.h"

namespace oceanbase
{
namespace sql
{

class ObFileSqlReader;

// Physical spec of a file table scan. The schema is inferred at resolve time and kept here so
// that execution never has to re-infer it, and so that a changed file can be detected.
class ObFileTableSpec : public ObOpSpec
{
  OB_UNIS_VERSION_V(1);
public:
  ObFileTableSpec(common::ObIAllocator &alloc, const ObPhyOperatorType type)
    : ObOpSpec(alloc, type),
      file_path_(),
      format_(OB_FILE_SQL_CSV),
      field_term_(','),
      line_term_('\n'),
      enclose_('"'),
      escape_('"'),
      has_header_(true),
      null_str_(),
      null_str_set_(false),
      column_names_(alloc),
      column_types_(alloc),
      column_nullable_(alloc),
      file_size_(-1),
      file_mtime_(-1),
      file_inode_(-1),
      est_rows_(0),
      column_exprs_(alloc),
      column_idxs_(alloc) {}
  INHERIT_TO_STRING_KV("op_spec", ObOpSpec, K_(file_path), K_(format), K_(est_rows));
public:
  common::ObString file_path_;
  int32_t format_;
  char field_term_;
  char line_term_;
  char enclose_;
  char escape_;
  bool has_header_;
  common::ObString null_str_;
  bool null_str_set_;
  common::ObFixedArray<common::ObString, common::ObIAllocator> column_names_;
  common::ObFixedArray<int32_t, common::ObIAllocator> column_types_;
  common::ObFixedArray<int32_t, common::ObIAllocator> column_nullable_;
  int64_t file_size_;
  int64_t file_mtime_;
  int64_t file_inode_;
  int64_t est_rows_;
  // output column expressions (only the columns referenced by the statement, column pruning)
  common::ObFixedArray<ObExpr *, common::ObIAllocator> column_exprs_;
  // file column index of every output expression
  common::ObFixedArray<int64_t, common::ObIAllocator> column_idxs_;
private:
  DISALLOW_COPY_AND_ASSIGN(ObFileTableSpec);
};

class ObFileTableOp : public ObOperator
{
public:
  ObFileTableOp(ObExecContext &exec_ctx, const ObOpSpec &spec, ObOpInput *input);
  virtual ~ObFileTableOp() {}
  virtual int inner_open() override;
  virtual int inner_rescan() override;
  virtual int inner_get_next_row() override;
  virtual int inner_get_next_batch(const int64_t max_row_cnt) override;
  virtual int inner_close() override;
  virtual void destroy() override { ObOperator::destroy(); }
private:
  int init_schema();
  int open_reader();
  int convert_cell(ObExpr *expr, ObDatum &datum, const ObFileSqlCell &cell,
                   const int32_t file_type);
  void release_reader();
private:
  ObFileSqlReader *reader_;
  common::ObSEArray<ObFileSqlColumnSchema, 16> schema_;
  common::ObSEArray<int64_t, 16> projection_;
  common::ObSEArray<ObFileSqlCell, 16> cells_;
  common::ObArenaAllocator batch_alloc_;
private:
  DISALLOW_COPY_AND_ASSIGN(ObFileTableOp);
};

} // namespace sql
} // namespace oceanbase

#endif // OCEANBASE_SQL_ENGINE_BASIC_OB_FILE_TABLE_OP_H_
