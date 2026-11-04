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

#ifndef OCEANBASE_SQL_ENGINE_FILE_OB_FILE_JSON_UTILS_H_
#define OCEANBASE_SQL_ENGINE_FILE_OB_FILE_JSON_UTILS_H_

#include <rapidjson/document.h>
#include "lib/string/ob_string.h"
#include "lib/allocator/ob_allocator.h"
#include "sql/engine/file/ob_file_scan_utils.h"

namespace oceanbase
{
namespace sql
{

// Convert one JSON scalar to the text representation used by the file scan operator.
// Nested objects and arrays are rejected by the callers (JSONL only supports flat objects).
inline bool ob_file_sql_json_scalar_to_text(const rapidjson::Value &value,
                                            common::ObIAllocator &alloc,
                                            common::ObString &text,
                                            ObFileSqlType &json_type)
{
  bool ok = true;
  text.reset();
  json_type = OB_FILE_SQL_TYPE_VARCHAR;
  if (value.IsString()) {
    json_type = OB_FILE_SQL_TYPE_VARCHAR;
    const int32_t len = static_cast<int32_t>(value.GetStringLength());
    char *buf = static_cast<char *>(alloc.alloc(len + 1));
    if (OB_ISNULL(buf)) {
      ok = false;
    } else {
      if (len > 0) {
        MEMCPY(buf, value.GetString(), len);
      }
      buf[len] = '\0';
      text.assign_ptr(buf, len);
    }
  } else if (value.IsBool()) {
    json_type = OB_FILE_SQL_TYPE_BOOLEAN;
    const char *literal = value.GetBool() ? "true" : "false";
    const int32_t len = static_cast<int32_t>(strlen(literal));
    char *buf = static_cast<char *>(alloc.alloc(len));
    if (OB_ISNULL(buf)) {
      ok = false;
    } else {
      MEMCPY(buf, literal, len);
      text.assign_ptr(buf, len);
    }
  } else if (value.IsInt64() || value.IsInt() || value.IsUint()) {
    json_type = OB_FILE_SQL_TYPE_BIGINT;
    char tmp[32];
    const int64_t n = (value.IsInt64() || value.IsInt())
                          ? snprintf(tmp, sizeof(tmp), "%lld",
                                     static_cast<long long>(value.IsInt() ? value.GetInt()
                                                                          : value.GetInt64()))
                          : snprintf(tmp, sizeof(tmp), "%llu",
                                     static_cast<unsigned long long>(value.GetUint()));
    char *buf = static_cast<char *>(alloc.alloc(n + 1));
    if (OB_ISNULL(buf)) {
      ok = false;
    } else {
      MEMCPY(buf, tmp, n + 1);
      text.assign_ptr(buf, static_cast<int32_t>(n));
    }
  } else if (value.IsUint64()) {
    json_type = OB_FILE_SQL_TYPE_BIGINT;
    char tmp[32];
    const uint64_t v = value.GetUint64();
    int64_t n = 0;
    if (v <= static_cast<uint64_t>(INT64_MAX)) {
      n = snprintf(tmp, sizeof(tmp), "%lld", static_cast<long long>(v));
    } else {
      // out of the BIGINT range: keep it as a double, the same way the type inference widens
      json_type = OB_FILE_SQL_TYPE_DOUBLE;
      n = snprintf(tmp, sizeof(tmp), "%.17g", static_cast<double>(v));
    }
    char *buf = static_cast<char *>(alloc.alloc(n + 1));
    if (OB_ISNULL(buf)) {
      ok = false;
    } else {
      MEMCPY(buf, tmp, n + 1);
      text.assign_ptr(buf, static_cast<int32_t>(n));
    }
  } else if (value.IsDouble()) {
    json_type = OB_FILE_SQL_TYPE_DOUBLE;
    char tmp[64];
    const int64_t n = snprintf(tmp, sizeof(tmp), "%.17g", value.GetDouble());
    char *buf = static_cast<char *>(alloc.alloc(n + 1));
    if (OB_ISNULL(buf)) {
      ok = false;
    } else {
      MEMCPY(buf, tmp, n + 1);
      text.assign_ptr(buf, static_cast<int32_t>(n));
    }
  } else if (value.IsNull()) {
    json_type = OB_FILE_SQL_TYPE_NULL;
  } else {
    // nested object / array: JSONL only supports flat objects
    ok = false;
  }
  return ok;
}

} // namespace sql
} // namespace oceanbase

#endif // OCEANBASE_SQL_ENGINE_FILE_OB_FILE_JSON_UTILS_H_
