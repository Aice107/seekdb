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

#ifndef _OB_LOG_FILE_TABLE_H
#define _OB_LOG_FILE_TABLE_H
#include "sql/optimizer/ob_logical_operator.h"

namespace oceanbase
{
namespace sql
{
class FileTablePath;
struct ObFileTableDef;

// Logical operator of the streaming file table scan (read_csv / read_json / read_parquet / glob).
class ObLogFileTable : public ObLogicalOperator
{
public:
  ObLogFileTable(ObLogPlan &plan)
    : ObLogicalOperator(plan),
      table_id_(common::OB_INVALID_ID),
      table_name_(),
      file_table_def_(NULL),
      column_exprs_() {}
  virtual ~ObLogFileTable() {}
  virtual int est_cost() override;
  virtual int do_re_est_cost(EstimateCostInfo &param, double &card, double &op_cost,
                             double &cost) override;
  virtual int compute_equal_set() override;
  virtual int compute_table_set() override;
  virtual int get_op_exprs(ObIArray<ObRawExpr *> &all_exprs) override;
  virtual int allocate_expr_post(ObAllocExprContext &ctx) override;
  virtual int inner_replace_op_exprs(ObRawExprReplacer &replacer) override;
  virtual int get_plan_item_info(PlanText &plan_text, ObSqlPlanItem &plan_item) override;
  int allocate_dummy_output();
  inline void set_table_id(const uint64_t table_id) { table_id_ = table_id; }
  inline uint64_t get_table_id() const { return table_id_; }
  inline void set_table_name(const common::ObString &table_name) { table_name_ = table_name; }
  inline const common::ObString &get_table_name() const { return table_name_; }
  inline void set_file_table_def(const ObFileTableDef *table_def) { file_table_def_ = table_def; }
  inline const ObFileTableDef *get_file_table_def() const { return file_table_def_; }
  inline common::ObIArray<ObColumnRefRawExpr *> &get_column_exprs() { return column_exprs_; }
  inline const common::ObIArray<ObColumnRefRawExpr *> &get_column_exprs() const
  {
    return column_exprs_;
  }
private:
  uint64_t table_id_;
  common::ObString table_name_;
  const ObFileTableDef *file_table_def_;
  common::ObSEArray<ObColumnRefRawExpr *, 16, common::ModulePageAllocator, true> column_exprs_;
  DISALLOW_COPY_AND_ASSIGN(ObLogFileTable);
};

} // namespace sql
} // namespace oceanbase
#endif // _OB_LOG_FILE_TABLE_H
