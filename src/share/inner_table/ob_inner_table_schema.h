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

#ifndef _OB_INNER_TABLE_SCHEMA_H_
#define _OB_INNER_TABLE_SCHEMA_H_

#include "share/ob_define.h"
#include "ob_inner_table_schema_constants.h"
#include "share/ob_version_parser.h"

namespace oceanbase
{
namespace share
{
namespace schema
{
class ObTableSchema;
}
}

namespace share
{

struct ALL_VIRTUAL_PLAN_STAT_CDE {
  enum {
    PLAN_ID = common::OB_APP_MIN_COLUMN_ID,
    SQL_ID,
    TYPE,
    IS_BIND_SENSITIVE,
    IS_BIND_AWARE,
    STATEMENT,
    QUERY_SQL,
    SPECIAL_PARAMS,
    PARAM_INFOS,
    SYS_VARS,
    CONFIGS,
    PLAN_HASH,
    FIRST_LOAD_TIME,
    SCHEMA_VERSION,
    LAST_ACTIVE_TIME,
    AVG_EXE_USEC,
    SLOWEST_EXE_TIME,
    SLOWEST_EXE_USEC,
    SLOW_COUNT,
    HIT_COUNT,
    PLAN_SIZE,
    EXECUTIONS,
    DISK_READS,
    DIRECT_WRITES,
    BUFFER_GETS,
    APPLICATION_WAIT_TIME,
    CONCURRENCY_WAIT_TIME,
    USER_IO_WAIT_TIME,
    ROWS_PROCESSED,
    ELAPSED_TIME,
    CPU_TIME,
    OUTLINE_VERSION,
    OUTLINE_ID,
    OUTLINE_DATA,
    ACS_SEL_INFO,
    TABLE_SCAN,
    DB_ID,
    TIMEOUT_COUNT,
    PS_STMT_ID,
    DELAYED_PX_QUERYS,
    SESSID,
    TEMP_TABLES,
    OBJECT_TYPE,
    ENABLE_BF_CACHE,
    BF_FILTER_CNT,
    BF_ACCESS_CNT,
    ENABLE_ROW_CACHE,
    ROW_CACHE_HIT_CNT,
    ROW_CACHE_MISS_CNT,
    ENABLE_FUSE_ROW_CACHE,
    FUSE_ROW_CACHE_HIT_CNT,
    FUSE_ROW_CACHE_MISS_CNT,
    HINTS_INFO,
    HINTS_ALL_WORKED,
    PL_SCHEMA_ID,
    IS_BATCHED_MULTI_STMT,
    OBJECT_STATUS,
    RULE_NAME,
    IS_IN_PC,
    ERASE_TIME,
    COMPILE_TIME,
    PL_EVICT_VERSION,
    FIRST_GET_PLAN_TIME,
    FIRST_EXE_USEC
  };
};


struct ALL_VIRTUAL_PARAMETER_STAT_CDE {
  enum {
    SVR_TYPE = common::OB_APP_MIN_COLUMN_ID,
    NAME,
    DATA_TYPE,
    VALUE,
    VALUE_STRICT,
    INFO,
    NEED_REBOOT,
    SECTION,
    VISIBLE_LEVEL,
    SCOPE,
    SOURCE,
    EDIT_LEVEL,
    DEFAULT_VALUE,
    ISDEFAULT
  };
};


struct ALL_VIRTUAL_PS_STAT_CDE {
  enum {
    STMT_COUNT = common::OB_APP_MIN_COLUMN_ID,
    HIT_COUNT,
    ACCESS_COUNT,
    MEM_HOLD
  };
};


struct ALL_VIRTUAL_PS_ITEM_INFO_CDE {
  enum {
    STMT_ID = common::OB_APP_MIN_COLUMN_ID,
    DB_ID,
    PS_SQL,
    PARAM_COUNT,
    STMT_ITEM_REF_COUNT,
    STMT_INFO_REF_COUNT,
    MEM_HOLD,
    STMT_TYPE,
    CHECKSUM,
    EXPIRED
  };
};


struct ALL_VIRTUAL_SESSION_PS_INFO_CDE {
  enum {
    SESSION_ID = common::OB_APP_MIN_COLUMN_ID,
    PS_CLIENT_STMT_ID,
    PS_INNER_STMT_ID,
    STMT_TYPE,
    PARAM_COUNT,
    PARAM_TYPES,
    REF_COUNT,
    CHECKSUM
  };
};

class ObInnerTableSchema
{

public:
  static int all_core_table_schema(share::schema::ObTableSchema &table_schema);
  static int all_table_schema(share::schema::ObTableSchema &table_schema);
  static int all_column_schema(share::schema::ObTableSchema &table_schema);
  static int all_ddl_operation_schema(share::schema::ObTableSchema &table_schema);
  static int all_table_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_column_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_part_schema(share::schema::ObTableSchema &table_schema);
  static int all_part_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_sub_part_schema(share::schema::ObTableSchema &table_schema);
  static int all_sub_part_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_part_info_schema(share::schema::ObTableSchema &table_schema);
  static int all_part_info_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_def_sub_part_schema(share::schema::ObTableSchema &table_schema);
  static int all_def_sub_part_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_sys_variable_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_foreign_key_schema(share::schema::ObTableSchema &table_schema);
  static int all_foreign_key_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_constraint_schema(share::schema::ObTableSchema &table_schema);
  static int all_constraint_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_trigger_schema(share::schema::ObTableSchema &table_schema);
  static int all_trigger_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_table_stat_schema(share::schema::ObTableSchema &table_schema);
  static int all_column_stat_schema(share::schema::ObTableSchema &table_schema);
  static int all_histogram_stat_schema(share::schema::ObTableSchema &table_schema);
  static int all_column_stat_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_histogram_stat_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_aux_stat_schema(share::schema::ObTableSchema &table_schema);
  static int all_user_schema(share::schema::ObTableSchema &table_schema);
  static int all_user_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_database_schema(share::schema::ObTableSchema &table_schema);
  static int all_database_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_table_privilege_schema(share::schema::ObTableSchema &table_schema);
  static int all_table_privilege_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_database_privilege_schema(share::schema::ObTableSchema &table_schema);
  static int all_database_privilege_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_sys_variable_schema(share::schema::ObTableSchema &table_schema);
  static int all_sys_stat_schema(share::schema::ObTableSchema &table_schema);
  static int all_outline_schema(share::schema::ObTableSchema &table_schema);
  static int all_outline_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_recyclebin_schema(share::schema::ObTableSchema &table_schema);
  static int all_foreign_key_column_schema(share::schema::ObTableSchema &table_schema);
  static int all_foreign_key_column_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_auto_increment_schema(share::schema::ObTableSchema &table_schema);
  static int all_ddl_checksum_schema(share::schema::ObTableSchema &table_schema);
  static int all_routine_schema(share::schema::ObTableSchema &table_schema);
  static int all_routine_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_routine_param_schema(share::schema::ObTableSchema &table_schema);
  static int all_routine_param_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_package_schema(share::schema::ObTableSchema &table_schema);
  static int all_package_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_acquired_snapshot_schema(share::schema::ObTableSchema &table_schema);
  static int all_ori_schema_version_schema(share::schema::ObTableSchema &table_schema);
  static int all_role_grantee_map_schema(share::schema::ObTableSchema &table_schema);
  static int all_role_grantee_map_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_sysauth_schema(share::schema::ObTableSchema &table_schema);
  static int all_sysauth_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_objauth_schema(share::schema::ObTableSchema &table_schema);
  static int all_objauth_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_error_schema(share::schema::ObTableSchema &table_schema);
  static int all_time_zone_name_schema(share::schema::ObTableSchema &table_schema);
  static int all_time_zone_transition_schema(share::schema::ObTableSchema &table_schema);
  static int all_time_zone_transition_type_schema(share::schema::ObTableSchema &table_schema);
  static int all_constraint_column_schema(share::schema::ObTableSchema &table_schema);
  static int all_constraint_column_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_dependency_schema(share::schema::ObTableSchema &table_schema);
  static int all_ddl_error_message_schema(share::schema::ObTableSchema &table_schema);
  static int all_ddl_task_status_schema(share::schema::ObTableSchema &table_schema);
  static int all_column_usage_schema(share::schema::ObTableSchema &table_schema);
  static int all_job_schema(share::schema::ObTableSchema &table_schema);
  static int all_monitor_modified_schema(share::schema::ObTableSchema &table_schema);
  static int all_table_stat_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_optstat_global_prefs_schema(share::schema::ObTableSchema &table_schema);
  static int all_optstat_user_prefs_schema(share::schema::ObTableSchema &table_schema);
  static int all_tablet_to_table_schema(share::schema::ObTableSchema &table_schema);
  static int all_tablet_to_table_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_tablet_checksum_schema(share::schema::ObTableSchema &table_schema);
  static int all_scheduler_job_schema(share::schema::ObTableSchema &table_schema);
  static int all_scheduler_program_schema(share::schema::ObTableSchema &table_schema);
  static int all_scheduler_program_argument_schema(share::schema::ObTableSchema &table_schema);
  static int all_freeze_info_schema(share::schema::ObTableSchema &table_schema);
  static int all_mock_fk_parent_table_schema(share::schema::ObTableSchema &table_schema);
  static int all_mock_fk_parent_table_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_mock_fk_parent_table_column_schema(share::schema::ObTableSchema &table_schema);
  static int all_mock_fk_parent_table_column_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_spatial_reference_systems_schema(share::schema::ObTableSchema &table_schema);
  static int all_dbms_lock_allocated_schema(share::schema::ObTableSchema &table_schema);
  static int all_scheduler_job_class_schema(share::schema::ObTableSchema &table_schema);
  static int all_routine_privilege_schema(share::schema::ObTableSchema &table_schema);
  static int all_routine_privilege_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_column_privilege_schema(share::schema::ObTableSchema &table_schema);
  static int all_column_privilege_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_detect_lock_info_v2_schema(share::schema::ObTableSchema &table_schema);
  static int ft_dict_ik_utf8_schema(share::schema::ObTableSchema &table_schema);
  static int ft_stopword_ik_utf8_schema(share::schema::ObTableSchema &table_schema);
  static int ft_quantifier_ik_utf8_schema(share::schema::ObTableSchema &table_schema);
  static int all_vector_index_task_schema(share::schema::ObTableSchema &table_schema);
  static int all_vector_index_task_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_ai_model_schema(share::schema::ObTableSchema &table_schema);
  static int all_ai_model_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_ai_model_endpoint_schema(share::schema::ObTableSchema &table_schema);
  static int all_ai_column_schema(share::schema::ObTableSchema &table_schema);
  static int all_ai_column_task_schema(share::schema::ObTableSchema &table_schema);
  static int all_objauth_mysql_schema(share::schema::ObTableSchema &table_schema);
  static int all_objauth_mysql_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_all_table_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_table_column_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_table_index_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_show_create_database_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_show_create_table_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_session_variable_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_privilege_grant_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_processlist_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_warning_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_database_status_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_global_variable_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_show_tables_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_show_create_procedure_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_plan_cache_stat_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_plan_stat_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_kvcache_info_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_data_type_class_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_data_type_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_memstore_info_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_concurrency_object_pool_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_disk_stat_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_tablet_memstore_info_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_trans_stat_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_trans_ctx_mgr_stat_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_trans_scheduler_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_core_all_table_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_core_column_table_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_memory_info_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_sys_parameter_stat_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_sys_parameter_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_engine_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_plan_cache_plan_explain_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_outline_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_tablet_sstable_macro_info_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_sys_task_status_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_macro_block_marker_status_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_io_stat_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_long_ops_status_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_server_object_pool_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_trans_lock_stat_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_parameter_stat_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_server_schema_info_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_memory_context_stat_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_dump_info_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_dag_warning_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_dag_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_dag_scheduler_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_server_compaction_progress_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_tablet_compaction_progress_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_compaction_diagnose_info_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_compaction_suggestion_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_session_info_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_tablet_compaction_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_io_calibration_status_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_io_benchmark_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_io_quota_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_server_compaction_event_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_tablet_stat_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_ddl_sim_point_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_ddl_sim_point_stat_schema(share::schema::ObTableSchema &table_schema);
  static int session_variables_schema(share::schema::ObTableSchema &table_schema);
  static int global_status_schema(share::schema::ObTableSchema &table_schema);
  static int session_status_schema(share::schema::ObTableSchema &table_schema);
  static int user_schema(share::schema::ObTableSchema &table_schema);
  static int db_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_lock_wait_stat_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_collation_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_charset_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_memstore_allocator_info_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_table_mgr_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_bad_block_table_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_px_worker_stat_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_tablet_store_stat_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_raid_stat_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_dtl_channel_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_dtl_memory_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_information_columns_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_ps_stat_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_ps_item_info_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_sql_workarea_history_stat_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_sql_workarea_active_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_sql_workarea_histogram_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_sql_workarea_memory_info_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_id_service_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_open_cursor_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_files_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_deadlock_event_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_ctx_memory_info_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_show_create_trigger_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_px_target_monitor_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_tablet_meta_table_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_load_data_stat_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_log_stat_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_tablet_local_checksum_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_server_stat_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_dtl_interm_result_monitor_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_apply_stat_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_replay_stat_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_ls_info_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_tablet_info_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_obj_lock_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_merge_info_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_tx_data_table_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_transaction_freeze_checkpoint_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_transaction_checkpoint_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_checkpoint_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_dml_stats_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_tablet_ddl_kv_info_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_privilege_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_tablet_pointer_status_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_storage_meta_memory_status_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_kvcache_store_memblock_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_column_checksum_error_info_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_tablet_compaction_info_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_schema_memory_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_schema_slot_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_minor_freeze_info_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_show_trace_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_sql_plan_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_malloc_sample_info_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_mds_node_stat_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_mds_event_history_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_tx_data_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_opt_stat_gather_monitor_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_timestamp_service_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_px_p2p_datahub_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_tablet_buffer_info_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_data_activity_metrics_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_scheduler_running_job_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_sqlstat_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_sys_variable_default_value_schema(share::schema::ObTableSchema &table_schema);
  static int enabled_roles_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_session_ps_info_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_tracepoint_info_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_resource_limit_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_resource_limit_detail_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_group_io_stat_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_nic_info_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_vector_index_info_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_temp_file_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_vector_mem_info_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_rootservice_job_schema(share::schema::ObTableSchema &table_schema);
  static int all_virtual_change_stream_refresh_stat_schema(share::schema::ObTableSchema &table_schema);
  static int schemata_schema(share::schema::ObTableSchema &table_schema);
  static int character_sets_schema(share::schema::ObTableSchema &table_schema);
  static int global_variables_schema(share::schema::ObTableSchema &table_schema);
  static int statistics_schema(share::schema::ObTableSchema &table_schema);
  static int views_schema(share::schema::ObTableSchema &table_schema);
  static int tables_schema(share::schema::ObTableSchema &table_schema);
  static int collations_schema(share::schema::ObTableSchema &table_schema);
  static int collation_character_set_applicability_schema(share::schema::ObTableSchema &table_schema);
  static int processlist_schema(share::schema::ObTableSchema &table_schema);
  static int key_column_usage_schema(share::schema::ObTableSchema &table_schema);
  static int engines_schema(share::schema::ObTableSchema &table_schema);
  static int routines_schema(share::schema::ObTableSchema &table_schema);
  static int profiling_schema(share::schema::ObTableSchema &table_schema);
  static int optimizer_trace_schema(share::schema::ObTableSchema &table_schema);
  static int innodb_sys_columns_schema(share::schema::ObTableSchema &table_schema);
  static int innodb_ft_being_deleted_schema(share::schema::ObTableSchema &table_schema);
  static int innodb_ft_config_schema(share::schema::ObTableSchema &table_schema);
  static int innodb_ft_deleted_schema(share::schema::ObTableSchema &table_schema);
  static int innodb_ft_index_cache_schema(share::schema::ObTableSchema &table_schema);
  static int v_ob_memory_schema(share::schema::ObTableSchema &table_schema);
  static int v_ob_plan_cache_plan_stat_schema(share::schema::ObTableSchema &table_schema);
  static int dba_recyclebin_schema(share::schema::ObTableSchema &table_schema);
  static int time_zone_name_schema(share::schema::ObTableSchema &table_schema);
  static int time_zone_transition_schema(share::schema::ObTableSchema &table_schema);
  static int time_zone_transition_type_schema(share::schema::ObTableSchema &table_schema);
  static int v_session_longops_schema(share::schema::ObTableSchema &table_schema);
  static int columns_schema(share::schema::ObTableSchema &table_schema);
  static int v_sql_workarea_schema(share::schema::ObTableSchema &table_schema);
  static int v_sql_workarea_active_schema(share::schema::ObTableSchema &table_schema);
  static int v_sql_workarea_histogram_schema(share::schema::ObTableSchema &table_schema);
  static int v_ob_sstables_schema(share::schema::ObTableSchema &table_schema);
  static int v_ob_merge_info_schema(share::schema::ObTableSchema &table_schema);
  static int v_ob_px_target_monitor_schema(share::schema::ObTableSchema &table_schema);
  static int column_privileges_schema(share::schema::ObTableSchema &table_schema);
  static int view_table_usage_schema(share::schema::ObTableSchema &table_schema);
  static int files_schema(share::schema::ObTableSchema &table_schema);
  static int dba_ob_databases_schema(share::schema::ObTableSchema &table_schema);
  static int dba_ob_major_compaction_schema(share::schema::ObTableSchema &table_schema);
  static int dba_objects_schema(share::schema::ObTableSchema &table_schema);
  static int dba_part_tables_schema(share::schema::ObTableSchema &table_schema);
  static int dba_part_key_columns_schema(share::schema::ObTableSchema &table_schema);
  static int dba_subpart_key_columns_schema(share::schema::ObTableSchema &table_schema);
  static int dba_tab_partitions_schema(share::schema::ObTableSchema &table_schema);
  static int dba_tab_subpartitions_schema(share::schema::ObTableSchema &table_schema);
  static int dba_subpartition_templates_schema(share::schema::ObTableSchema &table_schema);
  static int dba_part_indexes_schema(share::schema::ObTableSchema &table_schema);
  static int dba_ind_partitions_schema(share::schema::ObTableSchema &table_schema);
  static int dba_ind_subpartitions_schema(share::schema::ObTableSchema &table_schema);
  static int v_ob_server_stat_schema(share::schema::ObTableSchema &table_schema);
  static int v_ob_parameters_schema(share::schema::ObTableSchema &table_schema);
  static int v_ob_processlist_schema(share::schema::ObTableSchema &table_schema);
  static int v_ob_transaction_write_state_schema(share::schema::ObTableSchema &table_schema);
  static int v_ob_tablet_compaction_history_schema(share::schema::ObTableSchema &table_schema);
  static int v_ob_compaction_diagnose_info_schema(share::schema::ObTableSchema &table_schema);
  static int dba_tab_statistics_schema(share::schema::ObTableSchema &table_schema);
  static int dba_tab_col_statistics_schema(share::schema::ObTableSchema &table_schema);
  static int dba_part_col_statistics_schema(share::schema::ObTableSchema &table_schema);
  static int dba_subpart_col_statistics_schema(share::schema::ObTableSchema &table_schema);
  static int dba_tab_histograms_schema(share::schema::ObTableSchema &table_schema);
  static int dba_part_histograms_schema(share::schema::ObTableSchema &table_schema);
  static int dba_subpart_histograms_schema(share::schema::ObTableSchema &table_schema);
  static int dba_tab_stats_history_schema(share::schema::ObTableSchema &table_schema);
  static int dba_ind_statistics_schema(share::schema::ObTableSchema &table_schema);
  static int v_dml_stats_schema(share::schema::ObTableSchema &table_schema);
  static int dba_tab_modifications_schema(share::schema::ObTableSchema &table_schema);
  static int dba_scheduler_jobs_schema(share::schema::ObTableSchema &table_schema);
  static int dba_ob_outlines_schema(share::schema::ObTableSchema &table_schema);
  static int dba_ob_deadlock_event_history_schema(share::schema::ObTableSchema &table_schema);
  static int v_ob_log_stat_schema(share::schema::ObTableSchema &table_schema);
  static int st_geometry_columns_schema(share::schema::ObTableSchema &table_schema);
  static int st_spatial_reference_systems_schema(share::schema::ObTableSchema &table_schema);
  static int dba_ob_freeze_info_schema(share::schema::ObTableSchema &table_schema);
  static int dba_ob_auto_increment_schema(share::schema::ObTableSchema &table_schema);
  static int dba_scheduler_windows_schema(share::schema::ObTableSchema &table_schema);
  static int dba_ob_users_schema(share::schema::ObTableSchema &table_schema);
  static int dba_ob_database_privilege_schema(share::schema::ObTableSchema &table_schema);
  static int parameters_schema(share::schema::ObTableSchema &table_schema);
  static int table_privileges_schema(share::schema::ObTableSchema &table_schema);
  static int user_privileges_schema(share::schema::ObTableSchema &table_schema);
  static int schema_privileges_schema(share::schema::ObTableSchema &table_schema);
  static int check_constraints_schema(share::schema::ObTableSchema &table_schema);
  static int referential_constraints_schema(share::schema::ObTableSchema &table_schema);
  static int table_constraints_schema(share::schema::ObTableSchema &table_schema);
  static int v_ob_transaction_schedulers_schema(share::schema::ObTableSchema &table_schema);
  static int triggers_schema(share::schema::ObTableSchema &table_schema);
  static int partitions_schema(share::schema::ObTableSchema &table_schema);
  static int v_ob_opt_stat_gather_monitor_schema(share::schema::ObTableSchema &table_schema);
  static int v_ob_locks_schema(share::schema::ObTableSchema &table_schema);
  static int v_ob_timestamp_service_schema(share::schema::ObTableSchema &table_schema);
  static int v_ob_px_p2p_datahub_schema(share::schema::ObTableSchema &table_schema);
  static int dba_ob_table_stat_stale_info_schema(share::schema::ObTableSchema &table_schema);
  static int v_ob_session_schema(share::schema::ObTableSchema &table_schema);
  static int v_ob_pl_cache_object_schema(share::schema::ObTableSchema &table_schema);
  static int dba_ob_format_outlines_schema(share::schema::ObTableSchema &table_schema);
  static int procs_priv_schema(share::schema::ObTableSchema &table_schema);
  static int dba_ob_aux_statistics_schema(share::schema::ObTableSchema &table_schema);
  static int dba_ob_sys_variables_schema(share::schema::ObTableSchema &table_schema);
  static int role_edges_schema(share::schema::ObTableSchema &table_schema);
  static int default_roles_schema(share::schema::ObTableSchema &table_schema);
  static int columns_priv_schema(share::schema::ObTableSchema &table_schema);
  static int innodb_lock_waits_schema(share::schema::ObTableSchema &table_schema);
  static int innodb_locks_schema(share::schema::ObTableSchema &table_schema);
  static int innodb_trx_schema(share::schema::ObTableSchema &table_schema);
  static int ndb_transid_mysql_connection_map_schema(share::schema::ObTableSchema &table_schema);
  static int v_ob_group_io_stat_schema(share::schema::ObTableSchema &table_schema);
  static int tablespaces_schema(share::schema::ObTableSchema &table_schema);
  static int innodb_buffer_page_schema(share::schema::ObTableSchema &table_schema);
  static int innodb_buffer_page_lru_schema(share::schema::ObTableSchema &table_schema);
  static int innodb_buffer_pool_stats_schema(share::schema::ObTableSchema &table_schema);
  static int innodb_cmp_schema(share::schema::ObTableSchema &table_schema);
  static int innodb_cmp_per_index_schema(share::schema::ObTableSchema &table_schema);
  static int innodb_cmp_per_index_reset_schema(share::schema::ObTableSchema &table_schema);
  static int innodb_cmp_reset_schema(share::schema::ObTableSchema &table_schema);
  static int innodb_cmpmem_schema(share::schema::ObTableSchema &table_schema);
  static int innodb_cmpmem_reset_schema(share::schema::ObTableSchema &table_schema);
  static int innodb_sys_datafiles_schema(share::schema::ObTableSchema &table_schema);
  static int innodb_sys_indexes_schema(share::schema::ObTableSchema &table_schema);
  static int innodb_sys_tables_schema(share::schema::ObTableSchema &table_schema);
  static int innodb_sys_tablespaces_schema(share::schema::ObTableSchema &table_schema);
  static int innodb_sys_tablestats_schema(share::schema::ObTableSchema &table_schema);
  static int innodb_sys_virtual_schema(share::schema::ObTableSchema &table_schema);
  static int innodb_temp_table_info_schema(share::schema::ObTableSchema &table_schema);
  static int innodb_metrics_schema(share::schema::ObTableSchema &table_schema);
  static int role_table_grants_schema(share::schema::ObTableSchema &table_schema);
  static int role_column_grants_schema(share::schema::ObTableSchema &table_schema);
  static int role_routine_grants_schema(share::schema::ObTableSchema &table_schema);
  static int dba_ob_table_space_usage_schema(share::schema::ObTableSchema &table_schema);
  static int innodb_sys_fields_schema(share::schema::ObTableSchema &table_schema);
  static int innodb_sys_foreign_schema(share::schema::ObTableSchema &table_schema);
  static int innodb_sys_foreign_cols_schema(share::schema::ObTableSchema &table_schema);
  static int dba_ob_temp_files_schema(share::schema::ObTableSchema &table_schema);
  static int proc_schema(share::schema::ObTableSchema &table_schema);
  static int dba_ob_vector_index_tasks_schema(share::schema::ObTableSchema &table_schema);
  static int dba_ob_vector_index_task_history_schema(share::schema::ObTableSchema &table_schema);
  static int v_ob_vector_memory_schema(share::schema::ObTableSchema &table_schema);
  static int dba_ob_ai_models_schema(share::schema::ObTableSchema &table_schema);
  static int dba_ob_ai_model_endpoints_schema(share::schema::ObTableSchema &table_schema);
  static int dba_ob_rootservice_jobs_schema(share::schema::ObTableSchema &table_schema);
  static int dba_ob_change_stream_refresh_stat_schema(share::schema::ObTableSchema &table_schema);
  static int all_table_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_column_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_ddl_operation_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_table_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_column_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_part_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_part_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_sub_part_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_sub_part_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_part_info_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_part_info_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_def_sub_part_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_def_sub_part_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_sys_variable_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_foreign_key_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_foreign_key_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_constraint_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_constraint_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_trigger_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_trigger_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_table_stat_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_column_stat_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_histogram_stat_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_column_stat_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_histogram_stat_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_aux_stat_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_user_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_user_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_database_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_database_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_table_privilege_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_table_privilege_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_database_privilege_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_database_privilege_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_sys_variable_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_sys_stat_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_outline_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_outline_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_recyclebin_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_foreign_key_column_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_foreign_key_column_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_auto_increment_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_ddl_checksum_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_routine_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_routine_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_routine_param_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_routine_param_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_package_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_package_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_acquired_snapshot_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_ori_schema_version_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_role_grantee_map_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_role_grantee_map_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_sysauth_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_sysauth_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_objauth_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_objauth_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_error_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_time_zone_name_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_time_zone_transition_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_time_zone_transition_type_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_constraint_column_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_constraint_column_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_dependency_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_ddl_error_message_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_ddl_task_status_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_column_usage_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_job_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_monitor_modified_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_table_stat_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_optstat_global_prefs_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_optstat_user_prefs_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_tablet_to_table_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_tablet_to_table_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_tablet_checksum_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_scheduler_job_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_scheduler_program_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_scheduler_program_argument_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_freeze_info_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_mock_fk_parent_table_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_mock_fk_parent_table_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_mock_fk_parent_table_column_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_mock_fk_parent_table_column_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_spatial_reference_systems_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_dbms_lock_allocated_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_scheduler_job_class_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_routine_privilege_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_routine_privilege_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_column_privilege_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_column_privilege_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_detect_lock_info_v2_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int ft_dict_ik_utf8_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int ft_stopword_ik_utf8_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int ft_quantifier_ik_utf8_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_vector_index_task_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_vector_index_task_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_ai_model_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_ai_model_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_ai_model_endpoint_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_ai_column_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_ai_column_task_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_objauth_mysql_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_objauth_mysql_history_aux_lob_meta_schema(share::schema::ObTableSchema &table_schema);
  static int all_table_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_column_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_ddl_operation_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_table_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_column_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_part_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_part_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_sub_part_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_sub_part_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_part_info_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_part_info_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_def_sub_part_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_def_sub_part_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_sys_variable_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_foreign_key_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_foreign_key_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_constraint_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_constraint_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_trigger_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_trigger_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_table_stat_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_column_stat_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_histogram_stat_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_column_stat_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_histogram_stat_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_aux_stat_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_user_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_user_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_database_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_database_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_table_privilege_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_table_privilege_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_database_privilege_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_database_privilege_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_sys_variable_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_sys_stat_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_outline_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_outline_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_recyclebin_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_foreign_key_column_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_foreign_key_column_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_auto_increment_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_ddl_checksum_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_routine_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_routine_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_routine_param_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_routine_param_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_package_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_package_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_acquired_snapshot_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_ori_schema_version_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_role_grantee_map_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_role_grantee_map_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_sysauth_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_sysauth_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_objauth_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_objauth_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_error_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_time_zone_name_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_time_zone_transition_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_time_zone_transition_type_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_constraint_column_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_constraint_column_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_dependency_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_ddl_error_message_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_ddl_task_status_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_column_usage_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_job_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_monitor_modified_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_table_stat_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_optstat_global_prefs_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_optstat_user_prefs_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_tablet_to_table_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_tablet_to_table_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_tablet_checksum_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_scheduler_job_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_scheduler_program_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_scheduler_program_argument_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_freeze_info_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_mock_fk_parent_table_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_mock_fk_parent_table_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_mock_fk_parent_table_column_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_mock_fk_parent_table_column_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_spatial_reference_systems_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_dbms_lock_allocated_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_scheduler_job_class_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_routine_privilege_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_routine_privilege_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_column_privilege_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_column_privilege_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_detect_lock_info_v2_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int ft_dict_ik_utf8_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int ft_stopword_ik_utf8_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int ft_quantifier_ik_utf8_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_vector_index_task_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_vector_index_task_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_ai_model_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_ai_model_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_ai_model_endpoint_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_ai_column_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_ai_column_task_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_objauth_mysql_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_objauth_mysql_history_aux_lob_piece_schema(share::schema::ObTableSchema &table_schema);
  static int all_table_idx_data_table_id_schema(share::schema::ObTableSchema &table_schema);
  static int all_table_idx_db_tb_name_schema(share::schema::ObTableSchema &table_schema);
  static int all_table_idx_tb_name_schema(share::schema::ObTableSchema &table_schema);
  static int all_column_idx_tb_column_name_schema(share::schema::ObTableSchema &table_schema);
  static int all_column_idx_column_name_schema(share::schema::ObTableSchema &table_schema);
  static int all_ddl_operation_idx_ddl_type_schema(share::schema::ObTableSchema &table_schema);
  static int all_table_history_idx_data_table_id_schema(share::schema::ObTableSchema &table_schema);
  static int all_part_idx_part_name_schema(share::schema::ObTableSchema &table_schema);
  static int all_sub_part_idx_sub_part_name_schema(share::schema::ObTableSchema &table_schema);
  static int all_def_sub_part_idx_def_sub_part_name_schema(share::schema::ObTableSchema &table_schema);
  static int all_foreign_key_idx_fk_child_tid_schema(share::schema::ObTableSchema &table_schema);
  static int all_foreign_key_idx_fk_parent_tid_schema(share::schema::ObTableSchema &table_schema);
  static int all_foreign_key_idx_fk_name_schema(share::schema::ObTableSchema &table_schema);
  static int all_foreign_key_history_idx_fk_his_child_tid_schema(share::schema::ObTableSchema &table_schema);
  static int all_foreign_key_history_idx_fk_his_parent_tid_schema(share::schema::ObTableSchema &table_schema);
  static int all_constraint_idx_cst_name_schema(share::schema::ObTableSchema &table_schema);
  static int all_trigger_idx_trigger_base_obj_id_schema(share::schema::ObTableSchema &table_schema);
  static int all_trigger_idx_db_trigger_name_schema(share::schema::ObTableSchema &table_schema);
  static int all_trigger_idx_trigger_name_schema(share::schema::ObTableSchema &table_schema);
  static int all_trigger_history_idx_trigger_his_base_obj_id_schema(share::schema::ObTableSchema &table_schema);
  static int all_ddl_task_status_idx_task_key_schema(share::schema::ObTableSchema &table_schema);
  static int all_user_idx_ur_name_schema(share::schema::ObTableSchema &table_schema);
  static int all_database_idx_db_name_schema(share::schema::ObTableSchema &table_schema);
  static int all_recyclebin_idx_recyclebin_db_type_schema(share::schema::ObTableSchema &table_schema);
  static int all_ddl_checksum_idx_ddl_checksum_task_schema(share::schema::ObTableSchema &table_schema);
  static int all_routine_idx_db_routine_name_schema(share::schema::ObTableSchema &table_schema);
  static int all_routine_idx_routine_name_schema(share::schema::ObTableSchema &table_schema);
  static int all_routine_idx_routine_pkg_id_schema(share::schema::ObTableSchema &table_schema);
  static int all_routine_param_idx_routine_param_name_schema(share::schema::ObTableSchema &table_schema);
  static int all_package_idx_db_pkg_name_schema(share::schema::ObTableSchema &table_schema);
  static int all_package_idx_pkg_name_schema(share::schema::ObTableSchema &table_schema);
  static int all_acquired_snapshot_idx_snapshot_tablet_schema(share::schema::ObTableSchema &table_schema);
  static int all_role_grantee_map_idx_grantee_role_id_schema(share::schema::ObTableSchema &table_schema);
  static int all_role_grantee_map_history_idx_grantee_his_role_id_schema(share::schema::ObTableSchema &table_schema);
  static int all_objauth_idx_objauth_grantor_schema(share::schema::ObTableSchema &table_schema);
  static int all_objauth_idx_objauth_grantee_schema(share::schema::ObTableSchema &table_schema);
  static int all_dependency_idx_dependency_ref_obj_schema(share::schema::ObTableSchema &table_schema);
  static int all_ddl_error_message_idx_ddl_error_object_schema(share::schema::ObTableSchema &table_schema);
  static int all_table_stat_history_idx_table_stat_his_savtime_schema(share::schema::ObTableSchema &table_schema);
  static int all_column_stat_history_idx_column_stat_his_savtime_schema(share::schema::ObTableSchema &table_schema);
  static int all_histogram_stat_history_idx_histogram_stat_his_savtime_schema(share::schema::ObTableSchema &table_schema);
  static int all_tablet_to_table_idx_tablet_to_table_id_schema(share::schema::ObTableSchema &table_schema);
  static int all_job_idx_job_powner_schema(share::schema::ObTableSchema &table_schema);
  static int all_recyclebin_idx_recyclebin_ori_name_schema(share::schema::ObTableSchema &table_schema);
  static int all_table_privilege_idx_tb_priv_db_name_schema(share::schema::ObTableSchema &table_schema);
  static int all_table_privilege_idx_tb_priv_tb_name_schema(share::schema::ObTableSchema &table_schema);
  static int all_database_privilege_idx_db_priv_db_name_schema(share::schema::ObTableSchema &table_schema);
  static int all_dbms_lock_allocated_idx_dbms_lock_allocated_lockhandle_schema(share::schema::ObTableSchema &table_schema);
  static int all_dbms_lock_allocated_idx_dbms_lock_allocated_expiration_schema(share::schema::ObTableSchema &table_schema);
  static int all_column_privilege_idx_column_privilege_name_schema(share::schema::ObTableSchema &table_schema);
  static int all_ai_model_endpoint_idx_endpoint_name_schema(share::schema::ObTableSchema &table_schema);
  static int all_ai_model_endpoint_idx_ai_model_name_schema(share::schema::ObTableSchema &table_schema);
  static int all_objauth_mysql_idx_objauth_mysql_user_id_schema(share::schema::ObTableSchema &table_schema);
  static int all_objauth_mysql_idx_objauth_mysql_obj_name_schema(share::schema::ObTableSchema &table_schema);

private:
  DISALLOW_COPY_AND_ASSIGN(ObInnerTableSchema);
};

typedef int (*schema_create_func)(share::schema::ObTableSchema &table_schema);

const schema_create_func all_core_table_schema_creator [] = {
  ObInnerTableSchema::all_core_table_schema,
  NULL,};

const schema_create_func core_table_schema_creators [] = {
  ObInnerTableSchema::all_table_schema,
  ObInnerTableSchema::all_column_schema,
  ObInnerTableSchema::all_ddl_operation_schema,
  ObInnerTableSchema::all_table_history_schema,
  ObInnerTableSchema::all_column_history_schema,
  NULL,};

const schema_create_func core_related_table_schema_creators [] = {
  ObInnerTableSchema::all_core_table_schema,
  ObInnerTableSchema::all_table_schema,
  ObInnerTableSchema::all_column_schema,
  ObInnerTableSchema::all_ddl_operation_schema,
  ObInnerTableSchema::all_table_history_schema,
  ObInnerTableSchema::all_column_history_schema,
  NULL,};

const schema_create_func sys_table_schema_creators [] = {
  ObInnerTableSchema::all_part_schema,
  ObInnerTableSchema::all_part_history_schema,
  ObInnerTableSchema::all_sub_part_schema,
  ObInnerTableSchema::all_sub_part_history_schema,
  ObInnerTableSchema::all_part_info_schema,
  ObInnerTableSchema::all_part_info_history_schema,
  ObInnerTableSchema::all_def_sub_part_schema,
  ObInnerTableSchema::all_def_sub_part_history_schema,
  ObInnerTableSchema::all_sys_variable_history_schema,
  ObInnerTableSchema::all_foreign_key_schema,
  ObInnerTableSchema::all_foreign_key_history_schema,
  ObInnerTableSchema::all_constraint_schema,
  ObInnerTableSchema::all_constraint_history_schema,
  ObInnerTableSchema::all_trigger_schema,
  ObInnerTableSchema::all_trigger_history_schema,
  ObInnerTableSchema::all_table_stat_schema,
  ObInnerTableSchema::all_column_stat_schema,
  ObInnerTableSchema::all_histogram_stat_schema,
  ObInnerTableSchema::all_column_stat_history_schema,
  ObInnerTableSchema::all_histogram_stat_history_schema,
  ObInnerTableSchema::all_aux_stat_schema,
  ObInnerTableSchema::all_user_schema,
  ObInnerTableSchema::all_user_history_schema,
  ObInnerTableSchema::all_database_schema,
  ObInnerTableSchema::all_database_history_schema,
  ObInnerTableSchema::all_table_privilege_schema,
  ObInnerTableSchema::all_table_privilege_history_schema,
  ObInnerTableSchema::all_database_privilege_schema,
  ObInnerTableSchema::all_database_privilege_history_schema,
  ObInnerTableSchema::all_sys_variable_schema,
  ObInnerTableSchema::all_sys_stat_schema,
  ObInnerTableSchema::all_outline_schema,
  ObInnerTableSchema::all_outline_history_schema,
  ObInnerTableSchema::all_recyclebin_schema,
  ObInnerTableSchema::all_foreign_key_column_schema,
  ObInnerTableSchema::all_foreign_key_column_history_schema,
  ObInnerTableSchema::all_auto_increment_schema,
  ObInnerTableSchema::all_ddl_checksum_schema,
  ObInnerTableSchema::all_routine_schema,
  ObInnerTableSchema::all_routine_history_schema,
  ObInnerTableSchema::all_routine_param_schema,
  ObInnerTableSchema::all_routine_param_history_schema,
  ObInnerTableSchema::all_package_schema,
  ObInnerTableSchema::all_package_history_schema,
  ObInnerTableSchema::all_acquired_snapshot_schema,
  ObInnerTableSchema::all_ori_schema_version_schema,
  ObInnerTableSchema::all_role_grantee_map_schema,
  ObInnerTableSchema::all_role_grantee_map_history_schema,
  ObInnerTableSchema::all_sysauth_schema,
  ObInnerTableSchema::all_sysauth_history_schema,
  ObInnerTableSchema::all_objauth_schema,
  ObInnerTableSchema::all_objauth_history_schema,
  ObInnerTableSchema::all_error_schema,
  ObInnerTableSchema::all_time_zone_name_schema,
  ObInnerTableSchema::all_time_zone_transition_schema,
  ObInnerTableSchema::all_time_zone_transition_type_schema,
  ObInnerTableSchema::all_constraint_column_schema,
  ObInnerTableSchema::all_constraint_column_history_schema,
  ObInnerTableSchema::all_dependency_schema,
  ObInnerTableSchema::all_ddl_error_message_schema,
  ObInnerTableSchema::all_ddl_task_status_schema,
  ObInnerTableSchema::all_column_usage_schema,
  ObInnerTableSchema::all_job_schema,
  ObInnerTableSchema::all_monitor_modified_schema,
  ObInnerTableSchema::all_table_stat_history_schema,
  ObInnerTableSchema::all_optstat_global_prefs_schema,
  ObInnerTableSchema::all_optstat_user_prefs_schema,
  ObInnerTableSchema::all_tablet_to_table_schema,
  ObInnerTableSchema::all_tablet_to_table_history_schema,
  ObInnerTableSchema::all_tablet_checksum_schema,
  ObInnerTableSchema::all_scheduler_job_schema,
  ObInnerTableSchema::all_scheduler_program_schema,
  ObInnerTableSchema::all_scheduler_program_argument_schema,
  ObInnerTableSchema::all_freeze_info_schema,
  ObInnerTableSchema::all_mock_fk_parent_table_schema,
  ObInnerTableSchema::all_mock_fk_parent_table_history_schema,
  ObInnerTableSchema::all_mock_fk_parent_table_column_schema,
  ObInnerTableSchema::all_mock_fk_parent_table_column_history_schema,
  ObInnerTableSchema::all_spatial_reference_systems_schema,
  ObInnerTableSchema::all_dbms_lock_allocated_schema,
  ObInnerTableSchema::all_scheduler_job_class_schema,
  ObInnerTableSchema::all_routine_privilege_schema,
  ObInnerTableSchema::all_routine_privilege_history_schema,
  ObInnerTableSchema::all_column_privilege_schema,
  ObInnerTableSchema::all_column_privilege_history_schema,
  ObInnerTableSchema::all_detect_lock_info_v2_schema,
  ObInnerTableSchema::ft_dict_ik_utf8_schema,
  ObInnerTableSchema::ft_stopword_ik_utf8_schema,
  ObInnerTableSchema::ft_quantifier_ik_utf8_schema,
  ObInnerTableSchema::all_vector_index_task_schema,
  ObInnerTableSchema::all_vector_index_task_history_schema,
  ObInnerTableSchema::all_ai_model_schema,
  ObInnerTableSchema::all_ai_model_history_schema,
  ObInnerTableSchema::all_ai_model_endpoint_schema,
  ObInnerTableSchema::all_ai_column_schema,
  ObInnerTableSchema::all_ai_column_task_schema,
  ObInnerTableSchema::all_objauth_mysql_schema,
  ObInnerTableSchema::all_objauth_mysql_history_schema,
  NULL,};

const schema_create_func virtual_table_schema_creators [] = {
  ObInnerTableSchema::all_virtual_all_table_schema,
  ObInnerTableSchema::all_virtual_table_column_schema,
  ObInnerTableSchema::all_virtual_table_index_schema,
  ObInnerTableSchema::all_virtual_show_create_database_schema,
  ObInnerTableSchema::all_virtual_show_create_table_schema,
  ObInnerTableSchema::all_virtual_session_variable_schema,
  ObInnerTableSchema::all_virtual_privilege_grant_schema,
  ObInnerTableSchema::all_virtual_processlist_schema,
  ObInnerTableSchema::all_virtual_warning_schema,
  ObInnerTableSchema::all_virtual_database_status_schema,
  ObInnerTableSchema::all_virtual_global_variable_schema,
  ObInnerTableSchema::all_virtual_show_tables_schema,
  ObInnerTableSchema::all_virtual_show_create_procedure_schema,
  ObInnerTableSchema::all_virtual_plan_cache_stat_schema,
  ObInnerTableSchema::all_virtual_plan_stat_schema,
  ObInnerTableSchema::all_virtual_kvcache_info_schema,
  ObInnerTableSchema::all_virtual_data_type_class_schema,
  ObInnerTableSchema::all_virtual_data_type_schema,
  ObInnerTableSchema::all_virtual_memstore_info_schema,
  ObInnerTableSchema::all_virtual_concurrency_object_pool_schema,
  ObInnerTableSchema::all_virtual_disk_stat_schema,
  ObInnerTableSchema::all_virtual_tablet_memstore_info_schema,
  ObInnerTableSchema::all_virtual_trans_stat_schema,
  ObInnerTableSchema::all_virtual_trans_ctx_mgr_stat_schema,
  ObInnerTableSchema::all_virtual_trans_scheduler_schema,
  ObInnerTableSchema::all_virtual_core_all_table_schema,
  ObInnerTableSchema::all_virtual_core_column_table_schema,
  ObInnerTableSchema::all_virtual_memory_info_schema,
  ObInnerTableSchema::all_virtual_sys_parameter_stat_schema,
  ObInnerTableSchema::all_virtual_sys_parameter_schema,
  ObInnerTableSchema::all_virtual_engine_schema,
  ObInnerTableSchema::all_virtual_plan_cache_plan_explain_schema,
  ObInnerTableSchema::all_virtual_outline_schema,
  ObInnerTableSchema::all_virtual_tablet_sstable_macro_info_schema,
  ObInnerTableSchema::all_virtual_sys_task_status_schema,
  ObInnerTableSchema::all_virtual_macro_block_marker_status_schema,
  ObInnerTableSchema::all_virtual_io_stat_schema,
  ObInnerTableSchema::all_virtual_long_ops_status_schema,
  ObInnerTableSchema::all_virtual_server_object_pool_schema,
  ObInnerTableSchema::all_virtual_trans_lock_stat_schema,
  ObInnerTableSchema::all_virtual_parameter_stat_schema,
  ObInnerTableSchema::all_virtual_server_schema_info_schema,
  ObInnerTableSchema::all_virtual_memory_context_stat_schema,
  ObInnerTableSchema::all_virtual_dump_info_schema,
  ObInnerTableSchema::all_virtual_dag_warning_history_schema,
  ObInnerTableSchema::all_virtual_dag_schema,
  ObInnerTableSchema::all_virtual_dag_scheduler_schema,
  ObInnerTableSchema::all_virtual_server_compaction_progress_schema,
  ObInnerTableSchema::all_virtual_tablet_compaction_progress_schema,
  ObInnerTableSchema::all_virtual_compaction_diagnose_info_schema,
  ObInnerTableSchema::all_virtual_compaction_suggestion_schema,
  ObInnerTableSchema::all_virtual_session_info_schema,
  ObInnerTableSchema::all_virtual_tablet_compaction_history_schema,
  ObInnerTableSchema::all_virtual_io_calibration_status_schema,
  ObInnerTableSchema::all_virtual_io_benchmark_schema,
  ObInnerTableSchema::all_virtual_io_quota_schema,
  ObInnerTableSchema::all_virtual_server_compaction_event_history_schema,
  ObInnerTableSchema::all_virtual_tablet_stat_schema,
  ObInnerTableSchema::all_virtual_ddl_sim_point_schema,
  ObInnerTableSchema::all_virtual_ddl_sim_point_stat_schema,
  ObInnerTableSchema::session_variables_schema,
  ObInnerTableSchema::global_status_schema,
  ObInnerTableSchema::session_status_schema,
  ObInnerTableSchema::user_schema,
  ObInnerTableSchema::db_schema,
  ObInnerTableSchema::all_virtual_lock_wait_stat_schema,
  ObInnerTableSchema::all_virtual_collation_schema,
  ObInnerTableSchema::all_virtual_charset_schema,
  ObInnerTableSchema::all_virtual_memstore_allocator_info_schema,
  ObInnerTableSchema::all_virtual_table_mgr_schema,
  ObInnerTableSchema::all_virtual_bad_block_table_schema,
  ObInnerTableSchema::all_virtual_px_worker_stat_schema,
  ObInnerTableSchema::all_virtual_tablet_store_stat_schema,
  ObInnerTableSchema::all_virtual_raid_stat_schema,
  ObInnerTableSchema::all_virtual_dtl_channel_schema,
  ObInnerTableSchema::all_virtual_dtl_memory_schema,
  ObInnerTableSchema::all_virtual_information_columns_schema,
  ObInnerTableSchema::all_virtual_ps_stat_schema,
  ObInnerTableSchema::all_virtual_ps_item_info_schema,
  ObInnerTableSchema::all_virtual_sql_workarea_history_stat_schema,
  ObInnerTableSchema::all_virtual_sql_workarea_active_schema,
  ObInnerTableSchema::all_virtual_sql_workarea_histogram_schema,
  ObInnerTableSchema::all_virtual_sql_workarea_memory_info_schema,
  ObInnerTableSchema::all_virtual_id_service_schema,
  ObInnerTableSchema::all_virtual_open_cursor_schema,
  ObInnerTableSchema::all_virtual_files_schema,
  ObInnerTableSchema::all_virtual_deadlock_event_history_schema,
  ObInnerTableSchema::all_virtual_ctx_memory_info_schema,
  ObInnerTableSchema::all_virtual_show_create_trigger_schema,
  ObInnerTableSchema::all_virtual_px_target_monitor_schema,
  ObInnerTableSchema::all_virtual_tablet_meta_table_schema,
  ObInnerTableSchema::all_virtual_load_data_stat_schema,
  ObInnerTableSchema::all_virtual_log_stat_schema,
  ObInnerTableSchema::all_virtual_tablet_local_checksum_schema,
  ObInnerTableSchema::all_virtual_server_stat_schema,
  ObInnerTableSchema::all_virtual_dtl_interm_result_monitor_schema,
  ObInnerTableSchema::all_virtual_apply_stat_schema,
  ObInnerTableSchema::all_virtual_replay_stat_schema,
  ObInnerTableSchema::all_virtual_ls_info_schema,
  ObInnerTableSchema::all_virtual_tablet_info_schema,
  ObInnerTableSchema::all_virtual_obj_lock_schema,
  ObInnerTableSchema::all_virtual_merge_info_schema,
  ObInnerTableSchema::all_virtual_tx_data_table_schema,
  ObInnerTableSchema::all_virtual_transaction_freeze_checkpoint_schema,
  ObInnerTableSchema::all_virtual_transaction_checkpoint_schema,
  ObInnerTableSchema::all_virtual_checkpoint_schema,
  ObInnerTableSchema::all_virtual_dml_stats_schema,
  ObInnerTableSchema::all_virtual_tablet_ddl_kv_info_schema,
  ObInnerTableSchema::all_virtual_privilege_schema,
  ObInnerTableSchema::all_virtual_tablet_pointer_status_schema,
  ObInnerTableSchema::all_virtual_storage_meta_memory_status_schema,
  ObInnerTableSchema::all_virtual_kvcache_store_memblock_schema,
  ObInnerTableSchema::all_virtual_column_checksum_error_info_schema,
  ObInnerTableSchema::all_virtual_tablet_compaction_info_schema,
  ObInnerTableSchema::all_virtual_schema_memory_schema,
  ObInnerTableSchema::all_virtual_schema_slot_schema,
  ObInnerTableSchema::all_virtual_minor_freeze_info_schema,
  ObInnerTableSchema::all_virtual_show_trace_schema,
  ObInnerTableSchema::all_virtual_sql_plan_schema,
  ObInnerTableSchema::all_virtual_malloc_sample_info_schema,
  ObInnerTableSchema::all_virtual_mds_node_stat_schema,
  ObInnerTableSchema::all_virtual_mds_event_history_schema,
  ObInnerTableSchema::all_virtual_tx_data_schema,
  ObInnerTableSchema::all_virtual_opt_stat_gather_monitor_schema,
  ObInnerTableSchema::all_virtual_timestamp_service_schema,
  ObInnerTableSchema::all_virtual_px_p2p_datahub_schema,
  ObInnerTableSchema::all_virtual_tablet_buffer_info_schema,
  ObInnerTableSchema::all_virtual_data_activity_metrics_schema,
  ObInnerTableSchema::all_virtual_scheduler_running_job_schema,
  ObInnerTableSchema::all_virtual_sqlstat_schema,
  ObInnerTableSchema::all_virtual_sys_variable_default_value_schema,
  ObInnerTableSchema::enabled_roles_schema,
  ObInnerTableSchema::all_virtual_session_ps_info_schema,
  ObInnerTableSchema::all_virtual_tracepoint_info_schema,
  ObInnerTableSchema::all_virtual_resource_limit_schema,
  ObInnerTableSchema::all_virtual_resource_limit_detail_schema,
  ObInnerTableSchema::all_virtual_group_io_stat_schema,
  ObInnerTableSchema::all_virtual_nic_info_schema,
  ObInnerTableSchema::all_virtual_vector_index_info_schema,
  ObInnerTableSchema::all_virtual_temp_file_schema,
  ObInnerTableSchema::all_virtual_vector_mem_info_schema,
  ObInnerTableSchema::all_virtual_rootservice_job_schema,
  ObInnerTableSchema::all_virtual_change_stream_refresh_stat_schema,
  NULL,};

const schema_create_func sys_view_schema_creators [] = {
  ObInnerTableSchema::schemata_schema,
  ObInnerTableSchema::character_sets_schema,
  ObInnerTableSchema::global_variables_schema,
  ObInnerTableSchema::statistics_schema,
  ObInnerTableSchema::views_schema,
  ObInnerTableSchema::tables_schema,
  ObInnerTableSchema::collations_schema,
  ObInnerTableSchema::collation_character_set_applicability_schema,
  ObInnerTableSchema::processlist_schema,
  ObInnerTableSchema::key_column_usage_schema,
  ObInnerTableSchema::engines_schema,
  ObInnerTableSchema::routines_schema,
  ObInnerTableSchema::profiling_schema,
  ObInnerTableSchema::optimizer_trace_schema,
  ObInnerTableSchema::innodb_sys_columns_schema,
  ObInnerTableSchema::innodb_ft_being_deleted_schema,
  ObInnerTableSchema::innodb_ft_config_schema,
  ObInnerTableSchema::innodb_ft_deleted_schema,
  ObInnerTableSchema::innodb_ft_index_cache_schema,
  ObInnerTableSchema::v_ob_memory_schema,
  ObInnerTableSchema::v_ob_plan_cache_plan_stat_schema,
  ObInnerTableSchema::dba_recyclebin_schema,
  ObInnerTableSchema::time_zone_name_schema,
  ObInnerTableSchema::time_zone_transition_schema,
  ObInnerTableSchema::time_zone_transition_type_schema,
  ObInnerTableSchema::v_session_longops_schema,
  ObInnerTableSchema::columns_schema,
  ObInnerTableSchema::v_sql_workarea_schema,
  ObInnerTableSchema::v_sql_workarea_active_schema,
  ObInnerTableSchema::v_sql_workarea_histogram_schema,
  ObInnerTableSchema::v_ob_sstables_schema,
  ObInnerTableSchema::v_ob_merge_info_schema,
  ObInnerTableSchema::v_ob_px_target_monitor_schema,
  ObInnerTableSchema::column_privileges_schema,
  ObInnerTableSchema::view_table_usage_schema,
  ObInnerTableSchema::files_schema,
  ObInnerTableSchema::dba_ob_databases_schema,
  ObInnerTableSchema::dba_ob_major_compaction_schema,
  ObInnerTableSchema::dba_objects_schema,
  ObInnerTableSchema::dba_part_tables_schema,
  ObInnerTableSchema::dba_part_key_columns_schema,
  ObInnerTableSchema::dba_subpart_key_columns_schema,
  ObInnerTableSchema::dba_tab_partitions_schema,
  ObInnerTableSchema::dba_tab_subpartitions_schema,
  ObInnerTableSchema::dba_subpartition_templates_schema,
  ObInnerTableSchema::dba_part_indexes_schema,
  ObInnerTableSchema::dba_ind_partitions_schema,
  ObInnerTableSchema::dba_ind_subpartitions_schema,
  ObInnerTableSchema::v_ob_server_stat_schema,
  ObInnerTableSchema::v_ob_parameters_schema,
  ObInnerTableSchema::v_ob_processlist_schema,
  ObInnerTableSchema::v_ob_transaction_write_state_schema,
  ObInnerTableSchema::v_ob_tablet_compaction_history_schema,
  ObInnerTableSchema::v_ob_compaction_diagnose_info_schema,
  ObInnerTableSchema::dba_tab_statistics_schema,
  ObInnerTableSchema::dba_tab_col_statistics_schema,
  ObInnerTableSchema::dba_part_col_statistics_schema,
  ObInnerTableSchema::dba_subpart_col_statistics_schema,
  ObInnerTableSchema::dba_tab_histograms_schema,
  ObInnerTableSchema::dba_part_histograms_schema,
  ObInnerTableSchema::dba_subpart_histograms_schema,
  ObInnerTableSchema::dba_tab_stats_history_schema,
  ObInnerTableSchema::dba_ind_statistics_schema,
  ObInnerTableSchema::v_dml_stats_schema,
  ObInnerTableSchema::dba_tab_modifications_schema,
  ObInnerTableSchema::dba_scheduler_jobs_schema,
  ObInnerTableSchema::dba_ob_outlines_schema,
  ObInnerTableSchema::dba_ob_deadlock_event_history_schema,
  ObInnerTableSchema::v_ob_log_stat_schema,
  ObInnerTableSchema::st_geometry_columns_schema,
  ObInnerTableSchema::st_spatial_reference_systems_schema,
  ObInnerTableSchema::dba_ob_freeze_info_schema,
  ObInnerTableSchema::dba_ob_auto_increment_schema,
  ObInnerTableSchema::dba_scheduler_windows_schema,
  ObInnerTableSchema::dba_ob_users_schema,
  ObInnerTableSchema::dba_ob_database_privilege_schema,
  ObInnerTableSchema::parameters_schema,
  ObInnerTableSchema::table_privileges_schema,
  ObInnerTableSchema::user_privileges_schema,
  ObInnerTableSchema::schema_privileges_schema,
  ObInnerTableSchema::check_constraints_schema,
  ObInnerTableSchema::referential_constraints_schema,
  ObInnerTableSchema::table_constraints_schema,
  ObInnerTableSchema::v_ob_transaction_schedulers_schema,
  ObInnerTableSchema::triggers_schema,
  ObInnerTableSchema::partitions_schema,
  ObInnerTableSchema::v_ob_opt_stat_gather_monitor_schema,
  ObInnerTableSchema::v_ob_locks_schema,
  ObInnerTableSchema::v_ob_timestamp_service_schema,
  ObInnerTableSchema::v_ob_px_p2p_datahub_schema,
  ObInnerTableSchema::dba_ob_table_stat_stale_info_schema,
  ObInnerTableSchema::v_ob_session_schema,
  ObInnerTableSchema::v_ob_pl_cache_object_schema,
  ObInnerTableSchema::dba_ob_format_outlines_schema,
  ObInnerTableSchema::procs_priv_schema,
  ObInnerTableSchema::dba_ob_aux_statistics_schema,
  ObInnerTableSchema::dba_ob_sys_variables_schema,
  ObInnerTableSchema::role_edges_schema,
  ObInnerTableSchema::default_roles_schema,
  ObInnerTableSchema::columns_priv_schema,
  ObInnerTableSchema::innodb_lock_waits_schema,
  ObInnerTableSchema::innodb_locks_schema,
  ObInnerTableSchema::innodb_trx_schema,
  ObInnerTableSchema::ndb_transid_mysql_connection_map_schema,
  ObInnerTableSchema::v_ob_group_io_stat_schema,
  ObInnerTableSchema::tablespaces_schema,
  ObInnerTableSchema::innodb_buffer_page_schema,
  ObInnerTableSchema::innodb_buffer_page_lru_schema,
  ObInnerTableSchema::innodb_buffer_pool_stats_schema,
  ObInnerTableSchema::innodb_cmp_schema,
  ObInnerTableSchema::innodb_cmp_per_index_schema,
  ObInnerTableSchema::innodb_cmp_per_index_reset_schema,
  ObInnerTableSchema::innodb_cmp_reset_schema,
  ObInnerTableSchema::innodb_cmpmem_schema,
  ObInnerTableSchema::innodb_cmpmem_reset_schema,
  ObInnerTableSchema::innodb_sys_datafiles_schema,
  ObInnerTableSchema::innodb_sys_indexes_schema,
  ObInnerTableSchema::innodb_sys_tables_schema,
  ObInnerTableSchema::innodb_sys_tablespaces_schema,
  ObInnerTableSchema::innodb_sys_tablestats_schema,
  ObInnerTableSchema::innodb_sys_virtual_schema,
  ObInnerTableSchema::innodb_temp_table_info_schema,
  ObInnerTableSchema::innodb_metrics_schema,
  ObInnerTableSchema::role_table_grants_schema,
  ObInnerTableSchema::role_column_grants_schema,
  ObInnerTableSchema::role_routine_grants_schema,
  ObInnerTableSchema::dba_ob_table_space_usage_schema,
  ObInnerTableSchema::innodb_sys_fields_schema,
  ObInnerTableSchema::innodb_sys_foreign_schema,
  ObInnerTableSchema::innodb_sys_foreign_cols_schema,
  ObInnerTableSchema::dba_ob_temp_files_schema,
  ObInnerTableSchema::proc_schema,
  ObInnerTableSchema::dba_ob_vector_index_tasks_schema,
  ObInnerTableSchema::dba_ob_vector_index_task_history_schema,
  ObInnerTableSchema::v_ob_vector_memory_schema,
  ObInnerTableSchema::dba_ob_ai_models_schema,
  ObInnerTableSchema::dba_ob_ai_model_endpoints_schema,
  ObInnerTableSchema::dba_ob_rootservice_jobs_schema,
  ObInnerTableSchema::dba_ob_change_stream_refresh_stat_schema,
  NULL,};

const schema_create_func core_index_table_schema_creators [] = {
  ObInnerTableSchema::all_table_idx_data_table_id_schema,
  ObInnerTableSchema::all_table_idx_db_tb_name_schema,
  ObInnerTableSchema::all_table_idx_tb_name_schema,
  ObInnerTableSchema::all_column_idx_tb_column_name_schema,
  ObInnerTableSchema::all_column_idx_column_name_schema,
  ObInnerTableSchema::all_ddl_operation_idx_ddl_type_schema,
  ObInnerTableSchema::all_table_history_idx_data_table_id_schema,
  NULL,};

const schema_create_func sys_index_table_schema_creators [] = {
  ObInnerTableSchema::all_ddl_task_status_idx_task_key_schema,
  ObInnerTableSchema::all_user_idx_ur_name_schema,
  ObInnerTableSchema::all_database_idx_db_name_schema,
  ObInnerTableSchema::all_recyclebin_idx_recyclebin_db_type_schema,
  ObInnerTableSchema::all_part_idx_part_name_schema,
  ObInnerTableSchema::all_sub_part_idx_sub_part_name_schema,
  ObInnerTableSchema::all_def_sub_part_idx_def_sub_part_name_schema,
  ObInnerTableSchema::all_foreign_key_idx_fk_child_tid_schema,
  ObInnerTableSchema::all_foreign_key_idx_fk_parent_tid_schema,
  ObInnerTableSchema::all_foreign_key_idx_fk_name_schema,
  ObInnerTableSchema::all_foreign_key_history_idx_fk_his_child_tid_schema,
  ObInnerTableSchema::all_foreign_key_history_idx_fk_his_parent_tid_schema,
  ObInnerTableSchema::all_ddl_checksum_idx_ddl_checksum_task_schema,
  ObInnerTableSchema::all_routine_idx_db_routine_name_schema,
  ObInnerTableSchema::all_routine_idx_routine_name_schema,
  ObInnerTableSchema::all_routine_idx_routine_pkg_id_schema,
  ObInnerTableSchema::all_routine_param_idx_routine_param_name_schema,
  ObInnerTableSchema::all_package_idx_db_pkg_name_schema,
  ObInnerTableSchema::all_package_idx_pkg_name_schema,
  ObInnerTableSchema::all_acquired_snapshot_idx_snapshot_tablet_schema,
  ObInnerTableSchema::all_constraint_idx_cst_name_schema,
  ObInnerTableSchema::all_role_grantee_map_idx_grantee_role_id_schema,
  ObInnerTableSchema::all_role_grantee_map_history_idx_grantee_his_role_id_schema,
  ObInnerTableSchema::all_trigger_idx_trigger_base_obj_id_schema,
  ObInnerTableSchema::all_trigger_idx_db_trigger_name_schema,
  ObInnerTableSchema::all_trigger_idx_trigger_name_schema,
  ObInnerTableSchema::all_trigger_history_idx_trigger_his_base_obj_id_schema,
  ObInnerTableSchema::all_objauth_idx_objauth_grantor_schema,
  ObInnerTableSchema::all_objauth_idx_objauth_grantee_schema,
  ObInnerTableSchema::all_dependency_idx_dependency_ref_obj_schema,
  ObInnerTableSchema::all_ddl_error_message_idx_ddl_error_object_schema,
  ObInnerTableSchema::all_table_stat_history_idx_table_stat_his_savtime_schema,
  ObInnerTableSchema::all_column_stat_history_idx_column_stat_his_savtime_schema,
  ObInnerTableSchema::all_histogram_stat_history_idx_histogram_stat_his_savtime_schema,
  ObInnerTableSchema::all_tablet_to_table_idx_tablet_to_table_id_schema,
  ObInnerTableSchema::all_job_idx_job_powner_schema,
  ObInnerTableSchema::all_recyclebin_idx_recyclebin_ori_name_schema,
  ObInnerTableSchema::all_table_privilege_idx_tb_priv_db_name_schema,
  ObInnerTableSchema::all_table_privilege_idx_tb_priv_tb_name_schema,
  ObInnerTableSchema::all_database_privilege_idx_db_priv_db_name_schema,
  ObInnerTableSchema::all_dbms_lock_allocated_idx_dbms_lock_allocated_lockhandle_schema,
  ObInnerTableSchema::all_dbms_lock_allocated_idx_dbms_lock_allocated_expiration_schema,
  ObInnerTableSchema::all_column_privilege_idx_column_privilege_name_schema,
  ObInnerTableSchema::all_ai_model_endpoint_idx_endpoint_name_schema,
  ObInnerTableSchema::all_ai_model_endpoint_idx_ai_model_name_schema,
  ObInnerTableSchema::all_objauth_mysql_idx_objauth_mysql_user_id_schema,
  ObInnerTableSchema::all_objauth_mysql_idx_objauth_mysql_obj_name_schema,
  NULL,};

const schema_create_func information_schema_table_schema_creators[] = {
  NULL,};

const schema_create_func mysql_table_schema_creators[] = {
  NULL,};

const uint64_t runtime_space_tables [] = {
  OB_ALL_VIRTUAL_CORE_ALL_TABLE_TID,
  OB_ALL_VIRTUAL_CORE_COLUMN_TABLE_TID,  };

const char* const runtime_space_table_names [] = {
  OB_ALL_VIRTUAL_CORE_ALL_TABLE_TNAME,
  OB_ALL_VIRTUAL_CORE_COLUMN_TABLE_TNAME,  };

const uint64_t cluster_distributed_vtables [] = {  };

const uint64_t restrict_access_virtual_tables[] = {
    };


static inline bool is_restrict_access_virtual_table(const uint64_t tid)
{
  bool found = false;
  for (int64_t i = 0; i < ARRAYSIZEOF(restrict_access_virtual_tables) && !found; i++) {
    if (tid == restrict_access_virtual_tables[i]) {
      found = true;
    }
  }
  return found;
}

static inline bool is_runtime_table(const uint64_t tid)
{
  bool in_runtime_space = false;
  for (int64_t i = 0; i < ARRAYSIZEOF(runtime_space_tables); ++i) {
    if (tid == runtime_space_tables[i]) {
      in_runtime_space = true;
      break;
    }
  }
  return in_runtime_space;
}

static inline bool is_runtime_table_name(const common::ObString &tname)
{
  bool in_runtime_space = false;
  for (int64_t i = 0; i < ARRAYSIZEOF(runtime_space_table_names); ++i) {
    if (0 == tname.case_compare(runtime_space_table_names[i])) {
      in_runtime_space = true;
      break;
    }
  }
  return in_runtime_space;
}

static inline bool is_system_virtual_table(const uint64_t tid)
{
  return common::is_virtual_table(tid) && !is_runtime_table(tid);
}

static inline bool is_runtime_virtual_table(const uint64_t tid)
{
  return common::is_virtual_table(tid) && is_runtime_table(tid);
}

static inline bool is_cluster_distributed_vtables(const uint64_t tid)
{
  bool bret = false;
  for (int64_t i = 0; !bret && i < ARRAYSIZEOF(cluster_distributed_vtables); ++i) {
    if (tid == cluster_distributed_vtables[i]) {
      bret = true;
    }
  }
  return bret;
}

/* lob aux table mapping for sys table */
struct LOBMapping
{
  uint64_t data_table_tid_;
  uint64_t lob_meta_tid_;
  uint64_t lob_piece_tid_;
  schema_create_func lob_meta_func_;
  schema_create_func lob_piece_func_;
};

LOBMapping const lob_aux_table_mappings [] = {
  {
    OB_ALL_TABLE_TID,
    OB_ALL_TABLE_AUX_LOB_META_TID,
    OB_ALL_TABLE_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_table_aux_lob_meta_schema,
    ObInnerTableSchema::all_table_aux_lob_piece_schema
  },

  {
    OB_ALL_COLUMN_TID,
    OB_ALL_COLUMN_AUX_LOB_META_TID,
    OB_ALL_COLUMN_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_column_aux_lob_meta_schema,
    ObInnerTableSchema::all_column_aux_lob_piece_schema
  },

  {
    OB_ALL_DDL_OPERATION_TID,
    OB_ALL_DDL_OPERATION_AUX_LOB_META_TID,
    OB_ALL_DDL_OPERATION_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_ddl_operation_aux_lob_meta_schema,
    ObInnerTableSchema::all_ddl_operation_aux_lob_piece_schema
  },

  {
    OB_ALL_TABLE_HISTORY_TID,
    OB_ALL_TABLE_HISTORY_AUX_LOB_META_TID,
    OB_ALL_TABLE_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_table_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_table_history_aux_lob_piece_schema
  },

  {
    OB_ALL_COLUMN_HISTORY_TID,
    OB_ALL_COLUMN_HISTORY_AUX_LOB_META_TID,
    OB_ALL_COLUMN_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_column_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_column_history_aux_lob_piece_schema
  },

  {
    OB_ALL_PART_TID,
    OB_ALL_PART_AUX_LOB_META_TID,
    OB_ALL_PART_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_part_aux_lob_meta_schema,
    ObInnerTableSchema::all_part_aux_lob_piece_schema
  },

  {
    OB_ALL_PART_HISTORY_TID,
    OB_ALL_PART_HISTORY_AUX_LOB_META_TID,
    OB_ALL_PART_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_part_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_part_history_aux_lob_piece_schema
  },

  {
    OB_ALL_SUB_PART_TID,
    OB_ALL_SUB_PART_AUX_LOB_META_TID,
    OB_ALL_SUB_PART_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_sub_part_aux_lob_meta_schema,
    ObInnerTableSchema::all_sub_part_aux_lob_piece_schema
  },

  {
    OB_ALL_SUB_PART_HISTORY_TID,
    OB_ALL_SUB_PART_HISTORY_AUX_LOB_META_TID,
    OB_ALL_SUB_PART_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_sub_part_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_sub_part_history_aux_lob_piece_schema
  },

  {
    OB_ALL_PART_INFO_TID,
    OB_ALL_PART_INFO_AUX_LOB_META_TID,
    OB_ALL_PART_INFO_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_part_info_aux_lob_meta_schema,
    ObInnerTableSchema::all_part_info_aux_lob_piece_schema
  },

  {
    OB_ALL_PART_INFO_HISTORY_TID,
    OB_ALL_PART_INFO_HISTORY_AUX_LOB_META_TID,
    OB_ALL_PART_INFO_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_part_info_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_part_info_history_aux_lob_piece_schema
  },

  {
    OB_ALL_DEF_SUB_PART_TID,
    OB_ALL_DEF_SUB_PART_AUX_LOB_META_TID,
    OB_ALL_DEF_SUB_PART_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_def_sub_part_aux_lob_meta_schema,
    ObInnerTableSchema::all_def_sub_part_aux_lob_piece_schema
  },

  {
    OB_ALL_DEF_SUB_PART_HISTORY_TID,
    OB_ALL_DEF_SUB_PART_HISTORY_AUX_LOB_META_TID,
    OB_ALL_DEF_SUB_PART_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_def_sub_part_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_def_sub_part_history_aux_lob_piece_schema
  },

  {
    OB_ALL_SYS_VARIABLE_HISTORY_TID,
    OB_ALL_SYS_VARIABLE_HISTORY_AUX_LOB_META_TID,
    OB_ALL_SYS_VARIABLE_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_sys_variable_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_sys_variable_history_aux_lob_piece_schema
  },

  {
    OB_ALL_FOREIGN_KEY_TID,
    OB_ALL_FOREIGN_KEY_AUX_LOB_META_TID,
    OB_ALL_FOREIGN_KEY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_foreign_key_aux_lob_meta_schema,
    ObInnerTableSchema::all_foreign_key_aux_lob_piece_schema
  },

  {
    OB_ALL_FOREIGN_KEY_HISTORY_TID,
    OB_ALL_FOREIGN_KEY_HISTORY_AUX_LOB_META_TID,
    OB_ALL_FOREIGN_KEY_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_foreign_key_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_foreign_key_history_aux_lob_piece_schema
  },

  {
    OB_ALL_CONSTRAINT_TID,
    OB_ALL_CONSTRAINT_AUX_LOB_META_TID,
    OB_ALL_CONSTRAINT_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_constraint_aux_lob_meta_schema,
    ObInnerTableSchema::all_constraint_aux_lob_piece_schema
  },

  {
    OB_ALL_CONSTRAINT_HISTORY_TID,
    OB_ALL_CONSTRAINT_HISTORY_AUX_LOB_META_TID,
    OB_ALL_CONSTRAINT_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_constraint_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_constraint_history_aux_lob_piece_schema
  },

  {
    OB_ALL_TRIGGER_TID,
    OB_ALL_TRIGGER_AUX_LOB_META_TID,
    OB_ALL_TRIGGER_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_trigger_aux_lob_meta_schema,
    ObInnerTableSchema::all_trigger_aux_lob_piece_schema
  },

  {
    OB_ALL_TRIGGER_HISTORY_TID,
    OB_ALL_TRIGGER_HISTORY_AUX_LOB_META_TID,
    OB_ALL_TRIGGER_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_trigger_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_trigger_history_aux_lob_piece_schema
  },

  {
    OB_ALL_TABLE_STAT_TID,
    OB_ALL_TABLE_STAT_AUX_LOB_META_TID,
    OB_ALL_TABLE_STAT_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_table_stat_aux_lob_meta_schema,
    ObInnerTableSchema::all_table_stat_aux_lob_piece_schema
  },

  {
    OB_ALL_COLUMN_STAT_TID,
    OB_ALL_COLUMN_STAT_AUX_LOB_META_TID,
    OB_ALL_COLUMN_STAT_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_column_stat_aux_lob_meta_schema,
    ObInnerTableSchema::all_column_stat_aux_lob_piece_schema
  },

  {
    OB_ALL_HISTOGRAM_STAT_TID,
    OB_ALL_HISTOGRAM_STAT_AUX_LOB_META_TID,
    OB_ALL_HISTOGRAM_STAT_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_histogram_stat_aux_lob_meta_schema,
    ObInnerTableSchema::all_histogram_stat_aux_lob_piece_schema
  },

  {
    OB_ALL_COLUMN_STAT_HISTORY_TID,
    OB_ALL_COLUMN_STAT_HISTORY_AUX_LOB_META_TID,
    OB_ALL_COLUMN_STAT_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_column_stat_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_column_stat_history_aux_lob_piece_schema
  },

  {
    OB_ALL_HISTOGRAM_STAT_HISTORY_TID,
    OB_ALL_HISTOGRAM_STAT_HISTORY_AUX_LOB_META_TID,
    OB_ALL_HISTOGRAM_STAT_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_histogram_stat_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_histogram_stat_history_aux_lob_piece_schema
  },

  {
    OB_ALL_AUX_STAT_TID,
    OB_ALL_AUX_STAT_AUX_LOB_META_TID,
    OB_ALL_AUX_STAT_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_aux_stat_aux_lob_meta_schema,
    ObInnerTableSchema::all_aux_stat_aux_lob_piece_schema
  },

  {
    OB_ALL_USER_TID,
    OB_ALL_USER_AUX_LOB_META_TID,
    OB_ALL_USER_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_user_aux_lob_meta_schema,
    ObInnerTableSchema::all_user_aux_lob_piece_schema
  },

  {
    OB_ALL_USER_HISTORY_TID,
    OB_ALL_USER_HISTORY_AUX_LOB_META_TID,
    OB_ALL_USER_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_user_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_user_history_aux_lob_piece_schema
  },

  {
    OB_ALL_DATABASE_TID,
    OB_ALL_DATABASE_AUX_LOB_META_TID,
    OB_ALL_DATABASE_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_database_aux_lob_meta_schema,
    ObInnerTableSchema::all_database_aux_lob_piece_schema
  },

  {
    OB_ALL_DATABASE_HISTORY_TID,
    OB_ALL_DATABASE_HISTORY_AUX_LOB_META_TID,
    OB_ALL_DATABASE_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_database_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_database_history_aux_lob_piece_schema
  },

  {
    OB_ALL_TABLE_PRIVILEGE_TID,
    OB_ALL_TABLE_PRIVILEGE_AUX_LOB_META_TID,
    OB_ALL_TABLE_PRIVILEGE_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_table_privilege_aux_lob_meta_schema,
    ObInnerTableSchema::all_table_privilege_aux_lob_piece_schema
  },

  {
    OB_ALL_TABLE_PRIVILEGE_HISTORY_TID,
    OB_ALL_TABLE_PRIVILEGE_HISTORY_AUX_LOB_META_TID,
    OB_ALL_TABLE_PRIVILEGE_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_table_privilege_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_table_privilege_history_aux_lob_piece_schema
  },

  {
    OB_ALL_DATABASE_PRIVILEGE_TID,
    OB_ALL_DATABASE_PRIVILEGE_AUX_LOB_META_TID,
    OB_ALL_DATABASE_PRIVILEGE_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_database_privilege_aux_lob_meta_schema,
    ObInnerTableSchema::all_database_privilege_aux_lob_piece_schema
  },

  {
    OB_ALL_DATABASE_PRIVILEGE_HISTORY_TID,
    OB_ALL_DATABASE_PRIVILEGE_HISTORY_AUX_LOB_META_TID,
    OB_ALL_DATABASE_PRIVILEGE_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_database_privilege_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_database_privilege_history_aux_lob_piece_schema
  },

  {
    OB_ALL_SYS_VARIABLE_TID,
    OB_ALL_SYS_VARIABLE_AUX_LOB_META_TID,
    OB_ALL_SYS_VARIABLE_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_sys_variable_aux_lob_meta_schema,
    ObInnerTableSchema::all_sys_variable_aux_lob_piece_schema
  },

  {
    OB_ALL_SYS_STAT_TID,
    OB_ALL_SYS_STAT_AUX_LOB_META_TID,
    OB_ALL_SYS_STAT_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_sys_stat_aux_lob_meta_schema,
    ObInnerTableSchema::all_sys_stat_aux_lob_piece_schema
  },

  {
    OB_ALL_OUTLINE_TID,
    OB_ALL_OUTLINE_AUX_LOB_META_TID,
    OB_ALL_OUTLINE_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_outline_aux_lob_meta_schema,
    ObInnerTableSchema::all_outline_aux_lob_piece_schema
  },

  {
    OB_ALL_OUTLINE_HISTORY_TID,
    OB_ALL_OUTLINE_HISTORY_AUX_LOB_META_TID,
    OB_ALL_OUTLINE_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_outline_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_outline_history_aux_lob_piece_schema
  },

  {
    OB_ALL_RECYCLEBIN_TID,
    OB_ALL_RECYCLEBIN_AUX_LOB_META_TID,
    OB_ALL_RECYCLEBIN_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_recyclebin_aux_lob_meta_schema,
    ObInnerTableSchema::all_recyclebin_aux_lob_piece_schema
  },

  {
    OB_ALL_FOREIGN_KEY_COLUMN_TID,
    OB_ALL_FOREIGN_KEY_COLUMN_AUX_LOB_META_TID,
    OB_ALL_FOREIGN_KEY_COLUMN_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_foreign_key_column_aux_lob_meta_schema,
    ObInnerTableSchema::all_foreign_key_column_aux_lob_piece_schema
  },

  {
    OB_ALL_FOREIGN_KEY_COLUMN_HISTORY_TID,
    OB_ALL_FOREIGN_KEY_COLUMN_HISTORY_AUX_LOB_META_TID,
    OB_ALL_FOREIGN_KEY_COLUMN_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_foreign_key_column_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_foreign_key_column_history_aux_lob_piece_schema
  },

  {
    OB_ALL_AUTO_INCREMENT_TID,
    OB_ALL_AUTO_INCREMENT_AUX_LOB_META_TID,
    OB_ALL_AUTO_INCREMENT_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_auto_increment_aux_lob_meta_schema,
    ObInnerTableSchema::all_auto_increment_aux_lob_piece_schema
  },

  {
    OB_ALL_DDL_CHECKSUM_TID,
    OB_ALL_DDL_CHECKSUM_AUX_LOB_META_TID,
    OB_ALL_DDL_CHECKSUM_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_ddl_checksum_aux_lob_meta_schema,
    ObInnerTableSchema::all_ddl_checksum_aux_lob_piece_schema
  },

  {
    OB_ALL_ROUTINE_TID,
    OB_ALL_ROUTINE_AUX_LOB_META_TID,
    OB_ALL_ROUTINE_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_routine_aux_lob_meta_schema,
    ObInnerTableSchema::all_routine_aux_lob_piece_schema
  },

  {
    OB_ALL_ROUTINE_HISTORY_TID,
    OB_ALL_ROUTINE_HISTORY_AUX_LOB_META_TID,
    OB_ALL_ROUTINE_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_routine_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_routine_history_aux_lob_piece_schema
  },

  {
    OB_ALL_ROUTINE_PARAM_TID,
    OB_ALL_ROUTINE_PARAM_AUX_LOB_META_TID,
    OB_ALL_ROUTINE_PARAM_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_routine_param_aux_lob_meta_schema,
    ObInnerTableSchema::all_routine_param_aux_lob_piece_schema
  },

  {
    OB_ALL_ROUTINE_PARAM_HISTORY_TID,
    OB_ALL_ROUTINE_PARAM_HISTORY_AUX_LOB_META_TID,
    OB_ALL_ROUTINE_PARAM_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_routine_param_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_routine_param_history_aux_lob_piece_schema
  },

  {
    OB_ALL_PACKAGE_TID,
    OB_ALL_PACKAGE_AUX_LOB_META_TID,
    OB_ALL_PACKAGE_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_package_aux_lob_meta_schema,
    ObInnerTableSchema::all_package_aux_lob_piece_schema
  },

  {
    OB_ALL_PACKAGE_HISTORY_TID,
    OB_ALL_PACKAGE_HISTORY_AUX_LOB_META_TID,
    OB_ALL_PACKAGE_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_package_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_package_history_aux_lob_piece_schema
  },

  {
    OB_ALL_ACQUIRED_SNAPSHOT_TID,
    OB_ALL_ACQUIRED_SNAPSHOT_AUX_LOB_META_TID,
    OB_ALL_ACQUIRED_SNAPSHOT_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_acquired_snapshot_aux_lob_meta_schema,
    ObInnerTableSchema::all_acquired_snapshot_aux_lob_piece_schema
  },

  {
    OB_ALL_ORI_SCHEMA_VERSION_TID,
    OB_ALL_ORI_SCHEMA_VERSION_AUX_LOB_META_TID,
    OB_ALL_ORI_SCHEMA_VERSION_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_ori_schema_version_aux_lob_meta_schema,
    ObInnerTableSchema::all_ori_schema_version_aux_lob_piece_schema
  },

  {
    OB_ALL_ROLE_GRANTEE_MAP_TID,
    OB_ALL_ROLE_GRANTEE_MAP_AUX_LOB_META_TID,
    OB_ALL_ROLE_GRANTEE_MAP_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_role_grantee_map_aux_lob_meta_schema,
    ObInnerTableSchema::all_role_grantee_map_aux_lob_piece_schema
  },

  {
    OB_ALL_ROLE_GRANTEE_MAP_HISTORY_TID,
    OB_ALL_ROLE_GRANTEE_MAP_HISTORY_AUX_LOB_META_TID,
    OB_ALL_ROLE_GRANTEE_MAP_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_role_grantee_map_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_role_grantee_map_history_aux_lob_piece_schema
  },

  {
    OB_ALL_SYSAUTH_TID,
    OB_ALL_SYSAUTH_AUX_LOB_META_TID,
    OB_ALL_SYSAUTH_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_sysauth_aux_lob_meta_schema,
    ObInnerTableSchema::all_sysauth_aux_lob_piece_schema
  },

  {
    OB_ALL_SYSAUTH_HISTORY_TID,
    OB_ALL_SYSAUTH_HISTORY_AUX_LOB_META_TID,
    OB_ALL_SYSAUTH_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_sysauth_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_sysauth_history_aux_lob_piece_schema
  },

  {
    OB_ALL_OBJAUTH_TID,
    OB_ALL_OBJAUTH_AUX_LOB_META_TID,
    OB_ALL_OBJAUTH_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_objauth_aux_lob_meta_schema,
    ObInnerTableSchema::all_objauth_aux_lob_piece_schema
  },

  {
    OB_ALL_OBJAUTH_HISTORY_TID,
    OB_ALL_OBJAUTH_HISTORY_AUX_LOB_META_TID,
    OB_ALL_OBJAUTH_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_objauth_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_objauth_history_aux_lob_piece_schema
  },

  {
    OB_ALL_ERROR_TID,
    OB_ALL_ERROR_AUX_LOB_META_TID,
    OB_ALL_ERROR_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_error_aux_lob_meta_schema,
    ObInnerTableSchema::all_error_aux_lob_piece_schema
  },

  {
    OB_ALL_TIME_ZONE_NAME_TID,
    OB_ALL_TIME_ZONE_NAME_AUX_LOB_META_TID,
    OB_ALL_TIME_ZONE_NAME_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_time_zone_name_aux_lob_meta_schema,
    ObInnerTableSchema::all_time_zone_name_aux_lob_piece_schema
  },

  {
    OB_ALL_TIME_ZONE_TRANSITION_TID,
    OB_ALL_TIME_ZONE_TRANSITION_AUX_LOB_META_TID,
    OB_ALL_TIME_ZONE_TRANSITION_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_time_zone_transition_aux_lob_meta_schema,
    ObInnerTableSchema::all_time_zone_transition_aux_lob_piece_schema
  },

  {
    OB_ALL_TIME_ZONE_TRANSITION_TYPE_TID,
    OB_ALL_TIME_ZONE_TRANSITION_TYPE_AUX_LOB_META_TID,
    OB_ALL_TIME_ZONE_TRANSITION_TYPE_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_time_zone_transition_type_aux_lob_meta_schema,
    ObInnerTableSchema::all_time_zone_transition_type_aux_lob_piece_schema
  },

  {
    OB_ALL_CONSTRAINT_COLUMN_TID,
    OB_ALL_CONSTRAINT_COLUMN_AUX_LOB_META_TID,
    OB_ALL_CONSTRAINT_COLUMN_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_constraint_column_aux_lob_meta_schema,
    ObInnerTableSchema::all_constraint_column_aux_lob_piece_schema
  },

  {
    OB_ALL_CONSTRAINT_COLUMN_HISTORY_TID,
    OB_ALL_CONSTRAINT_COLUMN_HISTORY_AUX_LOB_META_TID,
    OB_ALL_CONSTRAINT_COLUMN_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_constraint_column_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_constraint_column_history_aux_lob_piece_schema
  },

  {
    OB_ALL_DEPENDENCY_TID,
    OB_ALL_DEPENDENCY_AUX_LOB_META_TID,
    OB_ALL_DEPENDENCY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_dependency_aux_lob_meta_schema,
    ObInnerTableSchema::all_dependency_aux_lob_piece_schema
  },

  {
    OB_ALL_DDL_ERROR_MESSAGE_TID,
    OB_ALL_DDL_ERROR_MESSAGE_AUX_LOB_META_TID,
    OB_ALL_DDL_ERROR_MESSAGE_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_ddl_error_message_aux_lob_meta_schema,
    ObInnerTableSchema::all_ddl_error_message_aux_lob_piece_schema
  },

  {
    OB_ALL_DDL_TASK_STATUS_TID,
    OB_ALL_DDL_TASK_STATUS_AUX_LOB_META_TID,
    OB_ALL_DDL_TASK_STATUS_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_ddl_task_status_aux_lob_meta_schema,
    ObInnerTableSchema::all_ddl_task_status_aux_lob_piece_schema
  },

  {
    OB_ALL_COLUMN_USAGE_TID,
    OB_ALL_COLUMN_USAGE_AUX_LOB_META_TID,
    OB_ALL_COLUMN_USAGE_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_column_usage_aux_lob_meta_schema,
    ObInnerTableSchema::all_column_usage_aux_lob_piece_schema
  },

  {
    OB_ALL_JOB_TID,
    OB_ALL_JOB_AUX_LOB_META_TID,
    OB_ALL_JOB_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_job_aux_lob_meta_schema,
    ObInnerTableSchema::all_job_aux_lob_piece_schema
  },

  {
    OB_ALL_MONITOR_MODIFIED_TID,
    OB_ALL_MONITOR_MODIFIED_AUX_LOB_META_TID,
    OB_ALL_MONITOR_MODIFIED_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_monitor_modified_aux_lob_meta_schema,
    ObInnerTableSchema::all_monitor_modified_aux_lob_piece_schema
  },

  {
    OB_ALL_TABLE_STAT_HISTORY_TID,
    OB_ALL_TABLE_STAT_HISTORY_AUX_LOB_META_TID,
    OB_ALL_TABLE_STAT_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_table_stat_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_table_stat_history_aux_lob_piece_schema
  },

  {
    OB_ALL_OPTSTAT_GLOBAL_PREFS_TID,
    OB_ALL_OPTSTAT_GLOBAL_PREFS_AUX_LOB_META_TID,
    OB_ALL_OPTSTAT_GLOBAL_PREFS_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_optstat_global_prefs_aux_lob_meta_schema,
    ObInnerTableSchema::all_optstat_global_prefs_aux_lob_piece_schema
  },

  {
    OB_ALL_OPTSTAT_USER_PREFS_TID,
    OB_ALL_OPTSTAT_USER_PREFS_AUX_LOB_META_TID,
    OB_ALL_OPTSTAT_USER_PREFS_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_optstat_user_prefs_aux_lob_meta_schema,
    ObInnerTableSchema::all_optstat_user_prefs_aux_lob_piece_schema
  },

  {
    OB_ALL_TABLET_TO_TABLE_TID,
    OB_ALL_TABLET_TO_TABLE_AUX_LOB_META_TID,
    OB_ALL_TABLET_TO_TABLE_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_tablet_to_table_aux_lob_meta_schema,
    ObInnerTableSchema::all_tablet_to_table_aux_lob_piece_schema
  },

  {
    OB_ALL_TABLET_TO_TABLE_HISTORY_TID,
    OB_ALL_TABLET_TO_TABLE_HISTORY_AUX_LOB_META_TID,
    OB_ALL_TABLET_TO_TABLE_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_tablet_to_table_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_tablet_to_table_history_aux_lob_piece_schema
  },

  {
    OB_ALL_TABLET_CHECKSUM_TID,
    OB_ALL_TABLET_CHECKSUM_AUX_LOB_META_TID,
    OB_ALL_TABLET_CHECKSUM_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_tablet_checksum_aux_lob_meta_schema,
    ObInnerTableSchema::all_tablet_checksum_aux_lob_piece_schema
  },

  {
    OB_ALL_SCHEDULER_JOB_TID,
    OB_ALL_SCHEDULER_JOB_AUX_LOB_META_TID,
    OB_ALL_SCHEDULER_JOB_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_scheduler_job_aux_lob_meta_schema,
    ObInnerTableSchema::all_scheduler_job_aux_lob_piece_schema
  },

  {
    OB_ALL_SCHEDULER_PROGRAM_TID,
    OB_ALL_SCHEDULER_PROGRAM_AUX_LOB_META_TID,
    OB_ALL_SCHEDULER_PROGRAM_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_scheduler_program_aux_lob_meta_schema,
    ObInnerTableSchema::all_scheduler_program_aux_lob_piece_schema
  },

  {
    OB_ALL_SCHEDULER_PROGRAM_ARGUMENT_TID,
    OB_ALL_SCHEDULER_PROGRAM_ARGUMENT_AUX_LOB_META_TID,
    OB_ALL_SCHEDULER_PROGRAM_ARGUMENT_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_scheduler_program_argument_aux_lob_meta_schema,
    ObInnerTableSchema::all_scheduler_program_argument_aux_lob_piece_schema
  },

  {
    OB_ALL_FREEZE_INFO_TID,
    OB_ALL_FREEZE_INFO_AUX_LOB_META_TID,
    OB_ALL_FREEZE_INFO_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_freeze_info_aux_lob_meta_schema,
    ObInnerTableSchema::all_freeze_info_aux_lob_piece_schema
  },

  {
    OB_ALL_MOCK_FK_PARENT_TABLE_TID,
    OB_ALL_MOCK_FK_PARENT_TABLE_AUX_LOB_META_TID,
    OB_ALL_MOCK_FK_PARENT_TABLE_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_mock_fk_parent_table_aux_lob_meta_schema,
    ObInnerTableSchema::all_mock_fk_parent_table_aux_lob_piece_schema
  },

  {
    OB_ALL_MOCK_FK_PARENT_TABLE_HISTORY_TID,
    OB_ALL_MOCK_FK_PARENT_TABLE_HISTORY_AUX_LOB_META_TID,
    OB_ALL_MOCK_FK_PARENT_TABLE_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_mock_fk_parent_table_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_mock_fk_parent_table_history_aux_lob_piece_schema
  },

  {
    OB_ALL_MOCK_FK_PARENT_TABLE_COLUMN_TID,
    OB_ALL_MOCK_FK_PARENT_TABLE_COLUMN_AUX_LOB_META_TID,
    OB_ALL_MOCK_FK_PARENT_TABLE_COLUMN_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_mock_fk_parent_table_column_aux_lob_meta_schema,
    ObInnerTableSchema::all_mock_fk_parent_table_column_aux_lob_piece_schema
  },

  {
    OB_ALL_MOCK_FK_PARENT_TABLE_COLUMN_HISTORY_TID,
    OB_ALL_MOCK_FK_PARENT_TABLE_COLUMN_HISTORY_AUX_LOB_META_TID,
    OB_ALL_MOCK_FK_PARENT_TABLE_COLUMN_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_mock_fk_parent_table_column_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_mock_fk_parent_table_column_history_aux_lob_piece_schema
  },

  {
    OB_ALL_SPATIAL_REFERENCE_SYSTEMS_TID,
    OB_ALL_SPATIAL_REFERENCE_SYSTEMS_AUX_LOB_META_TID,
    OB_ALL_SPATIAL_REFERENCE_SYSTEMS_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_spatial_reference_systems_aux_lob_meta_schema,
    ObInnerTableSchema::all_spatial_reference_systems_aux_lob_piece_schema
  },

  {
    OB_ALL_DBMS_LOCK_ALLOCATED_TID,
    OB_ALL_DBMS_LOCK_ALLOCATED_AUX_LOB_META_TID,
    OB_ALL_DBMS_LOCK_ALLOCATED_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_dbms_lock_allocated_aux_lob_meta_schema,
    ObInnerTableSchema::all_dbms_lock_allocated_aux_lob_piece_schema
  },

  {
    OB_ALL_SCHEDULER_JOB_CLASS_TID,
    OB_ALL_SCHEDULER_JOB_CLASS_AUX_LOB_META_TID,
    OB_ALL_SCHEDULER_JOB_CLASS_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_scheduler_job_class_aux_lob_meta_schema,
    ObInnerTableSchema::all_scheduler_job_class_aux_lob_piece_schema
  },

  {
    OB_ALL_ROUTINE_PRIVILEGE_TID,
    OB_ALL_ROUTINE_PRIVILEGE_AUX_LOB_META_TID,
    OB_ALL_ROUTINE_PRIVILEGE_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_routine_privilege_aux_lob_meta_schema,
    ObInnerTableSchema::all_routine_privilege_aux_lob_piece_schema
  },

  {
    OB_ALL_ROUTINE_PRIVILEGE_HISTORY_TID,
    OB_ALL_ROUTINE_PRIVILEGE_HISTORY_AUX_LOB_META_TID,
    OB_ALL_ROUTINE_PRIVILEGE_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_routine_privilege_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_routine_privilege_history_aux_lob_piece_schema
  },

  {
    OB_ALL_COLUMN_PRIVILEGE_TID,
    OB_ALL_COLUMN_PRIVILEGE_AUX_LOB_META_TID,
    OB_ALL_COLUMN_PRIVILEGE_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_column_privilege_aux_lob_meta_schema,
    ObInnerTableSchema::all_column_privilege_aux_lob_piece_schema
  },

  {
    OB_ALL_COLUMN_PRIVILEGE_HISTORY_TID,
    OB_ALL_COLUMN_PRIVILEGE_HISTORY_AUX_LOB_META_TID,
    OB_ALL_COLUMN_PRIVILEGE_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_column_privilege_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_column_privilege_history_aux_lob_piece_schema
  },

  {
    OB_ALL_DETECT_LOCK_INFO_V2_TID,
    OB_ALL_DETECT_LOCK_INFO_V2_AUX_LOB_META_TID,
    OB_ALL_DETECT_LOCK_INFO_V2_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_detect_lock_info_v2_aux_lob_meta_schema,
    ObInnerTableSchema::all_detect_lock_info_v2_aux_lob_piece_schema
  },

  {
    OB_FT_DICT_IK_UTF8_TID,
    OB_FT_DICT_IK_UTF8_AUX_LOB_META_TID,
    OB_FT_DICT_IK_UTF8_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::ft_dict_ik_utf8_aux_lob_meta_schema,
    ObInnerTableSchema::ft_dict_ik_utf8_aux_lob_piece_schema
  },

  {
    OB_FT_STOPWORD_IK_UTF8_TID,
    OB_FT_STOPWORD_IK_UTF8_AUX_LOB_META_TID,
    OB_FT_STOPWORD_IK_UTF8_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::ft_stopword_ik_utf8_aux_lob_meta_schema,
    ObInnerTableSchema::ft_stopword_ik_utf8_aux_lob_piece_schema
  },

  {
    OB_FT_QUANTIFIER_IK_UTF8_TID,
    OB_FT_QUANTIFIER_IK_UTF8_AUX_LOB_META_TID,
    OB_FT_QUANTIFIER_IK_UTF8_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::ft_quantifier_ik_utf8_aux_lob_meta_schema,
    ObInnerTableSchema::ft_quantifier_ik_utf8_aux_lob_piece_schema
  },

  {
    OB_ALL_VECTOR_INDEX_TASK_TID,
    OB_ALL_VECTOR_INDEX_TASK_AUX_LOB_META_TID,
    OB_ALL_VECTOR_INDEX_TASK_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_vector_index_task_aux_lob_meta_schema,
    ObInnerTableSchema::all_vector_index_task_aux_lob_piece_schema
  },

  {
    OB_ALL_VECTOR_INDEX_TASK_HISTORY_TID,
    OB_ALL_VECTOR_INDEX_TASK_HISTORY_AUX_LOB_META_TID,
    OB_ALL_VECTOR_INDEX_TASK_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_vector_index_task_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_vector_index_task_history_aux_lob_piece_schema
  },

  {
    OB_ALL_AI_MODEL_TID,
    OB_ALL_AI_MODEL_AUX_LOB_META_TID,
    OB_ALL_AI_MODEL_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_ai_model_aux_lob_meta_schema,
    ObInnerTableSchema::all_ai_model_aux_lob_piece_schema
  },

  {
    OB_ALL_AI_MODEL_HISTORY_TID,
    OB_ALL_AI_MODEL_HISTORY_AUX_LOB_META_TID,
    OB_ALL_AI_MODEL_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_ai_model_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_ai_model_history_aux_lob_piece_schema
  },

  {
    OB_ALL_AI_MODEL_ENDPOINT_TID,
    OB_ALL_AI_MODEL_ENDPOINT_AUX_LOB_META_TID,
    OB_ALL_AI_MODEL_ENDPOINT_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_ai_model_endpoint_aux_lob_meta_schema,
    ObInnerTableSchema::all_ai_model_endpoint_aux_lob_piece_schema
  },

  {
    OB_ALL_AI_COLUMN_TID,
    OB_ALL_AI_COLUMN_AUX_LOB_META_TID,
    OB_ALL_AI_COLUMN_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_ai_column_aux_lob_meta_schema,
    ObInnerTableSchema::all_ai_column_aux_lob_piece_schema
  },

  {
    OB_ALL_AI_COLUMN_TASK_TID,
    OB_ALL_AI_COLUMN_TASK_AUX_LOB_META_TID,
    OB_ALL_AI_COLUMN_TASK_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_ai_column_task_aux_lob_meta_schema,
    ObInnerTableSchema::all_ai_column_task_aux_lob_piece_schema
  },

  {
    OB_ALL_OBJAUTH_MYSQL_TID,
    OB_ALL_OBJAUTH_MYSQL_AUX_LOB_META_TID,
    OB_ALL_OBJAUTH_MYSQL_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_objauth_mysql_aux_lob_meta_schema,
    ObInnerTableSchema::all_objauth_mysql_aux_lob_piece_schema
  },

  {
    OB_ALL_OBJAUTH_MYSQL_HISTORY_TID,
    OB_ALL_OBJAUTH_MYSQL_HISTORY_AUX_LOB_META_TID,
    OB_ALL_OBJAUTH_MYSQL_HISTORY_AUX_LOB_PIECE_TID,
    ObInnerTableSchema::all_objauth_mysql_history_aux_lob_meta_schema,
    ObInnerTableSchema::all_objauth_mysql_history_aux_lob_piece_schema
  },

};

static inline bool get_sys_table_lob_aux_table_id(const uint64_t tid, uint64_t& meta_tid, uint64_t& piece_tid)
{
  bool bret = false;
  meta_tid = OB_INVALID_ID;
  piece_tid = OB_INVALID_ID;
  if (OB_ALL_CORE_TABLE_TID == tid) {
    // __all_core_table do not need lob aux table, return false
  } else if (is_system_table(tid)) {
    bret = true;
    meta_tid = tid + OB_MIN_SYS_LOB_META_TABLE_ID;
    piece_tid = tid + OB_MIN_SYS_LOB_PIECE_TABLE_ID;
  }
  return bret;
}

typedef common::hash::ObHashMap<uint64_t, LOBMapping> inner_lob_map_t;
extern inner_lob_map_t inner_lob_map;
extern bool inited_lob;
static inline int get_sys_table_lob_aux_schema(const uint64_t tid,
                                               share::schema::ObTableSchema& meta_schema,
                                               share::schema::ObTableSchema& piece_schema)
{
  int ret = OB_SUCCESS;
  LOBMapping item;
  if (OB_FAIL(inner_lob_map.get_refactored(tid, item))) {
    SERVER_LOG(WARN, "fail to get lob mapping item", K(ret), K(tid), K(inited_lob));
  } else if (OB_FAIL(item.lob_meta_func_(meta_schema))) {
    SERVER_LOG(WARN, "fail to build lob meta schema", K(ret), K(tid));
  } else if (OB_FAIL(item.lob_piece_func_(piece_schema))) {
    SERVER_LOG(WARN, "fail to build lob piece schema", K(ret), K(tid));
  }
  return ret;
}

const int64_t OB_CORE_TABLE_COUNT = 6;
const int64_t OB_SYS_TABLE_COUNT = 98;
const int64_t OB_VIRTUAL_TABLE_COUNT = 143;
const int64_t OB_SYS_VIEW_COUNT = 139;
const int64_t OB_RUNTIME_TABLE_COUNT = 387;
const int64_t OB_CORE_SCHEMA_VERSION = 1;
const int64_t OB_BOOTSTRAP_SCHEMA_VERSION = 390;

} // end namespace share
} // end namespace oceanbase
#endif /* _OB_INNER_TABLE_SCHEMA_H_ */
