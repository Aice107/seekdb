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

#define USING_LOG_PREFIX SQL_ENG
#include "config_bridge.h"
#include "common/ob_timeout_ctx.h"
#include "lib/stat/ob_diagnostic_info_guard.h"
#include "share/ob_server_struct.h"
#include "sql/engine/cmd/ob_table_executor.h"
#include "share/inner_table/ob_inner_table_schema.h"
#include "share/ob_dml_sql_splicer.h"
#include "query/command/ob_root_command_service.h"
#include "query/command/ob_root_service_serialization.h"
#include "query/runtime/ob_query_runtime_environment.h"
#include "query/session/ob_inner_sql_connection_access.h"
#include "sql/engine/expr/ob_expr_regexp_context.h"  // ObExprRegexpSessionVariables (unity regroup)
#include "sql/engine/cmd/ob_index_executor.h"
#include "sql/engine/cmd/ob_ddl_executor_util.h"
#include "sql/resolver/ddl/ob_create_table_stmt.h"
#include "sql/resolver/ddl/ob_alter_table_stmt.h"
#include "sql/resolver/ddl/ob_drop_table_stmt.h"
#include "sql/resolver/ddl/ob_rename_table_stmt.h"
#include "sql/resolver/ddl/ob_truncate_table_stmt.h"
#include "sql/resolver/ddl/ob_create_table_like_stmt.h"
#include "sql/resolver/ddl/ob_fork_table_stmt.h"
#include "sql/resolver/ddl/ob_recyclebin_restore_stmt.h"
#include "sql/resolver/ddl/ob_purge_stmt.h"
#include "sql/resolver/ddl/ob_optimize_stmt.h"
#include "sql/resolver/dml/ob_delete_resolver.h"
#include "sql/engine/cmd/ob_partition_executor_utils.h"

