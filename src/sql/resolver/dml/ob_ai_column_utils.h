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

#ifndef OCEANBASE_SQL_RESOLVER_DML_OB_AI_COLUMN_UTILS_H_
#define OCEANBASE_SQL_RESOLVER_DML_OB_AI_COLUMN_UTILS_H_

#include "lib/string/ob_string.h"
#include "share/schema/ob_table_schema.h"
#include "sql/session/ob_sql_session_info.h"

namespace oceanbase
{
namespace sql
{

// The AI column worker writes the generated result column itself. It marks its connection with
// the session user variable "@__ai_column_worker" so that the business SQL check below does not
// reject the internal write.
inline bool ai_column_internal_write(const ObSQLSessionInfo *session_info)
{
  bool internal = false;
  if (OB_NOT_NULL(session_info)) {
    const common::ObObj *value = session_info->get_user_variable_value(
        common::ObString::make_string("__ai_column_worker"));
    if (OB_NOT_NULL(value)) {
      if (value->is_integer_type()) {
        internal = (0 != value->get_int());
      } else if (value->is_string_type()) {
        internal = (0 == value->get_string().compare("1"));
      }
    }
  }
  return internal;
}

// An AI result column always has a hidden companion column named "__ai_state_<column name>".
inline bool is_ai_result_column(const share::schema::ObTableSchema &table_schema,
                                const uint64_t column_id)
{
  bool is_ai = false;
  const share::schema::ObColumnSchemaV2 *column = table_schema.get_column_schema(column_id);
  if (OB_NOT_NULL(column) && !column->is_hidden()) {
    const common::ObString name = column->get_column_name_str();
    char state_name[common::OB_MAX_COLUMN_NAME_LENGTH];
    if (!name.empty()) {
      const int64_t len = snprintf(state_name, sizeof(state_name), "__ai_state_%.*s",
                                   name.length(), name.ptr());
      if (len > 0 && len < static_cast<int64_t>(sizeof(state_name))) {
        const share::schema::ObColumnSchemaV2 *state_column =
            table_schema.get_column_schema(common::ObString(static_cast<int32_t>(len), state_name));
        is_ai = (OB_NOT_NULL(state_column));
      }
    }
  }
  return is_ai;
}

} // namespace sql
} // namespace oceanbase

#endif // OCEANBASE_SQL_RESOLVER_DML_OB_AI_COLUMN_UTILS_H_
