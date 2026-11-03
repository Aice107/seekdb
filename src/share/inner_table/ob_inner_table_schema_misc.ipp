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


#ifdef CLUSTER_PRIVATE_TABLE_SWITCH


#endif


#ifdef SYS_INDEX_TABLE_ID_SWITCH

case OB_ALL_TABLE_IDX_DATA_TABLE_ID_TID:
case OB_ALL_TABLE_IDX_DB_TB_NAME_TID:
case OB_ALL_TABLE_IDX_TB_NAME_TID:
case OB_ALL_COLUMN_IDX_TB_COLUMN_NAME_TID:
case OB_ALL_COLUMN_IDX_COLUMN_NAME_TID:
case OB_ALL_DDL_OPERATION_IDX_DDL_TYPE_TID:
case OB_ALL_TABLE_HISTORY_IDX_DATA_TABLE_ID_TID:
case OB_ALL_DDL_TASK_STATUS_IDX_TASK_KEY_TID:
case OB_ALL_USER_IDX_UR_NAME_TID:
case OB_ALL_DATABASE_IDX_DB_NAME_TID:
case OB_ALL_RECYCLEBIN_IDX_RECYCLEBIN_DB_TYPE_TID:
case OB_ALL_PART_IDX_PART_NAME_TID:
case OB_ALL_SUB_PART_IDX_SUB_PART_NAME_TID:
case OB_ALL_DEF_SUB_PART_IDX_DEF_SUB_PART_NAME_TID:
case OB_ALL_FOREIGN_KEY_IDX_FK_CHILD_TID_TID:
case OB_ALL_FOREIGN_KEY_IDX_FK_PARENT_TID_TID:
case OB_ALL_FOREIGN_KEY_IDX_FK_NAME_TID:
case OB_ALL_FOREIGN_KEY_HISTORY_IDX_FK_HIS_CHILD_TID_TID:
case OB_ALL_FOREIGN_KEY_HISTORY_IDX_FK_HIS_PARENT_TID_TID:
case OB_ALL_DDL_CHECKSUM_IDX_DDL_CHECKSUM_TASK_TID:
case OB_ALL_ROUTINE_IDX_DB_ROUTINE_NAME_TID:
case OB_ALL_ROUTINE_IDX_ROUTINE_NAME_TID:
case OB_ALL_ROUTINE_IDX_ROUTINE_PKG_ID_TID:
case OB_ALL_ROUTINE_PARAM_IDX_ROUTINE_PARAM_NAME_TID:
case OB_ALL_PACKAGE_IDX_DB_PKG_NAME_TID:
case OB_ALL_PACKAGE_IDX_PKG_NAME_TID:
case OB_ALL_ACQUIRED_SNAPSHOT_IDX_SNAPSHOT_TABLET_TID:
case OB_ALL_CONSTRAINT_IDX_CST_NAME_TID:
case OB_ALL_ROLE_GRANTEE_MAP_IDX_GRANTEE_ROLE_ID_TID:
case OB_ALL_ROLE_GRANTEE_MAP_HISTORY_IDX_GRANTEE_HIS_ROLE_ID_TID:
case OB_ALL_TRIGGER_IDX_TRIGGER_BASE_OBJ_ID_TID:
case OB_ALL_TRIGGER_IDX_DB_TRIGGER_NAME_TID:
case OB_ALL_TRIGGER_IDX_TRIGGER_NAME_TID:
case OB_ALL_TRIGGER_HISTORY_IDX_TRIGGER_HIS_BASE_OBJ_ID_TID:
case OB_ALL_OBJAUTH_IDX_OBJAUTH_GRANTOR_TID:
case OB_ALL_OBJAUTH_IDX_OBJAUTH_GRANTEE_TID:
case OB_ALL_DEPENDENCY_IDX_DEPENDENCY_REF_OBJ_TID:
case OB_ALL_DDL_ERROR_MESSAGE_IDX_DDL_ERROR_OBJECT_TID:
case OB_ALL_TABLE_STAT_HISTORY_IDX_TABLE_STAT_HIS_SAVTIME_TID:
case OB_ALL_COLUMN_STAT_HISTORY_IDX_COLUMN_STAT_HIS_SAVTIME_TID:
case OB_ALL_HISTOGRAM_STAT_HISTORY_IDX_HISTOGRAM_STAT_HIS_SAVTIME_TID:
case OB_ALL_TABLET_TO_TABLE_IDX_TABLET_TO_TABLE_ID_TID:
case OB_ALL_JOB_IDX_JOB_POWNER_TID:
case OB_ALL_RECYCLEBIN_IDX_RECYCLEBIN_ORI_NAME_TID:
case OB_ALL_TABLE_PRIVILEGE_IDX_TB_PRIV_DB_NAME_TID:
case OB_ALL_TABLE_PRIVILEGE_IDX_TB_PRIV_TB_NAME_TID:
case OB_ALL_DATABASE_PRIVILEGE_IDX_DB_PRIV_DB_NAME_TID:
case OB_ALL_DBMS_LOCK_ALLOCATED_IDX_DBMS_LOCK_ALLOCATED_LOCKHANDLE_TID:
case OB_ALL_DBMS_LOCK_ALLOCATED_IDX_DBMS_LOCK_ALLOCATED_EXPIRATION_TID:
case OB_ALL_COLUMN_PRIVILEGE_IDX_COLUMN_PRIVILEGE_NAME_TID:
case OB_ALL_AI_MODEL_ENDPOINT_IDX_ENDPOINT_NAME_TID:
case OB_ALL_AI_MODEL_ENDPOINT_IDX_AI_MODEL_NAME_TID:
case OB_ALL_OBJAUTH_MYSQL_IDX_OBJAUTH_MYSQL_USER_ID_TID:
case OB_ALL_OBJAUTH_MYSQL_IDX_OBJAUTH_MYSQL_OBJ_NAME_TID:

