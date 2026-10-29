# AI COLUMN implementation status (seekdb 2026 competition)

## Implemented

- Parser: `column_definition` accepts `... data_type [attrs] AI COLUMN '(' expr ')' [WITH '(' opts ')'] [ref] [pos]`.
  - Grammar: `src/sql/parser/sql_parser_mysql_mode.y`
  - Node type: `T_AI_COLUMN` (`src/query/api/query/parser/ob_item_type.h`)
- System tables:
  - `oceanbase.__all_ai_column` (table_id 1131)
  - `oceanbase.__all_ai_column_task` (table_id 1132)
  - Definitions: `src/share/inner_table/ob_inner_table_schema_def.py`
- DDL:
  - CREATE TABLE: result column stays user-visible; three hidden columns per AI column
    (`__ai_state_<col>`, `__ai_request_<col>`, `__ai_result_spec_<col>`) are appended after all
    user columns; metadata row is written to `__all_ai_column` after the DDL succeeds.
  - ALTER TABLE ADD COLUMN: metadata row is written after the ALTER succeeds.
  - `max_retries` / `sync_mode` options parsed from the raw option text.
  - JSON result columns get `normalized_expr` containing
    `Return exactly one valid JSON value`.
  - `dependency_columns` records the column refs referenced by the AI expression.
  - `raw_expr` records the original AI expression text (hex-escaped on insert).
  - `AI_EMBED(..., dim)` on `vector(N)` with `dim != N` fails with `OB_ERR_INVALID_VECTOR_DIM` (7600).
  - An AI column depending on another AI column fails with `OB_NOT_SUPPORTED` (client 1235).
- Hidden state column has pending default `1`.

## Tests

| Test | Status |
|---|---|
| `tools/deploy/mysql_test/test_suite/ai_column/t/ai_column_ddl.test` | pass |
| `ai_column_t1_dml.test` | fail: task rows + worker not implemented |
| `ai_column_worker.test` | fail: worker not implemented |
| `ai_column_retry_strict.test` | fail |
| `ai_column_vector_index.test` | fail |

`ai_column_t1_dml.test` diff shows only task/worker-related results are missing; the SQL
semantics (transaction visibility, primary key update, batch, delete) execute correctly.

## Remaining design

- Task creation hook: `ObDMLService::handle_after_processing_multi_row` has
  `ObDMLModifyRowNode` (`full_row_`, `old_row_`, `new_row_`, `dml_event_`, `dml_ctdef_`).
- Same-transaction write: `ObTableModifyOp::execute_write(sql)` uses `inner_conn_`
  (`ObInnerSQLConnectionAccess::create_connection_with_external_session`), so task rows
  created there are visible in the current transaction and rolled back with it.
- AI column detection: hidden columns whose name starts with `__ai_state_`.
- Rowkey predicate: `table_schema->get_rowkey_column_ids()` + the full row datums.
- Worker: scan `__all_ai_column_task` for pending tasks, evaluate
  `SELECT <raw_expr> FROM <table> WHERE <rowkey_predicate>` through an inner SQL connection,
  call the model endpoint, write the result column and delete/complete the task.

## Local test commands

```bash
# build
./build.sh release -DNEED_PARSER_CACHE=OFF
make -C build_release -j4 seekdb

# server
build_release/src/observer/seekdb --base-dir /tmp/obtest --port 2881 --nodaemon \
  --parameter memory_budget=2G --parameter log_disk_size=2G

# AI column DDL test (from tools/deploy)
../../deps/3rd/u01/obclient/bin/mysqltest --host=127.0.0.1 --port=2881 --user=root \
  --test-file=mysql_test/test_suite/ai_column/t/ai_column_ddl.test \
  --result-file=mysql_test/test_suite/ai_column/r/mysql/ai_column_ddl.result

# AI functions tests (mock on 127.0.0.1:8000)
../../deps/3rd/u01/obclient/bin/mysqltest --host=127.0.0.1 --port=2881 --user=root \
  --database=test --test-file=mysql_test/test_suite/ai_function/t/ai_prompt.test \
  --result-file=mysql_test/test_suite/ai_function/r/mysql/ai_prompt.result
```
