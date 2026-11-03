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

#define USING_LOG_PREFIX SHARE_SCHEMA
#include "ob_inner_table_schema.h"

#include "share/schema/ob_schema_macro_define.h"
#include "share/schema/ob_table_schema.h"
#include "share/scn.h"

namespace oceanbase
{
using namespace share::schema;
using namespace common;
namespace share
{

int ObInnerTableSchema::v_ob_memory_schema(ObTableSchema &table_schema)
{
  int ret = OB_SUCCESS;
  uint64_t column_id = OB_APP_MIN_COLUMN_ID - 1;

  //generated fields:
  table_schema.set_database_id(OB_SYS_DATABASE_ID);
  table_schema.set_table_id(OB_V_OB_MEMORY_TID);
  table_schema.set_rowkey_split_pos(0);
  table_schema.set_progressive_merge_num(0);
  table_schema.set_rowkey_column_num(0);
  table_schema.set_load_type(TABLE_LOAD_TYPE_IN_DISK);
  table_schema.set_table_type(SYSTEM_VIEW);
  table_schema.set_index_type(INDEX_TYPE_IS_NOT);
  table_schema.set_def_type(TABLE_DEF_TYPE_INTERNAL);

  if (OB_SUCC(ret)) {
    if (OB_FAIL(table_schema.set_table_name(OB_V_OB_MEMORY_TNAME))) {
      LOG_ERROR("fail to set table_name", K(ret));
    }
  }

  if (OB_SUCC(ret)) {
    if (OB_FAIL(table_schema.set_compress_func_name(OB_DEFAULT_COMPRESS_FUNC_NAME))) {
      LOG_ERROR("fail to set compress_func_name", K(ret));
    }
  }
  table_schema.set_part_level(PARTITION_LEVEL_ZERO);
  table_schema.set_charset_type(ObCharset::get_default_charset());
  table_schema.set_collation_type(ObCharset::get_default_collation(ObCharset::get_default_charset()));

  if (OB_SUCC(ret)) {
    if (OB_FAIL(table_schema.set_view_definition(R"__( SELECT      ctx_name AS CTX_NAME,      mod_name AS MOD_NAME,      sum(COUNT) AS COUNT,      sum(hold) AS HOLD,      sum(USED) AS USED FROM     oceanbase.__all_virtual_memory_info WHERE         mod_type='user' GROUP BY ctx_name, mod_name ORDER BY ctx_name, mod_name )__"))) {
      LOG_ERROR("fail to set view_definition", K(ret));
    }
  }
  table_schema.set_index_using_type(USING_BTREE);
  table_schema.set_row_store_type(ENCODING_ROW_STORE);
  table_schema.set_store_format(OB_STORE_FORMAT_DYNAMIC_MYSQL);
  table_schema.set_progressive_merge_round(1);
  table_schema.set_tablet_id(0);
  table_schema.set_micro_index_clustered(false);

  table_schema.set_max_used_column_id(column_id);
  return ret;
}

int ObInnerTableSchema::v_ob_plan_cache_plan_stat_schema(ObTableSchema &table_schema)
{
  int ret = OB_SUCCESS;
  uint64_t column_id = OB_APP_MIN_COLUMN_ID - 1;

  //generated fields:
  table_schema.set_database_id(OB_SYS_DATABASE_ID);
  table_schema.set_table_id(OB_V_OB_PLAN_CACHE_PLAN_STAT_TID);
  table_schema.set_rowkey_split_pos(0);
  table_schema.set_progressive_merge_num(0);
  table_schema.set_rowkey_column_num(0);
  table_schema.set_load_type(TABLE_LOAD_TYPE_IN_DISK);
  table_schema.set_table_type(SYSTEM_VIEW);
  table_schema.set_index_type(INDEX_TYPE_IS_NOT);
  table_schema.set_def_type(TABLE_DEF_TYPE_INTERNAL);

  if (OB_SUCC(ret)) {
    if (OB_FAIL(table_schema.set_table_name(OB_V_OB_PLAN_CACHE_PLAN_STAT_TNAME))) {
      LOG_ERROR("fail to set table_name", K(ret));
    }
  }

  if (OB_SUCC(ret)) {
    if (OB_FAIL(table_schema.set_compress_func_name(OB_DEFAULT_COMPRESS_FUNC_NAME))) {
      LOG_ERROR("fail to set compress_func_name", K(ret));
    }
  }
  table_schema.set_part_level(PARTITION_LEVEL_ZERO);
  table_schema.set_charset_type(ObCharset::get_default_charset());
  table_schema.set_collation_type(ObCharset::get_default_collation(ObCharset::get_default_charset()));

  if (OB_SUCC(ret)) {
    if (OB_FAIL(table_schema.set_view_definition(R"__(                           SELECT PLAN_ID,SQL_ID,TYPE,IS_BIND_SENSITIVE,IS_BIND_AWARE,                           DB_ID,STATEMENT,QUERY_SQL,SPECIAL_PARAMS,PARAM_INFOS, SYS_VARS, CONFIGS, PLAN_HASH,                           FIRST_LOAD_TIME,SCHEMA_VERSION,LAST_ACTIVE_TIME,AVG_EXE_USEC,SLOWEST_EXE_TIME,SLOWEST_EXE_USEC,                           SLOW_COUNT,HIT_COUNT,PLAN_SIZE,EXECUTIONS,DISK_READS,DIRECT_WRITES,BUFFER_GETS,APPLICATION_WAIT_TIME,                           CONCURRENCY_WAIT_TIME,USER_IO_WAIT_TIME,ROWS_PROCESSED,ELAPSED_TIME,CPU_TIME,                           DELAYED_PX_QUERYS,OUTLINE_VERSION,OUTLINE_ID,OUTLINE_DATA,ACS_SEL_INFO,                           TABLE_SCAN, TIMEOUT_COUNT, PS_STMT_ID, SESSID,                           TEMP_TABLES, OBJECT_TYPE,HINTS_INFO,HINTS_ALL_WORKED, PL_SCHEMA_ID,                           IS_BATCHED_MULTI_STMT, RULE_NAME,                           FIRST_GET_PLAN_TIME, FIRST_EXE_USEC                           FROM oceanbase.__all_virtual_plan_stat WHERE OBJECT_STATUS = 0 AND is_in_pc=true                       )__"))) {
      LOG_ERROR("fail to set view_definition", K(ret));
    }
  }
  table_schema.set_index_using_type(USING_BTREE);
  table_schema.set_row_store_type(ENCODING_ROW_STORE);
  table_schema.set_store_format(OB_STORE_FORMAT_DYNAMIC_MYSQL);
  table_schema.set_progressive_merge_round(1);
  table_schema.set_tablet_id(0);
  table_schema.set_micro_index_clustered(false);

  table_schema.set_max_used_column_id(column_id);
  return ret;
}

int ObInnerTableSchema::dba_recyclebin_schema(ObTableSchema &table_schema)
{
  int ret = OB_SUCCESS;
  uint64_t column_id = OB_APP_MIN_COLUMN_ID - 1;

  //generated fields:
  table_schema.set_database_id(OB_SYS_DATABASE_ID);
  table_schema.set_table_id(OB_DBA_RECYCLEBIN_TID);
  table_schema.set_rowkey_split_pos(0);
  table_schema.set_progressive_merge_num(0);
  table_schema.set_rowkey_column_num(0);
  table_schema.set_load_type(TABLE_LOAD_TYPE_IN_DISK);
  table_schema.set_table_type(SYSTEM_VIEW);
  table_schema.set_index_type(INDEX_TYPE_IS_NOT);
  table_schema.set_def_type(TABLE_DEF_TYPE_INTERNAL);

  if (OB_SUCC(ret)) {
    if (OB_FAIL(table_schema.set_table_name(OB_DBA_RECYCLEBIN_TNAME))) {
      LOG_ERROR("fail to set table_name", K(ret));
    }
  }

  if (OB_SUCC(ret)) {
    if (OB_FAIL(table_schema.set_compress_func_name(OB_DEFAULT_COMPRESS_FUNC_NAME))) {
      LOG_ERROR("fail to set compress_func_name", K(ret));
    }
  }
  table_schema.set_part_level(PARTITION_LEVEL_ZERO);
  table_schema.set_charset_type(ObCharset::get_default_charset());
  table_schema.set_collation_type(ObCharset::get_default_collation(ObCharset::get_default_charset()));

  if (OB_SUCC(ret)) {
    if (OB_FAIL(table_schema.set_view_definition(R"__(                       SELECT                       CAST(B.DATABASE_NAME AS CHAR(128)) AS OWNER,                       CAST(A.OBJECT_NAME AS CHAR(128)) AS OBJECT_NAME,                       CAST(A.ORIGINAL_NAME AS CHAR(128)) AS ORIGINAL_NAME,                       CAST(NULL AS CHAR(9)) AS OPERATION,                       CAST(CASE A.TYPE                            WHEN 1 THEN 'TABLE'                            WHEN 2 THEN 'NORMAL INDEX'                            WHEN 3 THEN 'VIEW'                            ELSE NULL END AS CHAR(25)) AS TYPE,                       CAST(NULL AS CHAR(30)) AS TS_NAME,                       CAST(C.GMT_CREATE AS DATE) AS CREATETIME,                       CAST(C.GMT_MODIFIED AS DATE) AS DROPTIME,                       CAST(NULL AS SIGNED) AS DROPSCN,                       CAST(NULL AS CHAR(128)) AS PARTITION_NAME,                       CAST('YES' AS CHAR(3)) AS CAN_UNDROP,                       CAST('YES' AS CHAR(3)) AS CAN_PURGE,                       CAST(NULL AS SIGNED) AS RELATED,                       CAST(NULL AS SIGNED) AS BASE_OBJECT,                       CAST(NULL AS SIGNED) AS PURGE_OBJECT,                       CAST(NULL AS SIGNED) AS SPACE                       FROM OCEANBASE.__ALL_RECYCLEBIN A                       JOIN OCEANBASE.__ALL_DATABASE B                         ON A.DATABASE_ID = B.DATABASE_ID                       JOIN OCEANBASE.__ALL_TABLE C                         ON A.TABLE_ID = C.TABLE_ID                       WHERE A.TYPE IN (1, 2, 3)                         AND C.TABLE_MODE >> 12 & 15 in (0,1)                         AND C.INDEX_ATTRIBUTES_SET & 16 = 0                                            UNION ALL                                            SELECT                       CAST(A.ORIGINAL_NAME AS CHAR(128)) AS OWNER,                       CAST(A.OBJECT_NAME AS CHAR(128)) AS OBJECT_NAME,                       CAST(A.ORIGINAL_NAME AS CHAR(128)) AS ORIGINAL_NAME,                       CAST(NULL AS CHAR(9)) AS OPERATION,                       CAST('DATABASE' AS CHAR(25)) AS TYPE,                       CAST(NULL AS CHAR(30)) AS TS_NAME,                       CAST(B.GMT_CREATE AS DATE) AS CREATETIME,                       CAST(B.GMT_MODIFIED AS DATE) AS DROPTIME,                       CAST(NULL AS SIGNED) AS DROPSCN,                       CAST(NULL AS CHAR(128)) AS PARTITION_NAME,                       CAST('YES' AS CHAR(3)) AS CAN_UNDROP,                       CAST('YES' AS CHAR(3)) AS CAN_PURGE,                       CAST(NULL AS SIGNED) AS RELATED,                       CAST(NULL AS SIGNED) AS BASE_OBJECT,                       CAST(NULL AS SIGNED) AS PURGE_OBJECT,                       CAST(NULL AS SIGNED) AS SPACE                       FROM OCEANBASE.__ALL_RECYCLEBIN A                       JOIN OCEANBASE.__ALL_DATABASE B                         ON A.DATABASE_ID = B.DATABASE_ID                       WHERE A.TYPE = 4                                            UNION ALL                                            SELECT                       CAST(B.DATABASE_NAME AS CHAR(128)) AS OWNER,                       CAST(A.OBJECT_NAME AS CHAR(128)) AS OBJECT_NAME,                       CAST(A.ORIGINAL_NAME AS CHAR(128)) AS ORIGINAL_NAME,                       CAST(NULL AS CHAR(9)) AS OPERATION,                       CAST('TRIGGER' AS CHAR(25)) AS TYPE,                       CAST(NULL AS CHAR(30)) AS TS_NAME,                       CAST(C.GMT_CREATE AS DATE) AS CREATETIME,                       CAST(C.GMT_MODIFIED AS DATE) AS DROPTIME,                       CAST(NULL AS SIGNED) AS DROPSCN,                       CAST(NULL AS CHAR(128)) AS PARTITION_NAME,                       CAST('YES' AS CHAR(3)) AS CAN_UNDROP,                       CAST('YES' AS CHAR(3)) AS CAN_PURGE,                       CAST(NULL AS SIGNED) AS RELATED,                       CAST(NULL AS SIGNED) AS BASE_OBJECT,                       CAST(NULL AS SIGNED) AS PURGE_OBJECT,                       CAST(NULL AS SIGNED) AS SPACE                       FROM OCEANBASE.__ALL_RECYCLEBIN A                       JOIN OCEANBASE.__ALL_DATABASE B                         ON A.DATABASE_ID = B.DATABASE_ID                       JOIN OCEANBASE.__ALL_TRIGGER C                         ON A.TABLE_ID = C.TRIGGER_ID                       WHERE A.TYPE = 6                     )__"))) {
      LOG_ERROR("fail to set view_definition", K(ret));
    }
  }
  table_schema.set_index_using_type(USING_BTREE);
  table_schema.set_row_store_type(ENCODING_ROW_STORE);
  table_schema.set_store_format(OB_STORE_FORMAT_DYNAMIC_MYSQL);
  table_schema.set_progressive_merge_round(1);
  table_schema.set_tablet_id(0);
  table_schema.set_micro_index_clustered(false);

  table_schema.set_max_used_column_id(column_id);
  return ret;
}


} // end namespace share
} // end namespace oceanbase