#endif


#ifdef SYS_INDEX_DATA_TABLE_ID_SWITCH

case OB_ALL_TABLE_TID:
case OB_ALL_COLUMN_TID:
case OB_ALL_DDL_OPERATION_TID:
case OB_ALL_TABLE_HISTORY_TID:
case OB_ALL_DDL_TASK_STATUS_TID:
case OB_ALL_USER_TID:
case OB_ALL_DATABASE_TID:
case OB_ALL_RECYCLEBIN_TID:
case OB_ALL_PART_TID:
case OB_ALL_SUB_PART_TID:
case OB_ALL_DEF_SUB_PART_TID:
case OB_ALL_FOREIGN_KEY_TID:
case OB_ALL_FOREIGN_KEY_HISTORY_TID:
case OB_ALL_DDL_CHECKSUM_TID:
case OB_ALL_ROUTINE_TID:
case OB_ALL_ROUTINE_PARAM_TID:
case OB_ALL_PACKAGE_TID:
case OB_ALL_ACQUIRED_SNAPSHOT_TID:
case OB_ALL_CONSTRAINT_TID:
case OB_ALL_ROLE_GRANTEE_MAP_TID:
case OB_ALL_ROLE_GRANTEE_MAP_HISTORY_TID:
case OB_ALL_TRIGGER_TID:
case OB_ALL_TRIGGER_HISTORY_TID:
case OB_ALL_OBJAUTH_TID:
case OB_ALL_DEPENDENCY_TID:
case OB_ALL_DDL_ERROR_MESSAGE_TID:
case OB_ALL_TABLE_STAT_HISTORY_TID:
case OB_ALL_COLUMN_STAT_HISTORY_TID:
case OB_ALL_HISTOGRAM_STAT_HISTORY_TID:
case OB_ALL_TABLET_TO_TABLE_TID:
case OB_ALL_JOB_TID:
case OB_ALL_TABLE_PRIVILEGE_TID:
case OB_ALL_DATABASE_PRIVILEGE_TID:
case OB_ALL_DBMS_LOCK_ALLOCATED_TID:
case OB_ALL_COLUMN_PRIVILEGE_TID:
case OB_ALL_AI_MODEL_ENDPOINT_TID:
case OB_ALL_OBJAUTH_MYSQL_TID:

#endif


#ifdef SYS_INDEX_DATA_TABLE_ID_TO_INDEX_IDS_SWITCH

