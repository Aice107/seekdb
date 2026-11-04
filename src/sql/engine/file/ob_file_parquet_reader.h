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

#ifndef OCEANBASE_SQL_ENGINE_FILE_OB_FILE_PARQUET_READER_H_
#define OCEANBASE_SQL_ENGINE_FILE_OB_FILE_PARQUET_READER_H_

#include "sql/engine/file/ob_file_scan_utils.h"

namespace oceanbase
{
namespace sql
{

class ObFileSqlReader;

// Read the footer schema of a parquet file (no data page is touched).
int ob_parquet_read_schema(const common::ObString &path,
                           common::ObIAllocator &alloc,
                           common::ObIArray<ObFileSqlColumnSchema> &columns,
                           int64_t &num_rows);

// Create a streaming parquet reader. Data is decoded one row group at a time and only the
// projected columns are decoded (column pruning).
int ob_parquet_create_reader(common::ObIAllocator &alloc, ObFileSqlReader *&reader);

} // namespace sql
} // namespace oceanbase

#endif // OCEANBASE_SQL_ENGINE_FILE_OB_FILE_PARQUET_READER_H_