#include "sql/printer/ob_select_stmt_printer.h"
#include "share/ob_structured_event_logger.h"
namespace oceanbase
{
using namespace common;
using namespace share;
using namespace share::schema;
using namespace observer;
namespace sql
{

ObCreateTableExecutor::ObCreateTableExecutor()
{
}

ObCreateTableExecutor::~ObCreateTableExecutor()
{
}

int ObCreateTableExecutor::prepare_stmt(ObCreateTableStmt &stmt,
                                        const ObSQLSessionInfo &my_session,
                                        ObString &create_table_name)
{
  int ret = OB_SUCCESS;
  ObArenaAllocator allocator("CreateTableExec");
  const int64_t buf_len = OB_MAX_SQL_LENGTH;
  char *buf = static_cast<char*>(allocator.alloc(buf_len));
  int64_t pos = 0;
  const int64_t session_id = my_session.get_server_sid();
  const int64_t timestamp = ObTimeUtility::current_time();
  obcall::ObCreateTableArg &create_table_arg = stmt.get_create_table_arg();
  create_table_name = create_table_arg.schema_.get_table_name_str();
  if (OB_FAIL(databuff_printf(buf, buf_len, pos, "__ctas_%ld_%ld", session_id, timestamp))) {
  } else {
    ObString tmp_table_name(pos, buf);
    if (OB_FAIL(create_table_arg.schema_.set_table_name(tmp_table_name))) {
    }
  }
  return ret;
}

int ObCreateTableExecutor::ObInsSQLPrinter::inner_print(char *buf, int64_t buf_len, int64_t &res_len)
{
  int ret = OB_SUCCESS;
  const char sep_char = '`';
  const ObSelectStmt *select_stmt = NULL;
  int64_t pos1 = 0;
  uint64_t insert_mode = 0;
  
  if (OB_ISNULL(stmt_) || OB_ISNULL(select_stmt= stmt_->get_sub_select())) {
    ret = OB_ERR_UNEXPECTED;
  } else {
    const char *insert_str = NULL;
    const int64_t parallel_str_max_len = 256;
    char parallel_str[parallel_str_max_len] = {0};
    int64_t parallel_str_pos = 0;
    const char *osg_str = NULL;
    insert_mode = stmt_->get_insert_mode();
    if (insert_mode != 0 &&
        insert_mode != 1 &&
        insert_mode != 2 ) {
      ret = OB_ERR_UNEXPECTED;
    } else {
      insert_str = insert_mode == 0 ? "insert" : insert_mode == 1 ? "insert ignore" : "replace";
      osg_str = do_osg_ ? "GATHER_OPTIMIZER_STATISTICS" : "NO_GATHER_OPTIMIZER_STATISTICS";
      if (stmt_->get_has_parallel_hint() &&
          OB_FAIL(databuff_printf(parallel_str, parallel_str_max_len, parallel_str_pos,
                                  "PARALLEL(%lu)", stmt_->get_parallelism()))) {
      }
    }
    if (OB_FAIL(ret)) {

    } else if (OB_FAIL(databuff_printf(buf, buf_len, pos1,
                                       "%s /*+ ENABLE_PARALLEL_DML %s %s */ into %c%.*s%c.%c%.*s%c",
                                       insert_str,
                                       parallel_str,
                                       osg_str,
                                       sep_char,
                                       stmt_->get_database_name().length(),
                                       stmt_->get_database_name().ptr(),
                                       sep_char,
                                       sep_char,
                                       stmt_->get_table_name().length(),
                                       stmt_->get_table_name().ptr(),
                                       sep_char
                                       ))) {
    }
  }
  if (OB_FAIL(ret)) {
    //do nothing
  } else {
    for (int64_t i = 0; OB_SUCC(ret) && i < select_stmt->get_select_item_size(); ++i) {
      const SelectItem &select_item = select_stmt->get_select_item(i);
      if (OB_FAIL(databuff_printf(buf, buf_len, pos1, (0 == i)? "(": ", "))) {
      } else { /* do nothing */ }
      if (OB_SUCC(ret)) {
        if (!select_item.alias_name_.empty()) {
          if (OB_FAIL(databuff_printf(buf, buf_len, pos1, "%c%.*s%c", sep_char, LEN_AND_PTR(select_item.alias_name_), sep_char))) {
          } else { /* do nothing */ }
        } else {
          if (OB_FAIL(databuff_printf(buf, buf_len, pos1, "%c%.*s%c", sep_char, LEN_AND_PTR(select_item.expr_name_), sep_char))) {
          } else { /* do nothing */ }
        }
      } else { /* do nothing */ }
    }
  }

  if (OB_SUCC(ret)) {
    ObSelectStmtPrinter select_stmt_printer(buf, buf_len, &pos1, select_stmt,
                                            schema_guard_,
                                            print_params_,
                                            param_store_,
                                            true);
    select_stmt_printer.set_is_first_stmt_for_hint(true);  // need print global hint
    if (OB_FAIL(databuff_printf(buf, buf_len, pos1, ") "))) {
    } else if (OB_FAIL(select_stmt_printer.do_print())) {
    } else {
      res_len = pos1;
      LOG_INFO("[CTAS] successfully print sql", "sql", buf);
    }
  }
  return ret;
}
// Prepare query insertion script
int ObCreateTableExecutor::prepare_ins_arg(ObCreateTableStmt &stmt,
                                           const ObSQLSessionInfo *my_session,
                                           ObSchemaGetterGuard *schema_guard,
                                           const ParamStore *param_store,
                                           ObSqlString &ins_sql) // out, final query insert statement
{
  int ret = OB_SUCCESS;
  ObArenaAllocator allocator("CreateTableExec");
  char *buf = static_cast<char*>(allocator.alloc(OB_MAX_SQL_LENGTH));
  int64_t buf_len = OB_MAX_SQL_LENGTH;
  int64_t pos1 = 0;
  bool no_osg_hint = false;
  bool online_sys_var = false;
  ObSelectStmt *select_stmt = stmt.get_sub_select();
  ObObjPrintParams obj_print_params(select_stmt->get_query_ctx()->get_timezone_info());
  obj_print_params.print_origin_stmt_ = true;
  if (OB_ISNULL(buf)) {
    ret = OB_ALLOCATE_MEMORY_FAILED;
    LOG_ERROR("allocate memory failed");
  } else if (OB_ISNULL(select_stmt) || OB_ISNULL(select_stmt->get_query_ctx()) || OB_ISNULL(my_session)) {
    ret = OB_ERR_UNEXPECTED;
  } else {
    //get hint
    no_osg_hint = select_stmt->get_query_ctx()->get_global_hint().has_no_gather_opt_stat_hint();

    //get system variable
    ObObj online_sys_var_obj;
    if (OB_FAIL(my_session->get_sys_variable(SYS_VAR__OPTIMIZER_GATHER_STATS_ON_LOAD, online_sys_var_obj))) {
    } else {
      online_sys_var = online_sys_var_obj.get_bool();
    }
  }

  if (OB_SUCC(ret)) {
    ObInsSQLPrinter sql_printer(&stmt, schema_guard, obj_print_params, param_store, !no_osg_hint && online_sys_var);
    ObString sql;
    if (OB_FAIL(sql_printer.do_print(allocator, sql))) {
    } else if (OB_FAIL(ins_sql.append(sql))){
    }
  }

  if (OB_SUCC(ret)) {
    ObString converted_sql = ins_sql.string();
    if (OB_FAIL(ObSQLUtils::convert_sql_text_from_schema_for_resolve(allocator,
                                                                     my_session->get_dtc_params(),
                                                                     converted_sql,
                                                                     ObCharset::COPY_STRING_ON_SAME_CHARSET))) {
    } else if (OB_FAIL(ins_sql.assign(converted_sql))) {
    }
  }
  return ret;
}
// Prepare alter table parameters
int ObCreateTableExecutor::prepare_alter_arg(ObCreateTableStmt &stmt,
                                             const ObSQLSessionInfo *my_session,
                                             const ObString &create_table_name,
                                             obcall::ObAlterTableArg &alter_table_arg) //out, final alter table arg, set session_id = 0;
{
  int ret = OB_SUCCESS;
  const obcall::ObCreateTableArg &create_table_arg = stmt.get_create_table_arg();
  ObTableSchema &table_schema = const_cast<obcall::ObCreateTableArg&>(create_table_arg).schema_;
  AlterTableSchema *alter_table_schema = &alter_table_arg.alter_table_schema_;
  table_schema.set_session_id(my_session->get_sessid_for_table());
  alter_table_arg.session_id_ = my_session->get_sessid_for_table();
  alter_table_schema->alter_type_ = OB_DDL_ALTER_TABLE;
  alter_table_arg.is_inner_ = my_session->is_inner();
  
  if (OB_FAIL(alter_table_arg.tz_info_wrap_.deep_copy(my_session->get_tz_info_wrap()))) {
  } else if (OB_FAIL(alter_table_schema->assign(table_schema))) {
  } else if (!table_schema.is_mysql_tmp_table()
             && FALSE_IT(alter_table_schema->set_session_id(0))) {
    //impossible
  } else if (OB_FAIL(alter_table_schema->set_origin_table_name(stmt.get_table_name()))) {
  } else if (OB_FAIL(alter_table_schema->set_origin_database_name(stmt.get_database_name()))) {
  } else if (OB_FAIL(alter_table_schema->set_table_name(create_table_name))) {
  } else if (OB_FAIL(alter_table_schema->set_database_name(stmt.get_database_name()))) {
  } else if (!table_schema.is_mysql_tmp_table()
             && OB_FAIL(alter_table_schema->alter_option_bitset_.add_member(obcall::ObAlterTableArg::SESSION_ID))) {
  } else if (OB_FAIL(alter_table_schema->alter_option_bitset_.add_member(obcall::ObAlterTableArg::TABLE_NAME))) {
  }
  return ret;
}
// Prepare drop table parameters
int ObCreateTableExecutor::prepare_drop_arg(const ObCreateTableStmt &stmt,
                                            const ObSQLSessionInfo *my_session,
                                            obcall::ObTableItem &table_item,
                                            obcall::ObDropTableArg &drop_table_arg) // out, drop table arguments
{
  int ret = OB_SUCCESS;
  const ObString &db_name = stmt.get_database_name();
  const ObString &tab_name = stmt.get_table_name();
  drop_table_arg.if_exist_ = true;
  
  drop_table_arg.to_recyclebin_ = false;
  drop_table_arg.table_type_ = USER_TABLE;
  drop_table_arg.session_id_ = my_session->get_sessid_for_table();
  
  int64_t foreign_key_checks = 0;
  my_session->get_foreign_key_checks(foreign_key_checks);
  drop_table_arg.foreign_key_checks_ = foreign_key_checks;
  table_item.database_name_ = db_name;
  table_item.table_name_ = tab_name;
  if (OB_FAIL(my_session->get_name_case_mode(table_item.mode_))) {
  } else if (OB_FAIL(drop_table_arg.tables_.push_back(table_item))) {
  }
  return ret;
}
// Query table creation processing, through internal session execution query insert code reference ObTableModify::ObTableModifyCtx::open_inner_conn() implementation
int ObCreateTableExecutor::execute_ctas(ObExecContext &ctx,
                                        ObCreateTableStmt &stmt)
{
  int ret = OB_SUCCESS;
  ObString cur_query;
  int64_t affected_rows = 0;
  ObMySQLProxy *sql_proxy = ctx.get_sql_proxy();
  ObSQLSessionInfo *my_session = ctx.get_my_session();
  ObPhysicalPlanCtx *plan_ctx = ctx.get_physical_plan_ctx();
  ObArenaAllocator allocator("CreateTableExec");
  HEAP_VAR(obcall::ObAlterTableArg, alter_table_arg) {
    obcall::ObDropTableArg drop_table_arg;
    obcall::ObTableItem table_item;
    ObString create_table_name;
    ObSqlString ins_sql;
    const ObGlobalContext &gctx = GCTX;
    obcall::ObCreateTableRes create_table_res;
    obcall::ObCreateTableArg &create_table_arg = stmt.get_create_table_arg();
    create_table_arg.is_inner_ = my_session->is_inner();
    bool need_clean = true;
    CK(OB_NOT_NULL(sql_proxy),
      OB_NOT_NULL(my_session),
      OB_NOT_NULL(gctx.schema_service_),
      OB_NOT_NULL(plan_ctx),
      OB_NOT_NULL(ctx.get_sql_ctx()));
    if (OB_SUCC(ret)) {
      if (OB_FAIL(ob_write_string(allocator, my_session->get_current_query_string(), cur_query))) {
      }
    }
    
    if (OB_SUCC(ret)) {
      if (OB_FAIL(prepare_stmt(stmt, *my_session, create_table_name))) {
      } else if (OB_FAIL(prepare_ins_arg(stmt, my_session, ctx.get_sql_ctx()->schema_guard_, &plan_ctx->get_param_store(), ins_sql))) {
      } else if (OB_FAIL(prepare_alter_arg(stmt, my_session, create_table_name, alter_table_arg))) {
      } else if (OB_FAIL(prepare_drop_arg(stmt, my_session, table_item, drop_table_arg))) {
      } else if (OB_FAIL(ctx.get_sql_ctx()->schema_guard_->reset())){
      } else {// 2. create table
        DEBUG_SYNC(BEFORE_SEND_PARALLEL_CREATE_TABLE);
        create_table_arg.is_parallel_ = false;
        if (OB_FAIL(ObDDLExecutorUtil::execute_pcreate_table(
            my_session, ctx.root_command_service(), "[parallel create table]",
                                                            create_table_arg, create_table_res))) {
        }
      }
      if (OB_FAIL(ret)) {
        // do nothing
      } else if (!(OB_INVALID_ID == create_table_res.table_id_
                  || (OB_INVALID_ID != create_table_res.table_id_
                      && true == create_table_res.do_nothing_)) ) { // If the table already exists, subsequent query inserts will not be performed
        // 1. for old rs
        // when table_exist, table_id == invalid_id, and do_nothing will alway be false
        // 2. for new rs
        // do_nothing is true when table_exist
        // --> when table_id == invalid, both old and new rs no table create
        // --> when table_id != invalid, both old and new rs do_nothing_ correct
        if (OB_INVALID_VERSION == create_table_res.schema_version_) {
          ret = OB_ERR_UNEXPECTED;
        } else {
          
          if (OB_FAIL(gctx.schema_service_->async_refresh_schema(create_table_res.schema_version_))) {
          }
        }
        #ifdef ERRSIM
        {
          int tmp_ret = OB_E(EventTable::EN_CTAS_FAIL_NO_DROP_ERROR) OB_SUCCESS; // error injection, make the table unable to be cleaned
          if (OB_FAIL(tmp_ret)) {
            ret = tmp_ret;
            need_clean = false;
          }
        }
        #else
          //do nothing...
        #endif
        //3, insert data
        if (OB_SUCC(ret)) {
          bool is_mysql_temp_table = stmt.get_create_table_arg().schema_.is_mysql_tmp_table();
          bool in_trans = my_session->is_in_transaction();
          bool need_set_autocommit = (!is_mysql_temp_table || !in_trans);
          bool original_autocommit = false;
          ObBasicSessionInfo::UserScopeGuard user_scope_guard(my_session->get_sql_scope_flags());
          common::sqlclient::ObISQLConnection *conn = NULL;
          common::sqlclient::ObISQLConnectionGuard conn_guard;

          if (OB_FAIL(my_session->get_autocommit(original_autocommit))) {
          } else if (need_set_autocommit &&
                     !original_autocommit && OB_FAIL(my_session->set_autocommit(true))) {
            LOG_WARN("failed to set autocommit", K(ret));
          } else {
            if (OB_FAIL(
                    query::ObInnerSQLConnectionAccess::
                        create_connection_with_external_session(
                            my_session, conn_guard))) {
            } else if (OB_ISNULL(conn = conn_guard.get_ptr())) {
              ret = OB_INNER_STAT_ERROR;
            } else if (OB_FAIL(
                           conn->execute_write(ins_sql.ptr(), affected_rows, true))) {
            }

            if (need_set_autocommit && !original_autocommit) {
              int tmp_ret = OB_SUCCESS;
              if (OB_TMP_FAIL(my_session->set_autocommit(original_autocommit))) {
                ret = (OB_SUCCESS == ret) ? tmp_ret : ret;
                LOG_WARN("failed to set autocommit", K(ret), K(tmp_ret), K(original_autocommit));
              }
            }
            conn = NULL;
            conn_guard.reset();
          }
        }

        DEBUG_SYNC(BEFORE_EXECUTE_CTAS_CLEAR_SESSION_ID);
        //4, refresh schema, reset table's sess id to 0
        if (OB_SUCC(ret)) {
          obcall::ObAlterTableRes res;
          bool finish = false;
          while (OB_SUCC(ret) && !finish) {
            if (OB_FAIL(query::serialize_root_service_call(
                    [&]{ return ctx.root_command_service().alter_table(alter_table_arg, res); }))) {
              if (OB_EAGAIN == ret) {
                ret = OB_SUCCESS; // maybe table lock conflict, retry
                if (OB_UNLIKELY(THIS_WORKER.get_timeout_remain() <= 0)) {
                  ret = OB_TIMEOUT;
                } else if (OB_FAIL(THIS_WORKER.check_status())) {
                }
              }
            } else {
              finish = true;
            }
          }
        }

        if (OB_FAIL(ret)) { //5, query table creation failed, need to clean up environment i.e. DROP TABLE
          my_session->update_last_active_time();
          if (OB_LIKELY(need_clean)) {
            int tmp_ret = OB_SUCCESS;
            obcall::ObDDLRes res;
            if (OB_SUCCESS != (tmp_ret = query::serialize_root_service_call([&]{
                  return ctx.root_command_service().drop_table(drop_table_arg, res);
                }))) {
            } else {
              LOG_INFO("table is created and dropped due to error ", K(ret));
            }
          }
        } else {
          plan_ctx->set_affected_rows(affected_rows);
        }

        if (OB_ERR_TABLE_EXIST == ret && create_table_arg.if_not_exist_) {
          ret = OB_SUCCESS;
        }
      } else {
      }
      char table_info_buffer[256];
      snprintf(table_info_buffer, sizeof(table_info_buffer), "table_id:%ld, hidden_table_id:%ld",
                alter_table_arg.table_id_, alter_table_arg.hidden_table_id_);
      SERVER_EVENT_ADD("ddl", "create table as select execute finish",
        "ret", ret,
        "trace_id", *ObCurTraceId::get_trace_id(),
        "rpc_dst", GCTX.self_addr(),
        "table_info", table_info_buffer,
        "schema_version", create_table_res.schema_version_);
      SQL_ENG_LOG(INFO, "finish create table execute.", K(ret), "ddl_event_info", ObDDLEventInfo(GCTX.self_addr()));
    }
    OZ(my_session->store_query_string(cur_query));
  }
  return ret;
}

int ObCreateTableExecutor::execute(ObExecContext &ctx, ObCreateTableStmt &stmt)
{
  int ret = OB_SUCCESS;
  ObSqlExecutorCtx *task_exec_ctx = NULL;
  obcall::ObCreateTableRes res;
  obcall::ObCreateTableArg &create_table_arg = stmt.get_create_table_arg();
  ObString first_stmt;
  ObSelectStmt *select_stmt = stmt.get_sub_select();
  const ObTableSchema &table_schema = create_table_arg.schema_;
  ObSQLSessionInfo *my_session = ctx.get_my_session();
  
  if (OB_ISNULL(my_session)) {
    ret = OB_ERR_UNEXPECTED;
  } else if (OB_FAIL(stmt.get_first_stmt(first_stmt))) {
  }

  if (OB_FAIL(ret)) {
  } else {
    create_table_arg.is_inner_ = my_session->is_inner();
    const_cast<obcall::ObCreateTableArg&>(create_table_arg).ddl_stmt_str_ = first_stmt;
    bool enable_parallel_create_table = false;
    {
      enable_parallel_create_table = true
                                     && config::_enable_parallel_table_creation();

    }
    if (OB_ISNULL(task_exec_ctx = GET_SQL_EXECUTOR_CTX(ctx))) {
      ret = OB_NOT_INIT;
    } else if (OB_FAIL(ObPartitionExecutorUtils::calc_values_exprs(ctx, stmt))) {
    } else if (OB_FAIL(set_index_arg_list(ctx, stmt))) {
    } else if (OB_ISNULL(select_stmt)) { // Processing for normal table creation
      bool &is_parallel_create = create_table_arg.is_parallel_;
      if (OB_FAIL(ctx.get_sql_ctx()->schema_guard_->reset())){
      } else if (table_schema.is_view_table()) {
        is_parallel_create = false;
      } else {
        is_parallel_create = true
                             && config::_enable_parallel_table_creation();
      }
      if (OB_FAIL(ret)) {
        // do nothing
      } else {
        DEBUG_SYNC(BEFORE_SEND_PARALLEL_CREATE_TABLE);
        if (OB_FAIL(ObDDLExecutorUtil::execute_pcreate_table(
            my_session, ctx.root_command_service(), "[parallel create table]",
                                                          create_table_arg, res))) {
        }
      }
    } else {
      if (OB_FAIL(execute_ctas(ctx, stmt))){
      }
    }
    if (OB_SUCC(ret) && !stmt.get_ai_column_defs().empty()) {
      uint64_t table_id = res.table_id_;
      if (0 == table_id || OB_INVALID_ID == table_id) {
        table_id = create_table_arg.schema_.get_table_id();
      }
      if (OB_FAIL(insert_ai_column_metadata(ctx, stmt, table_id))) {
        LOG_WARN("failed to insert ai column metadata", K(ret), K(table_id));
      }
    }

    SERVER_EVENT_ADD("ddl", "create table execute finish",
      "ret", ret,
      "trace_id", *ObCurTraceId::get_trace_id(),
      "rpc_dst", GCTX.self_addr(),
      "table_info", res.table_id_,
      "schema_version", res.schema_version_);
    SQL_ENG_LOG(INFO, "finish create table execute.", K(ret), "ddl_event_info", ObDDLEventInfo(GCTX.self_addr()));

    // only CTAS or create temporary table will make session_id != 0. If such table detected, set
    // need ctas cleanup task anyway to do some cleanup jobs
    if (0 != table_schema.get_session_id()) {
      query::request_query_ctas_cleanup(
          ctx.get_query_runtime_environment());
    }
  }
  return ret;
}

// Turns "content,tags" into "NOT (NEW.`content` <=> OLD.`content`) OR ...".
static int append_ai_change_condition(const common::ObString &deps, ObSqlString &cond)
{
  int ret = OB_SUCCESS;
  int32_t start = 0;
  bool first = true;
  for (int32_t i = 0; OB_SUCC(ret) && i <= deps.length(); ++i) {
    if (i == deps.length() || ',' == deps.ptr()[i]) {
      int32_t begin = start;
      int32_t end = i;
      while (begin < end && (' ' == deps.ptr()[begin] || '`' == deps.ptr()[begin])) {
        ++begin;
      }
      while (end > begin && (' ' == deps.ptr()[end - 1] || '`' == deps.ptr()[end - 1])) {
        --end;
      }
      if (end > begin) {
        if (!first && OB_FAIL(cond.append_fmt(" OR "))) {
        } else {
          first = false;
          if (OB_SUCC(ret) && OB_FAIL(cond.append_fmt(
                  "NOT (NEW.`%.*s` <=> OLD.`%.*s`)", end - begin, deps.ptr() + begin,
                  end - begin, deps.ptr() + begin))) {
          }
        }
      }
      start = i + 1;
    }
  }
  return ret;
}

int ObCreateTableExecutor::insert_ai_column_metadata(ObExecContext &ctx,
                                                     ObCreateTableStmt &stmt,
                                                     uint64_t table_id)
{
  int ret = OB_SUCCESS;
  ObSQLSessionInfo *session = ctx.get_my_session();
  ObMySQLProxy *sql_proxy = ctx.get_sql_proxy();
  const ObSEArray<ObAiColumnDef, 4> &defs = stmt.get_ai_column_defs();
  if (OB_ISNULL(session) || OB_ISNULL(sql_proxy)) {
    ret = OB_ERR_UNEXPECTED;
  }
  for (int64_t i = 0; OB_SUCC(ret) && i < defs.count(); ++i) {
    const ObAiColumnDef &def = defs.at(i);
    ObSqlString sql;
    int64_t affected_rows = 0;
    ObDMLSqlSplicer splicer;
    if (OB_FAIL(splicer.add_pk_column("table_id", table_id))) {
    } else if (OB_FAIL(splicer.add_pk_column("column_id", def.column_id_))) {
    } else if (OB_FAIL(splicer.add_column("column_name", def.column_name_))) {
    } else if (OB_FAIL(splicer.add_column("max_retries", def.max_retries_))) {
    } else if (OB_FAIL(splicer.add_column("state_column_id", static_cast<int64_t>(def.state_column_id_)))) {
    } else if (OB_FAIL(splicer.add_column("request_column_id", static_cast<int64_t>(def.request_column_id_)))) {
    } else if (OB_FAIL(splicer.add_column("result_spec_column_id", static_cast<int64_t>(def.result_spec_column_id_)))) {
    } else if (OB_FAIL(splicer.add_column("normalized_expr", def.normalized_expr_))) {
    } else if (OB_FAIL(splicer.add_column("raw_expr", ObHexEscapeSqlStr(def.raw_expr_)))) {
    } else if (OB_FAIL(splicer.add_column("dependency_columns", def.dependency_columns_))) {
    } else if (OB_FAIL(splicer.splice_insert_sql(OB_ALL_AI_COLUMN_TNAME, sql))) {
    } else if (OB_FAIL(sql_proxy->write(sql.ptr(), affected_rows))) {
      LOG_WARN("failed to write ai column metadata", K(ret), K(sql));
    }
  }
  if (OB_SUCC(ret) && !defs.empty()) {
    const share::schema::ObTableSchema &schema = stmt.get_create_table_arg().schema_;
    const ObString &db_name = stmt.get_create_table_arg().db_name_;
    const ObString &table_name = schema.get_table_name_str();
    ObSqlString pred_new;
    ObSqlString pred_old;
    ObSqlString pk_change;
    int64_t max_rk_pos = 0;
    for (int64_t i = 0; OB_SUCC(ret) && i < schema.get_column_count(); ++i) {
      const ObColumnSchemaV2 *c = schema.get_column_schema_by_idx(i);
      if (OB_NOT_NULL(c) && c->get_rowkey_position() > max_rk_pos) {
        max_rk_pos = c->get_rowkey_position();
      }
    }
    if (OB_SUCC(ret) && max_rk_pos <= 0) {
      ret = OB_ERR_UNEXPECTED;
      LOG_ERROR("no rowkey column for ai trigger", K(ret));
    } else if (OB_SUCC(ret) && OB_FAIL(pred_new.append_fmt("CONCAT("))) {
    } else if (OB_SUCC(ret) && OB_FAIL(pred_old.append_fmt("CONCAT("))) {
    } else if (OB_SUCC(ret)) {
      for (int64_t pos = 1; OB_SUCC(ret) && pos <= max_rk_pos; ++pos) {
        const ObColumnSchemaV2 *col = NULL;
        for (int64_t i = 0; OB_ISNULL(col) && i < schema.get_column_count(); ++i) {
          const ObColumnSchemaV2 *c = schema.get_column_schema_by_idx(i);
          if (OB_NOT_NULL(c) && c->get_rowkey_position() == pos) {
            col = c;
          }
        }
        if (OB_ISNULL(col)) {
          ret = OB_ERR_UNEXPECTED;
        } else if (OB_FAIL(pred_new.append_fmt(
                       "%s'`%s` = ', NEW.%s", pos > 1 ? ", ' and '" : "",
                       col->get_column_name(), col->get_column_name()))) {
        } else if (OB_FAIL(pred_old.append_fmt(
                       "%s'`%s` = ', OLD.%s", pos > 1 ? ", ' and '" : "",
                       col->get_column_name(), col->get_column_name()))) {
        } else if (OB_FAIL(pk_change.append_fmt(
                       "%sNOT (NEW.%s <=> OLD.%s)", pos > 1 ? " OR " : "",
                       col->get_column_name(), col->get_column_name()))) {
        }
      }
      if (OB_SUCC(ret) && OB_FAIL(pred_new.append_fmt(")"))) {
      } else if (OB_SUCC(ret) && OB_FAIL(pred_old.append_fmt(")"))) {
      }
    }
    if (OB_SUCC(ret) && db_name.empty()) {
      ret = OB_ERR_UNEXPECTED;
      LOG_ERROR("empty db name for ai column trigger", K(ret));
    }
    for (int64_t i = 0; OB_SUCC(ret) && i < defs.count(); ++i) {
      const ObAiColumnDef &def = defs.at(i);
      ObSqlString dep_change;
      ObSqlString cond;
      ObSqlString trg;
      const int64_t tid = static_cast<int64_t>(table_id);
      const int64_t cid = static_cast<int64_t>(def.column_id_);
      const ObString &cname = def.column_name_;
      if (OB_SUCC(ret) && OB_FAIL(append_ai_change_condition(def.dependency_columns_, dep_change))) {
      } else if (OB_SUCC(ret)) {
        if (dep_change.length() > 0) {
          ret = cond.append_fmt("(%s) OR (%s)", dep_change.ptr(), pk_change.ptr());
        } else {
          ret = cond.append_fmt("%s", pk_change.ptr());
        }
      }
      // 1) AFTER INSERT: queue one task row per AI column.
      if (OB_SUCC(ret) && OB_FAIL(trg.append_fmt(
              "CREATE TRIGGER `__ai_ins_%ld_%ld` AFTER INSERT ON `%.*s`.`%.*s` "
              "FOR EACH ROW INSERT INTO oceanbase.__all_ai_column_task "
              "(task_id, table_id, column_id, rowkey_predicate, eligible_ts, state, retry_count, request_id) "
              "VALUES (uuid_short(), %ld, %ld, %s, now(6), 0, 0, CONCAT('ai_', %ld, '_', %s))",
              tid, cid, db_name.length(), db_name.ptr(), table_name.length(), table_name.ptr(),
              tid, cid, pred_new.ptr(), tid, pred_new.ptr()))) {
      } else if (OB_SUCC(ret) && OB_FAIL(ObAiColumnTriggerQueue::enqueue(
                     session->get_server_sid(), db_name, table_name, trg.string()))) {
        LOG_ERROR("failed to enqueue ai insert trigger", K(ret), K(trg));
      } else if (OB_SUCC(ret)) {
        trg.reset();
      }
      // 2) BEFORE UPDATE: invalidate the stale result when a dependency column or the
      //    primary key changes. JSON columns need an explicit round trip, otherwise the
      //    trigger would turn the object into a JSON string.
      const ObColumnSchemaV2 *result_col = schema.get_column_schema(cname);
      const bool is_json_result = OB_NOT_NULL(result_col) && result_col->is_json();
      // Vector columns cannot be read back through NEW inside a trigger (OB -4006), so the
      // invalidation trigger is skipped for them; a native path has to null them instead.
      bool is_vector_result = false;
      if (OB_NOT_NULL(result_col) && 1 == result_col->get_extended_type_info().count()) {
        ObString info = result_col->get_extended_type_info().at(0);
        ObString head = info.split_on('(').trim();
        is_vector_result = (0 == head.compare("VECTOR"));
      }
      ObSqlString keep_expr;
      if (OB_SUCC(ret)) {
        if (is_json_result) {
          ret = keep_expr.append_fmt(
              "CAST(IF(json_type(NEW.`%.*s`) = 'STRING', json_unquote(NEW.`%.*s`), "
              "NEW.`%.*s`) AS JSON)", cname.length(), cname.ptr(),
              cname.length(), cname.ptr(), cname.length(), cname.ptr());
        } else {
          ret = keep_expr.append_fmt("NEW.`%.*s`", cname.length(), cname.ptr());
        }
      }
      if (OB_SUCC(ret) && is_vector_result) {
        // no invalidation trigger for vector results
      } else if (OB_SUCC(ret) && OB_FAIL(trg.append_fmt(
              "CREATE TRIGGER `__ai_upd_inv_%ld_%ld` BEFORE UPDATE ON `%.*s`.`%.*s` "
              "FOR EACH ROW SET NEW.`%.*s` = IF(%s, NULL, %s)",
              tid, cid, db_name.length(), db_name.ptr(), table_name.length(), table_name.ptr(),
              cname.length(), cname.ptr(), cond.ptr(), keep_expr.ptr()))) {
      } else if (OB_SUCC(ret) && OB_FAIL(ObAiColumnTriggerQueue::enqueue(
                     session->get_server_sid(), db_name, table_name, trg.string()))) {
        LOG_ERROR("failed to enqueue ai invalidate trigger", K(ret), K(trg));
      } else if (OB_SUCC(ret)) {
        trg.reset();
      }
      // 3) BEFORE UPDATE: drop the queued task of the old and the current row key so the
      //    AFTER UPDATE trigger can insert exactly one fresh task (no duplicates).
      if (OB_SUCC(ret) && OB_FAIL(trg.append_fmt(
              "CREATE TRIGGER `__ai_upd_del_%ld_%ld` BEFORE UPDATE ON `%.*s`.`%.*s` "
              "FOR EACH ROW DELETE FROM oceanbase.__all_ai_column_task "
              "WHERE table_id = %ld AND column_id = %ld "
              "AND (rowkey_predicate = %s OR rowkey_predicate = %s) AND (%s)",
              tid, cid, db_name.length(), db_name.ptr(), table_name.length(), table_name.ptr(),
              tid, cid, pred_old.ptr(), pred_new.ptr(), cond.ptr()))) {
      } else if (OB_SUCC(ret) && OB_FAIL(ObAiColumnTriggerQueue::enqueue(
                     session->get_server_sid(), db_name, table_name, trg.string()))) {
        LOG_ERROR("failed to enqueue ai update-cleanup trigger", K(ret), K(trg));
      } else if (OB_SUCC(ret)) {
        trg.reset();
      }
      // 4) AFTER UPDATE: queue one task row for the new value set.
      if (OB_SUCC(ret) && OB_FAIL(trg.append_fmt(
              "CREATE TRIGGER `__ai_upd_ins_%ld_%ld` AFTER UPDATE ON `%.*s`.`%.*s` "
              "FOR EACH ROW INSERT INTO oceanbase.__all_ai_column_task "
              "(task_id, table_id, column_id, rowkey_predicate, eligible_ts, state, retry_count, request_id) "
              "SELECT uuid_short(), %ld, %ld, %s, now(6), 0, 0, CONCAT('ai_', %ld, '_', %s) "
              "FROM dual WHERE (%s)",
              tid, cid, db_name.length(), db_name.ptr(), table_name.length(), table_name.ptr(),
              tid, cid, pred_new.ptr(), tid, pred_new.ptr(), cond.ptr()))) {
      } else if (OB_SUCC(ret) && OB_FAIL(ObAiColumnTriggerQueue::enqueue(
                     session->get_server_sid(), db_name, table_name, trg.string()))) {
        LOG_ERROR("failed to enqueue ai update trigger", K(ret), K(trg));
      } else if (OB_SUCC(ret)) {
        trg.reset();
      }
      // 5) AFTER DELETE: drop the queued tasks of the deleted row.
      if (OB_SUCC(ret) && OB_FAIL(trg.append_fmt(
              "CREATE TRIGGER `__ai_del_%ld_%ld` AFTER DELETE ON `%.*s`.`%.*s` "
              "FOR EACH ROW DELETE FROM oceanbase.__all_ai_column_task "
              "WHERE table_id = %ld AND column_id = %ld AND rowkey_predicate = %s",
              tid, cid, db_name.length(), db_name.ptr(), table_name.length(), table_name.ptr(),
              tid, cid, pred_old.ptr()))) {
      } else if (OB_SUCC(ret) && OB_FAIL(ObAiColumnTriggerQueue::enqueue(
                     session->get_server_sid(), db_name, table_name, trg.string()))) {
        LOG_ERROR("failed to enqueue ai delete trigger", K(ret), K(trg));
      }
    }
  }
  return ret;
}

static lib::ObMutex g_ai_trigger_mutex;
static common::ObSEArray<ObAiColumnTriggerQueue::TriggerReq, 16> g_ai_trigger_queue;
static common::ObArenaAllocator g_ai_trigger_alloc;

int ObAiColumnTriggerQueue::enqueue(uint64_t session_id,
                                    const common::ObString &db,
                                    const common::ObString &table,
                                    const common::ObString &body)
{
  int ret = OB_SUCCESS;
  TriggerReq req;
  lib::ObMutexGuard guard(g_ai_trigger_mutex);
  if (db.empty() || table.empty() || body.empty()) {
    ret = OB_INVALID_ARGUMENT;
  } else {
    req.session_id_ = session_id;
    if (OB_FAIL(ob_write_string(g_ai_trigger_alloc, db, req.db_))) {
    } else if (OB_FAIL(ob_write_string(g_ai_trigger_alloc, table, req.table_))) {
    } else if (OB_FAIL(ob_write_string(g_ai_trigger_alloc, body, req.body_))) {
    } else if (OB_FAIL(g_ai_trigger_queue.push_back(req))) {
    }
  }
  return ret;
}

int ObAiColumnTriggerQueue::drain_for_session(uint64_t session_id, common::ObMySQLProxy *proxy)
{
  int ret = OB_SUCCESS;
  ObSEArray<TriggerReq, 8> reqs;
  ObSEArray<TriggerReq, 8> remain;
  {
    lib::ObMutexGuard guard(g_ai_trigger_mutex);
    for (int64_t i = 0; OB_SUCC(ret) && i < g_ai_trigger_queue.count(); ++i) {
      const TriggerReq &req = g_ai_trigger_queue.at(i);
      if (req.session_id_ == session_id) {
        if (OB_FAIL(reqs.push_back(req))) {
        }
      } else if (OB_FAIL(remain.push_back(req))) {
      }
    }
    if (OB_SUCC(ret)) {
      g_ai_trigger_queue.reset();
      for (int64_t i = 0; OB_SUCC(ret) && i < remain.count(); ++i) {
        if (OB_FAIL(g_ai_trigger_queue.push_back(remain.at(i)))) {
        }
      }
    }
  }
  if (OB_SUCC(ret) && !reqs.empty() && OB_NOT_NULL(proxy)) {
    sqlclient::ObISQLConnectionGuard conn_guard;
    common::sqlclient::ObISQLConnection *conn = NULL;
    if (OB_FAIL(proxy->acquire_connection(conn_guard, 0))) {
    } else if (OB_ISNULL(conn = conn_guard.get_ptr())) {
      ret = OB_ERR_UNEXPECTED;
    }
    for (int64_t i = 0; i < reqs.count(); ++i) {
      const TriggerReq &req = reqs.at(i);
      ObSqlString use_sql;
      int64_t affected_rows = 0;
      int tmp_ret = OB_SUCCESS;
      if (OB_FAIL(use_sql.append_fmt("USE `%.*s`", req.db_.length(), req.db_.ptr()))) {
        tmp_ret = ret;
      } else if (OB_FAIL(tmp_ret = conn->execute_write(use_sql.string(), affected_rows))) {
        LOG_WARN("failed to use db for ai trigger", K(tmp_ret), K(use_sql));
      } else if (OB_FAIL(tmp_ret = conn->execute_write(req.body_, affected_rows))) {
        LOG_WARN("failed to create ai trigger", K(tmp_ret), K(req.body_));
      }
      if (OB_SUCCESS != tmp_ret && OB_SUCCESS == ret) {
        ret = tmp_ret;
      }
    }
  }
  return ret;
}

struct AiColumnTaskItem
{
  int64_t task_id_;
  int64_t table_id_;
  int64_t retry_count_;
  int64_t max_retries_;
  common::ObString db_;
  common::ObString table_;
  common::ObString column_;
  common::ObString predicate_;
  common::ObString raw_expr_;
  common::ObString normalized_expr_;
};

static __thread bool g_ai_worker_busy = false;

// The AI column spec (for example "Return exactly one valid JSON value") has to reach
// the model as the system message. AI_COMPLETE takes it as the "system_prompt" key of
// its optional third (JSON config) argument, so the stored expression is extended here.
static int build_ai_column_value_expr(const common::ObString &raw_expr,
                                      const common::ObString &normalized_expr,
                                      ObSqlString &out)
{
  int ret = OB_SUCCESS;
  int32_t close = raw_expr.length() - 1;
  while (close >= 0 && (' ' == raw_expr.ptr()[close] || ';' == raw_expr.ptr()[close])) {
    --close;
  }
  const bool is_complete = raw_expr.length() >= 12
      && 0 == strncasecmp(raw_expr.ptr(), "AI_COMPLETE(", 12);
  if (normalized_expr.empty() || !is_complete || close <= 0 || ')' != raw_expr.ptr()[close]) {
    ret = out.append(raw_expr);
  } else {
    if (OB_FAIL(out.append_fmt("%.*s, '{\"system_prompt\": \"", close, raw_expr.ptr()))) {
    }
    for (int32_t i = 0; OB_SUCC(ret) && i < normalized_expr.length(); ++i) {
      const char c = normalized_expr.ptr()[i];
      if ('\\' == c || '\'' == c || '"' == c) {
        ret = out.append_fmt("\\%c", c);
      } else {
        ret = out.append_fmt("%c", c);
      }
    }
    if (OB_SUCC(ret) && OB_FAIL(out.append_fmt("\"}')"))) {
    }
  }
  return ret;
}

// Re-assigning a row's dependency columns to their current values keeps the AI column
// triggers from invalidating the row (they only react when a dependency value changes).
// NULL-safe string fetch: nullable metadata (for example normalized_expr of a non-JSON
// AI column) must not abort the whole task batch.
static int get_ai_nullable_string(common::sqlclient::ObMySQLResult *result,
                                  const int64_t idx, ObString &out)
{
  int ret = OB_SUCCESS;
  out.reset();
  if (OB_FAIL(result->get_varchar(idx, out))) {
    ret = OB_SUCCESS;
    out.reset();
  }
  return ret;
}

static int build_ai_dep_assignments(common::ObMySQLProxy *proxy, const int64_t table_id,
                                    ObSqlString &out)
{
  int ret = OB_SUCCESS;
  ObSqlString sql;
  common::ObArenaAllocator allocator;
  ObSEArray<common::ObString, 8> seen;
  if (OB_FAIL(sql.append_fmt("SELECT DISTINCT dependency_columns FROM %s WHERE table_id = %ld",
                             OB_ALL_AI_COLUMN_TNAME, table_id))) {
  } else {
    SMART_VAR(ObMySQLProxy::MySQLResult, res) {
      common::sqlclient::ObMySQLResult *result = NULL;
      if (OB_FAIL(proxy->read(res, sql.ptr()))) {
      } else if (OB_ISNULL(result = res.get_result())) {
        ret = OB_ERR_UNEXPECTED;
      } else {
        while (OB_SUCC(ret) && OB_SUCC(result->next())) {
          ObString deps;
          if (OB_FAIL(get_ai_nullable_string(result, 0, deps))) {
            ret = OB_SUCCESS;
          } else if (deps.empty()) {
          } else {
            int32_t start = 0;
            for (int32_t i = 0; OB_SUCC(ret) && i <= deps.length(); ++i) {
              if (i == deps.length() || ',' == deps.ptr()[i]) {
                int32_t begin = start;
                int32_t end = i;
                while (begin < end && (' ' == deps.ptr()[begin] || '`' == deps.ptr()[begin])) {
                  ++begin;
                }
                while (end > begin && (' ' == deps.ptr()[end - 1] || '`' == deps.ptr()[end - 1])) {
                  --end;
                }
                if (end > begin) {
                  bool dup = false;
                  for (int64_t k = 0; !dup && k < seen.count(); ++k) {
                    if (seen.at(k).length() == end - begin
                        && 0 == strncmp(seen.at(k).ptr(), deps.ptr() + begin, end - begin)) {
                      dup = true;
                    }
                  }
                  if (!dup) {
                    ObString copy;
                    if (OB_FAIL(ob_write_string(allocator, ObString(end - begin, deps.ptr() + begin), copy))) {
                    } else if (OB_FAIL(seen.push_back(copy))) {
                    } else if (OB_FAIL(out.append_fmt("%s`%.*s` = `%.*s`", out.length() > 0 ? ", " : "",
                                                     end - begin, deps.ptr() + begin,
                                                     end - begin, deps.ptr() + begin))) {
                    }
                  }
                }
                start = i + 1;
              }
            }
          }
        }
        if (OB_ITER_END == ret) {
          ret = OB_SUCCESS;
        }
      }
    }
  }
  // The row key columns must be re-assigned as well: a trigger sees untouched NEW
  // columns as NULL, which would look like a primary key change.
  if (OB_SUCC(ret)) {
    ObSqlString rk_sql;
    if (OB_FAIL(rk_sql.append_fmt(
            "SELECT column_name FROM %s WHERE table_id = %ld AND rowkey_position > 0",
            OB_ALL_COLUMN_TNAME, table_id))) {
    } else {
      SMART_VAR(ObMySQLProxy::MySQLResult, rk_res) {
        common::sqlclient::ObMySQLResult *rk_result = NULL;
        if (OB_FAIL(proxy->read(rk_res, rk_sql.ptr()))) {
        } else if (OB_ISNULL(rk_result = rk_res.get_result())) {
          ret = OB_ERR_UNEXPECTED;
        } else {
          while (OB_SUCC(ret) && OB_SUCC(rk_result->next())) {
            ObString name;
            if (OB_FAIL(get_ai_nullable_string(rk_result, 0, name))) {
            } else if (name.empty()) {
            } else if (OB_FAIL(out.append_fmt("%s`%.*s` = `%.*s`", out.length() > 0 ? ", " : "",
                                             name.length(), name.ptr(),
                                             name.length(), name.ptr()))) {
            }
          }
          if (OB_ITER_END == ret) {
            ret = OB_SUCCESS;
          }
        }
      }
    }
  }
  return ret;
}

static int run_ai_column_tasks(common::ObMySQLProxy *proxy)
{
  int ret = OB_SUCCESS;
  common::ObArenaAllocator allocator;
  ObSEArray<AiColumnTaskItem, 8> tasks;
  ObSqlString sql;
  if (OB_FAIL(sql.append_fmt(
          "SELECT t.task_id, t.retry_count, a.max_retries, a.raw_expr, a.column_name, "
          "d.database_name, tb.table_name, t.rowkey_predicate, a.normalized_expr, t.table_id "
          "FROM %s t "
          "JOIN %s a ON a.table_id = t.table_id AND a.column_id = t.column_id "
          "JOIN %s tb ON tb.table_id = t.table_id "
          "JOIN %s d ON d.database_id = tb.database_id "
          "WHERE (t.state IN (0, 3) AND t.eligible_ts <= now(6)) "
          "OR (t.state = 1 AND t.eligible_ts < now(6) - interval 60 second) "
          "ORDER BY t.task_id LIMIT 8",
          OB_ALL_AI_COLUMN_TASK_TNAME,
          OB_ALL_AI_COLUMN_TNAME,
          OB_ALL_TABLE_TNAME,
          OB_ALL_DATABASE_TNAME))) {
  } else {
    SMART_VAR(ObMySQLProxy::MySQLResult, res) {
      common::sqlclient::ObMySQLResult *result = NULL;
      if (OB_FAIL(proxy->read(res, sql.ptr()))) {
        LOG_WARN("failed to query ai column tasks", K(ret), K(sql));
      } else if (OB_ISNULL(result = res.get_result())) {
        ret = OB_ERR_UNEXPECTED;
      } else {
        while (OB_SUCC(ret) && OB_SUCC(result->next())) {
          AiColumnTaskItem item;
          ObString cel;
          int64_t i64 = 0;
          if (OB_FAIL(result->get_int(static_cast<int64_t>(0), i64))) {
          } else if (FALSE_IT(item.task_id_ = i64)) {
          } else if (OB_FAIL(result->get_int(static_cast<int64_t>(1), i64))) {
          } else if (FALSE_IT(item.retry_count_ = i64)) {
          } else if (OB_FAIL(result->get_int(static_cast<int64_t>(2), i64))) {
          } else if (FALSE_IT(item.max_retries_ = i64)) {
          } else if (OB_FAIL(get_ai_nullable_string(result, 3, cel))
                     || OB_FAIL(ob_write_string(allocator, cel, item.raw_expr_))) {
          } else if (OB_FAIL(get_ai_nullable_string(result, 4, cel))
                     || OB_FAIL(ob_write_string(allocator, cel, item.column_))) {
          } else if (OB_FAIL(get_ai_nullable_string(result, 5, cel))
                     || OB_FAIL(ob_write_string(allocator, cel, item.db_))) {
          } else if (OB_FAIL(get_ai_nullable_string(result, 6, cel))
                     || OB_FAIL(ob_write_string(allocator, cel, item.table_))) {
          } else if (OB_FAIL(get_ai_nullable_string(result, 7, cel))
                     || OB_FAIL(ob_write_string(allocator, cel, item.predicate_))) {
          } else if (OB_FAIL(get_ai_nullable_string(result, 8, cel))
                     || OB_FAIL(ob_write_string(allocator, cel, item.normalized_expr_))) {
          } else if (OB_FAIL(result->get_int(static_cast<int64_t>(9), i64))) {
          } else if (FALSE_IT(item.table_id_ = i64)) {
          } else if (OB_FAIL(tasks.push_back(item))) {
          }
        }
        if (OB_ITER_END == ret) {
          ret = OB_SUCCESS;
        }
      }
    }
  }
  if (OB_SUCC(ret) && !tasks.empty()) {
    sqlclient::ObISQLConnectionGuard conn_guard;
    common::sqlclient::ObISQLConnection *conn = NULL;
    if (OB_FAIL(proxy->acquire_connection(conn_guard, 0))) {
    } else if (OB_ISNULL(conn = conn_guard.get_ptr())) {
      ret = OB_ERR_UNEXPECTED;
    }
    if (OB_SUCC(ret)) {
      ObSqlString set_sql;
      int64_t ignored = 0;
      if (OB_FAIL(set_sql.append_fmt(
              "SET SESSION ob_query_timeout = 3000000, ob_trx_lock_timeout = 100000"))) {
      } else if (OB_FAIL(conn->execute_write(set_sql.string(), ignored))) {
        ret = OB_SUCCESS;
      }
    }
    // Claim every task first: a task can be owned by exactly one worker, otherwise the same
    // model request would be executed twice.
    int64_t claimed[8];
    int64_t claimed_cnt = 0;
    bool used[8];
    MEMSET(used, 0, sizeof(used));
    for (int64_t i = 0; OB_SUCC(ret) && i < tasks.count() && i < 8; ++i) {
      const AiColumnTaskItem &item = tasks.at(i);
      ObSqlString claim;
      int64_t claimed_rows = 0;
      if (OB_FAIL(claim.append_fmt("UPDATE %s SET state = 1 WHERE task_id = %ld AND state IN (0, 3)",
                                   OB_ALL_AI_COLUMN_TASK_TNAME, item.task_id_))) {
      } else if (OB_FAIL(conn->execute_write(claim.string(), claimed_rows))) {
        LOG_WARN("failed to claim ai column task", K(ret), K(claim));
      } else if (1 == claimed_rows) {
        claimed[claimed_cnt++] = i;
      }
    }
    // Publish one row group at a time: every AI column of the same row is written by a
    // single UPDATE, so the results of one change become visible atomically.
    for (int64_t g = 0; OB_SUCC(ret) && g < claimed_cnt; ++g) {
      if (used[g]) {
        continue;
      }
      used[g] = true;
      const AiColumnTaskItem &head = tasks.at(claimed[g]);
      int64_t members[8];
      int64_t member_cnt = 0;
      members[member_cnt++] = claimed[g];
      for (int64_t h = g + 1; h < claimed_cnt; ++h) {
        if (used[h]) {
          continue;
        }
        const AiColumnTaskItem &other = tasks.at(claimed[h]);
        if (other.table_id_ == head.table_id_
            && 0 == other.db_.compare(head.db_)
            && 0 == other.table_.compare(head.table_)
            && 0 == other.predicate_.compare(head.predicate_)) {
          used[h] = true;
          members[member_cnt++] = claimed[h];
        }
      }
      ObSqlString upd;
      ObSqlString dep_assignments;
      if (OB_FAIL(upd.append_fmt("UPDATE `%.*s`.`%.*s` SET ",
                                 head.db_.length(), head.db_.ptr(),
                                 head.table_.length(), head.table_.ptr()))) {
      }
      for (int64_t m = 0; OB_SUCC(ret) && m < member_cnt; ++m) {
        const AiColumnTaskItem &item = tasks.at(members[m]);
        ObSqlString value_expr;
        if (OB_FAIL(build_ai_column_value_expr(item.raw_expr_, item.normalized_expr_, value_expr))) {
        } else if (OB_FAIL(upd.append_fmt("%s`%.*s` = (%.*s)", 0 == m ? "" : ", ",
                                          item.column_.length(), item.column_.ptr(),
                                          value_expr.length(), value_expr.ptr()))) {
        }
      }
      if (OB_SUCC(ret) && OB_FAIL(build_ai_dep_assignments(proxy, head.table_id_, dep_assignments))) {
      } else if (OB_SUCC(ret) && dep_assignments.length() > 0
                 && OB_FAIL(upd.append_fmt(", %s", dep_assignments.ptr()))) {
      } else if (OB_SUCC(ret) && OB_FAIL(upd.append_fmt(" WHERE %.*s",
                                                       head.predicate_.length(), head.predicate_.ptr()))) {
      }
      if (OB_SUCC(ret)) {
        int64_t affected_rows = 0;
        int tmp_ret = conn->execute_write(upd.string(), affected_rows);
        ObSqlString fix;
        if (OB_SUCCESS != tmp_ret) {
          LOG_WARN("ai column group evaluation failed", K(tmp_ret), K(upd));
          // A row locked by an open transaction is not a model failure: keep the task pending
          // and retry later instead of burning the retry budget.
          const bool deferred = (OB_TRY_LOCK_ROW_CONFLICT == tmp_ret || OB_TIMEOUT == tmp_ret
                                 || OB_TRANS_STMT_NEED_RETRY == tmp_ret);
          for (int64_t m = 0; m < member_cnt; ++m) {
            const AiColumnTaskItem &item = tasks.at(members[m]);
            if (deferred) {
              fix.append_fmt("UPDATE %s SET state = 0, "
                             "eligible_ts = now(6) + interval 1 second WHERE task_id = %ld;",
                             OB_ALL_AI_COLUMN_TASK_TNAME, item.task_id_);
            } else if (item.retry_count_ + 1 > item.max_retries_) {
              fix.append_fmt("DELETE FROM %s WHERE task_id = %ld;",
                             OB_ALL_AI_COLUMN_TASK_TNAME, item.task_id_);
            } else {
              fix.append_fmt("UPDATE %s SET retry_count = %ld, state = 3, "
                             "eligible_ts = now(6) + interval 1 second WHERE task_id = %ld;",
                             OB_ALL_AI_COLUMN_TASK_TNAME, item.retry_count_ + 1, item.task_id_);
            }
          }
        } else {
          fix.append_fmt("DELETE FROM %s WHERE task_id IN (", OB_ALL_AI_COLUMN_TASK_TNAME);
          for (int64_t m = 0; m < member_cnt; ++m) {
            fix.append_fmt("%s%ld", 0 == m ? "" : ", ", tasks.at(members[m]).task_id_);
          }
          fix.append_fmt(")");
        }
        int64_t row_affected = 0;
        if (OB_FAIL(conn->execute_write(fix.string(), row_affected))) {
          LOG_WARN("failed to update ai column task state", K(ret), K(fix));
          ret = OB_SUCCESS;
        }
      }
    }
  }

  return ret;
}

// Rows of the AI column that still have no value (pending or finally failed).
static int count_ai_column_null_rows(common::ObMySQLProxy *proxy,
                                     share::schema::ObSchemaGetterGuard &guard,
                                     const share::schema::ObTableSchema &table_schema,
                                     const share::schema::ObColumnSchemaV2 &column,
                                     int64_t &null_rows)
{
  int ret = OB_SUCCESS;
  const share::schema::ObDatabaseSchema *db_schema = NULL;
  null_rows = 0;
  ObSqlString sql;
  if (OB_ISNULL(proxy)) {
    ret = OB_NOT_INIT;
  } else if (OB_FAIL(guard.get_database_schema(table_schema.get_database_id(), db_schema))) {
  } else if (OB_ISNULL(db_schema)) {
    ret = OB_ERR_UNEXPECTED;
  } else if (OB_FAIL(sql.append_fmt("SELECT count(*) FROM `%.*s`.`%.*s` WHERE `%.*s` IS NULL",
                                    db_schema->get_database_name_str().length(),
                                    db_schema->get_database_name_str().ptr(),
                                    table_schema.get_table_name_str().length(),
                                    table_schema.get_table_name_str().ptr(),
                                    column.get_column_name_str().length(),
                                    column.get_column_name_str().ptr()))) {
  } else {
    SMART_VAR(ObMySQLProxy::MySQLResult, res) {
      common::sqlclient::ObMySQLResult *result = NULL;
      if (OB_FAIL(proxy->read(res, sql.ptr()))) {
      } else if (OB_ISNULL(result = res.get_result())) {
        ret = OB_ERR_UNEXPECTED;
      } else if (OB_FAIL(result->next())) {
        if (OB_ITER_END == ret) {
          ret = OB_SUCCESS;
        }
      } else if (OB_FAIL(result->get_int(static_cast<int64_t>(0), null_rows))) {
      }
    }
  }
  return ret;
}

// Number of not-yet-published tasks of one AI column of one table.
static int count_pending_ai_tasks(common::ObMySQLProxy *proxy, const uint64_t table_id,
                                  const uint64_t column_id, int64_t &pending_cnt)
{
  int ret = OB_SUCCESS;
  ObSqlString sql;
  pending_cnt = 0;
  if (OB_ISNULL(proxy)) {
    ret = OB_NOT_INIT;
  } else if (OB_FAIL(sql.append_fmt("SELECT count(*) FROM %s WHERE table_id = %lu AND column_id = %lu",
                                    OB_ALL_AI_COLUMN_TASK_TNAME, table_id, column_id))) {
  } else {
    SMART_VAR(ObMySQLProxy::MySQLResult, res) {
      common::sqlclient::ObMySQLResult *result = NULL;
      if (OB_FAIL(proxy->read(res, sql.ptr()))) {
      } else if (OB_ISNULL(result = res.get_result())) {
        ret = OB_ERR_UNEXPECTED;
      } else if (OB_FAIL(result->next())) {
        if (OB_ITER_END == ret) {
          ret = OB_SUCCESS;
        }
      } else if (OB_FAIL(result->get_int(static_cast<int64_t>(0), pending_cnt))) {
      }
    }
  }
  return ret;
}

int ObAiColumnStrictRead::check(ObSQLSessionInfo *session,
                                const uint64_t table_id,
                                const common::ObIArray<uint64_t> &column_ids)
{
  int ret = OB_SUCCESS;
  bool strict_read = false;
  if (OB_ISNULL(session) || OB_INVALID_ID == table_id || column_ids.empty()) {
  } else if (OB_FAIL(session->get_sys_variable(share::SYS_VAR_AI_COLUMN_STRICT_READ, strict_read))) {
  } else if (!strict_read) {
  } else {
    share::schema::ObSchemaGetterGuard guard;
    const share::schema::ObTableSchema *table_schema = NULL;
    if (OB_ISNULL(GCTX.schema_service_)) {
      ret = OB_ERR_UNEXPECTED;
    } else if (OB_FAIL(GCTX.schema_service_->get_runtime_schema_guard(guard))) {
    } else if (OB_FAIL(guard.get_table_schema(table_id, table_schema))) {
    } else if (OB_ISNULL(table_schema)) {
      ret = OB_ERR_UNEXPECTED;
    } else {
      for (int64_t i = 0; OB_SUCC(ret) && i < column_ids.count(); ++i) {
        const share::schema::ObColumnSchemaV2 *column =
            table_schema->get_column_schema(column_ids.at(i));
        if (OB_ISNULL(column)) {
        } else if (column->is_hidden()) {
        } else {
          ObString column_name = column->get_column_name_str();
          char state_name[OB_MAX_COLUMN_NAME_LENGTH];
          int64_t state_len = snprintf(state_name, sizeof(state_name), "__ai_state_%.*s",
                                       column_name.length(), column_name.ptr());
          if (OB_NOT_NULL(table_schema->get_column_schema(
                  ObString(static_cast<int32_t>(state_len), state_name)))) {
            int64_t pending = 0;
            int64_t not_ready_rows = 0;
            if (OB_FAIL(count_pending_ai_tasks(GCTX.sql_proxy_, table_id,
                                               column->get_column_id(), pending))) {
            } else if (pending > 0) {
              ret = OB_AI_COLUMN_NOT_READY;
              LOG_USER_ERROR(OB_AI_COLUMN_NOT_READY, table_id, column->get_column_id());
            } else if (OB_FAIL(count_ai_column_null_rows(GCTX.sql_proxy_, guard, *table_schema,
                                                         *column, not_ready_rows))) {
            } else if (not_ready_rows > 0) {
              // a row whose result is NULL without a pending task reached its final failed state
              ret = OB_AI_COLUMN_NOT_READY;
              LOG_USER_ERROR(OB_AI_COLUMN_NOT_READY, table_id, column->get_column_id());
            }
          }
        }
      }
    }
  }
  return ret;
}

static volatile bool g_ai_worker_thread_started = false;
static volatile bool g_ai_worker_thread_stop = false;

// The first AI model DDL of a fresh observer pays a one-time lazy initialization cost that
// can exceed the 10s statement timeout on a loaded CI machine. Touch the same path once,
// right after the server starts serving, so that user statements never pay for it.
static void warm_up_ai_service_once(common::ObMySQLProxy *proxy)
{
  int ret = OB_SUCCESS;
  sqlclient::ObISQLConnectionGuard conn_guard;
  common::sqlclient::ObISQLConnection *conn = NULL;
  int64_t affected_rows = 0;
  if (OB_ISNULL(proxy)) {
    ret = OB_NOT_INIT;
  } else if (OB_FAIL(proxy->acquire_connection(conn_guard, 0))) {
  } else if (OB_ISNULL(conn = conn_guard.get_ptr())) {
    ret = OB_ERR_UNEXPECTED;
  } else {
    // the model does not exist, the error is the expected outcome
    (void)conn->execute_write("CALL DBMS_AI_SERVICE.DROP_AI_MODEL('__seekdb_ai_warmup__')",
                              affected_rows);
  }
  if (OB_SUCCESS != ret) {
    LOG_INFO("ai service warm up skipped", K(ret));
  }
}

static void *ai_column_worker_loop(void *arg)
{
  UNUSED(arg);
  bool warmed_up = false;
  while (!g_ai_worker_thread_stop) {
    if (!GCTX.in_bootstrap_ && share::SS_SERVING == GCTX.status_ && OB_NOT_NULL(GCTX.sql_proxy_)) {
      if (!warmed_up) {
        warm_up_ai_service_once(GCTX.sql_proxy_);
        warmed_up = true;
      }
      int ret = ObAiColumnWorker::run_pending(GCTX.sql_proxy_);
      if (OB_SUCCESS != ret) {
        LOG_WARN("ai column background worker pass failed", K(ret));
      }
    }
    usleep(200 * 1000L);
  }
  return NULL;
}

void ObAiColumnWorker::ensure_background_thread_started()
{
  int ret = OB_SUCCESS;  // LOG_WARN expands to code referencing ret
  if (!g_ai_worker_thread_started) {
    static lib::ObMutex start_mutex;
    lib::ObMutexGuard guard(start_mutex);
    if (!g_ai_worker_thread_started) {
      pthread_t tid;
      int err = 0;
      if (0 == (err = pthread_create(&tid, NULL, ai_column_worker_loop, NULL))) {
        pthread_detach(tid);
        g_ai_worker_thread_started = true;
        LOG_INFO("ai column background worker started");
      } else {
        ret = OB_ERR_UNEXPECTED;
        LOG_WARN("failed to start ai column background worker", K(ret), K(err));
      }
    }
  }
}

int ObAiColumnWorker::run_pending(common::ObMySQLProxy *proxy)
{
  int ret = OB_SUCCESS;
  if (OB_ISNULL(proxy)) {
    ret = OB_NOT_INIT;
  } else if (GCTX.in_bootstrap_ || share::SS_SERVING != GCTX.status_) {
    // never touch inner tables before the server finished bootstrap
  } else if (g_ai_worker_busy) {
    // re-entrant call: inner statements issued by the worker itself land here
  } else {
    g_ai_worker_busy = true;
    if (OB_FAIL(run_ai_column_tasks(proxy))) {
      LOG_WARN("failed to run ai column tasks", K(ret));
    }
    g_ai_worker_busy = false;
  }
  return ret;
}

int ObCreateTableExecutor::set_index_arg_list(ObExecContext &ctx, ObCreateTableStmt &stmt)
{
  int ret = OB_SUCCESS;
  obcall::ObCreateTableArg &create_table_arg = const_cast<obcall::ObCreateTableArg &>(stmt.get_create_table_arg());
  if (stmt.get_index_partition_resolve_results().count()
      != stmt.get_index_arg_list().count()) {
    ret = OB_ERR_UNEXPECTED;
  }
  for (int64_t i = 0; OB_SUCC(ret) && i < stmt.get_index_arg_list().count(); i++) {
    HEAP_VAR(ObCreateIndexStmt, index_stmt) {
      ObPartitionResolveResult &resolve_result = stmt.get_index_partition_resolve_results().at(i);
      index_stmt.get_part_fun_exprs() = resolve_result.get_part_fun_exprs();
      index_stmt.get_part_values_exprs() = resolve_result.get_part_values_exprs();
      index_stmt.get_subpart_fun_exprs() = resolve_result.get_subpart_fun_exprs();
      index_stmt.get_template_subpart_values_exprs() = resolve_result.get_template_subpart_values_exprs();
      index_stmt.get_individual_subpart_values_exprs() = resolve_result.get_individual_subpart_values_exprs();
      if (OB_FAIL(index_stmt.get_create_index_arg().assign(stmt.get_index_arg_list().at(i)))) {
      } else if (OB_FAIL(ObPartitionExecutorUtils::calc_values_exprs(ctx, index_stmt))) {
      } else if (OB_FAIL(create_table_arg.index_arg_list_.push_back(index_stmt.get_create_index_arg()))) {
      }
    }
  }
  return ret;
}

ObAlterTableExecutor::ObAlterTableExecutor()
{
}

ObAlterTableExecutor::~ObAlterTableExecutor()
{
}

int ObAlterTableExecutor::refresh_schema_for_table()
{
  int ret = OB_SUCCESS;
  share::schema::ObSchemaGetterGuard schema_guard;
  const ObGlobalContext &gctx = GCTX;
  ObMultiVersionSchemaService *schema_service = gctx.schema_service_;
  int64_t local_version = OB_INVALID_VERSION;
  int64_t global_version = OB_INVALID_VERSION;

  if (OB_ISNULL(schema_service)) {
    ret = OB_ERR_UNEXPECTED;
  } else if (OB_FAIL(schema_service->get_runtime_refreshed_schema_version(
          local_version))) {
  } else if (OB_FAIL(schema_service->get_published_schema_version(
          global_version))) {
  } else if (local_version < global_version) {
    LOG_INFO("try to refresh schema", K(local_version), K(global_version));
    // force refresh schema latest version
    if (OB_FAIL(schema_service->refresh_and_add_schema())) {
    }
  }
  return ret;
}

/* From version 3100 onwards, the alter table logic is to put index creation and other operations into the same rpc sent to rs, and after returning, synchronize each created index, etc., if an index creation fails, roll back all indexes
   MySQL mode supports alter table to perform index creation operations and other operations simultaneously, need to ensure that rs processes drop index after processing add index
   Otherwise, prefix indexes will have issues:
*/
int ObAlterTableExecutor::alter_table_rpc_v2(
    obcall::ObAlterTableArg &alter_table_arg,
    obcall::ObAlterTableRes &res,
    common::ObIAllocator &allocator,
    ObSQLSessionInfo *my_session,
    query::ObIRootCommandService &root_commands,
    query::ObIQueryRuntimeEnvironment &runtime_environment,
    query::ObILocalCommandService &local_commands)
{
  int ret = OB_SUCCESS;
  // do not support cancel drop_index_task.
  bool is_support_cancel = true;
  const ObSArray<obcall::ObIndexArg *> index_arg_list = alter_table_arg.index_arg_list_;
  ObSArray<obcall::ObIndexArg *> add_index_arg_list;
  ObSArray<obcall::ObIndexArg *> drop_index_args;
  alter_table_arg.index_arg_list_.reset();
  
  if (OB_ISNULL(my_session)) {
    ret = OB_INVALID_ARGUMENT;
  } else {
  }
  for (int64_t i = 0; OB_SUCC(ret) && i < index_arg_list.size(); ++i) {
    obcall::ObIndexArg *index_arg = index_arg_list.at(i);
    if (OB_ISNULL(index_arg)) {
      ret = OB_INVALID_ARGUMENT;
    } else if (obcall::ObIndexArg::ADD_INDEX == index_arg->index_action_type_) {
      if (OB_FAIL(add_index_arg_list.push_back(index_arg))) {
      }
    } else if (obcall::ObIndexArg::DROP_INDEX == index_arg->index_action_type_) {
      if (OB_FAIL(drop_index_args.push_back(index_arg))) {
      } else if (OB_FAIL(alter_table_arg.index_arg_list_.push_back(index_arg))) {
      } else {
        obcall::ObDropIndexArg *drop_index_arg =
            static_cast<obcall::ObDropIndexArg *>(index_arg);
        drop_index_arg->is_add_to_scheduler_ = true;
        is_support_cancel = false;
      }
    } else { // for rename/drop index action
      if (OB_FAIL(alter_table_arg.index_arg_list_.push_back(index_arg))) {
      }
    }
  }
  // for add index action
  for (int64_t i = 0; OB_SUCC(ret) && i < add_index_arg_list.size(); ++i) {
    if (OB_FAIL(alter_table_arg.index_arg_list_.push_back(add_index_arg_list.at(i)))) {
    }
  }
  if (OB_SUCC(ret)) {
    AlterTableSchema &alter_table_schema = const_cast<AlterTableSchema &>(alter_table_arg.alter_table_schema_);
    if (OB_FAIL(populate_based_schema_obj_info_(alter_table_arg))) {
    } else {
      alter_table_arg.data_version_ = DATA_CURRENT_VERSION;
    }
    DEBUG_SYNC(BEFORE_SEND_ALTER_TABLE);

    if (OB_FAIL(ret)) {
    } else if (OB_FAIL(query::serialize_root_service_call(
                   [&]{ return root_commands.alter_table(alter_table_arg, res); }))) {
    } else {
      // In rollback, retries will not be attempted, nor will the schema version be checked
      alter_table_arg.based_schema_object_infos_.reset();
    }
  }

  if (OB_SUCC(ret)) {
    ObIArray<obcall::ObDDLRes> &ddl_ress = res.ddl_res_array_;
    for (int64_t i = 0; OB_SUCC(ret) && i < ddl_ress.count(); ++i) {
      obcall::ObDDLRes &ddl_res = ddl_ress.at(i);
      if (!alter_table_arg.is_update_global_indexes_ && OB_FAIL(ObDDLExecutorUtil::wait_ddl_finish(
          ddl_res.task_id_, res.ddl_need_retry_at_executor_, my_session,
          runtime_environment, local_commands, is_support_cancel))) {
      }
    }
  }

  if (OB_SUCC(ret)) {
    ObCreateIndexExecutor create_index_executor;
    uint64_t failed_index_no = OB_INVALID_ID;
    // Handling of global index for drop/truncate partition
    if (alter_table_arg.is_update_global_indexes_
        && (obcall::ObAlterTableArg::DROP_PARTITION == alter_table_arg.alter_part_type_
        || obcall::ObAlterTableArg::DROP_SUB_PARTITION == alter_table_arg.alter_part_type_
        || obcall::ObAlterTableArg::TRUNCATE_PARTITION == alter_table_arg.alter_part_type_
        || obcall::ObAlterTableArg::TRUNCATE_SUB_PARTITION == alter_table_arg.alter_part_type_)) {
      common::ObSArray<obcall::ObAlterTableResArg> &res_array = res.res_arg_array_;
      for (int64_t i = 0; OB_SUCC(ret) && i < res_array.size(); ++i) {
        SMART_VAR(obcall::ObCreateIndexArg, create_index_arg) {
          create_index_arg.index_schema_.set_table_id(res_array.at(i).schema_id_);
          create_index_arg.index_schema_.set_schema_version(res_array.at(i).schema_version_);
          if (OB_FAIL(create_index_executor.sync_check_index_status(
              *my_session, root_commands, create_index_arg, res, allocator))) {
          }
        }
      }
    } else if (res.ddl_res_array_.empty()) {
    } else if (is_create_index(res.ddl_type_) || DDL_NORMAL_TYPE == res.ddl_type_) {
      // TODO(shuangcan): alter table create index returns DDL_NORMAL_TYPE now, check if we can fix this later
      // Synchronize until index creation is successful
      for (int64_t i = 0; OB_SUCC(ret) && i < add_index_arg_list.size(); ++i) {
        obcall::ObIndexArg *index_arg = add_index_arg_list.at(i);
        obcall::ObCreateIndexArg *create_index_arg = NULL;
        if (OB_ISNULL(index_arg)) {
          ret = OB_ERR_UNEXPECTED;
        } else if (obcall::ObIndexArg::ADD_INDEX != index_arg->index_action_type_) {
          ret = OB_ERR_UNEXPECTED;
        } else if (OB_ISNULL(create_index_arg = static_cast<obcall::ObCreateIndexArg *>(index_arg))) {
          ret = OB_ERR_UNEXPECTED;
        } else if (INDEX_TYPE_PRIMARY == create_index_arg->index_type_ ||
            is_fts_index(create_index_arg->index_type_) ||
            is_multivalue_index(create_index_arg->index_type_)) {
          // TODO yunshan.tys temporary bypass, since res.res_arg_array_ is empty
          // TODO yunyi temporary bypass, since res.res_arg_array_ is empty
        } else {
          create_index_arg->index_schema_.set_table_id(res.res_arg_array_.at(i).schema_id_);
          create_index_arg->index_schema_.set_schema_version(res.res_arg_array_.at(i).schema_version_);
          if (OB_FAIL(create_index_executor.sync_check_index_status(
              *my_session, root_commands, *create_index_arg, res, allocator))) {
            failed_index_no = i;
          }
        }
      }
      // Rollback all established index
      if (OB_FAIL(ret)) {
        int tmp_ret = OB_SUCCESS;
        
        for (int64_t i = 0; (OB_SUCCESS == tmp_ret) && (i < add_index_arg_list.size()); ++i) {
          if (failed_index_no == i) {
            // Synchronization index building logic has already deleted this failure
            continue;
          } else {
            obcall::ObDropIndexArg drop_index_arg;
            obcall::ObDropIndexRes drop_index_res;
            obcall::ObCreateIndexArg *create_index_arg = static_cast<obcall::ObCreateIndexArg *>(add_index_arg_list.at(i));
            
            
            drop_index_arg.index_table_id_ = res.res_arg_array_.at(i).schema_id_;
            drop_index_arg.session_id_ = create_index_arg->session_id_;
            drop_index_arg.index_name_ = create_index_arg->index_name_;
            drop_index_arg.table_name_ = create_index_arg->table_name_;
            drop_index_arg.database_name_ = create_index_arg->database_name_;
            drop_index_arg.index_action_type_ = obcall::ObIndexArg::DROP_INDEX;
            drop_index_arg.is_add_to_scheduler_ = false;
            if (OB_SUCCESS != (tmp_ret = create_index_executor.set_drop_index_stmt_str(drop_index_arg, allocator))) {
            } else if (OB_SUCCESS != (tmp_ret = query::serialize_root_service_call(
                           [&]{ return root_commands.drop_index(drop_index_arg, drop_index_res); }))) {
            }
          }
        }
        if (OB_SUCCESS != tmp_ret && OB_INVALID_ID != failed_index_no) {    // rewrite LOG_USER_ERROR message
          uint64_t index_table_id = res.res_arg_array_.at(failed_index_no).schema_id_;
          int64_t schema_version = res.res_arg_array_.at(failed_index_no).schema_version_;
          bool is_finish = false;
          if (OB_SUCCESS != (tmp_ret = ObDDLExecutorUtil::wait_build_index_finish( res.task_id_, is_finish))) {
          }
        }
        LOG_INFO("added indexes failed, we rolled back all indexes added in this same alter table sql. But we didn't roll back other actions in this same alter table sql");
      }
    }
  }

  return ret;
}

int ObAlterTableExecutor::alter_table_exchange_partition_rpc(obcall::ObExchangePartitionArg &exchange_partition_arg,
                                                             obcall::ObAlterTableRes &res,
                                                             ObSQLSessionInfo *my_session,
                                                             query::ObIRootCommandService &root_commands)
{
  int ret = OB_SUCCESS;
  if (OB_ISNULL(my_session) || OB_UNLIKELY(!exchange_partition_arg.is_valid())) {
    ret = OB_INVALID_ARGUMENT;
  } else if (OB_FAIL(query::serialize_root_service_call(
                 [&]{ return root_commands.exchange_partition(exchange_partition_arg, res); }))) {
  } else {
    // In rollback, retries will not be attempted, nor will the schema version be checked
    exchange_partition_arg.based_schema_object_infos_.reset();
  }
  return ret;
}


// In a RETRY AI COLUMN predicate the bare word "status" is the AI state pseudo column
// (READY / FAILED), while a backtick quoted `status` refers to the business column.
static int rewrite_ai_retry_status(const ObString &sql, const ObString &result_column,
                                   ObSqlString &out)
{
  int ret = OB_SUCCESS;
  int32_t i = 0;
  while (OB_SUCC(ret) && i < sql.length()) {
    const char c = sql.ptr()[i];
    if ('\'' == c) {
      if (OB_FAIL(out.append_fmt("%c", c))) {
      } else {
        ++i;
        while (OB_SUCC(ret) && i < sql.length()) {
          const char d = sql.ptr()[i];
          if (OB_FAIL(out.append_fmt("%c", d))) {
          } else {
            ++i;
            if ('\'' == d) {
              if (i < sql.length() && '\'' == sql.ptr()[i]) {
                ret = out.append_fmt("%c", static_cast<char>('\''));
                ++i;
              } else {
                break;
              }
            }
          }
        }
      }
    } else if ('`' == c) {
      const int32_t start = i++;
      while (i < sql.length() && '`' != sql.ptr()[i]) {
        ++i;
      }
      if (i < sql.length()) {
        ++i;
      }
      if (OB_FAIL(out.append(sql.ptr() + start, i - start))) {
      }
    } else if (isalpha(static_cast<unsigned char>(c)) || '_' == c) {
      const int32_t start = i;
      while (i < sql.length()
             && (isalnum(static_cast<unsigned char>(sql.ptr()[i])) || '_' == sql.ptr()[i])) {
        ++i;
      }
      ObString word(i - start, sql.ptr() + start);
      const bool qualified = start > 0 && '.' == sql.ptr()[start - 1];
      if (!qualified && 0 == word.case_compare("status")) {
        if (OB_FAIL(out.append_fmt("(CASE WHEN `%.*s` IS NOT NULL THEN 'READY' ELSE 'FAILED' END)",
                                   result_column.length(), result_column.ptr()))) {
        }
      } else if (OB_FAIL(out.append(word))) {
      }
    } else if (OB_FAIL(out.append_fmt("%c", c))) {
    } else {
      ++i;
    }
  }
  return ret;
}

int ObAlterTableExecutor::do_ai_column_retry(ObExecContext &ctx, ObAlterTableStmt &stmt)
{
  int ret = OB_SUCCESS;
  ObMySQLProxy *proxy = ctx.get_sql_proxy();
  obcall::ObAlterTableArg &arg = stmt.get_alter_table_arg();
  const uint64_t table_id = arg.alter_table_schema_.get_table_id();
  share::schema::ObSchemaGetterGuard guard;
  const share::schema::ObTableSchema *table_schema = NULL;
  const share::schema::ObDatabaseSchema *db_schema = NULL;
  const ObString &column_name = stmt.get_ai_retry_column();
  const ObString &raw_where = stmt.get_ai_retry_where();
  ObSqlString where_buf;
  if (OB_FAIL(rewrite_ai_retry_status(raw_where, column_name, where_buf))) {
  }
  const ObString where_sql = where_buf.string();
  const share::schema::ObColumnSchemaV2 *result_column = NULL;
  ObSqlString rowkey_expr;
  int64_t max_rk_pos = 0;
  if (OB_ISNULL(proxy) || OB_INVALID_ID == table_id || where_sql.empty()) {
    ret = OB_ERR_UNEXPECTED;
  } else if (OB_ISNULL(GCTX.schema_service_)) {
    ret = OB_ERR_UNEXPECTED;
  } else if (OB_FAIL(GCTX.schema_service_->get_runtime_schema_guard(guard))) {
  } else if (OB_FAIL(guard.get_table_schema(table_id, table_schema)) || OB_ISNULL(table_schema)) {
    ret = OB_ERR_UNEXPECTED;
  } else if (OB_ISNULL(result_column = table_schema->get_column_schema(column_name))) {
    ret = OB_ERR_BAD_FIELD_ERROR;
  } else if (OB_FAIL(guard.get_database_schema(table_schema->get_database_id(), db_schema))
             || OB_ISNULL(db_schema)) {
    ret = OB_ERR_UNEXPECTED;
  }
  const share::schema::ObTableSchema &schema = *table_schema;
  const ObString &db_name = db_schema->get_database_name_str();
  const ObString &table_name = schema.get_table_name_str();
  for (int64_t i = 0; OB_SUCC(ret) && i < schema.get_column_count(); ++i) {
    const share::schema::ObColumnSchemaV2 *c = schema.get_column_schema_by_idx(i);
    if (OB_NOT_NULL(c) && c->get_rowkey_position() > max_rk_pos) {
      max_rk_pos = c->get_rowkey_position();
    }
  }
  if (OB_SUCC(ret) && max_rk_pos <= 0) {
    ret = OB_ERR_UNEXPECTED;
  } else if (OB_SUCC(ret) && OB_FAIL(rowkey_expr.append_fmt("CONCAT("))) {
  } else if (OB_SUCC(ret)) {
    for (int64_t pos = 1; OB_SUCC(ret) && pos <= max_rk_pos; ++pos) {
      const share::schema::ObColumnSchemaV2 *col = NULL;
      for (int64_t i = 0; OB_ISNULL(col) && i < schema.get_column_count(); ++i) {
        const share::schema::ObColumnSchemaV2 *c = schema.get_column_schema_by_idx(i);
        if (OB_NOT_NULL(c) && c->get_rowkey_position() == pos) {
          col = c;
        }
      }
      if (OB_ISNULL(col)) {
        ret = OB_ERR_UNEXPECTED;
      } else if (OB_FAIL(rowkey_expr.append_fmt("%s'`%s` = ', %s", pos > 1 ? ", ' and '" : "",
                                                col->get_column_name(), col->get_column_name()))) {
      }
    }
    if (OB_SUCC(ret) && OB_FAIL(rowkey_expr.append_fmt(")"))) {
    }
  }
  if (OB_SUCC(ret)) {
    sqlclient::ObISQLConnectionGuard conn_guard;
    common::sqlclient::ObISQLConnection *conn = NULL;
    ObSqlString invalidate_sql;
    ObSqlString enqueue_sql;
    int64_t affected_rows = 0;
    if (OB_FAIL(proxy->acquire_connection(conn_guard, 0))) {
    } else if (OB_ISNULL(conn = conn_guard.get_ptr())) {
      ret = OB_ERR_UNEXPECTED;
    } else if (OB_FAIL(invalidate_sql.append_fmt(
                   "UPDATE `%.*s`.`%.*s` SET `%.*s` = NULL WHERE %.*s",
                   db_name.length(), db_name.ptr(), table_name.length(), table_name.ptr(),
                   column_name.length(), column_name.ptr(),
                   where_sql.length(), where_sql.ptr()))) {
    } else if (OB_FAIL(conn->execute_write(invalidate_sql.string(), affected_rows))) {
      LOG_WARN("failed to invalidate ai column for retry", K(ret), K(invalidate_sql));
    } else if (OB_FAIL(enqueue_sql.append_fmt(
                   "INSERT INTO oceanbase.__all_ai_column_task "
                   "(task_id, table_id, column_id, rowkey_predicate, eligible_ts, state, "
                   "retry_count, request_id) "
                   "SELECT uuid_short(), %lu, %lu, %s, now(6), 0, 0, "
                   "CONCAT('ai_', %lu, '_', %s) FROM `%.*s`.`%.*s` WHERE %.*s",
                   schema.get_table_id(), result_column->get_column_id(),
                   rowkey_expr.ptr(), schema.get_table_id(), rowkey_expr.ptr(),
                   db_name.length(), db_name.ptr(), table_name.length(), table_name.ptr(),
                   where_sql.length(), where_sql.ptr()))) {
    } else if (OB_FAIL(conn->execute_write(enqueue_sql.string(), affected_rows))) {
      LOG_WARN("failed to enqueue ai column retry tasks", K(ret), K(enqueue_sql));
    }
  }
  return ret;
}

int ObAlterTableExecutor::execute(ObExecContext &ctx, ObAlterTableStmt &stmt)
{
  int ret = OB_SUCCESS;
  ObSqlExecutorCtx *task_exec_ctx = NULL;
  obcall::ObAlterTableArg &alter_table_arg = stmt.get_alter_table_arg();
  obcall::ObExchangePartitionArg &exchange_partition_arg = stmt.get_exchange_partition_arg();
  ObString first_stmt;
  OZ (stmt.get_first_stmt(first_stmt));
  OV (OB_NOT_NULL(task_exec_ctx = GET_SQL_EXECUTOR_CTX(ctx)), OB_NOT_INIT);
  if (OB_FAIL(ret)) {
    // do nothing
  } else if (stmt.is_ai_column_retry()) {
    if (OB_FAIL(do_ai_column_retry(ctx, stmt))) {
    }
  } else if (stmt.is_alter_triggers()) {
    if (stmt.get_tg_arg().trigger_infos_.count() > 0) {
      stmt.get_tg_arg().ddl_stmt_str_ = first_stmt;
      OZ (query::serialize_root_service_call(
          [&]{ return ctx.root_command_service().alter_trigger(stmt.get_tg_arg()); }),
          GCTX.self_addr());
    }
  } else {
    ObSQLSessionInfo *my_session = NULL;
    obcall::ObAlterTableRes res;
    bool need_modify_fk_validate = false;
    bool need_check = false;
    bool need_modify_notnull_validate = false;
    ObArenaAllocator allocator(ObModIds::OB_SQL_EXECUTOR);
    if (OB_FAIL(stmt.get_first_stmt(first_stmt))) {
    } else {
      alter_table_arg.ddl_stmt_str_ = first_stmt;
      exchange_partition_arg.ddl_stmt_str_ = first_stmt;
      my_session = ctx.get_my_session();
      if (NULL == my_session) {
        ret = OB_ERR_UNEXPECTED;
      } else if (FALSE_IT(alter_table_arg.sql_mode_ = my_session->get_sql_mode())) {
        // do nothing
      } else if (FALSE_IT(alter_table_arg.parallelism_ = stmt.get_parallelism())) {
      } else if (OB_FAIL(check_alter_partition(ctx, stmt, alter_table_arg))) {
      } else if (OB_FAIL(check_alter_part_key(ctx, alter_table_arg))) {
      } else if (OB_FAIL(set_index_arg_list(ctx, stmt))) {
      } else if (OB_INVALID_ID == alter_table_arg.session_id_
                && 0 != my_session->get_sessid_for_table()
                && FALSE_IT(alter_table_arg.session_id_ = my_session->get_sessid_for_table())) {
        //impossible
      } else {
        int64_t foreign_key_checks = 0;
        my_session->get_foreign_key_checks(foreign_key_checks);
        alter_table_arg.foreign_key_checks_ = foreign_key_checks;
        if ((obcall::ObAlterTableArg::ADD_CONSTRAINT == alter_table_arg.alter_constraint_type_
            || (obcall::ObAlterTableArg::ALTER_CONSTRAINT_STATE == alter_table_arg.alter_constraint_type_))) {
          if (OB_FAIL(need_check_constraint_validity(alter_table_arg, need_check))) {
          }
        }
        // If appending a foreign key with the validate attribute or modifying a foreign key to have the validate attribute, it does not take effect immediately
        // Validate existing data meets the foreign key's validate attribute requirements before activation, ensuring the optimizer can correctly optimize based on the foreign key's validate attribute
        if (OB_SUCC(ret) && alter_table_arg.foreign_key_checks_ && 1 == alter_table_arg.foreign_key_arg_list_.count()) {
          if ((!alter_table_arg.foreign_key_arg_list_.at(0).is_modify_fk_state_
              && alter_table_arg.foreign_key_arg_list_.at(0).validate_flag_)
              || (alter_table_arg.foreign_key_arg_list_.at(0).is_modify_validate_flag_
                  && alter_table_arg.foreign_key_arg_list_.at(0).validate_flag_)) {
            need_modify_fk_validate = true;
          }
        }
        if (OB_SUCC(ret)) {
          if ((obcall::ObAlterTableArg::EXCHANGE_PARTITION == alter_table_arg.alter_part_type_)
              || (obcall::ObAlterTableArg::EXCHANGE_SUBPARTITION == alter_table_arg.alter_part_type_)) {
            if (OB_FAIL(alter_table_exchange_partition_rpc(exchange_partition_arg,
                                                           res,
                                                           my_session,
                                                           ctx.root_command_service()))) {
            }
          } else if (OB_FAIL(alter_table_rpc_v2(alter_table_arg,
                                                res,
                                                allocator,
                                                my_session,
                                                ctx.root_command_service(),
                                                *ctx.get_query_runtime_environment(),
                                                ctx.local_command_service()))) {
          }
        }
        if (OB_SUCC(ret) && !stmt.get_ai_column_defs().empty()) {
          ObMySQLProxy *sql_proxy = ctx.get_sql_proxy();
          uint64_t table_id = alter_table_arg.alter_table_schema_.get_table_id();
          const ObSEArray<ObAiColumnDef, 4> &defs = stmt.get_ai_column_defs();
          for (int64_t j = 0; OB_SUCC(ret) && j < defs.count(); ++j) {
            const ObAiColumnDef &def = defs.at(j);
            ObSqlString sql;
            int64_t affected_rows = 0;
            if (OB_ISNULL(sql_proxy)) {
              ret = OB_ERR_UNEXPECTED;
            } else if (OB_FAIL(sql.append_fmt(
                    "INSERT INTO %s (gmt_create, gmt_modified, table_id, column_id, column_name, "
                    "max_retries, state_column_id, request_column_id, result_spec_column_id, normalized_expr) "
                    "VALUES (now(6), now(6), %lu, 0, '%.*s', %ld, 0, 0, 0, '%.*s')",
                    OB_ALL_AI_COLUMN_TNAME, table_id,
                    def.column_name_.length(), def.column_name_.ptr(), def.max_retries_,
                    def.normalized_expr_.length(), def.normalized_expr_.ptr()))) {
            } else if (OB_FAIL(sql_proxy->write(sql.ptr(), affected_rows))) {
              LOG_WARN("failed to write alter ai column metadata", K(ret), K(sql));
            }
          }
        }
      }
    }
    if (OB_SUCC(ret)) {
      if (!need_check) {
        // do nothing, don't check if data is valid
      } else if (OB_FAIL(refresh_schema_for_table())) {
      } else if (OB_FAIL(ObDDLExecutorUtil::wait_ddl_finish(
          res.task_id_, res.ddl_need_retry_at_executor_, my_session,
          *ctx.get_query_runtime_environment(), ctx.local_command_service()))) {
      }
    }
    if (OB_SUCC(ret)
        && 1 == alter_table_arg.foreign_key_arg_list_.count()) {
      if (!need_modify_fk_validate) {
        // do nothing, don't check if data is valid
      } else {
        if (OB_FAIL(refresh_schema_for_table())) {
        } else if (OB_FAIL(ObDDLExecutorUtil::wait_ddl_finish(
            res.task_id_, res.ddl_need_retry_at_executor_, my_session,
            *ctx.get_query_runtime_environment(), ctx.local_command_service()))) {
        }
      }
    }

    if (OB_SUCC(ret)) {
      bool is_support_cancel = true;
      const bool need_wait_ddl_finish = is_double_table_long_running_ddl(res.ddl_type_)
                                     || is_simple_table_long_running_ddl(res.ddl_type_)
                                     || (ObDDLType::DDL_DROP_COLUMN_INSTANT == res.ddl_type_ && res.task_id_ > 0 /* with drop lob*/);
      if (OB_SUCC(ret) && need_wait_ddl_finish) {
        int64_t affected_rows = 0;
        if (OB_FAIL(refresh_schema_for_table())) {
        } else if (OB_FAIL(ObDDLExecutorUtil::wait_ddl_finish(
            res.task_id_, res.ddl_need_retry_at_executor_, my_session,
            *ctx.get_query_runtime_environment(), ctx.local_command_service(), is_support_cancel))) {
        }
      }
    }
    char table_info_buffer[256];
    snprintf(table_info_buffer, sizeof(table_info_buffer), "table_id:%ld, hidden_table_id:%ld", 
              alter_table_arg.table_id_, alter_table_arg.hidden_table_id_);

    SERVER_EVENT_ADD("ddl", "alter table execute finish",
      "ret", ret,
      "trace_id", *ObCurTraceId::get_trace_id(),
      "task_id", res.task_id_,
      "table_info", table_info_buffer,
      "schema_version", res.schema_version_);
    SQL_ENG_LOG(INFO, "finish alter table execute.", K(ret), "ddl_event_info", ObDDLEventInfo(GCTX.self_addr()), K(first_stmt));
  }
  return ret;
}

int ObAlterTableExecutor::need_check_constraint_validity(obcall::ObAlterTableArg &alter_table_arg, bool &need_check)
{
  int ret = OB_SUCCESS;
  need_check = false;
  if (obcall::ObAlterTableArg::ADD_CONSTRAINT != alter_table_arg.alter_constraint_type_
      && obcall::ObAlterTableArg::ALTER_CONSTRAINT_STATE != alter_table_arg.alter_constraint_type_) {
  } else {
    ObTableSchema::const_constraint_iterator iter =
        alter_table_arg.alter_table_schema_.constraint_begin();
    for(; iter != alter_table_arg.alter_table_schema_.constraint_end() && OB_SUCC(ret) && !need_check; iter++) {
      if (obcall::ObAlterTableArg::ALTER_CONSTRAINT_STATE == alter_table_arg.alter_constraint_type_) {
        if ((*iter)->get_is_modify_validate_flag() && (*iter)->is_validated()) {
          need_check = true;
        }
      } else if (CONSTRAINT_TYPE_CHECK == (*iter)->get_constraint_type()) {
        if ((*iter)->is_validated()) {
          need_check = (*iter)->is_validated();
        }
      } else if (CONSTRAINT_TYPE_NOT_NULL == (*iter)->get_constraint_type()) {
        if (1 != (*iter)->get_column_cnt()) {
          ret = OB_ERR_UNEXPECTED;
        } else if (OB_INVALID_ID != *(*iter)->cst_col_begin()) {
          // alter table modify column not null.
          need_check = (*iter)->is_validated();
        }
      } else {
        ret = OB_ERR_UNEXPECTED;
      }
      if (OB_SUCC(ret) && !need_check) {
        (*iter)->set_need_validate_data(false);
      }
    }
  }
  return ret;
}


int ObAlterTableExecutor::resolve_alter_column_partition_expr(
    const share::schema::ObColumnSchemaV2 &col_schema,
    const share::schema::ObTableSchema &table_schema,
    ObSchemaGetterGuard &schema_guard,
    ObSQLSessionInfo &session_info,
    common::ObIAllocator &allocator,
    const bool is_sub_part,
    ObRawExprResType &dst_res_type)
{
  int ret = OB_SUCCESS;
  ObRawExpr *part_expr = NULL;
  ObRawExprFactory expr_factory(allocator);
  ObSchemaChecker schema_checker;
  if (OB_FAIL(schema_checker.init(schema_guard))) {
  } else {
    ObResolverParams resolver_ctx;
    ObStmtFactory stmt_factory(allocator);
    TableItem table_item;
    resolver_ctx.allocator_ = &allocator;
    resolver_ctx.schema_checker_ = &schema_checker;
    resolver_ctx.session_info_ = &session_info;
    resolver_ctx.disable_privilege_check_ = PRIV_CHECK_FLAG_DISABLE;
    resolver_ctx.expr_factory_ = &expr_factory;
    resolver_ctx.stmt_factory_ = &stmt_factory;
    resolver_ctx.query_ctx_ = stmt_factory.get_query_ctx();
    table_item.table_id_ = table_schema.get_table_id();
    table_item.ref_id_ = table_schema.get_table_id();
    table_item.type_ = TableItem::BASE_TABLE;
    // This is just to use the resolver to resolve the partition expr interface.
    // The resolver of any statement has this ability. The reason for using the delete
    // resolver is that the delete resolver is the simplest
    ObPartitionFuncType part_type;
    SMART_VAR (ObDeleteResolver, delete_resolver, resolver_ctx) {
      ObDeleteStmt *delete_stmt = delete_resolver.create_stmt<ObDeleteStmt>();
      CK (OB_NOT_NULL(delete_stmt));
      CK (OB_NOT_NULL(resolver_ctx.query_ctx_));
      OZ (delete_stmt->get_table_items().push_back(&table_item));
      OZ (delete_stmt->set_table_bit_index(table_schema.get_table_id()));
      if (!is_sub_part) {
        const ObString &part_str = table_schema.get_part_option().get_part_func_expr_str();
        part_type = table_schema.get_part_option().get_part_func_type();
        OZ (delete_resolver.resolve_partition_expr(table_item, table_schema,
        part_type, part_str, part_expr));
      } else {
        const ObString &part_str = table_schema.get_sub_part_option().get_part_func_expr_str();
        part_type = table_schema.get_sub_part_option().get_part_func_type();
        OZ (delete_resolver.resolve_partition_expr(table_item, table_schema,
        part_type, part_str, part_expr));
      }
      CK (OB_NOT_NULL(part_expr));
    }
  }
  if (OB_FAIL(ret)) {
  } else if (part_expr->is_column_ref_expr()) {
    ObColumnRefRawExpr *column_ref = static_cast<ObColumnRefRawExpr*>(part_expr);
    if (column_ref->get_column_id() == col_schema.get_column_id()) {
      if (OB_FAIL(ObRawExprUtils::init_column_expr(col_schema, &session_info, *column_ref))) {
      } else if (CS_TYPE_INVALID == column_ref->get_collation_type()) {
        column_ref->set_collation_type(table_schema.get_collation_type());
      }
    }
  } else {
    for (int64_t i = 0; OB_SUCC(ret) && i < part_expr->get_param_count(); ++i) {
      ObRawExpr *sub_expr = part_expr->get_param_expr(i);
      if (OB_ISNULL(sub_expr)) {
        ret = OB_ERR_UNEXPECTED;
      } else if (sub_expr->is_column_ref_expr()) {
        ObColumnRefRawExpr *column_ref = static_cast<ObColumnRefRawExpr*>(sub_expr);
        if (column_ref->get_column_id() == col_schema.get_column_id()) {
          if (OB_FAIL(ObRawExprUtils::init_column_expr(col_schema, &session_info, *column_ref))) {
          } else if (CS_TYPE_INVALID == column_ref->get_collation_type()) {
            column_ref->set_collation_type(table_schema.get_collation_type());
          }
        }
      }
    }
  }
  OZ (part_expr->formalize(&session_info));
  OX (dst_res_type = part_expr->get_result_type());
  return ret;
}

template<class T>
int ObAlterTableExecutor::calc_range_part_high_bound(
    const ObPartitionFuncType part_func_type,
    const ObString &col_name,
    const ObRawExprResType &dst_res_type,
    T &part,
    ObExecContext &ctx)
{
  int ret = OB_SUCCESS;
  ObExprCtx expr_ctx;
  ObAccuracy accuracy(dst_res_type.get_accuracy());
  const ObObjType fun_expr_type = dst_res_type.get_type();
  const ObCollationType fun_collation_type = dst_res_type.get_collation_type();
  ObObjType expected_obj_type = fun_expr_type;
  ObSEArray<ObObj, obcall::OB_DEFAULT_ARRAY_SIZE> range_partition_obj;
  if (OB_FAIL(ObSQLUtils::wrap_expr_ctx(stmt::T_ALTER_TABLE, ctx, ctx.get_allocator(), expr_ctx))) {
  } else {
    expr_ctx.cast_mode_ = CM_WARN_ON_FAIL; //always set to WARN_ON_FAIL to allow calculate
    const common::ObRowkey &row_key = part.get_high_bound_val();
    int64_t obj_cnt = row_key.get_obj_cnt();
    for (int64_t i = 0; OB_SUCC(ret) && i < obj_cnt; ++i) {
      const ObObj &src_obj = row_key.get_obj_ptr()[i];
      if (src_obj.is_max_value()) {
        if (OB_FAIL(range_partition_obj.push_back(src_obj))) {
        }
      } else {
        if (ob_is_integer_type(fun_expr_type)) {
          // Type promotion to int64 or uint64
          expected_obj_type = ob_is_int_tc(fun_expr_type) ? ObIntType : ObUInt64Type;
        }
        const ObObj *dst_obj = NULL;
        EXPR_DEFINE_CAST_CTX(expr_ctx, CM_NONE);
        cast_ctx.dest_collation_ = fun_collation_type;
        cast_ctx.res_accuracy_ = &accuracy;
        EXPR_CAST_OBJ_V2(expected_obj_type, src_obj, dst_obj);
        if (OB_SUCC(ret)) {
          if (OB_ISNULL(dst_obj)) {
            ret = OB_ERR_UNEXPECTED;
          } else if ((PARTITION_FUNC_TYPE_RANGE_COLUMNS == part_func_type
                    || PARTITION_FUNC_TYPE_LIST_COLUMNS == part_func_type)
                    && OB_FAIL(ObResolverUtils::check_partition_range_value_result_type(part_func_type,
                                                                                        dst_res_type,
                                                                                        col_name,
                                                                                        const_cast<ObObj&>(*dst_obj)))) {
          } else if (OB_FAIL(range_partition_obj.push_back(*dst_obj))) {
          }
        } else if (OB_ERR_UNEXPECTED != ret) {
          ret = OB_ERR_WRONG_TYPE_COLUMN_VALUE_ERROR;
          LOG_WARN("failed to cast obj", K(expected_obj_type), K(fun_expr_type), K(src_obj));
        }
      }
    }
    if (OB_SUCC(ret)) {
      ObRowkey high_rowkey(&range_partition_obj.at(0), range_partition_obj.count());
      part.reset_high_bound_val();
      if (OB_FAIL(part.set_high_bound_val(high_rowkey))) {
      }
    }
  }
  return ret;
}

int ObAlterTableExecutor::calc_range_values_exprs(
    const ObColumnSchemaV2 &col_schema,
    const share::schema::ObTableSchema &orig_table_schema,
    share::schema::ObTableSchema &new_table_schema,
    ObSchemaGetterGuard &schema_guard,
    ObSQLSessionInfo &session_info,
    common::ObIAllocator &allocator,
    ObExecContext &ctx,
    const bool is_subpart)
{
  int ret = OB_SUCCESS;
  ObRawExprResType dst_res_type;
  if (OB_FAIL(resolve_alter_column_partition_expr(col_schema, orig_table_schema, schema_guard,
              session_info, allocator, is_subpart, dst_res_type))) {
  } else if (is_subpart) {
    const int64_t part_num = new_table_schema.get_partition_num();
    const ObPartitionFuncType part_func_type = orig_table_schema.get_sub_part_option().get_part_func_type();
    ObPartition **part_array = new_table_schema.get_part_array();
    CK (OB_NOT_NULL(part_array));
    for (int64_t i = 0; i < part_num && OB_SUCC(ret); ++i) {
      ObPartition *part = part_array[i];
      CK (OB_NOT_NULL(part));
      CK (OB_NOT_NULL(part->get_subpart_array()));
      for (int64_t j = 0; OB_SUCC(ret) && j < part->get_subpartition_num(); j++) {
        ObSubPartition *sub_part = part->get_subpart_array()[j];
        CK (OB_NOT_NULL(sub_part));
        OZ (calc_range_part_high_bound(part_func_type,
                                       col_schema.get_column_name_str(),
                                       dst_res_type,
                                       *sub_part,
                                       ctx));
      }
      if (OB_SUCC(ret)) {
        if (OB_FAIL(ObPartitionExecutorUtils::check_increasing_range_value(part->get_subpart_array(),
                                                                           part->get_subpartition_num(),
                                                                           stmt::T_ALTER_TABLE))) {
        }
      }
    }
  } else {
    const int64_t part_num = new_table_schema.get_partition_num();
    const ObPartitionFuncType part_func_type = orig_table_schema.get_part_option().get_part_func_type();
    ObPartition **part_array = new_table_schema.get_part_array();
    CK (OB_NOT_NULL(part_array));
    for (int64_t i = 0; i < part_num && OB_SUCC(ret); ++i) {
      ObPartition *part = part_array[i];
      CK (OB_NOT_NULL(part));
      OZ (calc_range_part_high_bound(part_func_type,
                                     col_schema.get_column_name_str(),
                                     dst_res_type,
                                     *part,
                                     ctx));
    }
    if (OB_SUCC(ret)) {
      if (OB_FAIL(ObPartitionExecutorUtils::check_increasing_range_value(part_array,
                                                                         part_num,
                                                                         stmt::T_ALTER_TABLE))) {
      }
    }
  }
  return ret;
}

template<class T>
int ObAlterTableExecutor::calc_list_part_rows(
    const ObPartitionFuncType part_func_type,
    const ObString &col_name,
    const ObRawExprResType &dst_res_type,
    const T &orig_part,
    T &new_part,
    ObExecContext &ctx,
    common::ObIAllocator &allocator)
{
  int ret = OB_SUCCESS;
  ObExprCtx expr_ctx;
  const ObObjType fun_expr_type = dst_res_type.get_type();
  const ObCollationType fun_collation_type = dst_res_type.get_collation_type();
  ObObjType expected_obj_type = fun_expr_type;
  ObSEArray<ObObj, obcall::OB_DEFAULT_ARRAY_SIZE> range_partition_obj;
  if (OB_FAIL(ObSQLUtils::wrap_expr_ctx(stmt::T_ALTER_TABLE, ctx, ctx.get_allocator(), expr_ctx))) {
  } else {
    new_part.reset_list_row_values();
    expr_ctx.cast_mode_ = CM_WARN_ON_FAIL; //always set to WARN_ON_FAIL to allow calculate
    const common::ObIArray<common::ObNewRow>& row_list = orig_part.get_list_row_values();
    for (int64_t i = 0; OB_SUCC(ret) && i < row_list.count(); i ++) {
      const common::ObNewRow &row = row_list.at(i);
      for (int64_t j = 0; OB_SUCC(ret) && j < row.get_count(); ++j) {
        const ObObj &src_obj = row.get_cell(j);
        if (src_obj.is_max_value()) {
          if (OB_FAIL(range_partition_obj.push_back(src_obj))) {
          }
        } else {
          if (ob_is_integer_type(fun_expr_type)) {
            // Type promotion to int64 or uint64
            expected_obj_type = ob_is_int_tc(fun_expr_type) ? ObIntType : ObUInt64Type;
          }
          const ObObj *dst_obj = NULL;
          EXPR_DEFINE_CAST_CTX(expr_ctx, CM_NONE);
          cast_ctx.dest_collation_ = fun_collation_type;
          EXPR_CAST_OBJ_V2(expected_obj_type, src_obj, dst_obj);
          if (OB_SUCC(ret)) {
            if (OB_ISNULL(dst_obj)) {
              ret = OB_ERR_UNEXPECTED;
            } else if ((PARTITION_FUNC_TYPE_RANGE_COLUMNS == part_func_type
                      || PARTITION_FUNC_TYPE_LIST_COLUMNS == part_func_type)
                      && OB_FAIL(ObResolverUtils::check_partition_range_value_result_type(part_func_type,
                                                                                          dst_res_type,
                                                                                          col_name,
                                                                                          const_cast<ObObj&>(*dst_obj)))) {
            } else if (OB_FAIL(range_partition_obj.push_back(*dst_obj))) {
            }
          } else if (OB_ERR_UNEXPECTED != ret) {
            ret = OB_ERR_WRONG_TYPE_COLUMN_VALUE_ERROR;
            LOG_WARN("failed to cast obj", K(expected_obj_type), K(fun_expr_type), K(src_obj));
          }
        }
      }
      if (OB_SUCC(ret)) {
        ObNewRow row;
        ObObj* obj_array = (ObObj *)allocator.alloc(range_partition_obj.count() * sizeof(ObObj));
        CK (OB_NOT_NULL(obj_array));
        for (int64_t k = 0; OB_SUCC(ret) && k < range_partition_obj.count(); k ++) {
          new (obj_array + k) ObObj();
          obj_array[k] = (&range_partition_obj.at(0))[k];
        }
        OX (row.assign(obj_array, range_partition_obj.count()));
        OZ (new_part.add_list_row(row));
        OX (range_partition_obj.reuse());
      }
    }
  }
  return ret;
}

int ObAlterTableExecutor::calc_list_values_exprs(
    const ObColumnSchemaV2 &col_schema,
    const share::schema::ObTableSchema &orig_table_schema,
    share::schema::ObTableSchema &new_table_schema,
    ObSchemaGetterGuard &schema_guard,
    ObSQLSessionInfo &session_info,
    common::ObIAllocator &allocator,
    ObExecContext &ctx,
    const bool is_subpart)
{
  int ret = OB_SUCCESS;
  ObRawExprResType dst_res_type;
  if (OB_FAIL(resolve_alter_column_partition_expr(col_schema, orig_table_schema, schema_guard,
              session_info, allocator, is_subpart, dst_res_type))) {
  } else if (is_subpart) {
    const int64_t part_num = orig_table_schema.get_partition_num();
    const ObPartitionFuncType part_func_type = orig_table_schema.get_sub_part_option().get_part_func_type();
    ObPartition **orig_part_array = orig_table_schema.get_part_array();
    ObPartition **new_part_array = new_table_schema.get_part_array();
    CK (OB_NOT_NULL(orig_part_array) && OB_NOT_NULL(new_part_array));
    for (int64_t i = 0; i < part_num && OB_SUCC(ret); ++i) {
      ObPartition *orig_part = orig_part_array[i];
      ObPartition *new_part = new_part_array[i];
      CK (OB_NOT_NULL(orig_part) && OB_NOT_NULL(new_part));
      CK (OB_NOT_NULL(orig_part->get_subpart_array()));
      CK (OB_NOT_NULL(orig_part->get_subpart_array()));
      for (int64_t j = 0; OB_SUCC(ret) && j < orig_part->get_subpartition_num(); j++) {
        ObSubPartition *orig_sub_part = orig_part->get_subpart_array()[j];
        ObSubPartition *new_sub_part = new_part->get_subpart_array()[j];
        CK (OB_NOT_NULL(orig_sub_part) && OB_NOT_NULL(new_sub_part));
        OZ (calc_list_part_rows(part_func_type,
                                col_schema.get_column_name_str(),
                                dst_res_type,
                                *orig_sub_part,
                                *new_sub_part,
                                ctx,
                                allocator));
      }
    }
  } else {
    const int64_t part_num = orig_table_schema.get_partition_num();
    const ObPartitionFuncType part_func_type = orig_table_schema.get_part_option().get_part_func_type();
    ObPartition **orig_part_array = orig_table_schema.get_part_array();
    ObPartition **new_part_array = new_table_schema.get_part_array();
    CK (OB_NOT_NULL(orig_part_array) && OB_NOT_NULL(new_part_array));
    for (int64_t i = 0; i < part_num && OB_SUCC(ret); ++i) {
      ObPartition *orig_part = orig_part_array[i];
      ObPartition *new_part = new_part_array[i];
      CK (OB_NOT_NULL(orig_part) && OB_NOT_NULL(new_part));
      OZ (calc_list_part_rows(part_func_type,
                              col_schema.get_column_name_str(),
                              dst_res_type,
                              *orig_part,
                              *new_part,
                              ctx,
                              allocator));
    }
  }
  return ret;
}

int ObAlterTableExecutor::check_alter_part_key(ObExecContext &ctx,
                                               obcall::ObAlterTableArg &arg)
{
  int ret = OB_SUCCESS;
  if (arg.is_alter_columns_) {
    bool is_contain_part_key = false;
    ObSchemaGetterGuard schema_guard;
    common::ObIAllocator &allocator = arg.allocator_;
    AlterTableSchema &table_schema = const_cast<AlterTableSchema &>(arg.alter_table_schema_);
    share::schema::ObTableSchema::const_column_iterator it_begin = table_schema.column_begin();
    share::schema::ObTableSchema::const_column_iterator it_end = table_schema.column_end();
    
    schema_guard.set_session_id(arg.session_id_);
    const ObString &origin_database_name = table_schema.get_origin_database_name();
    const ObString &origin_table_name = table_schema.get_origin_table_name();
    ObSQLSessionInfo *my_session = ctx.get_my_session();
    const share::schema::ObTableSchema *orig_table_schema = NULL;
    AlterColumnSchema *alter_column_schema = NULL;
    const ObColumnSchemaV2 *orig_column_schema = NULL;
    CK (!origin_database_name.empty() && !origin_table_name.empty());
    CK (OB_NOT_NULL(my_session));
    OZ (ObMultiVersionSchemaService::get_instance().get_runtime_schema_guard(
    schema_guard));
    if (FAILEDx(schema_guard.get_table_schema(
                                              origin_database_name,
                                              origin_table_name,
                                              false/*is_index*/,
                                              orig_table_schema))) {
    } else if (OB_ISNULL(orig_table_schema)) {
      ret = OB_TABLE_NOT_EXIST;
    } else {
      OZ (table_schema.assign_partition_schema(*orig_table_schema));
      for(;OB_SUCC(ret) && it_begin != it_end; it_begin++) {
        if (OB_ISNULL(alter_column_schema = static_cast<AlterColumnSchema *>(*it_begin))) {
          ret = OB_ERR_UNEXPECTED;
        } else if (OB_DDL_CHANGE_COLUMN == alter_column_schema->alter_type_
          || OB_DDL_MODIFY_COLUMN == alter_column_schema->alter_type_) {
          bool is_same = false;
          const ObString &orig_column_name = alter_column_schema->get_origin_column_name();
          orig_column_schema = orig_table_schema->get_column_schema(orig_column_name);
          if (OB_ISNULL(orig_column_schema)) {
            ret = OB_ERR_CANT_DROP_FIELD_OR_KEY;
            LOG_USER_ERROR(OB_ERR_CANT_DROP_FIELD_OR_KEY, orig_column_name.length(), orig_column_name.ptr());
          } else if (OB_FAIL(ObTableSchema::check_is_exactly_same_type(
            *orig_column_schema, *alter_column_schema, is_same))) {
          } else if (!is_same && orig_column_schema->is_tbl_part_key_column()) {
            const bool is_part = orig_column_schema->is_part_key_column();
            const bool is_subpart = orig_column_schema->is_subpart_key_column();
            if (is_contain_part_key) {
              ret = OB_NOT_SUPPORTED;
              LOG_USER_ERROR(OB_NOT_SUPPORTED, "There are several mutually exclusive "
              "DDL in single statement");
            }
            // The column may be part key column, and may be subpart key column too.
            if (OB_SUCC(ret) && is_part) {
              if (orig_table_schema->is_list_part()) {
                OZ (calc_list_values_exprs(*alter_column_schema, *orig_table_schema, table_schema,
                  schema_guard, *my_session, allocator, ctx, false));
              } else if (orig_table_schema->is_range_part()) {
                OZ (calc_range_values_exprs(*alter_column_schema, *orig_table_schema, table_schema,
                  schema_guard, *my_session, allocator, ctx, false));
              }
            }
            if (OB_SUCC(ret) && is_subpart) {
              if (orig_table_schema->is_list_subpart()) {
                OZ (calc_list_values_exprs(*alter_column_schema, *orig_table_schema, table_schema,
                  schema_guard, *my_session, allocator, ctx, true));
              } else if (orig_table_schema->is_range_subpart()) {
                OZ (calc_range_values_exprs(*alter_column_schema, *orig_table_schema, table_schema,
                  schema_guard, *my_session, allocator, ctx, true));
              }
            }
            is_contain_part_key = true;
          }
        }
      }
    }
  }
  return ret;
}

int ObAlterTableExecutor::check_alter_partition(ObExecContext &ctx,
                                                ObAlterTableStmt &stmt,
                                                const obcall::ObAlterTableArg &arg)
{
  int ret = OB_SUCCESS;
  AlterTableSchema &table_schema = const_cast<AlterTableSchema &>(arg.alter_table_schema_);

  if (arg.is_alter_partitions_) {
    if (obcall::ObAlterTableArg::REPARTITION_TABLE == arg.alter_part_type_) {
      if (table_schema.is_range_part() || table_schema.is_list_part()
         || table_schema.is_range_subpart() || table_schema.is_list_subpart()) {
        if (OB_FAIL(ObPartitionExecutorUtils::calc_values_exprs_for_alter_table(ctx,
                                                                                table_schema,
                                                                                stmt))) {
        }
      }
    } else if (obcall::ObAlterTableArg::ADD_PARTITION == arg.alter_part_type_) {
      if (table_schema.is_range_part() || table_schema.is_list_part()) {
        if (OB_FAIL(ObPartitionExecutorUtils::calc_values_exprs_for_alter_table(ctx,
                                                                                table_schema,
                                                                                stmt))) {
        }
      } else {
        ret = OB_NOT_SUPPORTED;
        LOG_USER_WARN(OB_NOT_SUPPORTED, "add hash partition");
      }
    } else if (obcall::ObAlterTableArg::ADD_SUB_PARTITION == arg.alter_part_type_) {
      if (table_schema.is_range_subpart()) {
        if (OB_FAIL(ObPartitionExecutorUtils::set_individual_range_part_high_bound(
                    ctx, stmt::T_CREATE_TABLE, table_schema, stmt))) {
        }
      } else if (table_schema.is_list_subpart()) {
        if (OB_FAIL(ObPartitionExecutorUtils::set_individual_list_part_rows(
                    ctx, stmt, stmt::T_CREATE_TABLE, table_schema,
                    stmt.get_subpart_fun_exprs(),
                    stmt.get_individual_subpart_values_exprs()))) {
        }
      } else {
        ret = OB_NOT_SUPPORTED;
        LOG_USER_WARN(OB_NOT_SUPPORTED, "add hash subpartition");
      }
    } else if (obcall::ObAlterTableArg::DROP_PARTITION == arg.alter_part_type_
               || obcall::ObAlterTableArg::DROP_SUB_PARTITION == arg.alter_part_type_
               || obcall::ObAlterTableArg::RENAME_PARTITION == arg.alter_part_type_
               || obcall::ObAlterTableArg::RENAME_SUB_PARTITION == arg.alter_part_type_
               || obcall::ObAlterTableArg::TRUNCATE_PARTITION == arg.alter_part_type_
               || obcall::ObAlterTableArg::TRUNCATE_SUB_PARTITION == arg.alter_part_type_) {
      // do-nothing
    } else if ((obcall::ObAlterTableArg::EXCHANGE_PARTITION == arg.alter_part_type_)
        || (obcall::ObAlterTableArg::EXCHANGE_SUBPARTITION == arg.alter_part_type_)) {
      // do-nothing
    } else {
      ret = OB_ERR_UNEXPECTED;
    }
  }

  return ret;
}

int ObAlterTableExecutor::set_index_arg_list(ObExecContext &ctx, ObAlterTableStmt &stmt)
{
  int ret = OB_SUCCESS;
  ObSQLSessionInfo *my_session = ctx.get_my_session();
  obcall::ObAlterTableArg &alter_table_arg = const_cast<obcall::ObAlterTableArg &>(stmt.get_alter_table_arg());
  if (OB_ISNULL(my_session)) {
    ret = OB_INVALID_ARGUMENT;
  } else if (stmt.get_index_partition_resolve_results().count()
      != stmt.get_index_arg_list().count()) {
    ret = OB_ERR_UNEXPECTED;
  }
  for (int64_t i = 0; OB_SUCC(ret) && i < stmt.get_index_arg_list().count(); i++) {
    HEAP_VAR(ObCreateIndexStmt, index_stmt) {
      obcall::ObCreateIndexArg &create_index_arg = *(stmt.get_index_arg_list().at(i));
      ObPartitionResolveResult &resolve_result = stmt.get_index_partition_resolve_results().at(i);
      index_stmt.get_part_fun_exprs() = resolve_result.get_part_fun_exprs();
      index_stmt.get_part_values_exprs() = resolve_result.get_part_values_exprs();
      index_stmt.get_subpart_fun_exprs() = resolve_result.get_subpart_fun_exprs();
      index_stmt.get_template_subpart_values_exprs() = resolve_result.get_template_subpart_values_exprs();
      index_stmt.get_individual_subpart_values_exprs() = resolve_result.get_individual_subpart_values_exprs();
      if (OB_FAIL(index_stmt.get_create_index_arg().assign(create_index_arg))) {
      } else if (OB_FAIL(ObPartitionExecutorUtils::calc_values_exprs(ctx, index_stmt))) {
      } else {
        create_index_arg.is_inner_ = my_session->is_inner();
        if (OB_FAIL(create_index_arg.assign(index_stmt.get_create_index_arg()))) {
        } else if (OB_FAIL(alter_table_arg.index_arg_list_.push_back(&create_index_arg))) {
        }
      }
    }
  }
  return ret;
}

ObCommentExecutor::ObCommentExecutor()
{
}

ObCommentExecutor::~ObCommentExecutor()
{
}

int ObCommentExecutor::execute(ObExecContext &ctx, ObAlterTableStmt &stmt)
{
  int ret = OB_SUCCESS;
  ObSqlExecutorCtx *task_exec_ctx = nullptr;
  obcall::ObAlterTableArg &alter_table_arg = stmt.get_alter_table_arg();
  ObString first_stmt;
  if (OB_FAIL(stmt.get_first_stmt(first_stmt))) {
  } else if (OB_ISNULL(task_exec_ctx = GET_SQL_EXECUTOR_CTX(ctx))) {
    ret = OB_NOT_INIT;
  } else {
    ObSQLSessionInfo *my_session = nullptr;
    obcall::ObSetCommentArg set_comment_arg;
    obcall::ObParallelDDLRes set_comment_res;
    
    alter_table_arg.ddl_stmt_str_ = first_stmt;
    alter_table_arg.is_parallel_ = true;
    my_session = ctx.get_my_session();
    int64_t start_time = ObTimeUtility::current_time();
    ObTimeoutCtx tctx;
    const int64_t rpc_timeout = OB_DEFAULT_RPC_TIMEOUT;
    if (OB_ISNULL(my_session)) {
      ret = OB_ERR_UNEXPECTED;
    } else if (OB_INVALID_ID == alter_table_arg.session_id_
               && FALSE_IT(alter_table_arg.session_id_ = my_session->get_sessid_for_table())) {
      // should not in this field
    } else if (OB_FAIL(tctx.set_timeout(rpc_timeout))) {
    } else if (OB_FAIL(assign_alter_to_comment_(alter_table_arg, set_comment_arg))) {
    } else if (OB_FAIL(query::serialize_root_service_call(
                   [&]{ return ctx.root_command_service().set_comment(set_comment_arg, set_comment_res); }))) {
    } else {
      int64_t refresh_time = ObTimeUtility::current_time();
      if (OB_FAIL(ObDDLExecutorUtil::wait_local_schema_visible(
          tctx, my_session, set_comment_res.schema_version_))) {
      }
      int64_t end_time = ObTimeUtility::current_time();
      LOG_INFO("[parallel_comment_table]", KR(ret),
               "cost", end_time - start_time,
               "execute_time", refresh_time - start_time,
               "wait_schema", end_time - refresh_time,
               "table_name", set_comment_arg.table_name_);
    }
  }
  return ret;
}

int ObCommentExecutor::assign_alter_to_comment_(const obcall::ObAlterTableArg &alter_table_arg, obcall::ObSetCommentArg &set_comment_arg)
{
  int ret = OB_SUCCESS;
  const AlterTableSchema &alter_table_schema = alter_table_arg.alter_table_schema_;
  set_comment_arg.session_id_ = alter_table_arg.session_id_;
  set_comment_arg.database_name_ = alter_table_schema.get_origin_database_name();
  set_comment_arg.table_name_ = alter_table_schema.get_origin_table_name();
  if (OB_FAIL(set_comment_arg.ObDDLArg::assign(alter_table_arg))) {
  } else if (alter_table_arg.alter_table_schema_.alter_option_bitset_.has_member(obcall::ObAlterTableArg::COMMENT)) {
    set_comment_arg.op_type_ = obcall::ObSetCommentArg::COMMENT_TABLE;
    set_comment_arg.table_comment_ = alter_table_schema.get_comment();
  } else {
    set_comment_arg.op_type_ = obcall::ObSetCommentArg::COMMENT_COLUMN;
    ObTableSchema::const_column_iterator it_begin = alter_table_schema.column_begin();
    ObTableSchema::const_column_iterator it_end = alter_table_schema.column_end();
    for(; OB_SUCC(ret) && it_begin != it_end; it_begin++) {
      ObColumnSchemaV2 *column_schema = static_cast<ObColumnSchemaV2 *>(*it_begin);
      if (OB_ISNULL(column_schema)) {
        ret = OB_ERR_UNEXPECTED;
      } else if (OB_FAIL(set_comment_arg.column_name_list_.push_back(column_schema->get_column_name()))) {
      } else if (OB_FAIL(set_comment_arg.column_comment_list_.push_back(column_schema->get_comment()))) {
      }
    }
  }

  return ret;
}
/**
 *
 */

ObDropTableExecutor::ObDropTableExecutor()
{
}

ObDropTableExecutor::~ObDropTableExecutor()
{
}

int ObDropTableExecutor::execute(ObExecContext &ctx, ObDropTableStmt &stmt)
{
  int ret = OB_SUCCESS;
  ObSqlExecutorCtx *task_exec_ctx = NULL;
  const obcall::ObDropTableArg &drop_table_arg = stmt.get_drop_table_arg();
  obcall::ObDropTableArg &tmp_arg = const_cast<obcall::ObDropTableArg&>(drop_table_arg);
  ObString first_stmt;
  ObSQLSessionInfo *my_session = NULL;
  int64_t foreign_key_checks = 0;
  
  const ObTableType table_type = drop_table_arg.table_type_;
  if (OB_FAIL(stmt.get_first_stmt(first_stmt))) {
  } else {
    int64_t affected_rows = 0;
    tmp_arg.ddl_stmt_str_ = first_stmt;
    my_session = ctx.get_my_session();
    if (NULL == my_session) {
      ret = OB_ERR_UNEXPECTED;
    } else if (OB_ISNULL(task_exec_ctx = GET_SQL_EXECUTOR_CTX(ctx))) {
      ret = OB_NOT_INIT;
      LOG_WARN("get task executor context failed");
    } else if (OB_INVALID_ID == drop_table_arg.session_id_
               && FALSE_IT(tmp_arg.session_id_ = my_session->get_sessid_for_table())) {
      //impossible
    } else if (FALSE_IT(my_session->get_foreign_key_checks(foreign_key_checks))) {
    } else if (FALSE_IT(tmp_arg.foreign_key_checks_ = foreign_key_checks)) {
    } else {
      bool is_parallel_drop = false;
      if (!ObSchemaUtils::is_support_parallel_drop(table_type)) {
        is_parallel_drop = false;
      } else if (OB_FAIL(ObParallelDDLControlMode::is_parallel_ddl_enable(ObParallelDDLControlMode::DROP_TABLE, is_parallel_drop))) {
      }

      if (OB_SUCC(ret)) {
        if (is_parallel_drop) {
          int64_t start_time = ObTimeUtility::current_time();
          obcall::ObDropTableRes res;
          ObTimeoutCtx timeout_ctx;
          tmp_arg.is_parallel_ = true;
          if (OB_FAIL(timeout_ctx.set_timeout(OB_DEFAULT_RPC_TIMEOUT))) {
          } else if (OB_FAIL(ctx.root_command_service().parallel_drop_table(drop_table_arg, res))) {
          } else {
            int64_t refresh_time = ObTimeUtility::current_time();
            if (!res.do_nothing_ && OB_FAIL(ObDDLExecutorUtil::wait_local_schema_visible(
                                            timeout_ctx, my_session, res.schema_version_))) {
              LOG_ERROR("fail to wait for local schema visibility", KR(ret), K(res));
            }
            int64_t end_time = ObTimeUtility::current_time();
            LOG_INFO("[parallel_drop_table]", KR(ret),
                      "cost", end_time - start_time,
                      "execute_time", refresh_time - start_time,
                      "wait_schema", end_time - refresh_time);

            SERVER_EVENT_ADD("ddl", "drop table execute finish",
              "ret", ret,
              "trace_id", *ObCurTraceId::get_trace_id(),
              "rpc_dst", GCTX.self_addr(),
              "schema_version", res.schema_version_);
            SQL_ENG_LOG(INFO, "finish drop table execute.", KR(ret), "ddl_event_info", ObDDLEventInfo(GCTX.self_addr()));
          }
        } else {
          obcall::ObDDLRes res;
          if (OB_FAIL(query::serialize_root_service_call(
                  [&]{ return ctx.root_command_service().drop_table(drop_table_arg, res); }))) {
          } else if (res.is_valid() && OB_FAIL(ObDDLExecutorUtil::wait_ddl_retry_task_finish(
              res.task_id_, *my_session, *ctx.get_query_runtime_environment(),
              ctx.local_command_service(), affected_rows))) {
          } else {
            //do nothing
          }

          SERVER_EVENT_ADD("ddl", "drop table execute finish",
          "ret", ret,
          "trace_id", *ObCurTraceId::get_trace_id(),
          "task_id", res.task_id_,
          "schema_id", res.schema_id_);
          SQL_ENG_LOG(INFO, "finish drop table execute.", KR(ret), "ddl_event_info", ObDDLEventInfo(GCTX.self_addr()));
        }
      }
    }    
  }

  return ret;
}

/**
 *
 */
ObRenameTableExecutor::ObRenameTableExecutor()
{
}

ObRenameTableExecutor::~ObRenameTableExecutor()
{
}

int ObRenameTableExecutor::execute(ObExecContext &ctx, ObRenameTableStmt &stmt)
{
  int ret = OB_SUCCESS;
  const obcall::ObRenameTableArg &rename_table_arg = stmt.get_rename_table_arg();
  ObSqlExecutorCtx *task_exec_ctx = NULL;
  if (OB_ISNULL(task_exec_ctx = GET_SQL_EXECUTOR_CTX(ctx))) {
    ret = OB_NOT_INIT;
    LOG_WARN("get task executor context failed");
  } else if (OB_FAIL(query::serialize_root_service_call(
                 [&]{ return ctx.root_command_service().rename_table(rename_table_arg); }))) {
  }
  return ret;
}

/**
 *
 */

ObTruncateTableExecutor::ObTruncateTableExecutor()
{
}

ObTruncateTableExecutor::~ObTruncateTableExecutor()
{
}

int ObTruncateTableExecutor::check_use_parallel_truncate(const obcall::ObTruncateTableArg &arg, bool &use_parallel_truncate)
{
  int ret = OB_SUCCESS;
  use_parallel_truncate = false;
  const ObTableSchema *table_schema = NULL;
  
  const ObString table_name = arg.table_name_;
  const ObString database_name = arg.database_name_;
  share::schema::ObSchemaGetterGuard schema_guard;
  if (OB_ISNULL(GCTX.schema_service_)) {
    ret = OB_NOT_INIT;
  } else if (OB_FAIL(GCTX.schema_service_->get_runtime_schema_guard(schema_guard))) {
  } else if (FALSE_IT(schema_guard.set_session_id(arg.session_id_))) {
  } else if (OB_FAIL(schema_guard.get_table_schema( database_name, table_name, false, table_schema))) {
  } else if (OB_ISNULL(table_schema)) {
    ret = OB_TABLE_NOT_EXIST;
  } else {
    use_parallel_truncate = true;
  }
  if (OB_FAIL(ret)) {
    // do nothing
  } else if (use_parallel_truncate
             && OB_FAIL(ObParallelDDLControlMode::is_parallel_ddl_enable(
                        ObParallelDDLControlMode::TRUNCATE_TABLE, use_parallel_truncate))) {
  }
  return ret;
}

int ObTruncateTableExecutor::execute(ObExecContext &ctx, ObTruncateTableStmt &stmt)
{
  int ret = OB_SUCCESS;
  const obcall::ObTruncateTableArg &truncate_table_arg = stmt.get_truncate_table_arg();
  obcall::ObTruncateTableArg &tmp_arg = const_cast<obcall::ObTruncateTableArg&>(truncate_table_arg);
  ObString first_stmt;
  obcall::ObDDLRes res;
  ObSQLSessionInfo *my_session = ctx.get_my_session();
  if (OB_FAIL(stmt.get_first_stmt(first_stmt))) {
  } else {
    tmp_arg.ddl_stmt_str_ = first_stmt;

    ObSqlExecutorCtx *task_exec_ctx = NULL;
    if (OB_ISNULL(task_exec_ctx = GET_SQL_EXECUTOR_CTX(ctx))) {
      ret = OB_NOT_INIT;
      LOG_WARN("get task executor context failed");
    } else if (OB_ISNULL(my_session)) {
      ret = OB_ERR_UNEXPECTED;
    } else if (OB_INVALID_ID == truncate_table_arg.session_id_
               && FALSE_IT(tmp_arg.session_id_ = my_session->get_sessid_for_table())) {
      //impossible
    } else {
      int64_t foreign_key_checks = 0;
      my_session->get_foreign_key_checks(foreign_key_checks);
      tmp_arg.foreign_key_checks_ = foreign_key_checks;
      int64_t affected_rows = 0;
      bool use_parallel_truncate = false;
      
      if (OB_FAIL(check_use_parallel_truncate(truncate_table_arg, use_parallel_truncate))) {
      } else if (!use_parallel_truncate) {
        if (OB_FAIL(query::serialize_root_service_call(
                [&]{ return ctx.root_command_service().truncate_table(truncate_table_arg, res); }))) {
        } else if (res.is_valid()
          && OB_FAIL(ObDDLExecutorUtil::wait_ddl_retry_task_finish(
              res.task_id_, *my_session, *ctx.get_query_runtime_environment(),
              ctx.local_command_service(), affected_rows))) {
        }
      } else {
        // new parallel truncate
        ObTimeoutCtx timeout_ctx;
        tmp_arg.is_parallel_ = true;
        if (OB_FAIL(timeout_ctx.set_timeout(OB_DEFAULT_RPC_TIMEOUT))) {
        } else {
          int64_t start_time = ObTimeUtility::current_time();
          while (OB_SUCC(ret)) {
            DEBUG_SYNC(BEFORE_PARELLEL_TRUNCATE);
            if (OB_FAIL(query::serialize_root_service_call(
                    [&]{ return ctx.root_command_service().truncate_table_v2(truncate_table_arg, res); }))) {
              if ((OB_TRY_LOCK_ROW_CONFLICT == ret || OB_TIMEOUT == ret || OB_NOT_MASTER == ret
                    || OB_RS_NOT_MASTER == ret || OB_RS_SHUTDOWN == ret || OB_SERVER_RUNTIME_NOT_READY == ret) && timeout_ctx.get_timeout() > 0) {
                ob_usleep(1 * 1000 * 1000);
                // retry
                ret = OB_SUCCESS;
              }
            } else {
              // success
              break;
            }
          }
          int64_t step_time = ObTimeUtility::current_time();
          LOG_INFO("truncate_table_v2 finish trans", K(ret), "cost", step_time-start_time, "table_name", truncate_table_arg.table_name_, K(res));
          if (OB_FAIL(ret)) {
          } else if (!res.is_valid()) {
            ret = OB_ERR_UNEXPECTED;
          } else if (OB_FAIL(ObDDLExecutorUtil::wait_local_schema_visible(
                     timeout_ctx, my_session, res.task_id_))) {
          }
          int64_t end_time = ObTimeUtility::current_time();
          LOG_INFO("truncate_table_v2", KR(ret), "cost", end_time-start_time,
                                                "trans_cost", step_time - start_time,
                                                "wait_refresh", end_time - step_time,
                                                "table_name", truncate_table_arg.table_name_,
                                                K(res));
        }
      }
    }
    SERVER_EVENT_ADD("ddl", "truncate table execute finish",
      "ret", ret,
      "trace_id", *ObCurTraceId::get_trace_id(),
      "task_id", res.task_id_,
      "table_info", truncate_table_arg.table_name_,
      "schema_id", res.schema_id_);
    SQL_ENG_LOG(INFO, "finish truncate table execute.", K(ret), "ddl_event_info", ObDDLEventInfo(GCTX.self_addr()));
  }
  return ret;
}

ObCreateTableLikeExecutor::ObCreateTableLikeExecutor()
{
}

ObCreateTableLikeExecutor::~ObCreateTableLikeExecutor()
{
}

int ObCreateTableLikeExecutor::execute(ObExecContext &ctx, ObCreateTableLikeStmt &stmt)
{
  int ret = OB_SUCCESS;
  const obcall::ObCreateTableLikeArg &create_table_like_arg = stmt.get_create_table_like_arg();
  obcall::ObCreateTableLikeArg &tmp_arg = const_cast<obcall::ObCreateTableLikeArg&>(create_table_like_arg);
  ObString first_stmt;
  ObSQLSessionInfo *my_session = nullptr;
  if (OB_FAIL(stmt.get_first_stmt(first_stmt))) {
  } else if (OB_ISNULL(my_session = ctx.get_my_session())) {
    ret = OB_ERR_UNEXPECTED;
  } else {
    tmp_arg.ddl_stmt_str_ = first_stmt;
    tmp_arg.session_id_ = my_session->get_sessid_for_table();
    ObSqlExecutorCtx *task_exec_ctx = NULL;
    if (OB_ISNULL(task_exec_ctx = GET_SQL_EXECUTOR_CTX(ctx))) {
      ret = OB_NOT_INIT;
      LOG_WARN("get task executor context failed");
    } else if (OB_FAIL(query::serialize_root_service_call(
                   [&]{ return ctx.root_command_service().create_table_like(create_table_like_arg); }))) {
    }
  }
  return ret;
}

ObForkTableExecutor::ObForkTableExecutor()
{
}

ObForkTableExecutor::~ObForkTableExecutor()
{
}

int ObForkTableExecutor::execute(ObExecContext &ctx, ObForkTableStmt &stmt)
{
  int ret = OB_SUCCESS;
  const obcall::ObForkTableArg &fork_table_arg = stmt.get_fork_table_arg();
  obcall::ObForkTableArg &tmp_arg = const_cast<obcall::ObForkTableArg&>(fork_table_arg);
  ObString first_stmt;
  obcall::ObDDLRes res;
  ObSQLSessionInfo *my_session = nullptr;
  if (OB_FAIL(stmt.get_first_stmt(first_stmt))) {
  } else if (OB_ISNULL(my_session = ctx.get_my_session())) {
    ret = OB_ERR_UNEXPECTED;
  } else {
    uint64_t data_version = 0;
    tmp_arg.ddl_stmt_str_ = first_stmt;
    tmp_arg.session_id_ = my_session->get_sessid_for_table();
    ObSqlExecutorCtx *task_exec_ctx = NULL;
    if (OB_ISNULL(task_exec_ctx = GET_SQL_EXECUTOR_CTX(ctx))) {
      ret = OB_NOT_INIT;
      LOG_WARN("get task executor context failed");
    } else if (OB_FAIL(query::serialize_root_service_call(
                   [&]{ return ctx.root_command_service().fork_table(fork_table_arg, res); }))) {
    } else {
      LOG_INFO("fork table executor finished", K(fork_table_arg));
    }
  }
  return ret;
}

int ObRecyclebinRestoreTableExecutor::execute(ObExecContext &ctx, ObRecyclebinRestoreTableStmt &stmt)
{
  int ret = OB_SUCCESS;
  const obcall::ObRecyclebinRestoreTableArg &restore_table_arg = stmt.get_restore_table_arg();
  obcall::ObRecyclebinRestoreTableArg &tmp_arg = const_cast<obcall::ObRecyclebinRestoreTableArg&>(restore_table_arg);
  ObString first_stmt;
  if (OB_FAIL(stmt.get_first_stmt(first_stmt))) {
  } else {
    tmp_arg.ddl_stmt_str_ = first_stmt;
    ObSqlExecutorCtx *task_exec_ctx = NULL;
    if (OB_ISNULL(task_exec_ctx = GET_SQL_EXECUTOR_CTX(ctx))) {
      ret = OB_NOT_INIT;
      LOG_WARN("get task executor context failed");
    } else if (OB_FAIL(query::serialize_root_service_call(
                   [&]{ return ctx.root_command_service().restore_table_from_recyclebin(restore_table_arg); }))) {
    }
  }
  return ret;
}

int ObPurgeTableExecutor::execute(ObExecContext &ctx, ObPurgeTableStmt &stmt)
{
  int ret = OB_SUCCESS;
  const obcall::ObPurgeTableArg &purge_table_arg = stmt.get_purge_table_arg();
  obcall::ObPurgeTableArg &tmp_arg = const_cast<obcall::ObPurgeTableArg&>(purge_table_arg);
  ObString first_stmt;
  if (OB_FAIL(stmt.get_first_stmt(first_stmt))) {
  } else {
    tmp_arg.ddl_stmt_str_ = first_stmt;

    ObSqlExecutorCtx *task_exec_ctx = NULL;
    if (OB_ISNULL(task_exec_ctx = GET_SQL_EXECUTOR_CTX(ctx))) {
      ret = OB_NOT_INIT;
      LOG_WARN("get task executor context failed");
    } else if (OB_FAIL(query::serialize_root_service_call(
                   [&]{ return ctx.root_command_service().purge_table(purge_table_arg); }))) {
    }
  }
  return ret;
}

int ObOptimizeTableExecutor::execute(ObExecContext &ctx, ObOptimizeTableStmt &stmt)
{
  int ret = OB_SUCCESS;
  obcall::ObOptimizeTableArg &arg = stmt.get_optimize_table_arg();
  ObString first_stmt;
  if (OB_FAIL(stmt.get_first_stmt(first_stmt))) {
  } else {
    arg.ddl_stmt_str_ = first_stmt;
    ObSqlExecutorCtx *task_exec_ctx = nullptr;
    if (OB_ISNULL(task_exec_ctx = GET_SQL_EXECUTOR_CTX(ctx))) {
      ret = OB_ERR_UNEXPECTED;
    } else if (OB_FAIL(query::serialize_root_service_call(
                   [&]{ return ctx.root_command_service().optimize_table(arg); }))) {
    }
  }
  return ret;
}

int ObAlterTableExecutor::populate_based_schema_obj_info_(obcall::ObAlterTableArg &alter_table_arg) {
  int ret = OB_SUCCESS;
  const uint64_t table_id = alter_table_arg.alter_table_schema_.get_table_id();
  if (OB_INVALID_ID != table_id) {
    
    SMART_VAR(ObSchemaGetterGuard, guard) {
    const ObTableSchema *orig_table = nullptr;
    if (OB_FAIL(ObMultiVersionSchemaService::get_instance().get_runtime_schema_guard(
                guard))) {
    } else if (OB_FAIL(guard.get_table_schema( table_id, orig_table))) {
    } else if (OB_ISNULL(orig_table)) {
      ret = OB_TABLE_NOT_EXIST;
    } else {
      bool find = false;
      for (int i = 0; i < OB_SUCC(ret) && alter_table_arg.based_schema_object_infos_.count(); ++i) {
        ObBasedSchemaObjectInfo &based_schema_object_info =
                                alter_table_arg.based_schema_object_infos_.at(i);
        if (based_schema_object_info.schema_id_ == alter_table_arg.table_id_) {
          find = true;
          if (based_schema_object_info.schema_version_ == orig_table->get_schema_version()) {
            break;
          } else {
            ret = OB_ERR_PARALLEL_DDL_CONFLICT;
          }
        }
      }
      if (false == find) {
        if (OB_FAIL(alter_table_arg.based_schema_object_infos_.push_back(
                    ObBasedSchemaObjectInfo(table_id, TABLE_SCHEMA,
                                            orig_table->get_schema_version())))) {
        }
      }
    }
    } // end smart var
  }
  return ret;
}

} //end namespace sql
} //end namespace oceanbase