case OB_ALL_TABLE_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_TABLE_IDX_DATA_TABLE_ID_TID))) {
  }
  if (FAILEDx(index_tids.push_back(OB_ALL_TABLE_IDX_DB_TB_NAME_TID))) {
  }
  if (FAILEDx(index_tids.push_back(OB_ALL_TABLE_IDX_TB_NAME_TID))) {
  }
  break;
}
case OB_ALL_COLUMN_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_COLUMN_IDX_TB_COLUMN_NAME_TID))) {
  }
  if (FAILEDx(index_tids.push_back(OB_ALL_COLUMN_IDX_COLUMN_NAME_TID))) {
  }
  break;
}
case OB_ALL_DDL_OPERATION_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_DDL_OPERATION_IDX_DDL_TYPE_TID))) {
  }
  break;
}
case OB_ALL_TABLE_HISTORY_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_TABLE_HISTORY_IDX_DATA_TABLE_ID_TID))) {
  }
  break;
}
case OB_ALL_DDL_TASK_STATUS_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_DDL_TASK_STATUS_IDX_TASK_KEY_TID))) {
  }
  break;
}
case OB_ALL_USER_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_USER_IDX_UR_NAME_TID))) {
  }
  break;
}
case OB_ALL_DATABASE_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_DATABASE_IDX_DB_NAME_TID))) {
  }
  break;
}
case OB_ALL_RECYCLEBIN_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_RECYCLEBIN_IDX_RECYCLEBIN_DB_TYPE_TID))) {
  }
  if (FAILEDx(index_tids.push_back(OB_ALL_RECYCLEBIN_IDX_RECYCLEBIN_ORI_NAME_TID))) {
  }
  break;
}
case OB_ALL_PART_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_PART_IDX_PART_NAME_TID))) {
  }
  break;
}
case OB_ALL_SUB_PART_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_SUB_PART_IDX_SUB_PART_NAME_TID))) {
  }
  break;
}
case OB_ALL_DEF_SUB_PART_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_DEF_SUB_PART_IDX_DEF_SUB_PART_NAME_TID))) {
  }
  break;
}
case OB_ALL_FOREIGN_KEY_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_FOREIGN_KEY_IDX_FK_CHILD_TID_TID))) {
  }
  if (FAILEDx(index_tids.push_back(OB_ALL_FOREIGN_KEY_IDX_FK_PARENT_TID_TID))) {
  }
  if (FAILEDx(index_tids.push_back(OB_ALL_FOREIGN_KEY_IDX_FK_NAME_TID))) {
  }
  break;
}
case OB_ALL_FOREIGN_KEY_HISTORY_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_FOREIGN_KEY_HISTORY_IDX_FK_HIS_CHILD_TID_TID))) {
  }
  if (FAILEDx(index_tids.push_back(OB_ALL_FOREIGN_KEY_HISTORY_IDX_FK_HIS_PARENT_TID_TID))) {
  }
  break;
}
case OB_ALL_DDL_CHECKSUM_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_DDL_CHECKSUM_IDX_DDL_CHECKSUM_TASK_TID))) {
  }
  break;
}
case OB_ALL_ROUTINE_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_ROUTINE_IDX_DB_ROUTINE_NAME_TID))) {
  }
  if (FAILEDx(index_tids.push_back(OB_ALL_ROUTINE_IDX_ROUTINE_NAME_TID))) {
  }
  if (FAILEDx(index_tids.push_back(OB_ALL_ROUTINE_IDX_ROUTINE_PKG_ID_TID))) {
  }
  break;
}
case OB_ALL_ROUTINE_PARAM_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_ROUTINE_PARAM_IDX_ROUTINE_PARAM_NAME_TID))) {
  }
  break;
}
case OB_ALL_PACKAGE_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_PACKAGE_IDX_DB_PKG_NAME_TID))) {
  }
  if (FAILEDx(index_tids.push_back(OB_ALL_PACKAGE_IDX_PKG_NAME_TID))) {
  }
  break;
}
case OB_ALL_ACQUIRED_SNAPSHOT_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_ACQUIRED_SNAPSHOT_IDX_SNAPSHOT_TABLET_TID))) {
  }
  break;
}
case OB_ALL_CONSTRAINT_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_CONSTRAINT_IDX_CST_NAME_TID))) {
  }
  break;
}
case OB_ALL_ROLE_GRANTEE_MAP_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_ROLE_GRANTEE_MAP_IDX_GRANTEE_ROLE_ID_TID))) {
  }
  break;
}
case OB_ALL_ROLE_GRANTEE_MAP_HISTORY_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_ROLE_GRANTEE_MAP_HISTORY_IDX_GRANTEE_HIS_ROLE_ID_TID))) {
  }
  break;
}
case OB_ALL_TRIGGER_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_TRIGGER_IDX_TRIGGER_BASE_OBJ_ID_TID))) {
  }
  if (FAILEDx(index_tids.push_back(OB_ALL_TRIGGER_IDX_DB_TRIGGER_NAME_TID))) {
  }
  if (FAILEDx(index_tids.push_back(OB_ALL_TRIGGER_IDX_TRIGGER_NAME_TID))) {
  }
  break;
}
case OB_ALL_TRIGGER_HISTORY_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_TRIGGER_HISTORY_IDX_TRIGGER_HIS_BASE_OBJ_ID_TID))) {
  }
  break;
}
case OB_ALL_OBJAUTH_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_OBJAUTH_IDX_OBJAUTH_GRANTOR_TID))) {
  }
  if (FAILEDx(index_tids.push_back(OB_ALL_OBJAUTH_IDX_OBJAUTH_GRANTEE_TID))) {
  }
  break;
}
case OB_ALL_DEPENDENCY_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_DEPENDENCY_IDX_DEPENDENCY_REF_OBJ_TID))) {
  }
  break;
}
case OB_ALL_DDL_ERROR_MESSAGE_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_DDL_ERROR_MESSAGE_IDX_DDL_ERROR_OBJECT_TID))) {
  }
  break;
}
case OB_ALL_TABLE_STAT_HISTORY_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_TABLE_STAT_HISTORY_IDX_TABLE_STAT_HIS_SAVTIME_TID))) {
  }
  break;
}
case OB_ALL_COLUMN_STAT_HISTORY_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_COLUMN_STAT_HISTORY_IDX_COLUMN_STAT_HIS_SAVTIME_TID))) {
  }
  break;
}
case OB_ALL_HISTOGRAM_STAT_HISTORY_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_HISTOGRAM_STAT_HISTORY_IDX_HISTOGRAM_STAT_HIS_SAVTIME_TID))) {
  }
  break;
}
case OB_ALL_TABLET_TO_TABLE_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_TABLET_TO_TABLE_IDX_TABLET_TO_TABLE_ID_TID))) {
  }
  break;
}
case OB_ALL_JOB_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_JOB_IDX_JOB_POWNER_TID))) {
  }
  break;
}
case OB_ALL_TABLE_PRIVILEGE_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_TABLE_PRIVILEGE_IDX_TB_PRIV_DB_NAME_TID))) {
  }
  if (FAILEDx(index_tids.push_back(OB_ALL_TABLE_PRIVILEGE_IDX_TB_PRIV_TB_NAME_TID))) {
  }
  break;
}
case OB_ALL_DATABASE_PRIVILEGE_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_DATABASE_PRIVILEGE_IDX_DB_PRIV_DB_NAME_TID))) {
  }
  break;
}
case OB_ALL_DBMS_LOCK_ALLOCATED_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_DBMS_LOCK_ALLOCATED_IDX_DBMS_LOCK_ALLOCATED_LOCKHANDLE_TID))) {
  }
  if (FAILEDx(index_tids.push_back(OB_ALL_DBMS_LOCK_ALLOCATED_IDX_DBMS_LOCK_ALLOCATED_EXPIRATION_TID))) {
  }
  break;
}
case OB_ALL_COLUMN_PRIVILEGE_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_COLUMN_PRIVILEGE_IDX_COLUMN_PRIVILEGE_NAME_TID))) {
  }
  break;
}
case OB_ALL_AI_MODEL_ENDPOINT_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_AI_MODEL_ENDPOINT_IDX_ENDPOINT_NAME_TID))) {
  }
  if (FAILEDx(index_tids.push_back(OB_ALL_AI_MODEL_ENDPOINT_IDX_AI_MODEL_NAME_TID))) {
  }
  break;
}
case OB_ALL_OBJAUTH_MYSQL_TID: {
  if (FAILEDx(index_tids.push_back(OB_ALL_OBJAUTH_MYSQL_IDX_OBJAUTH_MYSQL_USER_ID_TID))) {
  }
  if (FAILEDx(index_tids.push_back(OB_ALL_OBJAUTH_MYSQL_IDX_OBJAUTH_MYSQL_OBJ_NAME_TID))) {
  }
  break;
}

