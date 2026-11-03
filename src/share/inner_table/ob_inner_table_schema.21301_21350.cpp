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

int ObInnerTableSchema::v_ob_log_stat_schema(ObTableSchema &table_schema)
{
  int ret = OB_SUCCESS;
  uint64_t column_id = OB_APP_MIN_COLUMN_ID - 1;

  //generated fields:
  table_schema.set_database_id(OB_SYS_DATABASE_ID);
  table_schema.set_table_id(OB_V_OB_LOG_STAT_TID);
  table_schema.set_rowkey_split_pos(0);
  table_schema.set_progressive_merge_num(0);
  table_schema.set_rowkey_column_num(0);
  table_schema.set_load_type(TABLE_LOAD_TYPE_IN_DISK);
  table_schema.set_table_type(SYSTEM_VIEW);
  table_schema.set_index_type(INDEX_TYPE_IS_NOT);
  table_schema.set_def_type(TABLE_DEF_TYPE_INTERNAL);

  if (OB_SUCC(ret)) {
    if (OB_FAIL(table_schema.set_table_name(OB_V_OB_LOG_STAT_TNAME))) {
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
    if (OB_FAIL(table_schema.set_view_definition(R"__(   SELECT     ACCESS_MODE,     BASE_LSN,     BEGIN_LSN,     BEGIN_SCN,     END_LSN,     END_SCN,     MAX_LSN,     MAX_SCN   FROM oceanbase.__all_virtual_log_stat )__"))) {
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

int ObInnerTableSchema::st_geometry_columns_schema(ObTableSchema &table_schema)
{
  int ret = OB_SUCCESS;
  uint64_t column_id = OB_APP_MIN_COLUMN_ID - 1;

  //generated fields:
  table_schema.set_database_id(OB_INFORMATION_SCHEMA_ID);
  table_schema.set_table_id(OB_ST_GEOMETRY_COLUMNS_TID);
  table_schema.set_rowkey_split_pos(0);
  table_schema.set_progressive_merge_num(0);
  table_schema.set_rowkey_column_num(0);
  table_schema.set_load_type(TABLE_LOAD_TYPE_IN_DISK);
  table_schema.set_table_type(SYSTEM_VIEW);
  table_schema.set_index_type(INDEX_TYPE_IS_NOT);
  table_schema.set_def_type(TABLE_DEF_TYPE_INTERNAL);

  if (OB_SUCC(ret)) {
    if (OB_FAIL(table_schema.set_table_name(OB_ST_GEOMETRY_COLUMNS_TNAME))) {
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
    if (OB_FAIL(table_schema.set_view_definition(R"__(                       select CAST(db.database_name AS CHAR(128)) collate utf8mb4_name_case as TABLE_SCHEMA,                              CAST(tbl.table_name AS CHAR(256)) collate utf8mb4_name_case as TABLE_NAME,                              CAST(col.column_name AS CHAR(128)) as COLUMN_NAME,                              CAST(srs.srs_name AS CHAR(128)) as SRS_NAME,                              CAST(if ((col.srs_id >> 32) = 4294967295, NULL, col.srs_id >> 32) AS UNSIGNED) as SRS_ID,                              CAST(case (col.srs_id & 31)                                     when 0 then 'geometry'                                     when 1 then 'point'                                     when 2 then 'linestring'                                     when 3 then 'polygon'                                     when 4 then 'multipoint'                                     when 5 then 'multilinestring'                                     when 6 then 'multipolygon'                                     when 7 then 'geomcollection'                                     else 'invalid'                               end AS CHAR(128))as GEOMETRY_TYPE_NAME                       from                           oceanbase.__all_column col left join oceanbase.__all_spatial_reference_systems srs on (col.srs_id >> 32) = srs.srs_id                           join oceanbase.__all_table tbl on (tbl.table_id = col.table_id)                           join oceanbase.__all_database db on (db.database_id = tbl.database_id)                           and db.database_name != '__recyclebin'                       where col.data_type  = 37                         and ((col.column_flags & 2097152) = 0)                         and tbl.table_mode >> 12 & 15 in (0,1)                         and tbl.index_attributes_set & 16 = 0                         and (0 = sys_privilege_check('table_acc')                              or 0 = sys_privilege_check('table_acc', db.database_name, tbl.table_name));                     )__"))) {
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

int ObInnerTableSchema::st_spatial_reference_systems_schema(ObTableSchema &table_schema)
{
  int ret = OB_SUCCESS;
  uint64_t column_id = OB_APP_MIN_COLUMN_ID - 1;

  //generated fields:
  table_schema.set_database_id(OB_INFORMATION_SCHEMA_ID);
  table_schema.set_table_id(OB_ST_SPATIAL_REFERENCE_SYSTEMS_TID);
  table_schema.set_rowkey_split_pos(0);
  table_schema.set_progressive_merge_num(0);
  table_schema.set_rowkey_column_num(0);
  table_schema.set_load_type(TABLE_LOAD_TYPE_IN_DISK);
  table_schema.set_table_type(SYSTEM_VIEW);
  table_schema.set_index_type(INDEX_TYPE_IS_NOT);
  table_schema.set_def_type(TABLE_DEF_TYPE_INTERNAL);

  if (OB_SUCC(ret)) {
    if (OB_FAIL(table_schema.set_table_name(OB_ST_SPATIAL_REFERENCE_SYSTEMS_TNAME))) {
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
    if (OB_FAIL(table_schema.set_view_definition(R"__(
  select CAST(srs_name AS CHAR(128)) as SRS_NAME,
         CAST(srs_id AS UNSIGNED) as SRS_ID,
         CAST(organization AS CHAR(256)) as ORGANIZATION,
         CAST(organization_coordsys_id AS UNSIGNED) as ORGANIZATION_COORDSYS_ID,
         CAST(definition AS CHAR(4096)) as DEFINITION,
         CAST(description AS CHAR(2048)) as DESCRIPTION
  from oceanbase.__all_spatial_reference_systems; )__"))) {
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

int ObInnerTableSchema::dba_ob_freeze_info_schema(ObTableSchema &table_schema)
{
  int ret = OB_SUCCESS;
  uint64_t column_id = OB_APP_MIN_COLUMN_ID - 1;

  //generated fields:
  table_schema.set_database_id(OB_SYS_DATABASE_ID);
  table_schema.set_table_id(OB_DBA_OB_FREEZE_INFO_TID);
  table_schema.set_rowkey_split_pos(0);
  table_schema.set_progressive_merge_num(0);
  table_schema.set_rowkey_column_num(0);
  table_schema.set_load_type(TABLE_LOAD_TYPE_IN_DISK);
  table_schema.set_table_type(SYSTEM_VIEW);
  table_schema.set_index_type(INDEX_TYPE_IS_NOT);
  table_schema.set_def_type(TABLE_DEF_TYPE_INTERNAL);

  if (OB_SUCC(ret)) {
    if (OB_FAIL(table_schema.set_table_name(OB_DBA_OB_FREEZE_INFO_TNAME))) {
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
    if (OB_FAIL(table_schema.set_view_definition(R"__(   SELECT FROZEN_SCN,          DATA_VERSION,          SCHEMA_VERSION,          GMT_CREATE,          GMT_MODIFIED   FROM OCEANBASE.__ALL_FREEZE_INFO   )__"))) {
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

int ObInnerTableSchema::dba_ob_auto_increment_schema(ObTableSchema &table_schema)
{
  int ret = OB_SUCCESS;
  uint64_t column_id = OB_APP_MIN_COLUMN_ID - 1;

  //generated fields:
  table_schema.set_database_id(OB_SYS_DATABASE_ID);
  table_schema.set_table_id(OB_DBA_OB_AUTO_INCREMENT_TID);
  table_schema.set_rowkey_split_pos(0);
  table_schema.set_progressive_merge_num(0);
  table_schema.set_rowkey_column_num(0);
  table_schema.set_load_type(TABLE_LOAD_TYPE_IN_DISK);
  table_schema.set_table_type(SYSTEM_VIEW);
  table_schema.set_index_type(INDEX_TYPE_IS_NOT);
  table_schema.set_def_type(TABLE_DEF_TYPE_INTERNAL);

  if (OB_SUCC(ret)) {
    if (OB_FAIL(table_schema.set_table_name(OB_DBA_OB_AUTO_INCREMENT_TNAME))) {
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
    if (OB_FAIL(table_schema.set_view_definition(R"__(   SELECT CAST(GMT_CREATE AS DATETIME(6)) AS CREATE_TIME,          CAST(GMT_MODIFIED AS DATETIME(6)) AS MODIFY_TIME,          CAST(SEQUENCE_KEY AS SIGNED) AS AUTO_INCREMENT_KEY,          CAST(COLUMN_ID AS SIGNED) AS COLUMN_ID,          CAST(SEQUENCE_VALUE AS UNSIGNED) AS AUTO_INCREMENT_VALUE,          CAST(SYNC_VALUE AS UNSIGNED) AS SYNC_VALUE   FROM OCEANBASE.__ALL_AUTO_INCREMENT   )__"))) {
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

int ObInnerTableSchema::dba_scheduler_windows_schema(ObTableSchema &table_schema)
{
  int ret = OB_SUCCESS;
  uint64_t column_id = OB_APP_MIN_COLUMN_ID - 1;

  //generated fields:
  table_schema.set_database_id(OB_SYS_DATABASE_ID);
  table_schema.set_table_id(OB_DBA_SCHEDULER_WINDOWS_TID);
  table_schema.set_rowkey_split_pos(0);
  table_schema.set_progressive_merge_num(0);
  table_schema.set_rowkey_column_num(0);
  table_schema.set_load_type(TABLE_LOAD_TYPE_IN_DISK);
  table_schema.set_table_type(SYSTEM_VIEW);
  table_schema.set_index_type(INDEX_TYPE_IS_NOT);
  table_schema.set_def_type(TABLE_DEF_TYPE_INTERNAL);

  if (OB_SUCC(ret)) {
    if (OB_FAIL(table_schema.set_table_name(OB_DBA_SCHEDULER_WINDOWS_TNAME))) {
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
    if (OB_FAIL(table_schema.set_view_definition(R"__(SELECT     CAST(T.POWNER AS CHAR(128)) AS OWNER,     CAST(T.JOB_NAME AS CHAR(128)) AS WINDOW_NAME,     CAST(NULL AS CHAR(128)) AS RESOURCE_PLAN,     CAST(NULL AS CHAR(4000)) AS SCHEDULE_OWNER,     CAST(NULL AS CHAR(4000)) AS SCHEDULE_NAME,     CAST(NULL AS CHAR(8)) AS SCHEDULE_TYPE,     CAST(T.START_DATE AS DATETIME(6)) AS START_DATE,     CAST(T.REPEAT_INTERVAL AS CHAR(4000)) AS REPEAT_INTERVAL,     CAST(T.END_DATE AS DATETIME(6)) AS END_DATE,     CAST(T.MAX_RUN_DURATION AS SIGNED) AS DURATION,     CAST(NULL AS CHAR(4)) AS WINDOW_PRIORITY,     CAST(T.NEXT_DATE AS DATETIME(6)) AS NEXT_RUN_DATE,     CAST(T.LAST_DATE AS DATETIME(6)) AS LAST_START_DATE,     CAST(T.ENABLED AS CHAR(5)) AS ENABLED,     CAST(NULL AS CHAR(5)) AS ACTIVE,     CAST(NULL AS DATETIME(6)) AS MANUAL_OPEN_TIME,     CAST(NULL AS SIGNED) AS MANUAL_DURATION,     CAST(T.COMMENTS AS CHAR(4000)) AS COMMENTS   FROM oceanbase.__all_scheduler_job T WHERE T.JOB > 0 and T.JOB_NAME in ('MONDAY_WINDOW',     'TUESDAY_WINDOW', 'WEDNESDAY_WINDOW', 'THURSDAY_WINDOW', 'FRIDAY_WINDOW', 'SATURDAY_WINDOW', 'SUNDAY_WINDOW')   )__"))) {
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

int ObInnerTableSchema::dba_ob_users_schema(ObTableSchema &table_schema)
{
  int ret = OB_SUCCESS;
  uint64_t column_id = OB_APP_MIN_COLUMN_ID - 1;

  //generated fields:
  table_schema.set_database_id(OB_SYS_DATABASE_ID);
  table_schema.set_table_id(OB_DBA_OB_USERS_TID);
  table_schema.set_rowkey_split_pos(0);
  table_schema.set_progressive_merge_num(0);
  table_schema.set_rowkey_column_num(0);
  table_schema.set_load_type(TABLE_LOAD_TYPE_IN_DISK);
  table_schema.set_table_type(SYSTEM_VIEW);
  table_schema.set_index_type(INDEX_TYPE_IS_NOT);
  table_schema.set_def_type(TABLE_DEF_TYPE_INTERNAL);

  if (OB_SUCC(ret)) {
    if (OB_FAIL(table_schema.set_table_name(OB_DBA_OB_USERS_TNAME))) {
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
    if (OB_FAIL(table_schema.set_view_definition(R"__(     SELECT USER_NAME,             HOST,             PASSWD,             INFO,             (CASE WHEN PRIV_ALTER = 0 THEN 'NO' ELSE 'YES' END) AS PRIV_ALTER,             (CASE WHEN PRIV_CREATE = 0 THEN 'NO' ELSE 'YES' END) AS PRIV_CREATE,             (CASE WHEN PRIV_DELETE = 0 THEN 'NO' ELSE 'YES' END) AS PRIV_DELETE,             (CASE WHEN PRIV_DROP = 0 THEN 'NO' ELSE 'YES' END) AS PRIV_DROP,             (CASE WHEN PRIV_GRANT_OPTION = 0 THEN 'NO' ELSE 'YES' END) AS PRIV_GRANT_OPTION,             (CASE WHEN PRIV_INSERT = 0 THEN 'NO' ELSE 'YES' END) AS PRIV_INSERT,             (CASE WHEN PRIV_UPDATE = 0 THEN 'NO' ELSE 'YES' END) AS PRIV_UPDATE,             (CASE WHEN PRIV_SELECT = 0 THEN 'NO' ELSE 'YES' END) AS PRIV_SELECT,             (CASE WHEN PRIV_INDEX = 0 THEN 'NO' ELSE 'YES' END) AS PRIV_INDEX,             (CASE WHEN PRIV_CREATE_VIEW = 0 THEN 'NO' ELSE 'YES' END) AS PRIV_CREATE_VIEW,             (CASE WHEN PRIV_SHOW_VIEW = 0 THEN 'NO' ELSE 'YES' END) AS PRIV_SHOW_VIEW,             (CASE WHEN PRIV_SHOW_DB = 0 THEN 'NO' ELSE 'YES' END) AS PRIV_SHOW_DB,             (CASE WHEN PRIV_CREATE_USER = 0 THEN 'NO' ELSE 'YES' END) AS PRIV_CREATE_USER,             (CASE WHEN PRIV_SUPER = 0 THEN 'NO' ELSE 'YES' END) AS PRIV_SUPER,             (CASE WHEN IS_LOCKED = 0 THEN 'NO' ELSE 'YES' END) AS IS_LOCKED,             (CASE WHEN PRIV_PROCESS = 0 THEN 'NO' ELSE 'YES' END) AS PRIV_PROCESS,             SSL_TYPE,             SSL_CIPHER,             X509_ISSUER,             X509_SUBJECT,             (CASE WHEN TYPE = 0 THEN 'USER' ELSE 'ROLE' END) AS TYPE,             PASSWORD_LAST_CHANGED,             (CASE WHEN PRIV_FILE = 0 THEN 'NO' ELSE 'YES' END) AS PRIV_FILE,             (CASE WHEN PRIV_ALTER_SYSTEM = 0 THEN 'NO' ELSE 'YES' END) AS PRIV_ALTER_SYSTEM,             MAX_CONNECTIONS,             MAX_USER_CONNECTIONS,             (CASE WHEN PRIV_REPL_SLAVE = 0 THEN 'NO' ELSE 'YES' END) AS PRIV_REPL_SLAVE,             (CASE WHEN PRIV_REPL_CLIENT = 0 THEN 'NO' ELSE 'YES' END) AS PRIV_REPL_CLIENT,             (CASE WHEN (PRIV_OTHERS & (1 << 0)) != 0 THEN 'YES' ELSE 'NO' END) AS PRIV_EXECUTE,             (CASE WHEN (PRIV_OTHERS & (1 << 1)) != 0 THEN 'YES' ELSE 'NO' END) AS PRIV_ALTER_ROUTINE,             (CASE WHEN (PRIV_OTHERS & (1 << 2)) != 0 THEN 'YES' ELSE 'NO' END) AS PRIV_CREATE_ROUTINE,             (CASE WHEN (PRIV_OTHERS & (1 << 3)) != 0 THEN 'YES' ELSE 'NO' END) AS PRIV_CREATE_TABLESPACE,             (CASE WHEN (PRIV_OTHERS & (1 << 4)) != 0 THEN 'YES' ELSE 'NO' END) AS PRIV_SHUTDOWN,             (CASE WHEN (PRIV_OTHERS & (1 << 5)) != 0 THEN 'YES' ELSE 'NO' END) AS PRIV_RELOAD,             (CASE WHEN (PRIV_OTHERS & (1 << 6)) != 0 THEN 'YES' ELSE 'NO' END) AS PRIV_REFERENCES,             (CASE WHEN (PRIV_OTHERS & (1 << 7)) != 0 THEN 'YES' ELSE 'NO' END) AS PRIV_CREATE_ROLE,             (CASE WHEN (PRIV_OTHERS & (1 << 8)) != 0 THEN 'YES' ELSE 'NO' END) AS PRIV_DROP_ROLE,             (CASE WHEN (PRIV_OTHERS & (1 << 9)) != 0 THEN 'YES' ELSE 'NO' END) AS PRIV_TRIGGER,             (CASE WHEN (PRIV_OTHERS & (1 << 10)) != 0 THEN 'YES' ELSE 'NO' END) AS PRIV_LOCK_TABLE     FROM OCEANBASE.__all_user;     )__"))) {
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

int ObInnerTableSchema::dba_ob_database_privilege_schema(ObTableSchema &table_schema)
{
  int ret = OB_SUCCESS;
  uint64_t column_id = OB_APP_MIN_COLUMN_ID - 1;

  //generated fields:
  table_schema.set_database_id(OB_SYS_DATABASE_ID);
  table_schema.set_table_id(OB_DBA_OB_DATABASE_PRIVILEGE_TID);
  table_schema.set_rowkey_split_pos(0);
  table_schema.set_progressive_merge_num(0);
  table_schema.set_rowkey_column_num(0);
  table_schema.set_load_type(TABLE_LOAD_TYPE_IN_DISK);
  table_schema.set_table_type(SYSTEM_VIEW);
  table_schema.set_index_type(INDEX_TYPE_IS_NOT);
  table_schema.set_def_type(TABLE_DEF_TYPE_INTERNAL);

  if (OB_SUCC(ret)) {
    if (OB_FAIL(table_schema.set_table_name(OB_DBA_OB_DATABASE_PRIVILEGE_TNAME))) {
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
    if (OB_FAIL(table_schema.set_view_definition(R"__(     WITH DB_PRIV AS (       select A.user_id USER_ID,              A.database_name DATABASE_NAME,              A.priv_alter PRIV_ALTER,              A.priv_create PRIV_CREATE,              A.priv_delete PRIV_DELETE,              A.priv_drop PRIV_DROP,              A.priv_grant_option PRIV_GRANT_OPTION,              A.priv_insert PRIV_INSERT,              A.priv_update PRIV_UPDATE,              A.priv_select PRIV_SELECT,              A.priv_index PRIV_INDEX,              A.priv_create_view PRIV_CREATE_VIEW,              A.priv_show_view PRIV_SHOW_VIEW,              A.GMT_CREATE GMT_CREATE,              A.GMT_MODIFIED GMT_MODIFIED,              A.priv_others PRIV_OTHERS       from oceanbase.__all_database_privilege_history A,           (select user_id, database_name, max(schema_version) schema_version from oceanbase.__all_database_privilege_history group by user_id, database_name, database_name collate utf8mb4_bin) B       where A.user_id = B.user_id and A.database_name collate utf8mb4_bin = B.database_name collate utf8mb4_bin and A.schema_version = B.schema_version and A.is_deleted = 0     )     SELECT A.USER_ID USER_ID,             B.USER_NAME USERNAME,             A.DATABASE_NAME DATABASE_NAME,             A.GMT_CREATE GMT_CREATE,             A.GMT_MODIFIED GMT_MODIFIED,             (CASE WHEN A.PRIV_ALTER = 0 THEN 'NO' ELSE 'YES' END) AS PRIV_ALTER,             (CASE WHEN A.PRIV_CREATE = 0 THEN 'NO' ELSE 'YES' END) AS PRIV_CREATE,             (CASE WHEN A.PRIV_DELETE = 0 THEN 'NO' ELSE 'YES' END) AS PRIV_DELETE,             (CASE WHEN A.PRIV_DROP = 0 THEN 'NO' ELSE 'YES' END) AS PRIV_DROP,             (CASE WHEN A.PRIV_GRANT_OPTION = 0 THEN 'NO' ELSE 'YES' END) AS PRIV_GRANT_OPTION,             (CASE WHEN A.PRIV_INSERT = 0 THEN 'NO' ELSE 'YES' END) AS PRIV_INSERT,             (CASE WHEN A.PRIV_UPDATE = 0 THEN 'NO' ELSE 'YES' END) AS PRIV_UPDATE,             (CASE WHEN A.PRIV_SELECT = 0 THEN 'NO' ELSE 'YES' END) AS PRIV_SELECT,             (CASE WHEN A.PRIV_INDEX = 0 THEN 'NO' ELSE 'YES' END) AS PRIV_INDEX,             (CASE WHEN A.PRIV_CREATE_VIEW = 0 THEN 'NO' ELSE 'YES' END) AS PRIV_CREATE_VIEW,             (CASE WHEN A.PRIV_SHOW_VIEW = 0 THEN 'NO' ELSE 'YES' END) AS PRIV_SHOW_VIEW,             (CASE WHEN (A.PRIV_OTHERS & (1 << 0)) != 0 THEN 'YES' ELSE 'NO' END) AS PRIV_EXECUTE,             (CASE WHEN (A.PRIV_OTHERS & (1 << 1)) != 0 THEN 'YES' ELSE 'NO' END) AS PRIV_ALTER_ROUTINE,             (CASE WHEN (A.PRIV_OTHERS & (1 << 2)) != 0 THEN 'YES' ELSE 'NO' END) AS PRIV_CREATE_ROUTINE,             (CASE WHEN (A.PRIV_OTHERS & (1 << 6)) != 0 THEN 'YES' ELSE 'NO' END) AS PRIV_REFERENCES,             (CASE WHEN (A.PRIV_OTHERS & (1 << 9)) != 0 THEN 'YES' ELSE 'NO' END) AS PRIV_TRIGGER,             (CASE WHEN (A.PRIV_OTHERS & (1 << 10)) != 0 THEN 'YES' ELSE 'NO' END) AS PRIV_LOCK_TABLE     FROM DB_PRIV A INNER JOIN OCEANBASE.__all_user B           ON A.USER_ID = B.USER_ID;     )__"))) {
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

int ObInnerTableSchema::parameters_schema(ObTableSchema &table_schema)
{
  int ret = OB_SUCCESS;
  uint64_t column_id = OB_APP_MIN_COLUMN_ID - 1;

  //generated fields:
  table_schema.set_database_id(OB_INFORMATION_SCHEMA_ID);
  table_schema.set_table_id(OB_PARAMETERS_TID);
  table_schema.set_rowkey_split_pos(0);
  table_schema.set_progressive_merge_num(0);
  table_schema.set_rowkey_column_num(0);
  table_schema.set_load_type(TABLE_LOAD_TYPE_IN_DISK);
  table_schema.set_table_type(SYSTEM_VIEW);
  table_schema.set_index_type(INDEX_TYPE_IS_NOT);
  table_schema.set_def_type(TABLE_DEF_TYPE_INTERNAL);

  if (OB_SUCC(ret)) {
    if (OB_FAIL(table_schema.set_table_name(OB_PARAMETERS_TNAME))) {
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
    if (OB_FAIL(table_schema.set_view_definition(R"__(select CAST('def' AS CHAR(512)) AS SPECIFIC_CATALOG,                                             CAST(d.database_name AS CHAR(128)) collate utf8mb4_name_case AS SPECIFIC_SCHEMA,                                             CAST(r.routine_name AS CHAR(64)) AS SPECIFIC_NAME,                                             CAST(rp.param_position AS signed) AS ORDINAL_POSITION,                                             CAST(CASE rp.param_position WHEN 0 THEN NULL                                               ELSE CASE rp.flag & 0x03                                               WHEN 1 THEN 'IN'                                               WHEN 2 THEN 'OUT'                                               WHEN 3 THEN 'INOUT'                                               ELSE NULL                                               END                                             END AS CHAR(5)) AS PARAMETER_MODE,                                             CAST(rp.param_name AS CHAR(64)) AS PARAMETER_NAME,                                             CAST(lower(case v.data_type_str                                                        when 'TINYINT UNSIGNED' then 'TINYINT'                                                        when 'SMALLINT UNSIGNED' then 'SMALLINT'                                                        when 'MEDIUMINT UNSIGNED' then 'MEDIUMINT'                                                        when 'INT UNSIGNED' then 'INT'                                                        when 'BIGINT UNSIGNED' then 'BIGINT'                                                        when 'FLOAT UNSIGNED' then 'FLOAT'                                                        when 'DOUBLE UNSIGNED' then 'DOUBLE'                                                        when 'DECIMAL UNSIGNED' then 'DECIMAL'                                                        when 'CHAR' then if(rp.param_charset = 1, 'BINARY', 'CHAR')                                                        when 'VARCHAR' then if(rp.param_charset = 1, 'VARBINARY', 'VARCHAR')                                                        when 'TINYTEXT' then if(rp.param_charset = 1, 'TINYBLOB', 'TINYTEXT')                                                        when 'TEXT' then if(rp.param_charset = 1, 'BLOB', 'TEXT')                                                        when 'MEDIUMTEXT' then if(rp.param_charset = 1, 'MEDIUMBLOB', 'MEDIUMTEXT')                                                        when 'LONGTEXT' then if(rp.param_charset = 1, 'LONGBLOB', 'LONGTEXT')                                                        when 'MYSQL_DATE' then 'DATE'                                                        when 'MYSQL_DATETIME' then 'DATETIME'                                                        else v.data_type_str end) AS CHAR(64)) AS DATA_TYPE,                                             CASE WHEN rp.param_type IN (22, 23, 27, 28, 29, 30) THEN CAST(rp.param_length AS SIGNED)                                               ELSE CAST(NULL AS SIGNED)                                             END AS CHARACTER_MAXIMUM_LENGTH,                                             CASE WHEN rp.param_type IN (22, 23, 27, 28, 29, 30, 43, 44, 46)                                               THEN CAST(                                                 rp.param_length * CASE rp.param_coll_type                                                 WHEN 63 THEN 1                                                 WHEN 249 THEN 4                                                 WHEN 248 THEN 4                                                 WHEN 87 THEN 2                                                 WHEN 28 THEN 2                                                 WHEN 55 THEN 4                                                 WHEN 54 THEN 4                                                 WHEN 101 THEN 2                                                 WHEN 46 THEN 4                                                 WHEN 45 THEN 4                                                 WHEN 224 THEN 4                                                 ELSE 1                                                 END                                                   AS SIGNED                                               )                                               ELSE CAST(NULL AS SIGNED)                                             END AS CHARACTER_OCTET_LENGTH,                                             CASE WHEN rp.param_type IN (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15, 16, 31, 50) THEN CAST(rp.param_precision AS UNSIGNED)                                               WHEN rp.param_type IN (11, 13) THEN CAST(if(rp.param_scale = -1, 12, rp.param_precision) AS UNSIGNED)                                               WHEN rp.param_type IN (12, 14) THEN CAST(if(rp.param_scale = -1, 22, rp.param_precision) AS UNSIGNED)                                               ELSE CAST(NULL AS UNSIGNED)                                             END AS NUMERIC_PRECISION,                                             CASE WHEN rp.param_type IN (15, 16, 50) THEN CAST(rp.param_scale AS SIGNED)                                               WHEN rp.param_type IN (11, 12, 13, 14) THEN CAST(if(rp.param_scale = -1, 0, rp.param_scale) AS SIGNED)                                               WHEN rp.param_type IN (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 31) THEN CAST(0 AS SIGNED)                                               ELSE CAST(NULL AS SIGNED)                                             END AS NUMERIC_SCALE,                                             CASE WHEN rp.param_type IN (17, 18, 20, 42) THEN CAST(rp.param_scale AS UNSIGNED)                                               ELSE CAST(NULL AS UNSIGNED)                                             END AS DATETIME_PRECISION,                                             CAST(CASE rp.param_charset                                               WHEN 1 THEN 'binary'                                               WHEN 2 THEN 'utf8mb4'                                               WHEN 3 THEN 'gbk'                                               WHEN 4 THEN 'utf16'                                               WHEN 5 THEN 'gb18030'                                               WHEN 6 THEN 'latin1'                                               WHEN 7 THEN 'gb18030_2022'                                               WHEN 8 THEN 'ascii'                                               WHEN 9 THEN 'tis620'                                               ELSE NULL                                             END AS CHAR(64)) AS CHARACTER_SET_NAME,                                             CAST(CASE rp.param_coll_type                                             WHEN 8 THEN 'latin1_swedish_ci'                                             WHEN 11 THEN 'ascii_general_ci'                                             WHEN 18 THEN 'tis620_thai_ci'                                             WHEN 28 THEN 'gbk_chinese_ci'                                             WHEN 45 THEN 'utf8mb4_general_ci'                                             WHEN 46 THEN 'utf8mb4_bin'                                             WHEN 47 THEN 'latin1_bin'                                             WHEN 54 THEN 'utf16_general_ci'                                             WHEN 55 THEN 'utf16_bin'                                             WHEN 63 THEN 'binary'                                             WHEN 65 THEN 'ascii_bin'                                             WHEN 87 THEN 'gbk_bin'                                             WHEN 89 THEN 'tis620_bin'                                             WHEN 101 THEN 'utf16_unicode_ci'                                             WHEN 216 THEN 'gb18030_2022_bin'                                             WHEN 217 THEN 'gb18030_2022_chinese_ci'                                             WHEN 218 THEN 'gb18030_2022_chinese_cs'                                             WHEN 219 THEN 'gb18030_2022_radical_ci'                                             WHEN 220 THEN 'gb18030_2022_radical_cs'                                             WHEN 221 THEN 'gb18030_2022_stroke_ci'                                             WHEN 222 THEN 'gb18030_2022_stroke_cs'                                             WHEN 224 THEN 'utf8mb4_unicode_ci'                                             WHEN 234 THEN 'utf8mb4_czech_ci'                                             WHEN 245 THEN 'utf8mb4_croatian_ci'                                             WHEN 246 THEN 'utf8mb4_unicode_520_ci'                                             WHEN 248 THEN 'gb18030_chinese_ci'                                             WHEN 249 THEN 'gb18030_bin'                                             WHEN 255 THEN 'utf8mb4_0900_ai_ci'                                               ELSE NULL                                             END AS CHAR(64)) AS COLLATION_NAME,                                             CAST(CASE WHEN rp.param_type IN (1, 2, 3, 4, 5, 31)                                               THEN CONCAT(lower(v.data_type_str),'(',rp.param_precision,')')                                               WHEN (rp.param_type in (6, 7, 8, 9, 10) AND rp.param_zero_fill)                                               THEN CONCAT(lower(v.data_type_str), ' zerofill')                                               WHEN rp.param_type IN (15,16,50)                                               THEN CONCAT(lower(v.data_type_str),'(',rp.param_precision, ',', rp.param_scale,')')                                               WHEN rp.param_type IN (17, 18, 20)                                               THEN CONCAT(lower(v.data_type_str),'(', rp.param_scale, ')')                                               WHEN (rp.param_type IN (22, 23) AND rp.param_charset != 1)                                               THEN CONCAT(lower(v.data_type_str),'(', rp.param_length, ')')                                               WHEN (rp.param_type IN (22) AND rp.param_charset = 1)                                               THEN CONCAT(lower('VARBINARY'),'(', rp.param_length, ')')                                               WHEN (rp.param_type IN (23) AND rp.param_charset = 1)                                               THEN CONCAT(lower('BINARY'),'(', rp.param_length, ')')                                               WHEN (rp.param_type IN (27, 28, 29, 30) AND rp.param_charset = 1)                                               THEN lower(REPLACE(v.data_type_str, 'TEXT', 'BLOB'))                                               WHEN rp.param_type IN (32, 33)                                               THEN get_mysql_routine_parameter_type_str(rp.routine_id, rp.param_position)                                               WHEN rp.param_type = 41 THEN lower('DATE')                                               WHEN rp.param_type = 42 THEN CONCAT(lower('DATETIME'),'(', rp.param_scale, ')')                                               ELSE lower(v.data_type_str) END AS char(4194304)) AS DTD_IDENTIFIER,                                             CAST(CASE WHEN r.routine_type = 1 THEN 'PROCEDURE'                                               WHEN ROUTINE_TYPE = 2 THEN 'FUNCTION'                                               ELSE NULL                                             END AS CHAR(9)) AS ROUTINE_TYPE                                           from                                             oceanbase.__all_routine_param as rp                                             join oceanbase.__all_routine as r on rp.subprogram_id = r.subprogram_id                                             and rp.routine_id = r.routine_id                                             join oceanbase.__all_database as d on r.database_id = d.database_id                                             left join oceanbase.__all_virtual_data_type v on rp.param_type = v.data_type                                           WHERE                                             in_recyclebin = 0                                             and database_name != '__recyclebin'                                             and (0 = sys_privilege_check('routine_acc')                                                  or 0 = sys_privilege_check('routine_acc', d.database_name, r.routine_name, r.routine_type))                                           order by SPECIFIC_SCHEMA,                                             SPECIFIC_NAME,                                             ORDINAL_POSITION                                           )__"))) {
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

int ObInnerTableSchema::table_privileges_schema(ObTableSchema &table_schema)
{
  int ret = OB_SUCCESS;
  uint64_t column_id = OB_APP_MIN_COLUMN_ID - 1;

  //generated fields:
  table_schema.set_database_id(OB_INFORMATION_SCHEMA_ID);
  table_schema.set_table_id(OB_TABLE_PRIVILEGES_TID);
  table_schema.set_rowkey_split_pos(0);
  table_schema.set_progressive_merge_num(0);
  table_schema.set_rowkey_column_num(0);
  table_schema.set_load_type(TABLE_LOAD_TYPE_IN_DISK);
  table_schema.set_table_type(SYSTEM_VIEW);
  table_schema.set_index_type(INDEX_TYPE_IS_NOT);
  table_schema.set_def_type(TABLE_DEF_TYPE_INTERNAL);

  if (OB_SUCC(ret)) {
    if (OB_FAIL(table_schema.set_table_name(OB_TABLE_PRIVILEGES_TNAME))) {
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
    if (OB_FAIL(table_schema.set_view_definition(R"__(   WITH DB_PRIV AS (     select A.user_id USER_ID,            A.database_name DATABASE_NAME,            A.priv_alter PRIV_ALTER,            A.priv_create PRIV_CREATE,            A.priv_delete PRIV_DELETE,            A.priv_drop PRIV_DROP,            A.priv_grant_option PRIV_GRANT_OPTION,            A.priv_insert PRIV_INSERT,            A.priv_update PRIV_UPDATE,            A.priv_select PRIV_SELECT,            A.priv_index PRIV_INDEX,            A.priv_create_view PRIV_CREATE_VIEW,            A.priv_show_view PRIV_SHOW_VIEW,            A.GMT_CREATE GMT_CREATE,            A.GMT_MODIFIED GMT_MODIFIED,            A.PRIV_OTHERS PRIV_OTHERS     from oceanbase.__all_database_privilege_history A,         (select user_id, database_name, max(schema_version) schema_version from oceanbase.__all_database_privilege_history group by user_id, database_name, database_name collate utf8mb4_bin) B     where A.user_id = B.user_id and A.database_name collate utf8mb4_bin = B.database_name collate utf8mb4_bin and A.schema_version = B.schema_version and A.is_deleted = 0   ),   TABLE_PRIV AS (     select A.user_id USER_ID,            A.database_name DATABASE_NAME,            A.table_name TABLE_NAME,            A.priv_alter PRIV_ALTER,            A.priv_create PRIV_CREATE,            A.priv_delete PRIV_DELETE,            A.priv_drop PRIV_DROP,            A.priv_grant_option PRIV_GRANT_OPTION,            A.priv_insert PRIV_INSERT,            A.priv_update PRIV_UPDATE,            A.priv_select PRIV_SELECT,            A.priv_index PRIV_INDEX,            A.priv_create_view PRIV_CREATE_VIEW,            A.priv_show_view PRIV_SHOW_VIEW,            A.PRIV_OTHERS PRIV_OTHERS     from oceanbase.__all_table_privilege_history A,         (select user_id, database_name, table_name, max(schema_version) schema_version from oceanbase.__all_table_privilege_history group by user_id, database_name, database_name collate utf8mb4_bin, table_name, table_name collate utf8mb4_bin) B     where A.user_id = B.user_id and A.database_name collate utf8mb4_bin = B.database_name collate utf8mb4_bin and A.schema_version = B.schema_version and A.table_name collate utf8mb4_bin = B.table_name collate utf8mb4_bin and A.is_deleted = 0   )   SELECT          CAST(CONCAT('''', V.USER_NAME, '''', '@', '''', V.HOST, '''') AS CHAR(81)) AS GRANTEE ,          CAST('def' AS CHAR(512)) AS TABLE_CATALOG ,          CAST(V.DATABASE_NAME AS CHAR(128)) collate utf8mb4_name_case AS TABLE_SCHEMA ,          CAST(V.TABLE_NAME AS CHAR(64)) collate utf8mb4_name_case AS TABLE_NAME,          CAST(V.PRIVILEGE_TYPE AS CHAR(64)) AS PRIVILEGE_TYPE ,          CAST(V.IS_GRANTABLE AS CHAR(3)) AS IS_GRANTABLE   FROM     (SELECT TP.DATABASE_NAME AS DATABASE_NAME,             TP.TABLE_NAME AS TABLE_NAME,             U.USER_NAME AS USER_NAME,             U.HOST AS HOST,             CASE                 WHEN V1.C1 = 1                      AND TP.PRIV_ALTER = 1 THEN 'ALTER'                 WHEN V1.C1 = 2                      AND TP.PRIV_CREATE = 1 THEN 'CREATE'                 WHEN V1.C1 = 4                      AND TP.PRIV_DELETE = 1 THEN 'DELETE'                 WHEN V1.C1 = 5                      AND TP.PRIV_DROP = 1 THEN 'DROP'                 WHEN V1.C1 = 7                      AND TP.PRIV_INSERT = 1 THEN 'INSERT'                 WHEN V1.C1 = 8                      AND TP.PRIV_UPDATE = 1 THEN 'UPDATE'                 WHEN V1.C1 = 9                      AND TP.PRIV_SELECT = 1 THEN 'SELECT'                 WHEN V1.C1 = 10                      AND TP.PRIV_INDEX = 1 THEN 'INDEX'                 WHEN V1.C1 = 11                      AND TP.PRIV_CREATE_VIEW = 1 THEN 'CREATE VIEW'                 WHEN V1.C1 = 12                      AND TP.PRIV_SHOW_VIEW = 1 THEN 'SHOW VIEW'                 WHEN V1.C1 = 22                      AND (TP.PRIV_OTHERS & (1 << 6)) != 0 THEN 'REFERENCES'                 WHEN V1.C1 = 44                      AND (TP.PRIV_OTHERS & (1 << 9)) != 0 THEN 'TRIGGER'                 WHEN V1.C1 = 45                      AND (TP.PRIV_OTHERS & (1 << 19)) != 0 THEN 'LOCK TABLES'                 ELSE NULL             END PRIVILEGE_TYPE ,             CASE                 WHEN TP.PRIV_GRANT_OPTION = 1 THEN 'YES'                 WHEN TP.PRIV_GRANT_OPTION = 0 THEN 'NO'             END IS_GRANTABLE      FROM TABLE_PRIV TP,                       oceanbase.__all_user U,        (SELECT 1 AS C1         UNION ALL SELECT 2 AS C1         UNION ALL SELECT 4 AS C1         UNION ALL SELECT 5 AS C1         UNION ALL SELECT 7 AS C1         UNION ALL SELECT 8 AS C1         UNION ALL SELECT 9 AS C1         UNION ALL SELECT 10 AS C1         UNION ALL SELECT 11 AS C1         UNION ALL SELECT 12 AS C1         UNION ALL SELECT 22 AS C1         UNION ALL SELECT 44 AS C1         UNION ALL SELECT 45 AS C1) V1,        (SELECT USER_ID         FROM oceanbase.__all_user         WHERE CONCAT(USER_NAME, '@', HOST) = CURRENT_USER()) CURR      LEFT JOIN        (SELECT USER_ID         FROM DB_PRIV         WHERE DATABASE_NAME = 'mysql'           AND PRIV_SELECT = 1) DB ON CURR.USER_ID = DB.USER_ID      WHERE TP.USER_ID = U.USER_ID        AND (DB.USER_ID IS NOT NULL             OR 512 & CURRENT_USER_PRIV() = 512             OR TP.USER_ID = CURR.USER_ID)) V   WHERE V.PRIVILEGE_TYPE IS NOT NULL   )__"))) {
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

int ObInnerTableSchema::user_privileges_schema(ObTableSchema &table_schema)
{
  int ret = OB_SUCCESS;
  uint64_t column_id = OB_APP_MIN_COLUMN_ID - 1;

  //generated fields:
  table_schema.set_database_id(OB_INFORMATION_SCHEMA_ID);
  table_schema.set_table_id(OB_USER_PRIVILEGES_TID);
  table_schema.set_rowkey_split_pos(0);
  table_schema.set_progressive_merge_num(0);
  table_schema.set_rowkey_column_num(0);
  table_schema.set_load_type(TABLE_LOAD_TYPE_IN_DISK);
  table_schema.set_table_type(SYSTEM_VIEW);
  table_schema.set_index_type(INDEX_TYPE_IS_NOT);
  table_schema.set_def_type(TABLE_DEF_TYPE_INTERNAL);

  if (OB_SUCC(ret)) {
    if (OB_FAIL(table_schema.set_table_name(OB_USER_PRIVILEGES_TNAME))) {
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
    if (OB_FAIL(table_schema.set_view_definition(R"__(   SELECT CAST(CONCAT('''', V.USER_NAME, '''', '@', '''', V.HOST, '''') AS CHAR(81)) AS GRANTEE ,          CAST('def' AS CHAR(512)) AS TABLE_CATALOG ,          CAST(V.PRIVILEGE_TYPE AS CHAR(64)) AS PRIVILEGE_TYPE ,          CAST(V.IS_GRANTABLE AS CHAR(3)) AS IS_GRANTABLE   FROM     (SELECT U.USER_NAME AS USER_NAME,             U.HOST AS HOST,             CASE                 WHEN V1.C1 = 1                      AND U.PRIV_ALTER = 1 THEN 'ALTER'                 WHEN V1.C1 = 2                      AND U.PRIV_CREATE = 1 THEN 'CREATE'                 WHEN V1.C1 = 3                      AND U.PRIV_CREATE_USER = 1 THEN 'CREATE USER'                 WHEN V1.C1 = 4                      AND U.PRIV_DELETE = 1 THEN 'DELETE'                 WHEN V1.C1 = 5                      AND U.PRIV_DROP = 1 THEN 'DROP'                 WHEN V1.C1 = 6                      AND U.PRIV_INSERT = 1 THEN 'INSERT'                 WHEN V1.C1 = 7                      AND U.PRIV_UPDATE = 1 THEN 'UPDATE'                 WHEN V1.C1 = 8                      AND U.PRIV_SELECT = 1 THEN 'SELECT'                 WHEN V1.C1 = 9                      AND U.PRIV_INDEX = 1 THEN 'INDEX'                 WHEN V1.C1 = 10                      AND U.PRIV_CREATE_VIEW = 1 THEN 'CREATE VIEW'                 WHEN V1.C1 = 11                      AND U.PRIV_SHOW_VIEW = 1 THEN 'SHOW VIEW'                 WHEN V1.C1 = 12                      AND U.PRIV_SHOW_DB = 1 THEN 'SHOW DATABASES'                 WHEN V1.C1 = 13                      AND U.PRIV_SUPER = 1 THEN 'SUPER'                 WHEN V1.C1 = 14                      AND U.PRIV_PROCESS = 1 THEN 'PROCESS'                 WHEN V1.C1 = 16                      AND (U.PRIV_OTHERS & (1 << 6)) != 0 THEN 'REFERENCES'                 WHEN V1.C1 = 17                      AND (U.PRIV_OTHERS & (1 << 0)) != 0 THEN 'EXECUTE'                 WHEN V1.C1 = 18                      AND U.PRIV_FILE = 1 THEN 'FILE'                 WHEN V1.C1 = 19                      AND U.PRIV_ALTER_SYSTEM = 1 THEN 'ALTER SYSTEM'                 WHEN V1.C1 = 20                      AND (U.PRIV_OTHERS & (1 << 1)) != 0 THEN 'ALTER ROUTINE'                 WHEN V1.C1 = 21                      AND (U.PRIV_OTHERS & (1 << 2)) != 0 THEN 'CREATE ROUTINE'                 WHEN V1.C1 = 22                      AND (U.PRIV_OTHERS & (1 << 3)) != 0 THEN 'CREATE TABLESPACE'                 WHEN V1.C1 = 23                      AND (U.PRIV_OTHERS & (1 << 4)) != 0 THEN 'SHUTDOWN'                 WHEN V1.C1 = 24                      AND (U.PRIV_OTHERS & (1 << 5)) != 0 THEN 'RELOAD'                 WHEN V1.C1 = 25                      AND (U.PRIV_OTHERS & (1 << 7)) != 0 THEN 'CREATE ROLE'                 WHEN V1.C1 = 26                      AND (U.PRIV_OTHERS & (1 << 8)) != 0 THEN 'DROP ROLE'                 WHEN V1.C1 = 27                      AND (U.PRIV_OTHERS & (1 << 9)) != 0 THEN 'TRIGGER'                 WHEN V1.C1 = 28                      AND (U.PRIV_OTHERS & (1 << 10)) != 0 THEN 'LOCK TABLES'                 WHEN V1.C1 = 29                      AND (U.PRIV_OTHERS & (1 << 11) != 0) THEN 'CREATE AI MODEL'                 WHEN V1.C1 = 30                      AND (U.PRIV_OTHERS & (1 << 12) != 0) THEN 'ALTER AI MODEL'                 WHEN V1.C1 = 31                      AND (U.PRIV_OTHERS & (1 << 13) != 0) THEN 'DROP AI MODEL'                 WHEN V1.C1 = 32                      AND (U.PRIV_OTHERS & (1 << 14) != 0) THEN 'ACCESS AI MODEL'                 WHEN V1.C1 = 33                      AND U.PRIV_REPL_SLAVE = 1 THEN 'REPLICATION SLAVE'                 WHEN V1.C1 = 34                      AND U.PRIV_REPL_CLIENT = 1 THEN 'REPLICATION CLIENT'                 WHEN V1.C1 = 0                      AND U.PRIV_ALTER = 0                      AND U.PRIV_CREATE = 0                      AND U.PRIV_CREATE_USER = 0                      AND U.PRIV_DELETE = 0                      AND U.PRIV_DROP = 0                      AND U.PRIV_INSERT = 0                      AND U.PRIV_UPDATE = 0                      AND U.PRIV_SELECT = 0                      AND U.PRIV_INDEX = 0                      AND U.PRIV_CREATE_VIEW = 0                      AND U.PRIV_SHOW_VIEW = 0                      AND U.PRIV_SHOW_DB = 0                      AND U.PRIV_SUPER = 0                      AND U.PRIV_PROCESS = 0                      AND U.PRIV_FILE = 0                      AND U.PRIV_ALTER_SYSTEM = 0                      AND U.PRIV_REPL_SLAVE = 0                      AND U.PRIV_REPL_CLIENT = 0                      AND U.PRIV_OTHERS = 0 THEN 'USAGE'             END PRIVILEGE_TYPE ,             CASE                 WHEN U.PRIV_GRANT_OPTION = 0 THEN 'NO'                 WHEN U.PRIV_ALTER = 0                      AND U.PRIV_CREATE = 0                      AND U.PRIV_CREATE_USER = 0                      AND U.PRIV_DELETE = 0                      AND U.PRIV_DROP = 0                      AND U.PRIV_INSERT = 0                      AND U.PRIV_UPDATE = 0                      AND U.PRIV_SELECT = 0                      AND U.PRIV_INDEX = 0                      AND U.PRIV_CREATE_VIEW = 0                      AND U.PRIV_SHOW_VIEW = 0                      AND U.PRIV_SHOW_DB = 0                      AND U.PRIV_SUPER = 0                      AND U.PRIV_PROCESS = 0                      AND U.PRIV_FILE = 0                      AND U.PRIV_ALTER_SYSTEM = 0                      AND U.PRIV_REPL_SLAVE = 0                      AND U.PRIV_REPL_CLIENT = 0                      AND U.PRIV_OTHERS = 0 THEN 'NO'                 WHEN U.PRIV_GRANT_OPTION = 1 THEN 'YES'             END IS_GRANTABLE      FROM oceanbase.__all_user U,        (SELECT 0 AS C1         UNION ALL SELECT 1 AS C1         UNION ALL SELECT 2 AS C1         UNION ALL SELECT 3 AS C1         UNION ALL SELECT 4 AS C1         UNION ALL SELECT 5 AS C1         UNION ALL SELECT 6 AS C1         UNION ALL SELECT 7 AS C1         UNION ALL SELECT 8 AS C1         UNION ALL SELECT 9 AS C1         UNION ALL SELECT 10 AS C1         UNION ALL SELECT 11 AS C1         UNION ALL SELECT 12 AS C1         UNION ALL SELECT 13 AS C1         UNION ALL SELECT 14 AS C1         UNION ALL SELECT 16 AS C1         UNION ALL SELECT 17 AS C1         UNION ALL SELECT 18 AS C1         UNION ALL SELECT 19 AS C1         UNION ALL SELECT 20 AS C1         UNION ALL SELECT 21 AS C1         UNION ALL SELECT 22 AS C1         UNION ALL SELECT 23 AS C1         UNION ALL SELECT 24 AS C1         UNION ALL SELECT 25 AS C1         UNION ALL SELECT 26 AS C1         UNION ALL SELECT 27 AS C1         UNION ALL SELECT 28 AS C1         UNION ALL SELECT 29 AS C1         UNION ALL SELECT 30 AS C1         UNION ALL SELECT 31 AS C1         UNION ALL SELECT 32 AS C1         UNION ALL SELECT 33 AS C1         UNION ALL SELECT 34 AS C1) V1,        (SELECT USER_ID         FROM oceanbase.__all_user         WHERE CONCAT(USER_NAME, '@', HOST) = CURRENT_USER()) CURR      LEFT JOIN        (SELECT USER_ID         FROM oceanbase.__all_database_privilege         WHERE DATABASE_NAME = 'mysql'           AND PRIV_SELECT = 1) DB ON CURR.USER_ID = DB.USER_ID      WHERE (DB.USER_ID IS NOT NULL             OR 512 & CURRENT_USER_PRIV() = 512             OR U.USER_ID = CURR.USER_ID)) V   WHERE V.PRIVILEGE_TYPE IS NOT NULL   )__"))) {
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

int ObInnerTableSchema::schema_privileges_schema(ObTableSchema &table_schema)
{
  int ret = OB_SUCCESS;
  uint64_t column_id = OB_APP_MIN_COLUMN_ID - 1;

  //generated fields:
  table_schema.set_database_id(OB_INFORMATION_SCHEMA_ID);
  table_schema.set_table_id(OB_SCHEMA_PRIVILEGES_TID);
  table_schema.set_rowkey_split_pos(0);
  table_schema.set_progressive_merge_num(0);
  table_schema.set_rowkey_column_num(0);
  table_schema.set_load_type(TABLE_LOAD_TYPE_IN_DISK);
  table_schema.set_table_type(SYSTEM_VIEW);
  table_schema.set_index_type(INDEX_TYPE_IS_NOT);
  table_schema.set_def_type(TABLE_DEF_TYPE_INTERNAL);

  if (OB_SUCC(ret)) {
    if (OB_FAIL(table_schema.set_table_name(OB_SCHEMA_PRIVILEGES_TNAME))) {
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
    if (OB_FAIL(table_schema.set_view_definition(R"__(   WITH DB_PRIV AS (     select A.user_id USER_ID,            A.database_name DATABASE_NAME,            A.priv_alter PRIV_ALTER,            A.priv_create PRIV_CREATE,            A.priv_delete PRIV_DELETE,            A.priv_drop PRIV_DROP,            A.priv_grant_option PRIV_GRANT_OPTION,            A.priv_insert PRIV_INSERT,            A.priv_update PRIV_UPDATE,            A.priv_select PRIV_SELECT,            A.priv_index PRIV_INDEX,            A.priv_create_view PRIV_CREATE_VIEW,            A.priv_show_view PRIV_SHOW_VIEW,            A.priv_others PRIV_OTHERS     from oceanbase.__all_database_privilege_history A,         (select user_id, database_name, max(schema_version) schema_version from oceanbase.__all_database_privilege_history group by user_id, database_name, database_name collate utf8mb4_bin) B     where A.user_id = B.user_id and A.database_name collate utf8mb4_bin = B.database_name collate utf8mb4_bin and A.schema_version = B.schema_version and A.is_deleted = 0   )   SELECT CAST(CONCAT('''', V.USER_NAME, '''', '@', '''', V.HOST, '''') AS CHAR(81)) AS GRANTEE ,          CAST('def' AS CHAR(512)) AS TABLE_CATALOG ,          CAST(V.DATABASE_NAME AS CHAR(128)) collate utf8mb4_name_case AS TABLE_SCHEMA ,          CAST(V.PRIVILEGE_TYPE AS CHAR(64)) AS PRIVILEGE_TYPE ,          CAST(V.IS_GRANTABLE AS CHAR(3)) AS IS_GRANTABLE   FROM     (SELECT DP.DATABASE_NAME DATABASE_NAME,             U.USER_NAME AS USER_NAME,             U.HOST AS HOST,             CASE                 WHEN V1.C1 = 1                      AND DP.PRIV_ALTER = 1 THEN 'ALTER'                 WHEN V1.C1 = 2                      AND DP.PRIV_CREATE = 1 THEN 'CREATE'                 WHEN V1.C1 = 4                      AND DP.PRIV_DELETE = 1 THEN 'DELETE'                 WHEN V1.C1 = 5                      AND DP.PRIV_DROP = 1 THEN 'DROP'                 WHEN V1.C1 = 6                      AND DP.PRIV_INSERT = 1 THEN 'INSERT'                 WHEN V1.C1 = 7                      AND DP.PRIV_UPDATE = 1 THEN 'UPDATE'                 WHEN V1.C1 = 8                      AND DP.PRIV_SELECT = 1 THEN 'SELECT'                 WHEN V1.C1 = 9                      AND DP.PRIV_INDEX = 1 THEN 'INDEX'                 WHEN V1.C1 = 10                      AND DP.PRIV_CREATE_VIEW = 1 THEN 'CREATE VIEW'                 WHEN V1.C1 = 11                      AND DP.PRIV_SHOW_VIEW = 1 THEN 'SHOW VIEW'                 WHEN V1.C1 = 16                      AND (DP.PRIV_OTHERS & (1 << 6)) != 0 THEN 'REFERENCES'                 WHEN V1.C1 = 17                      AND (DP.PRIV_OTHERS & (1 << 0)) != 0 THEN 'EXECUTE'                 WHEN V1.C1 = 20                      AND (DP.PRIV_OTHERS & (1 << 1)) != 0 THEN 'ALTER ROUTINE'                 WHEN V1.C1 = 21                      AND (DP.PRIV_OTHERS & (1 << 2)) != 0 THEN 'CREATE ROUTINE'                 WHEN V1.C1 = 27                      AND (DP.PRIV_OTHERS & (1 << 9)) != 0 THEN 'TRIGGER'                 WHEN V1.C1 = 28                      AND (DP.PRIV_OTHERS & (1 << 10)) != 0 THEN 'LOCK TABLES'                 ELSE NULL             END PRIVILEGE_TYPE ,             CASE                 WHEN DP.PRIV_GRANT_OPTION = 1 THEN 'YES'                 WHEN DP.PRIV_GRANT_OPTION = 0 THEN 'NO'             END IS_GRANTABLE      FROM DB_PRIV DP,                       oceanbase.__all_user U,        (SELECT 1 AS C1         UNION ALL SELECT 2 AS C1         UNION ALL SELECT 4 AS C1         UNION ALL SELECT 5 AS C1         UNION ALL SELECT 6 AS C1         UNION ALL SELECT 7 AS C1         UNION ALL SELECT 8 AS C1         UNION ALL SELECT 9 AS C1         UNION ALL SELECT 10 AS C1         UNION ALL SELECT 11 AS C1         UNION ALL SELECT 16 AS C1         UNION ALL SELECT 17 AS C1         UNION ALL SELECT 20 AS C1         UNION ALL SELECT 21 AS C1         UNION ALL SELECT 27 AS C1         UNION ALL SELECT 28 AS C1) V1,        (SELECT USER_ID         FROM oceanbase.__all_user         WHERE CONCAT(USER_NAME, '@', HOST) = CURRENT_USER()) CURR      LEFT JOIN        (SELECT USER_ID         FROM DB_PRIV         WHERE DATABASE_NAME = 'mysql'           AND PRIV_SELECT = 1) DB ON CURR.USER_ID = DB.USER_ID      WHERE DP.USER_ID = U.USER_ID        AND DP.DATABASE_NAME != '__recyclebin'        AND DP.DATABASE_NAME != '__public'        AND DP.DATABASE_NAME != 'SYS'        AND DP.DATABASE_NAME != 'LBACSYS'        AND DP.DATABASE_NAME != 'ORAAUDITOR'        AND (DB.USER_ID IS NOT NULL             OR 512 & CURRENT_USER_PRIV() = 512             OR DP.USER_ID = CURR.USER_ID)) V   WHERE V.PRIVILEGE_TYPE IS NOT NULL   )__"))) {
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
