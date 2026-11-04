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

#ifndef OCEANBASE_SQL_ENGINE_FILE_OB_FILE_READER_H_
#define OCEANBASE_SQL_ENGINE_FILE_OB_FILE_READER_H_

#include "sql/engine/file/ob_file_scan_utils.h"

namespace oceanbase
{
namespace sql
{

// Parameters shared by every file reader implementation.
struct ObFileSqlReadParam
{
  ObFileSqlReadParam()
    : path_(), format_(OB_FILE_SQL_CSV), csv_options_(), schema_(NULL), projection_(NULL) {}
  common::ObString path_;
  ObFileSqlFormat format_;
  ObFileSqlCsvOptions csv_options_;
  // full column schema of the file (inferred at resolve time)
  const common::ObIArray<ObFileSqlColumnSchema> *schema_;
  // file column indexes that the executor actually needs (column pruning)
  const common::ObIArray<int64_t> *projection_;
};

// A streaming row source. next_row() returns OB_ITER_END at the end of the data.
// Cells point into memory owned by the reader and stay valid until the next next_row() call.
class ObFileSqlReader
{
public:
  virtual ~ObFileSqlReader() {}
  virtual int open(const ObFileSqlReadParam &param) = 0;
  virtual int next_row(common::ObIArray<ObFileSqlCell> &cells) = 0;
  virtual int rescan() = 0;
  virtual void close() = 0;
};

// Factory: the returned reader is allocated from %alloc and must be destroyed by the caller.
int ob_file_sql_create_reader(const ObFileSqlFormat format, common::ObIAllocator &alloc,
                              ObFileSqlReader *&reader);

} // namespace sql
} // namespace oceanbase

#endif // OCEANBASE_SQL_ENGINE_FILE_OB_FILE_READER_H_