#endif


#ifdef SYS_INDEX_DATA_TABLE_ID_TO_INDEX_SCHEMAS_SWITCH

case OB_ALL_TABLE_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_table_idx_data_table_id_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_table_idx_db_tb_name_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_table_idx_tb_name_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_COLUMN_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_column_idx_tb_column_name_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_column_idx_column_name_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_DDL_OPERATION_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_ddl_operation_idx_ddl_type_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_TABLE_HISTORY_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_table_history_idx_data_table_id_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_DDL_TASK_STATUS_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_ddl_task_status_idx_task_key_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_USER_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_user_idx_ur_name_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_DATABASE_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_database_idx_db_name_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_RECYCLEBIN_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_recyclebin_idx_recyclebin_db_type_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_recyclebin_idx_recyclebin_ori_name_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_PART_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_part_idx_part_name_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_SUB_PART_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_sub_part_idx_sub_part_name_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_DEF_SUB_PART_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_def_sub_part_idx_def_sub_part_name_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_FOREIGN_KEY_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_foreign_key_idx_fk_child_tid_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_foreign_key_idx_fk_parent_tid_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_foreign_key_idx_fk_name_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_FOREIGN_KEY_HISTORY_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_foreign_key_history_idx_fk_his_child_tid_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_foreign_key_history_idx_fk_his_parent_tid_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_DDL_CHECKSUM_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_ddl_checksum_idx_ddl_checksum_task_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_ROUTINE_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_routine_idx_db_routine_name_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_routine_idx_routine_name_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_routine_idx_routine_pkg_id_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_ROUTINE_PARAM_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_routine_param_idx_routine_param_name_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_PACKAGE_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_package_idx_db_pkg_name_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_package_idx_pkg_name_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_ACQUIRED_SNAPSHOT_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_acquired_snapshot_idx_snapshot_tablet_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_CONSTRAINT_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_constraint_idx_cst_name_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_ROLE_GRANTEE_MAP_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_role_grantee_map_idx_grantee_role_id_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_ROLE_GRANTEE_MAP_HISTORY_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_role_grantee_map_history_idx_grantee_his_role_id_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_TRIGGER_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_trigger_idx_trigger_base_obj_id_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_trigger_idx_db_trigger_name_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_trigger_idx_trigger_name_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_TRIGGER_HISTORY_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_trigger_history_idx_trigger_his_base_obj_id_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_OBJAUTH_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_objauth_idx_objauth_grantor_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_objauth_idx_objauth_grantee_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_DEPENDENCY_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_dependency_idx_dependency_ref_obj_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_DDL_ERROR_MESSAGE_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_ddl_error_message_idx_ddl_error_object_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_TABLE_STAT_HISTORY_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_table_stat_history_idx_table_stat_his_savtime_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_COLUMN_STAT_HISTORY_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_column_stat_history_idx_column_stat_his_savtime_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_HISTOGRAM_STAT_HISTORY_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_histogram_stat_history_idx_histogram_stat_his_savtime_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_TABLET_TO_TABLE_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_tablet_to_table_idx_tablet_to_table_id_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_JOB_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_job_idx_job_powner_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_TABLE_PRIVILEGE_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_table_privilege_idx_tb_priv_db_name_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_table_privilege_idx_tb_priv_tb_name_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_DATABASE_PRIVILEGE_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_database_privilege_idx_db_priv_db_name_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_DBMS_LOCK_ALLOCATED_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_dbms_lock_allocated_idx_dbms_lock_allocated_lockhandle_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_dbms_lock_allocated_idx_dbms_lock_allocated_expiration_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_COLUMN_PRIVILEGE_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_column_privilege_idx_column_privilege_name_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_AI_MODEL_ENDPOINT_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_ai_model_endpoint_idx_endpoint_name_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_ai_model_endpoint_idx_ai_model_name_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}
case OB_ALL_OBJAUTH_MYSQL_TID: {
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_objauth_mysql_idx_objauth_mysql_user_id_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  index_schema.reset();
  if (FAILEDx(ObInnerTableSchema::all_objauth_mysql_idx_objauth_mysql_obj_name_schema(index_schema))) {
  } else if (OB_FAIL(append_table_(index_schema, tables))) {
  }
  break;
}

#endif


#ifdef ADD_SYS_INDEX_ID

  } else if (OB_FAIL(table_ids.push_back(OB_ALL_TABLE_IDX_DATA_TABLE_ID_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_TABLE_IDX_DB_TB_NAME_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_TABLE_IDX_TB_NAME_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_COLUMN_IDX_TB_COLUMN_NAME_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_COLUMN_IDX_COLUMN_NAME_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_DDL_OPERATION_IDX_DDL_TYPE_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_TABLE_HISTORY_IDX_DATA_TABLE_ID_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_DDL_TASK_STATUS_IDX_TASK_KEY_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_USER_IDX_UR_NAME_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_DATABASE_IDX_DB_NAME_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_RECYCLEBIN_IDX_RECYCLEBIN_DB_TYPE_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_PART_IDX_PART_NAME_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_SUB_PART_IDX_SUB_PART_NAME_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_DEF_SUB_PART_IDX_DEF_SUB_PART_NAME_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_FOREIGN_KEY_IDX_FK_CHILD_TID_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_FOREIGN_KEY_IDX_FK_PARENT_TID_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_FOREIGN_KEY_IDX_FK_NAME_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_FOREIGN_KEY_HISTORY_IDX_FK_HIS_CHILD_TID_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_FOREIGN_KEY_HISTORY_IDX_FK_HIS_PARENT_TID_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_DDL_CHECKSUM_IDX_DDL_CHECKSUM_TASK_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_ROUTINE_IDX_DB_ROUTINE_NAME_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_ROUTINE_IDX_ROUTINE_NAME_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_ROUTINE_IDX_ROUTINE_PKG_ID_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_ROUTINE_PARAM_IDX_ROUTINE_PARAM_NAME_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_PACKAGE_IDX_DB_PKG_NAME_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_PACKAGE_IDX_PKG_NAME_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_ACQUIRED_SNAPSHOT_IDX_SNAPSHOT_TABLET_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_CONSTRAINT_IDX_CST_NAME_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_ROLE_GRANTEE_MAP_IDX_GRANTEE_ROLE_ID_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_ROLE_GRANTEE_MAP_HISTORY_IDX_GRANTEE_HIS_ROLE_ID_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_TRIGGER_IDX_TRIGGER_BASE_OBJ_ID_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_TRIGGER_IDX_DB_TRIGGER_NAME_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_TRIGGER_IDX_TRIGGER_NAME_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_TRIGGER_HISTORY_IDX_TRIGGER_HIS_BASE_OBJ_ID_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_OBJAUTH_IDX_OBJAUTH_GRANTOR_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_OBJAUTH_IDX_OBJAUTH_GRANTEE_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_DEPENDENCY_IDX_DEPENDENCY_REF_OBJ_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_DDL_ERROR_MESSAGE_IDX_DDL_ERROR_OBJECT_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_TABLE_STAT_HISTORY_IDX_TABLE_STAT_HIS_SAVTIME_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_COLUMN_STAT_HISTORY_IDX_COLUMN_STAT_HIS_SAVTIME_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_HISTOGRAM_STAT_HISTORY_IDX_HISTOGRAM_STAT_HIS_SAVTIME_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_TABLET_TO_TABLE_IDX_TABLET_TO_TABLE_ID_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_JOB_IDX_JOB_POWNER_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_RECYCLEBIN_IDX_RECYCLEBIN_ORI_NAME_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_TABLE_PRIVILEGE_IDX_TB_PRIV_DB_NAME_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_TABLE_PRIVILEGE_IDX_TB_PRIV_TB_NAME_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_DATABASE_PRIVILEGE_IDX_DB_PRIV_DB_NAME_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_DBMS_LOCK_ALLOCATED_IDX_DBMS_LOCK_ALLOCATED_LOCKHANDLE_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_DBMS_LOCK_ALLOCATED_IDX_DBMS_LOCK_ALLOCATED_EXPIRATION_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_COLUMN_PRIVILEGE_IDX_COLUMN_PRIVILEGE_NAME_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_AI_MODEL_ENDPOINT_IDX_ENDPOINT_NAME_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_AI_MODEL_ENDPOINT_IDX_AI_MODEL_NAME_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_OBJAUTH_MYSQL_IDX_OBJAUTH_MYSQL_USER_ID_TID))) {
  } else if (OB_FAIL(table_ids.push_back(OB_ALL_OBJAUTH_MYSQL_IDX_OBJAUTH_MYSQL_OBJ_NAME_TID))) {

#endif


#ifdef LOCAL_VIRTUAL_TABLE_CREATE_ITER

  // All local virtual tables are defined in ob_all_virtual_local_tables.h
  // Include it in ob_virtual_table_iterator_factory.cpp:
  // (local virtual tables header is pulled in by the factory cpp, not here)

  BEGIN_CREATE_VT_ITER_SWITCH_LAMBDA
    case OB_ALL_VIRTUAL_SYS_PARAMETER_TID: {
      ObAllVirtualSysParameter *oballvirtualsysparameter = NULL;
      if (OB_FAIL(NEW_VIRTUAL_TABLE(ObAllVirtualSysParameter, oballvirtualsysparameter))) {
        SERVER_LOG(ERROR, "ObAllVirtualSysParameter construct failed", K(ret));
      } else {
        vt_iter = static_cast<ObVirtualTableIterator *>(oballvirtualsysparameter);
      }
      break;
    }
    case OB_ALL_VIRTUAL_DEADLOCK_EVENT_HISTORY_TID: {
      ObAllVirtualDeadlockEventHistory *oballvirtualdeadlockeventhistory = NULL;
      if (OB_FAIL(NEW_VIRTUAL_TABLE(ObAllVirtualDeadlockEventHistory, oballvirtualdeadlockeventhistory))) {
        SERVER_LOG(ERROR, "ObAllVirtualDeadlockEventHistory construct failed", K(ret));
      } else {
        vt_iter = static_cast<ObVirtualTableIterator *>(oballvirtualdeadlockeventhistory);
      }
      break;
    }
    case OB_ALL_VIRTUAL_TABLET_META_TABLE_TID: {
      ObAllVirtualTabletMetaTable *oballvirtualtabletmetatable = NULL;
      if (OB_FAIL(NEW_VIRTUAL_TABLE(ObAllVirtualTabletMetaTable, oballvirtualtabletmetatable))) {
        SERVER_LOG(ERROR, "ObAllVirtualTabletMetaTable construct failed", K(ret));
      } else {
        vt_iter = static_cast<ObVirtualTableIterator *>(oballvirtualtabletmetatable);
      }
      break;
    }
    case OB_ALL_VIRTUAL_TABLET_LOCAL_CHECKSUM_TID: {
      ObAllVirtualTabletLocalChecksum *oballvirtualtabletlocalchecksum = NULL;
      if (OB_FAIL(NEW_VIRTUAL_TABLE(ObAllVirtualTabletLocalChecksum, oballvirtualtabletlocalchecksum))) {
        SERVER_LOG(ERROR, "ObAllVirtualTabletLocalChecksum construct failed", K(ret));
      } else {
        vt_iter = static_cast<ObVirtualTableIterator *>(oballvirtualtabletlocalchecksum);
      }
      break;
    }
    case OB_ALL_VIRTUAL_MERGE_INFO_TID: {
      ObAllVirtualMergeInfo *oballvirtualmergeinfo = NULL;
      if (OB_FAIL(NEW_VIRTUAL_TABLE(ObAllVirtualMergeInfo, oballvirtualmergeinfo))) {
        SERVER_LOG(ERROR, "ObAllVirtualMergeInfo construct failed", K(ret));
      } else {
        vt_iter = static_cast<ObVirtualTableIterator *>(oballvirtualmergeinfo);
      }
      break;
    }
    case OB_ALL_VIRTUAL_COLUMN_CHECKSUM_ERROR_INFO_TID: {
      ObAllVirtualColumnChecksumErrorInfo *oballvirtualcolumnchecksumerrorinfo = NULL;
      if (OB_FAIL(NEW_VIRTUAL_TABLE(ObAllVirtualColumnChecksumErrorInfo, oballvirtualcolumnchecksumerrorinfo))) {
        SERVER_LOG(ERROR, "ObAllVirtualColumnChecksumErrorInfo construct failed", K(ret));
      } else {
        vt_iter = static_cast<ObVirtualTableIterator *>(oballvirtualcolumnchecksumerrorinfo);
      }
      break;
    }
    case OB_ALL_VIRTUAL_ROOTSERVICE_JOB_TID: {
      ObAllVirtualRootserviceJob *oballvirtualrootservicejob = NULL;
      if (OB_FAIL(NEW_VIRTUAL_TABLE(ObAllVirtualRootserviceJob, oballvirtualrootservicejob))) {
        SERVER_LOG(ERROR, "ObAllVirtualRootserviceJob construct failed", K(ret));
      } else {
        vt_iter = static_cast<ObVirtualTableIterator *>(oballvirtualrootservicejob);
      }
      break;
    }
  END_CREATE_VT_ITER_SWITCH_LAMBDA

#endif // LOCAL_VIRTUAL_TABLE_CREATE_ITER
