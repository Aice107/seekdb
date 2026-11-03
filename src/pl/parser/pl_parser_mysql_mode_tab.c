
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1

/* Substitute the variable and function names.  */
#define yyparse         obpl_mysql_yyparse
#define yylex           obpl_mysql_yylex
#define yyerror         obpl_mysql_yyerror
#define yylval          obpl_mysql_yylval
#define yychar          obpl_mysql_yychar
#define yydebug         obpl_mysql_yydebug
#define yynerrs         obpl_mysql_yynerrs
#define yylloc          obpl_mysql_yylloc

/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 26 "../../../src/pl/parser/pl_parser_mysql_mode.y"

#include <stdint.h>
#define YYDEBUG 1


/* Line 189 of yacc.c  */
#line 87 "../../../src/pl/parser/pl_parser_mysql_mode_tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* "%code requires" blocks.  */

/* Line 209 of yacc.c  */
#line 37 "../../../src/pl/parser/pl_parser_mysql_mode.y"

#ifndef YYLTYPE_IS_DECLARED
#define YYLTYPE_IS_DECLARED 1
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
  int abs_first_column;
  int abs_last_column;
} YYLTYPE;
#endif /*YYLTYPE_IS_DECLARED*/

# define YYLLOC_DEFAULT(Current, Rhs, N)                        \
  do                                                            \
    if (YYID (N)) {                                             \
      (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;    \
      (Current).first_column = YYRHSLOC (Rhs, 1).first_column;  \
      (Current).last_line    = YYRHSLOC (Rhs, N).last_line;     \
      (Current).last_column  = YYRHSLOC (Rhs, N).last_column;   \
      (Current).abs_first_column = YYRHSLOC (Rhs, 1).abs_first_column;     \
      (Current).abs_last_column  = YYRHSLOC (Rhs, N).abs_last_column;      \
    } else {                                                    \
      (Current).first_line   = (Current).last_line   =          \
        YYRHSLOC (Rhs, 0).last_line;                            \
      (Current).first_column = (Current).last_column =          \
        YYRHSLOC (Rhs, 0).last_column;                          \
      (Current).abs_first_column = (Current).abs_last_column =          \
        YYRHSLOC (Rhs, 0).abs_last_column;                              \
    }                                                           \
  while (YYID (0))



/* Line 209 of yacc.c  */
#line 147 "../../../src/pl/parser/pl_parser_mysql_mode_tab.c"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     END_P = 258,
     SQL_KEYWORD = 259,
     SQL_TOKEN = 260,
     PARAM_ASSIGN_OPERATOR = 261,
     PARSER_SYNTAX_ERROR = 262,
     IDENT = 263,
     STRING = 264,
     INTNUM = 265,
     DECIMAL_VAL = 266,
     HEX_STRING_VALUE = 267,
     DATE_VALUE = 268,
     SYSTEM_VARIABLE = 269,
     USER_VARIABLE = 270,
     NULLX = 271,
     USER_NAME = 272,
     ALTER = 273,
     BEFORE = 274,
     BY = 275,
     CALL = 276,
     CASE = 277,
     CONDITION = 278,
     CONTINUE = 279,
     CREATE = 280,
     CURRENT_USER = 281,
     CURSOR = 282,
     DECLARE = 283,
     DEFAULT = 284,
     DELETE = 285,
     DETERMINISTIC = 286,
     DROP = 287,
     EACH = 288,
     ELSE = 289,
     ELSEIF = 290,
     EXISTS = 291,
     EXIT = 292,
     FETCH = 293,
     FOR = 294,
     FROM = 295,
     IF = 296,
     IN = 297,
     INDEX = 298,
     INOUT = 299,
     INSERT = 300,
     INTO = 301,
     IS = 302,
     ITERATE = 303,
     LEAVE = 304,
     LIMIT = 305,
     LONG = 306,
     LOOP = 307,
     MODIFIES = 308,
     NOT = 309,
     ON = 310,
     OR = 311,
     OUT = 312,
     PROCEDURE = 313,
     READS = 314,
     RENAME = 315,
     REPEAT = 316,
     REPLACE = 317,
     RESIGNAL = 318,
     RETURN = 319,
     SELECT = 320,
     SIGNAL = 321,
     SQL = 322,
     SQLEXCEPTION = 323,
     SQLSTATE = 324,
     SQLWARNING = 325,
     TABLE = 326,
     THEN = 327,
     TRIGGER = 328,
     UPDATE = 329,
     USING = 330,
     WHEN = 331,
     WHILE = 332,
     TINYINT = 333,
     SMALLINT = 334,
     MEDIUMINT = 335,
     INTEGER = 336,
     BIGINT = 337,
     FLOAT = 338,
     DOUBLE = 339,
     PRECISION = 340,
     DEC = 341,
     DECIMAL = 342,
     NUMERIC = 343,
     CHARACTER = 344,
     VARCHAR = 345,
     BINARY = 346,
     VARBINARY = 347,
     UNSIGNED = 348,
     ZEROFILL = 349,
     COLLATE = 350,
     SET = 351,
     BLOB = 352,
     TINYTEXT = 353,
     MEDIUMTEXT = 354,
     LONGTEXT = 355,
     TINYBLOB = 356,
     MEDIUMBLOB = 357,
     LONGBLOB = 358,
     VARYING = 359,
     LOAD = 360,
     CHARSET = 361,
     COMMIT = 362,
     ROLLBACK = 363,
     DO = 364,
     UNTIL = 365,
     AFTER = 366,
     AT = 367,
     AUTHID = 368,
     BEGIN_KEY = 369,
     BINARY_INTEGER = 370,
     BODY = 371,
     C = 372,
     CATALOG_NAME = 373,
     CLASS_ORIGIN = 374,
     CLOSE = 375,
     COLUMN_NAME = 376,
     COMMENT = 377,
     CONSTRAINT_CATALOG = 378,
     CONSTRAINT_NAME = 379,
     CONSTRAINT_ORIGIN = 380,
     CONSTRAINT_SCHEMA = 381,
     CONTAINS = 382,
     COUNT = 383,
     CURSOR_NAME = 384,
     DATA = 385,
     DAY = 386,
     DEFINER = 387,
     DISABLE = 388,
     ENABLE = 389,
     END_KEY = 390,
     EXTEND = 391,
     FOLLOWS = 392,
     FOUND = 393,
     FUNCTION = 394,
     HANDLER = 395,
     HOUR = 396,
     INTERFACE = 397,
     INTERVAL = 398,
     INVOKER = 399,
     JSON = 400,
     LANGUAGE = 401,
     MESSAGE_TEXT = 402,
     MINUTE = 403,
     MONTH = 404,
     MYSQL_ERRNO = 405,
     NATIONAL = 406,
     NEXT = 407,
     NO = 408,
     OF = 409,
     OPEN = 410,
     PACKAGE = 411,
     PRAGMA = 412,
     PRECEDES = 413,
     RECORD = 414,
     RETURNS = 415,
     ROW = 416,
     ROWTYPE = 417,
     SCHEMA_NAME = 418,
     SECOND = 419,
     SECURITY = 420,
     SUBCLASS_ORIGIN = 421,
     TABLE_NAME = 422,
     TO = 423,
     USER = 424,
     TYPE = 425,
     VALUE = 426,
     DATETIME = 427,
     TIMESTAMP = 428,
     TIME = 429,
     DATE = 430,
     YEAR = 431,
     TEXT = 432,
     NCHAR = 433,
     NVARCHAR = 434,
     BOOL = 435,
     BOOLEAN = 436,
     ENUM = 437,
     BIT = 438,
     FIXED = 439,
     SIGNED = 440,
     STARTS = 441,
     ROLE = 442,
     SUBMIT = 443,
     CANCEL = 444,
     JOB = 445,
     RECOVER = 446,
     GEOMETRY = 447,
     POINT = 448,
     LINESTRING = 449,
     POLYGON = 450,
     MULTIPOINT = 451,
     MULTILINESTRING = 452,
     MULTIPOLYGON = 453,
     GEOMETRYCOLLECTION = 454,
     GEOMCOLLECTION = 455,
     SERIAL = 456,
     LOWER_PARENS = 457,
     PARENS = 458,
     DECLARATION = 459
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 31 "../../../src/pl/parser/pl_parser_mysql_mode.y"

  struct _ParseNode *node;
  const struct _NonReservedKeyword *non_reserved_keyword;
  int64_t ival;



/* Line 214 of yacc.c  */
#line 376 "../../../src/pl/parser/pl_parser_mysql_mode_tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */

/* Line 264 of yacc.c  */
#line 71 "../../../src/pl/parser/pl_parser_mysql_mode.y"

#include "pl/parser/pl_parser_mysql_mode_lex.h"
#include "pl/parser/pl_parser_base.h"

typedef struct _YYLookaheadToken
{
  int *la_yychar;
  /* The semantic value of the lookahead symbol.  */
  YYSTYPE *la_yylval;
  /* Location data for the lookahead symbol.  */
  YYLTYPE *la_yylloc;
} YYLookaheadToken;

extern ParseNode *obpl_mysql_read_sql_construct(ObParseCtx *parse_ctx, const char *prefix, YYLookaheadToken *la_token, int end_token_cnt, ...);
extern void obpl_mysql_yyerror(YYLTYPE *yylloc, ObParseCtx *parse_ctx, char *s);
extern void obpl_mysql_parse_fatal_error(int32_t errcode, yyscan_t yyscanner, yyconst char *msg, ...);

int obpl_mysql_check_specific_node(const ParseNode *node, const ObItemType type, int *is_contain) {
  int ret = OB_PARSER_SUCCESS;
  if (obpl_parser_check_stack_overflow()) {
    ret = OB_PARSER_ERR_SIZE_OVERFLOW;
  } else if (OB_UNLIKELY(NULL == is_contain)) {
    ret = OB_PARSER_ERR_UNEXPECTED;
  } else {
    *is_contain = false;
  }

  if (OB_PARSER_SUCCESS == ret && OB_NOT_NULL(node)) {
    if (type == node->type_) {
      *is_contain = true;
    } else {
      for (int64_t i = 0; OB_PARSER_SUCCESS == ret && !*is_contain && i < node->num_child_; ++i) {
        ret = obpl_mysql_check_specific_node(node->children_[i], type, is_contain);
      }
    }
  }
  return ret;
}

int obpl_mysql_wrap_node_into_subquery(ObParseCtx *_parse_ctx, ParseNode *node) {
  int ret = OB_PARSER_SUCCESS;
  if (OB_NOT_NULL(node) && OB_NOT_NULL(node->str_value_)) {
    int max_query_len = node->str_len_ + 22;
    char *subquery = (char *)parse_malloc(max_query_len, _parse_ctx->mem_pool_);
    int len = 0;
    if (OB_UNLIKELY(NULL == subquery)) {
      ret = OB_PARSER_ERR_NO_MEMORY;
    } else if ((len = snprintf(subquery, max_query_len, "(SELECT %s AS SUBQUERY)", node->str_value_)) <= 0) {
      ret = OB_PARSER_ERR_UNEXPECTED;
    } else {
      ParseResult parse_result;
      memset(&parse_result, 0, sizeof(ParseResult));
      parse_result.input_sql_ = subquery;
      parse_result.input_sql_len_ = len;
      parse_result.malloc_pool_ = _parse_ctx->mem_pool_;
      parse_result.pl_parse_info_.is_pl_parse_ = true;
      parse_result.pl_parse_info_.is_pl_parse_expr_ = true;
      parse_result.is_for_trigger_ = (1 == _parse_ctx->is_for_trigger_);
      parse_result.question_mark_ctx_ = _parse_ctx->question_mark_ctx_;
      parse_result.charset_info_ = _parse_ctx->charset_info_;
      parse_result.charset_info_nls_db_ = _parse_ctx->charset_info_nls_db_;
      parse_result.is_not_utf8_connection_ = _parse_ctx->is_not_utf8_connection_;
      parse_result.connection_collation_ = _parse_ctx->connection_collation_;
      parse_result.sql_mode_ = _parse_ctx->scanner_ctx_.sql_mode_;
      parse_result.semicolon_start_col_ = INT32_MAX;
      if (0 == parse_sql_stmt(&parse_result)) {
        *node = *parse_result.result_tree_->children_[0];
        node->str_value_ = subquery;
        node->str_len_ = len;
        node->pl_str_off_ = -1;
      }
    }
  }
  return ret;
}

void obpl_mysql_wrap_get_user_var_into_subquery(ObParseCtx *parse_ctx, ParseNode *node) {
  int ret = OB_PARSER_SUCCESS;
  int is_contain = false;
  if (OB_PARSER_SUCCESS != (ret = obpl_mysql_check_specific_node(node, T_OP_GET_USER_VAR, &is_contain))) {
    obpl_mysql_parse_fatal_error(ret, YYLEX_PARAM, "failed to check T_OP_GET_USER_VAR in parse tree");
  } else if (is_contain) {
    if (OB_PARSER_SUCCESS != (ret = obpl_mysql_wrap_node_into_subquery(parse_ctx, node))) {
      obpl_mysql_parse_fatal_error(ret, YYLEX_PARAM, "failed to wrap T_OP_GET_USER_VAR into subquery");
    }
  }
}

#define YY_FATAL_ERROR(msg, args...) (obpl_mysql_parse_fatal_error(OB_PARSER_ERR_NO_MEMORY, YYLEX_PARAM, msg, ##args))
#define YY_UNEXPECTED_ERROR(msg, args...) (obpl_mysql_parse_fatal_error(OB_PARSER_ERR_UNEXPECTED, YYLEX_PARAM, msg, ##args))

#define do_parse_sql_stmt(node, _parse_ctx, start_loc, end_loc, end_tok_num, ...)                          \
  do {                                                                                                     \
    YYLookaheadToken la_token;                                                                             \
    la_token.la_yychar = &yychar;                                                                          \
    la_token.la_yylval = &yylval;                                                                          \
    la_token.la_yylloc = &yylloc;                                                                          \
    _parse_ctx->scanner_ctx_.sql_start_loc = start_loc;                                                    \
    _parse_ctx->scanner_ctx_.sql_end_loc = end_loc;                                                        \
    node = obpl_mysql_read_sql_construct(_parse_ctx, "", &la_token, end_tok_num, ##__VA_ARGS__);           \
    if (NULL == node) {                                                                                    \
      YYERROR;                                                                                             \
    }                                                                                                      \
    reset_current_location(_parse_ctx->scanner_ctx_.sql_start_loc, _parse_ctx->scanner_ctx_.sql_end_loc);  \
  } while (0)

#define do_parse_sql_expr_rule(node, _parse_ctx, end_tok_num, ...)                                         \
  do {                                                                                                     \
    ParseNode *select_node = NULL;                                                                         \
    YYLookaheadToken la_token;                                                                             \
    la_token.la_yychar = &yychar;                                                                          \
    la_token.la_yylval = &yylval;                                                                          \
    la_token.la_yylloc = &yylloc;                                                                          \
    _parse_ctx->scanner_ctx_.sql_start_loc = -1;                                                           \
    _parse_ctx->scanner_ctx_.sql_end_loc = -1;                                                             \
    select_node = obpl_mysql_read_sql_construct(_parse_ctx, "SELECT ", &la_token, end_tok_num, ##__VA_ARGS__);        \
    reset_current_location(_parse_ctx->scanner_ctx_.sql_start_loc, _parse_ctx->scanner_ctx_.sql_end_loc);  \
    if (select_node != NULL) {                                                                             \
      if (NULL == select_node->children_[2] || NULL == select_node->children_[2]->children_[0]) {          \
        YYERROR;                                                                                           \
      } else {                                                                                             \
        node = select_node->children_[2]->children_[0]->children_[0];                                      \
      }                                                                                                    \
    } else {                                                                                               \
      node = NULL;                                                                                         \
    }                                                                                                      \
} while (0)


/* Line 264 of yacc.c  */
#line 531 "../../../src/pl/parser/pl_parser_mysql_mode_tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  214
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   6792

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  214
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  156
/* YYNRULES -- Number of rules.  */
#define YYNRULES  510
/* YYNRULES -- Number of states.  */
#define YYNSTATES  784

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   459

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   213,     2,     2,
     204,   205,     2,     2,   209,     2,   210,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   212,   207,
       2,   211,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   208,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   206
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,    10,    12,    14,    15,    17,    19,
      21,    23,    25,    27,    29,    31,    33,    35,    37,    39,
      41,    43,    45,    47,    49,    51,    53,    55,    57,    59,
      62,    64,    66,    68,    70,    72,    74,    76,    79,    82,
      85,    90,    93,    96,    99,   101,   103,   105,   107,   110,
     113,   116,   119,   122,   126,   129,   139,   148,   160,   171,
     172,   175,   179,   183,   185,   188,   189,   192,   193,   197,
     199,   205,   209,   211,   213,   215,   217,   219,   221,   223,
     225,   227,   229,   231,   233,   235,   237,   239,   241,   243,
     245,   247,   249,   251,   253,   255,   257,   259,   261,   263,
     265,   267,   269,   271,   273,   275,   277,   279,   281,   283,
     285,   287,   289,   291,   293,   295,   297,   299,   301,   303,
     305,   307,   309,   311,   313,   315,   317,   319,   321,   323,
     325,   327,   329,   331,   333,   335,   337,   339,   341,   343,
     345,   347,   349,   351,   353,   355,   357,   359,   361,   363,
     365,   367,   369,   371,   373,   375,   377,   379,   381,   383,
     385,   387,   389,   391,   395,   402,   405,   408,   410,   413,
     415,   416,   418,   419,   422,   423,   425,   429,   432,   434,
     436,   438,   446,   452,   453,   455,   459,   467,   474,   481,
     487,   491,   496,   504,   507,   511,   513,   515,   517,   519,
     522,   525,   529,   534,   543,   554,   565,   567,   569,   571,
     573,   575,   577,   582,   593,   603,   616,   628,   629,   634,
     639,   641,   643,   645,   646,   647,   650,   651,   653,   657,
     659,   664,   665,   667,   671,   673,   676,   677,   679,   681,
     683,   685,   687,   691,   696,   702,   704,   707,   709,   711,
     714,   717,   720,   723,   726,   730,   734,   738,   742,   744,
     746,   751,   756,   757,   759,   761,   764,   766,   768,   770,
     772,   774,   776,   778,   780,   782,   784,   786,   788,   790,
     792,   794,   796,   801,   806,   810,   817,   823,   825,   828,
     833,   836,   839,   841,   844,   848,   852,   857,   862,   864,
     865,   867,   870,   874,   877,   881,   882,   886,   891,   897,
     904,   910,   912,   914,   916,   920,   922,   924,   926,   929,
     931,   933,   935,   939,   942,   945,   949,   954,   960,   963,
     964,   966,   968,   972,   974,   975,   978,   979,   982,   983,
     985,   989,   990,   995,  1002,  1009,  1014,  1017,  1020,  1023,
    1028,  1033,  1034,  1037,  1038,  1042,  1044,  1046,  1049,  1053,
    1057,  1062,  1066,  1071,  1074,  1078,  1082,  1087,  1091,  1096,
    1099,  1103,  1107,  1112,  1116,  1121,  1124,  1126,  1132,  1137,
    1144,  1150,  1155,  1158,  1161,  1163,  1166,  1168,  1170,  1173,
    1179,  1187,  1195,  1197,  1199,  1201,  1203,  1205,  1207,  1209,
    1211,  1213,  1215,  1219,  1221,  1223,  1225,  1227,  1229,  1231,
    1233,  1235,  1238,  1240,  1242,  1244,  1246,  1248,  1250,  1252,
    1254,  1257,  1259,  1262,  1264,  1267,  1270,  1274,  1278,  1279,
    1283,  1284,  1290,  1294,  1298,  1299,  1305,  1309,  1310,  1314,
    1315,  1319,  1320,  1322,  1324,  1326,  1328,  1330,  1332,  1334,
    1336,  1338,  1340,  1343,  1345,  1347,  1349,  1351,  1353,  1356,
    1358,  1359,  1363,  1365,  1369,  1371,  1373,  1375,  1376,  1378,
    1379,  1381,  1383,  1385,  1387,  1389,  1392,  1393,  1395,  1398,
    1401,  1403,  1404,  1408,  1412,  1413,  1415,  1417,  1419,  1420,
    1423,  1425,  1429,  1433,  1435,  1437,  1439,  1441,  1443,  1445,
    1447,  1449,  1451,  1453,  1455,  1457,  1459,  1461,  1463,  1465,
    1467
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     215,     0,    -1,   216,     3,    -1,   216,   207,   217,    -1,
     217,    -1,   218,    -1,    -1,   259,    -1,   260,    -1,   324,
      -1,   325,    -1,   279,    -1,   280,    -1,   233,    -1,   246,
      -1,   248,    -1,   221,    -1,   223,    -1,   222,    -1,   360,
      -1,   361,    -1,   234,    -1,   247,    -1,   252,    -1,   258,
      -1,   253,    -1,     4,    -1,    71,    -1,   169,    -1,   204,
     220,    -1,     4,    -1,    45,    -1,    30,    -1,    74,    -1,
     105,    -1,   220,    -1,    62,    -1,    25,   219,    -1,    25,
     187,    -1,    32,   187,    -1,    25,    56,    62,   219,    -1,
      32,   219,    -1,    18,   219,    -1,    60,   219,    -1,    96,
      -1,   107,    -1,   108,    -1,    65,    -1,   204,    65,    -1,
     109,   317,    -1,   109,   307,    -1,   109,   309,    -1,   109,
     308,    -1,    21,   230,   224,    -1,   208,   283,    -1,   208,
      58,   327,   229,   204,   265,   205,   274,   277,    -1,   208,
      58,   327,   229,   204,   265,   205,   277,    -1,   208,   139,
     327,   229,   204,   268,   205,   160,   313,   274,   278,    -1,
     208,   139,   327,   229,   204,   268,   205,   160,   313,   278,
      -1,    -1,   204,   205,    -1,   204,   225,   205,    -1,   225,
     209,   226,    -1,   226,    -1,   228,   227,    -1,    -1,     6,
     228,    -1,    -1,   231,   210,   231,    -1,   231,    -1,   231,
     210,   231,   210,   231,    -1,   231,   210,   231,    -1,   231,
      -1,     8,    -1,   232,    -1,   111,    -1,   112,    -1,   113,
      -1,   114,    -1,   115,    -1,   116,    -1,   117,    -1,   118,
      -1,   119,    -1,   120,    -1,   121,    -1,   122,    -1,   123,
      -1,   124,    -1,   125,    -1,   126,    -1,   127,    -1,   128,
      -1,   129,    -1,   130,    -1,   132,    -1,   133,    -1,   134,
      -1,   135,    -1,   136,    -1,   138,    -1,   139,    -1,   140,
      -1,   142,    -1,   144,    -1,   145,    -1,   146,    -1,   147,
      -1,   150,    -1,   152,    -1,   153,    -1,   154,    -1,   155,
      -1,   169,    -1,   156,    -1,   157,    -1,   159,    -1,   160,
      -1,   161,    -1,   162,    -1,   187,    -1,   163,    -1,   165,
      -1,   186,    -1,   166,    -1,   167,    -1,   168,    -1,   170,
      -1,   171,    -1,   137,    -1,   158,    -1,   151,    -1,   172,
      -1,   173,    -1,   174,    -1,   175,    -1,   176,    -1,   177,
      -1,   178,    -1,   179,    -1,   180,    -1,   181,    -1,   182,
      -1,   183,    -1,   184,    -1,   185,    -1,   191,    -1,   192,
      -1,   193,    -1,   194,    -1,   195,    -1,   196,    -1,   197,
      -1,   198,    -1,   199,    -1,   200,    -1,   149,    -1,   131,
      -1,   141,    -1,   148,    -1,   164,    -1,   143,    -1,   201,
      -1,    25,   239,   234,    -1,   156,   229,   238,   240,   135,
     245,    -1,   113,    26,    -1,   113,   132,    -1,   235,    -1,
     237,   236,    -1,   236,    -1,    -1,   237,    -1,    -1,    56,
      62,    -1,    -1,   241,    -1,   241,   242,   207,    -1,   242,
     207,    -1,   301,    -1,   243,    -1,   244,    -1,   139,   231,
     204,   265,   205,    64,   313,    -1,    58,   231,   204,   265,
     205,    -1,    -1,   231,    -1,    25,   239,   247,    -1,   156,
     116,   229,   250,   298,   135,   245,    -1,   156,   116,   229,
     298,   135,   245,    -1,   156,   116,   229,   250,   135,   245,
      -1,   156,   116,   229,   135,   245,    -1,    32,   156,   229,
      -1,    32,   156,   116,   229,    -1,   157,   142,   204,   117,
     209,   231,   205,    -1,   251,   207,    -1,   250,   251,   207,
      -1,   301,    -1,   243,    -1,   244,    -1,   249,    -1,   243,
     278,    -1,   244,   277,    -1,    25,   261,   253,    -1,    73,
     327,   229,   254,    -1,   255,   256,    55,   229,    39,    33,
     161,   257,    -1,   255,   256,    55,   229,    39,    33,   161,
     137,   229,   257,    -1,   255,   256,    55,   229,    39,    33,
     161,   158,   229,   257,    -1,    19,    -1,   111,    -1,    45,
      -1,    30,    -1,    74,    -1,   283,    -1,    32,    73,   326,
     229,    -1,    25,   261,    58,   327,   229,   204,   265,   205,
     274,   277,    -1,    25,   261,    58,   327,   229,   204,   265,
     205,   277,    -1,    25,   261,   139,   327,   229,   204,   268,
     205,   160,   313,   274,   278,    -1,    25,   261,   139,   327,
     229,   204,   268,   205,   160,   313,   278,    -1,    -1,   132,
     211,   262,   263,    -1,   132,   211,    26,   264,    -1,     9,
      -1,     8,    -1,    15,    -1,    -1,    -1,   204,   205,    -1,
      -1,   266,    -1,   266,   209,   267,    -1,   267,    -1,   271,
     231,   272,   315,    -1,    -1,   269,    -1,   269,   209,   270,
      -1,   270,    -1,   231,   272,    -1,    -1,    42,    -1,    57,
      -1,    44,    -1,   313,    -1,   231,    -1,   231,   210,   231,
      -1,   210,   231,   210,   231,    -1,   231,   210,   231,   210,
     231,    -1,   275,    -1,   274,   275,    -1,   276,    -1,    31,
      -1,    54,    31,    -1,   122,     9,    -1,   146,    67,    -1,
     153,    67,    -1,   127,    67,    -1,    59,    67,   130,    -1,
      53,    67,   130,    -1,    67,   165,   132,    -1,    67,   165,
     144,    -1,   283,    -1,   286,    -1,    18,    58,   229,   281,
      -1,    18,   139,   229,   281,    -1,    -1,   282,    -1,   276,
      -1,   282,   276,    -1,   284,    -1,   285,    -1,   218,    -1,
     286,    -1,   322,    -1,   323,    -1,   307,    -1,   309,    -1,
     308,    -1,   287,    -1,   289,    -1,   293,    -1,   295,    -1,
     319,    -1,   320,    -1,   321,    -1,    41,   288,   135,    41,
      -1,   318,    72,   298,   292,    -1,   318,    72,   298,    -1,
      22,   318,   290,   292,   135,    22,    -1,    22,   318,   290,
     135,    22,    -1,   291,    -1,   290,   291,    -1,    76,   318,
      72,   298,    -1,    35,   288,    -1,    34,   298,    -1,   294,
      -1,   114,   135,    -1,   114,   299,   135,    -1,   114,   298,
     135,    -1,   114,   299,   298,   135,    -1,   296,   212,   294,
     297,    -1,   231,    -1,    -1,   296,    -1,   283,   207,    -1,
     298,   283,   207,    -1,   299,   207,    -1,   300,   301,   207,
      -1,    -1,   300,   301,   207,    -1,    28,   312,   313,   314,
      -1,    28,   231,    23,    39,   305,    -1,    28,   302,   140,
      39,   303,   283,    -1,    28,   231,    27,    39,   221,    -1,
      37,    -1,    24,    -1,   304,    -1,   303,   209,   304,    -1,
     305,    -1,   231,    -1,    70,    -1,    54,   138,    -1,    68,
      -1,   344,    -1,   306,    -1,    69,   311,     9,    -1,   155,
     231,    -1,   120,   231,    -1,    38,   231,   310,    -1,    38,
      40,   231,   310,    -1,    38,   152,    40,   231,   310,    -1,
      46,   317,    -1,    -1,   171,    -1,   231,    -1,   312,   209,
     231,    -1,   329,    -1,    -1,    29,   316,    -1,    -1,    29,
     316,    -1,    -1,   318,    -1,   317,   209,   318,    -1,    -1,
      52,   298,   135,    52,    -1,    77,   318,   109,   298,   135,
      77,    -1,    61,   298,   110,   318,   135,    61,    -1,   296,
     212,   319,   297,    -1,    64,   318,    -1,    48,   296,    -1,
      49,   296,    -1,    32,    58,   326,   229,    -1,    32,   139,
     326,   229,    -1,    -1,    41,    36,    -1,    -1,    41,    54,
      36,    -1,   199,    -1,   200,    -1,   331,   338,    -1,   331,
     338,    94,    -1,   331,   338,   185,    -1,   331,   338,   185,
      94,    -1,   331,   338,    93,    -1,   331,   338,    93,    94,
      -1,   332,   340,    -1,   332,   340,    94,    -1,   332,   340,
     185,    -1,   332,   340,   185,    94,    -1,   332,   340,    93,
      -1,   332,   340,    93,    94,    -1,   334,   341,    -1,   334,
     341,    94,    -1,   334,   341,   185,    -1,   334,   341,   185,
      94,    -1,   334,   341,    93,    -1,   334,   341,    93,    94,
      -1,   333,   343,    -1,   335,    -1,    89,   352,   353,   356,
     359,    -1,   336,   352,   353,   359,    -1,    89,   104,   349,
     353,   356,   359,    -1,    90,   349,   353,   356,   359,    -1,
     337,   352,   353,   359,    -1,    91,   352,    -1,    92,   349,
      -1,     9,    -1,   183,   339,    -1,   180,    -1,   181,    -1,
     347,   348,    -1,   346,   348,   353,   356,   359,    -1,   182,
     204,   350,   205,   353,   356,   359,    -1,    96,   204,   350,
     205,   353,   356,   359,    -1,   145,    -1,   192,    -1,   193,
      -1,   194,    -1,   195,    -1,   196,    -1,   197,    -1,   198,
      -1,   328,    -1,   201,    -1,   330,   213,   162,    -1,   230,
      -1,    78,    -1,    79,    -1,    80,    -1,    81,    -1,    82,
      -1,    83,    -1,    84,    -1,    84,    85,    -1,   172,    -1,
     173,    -1,   174,    -1,    86,    -1,    87,    -1,    88,    -1,
     184,    -1,   175,    -1,   176,   342,    -1,   178,    -1,   151,
      89,    -1,   179,    -1,   178,    90,    -1,   151,    90,    -1,
     151,    89,   104,    -1,   204,    10,   205,    -1,    -1,   204,
      10,   205,    -1,    -1,   204,    10,   209,    10,   205,    -1,
     204,    10,   205,    -1,   204,    11,   205,    -1,    -1,   204,
      10,   209,    10,   205,    -1,   204,    10,   205,    -1,    -1,
     204,    10,   205,    -1,    -1,   204,    10,   205,    -1,    -1,
      10,    -1,    11,    -1,   344,    -1,    13,    -1,    12,    -1,
      16,    -1,    98,    -1,   177,    -1,    99,    -1,   100,    -1,
      51,    90,    -1,    51,    -1,   101,    -1,    97,    -1,   102,
      -1,   103,    -1,    51,    92,    -1,   349,    -1,    -1,   204,
     344,   205,    -1,   351,    -1,   350,   209,   351,    -1,     9,
      -1,    12,    -1,   349,    -1,    -1,    91,    -1,    -1,   231,
      -1,     9,    -1,   231,    -1,     9,    -1,    91,    -1,   357,
     355,    -1,    -1,   106,    -1,    89,    96,    -1,    95,   354,
      -1,   358,    -1,    -1,    66,   363,   364,    -1,    63,   362,
     364,    -1,    -1,   363,    -1,   231,    -1,   306,    -1,    -1,
      96,   365,    -1,   366,    -1,   365,   209,   366,    -1,   369,
     211,   367,    -1,   345,    -1,   368,    -1,   273,    -1,     9,
      -1,    14,    -1,    15,    -1,   119,    -1,   166,    -1,   123,
      -1,   126,    -1,   124,    -1,   118,    -1,   163,    -1,   167,
      -1,   121,    -1,   129,    -1,   147,    -1,   150,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   302,   302,   311,   316,   332,   357,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   394,   395,   396,   400,
     401,   402,   403,   404,   405,   409,   416,   423,   430,   437,
     444,   451,   458,   465,   472,   503,   511,   519,   526,   536,
     591,   592,   593,   597,   601,   609,   617,   625,   633,   644,
     645,   646,   653,   660,   664,   681,   682,   691,   706,   710,
     717,   721,   725,   732,   742,   750,   751,   752,   753,   754,
     755,   756,   757,   758,   759,   760,   761,   762,   763,   764,
     765,   766,   767,   768,   769,   770,   771,   772,   773,   774,
     775,   776,   777,   778,   779,   780,   781,   782,   783,   784,
     785,   786,   787,   788,   789,   790,   791,   792,   793,   794,
     795,   796,   797,   798,   799,   800,   801,   802,   803,   804,
     805,   806,   807,   808,   809,   810,   811,   812,   813,   814,
     815,   816,   817,   818,   819,   820,   821,   822,   823,   824,
     825,   826,   827,   828,   829,   830,   831,   832,   833,   834,
     835,   836,   837,   846,   861,   878,   883,   891,   895,   899,
     903,   904,   911,   912,   916,   917,   924,   928,   931,   932,
     933,   937,   950,   963,   964,   973,   990,  1006,  1021,  1035,
    1055,  1060,  1068,  1075,  1076,  1083,  1084,  1085,  1086,  1087,
    1097,  1115,  1125,  1140,  1145,  1152,  1161,  1162,  1166,  1167,
    1168,  1172,  1197,  1210,  1232,  1255,  1277,  1300,  1301,  1305,
    1316,  1320,  1326,  1331,  1338,  1339,  1343,  1344,  1351,  1355,
    1359,  1368,  1369,  1376,  1380,  1384,  1392,  1393,  1394,  1395,
    1399,  1402,  1406,  1410,  1414,  1421,  1422,  1429,  1430,  1434,
    1438,  1444,  1445,  1450,  1455,  1460,  1465,  1470,  1478,  1482,
    1491,  1498,  1505,  1506,  1513,  1514,  1520,  1525,  1533,  1545,
    1550,  1555,  1560,  1565,  1570,  1578,  1582,  1586,  1590,  1594,
    1598,  1602,  1609,  1613,  1622,  1634,  1640,  1649,  1650,  1657,
    1672,  1678,  1687,  1691,  1695,  1701,  1707,  1718,  1725,  1729,
    1730,  1737,  1738,  1745,  1749,  1757,  1758,  1765,  1772,  1777,
    1787,  1804,  1805,  1809,  1810,  1817,  1818,  1819,  1820,  1821,
    1825,  1829,  1836,  1844,  1851,  1858,  1862,  1866,  1873,  1894,
    1895,  1898,  1899,  1906,  1910,  1911,  1921,  1922,  1941,  1947,
    1948,  1955,  1963,  1969,  1975,  1984,  1991,  1999,  2006,  2013,
    2021,  2029,  2030,  2034,  2035,  2039,  2040,  2044,  2050,  2056,
    2062,  2068,  2074,  2080,  2094,  2108,  2122,  2136,  2150,  2164,
    2175,  2186,  2197,  2208,  2219,  2230,  2235,  2239,  2248,  2269,
    2275,  2281,  2295,  2304,  2310,  2316,  2321,  2327,  2333,  2343,
    2353,  2361,  2369,  2374,  2380,  2386,  2392,  2398,  2404,  2410,
    2416,  2423,  2429,  2441,  2447,  2448,  2449,  2450,  2451,  2455,
    2456,  2457,  2461,  2462,  2463,  2467,  2468,  2469,  2470,  2473,
    2474,  2478,  2479,  2483,  2484,  2485,  2486,  2490,  2491,  2495,
    2496,  2500,  2506,  2512,  2520,  2524,  2539,  2551,  2560,  2561,
    2565,  2570,  2576,  2581,  2589,  2590,  2591,  2592,  2596,  2597,
    2598,  2599,  2600,  2601,  2605,  2606,  2607,  2608,  2609,  2613,
    2614,  2617,  2655,  2659,  2666,  2670,  2677,  2682,  2688,  2693,
    2697,  2703,  2711,  2718,  2724,  2737,  2744,  2748,  2752,  2759,
    2769,  2773,  2777,  2784,  2791,  2792,  2796,  2797,  2801,  2802,
    2809,  2810,  2817,  2825,  2826,  2827,  2828,  2832,  2833,  2837,
    2838,  2839,  2840,  2841,  2842,  2843,  2844,  2845,  2846,  2847,
    2848
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "END_P", "SQL_KEYWORD", "SQL_TOKEN",
  "PARAM_ASSIGN_OPERATOR", "PARSER_SYNTAX_ERROR", "IDENT", "STRING",
  "INTNUM", "DECIMAL_VAL", "HEX_STRING_VALUE", "DATE_VALUE",
  "SYSTEM_VARIABLE", "USER_VARIABLE", "NULLX", "USER_NAME", "ALTER",
  "BEFORE", "BY", "CALL", "CASE", "CONDITION", "CONTINUE", "CREATE",
  "CURRENT_USER", "CURSOR", "DECLARE", "DEFAULT", "DELETE",
  "DETERMINISTIC", "DROP", "EACH", "ELSE", "ELSEIF", "EXISTS", "EXIT",
  "FETCH", "FOR", "FROM", "IF", "IN", "INDEX", "INOUT", "INSERT", "INTO",
  "IS", "ITERATE", "LEAVE", "LIMIT", "LONG", "LOOP", "MODIFIES", "NOT",
  "ON", "OR", "OUT", "PROCEDURE", "READS", "RENAME", "REPEAT", "REPLACE",
  "RESIGNAL", "RETURN", "SELECT", "SIGNAL", "SQL", "SQLEXCEPTION",
  "SQLSTATE", "SQLWARNING", "TABLE", "THEN", "TRIGGER", "UPDATE", "USING",
  "WHEN", "WHILE", "TINYINT", "SMALLINT", "MEDIUMINT", "INTEGER", "BIGINT",
  "FLOAT", "DOUBLE", "PRECISION", "DEC", "DECIMAL", "NUMERIC", "CHARACTER",
  "VARCHAR", "BINARY", "VARBINARY", "UNSIGNED", "ZEROFILL", "COLLATE",
  "SET", "BLOB", "TINYTEXT", "MEDIUMTEXT", "LONGTEXT", "TINYBLOB",
  "MEDIUMBLOB", "LONGBLOB", "VARYING", "LOAD", "CHARSET", "COMMIT",
  "ROLLBACK", "DO", "UNTIL", "AFTER", "AT", "AUTHID", "BEGIN_KEY",
  "BINARY_INTEGER", "BODY", "C", "CATALOG_NAME", "CLASS_ORIGIN", "CLOSE",
  "COLUMN_NAME", "COMMENT", "CONSTRAINT_CATALOG", "CONSTRAINT_NAME",
  "CONSTRAINT_ORIGIN", "CONSTRAINT_SCHEMA", "CONTAINS", "COUNT",
  "CURSOR_NAME", "DATA", "DAY", "DEFINER", "DISABLE", "ENABLE", "END_KEY",
  "EXTEND", "FOLLOWS", "FOUND", "FUNCTION", "HANDLER", "HOUR", "INTERFACE",
  "INTERVAL", "INVOKER", "JSON", "LANGUAGE", "MESSAGE_TEXT", "MINUTE",
  "MONTH", "MYSQL_ERRNO", "NATIONAL", "NEXT", "NO", "OF", "OPEN",
  "PACKAGE", "PRAGMA", "PRECEDES", "RECORD", "RETURNS", "ROW", "ROWTYPE",
  "SCHEMA_NAME", "SECOND", "SECURITY", "SUBCLASS_ORIGIN", "TABLE_NAME",
  "TO", "USER", "TYPE", "VALUE", "DATETIME", "TIMESTAMP", "TIME", "DATE",
  "YEAR", "TEXT", "NCHAR", "NVARCHAR", "BOOL", "BOOLEAN", "ENUM", "BIT",
  "FIXED", "SIGNED", "STARTS", "ROLE", "SUBMIT", "CANCEL", "JOB",
  "RECOVER", "GEOMETRY", "POINT", "LINESTRING", "POLYGON", "MULTIPOINT",
  "MULTILINESTRING", "MULTIPOLYGON", "GEOMETRYCOLLECTION",
  "GEOMCOLLECTION", "SERIAL", "LOWER_PARENS", "PARENS", "'('", "')'",
  "DECLARATION", "';'", "'^'", "','", "'.'", "'='", "':'", "'%'",
  "$accept", "stmt_block", "stmt_list", "stmt", "outer_stmt",
  "sql_keyword", "sql_stmt_prefix", "sql_stmt", "do_sp_stmt",
  "call_sp_stmt", "opt_sp_cparam_list", "sp_cparams", "sp_cparam",
  "opt_sp_cparam_with_assign", "cexpr", "sp_name", "sp_call_name", "ident",
  "unreserved_keyword", "create_package_stmt", "package_block",
  "invoke_right", "proc_clause", "proc_clause_list", "opt_proc_clause",
  "opt_replace", "opt_package_stmts", "package_stmts", "package_stmt",
  "func_decl", "proc_decl", "opt_tail_package_name",
  "create_package_body_stmt", "package_body_block", "drop_package_stmt",
  "interface_pragma", "decl_stmt_ext_list", "decl_stmt_ext",
  "create_trigger_stmt", "plsql_trigger_source", "trigger_definition",
  "trigger_time", "trigger_event", "trigger_body", "drop_trigger_stmt",
  "create_procedure_stmt", "create_function_stmt", "opt_sp_definer",
  "user", "opt_host_name", "opt_parentheses", "opt_sp_param_list",
  "sp_param_list", "sp_param", "opt_sp_fparam_list", "sp_fparam_list",
  "sp_fparam", "opt_sp_inout", "param_type", "simple_ident",
  "sp_create_chistics", "sp_create_chistic", "sp_chistic",
  "procedure_body", "function_body", "alter_procedure_stmt",
  "alter_function_stmt", "opt_sp_alter_chistics", "sp_alter_chistics",
  "sp_proc_stmt", "sp_proc_outer_statement", "sp_proc_inner_statement",
  "sp_proc_independent_statement", "sp_proc_stmt_if", "sp_if",
  "sp_proc_stmt_case", "sp_when_list", "sp_when", "sp_elseifs",
  "sp_unlabeled_block", "sp_block_content", "sp_labeled_block",
  "label_ident", "opt_sp_label", "sp_proc_stmts", "sp_decls",
  "opt_sp_decls", "sp_decl", "sp_handler_type", "sp_hcond_list",
  "sp_hcond", "sp_cond", "sqlstate", "sp_proc_stmt_open",
  "sp_proc_stmt_close", "sp_proc_stmt_fetch", "into_clause", "opt_value",
  "sp_decl_idents", "sp_data_type", "opt_sp_decl_default",
  "opt_param_default", "default_expr", "expr_list", "expr",
  "sp_unlabeled_control", "sp_labeled_control", "sp_proc_stmt_return",
  "sp_proc_stmt_iterate", "sp_proc_stmt_leave", "drop_procedure_stmt",
  "drop_function_stmt", "opt_if_exists", "opt_if_not_exists",
  "geometry_collection", "scalar_data_type", "pl_obj_access_ref",
  "int_type_i", "float_type_i", "datetime_type_i", "number_type",
  "date_year_type_i", "nchar_type_i", "nvarchar_type_i",
  "opt_int_length_i", "opt_bit_length_i", "opt_float_precision",
  "opt_number_precision", "opt_year_i", "opt_datetime_fsp_i",
  "number_literal", "literal", "text_type_i", "blob_type_i",
  "opt_string_length_i_v2", "string_length_i", "string_list",
  "text_string", "opt_string_length_i", "opt_binary", "collation_name",
  "charset_name", "opt_charset", "charset_key", "collation",
  "opt_collation", "signal_stmt", "resignal_stmt", "opt_signal_value",
  "signal_value", "opt_set_signal_information",
  "signal_information_item_list", "signal_information_item",
  "signal_allowed_expr", "variable", "scond_info_item_name", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,    40,    41,   459,    59,    94,    44,
      46,    61,    58,    37
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   214,   215,   216,   216,   217,   217,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   219,   219,   219,   220,
     220,   220,   220,   220,   220,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   222,
     222,   222,   222,   223,   223,   223,   223,   223,   223,   224,
     224,   224,   225,   225,   226,   227,   227,   228,   229,   229,
     230,   230,   230,   231,   231,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   233,   234,   235,   235,   236,   237,   237,
     238,   238,   239,   239,   240,   240,   241,   241,   242,   242,
     242,   243,   244,   245,   245,   246,   247,   247,   247,   247,
     248,   248,   249,   250,   250,   251,   251,   251,   251,   251,
     251,   252,   253,   254,   254,   254,   255,   255,   256,   256,
     256,   257,   258,   259,   259,   260,   260,   261,   261,   261,
     262,   262,   263,   263,   264,   264,   265,   265,   266,   266,
     267,   268,   268,   269,   269,   270,   271,   271,   271,   271,
     272,   273,   273,   273,   273,   274,   274,   275,   275,   275,
     276,   276,   276,   276,   276,   276,   276,   276,   277,   278,
     279,   280,   281,   281,   282,   282,   283,   283,   284,   285,
     285,   285,   285,   285,   285,   286,   286,   286,   286,   286,
     286,   286,   287,   288,   288,   289,   289,   290,   290,   291,
     292,   292,   293,   294,   294,   294,   294,   295,   296,   297,
     297,   298,   298,   299,   299,   300,   300,   301,   301,   301,
     301,   302,   302,   303,   303,   304,   304,   304,   304,   304,
     305,   305,   306,   307,   308,   309,   309,   309,   310,   311,
     311,   312,   312,   313,   314,   314,   315,   315,   316,   317,
     317,   318,   319,   319,   319,   320,   321,   322,   323,   324,
     325,   326,   326,   327,   327,   328,   328,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   330,   331,   331,   331,   331,   331,   332,
     332,   332,   333,   333,   333,   334,   334,   334,   334,   335,
     335,   336,   336,   337,   337,   337,   337,   338,   338,   339,
     339,   340,   340,   340,   340,   341,   341,   341,   342,   342,
     343,   343,   344,   344,   345,   345,   345,   345,   346,   346,
     346,   346,   346,   346,   347,   347,   347,   347,   347,   348,
     348,   349,   350,   350,   351,   351,   352,   352,   353,   353,
     354,   354,   355,   355,   355,   356,   356,   357,   357,   358,
     359,   359,   360,   361,   362,   362,   363,   363,   364,   364,
     365,   365,   366,   367,   367,   367,   367,   368,   368,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     369
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     1,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       4,     2,     2,     2,     1,     1,     1,     1,     2,     2,
       2,     2,     2,     3,     2,     9,     8,    11,    10,     0,
       2,     3,     3,     1,     2,     0,     2,     0,     3,     1,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     6,     2,     2,     1,     2,     1,
       0,     1,     0,     2,     0,     1,     3,     2,     1,     1,
       1,     7,     5,     0,     1,     3,     7,     6,     6,     5,
       3,     4,     7,     2,     3,     1,     1,     1,     1,     2,
       2,     3,     4,     8,    10,    10,     1,     1,     1,     1,
       1,     1,     4,    10,     9,    12,    11,     0,     4,     4,
       1,     1,     1,     0,     0,     2,     0,     1,     3,     1,
       4,     0,     1,     3,     1,     2,     0,     1,     1,     1,
       1,     1,     3,     4,     5,     1,     2,     1,     1,     2,
       2,     2,     2,     2,     3,     3,     3,     3,     1,     1,
       4,     4,     0,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     3,     6,     5,     1,     2,     4,
       2,     2,     1,     2,     3,     3,     4,     4,     1,     0,
       1,     2,     3,     2,     3,     0,     3,     4,     5,     6,
       5,     1,     1,     1,     3,     1,     1,     1,     2,     1,
       1,     1,     3,     2,     2,     3,     4,     5,     2,     0,
       1,     1,     3,     1,     0,     2,     0,     2,     0,     1,
       3,     0,     4,     6,     6,     4,     2,     2,     2,     4,
       4,     0,     2,     0,     3,     1,     1,     2,     3,     3,
       4,     3,     4,     2,     3,     3,     4,     3,     4,     2,
       3,     3,     4,     3,     4,     2,     1,     5,     4,     6,
       5,     4,     2,     2,     1,     2,     1,     1,     2,     5,
       7,     7,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     2,     1,     2,     2,     3,     3,     0,     3,
       0,     5,     3,     3,     0,     5,     3,     0,     3,     0,
       3,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     2,     1,
       0,     3,     1,     3,     1,     1,     1,     0,     1,     0,
       1,     1,     1,     1,     1,     2,     0,     1,     2,     2,
       1,     0,     3,     3,     0,     1,     1,     1,     0,     2,
       1,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       6,    30,     0,     0,   217,    32,     0,    31,     0,    36,
     484,    47,     0,   353,    33,    44,    34,    45,    46,   341,
       0,     0,     0,     0,     0,     4,     5,    35,    16,    18,
      17,    13,    21,    14,    22,    15,    23,    25,    24,     7,
       8,    11,    12,     9,    10,    19,    20,    26,     0,    27,
       0,    28,    42,    73,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,   157,    95,    96,    97,    98,    99,
     129,   100,   101,   102,   158,   103,   161,   104,   105,   106,
     107,   159,   156,   108,   131,   109,   110,   111,   112,   114,
     115,   130,   116,   117,   118,   119,   121,   160,   122,   124,
     125,   126,   113,   127,   128,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   123,
     120,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   162,    59,    72,    74,     0,     0,    38,    37,     0,
       0,   351,   351,   351,     0,    39,    41,    43,   329,   486,
     487,   488,   485,   488,     0,     0,     0,     0,     0,    50,
      52,    51,    49,   339,    80,   170,    69,    48,     0,    29,
     341,   341,     0,     0,     0,   353,     0,   341,   341,    78,
      84,   353,   112,   114,   268,   298,    54,   266,   267,   269,
     275,   276,   277,   292,   278,     0,   272,   274,   273,   279,
     280,   281,   270,   271,     1,     2,     6,   262,   262,    67,
      53,     0,   173,     0,   163,   185,   353,   353,   201,     0,
       0,     0,     0,    80,   190,   330,     0,     0,   483,   482,
       0,     0,     0,   109,     0,   324,   323,   341,     0,     0,
     167,   169,   171,   174,     0,     0,     0,     0,   347,   348,
       0,     0,     0,     0,   346,     0,   293,     0,     0,     0,
       0,     0,     3,     0,     0,     0,     0,     0,     0,     0,
     264,   260,   263,   261,    60,     0,    63,    65,    71,    40,
     221,   220,   224,   223,     0,     0,   352,   349,   212,   350,
     191,   322,   504,   499,   507,   501,   503,   502,   508,   509,
     510,   505,   500,   506,   489,   490,     0,   354,   206,   207,
     202,     0,     0,     0,   341,   325,   340,     0,     0,   183,
     101,   115,   196,   197,   198,     0,     0,     0,   195,   165,
     166,   168,     0,     0,   175,     0,   179,   180,   178,    68,
     341,     0,   287,     0,     0,   301,    98,     0,     0,   341,
       0,   295,   294,   303,     0,     0,     0,   305,   299,   299,
       0,     0,     0,   250,   253,   251,   252,   265,    61,    67,
      67,    64,     0,     0,   219,   222,   218,     0,     0,     0,
       0,   209,   208,   210,     0,   326,     0,   328,   312,   311,
     331,     0,     0,     0,   184,   189,     0,     0,   199,   259,
     200,   258,   183,     0,     0,   193,   183,   183,     0,   177,
       0,     0,   341,     0,   288,     0,   282,   284,   342,   302,
     236,     0,     0,   296,   304,   231,   300,   297,   345,   255,
     254,   256,   257,    62,    66,    70,   225,   236,   231,   491,
     496,   442,   443,   446,   445,   497,   498,   447,     0,   241,
     495,   444,   493,   492,   494,     0,   327,     0,     0,     0,
     384,   453,   404,   405,   406,   407,   408,   409,   410,   415,
     416,   417,   467,     0,   467,     0,     0,   455,   448,   450,
     451,   454,   456,   457,   392,   131,   412,   413,   414,   419,
     439,   449,   421,   423,   386,   387,   142,   430,   418,   393,
     394,   395,   396,   397,   398,   399,   355,   356,   401,     0,
     403,   334,   400,   333,     0,   428,   434,   441,   437,   376,
     467,   467,   460,   460,   236,   236,     0,   188,   194,   183,
     187,   164,   176,     0,   291,   290,   286,     0,   283,   237,
     239,   238,     0,   227,   229,     0,     0,    98,     0,     0,
     232,   234,     0,     0,     0,     0,     0,     0,     0,     0,
     452,   458,   411,     0,     0,   466,   469,   469,   382,   383,
       0,   422,   425,     0,   420,   424,     0,     0,   385,   332,
     338,   307,     0,     0,   357,     0,   363,     0,   375,     0,
     369,   469,   469,   469,   459,   388,     0,     0,     0,   186,
     289,   285,     0,   236,     0,   344,   343,   235,   240,     0,
       0,     0,     0,     0,   242,     0,   308,   321,   320,     0,
       0,     0,   310,     0,   319,   317,   316,     0,   313,   315,
     469,     0,   468,   476,   476,   464,   465,     0,   462,   426,
       0,     0,     0,   335,   402,     0,   361,   358,   359,     0,
       0,   367,   364,   365,     0,     0,   373,   370,   371,   481,
     481,   476,   182,     0,     0,   248,     0,    86,    91,   106,
     110,     0,   245,   247,    56,   228,   336,     0,   233,     0,
     214,     0,   243,     0,     0,     0,   318,     0,   309,   476,
     461,     0,   477,   481,     0,   481,   469,     0,   438,   469,
     429,   427,   362,   360,   432,     0,   433,   368,   366,   440,
     436,     0,   374,   372,     0,   480,   378,   381,   481,     0,
       0,   249,   246,    55,   338,   230,     0,   213,     0,   244,
       0,     0,   314,   481,   478,   377,   473,   474,   472,   475,
     380,   476,   463,   476,     0,     0,   471,   470,   479,   389,
     181,   192,   337,     0,    58,     0,   216,   129,   130,   203,
     211,   379,   481,   481,   431,   435,    57,   215,     0,     0,
     391,   390,   204,   205
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    23,    24,    25,   194,    52,    27,    28,    29,    30,
     220,   285,   286,   381,   287,   175,   520,   195,   144,    31,
      32,   250,   251,   252,   253,   149,   343,   344,   345,   332,
     333,   405,    33,    34,    35,   334,   335,   336,    36,    37,
     320,   321,   394,   769,    38,    39,    40,   150,   293,   386,
     384,   552,   553,   554,   559,   560,   561,   555,   617,   460,
     681,   682,   683,   410,   408,    41,    42,   281,   282,   260,
     197,   198,   199,   200,   256,   201,   351,   352,   425,   202,
     203,   204,   205,   437,   267,   268,   269,   338,   401,   637,
     638,   639,   627,   206,   207,   208,   325,   236,   402,   618,
     591,   735,   653,   172,   173,   209,   210,   211,   212,   213,
      43,    44,   230,   165,   522,   523,   524,   525,   526,   527,
     528,   529,   530,   531,   594,   588,   596,   600,   584,   598,
     628,   462,   532,   533,   603,   575,   647,   648,   576,   643,
     758,   749,   703,   704,   725,   726,    45,    46,   161,   162,
     238,   314,   315,   463,   464,   316
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -609
static const yytype_int16 yypact[] =
{
     244,  -609,    40,  6318,    48,  -609,    67,  -609,    16,  -609,
    5956,  -609,  5956,    37,  -609,  -609,  -609,  -609,  -609,   -20,
    6409,     9,  1521,    50,     5,  -609,  -609,  -609,  -609,  -609,
    -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,
    -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  6318,  -609,
    6318,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,
    -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,
    -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,
    -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,
    -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,
    -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,
    -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,
    -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,
    -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,
    -609,  -609,  -145,  -141,  -609,    64,   -99,  -609,  -609,   -22,
      28,   111,   111,   111,  6500,  -609,  -609,  -609,    15,  -609,
    -609,    63,  -609,    63,   156,  6318,  6136,  6318,  6318,  -609,
    -609,  -609,    46,  -609,  6591,   112,    56,  -609,    18,  -609,
    -609,  -609,  6318,  6318,  2511,    37,  2511,  -609,  -609,  1719,
    6318,   -12,  6318,  6409,  -609,  -609,  -609,  -609,  -609,  -609,
    -609,  -609,  -609,  -609,  -609,    83,  -609,  -609,  -609,  -609,
    -609,  -609,  -609,  -609,  -609,  -609,   244,   211,   211,    55,
    -609,  6318,    16,   273,  -609,  -609,    37,    37,  -609,   265,
    6318,  6318,  6318,  6318,  -609,  -609,   306,   300,  -609,  -609,
     287,    13,  6318,   295,   302,  -609,  -609,  -609,  1125,    11,
    -609,  -609,   112,    21,  6318,   278,   255,   322,  -609,  -609,
     189,  2709,  6318,  1917,  -609,   288,   190,  2907,  2115,   375,
    6318,   200,  -609,   338,   340,   243,   401,   345,   349,   353,
    -609,  -609,   211,  -609,  -609,   -96,  -609,   416,   215,  -609,
    -609,  -609,   224,   415,  6318,  6318,  -609,  -609,  -609,  -609,
    -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,
    -609,  -609,  -609,  -609,   222,  -609,   223,  -609,  -609,  -609,
    -609,   124,   302,  6318,  -609,  -609,  -609,  5679,  6318,  4391,
    6318,   291,  5305,  2511,  -609,  1323,   228,  3105,  -609,  -609,
    -609,  -609,  6318,   301,    21,   230,  -609,  -609,  -609,  -609,
    -609,    23,  -609,   397,  2511,  -609,   387,   233,   237,  -609,
    2511,   190,   190,  -609,  3303,   236,   242,  3501,  6318,  6318,
     319,   321,    89,  -609,  -609,  -609,  -609,  -609,  -609,  -609,
    -609,  -609,  6318,   248,  -609,  -609,  -609,   250,   252,   300,
    4585,  -609,  -609,  -609,   402,  -609,   302,    46,  -609,  -609,
     184,   318,  4765,   256,  -609,  -609,   257,   260,  -609,  -609,
    -609,  -609,  4391,   258,  3699,  -609,  4391,  6318,   261,  -609,
     398,  2511,  -609,   437,  -609,   336,  -609,  2313,  -609,  -609,
      -6,   337,  3897,   190,   441,  6318,  -609,  -609,  -609,  -609,
    -609,  -609,  -609,  -609,  -609,  -609,  -609,    -6,  6318,  -609,
    -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  6318,   263,
    -609,  -609,  -609,  -609,  -609,  6318,  -609,   435,   436,   438,
    -609,   155,  -609,  -609,  -609,  -609,  -609,  -609,   391,  -609,
    -609,  -609,   -73,   274,   274,   274,   276,  -609,  -609,  -609,
    -609,  -609,  -609,  -609,  -122,   182,    95,   118,   132,   145,
     109,   146,   -60,   150,   157,   158,   277,   137,   159,   163,
     164,   165,   171,   172,   173,   178,   179,   185,   191,  6318,
    -609,   450,  -609,  -609,   269,   279,   280,   281,   282,  -609,
     274,   274,   274,   274,    -6,    -6,   370,  -609,  -609,  4391,
    -609,  -609,  -609,  2511,  4293,  -609,  -609,   466,  -609,  -609,
    -609,  -609,   284,   283,  -609,  6318,   429,   414,  4945,   289,
     286,  -609,   292,   293,   290,  6318,   454,    97,    10,  5499,
    -609,  -609,  -609,   274,   167,  -609,   405,   405,  -609,  -609,
     325,   395,  -609,   491,  -609,  -609,   325,   492,  -609,  -609,
    -609,  -609,   341,   494,   -29,   275,   -17,   495,  -609,   496,
      -4,   405,   405,   405,  -609,  -609,   303,   304,   298,  -609,
    4293,  -609,   927,   131,  4945,  -609,  -609,  -609,  -609,   350,
    6318,   927,   351,  6318,   305,   479,  -609,  -609,  -609,    16,
      39,    62,  -609,   376,  -609,  -609,  -609,   729,  -609,  -609,
     405,   308,  -609,    14,    14,  -609,  -609,    32,  -609,  -609,
     312,    78,   313,  -609,  -609,   314,   426,  -609,   427,    79,
     317,   430,  -609,   431,   323,    88,   432,  -609,   433,   434,
     434,    14,  -609,   467,  6318,  -609,   499,   401,   345,   349,
     353,   927,  -609,  -609,  -609,  -609,   503,  4945,  -609,   927,
    -609,  4945,  -609,  6318,   372,   472,  -609,  5499,  -609,    14,
    -609,   439,  -609,   434,  5776,   434,   405,   325,  -609,   405,
    -609,  -609,  -609,  -609,  -609,   527,  -609,  -609,  -609,  -609,
    -609,   528,  -609,  -609,  6227,  -609,  -609,  -609,   434,  4945,
     335,  -609,  -609,  -609,  -609,  -609,  5125,  -609,  5125,  -609,
    4095,    16,  -609,   434,  -609,  -609,  -609,  -609,  -609,  -609,
    -609,    14,  -609,    14,   339,   342,  -609,  -609,  -609,  -609,
    -609,  -609,  -609,  5125,  -609,  5125,  -609,  6318,  6318,  -609,
    -609,  -609,   434,   434,  -609,  -609,  -609,  -609,  2511,  2511,
    -609,  -609,  -609,  -609
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -609,  -609,  -609,   326,     3,    -2,     4,   -27,  -609,  -609,
    -609,  -609,   160,  -609,   166,   -38,   540,    -3,  -609,  -609,
     396,  -609,   296,  -609,  -609,  -609,  -609,  -609,   205,  -212,
    -200,  -356,  -609,   404,  -609,  -609,  -609,   216,  -609,   400,
    -609,  -609,  -609,  -449,  -609,  -609,  -609,  -609,  -609,  -609,
    -609,  -319,  -609,   -59,   108,  -609,   -63,  -609,   -56,  -609,
    -597,  -608,  -121,  -378,  -463,  -609,  -609,   343,  -609,   -21,
    -609,  -609,  -321,  -609,   138,  -609,  -609,   208,   136,  -609,
     294,  -609,  -167,   195,  -163,  -609,  -609,  -207,  -609,  -609,
    -130,     1,   334,   550,   551,   552,  -254,  -609,  -609,  -397,
    -609,  -609,  -162,   249,  -154,   307,  -609,  -609,  -609,  -609,
    -609,  -609,   209,    53,  -609,  -609,  -609,  -609,  -609,  -609,
    -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,  -609,
    -371,  -609,  -609,  -609,    41,  -403,   -11,  -131,  -382,  -456,
    -609,  -609,  -577,  -609,  -609,  -407,  -609,  -609,  -609,   565,
     417,  -609,   192,  -609,  -609,  -609
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -307
static const yytype_int16 yytable[] =
{
     143,   196,   148,    26,   156,   521,   157,   159,   215,   159,
     217,   409,   218,     1,     1,   258,   259,   176,   166,   461,
      47,   261,     1,   263,   689,   179,   255,   257,   629,   164,
     585,   573,   318,   264,   265,   630,   549,   339,   550,     5,
       5,   346,   631,    47,    47,   176,   348,   176,     5,   327,
     214,   551,    47,   347,     7,     7,   537,   421,   422,   219,
     540,   541,   365,     7,   656,   657,    47,   705,   395,   221,
       8,    47,     9,   732,   177,    11,   661,   662,   164,   328,
     577,   732,   579,    14,    14,   337,   226,    49,  -105,   666,
     667,  -105,    14,   326,   728,   695,   280,   280,    48,   350,
     167,    13,   578,   701,   145,   364,    15,   451,   452,   378,
      49,    49,   223,   379,    16,    16,   234,    17,    18,    49,
     702,   644,   743,    16,   319,   151,   222,   241,   562,   604,
     604,   574,   346,    49,    20,   168,   248,   348,    49,   763,
     152,   765,   466,   340,   347,   669,   670,   671,   601,   602,
    -138,   176,   229,  -138,   391,   732,   658,   732,   423,   237,
     342,   377,   176,   244,   245,   246,   158,   227,   663,   392,
     640,   176,   414,   549,   772,   550,   773,   451,   452,    50,
     146,   668,   179,   609,   699,    51,   235,   245,   551,   246,
     176,   427,   297,   298,   299,   300,   420,   432,   393,  -226,
    -101,   436,   436,   641,  -172,   431,   153,   467,    51,    51,
     240,   468,   216,   178,    21,   606,   607,    51,   288,    26,
     289,   441,   178,   154,   358,   249,   147,   176,   176,   176,
     176,    51,   366,   442,   684,   147,    51,   706,   262,   322,
     357,   707,   357,   690,   270,   570,   357,   571,     1,   155,
     751,   349,   184,   753,   155,   247,   387,   388,   544,   176,
     284,   186,     2,   727,   273,     3,   254,   176,   257,     4,
     274,   581,   582,   764,     5,   766,     6,   188,   275,   294,
     295,   290,   291,   709,   714,   659,   660,   707,   715,     7,
     736,   176,   176,   720,   738,   271,   745,   721,   750,   292,
     776,   296,   777,   733,     8,  -132,     9,    10,  -132,    11,
      12,   737,   411,   583,   367,   301,   357,    13,    14,  -136,
     396,   759,  -136,   317,   400,   403,   404,   406,  -133,   782,
     783,  -133,   760,   276,   645,   323,   771,   646,   277,   406,
      15,   587,  -134,   357,   160,  -134,   160,  -143,   324,    16,
    -143,    17,    18,    19,   350,  -135,  -137,   278,  -135,  -137,
    -139,   231,   232,  -139,   279,   780,   781,  -140,  -141,  -144,
    -140,  -141,  -144,  -147,  -148,  -149,  -147,  -148,  -149,   445,
     610,  -150,  -151,  -152,  -150,  -151,  -152,   459,  -153,  -154,
     353,  -153,  -154,   357,   354,  -155,   355,   360,  -155,   143,
      20,  -162,   -98,   327,  -162,   370,   357,   371,   372,   404,
     373,   357,   374,   404,   404,   409,   375,   409,   302,   303,
     376,   304,   380,   305,   306,   382,   307,   566,   383,   308,
     385,   389,   558,   407,   390,   415,   417,   419,   426,   428,
     429,   430,   409,   434,   409,   558,   435,   309,    21,   439,
     310,   440,    22,   446,   447,   564,   448,   465,   469,   546,
     534,   535,   176,   311,   536,   538,   312,   313,   542,  -306,
     543,   547,   556,   565,   567,   568,   572,   569,   574,   590,
     580,   586,   592,   593,   595,   597,   599,   608,   611,   612,
     615,   616,   613,   625,   619,   620,   642,   621,   622,   649,
     623,   650,   652,   654,   655,   664,   665,   674,   672,   673,
     687,   691,   694,   700,   696,   693,   589,   708,   710,   711,
     712,   713,   716,   357,   717,   718,   722,   723,   719,   724,
     731,   729,   734,   740,   741,   744,   404,   754,   755,   443,
     761,   632,   272,   142,   774,   224,   444,   775,   341,   418,
     228,   413,   614,   225,   685,   143,   563,   688,   686,   424,
     545,   283,   624,   548,   438,   368,   636,   742,   626,   169,
     170,   171,   762,   397,   605,   651,   752,   163,   369,     0,
     239,   449,     0,     0,     0,     0,     0,     0,     0,   357,
       0,   411,     0,     0,     0,     0,     0,     0,     0,     0,
     411,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   143,     0,     0,     0,     0,   698,   558,     0,     0,
     692,     0,     0,     0,     0,     0,     0,     0,   148,   156,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     411,     0,     0,     0,     0,     0,     0,     0,   411,     0,
       0,   730,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   143,     0,     0,     0,   143,     0,
     739,     0,     0,     0,   636,     0,     0,     0,     0,     0,
       0,   748,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   770,
       0,   757,     0,     0,     0,     0,   143,     0,     0,   778,
     779,     0,     0,     1,     0,     0,     0,    53,     0,   289,
       0,     0,     0,     0,     0,     0,     0,     2,     0,     0,
       3,   180,     0,     0,     4,     0,     0,   770,   770,     5,
       0,     6,     0,     0,   176,   176,     0,   166,     0,     0,
     181,     0,     0,     0,     7,     0,     0,   182,   183,     0,
       0,   184,     0,     0,     0,     0,     0,     0,     0,     8,
     186,     9,    10,   187,    11,    12,     0,     0,     0,     0,
       0,     0,    13,    14,     0,     0,   188,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,     0,     0,
       0,     0,     0,     0,    16,     0,    17,    18,    19,     0,
      54,    55,    56,   189,    58,    59,    60,    61,    62,   190,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,   192,   193,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     0,     0,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     1,     0,    21,     0,    53,     0,    22,   697,     0,
       0,     0,     0,     0,     0,     2,     0,     0,     3,   180,
       0,     0,     4,     0,     0,     0,     0,     5,   675,     6,
       0,     0,     0,     0,     0,   166,     0,     0,   181,     0,
       0,     0,     7,     0,     0,   182,   183,     0,     0,   184,
     273,   676,     0,     0,     0,     0,   274,     8,   186,     9,
      10,   187,    11,    12,   275,     0,     0,     0,     0,     0,
      13,    14,     0,     0,   188,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,     0,     0,     0,     0,     0,     0,
       0,     0,    16,     0,    17,    18,    19,     0,    54,    55,
      56,   189,    58,    59,    60,    61,    62,   190,    64,   677,
      66,    67,    68,    69,   678,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,   679,    90,    91,    92,    93,    94,    95,
     680,    97,   192,   193,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,     0,     0,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     1,
       0,    21,     0,    53,     0,    22,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     3,   180,     0,     0,
       4,     0,     0,   327,     0,     5,     0,     6,     0,     0,
       0,     0,     0,   166,     0,     0,   181,     0,     0,     0,
       7,     0,     0,   182,   183,     0,     0,   184,     0,     0,
       0,     0,     0,   328,     0,     8,   186,     9,    10,   187,
      11,    12,     0,     0,     0,     0,     0,     0,    13,    14,
       0,     0,   188,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,     0,     0,     0,     0,
      16,     0,    17,    18,    19,     0,    54,    55,    56,   189,
      58,    59,    60,    61,    62,   190,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
     329,    79,    80,    81,   330,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
     192,   193,   331,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,     0,     0,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,     1,     0,    21,
       0,    53,     0,    22,     0,     0,     0,     0,     0,     0,
       0,     2,     0,     0,     3,   180,     0,     0,     4,     0,
       0,   327,     0,     5,     0,     6,     0,     0,     0,     0,
       0,   166,     0,     0,   181,     0,     0,     0,     7,     0,
       0,   182,   183,     0,     0,   184,     0,     0,     0,     0,
       0,   328,     0,     8,   186,     9,    10,   187,    11,    12,
       0,     0,     0,     0,     0,     0,    13,    14,     0,     0,
     188,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,     0,     0,     0,     0,     0,     0,     0,    16,     0,
      17,    18,    19,     0,    54,    55,    56,   189,    58,    59,
      60,    61,    62,   190,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,   412,    79,
      80,    81,   330,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,   192,   193,
     331,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     1,     0,    21,     0,    53,
       0,    22,     0,     0,     0,     0,     0,     0,     0,     2,
       0,     0,     3,   180,     0,     0,     4,     0,     0,     0,
       0,     5,     0,     6,     0,     0,     0,     0,     0,   166,
       0,     0,   181,     0,     0,     0,     7,     0,     0,   182,
     183,     0,     0,   184,     0,     0,     0,     0,     0,   185,
       0,     8,   186,     9,    10,   187,    11,    12,     0,     0,
       0,     0,     0,     0,    13,    14,     0,     0,   188,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,     0,     0,
       0,     0,     0,     0,     0,     0,    16,     0,    17,    18,
      19,     0,    54,    55,    56,   189,    58,    59,    60,    61,
      62,   190,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
     191,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,   192,   193,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,     0,
       0,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     1,     0,    21,     0,    53,     0,    22,
       0,     0,     0,     0,     0,     0,     0,     2,     0,     0,
       3,   180,     0,     0,     4,     0,     0,  -305,     0,     5,
       0,     6,     0,     0,     0,     0,     0,   166,     0,     0,
     181,     0,     0,     0,     7,     0,     0,   182,   183,     0,
       0,   184,     0,     0,     0,     0,     0,     0,     0,     8,
     186,     9,    10,   187,    11,    12,     0,     0,     0,     0,
       0,     0,    13,    14,     0,     0,   188,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,     0,     0,
       0,     0,     0,     0,    16,     0,    17,    18,    19,     0,
      54,    55,    56,   189,    58,    59,    60,    61,    62,   190,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,   266,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,   192,   193,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     0,     0,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     1,     0,    21,     0,    53,     0,    22,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     0,     3,   180,
       0,     0,     4,     0,     0,     0,     0,     5,     0,     6,
       0,     0,     0,     0,     0,   166,     0,     0,   181,     0,
       0,     0,     7,     0,     0,   182,   183,     0,     0,   184,
       0,     0,     0,     0,     0,     0,     0,     8,   186,     9,
      10,   187,    11,    12,     0,     0,     0,     0,     0,     0,
      13,    14,     0,     0,   188,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,     0,     0,     0,     0,     0,     0,
       0,     0,    16,     0,    17,    18,    19,   359,    54,    55,
      56,   189,    58,    59,    60,    61,    62,   190,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,   192,   193,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,     0,     0,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     1,
       0,    21,     0,    53,     0,    22,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     3,   180,     0,     0,
       4,     0,     0,     0,     0,     5,     0,     6,     0,     0,
       0,     0,     0,   166,     0,     0,   181,     0,     0,     0,
       7,     0,     0,   182,   183,     0,     0,   184,     0,     0,
       0,     0,     0,     0,     0,     8,   186,     9,    10,   187,
      11,    12,     0,     0,     0,     0,     0,     0,    13,    14,
       0,     0,   188,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,     0,     0,     0,     0,
      16,     0,    17,    18,    19,     0,    54,    55,    56,   189,
      58,    59,    60,    61,    62,   190,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
     362,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
     192,   193,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,     0,     0,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,     1,     0,    21,
       0,    53,   363,    22,     0,     0,     0,     0,     0,     0,
       0,     2,     0,     0,     3,   180,     0,     0,     4,     0,
       0,     0,     0,     5,     0,     6,     0,   421,   422,     0,
       0,   166,     0,     0,   181,     0,     0,     0,     7,     0,
       0,   182,   183,     0,     0,   184,     0,     0,     0,     0,
       0,     0,     0,     8,   186,     9,    10,   187,    11,    12,
       0,     0,     0,     0,     0,     0,    13,    14,     0,     0,
     188,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,     0,     0,     0,     0,     0,     0,     0,    16,     0,
      17,    18,    19,     0,    54,    55,    56,   189,    58,    59,
      60,    61,    62,   190,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,     0,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,   192,   193,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     1,     0,    21,     0,    53,
       0,    22,     0,     0,     0,     0,     0,     0,     0,     2,
       0,     0,     3,   180,     0,     0,     4,     0,     0,     0,
       0,     5,     0,     6,     0,     0,     0,     0,     0,   166,
       0,     0,   181,     0,     0,     0,     7,     0,     0,   182,
     183,     0,     0,   184,     0,     0,     0,     0,     0,     0,
       0,     8,   186,     9,    10,   187,    11,    12,     0,     0,
       0,     0,     0,     0,    13,    14,     0,     0,   188,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,     0,     0,
       0,     0,     0,     0,     0,     0,    16,     0,    17,    18,
      19,     0,    54,    55,    56,   189,    58,    59,    60,    61,
      62,   190,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,   192,   193,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,     0,
       0,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     1,     0,    21,     0,    53,     0,    22,
       0,     0,     0,     0,     0,     0,     0,     2,     0,     0,
       3,   180,     0,     0,     4,     0,     0,     0,     0,     5,
       0,     6,     0,     0,     0,     0,     0,   166,     0,     0,
     181,     0,     0,     0,     7,     0,     0,   182,   183,     0,
       0,   184,     0,     0,     0,     0,     0,     0,     0,     8,
     186,     9,    10,   187,    11,    12,     0,     0,     0,     0,
       0,     0,    13,    14,     0,     0,   188,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,     0,     0,
       0,     0,     0,     0,    16,     0,    17,    18,    19,     0,
      54,    55,    56,   189,    58,    59,    60,    61,    62,   190,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,   356,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,   192,   193,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     0,     0,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     1,     0,    21,     0,    53,     0,    22,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     0,     3,   180,
       0,     0,     4,     0,     0,     0,     0,     5,     0,     6,
       0,     0,     0,     0,     0,   166,     0,     0,   181,     0,
       0,     0,     7,     0,     0,   182,   183,     0,     0,   184,
       0,     0,     0,     0,     0,     0,     0,     8,   186,     9,
      10,   187,    11,    12,     0,     0,     0,     0,     0,     0,
      13,    14,     0,     0,   188,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,     0,     0,     0,     0,     0,     0,
       0,     0,    16,     0,    17,    18,    19,     0,    54,    55,
      56,   189,    58,    59,    60,    61,    62,   190,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,   361,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,   192,   193,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,     0,     0,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     1,
       0,    21,     0,    53,     0,    22,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     3,   180,     0,     0,
       4,     0,     0,     0,     0,     5,     0,     6,     0,     0,
       0,     0,     0,   166,     0,     0,   181,     0,     0,     0,
       7,     0,     0,   182,   183,     0,     0,   184,     0,     0,
       0,     0,     0,     0,     0,     8,   186,     9,    10,   187,
      11,    12,     0,     0,     0,     0,     0,     0,    13,    14,
       0,     0,   188,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,     0,     0,     0,     0,
      16,     0,    17,    18,    19,     0,    54,    55,    56,   189,
      58,    59,    60,    61,    62,   190,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
     416,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
     192,   193,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,     0,     0,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,     1,     0,    21,
       0,    53,     0,    22,     0,     0,     0,     0,     0,     0,
       0,     2,     0,     0,     3,   180,     0,     0,     4,     0,
       0,     0,     0,     5,     0,     6,     0,     0,     0,     0,
       0,   166,     0,     0,   181,     0,     0,     0,     7,     0,
       0,   182,   183,     0,     0,   184,     0,     0,     0,     0,
       0,     0,     0,     8,   186,     9,    10,   187,    11,    12,
       0,     0,     0,     0,     0,     0,    13,    14,     0,     0,
     188,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,     0,     0,     0,     0,     0,     0,     0,    16,     0,
      17,    18,    19,     0,    54,    55,    56,   189,    58,    59,
      60,    61,    62,   190,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,   433,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,   192,   193,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     1,     0,    21,     0,    53,
       0,    22,     0,     0,     0,     0,     0,     0,     0,     2,
       0,     0,     3,   180,     0,     0,     4,     0,     0,     0,
       0,     5,     0,     6,     0,     0,     0,     0,     0,   166,
       0,     0,   181,     0,     0,     0,     7,     0,     0,   182,
     183,     0,     0,   184,     0,     0,     0,     0,     0,     0,
       0,     8,   186,     9,    10,   187,    11,    12,     0,     0,
       0,     0,     0,     0,    13,    14,     0,     0,   188,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,     0,     0,
       0,     0,     0,     0,     0,     0,    16,     0,    17,    18,
      19,     0,    54,    55,    56,   189,    58,    59,    60,    61,
      62,   190,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,   266,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,   192,   193,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,     0,
       0,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     1,     0,    21,     0,    53,     0,    22,
       0,     0,     0,     0,     0,     0,     0,     2,     0,     0,
       3,   180,     0,     0,     4,     0,     0,     0,     0,     5,
       0,     6,     0,     0,     0,     0,     0,   166,     0,     0,
     181,     0,     0,     0,     7,     0,     0,   182,   183,     0,
       0,   184,     0,     0,     0,     0,     0,     0,     0,     8,
     186,     9,    10,   187,    11,    12,     0,     0,     0,     0,
       0,     0,    13,    14,     0,     0,   188,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,     0,     0,
       0,     0,     0,     0,    16,     0,    17,    18,    19,     0,
      54,    55,    56,   189,    58,    59,    60,    61,    62,   190,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,   539,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,   192,   193,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     0,     0,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     1,     0,    21,     0,    53,     0,    22,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     0,     3,   180,
       0,     0,     4,     0,     0,     0,     0,     5,     0,     6,
       0,     0,     0,     0,     0,   166,     0,     0,   181,     0,
       0,     0,     7,     0,     0,   182,   183,     0,     0,   184,
       0,     0,     0,     0,     0,     0,     0,     8,   186,     9,
      10,   187,    11,    12,     0,     0,     0,     0,     0,     0,
      13,    14,     0,     0,   188,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,     0,     0,     0,     0,     0,     0,
       0,     0,    16,     0,    17,    18,    19,     0,    54,    55,
      56,   189,    58,    59,    60,    61,    62,   190,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,   557,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,   192,   193,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,     0,     0,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     1,
       0,    21,     0,    53,     0,    22,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     3,   180,     0,     0,
       4,     0,     0,     0,     0,     5,     0,     6,     0,     0,
       0,     0,     0,   166,     0,     0,   181,     0,     0,     0,
       7,     0,     0,   182,   183,     0,     0,   184,     0,     0,
       0,     0,     0,     0,     0,     8,   186,     9,    10,   187,
      11,    12,     0,     0,     0,     0,     0,     0,    13,    14,
       0,     0,   188,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,     0,     0,     0,     0,
      16,     0,    17,    18,    19,     0,    54,    55,    56,   189,
      58,    59,    60,    61,    62,   190,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,   767,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
     192,   193,   100,   768,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,     0,     0,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,     1,     0,    21,
       0,    53,     0,    22,     0,     0,     0,     0,     0,     0,
       0,     2,     0,     0,     3,   180,     0,     0,     4,     0,
       0,     0,     0,     5,     0,     6,     0,     0,     0,     0,
       0,   166,     0,     0,   181,     0,     0,     0,     7,     0,
       0,   182,   183,     0,     0,   184,     0,     0,     0,     0,
       0,     0,     0,     8,   186,     9,    10,   187,    11,    12,
       0,     0,     0,     0,     0,     0,    13,    14,     0,     0,
     188,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,     0,     0,     0,     0,     0,     0,     0,    16,    53,
      17,    18,    19,     0,    54,    55,    56,   189,    58,    59,
      60,    61,    62,   190,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,     0,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,   192,   193,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     0,     0,    21,     0,     0,
       0,    22,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,     0,
       0,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,    53,   450,   451,   452,   453,   454,   455,
     456,   457,     0,   -98,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    53,   470,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,     0,     0,     0,
       0,     0,     0,     0,     0,   458,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   471,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   472,   473,   474,   475,   476,   477,   478,
       0,   479,   480,   481,   482,   483,   484,   485,     0,     0,
       0,   486,   487,   488,   489,   490,   491,   492,   493,     0,
       0,     0,     0,     0,     0,     0,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
     494,    89,    90,    91,    92,    93,   495,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   506,   507,   508,
     128,   129,   130,    53,   470,     0,   131,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,     0,     0,     0,
       0,     0,     0,     0,   519,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   471,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   472,   473,   474,   475,   476,   477,   478,
       0,   479,   480,   481,   482,   483,   484,   485,     0,     0,
       0,   486,   487,   488,   489,   490,   491,   492,   493,     0,
       0,     0,     0,     0,     0,     0,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
     494,    89,    90,    91,    92,    93,   495,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   506,   507,   508,
     128,   129,   130,    53,     0,     0,   131,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   180,     0,     0,
       0,     0,     0,     0,     0,     0,   675,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   181,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   184,   273,   676,
       0,     0,     0,     0,   274,     0,   186,     0,     0,   187,
       0,     0,   275,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   188,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    54,    55,    56,   189,
      58,    59,    60,    61,    62,    63,    64,   677,    66,    67,
      68,    69,   678,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,   679,    90,    91,    92,    93,    94,    95,   680,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    53,     0,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   180,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   181,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   184,     0,     0,
       0,     0,     0,     0,     0,     0,   186,     0,     0,   187,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   188,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    54,    55,    56,   189,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,     0,     0,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,    53,     0,   451,
     452,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   633,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   634,   158,   635,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,    53,     0,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,   398,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   399,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,   746,     0,     0,     0,     0,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   747,     0,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,     0,     0,     0,     0,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    53,     0,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   158,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    53,     0,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   242,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,   756,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,   243,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,     0,     0,    53,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,     0,     0,    53,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,     0,     0,    53,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
      54,    55,    56,    57,    58,   174,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     0,     0,    53,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,    54,    55,    56,    57,    58,   233,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,     0,     0,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,     0,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,     0,
       0,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141
};

static const yytype_int16 yycheck[] =
{
       3,    22,     4,     0,     6,   402,     8,    10,     3,    12,
      48,   332,    50,     4,     4,   182,   183,    20,    38,   390,
       4,   184,     4,   186,   621,    21,   180,   181,    18,    41,
      90,   104,    19,   187,   188,    25,    42,    26,    44,    30,
      30,   253,    32,     4,     4,    48,   253,    50,    30,    28,
       0,    57,     4,   253,    45,    45,   412,    34,    35,   204,
     416,   417,   269,    45,    93,    94,     4,   644,   322,   210,
      60,     4,    62,   681,    65,    65,    93,    94,    41,    58,
     483,   689,   485,    74,    74,   248,    58,    71,   210,    93,
      94,   213,    74,   247,   671,    56,   217,   218,    58,    76,
     120,    73,   484,    89,    56,   268,    96,    10,    11,   205,
      71,    71,   211,   209,   105,   105,   154,   107,   108,    71,
     106,   577,   699,   105,   111,    58,    62,   165,   447,   532,
     533,   204,   344,    71,   156,   155,   174,   344,    71,   736,
      73,   738,   396,   132,   344,   601,   602,   603,   530,   531,
     210,   154,    41,   213,    30,   763,   185,   765,   135,    96,
     139,   282,   165,   166,   167,   168,    69,   139,   185,    45,
     573,   174,   335,    42,   751,    44,   753,    10,    11,   139,
     132,   185,   178,   539,   640,   169,   171,   190,    57,   192,
     193,   354,   230,   231,   232,   233,   350,   360,    74,   205,
     212,   368,   369,   574,   156,   359,   139,    23,   169,   169,
      54,    27,   207,   204,   204,   534,   535,   169,   221,   216,
     222,   132,   204,   156,   262,   113,   187,   230,   231,   232,
     233,   169,   270,   144,   612,   187,   169,   205,   185,   242,
     261,   209,   263,   621,   191,    90,   267,    92,     4,   187,
     706,   254,    52,   709,   187,   209,   294,   295,   421,   262,
     205,    61,    18,   670,    53,    21,   210,   270,   422,    25,
      59,    89,    90,   736,    30,   738,    32,    77,    67,   226,
     227,     8,     9,   205,   205,    10,    11,   209,   209,    45,
     687,   294,   295,   205,   691,   212,   703,   209,   705,    26,
     763,    36,   765,   681,    60,   210,    62,    63,   213,    65,
      66,   689,   333,   204,   114,     9,   337,    73,    74,   210,
     323,   728,   213,    36,   327,   328,   329,   330,   210,   778,
     779,   213,   729,   122,     9,    40,   743,    12,   127,   342,
      96,   204,   210,   364,    10,   213,    12,   210,    46,   105,
     213,   107,   108,   109,    76,   210,   210,   146,   213,   213,
     210,   152,   153,   213,   153,   772,   773,   210,   210,   210,
     213,   213,   213,   210,   210,   210,   213,   213,   213,   382,
     543,   210,   210,   210,   213,   213,   213,   390,   210,   210,
     135,   213,   213,   414,    72,   210,   207,   109,   213,   402,
     156,   210,   212,    28,   213,    67,   427,    67,   165,   412,
       9,   432,    67,   416,   417,   736,    67,   738,   118,   119,
      67,   121,     6,   123,   124,   210,   126,   465,   204,   129,
      15,   209,   435,   142,   211,   207,   135,   207,    41,    52,
     207,   204,   763,   207,   765,   448,   204,   147,   204,   130,
     150,   130,   208,   205,   204,   458,   204,    55,   140,    22,
     204,   204,   465,   163,   204,   207,   166,   167,   207,    28,
      72,   135,   135,   210,    39,    39,    85,    39,   204,    29,
     204,   204,   213,   204,   204,   204,   204,   117,    22,   205,
      61,    77,   209,    39,   205,   209,    91,   205,   205,   104,
     210,    10,    10,   162,    10,    10,    10,   209,   205,   205,
     160,   160,    33,   205,   138,   210,   519,   205,   205,   205,
      94,    94,   205,   544,    94,    94,    94,    94,   205,    95,
      31,    64,    29,   161,    62,    96,   539,    10,    10,   379,
     205,   568,   216,     3,   205,   149,   380,   205,   252,   344,
     150,   335,   555,   149,   613,   558,   448,   620,   614,   351,
     422,   218,   565,   427,   369,   271,   569,   697,   567,    19,
      19,    19,   734,   324,   533,   586,   707,    12,   271,    -1,
     163,   389,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   610,
      -1,   612,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     621,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   614,    -1,    -1,    -1,    -1,   637,   620,    -1,    -1,
     623,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   630,   631,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     681,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   689,    -1,
      -1,   674,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   687,    -1,    -1,    -1,   691,    -1,
     693,    -1,    -1,    -1,   697,    -1,    -1,    -1,    -1,    -1,
      -1,   704,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   740,
      -1,   724,    -1,    -1,    -1,    -1,   729,    -1,    -1,   767,
     768,    -1,    -1,     4,    -1,    -1,    -1,     8,    -1,   741,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,
      21,    22,    -1,    -1,    25,    -1,    -1,   778,   779,    30,
      -1,    32,    -1,    -1,   767,   768,    -1,    38,    -1,    -1,
      41,    -1,    -1,    -1,    45,    -1,    -1,    48,    49,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    62,    63,    64,    65,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    74,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,   107,   108,   109,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,     4,    -1,   204,    -1,     8,    -1,   208,   209,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    21,    22,
      -1,    -1,    25,    -1,    -1,    -1,    -1,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    -1,
      -1,    -1,    45,    -1,    -1,    48,    49,    -1,    -1,    52,
      53,    54,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    -1,    -1,    -1,    -1,
      73,    74,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,   107,   108,   109,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,     4,
      -1,   204,    -1,     8,    -1,   208,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    -1,    21,    22,    -1,    -1,
      25,    -1,    -1,    28,    -1,    30,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    41,    -1,    -1,    -1,
      45,    -1,    -1,    48,    49,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    60,    61,    62,    63,    64,
      65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     105,    -1,   107,   108,   109,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,     4,    -1,   204,
      -1,     8,    -1,   208,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    -1,    -1,    21,    22,    -1,    -1,    25,    -1,
      -1,    28,    -1,    30,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    41,    -1,    -1,    -1,    45,    -1,
      -1,    48,    49,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    60,    61,    62,    63,    64,    65,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,
     107,   108,   109,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,     4,    -1,   204,    -1,     8,
      -1,   208,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      -1,    -1,    21,    22,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    30,    -1,    32,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    41,    -1,    -1,    -1,    45,    -1,    -1,    48,
      49,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    74,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,   107,   108,
     109,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,     4,    -1,   204,    -1,     8,    -1,   208,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,
      21,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,    30,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      41,    -1,    -1,    -1,    45,    -1,    -1,    48,    49,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    62,    63,    64,    65,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    74,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,   107,   108,   109,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,     4,    -1,   204,    -1,     8,    -1,   208,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    21,    22,
      -1,    -1,    25,    -1,    -1,    -1,    -1,    30,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    -1,
      -1,    -1,    45,    -1,    -1,    48,    49,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,
      63,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,     4,
      -1,   204,    -1,     8,    -1,   208,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    -1,    21,    22,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    30,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    41,    -1,    -1,    -1,
      45,    -1,    -1,    48,    49,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    62,    63,    64,
      65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     105,    -1,   107,   108,   109,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,     4,    -1,   204,
      -1,     8,   207,   208,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    -1,    -1,    21,    22,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    30,    -1,    32,    -1,    34,    35,    -1,
      -1,    38,    -1,    -1,    41,    -1,    -1,    -1,    45,    -1,
      -1,    48,    49,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    61,    62,    63,    64,    65,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,
     107,   108,   109,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,    -1,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,     4,    -1,   204,    -1,     8,
      -1,   208,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      -1,    -1,    21,    22,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    30,    -1,    32,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    41,    -1,    -1,    -1,    45,    -1,    -1,    48,
      49,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    74,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,   107,   108,
     109,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,     4,    -1,   204,    -1,     8,    -1,   208,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,
      21,    22,    -1,    -1,    25,    -1,    -1,    -1,    -1,    30,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      41,    -1,    -1,    -1,    45,    -1,    -1,    48,    49,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    62,    63,    64,    65,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    74,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,   107,   108,   109,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,     4,    -1,   204,    -1,     8,    -1,   208,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    21,    22,
      -1,    -1,    25,    -1,    -1,    -1,    -1,    30,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    -1,
      -1,    -1,    45,    -1,    -1,    48,    49,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,
      63,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,   107,   108,   109,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,     4,
      -1,   204,    -1,     8,    -1,   208,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    -1,    21,    22,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    30,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    41,    -1,    -1,    -1,
      45,    -1,    -1,    48,    49,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    62,    63,    64,
      65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     105,    -1,   107,   108,   109,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,     4,    -1,   204,
      -1,     8,    -1,   208,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    -1,    -1,    21,    22,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    30,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    41,    -1,    -1,    -1,    45,    -1,
      -1,    48,    49,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    61,    62,    63,    64,    65,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,
     107,   108,   109,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,     4,    -1,   204,    -1,     8,
      -1,   208,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      -1,    -1,    21,    22,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    30,    -1,    32,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    41,    -1,    -1,    -1,    45,    -1,    -1,    48,
      49,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    74,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,   107,   108,
     109,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,     4,    -1,   204,    -1,     8,    -1,   208,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,
      21,    22,    -1,    -1,    25,    -1,    -1,    -1,    -1,    30,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      41,    -1,    -1,    -1,    45,    -1,    -1,    48,    49,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    62,    63,    64,    65,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    74,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,   107,   108,   109,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,    -1,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,     4,    -1,   204,    -1,     8,    -1,   208,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    21,    22,
      -1,    -1,    25,    -1,    -1,    -1,    -1,    30,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    -1,
      -1,    -1,    45,    -1,    -1,    48,    49,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,
      63,    64,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,   107,   108,   109,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,    -1,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,     4,
      -1,   204,    -1,     8,    -1,   208,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    -1,    21,    22,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    30,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    41,    -1,    -1,    -1,
      45,    -1,    -1,    48,    49,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    62,    63,    64,
      65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     105,    -1,   107,   108,   109,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,     4,    -1,   204,
      -1,     8,    -1,   208,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    -1,    -1,    21,    22,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    30,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    41,    -1,    -1,    -1,    45,    -1,
      -1,    48,    49,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    61,    62,    63,    64,    65,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,     8,
     107,   108,   109,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,    -1,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,    -1,    -1,    -1,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,    -1,    -1,   204,    -1,    -1,
      -1,   208,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,   212,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,     8,     9,    -1,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      -1,    86,    87,    88,    89,    90,    91,    92,    -1,    -1,
      -1,    96,    97,    98,    99,   100,   101,   102,   103,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,     8,     9,    -1,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   209,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      -1,    86,    87,    88,    89,    90,    91,    92,    -1,    -1,
      -1,    96,    97,    98,    99,   100,   101,   102,   103,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,     8,    -1,    -1,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,
      -1,    -1,    -1,    -1,    59,    -1,    61,    -1,    -1,    64,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,     8,    -1,    -1,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,    -1,    -1,    -1,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,     8,    -1,    -1,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     8,     9,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    91,    -1,    -1,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,     8,    -1,    -1,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,     8,    -1,    -1,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,    -1,    -1,     8,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,    -1,    -1,     8,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    -1,    -1,     8,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,    -1,    -1,     8,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,    -1,    -1,
      -1,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,    -1,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,    -1,
      -1,    -1,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     4,    18,    21,    25,    30,    32,    45,    60,    62,
      63,    65,    66,    73,    74,    96,   105,   107,   108,   109,
     156,   204,   208,   215,   216,   217,   218,   220,   221,   222,
     223,   233,   234,   246,   247,   248,   252,   253,   258,   259,
     260,   279,   280,   324,   325,   360,   361,     4,    58,    71,
     139,   169,   219,     8,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   230,   231,   232,    56,   132,   187,   219,   239,
     261,    58,    73,   139,   156,   187,   219,   219,    69,   231,
     306,   362,   363,   363,    41,   327,    38,   120,   155,   307,
     308,   309,   317,   318,   116,   229,   231,    65,   204,   220,
      22,    41,    48,    49,    52,    58,    61,    64,    77,   114,
     120,   139,   155,   156,   218,   231,   283,   284,   285,   286,
     287,   289,   293,   294,   295,   296,   307,   308,   309,   319,
     320,   321,   322,   323,     0,     3,   207,   229,   229,   204,
     224,   210,    62,   211,   234,   247,    58,   139,   253,    41,
     326,   326,   326,   116,   229,   171,   311,    96,   364,   364,
      54,   229,    40,   152,   231,   231,   231,   209,   229,   113,
     235,   236,   237,   238,   210,   318,   288,   318,   296,   296,
     283,   298,   327,   298,   318,   318,   135,   298,   299,   300,
     327,   212,   217,    53,    59,    67,   122,   127,   146,   153,
     276,   281,   282,   281,   205,   225,   226,   228,   231,   219,
       8,     9,    26,   262,   327,   327,    36,   229,   229,   229,
     229,     9,   118,   119,   121,   123,   124,   126,   129,   147,
     150,   163,   166,   167,   365,   366,   369,    36,    19,   111,
     254,   255,   231,    40,    46,   310,   318,    28,    58,   135,
     139,   157,   243,   244,   249,   250,   251,   298,   301,    26,
     132,   236,   139,   240,   241,   242,   243,   244,   301,   231,
      76,   290,   291,   135,    72,   207,   135,   283,   229,   110,
     109,   135,   135,   207,   298,   301,   229,   114,   294,   319,
      67,    67,   165,     9,    67,    67,    67,   276,   205,   209,
       6,   227,   210,   204,   264,    15,   263,   229,   229,   209,
     211,    30,    45,    74,   256,   310,   231,   317,    24,    37,
     231,   302,   312,   231,   231,   245,   231,   142,   278,   286,
     277,   283,   135,   251,   298,   207,   135,   135,   242,   207,
     318,    34,    35,   135,   291,   292,    41,   298,    52,   207,
     204,   318,   298,   135,   207,   204,   296,   297,   297,   130,
     130,   132,   144,   226,   228,   231,   205,   204,   204,   366,
       9,    10,    11,    12,    13,    14,    15,    16,   210,   231,
     273,   344,   345,   367,   368,    55,   310,    23,    27,   140,
       9,    51,    78,    79,    80,    81,    82,    83,    84,    86,
      87,    88,    89,    90,    91,    92,    96,    97,    98,    99,
     100,   101,   102,   103,   145,   151,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   209,
     230,   313,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   346,   347,   204,   204,   204,   245,   207,   135,
     245,   245,   207,    72,   298,   288,    22,   135,   292,    42,
      44,    57,   265,   266,   267,   271,   135,   135,   231,   268,
     269,   270,   265,   268,   231,   210,   229,    39,    39,    39,
      90,    92,    85,   104,   204,   349,   352,   349,   352,   349,
     204,    89,    90,   204,   342,    90,   204,   204,   339,   231,
      29,   314,   213,   204,   338,   204,   340,   204,   343,   204,
     341,   352,   352,   348,   349,   348,   265,   265,   117,   245,
     298,    22,   205,   209,   231,    61,    77,   272,   313,   205,
     209,   205,   205,   210,   231,    39,   305,   306,   344,    18,
      25,    32,   221,    54,    68,    70,   231,   303,   304,   305,
     349,   344,    91,   353,   353,     9,    12,   350,   351,   104,
      10,   350,    10,   316,   162,    10,    93,    94,   185,    10,
      11,    93,    94,   185,    10,    10,    93,    94,   185,   353,
     353,   353,   205,   205,   209,    31,    54,   122,   127,   146,
     153,   274,   275,   276,   277,   267,   272,   160,   270,   274,
     277,   160,   231,   210,    33,    56,   138,   209,   283,   353,
     205,    89,   106,   356,   357,   356,   205,   209,   205,   205,
     205,   205,    94,    94,   205,   209,   205,    94,    94,   205,
     205,   209,    94,    94,    95,   358,   359,   359,   356,    64,
     231,    31,   275,   277,    29,   315,   313,   277,   313,   231,
     161,    62,   304,   356,    96,   359,     9,    91,   231,   355,
     359,   353,   351,   353,    10,    10,     9,   231,   354,   359,
     313,   205,   316,   274,   278,   274,   278,   137,   158,   257,
     283,   359,   356,   356,   205,   205,   278,   278,   229,   229,
     359,   359,   257,   257
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (&yylloc, parse_ctx, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, &yylloc, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, &yylloc)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location, parse_ctx); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, ObParseCtx *parse_ctx)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, parse_ctx)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    ObParseCtx *parse_ctx;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (parse_ctx);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, ObParseCtx *parse_ctx)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, parse_ctx)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    ObParseCtx *parse_ctx;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, parse_ctx);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, ObParseCtx *parse_ctx)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, parse_ctx)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    ObParseCtx *parse_ctx;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , parse_ctx);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, parse_ctx); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, ObParseCtx *parse_ctx)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, parse_ctx)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    ObParseCtx *parse_ctx;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (parse_ctx);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (ObParseCtx *parse_ctx);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */





/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (ObParseCtx *parse_ctx)
#else
int
yyparse (parse_ctx)
    ObParseCtx *parse_ctx;
#endif
#endif
{
/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 303 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      merge_nodes((yyval.node), parse_ctx->mem_pool_, T_STMT_LIST, (yyvsp[(1) - (2)].node));
      parse_ctx->stmt_tree_ = (yyval.node);
      YYACCEPT;
    ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 312 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_LINK_NODE, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
      parse_ctx->stmt_tree_ = (yyval.node);
    ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 317 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.node) = (yyvsp[(1) - (1)].node);
      parse_ctx->stmt_tree_ = (yyval.node);
    ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 333 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
    if(NULL != (yyvsp[(1) - (1)].node) && !parse_ctx->is_inner_parse_) {
      switch((yyvsp[(1) - (1)].node)->type_) {
        // wrap nodes of following types into an anonymous block to mock SQL execution.
        case T_SP_DO:
        case T_SP_SIGNAL:
        case T_SP_RESIGNAL: {
          ParseNode *proc_stmts = NULL;
          merge_nodes(proc_stmts, parse_ctx->mem_pool_, T_SP_PROC_STMT_LIST, (yyvsp[(1) - (1)].node));
          ParseNode *block_content = NULL;
          merge_nodes(block_content, parse_ctx->mem_pool_, T_SP_BLOCK_CONTENT, proc_stmts);
          malloc_non_terminal_node((yyvsp[(1) - (1)].node), parse_ctx->mem_pool_, T_SP_ANONYMOUS_BLOCK, 1, block_content);
        } break;
        default:{
          // do nothing
        } break;
      }
    }

    (yyval.node) = (yyvsp[(1) - (1)].node);
    int32_t str_len = (yylsp[(1) - (1)]).last_column - (yylsp[(1) - (1)]).first_column + 1;
    (yyval.node)->pos_ = (yylsp[(1) - (1)]).first_column;
    (yyval.node)->str_len_ = str_len;
  ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 357 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 360 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 361 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 362 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 363 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 364 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 365 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 366 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 367 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 368 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 369 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 370 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 371 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 372 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 373 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 374 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 375 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 376 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 377 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 379 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      if (!parse_ctx->is_inner_parse_) {
        obpl_mysql_yyerror(&(yylsp[(1) - (1)]), parse_ctx, "Syntax Error\n");
        YYERROR;
      }
      (yyval.node) = (yyvsp[(1) - (1)].node);
    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 394 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 395 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 396 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 400 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 401 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 402 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 403 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 404 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 405 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 410 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      //read sql query string直到读到token';'或者END_P
      ParseNode *sql_stmt = NULL;
      do_parse_sql_stmt(sql_stmt, parse_ctx, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_column, 2, ';', END_P);
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SQL_STMT, 1, sql_stmt);
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 417 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      //read sql query string直到读到token';'或者END_P
      ParseNode *sql_stmt = NULL;
      do_parse_sql_stmt(sql_stmt, parse_ctx, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_column, 2, ';', END_P);
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SQL_STMT, 1, sql_stmt);
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 424 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      //read sql query string直到读到token';'或者END_P
      ParseNode *sql_stmt = NULL;
      do_parse_sql_stmt(sql_stmt, parse_ctx, (yylsp[(1) - (2)]).first_column, (yylsp[(1) - (2)]).last_column, 2, ';', END_P);
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SQL_STMT, 1, sql_stmt);
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 431 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      //read sql query string直到读到token';'或者END_P
      ParseNode *sql_stmt = NULL;
      do_parse_sql_stmt(sql_stmt, parse_ctx, (yylsp[(1) - (2)]).first_column, (yylsp[(1) - (2)]).last_column, 2, ';', END_P);
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SQL_STMT, 1, sql_stmt);
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 438 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      //read sql query string直到读到token';'或者END_P
      ParseNode *sql_stmt = NULL;
      do_parse_sql_stmt(sql_stmt, parse_ctx, (yylsp[(1) - (2)]).first_column, (yylsp[(1) - (2)]).last_column, 2, ';', END_P);
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SQL_STMT, 1, sql_stmt);
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 445 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      //read sql query string直到读到token';'或者END_P
      ParseNode *sql_stmt = NULL;
      do_parse_sql_stmt(sql_stmt, parse_ctx, (yylsp[(1) - (4)]).first_column, (yylsp[(1) - (4)]).last_column, 2, ';', END_P);
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SQL_STMT, 1, sql_stmt);
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 452 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      //read sql query string直到读到token';'或者END_P
      ParseNode *sql_stmt = NULL;
      do_parse_sql_stmt(sql_stmt, parse_ctx, (yylsp[(1) - (2)]).first_column, (yylsp[(1) - (2)]).last_column, 2, ';', END_P);
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SQL_STMT, 1, sql_stmt);
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 459 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      //read sql query string直到读到token';'或者END_P
      ParseNode *sql_stmt = NULL;
      do_parse_sql_stmt(sql_stmt, parse_ctx, (yylsp[(1) - (2)]).first_column, (yylsp[(1) - (2)]).last_column, 2, ';', END_P);
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SQL_STMT, 1, sql_stmt);
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 466 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      //read sql query string直到读到token';'或者END_P
      ParseNode *sql_stmt = NULL;
      do_parse_sql_stmt(sql_stmt, parse_ctx, (yylsp[(1) - (2)]).first_column, (yylsp[(1) - (2)]).last_column, 2, ';', END_P);
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SQL_STMT, 1, sql_stmt);
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 473 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      //read sql query string直到读到token';'或者END_P
      ParseNode *sql_stmt = NULL;
      do_parse_sql_stmt(sql_stmt, parse_ctx, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_column, 2, ';', END_P);
      if (T_SET_PASSWORD == sql_stmt->type_ ||
          T_SET_NAMES == sql_stmt->type_ ||
          T_SET_CHARSET == sql_stmt->type_ ||
          T_SET_ROLE == sql_stmt->type_ ||
          T_ALTER_USER_DEFAULT_ROLE == sql_stmt->type_) {
        malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SQL_STMT, 1, sql_stmt);
      } else {
        (yyval.node) = sql_stmt;
      }
      if(T_VARIABLE_SET == (yyval.node)->type_) {
        int64_t child_cnt = (yyval.node)->num_child_;
        for(int64_t i = 0; i < (yyval.node)->num_child_; ++i) {
          if (T_SET_NAMES == (yyval.node)->children_[i]->type_ || T_SET_CHARSET == (yyval.node)->children_[i]->type_) {
            malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SQL_STMT, 1, sql_stmt);
            if (child_cnt > 1) {
              obpl_mysql_yyerror(&(yylsp[(1) - (1)]), parse_ctx, "Syntax Error\n");
              YYERROR;
            }
          } else if(OB_UNLIKELY(NULL == (yyval.node)->children_[i] || NULL == (yyval.node)->children_[i]->children_[1])) {
            YY_UNEXPECTED_ERROR("value node in SET statement is NULL");
          } else {
            obpl_mysql_wrap_get_user_var_into_subquery(parse_ctx, (yyval.node)->children_[i]->children_[1]);
          }
        }
      }
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 504 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SQL_STMT);
      (yyval.node)->str_value_ = parse_strdup("COMMIT", parse_ctx->mem_pool_, &((yyval.node)->str_len_));
      if (OB_UNLIKELY(NULL == (yyval.node)->str_value_)) {
        YY_FATAL_ERROR("no more memory to malloc 'COMMIT; string\n");
      }
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 512 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SQL_STMT);
      (yyval.node)->str_value_ = parse_strdup("ROLLBACK", parse_ctx->mem_pool_, &((yyval.node)->str_len_));
      if (OB_UNLIKELY(NULL == (yyval.node)->str_value_)) {
        YY_FATAL_ERROR("no more memory to malloc 'ROLLBACK; string\n");
      }
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 520 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
    //read sql query string直到读到token';'或者END_P
    ParseNode *sql_stmt = NULL;
    do_parse_sql_stmt(sql_stmt, parse_ctx, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_column, 2, ';', END_P);
    malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SQL_STMT, 1, sql_stmt);
  ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 527 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      //read sql query string直到读到token';'或者END_P
      ParseNode *sql_stmt = NULL;
      do_parse_sql_stmt(sql_stmt, parse_ctx, (yylsp[(1) - (2)]).first_column, (yylsp[(1) - (2)]).last_column, 2, ';', END_P);
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SQL_STMT, 1, sql_stmt);
  ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 537 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      if (NULL == (yyvsp[(2) - (2)].node)) {
        obpl_mysql_yyerror(&(yylsp[(2) - (2)]), parse_ctx, "Syntax Error, Invalid expr to be evaluated\n");
        YYERROR;
      } else if (T_OBJ_ACCESS_REF == (yyvsp[(2) - (2)].node)->type_) {
        ParseNode *cur_node = (yyvsp[(2) - (2)].node);
        ParseNode *last_node = NULL;
        while (NULL != cur_node->children_[1] && T_OBJ_ACCESS_REF == cur_node->children_[1]->type_) {
          last_node = cur_node;
          cur_node = cur_node->children_[1];
        }
        if (OB_UNLIKELY(NULL == cur_node || NULL != cur_node->children_[1] || NULL == cur_node->children_[0])) {
          obpl_mysql_yyerror(&(yylsp[(2) - (2)]), parse_ctx, "Syntax Error, Invalid ObjAccess string\n");
          YYERROR;
        } else if (T_IDENT == cur_node->children_[0]->type_
            && 6 == cur_node->children_[0]->str_len_
            && 0 == strncasecmp(cur_node->children_[0]->str_value_, "EXTEND", 6)) {
          if (OB_UNLIKELY(NULL == last_node)) {
            obpl_mysql_yyerror(&(yylsp[(2) - (2)]), parse_ctx, "Syntax Error, Invalid ObjAccess string\n");
            YYERROR;
          } else {
            last_node->children_[1] = NULL;
            malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_EXTEND, 2, (yyvsp[(2) - (2)].node), NULL);
          }
        } else if (T_FUN_SYS == cur_node->children_[0]->type_
            && NULL != cur_node->children_[0]->children_[0]
            && T_IDENT == cur_node->children_[0]->children_[0]->type_
            && 6 == cur_node->children_[0]->children_[0]->str_len_
            && 0 == strncasecmp(cur_node->children_[0]->children_[0]->str_value_, "EXTEND", 6)) {
          if (OB_UNLIKELY(NULL == last_node)) {
            obpl_mysql_yyerror(&(yylsp[(2) - (2)]), parse_ctx, "Syntax Error, Invalid ObjAccess string\n");
            YYERROR;
          } else {
            last_node->children_[1] = NULL;
            malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_EXTEND, 2, (yyvsp[(2) - (2)].node), cur_node->children_[0]);
          }
        } else {
        ParseNode *do_expr_list = NULL;
        merge_nodes(do_expr_list, parse_ctx->mem_pool_, T_EXPR_LIST, (yyvsp[(2) - (2)].node));
        malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_DO, 1, do_expr_list);
        }
      } else {
        ParseNode *do_expr_list = NULL;
        merge_nodes(do_expr_list, parse_ctx->mem_pool_, T_EXPR_LIST, (yyvsp[(2) - (2)].node));
        for (int64_t i = 0; i < do_expr_list->num_child_; ++i) {
          if (T_COLUMN_REF == do_expr_list->children_[i]->type_) {
            obpl_mysql_yyerror(&(yylsp[(2) - (2)]), parse_ctx, "Syntax Error, DO statement cannot reference to a table\n");
            YYERROR;
            break;
          }
        }
        malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_DO, 1, do_expr_list);
      }
    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 591 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(2) - (2)].node); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 592 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(2) - (2)].node); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 593 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(2) - (2)].node); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 598 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_CALL_STMT, 2, (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 602 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      if (!parse_ctx->is_inner_parse_) {
        obpl_mysql_yyerror(&(yylsp[(2) - (2)]), parse_ctx, "Syntax Error\n");
        YYERROR; //生成一个语法错误
      }
      (yyval.node) = (yyvsp[(2) - (2)].node);
    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 610 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      if (!parse_ctx->is_inner_parse_) {
        obpl_mysql_yyerror(&(yylsp[(2) - (9)]), parse_ctx, "Syntax Error\n");
        YYERROR; //生成一个语法错误
      }
      (yyval.node) = (yyvsp[(9) - (9)].node);
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 618 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      if (!parse_ctx->is_inner_parse_) {
        obpl_mysql_yyerror(&(yylsp[(2) - (8)]), parse_ctx, "Syntax Error\n");
        YYERROR; //生成一个语法错误
      }
      (yyval.node) = (yyvsp[(8) - (8)].node);
    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 626 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      if (!parse_ctx->is_inner_parse_) {
        obpl_mysql_yyerror(&(yylsp[(2) - (11)]), parse_ctx, "Syntax Error\n");
        YYERROR; //生成一个语法错误
      }
      (yyval.node) = (yyvsp[(11) - (11)].node);
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 634 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      if (!parse_ctx->is_inner_parse_) {
        obpl_mysql_yyerror(&(yylsp[(2) - (10)]), parse_ctx, "Syntax Error\n");
        YYERROR; //生成一个语法错误
      }
      (yyval.node) = (yyvsp[(10) - (10)].node);
    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 644 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 645 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 647 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      merge_nodes((yyval.node), parse_ctx->mem_pool_, T_SP_CPARAM_LIST, (yyvsp[(2) - (3)].node));
    ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 654 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      if ((yyvsp[(1) - (3)].node) == NULL || (yyvsp[(3) - (3)].node) == NULL) {
        YYERROR;
      }
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_LINK_NODE, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 660 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 665 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
    if (NULL == (yyvsp[(1) - (2)].node) && NULL != (yyvsp[(2) - (2)].node)) {
      YYERROR;
    }
    if (NULL == (yyvsp[(2) - (2)].node)) {
      (yyval.node) = (yyvsp[(1) - (2)].node);
    }
    if (NULL != (yyvsp[(2) - (2)].node)) {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_CPARAM, 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
    }
      if (NULL != (yyvsp[(1) - (2)].node))
    copy_node_abs_location((yyvsp[(1) - (2)].node)->stmt_loc_, (yylsp[(1) - (2)]));
  ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 681 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 683 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
    if (NULL == (yyvsp[(2) - (2)].node)) YYERROR; (yyval.node) = (yyvsp[(2) - (2)].node);
      if (NULL != (yyvsp[(2) - (2)].node))
    copy_node_abs_location((yyvsp[(2) - (2)].node)->stmt_loc_, (yylsp[(2) - (2)]));
  ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 691 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      //same as expr in sql rule, and terminate when read ';'
      do_parse_sql_expr_rule((yyval.node), parse_ctx, 3, ',', ')', PARAM_ASSIGN_OPERATOR);
      if (NULL == (yyval.node)) {
        YYERROR;
      }
    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 707 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_NAME, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 711 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_NAME, 2, NULL, (yyvsp[(1) - (1)].node));
    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 718 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_ACCESS_NAME, 3, (yyvsp[(1) - (5)].node), (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node));
    ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 722 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_ACCESS_NAME, 3, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 726 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_ACCESS_NAME, 3, NULL, NULL, (yyvsp[(1) - (1)].node));
    ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 733 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.node) = (yyvsp[(1) - (1)].node);
      (yyval.node)->pl_str_off_ = (yylsp[(1) - (1)]).first_column;
      // Check if this identifier is create_ai_model_endpoint or alter_ai_model_endpoint and set sensitive data flag
      if (((yyval.node)->str_len_ == 24 && !strncasecmp((yyval.node)->str_value_, "create_ai_model_endpoint", 24))
        || ((yyval.node)->str_len_ == 23 &&  !strncasecmp((yyval.node)->str_value_, "alter_ai_model_endpoint", 23))) {
        parse_ctx->contain_sensitive_data_ = 1;
      }
    ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 743 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      get_non_reserved_node((yyval.node), parse_ctx->mem_pool_, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_column);
      (yyval.node)->pl_str_off_ = (yylsp[(1) - (1)]).first_column;
    ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 847 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      const char *stmt_str = parse_ctx->orig_stmt_str_ + (yylsp[(3) - (3)]).first_column;
      int32_t str_len = (yylsp[(3) - (3)]).last_column - (yylsp[(3) - (3)]).first_column + 1;
      (yyvsp[(3) - (3)].node)->str_value_ = parse_strndup(stmt_str, str_len, parse_ctx->mem_pool_);
      check_ptr((yyvsp[(3) - (3)].node)->str_value_);
      (yyvsp[(3) - (3)].node)->str_len_ = str_len;
      (yyvsp[(3) - (3)].node)->pl_str_off_ = (yylsp[(3) - (3)]).first_column;
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_PACKAGE_CREATE, 1, (yyvsp[(3) - (3)].node));
      (yyval.node)->int32_values_[0] = (yyvsp[(2) - (3)].ival);
      (yyval.node)->int32_values_[1] = 0;
    ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 862 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      ParseNode *pkg_decl_stmts = NULL;
      merge_nodes(pkg_decl_stmts, parse_ctx->mem_pool_, T_PACKAGE_STMTS, (yyvsp[(4) - (6)].node));
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_PACKAGE_BLOCK, 4, (yyvsp[(2) - (6)].node), (yyvsp[(3) - (6)].node), pkg_decl_stmts, (yyvsp[(6) - (6)].node));
      if (parse_ctx->is_inner_parse_) {
        const char *stmt_str = parse_ctx->orig_stmt_str_ + (yylsp[(4) - (6)]).first_column;
        int32_t str_len = (yylsp[(6) - (6)]).last_column - (yylsp[(4) - (6)]).first_column + 1;
        (yyval.node)->str_value_ = parse_strndup(stmt_str, str_len, parse_ctx->mem_pool_);
        check_ptr((yyval.node)->str_value_);
        (yyval.node)->str_len_ = str_len;
        (yyval.node)->pl_str_off_ = (yylsp[(4) - (6)]).first_column;
      }
    ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 879 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_INVOKE);
      (yyval.node)->value_ = SP_CURRENT_USER;
    ;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 884 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_INVOKE);
      (yyval.node)->value_ = SP_DEFINER;
    ;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 891 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 896 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_LINK_NODE, 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
    ;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 899 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 903 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 905 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      merge_nodes((yyval.node), parse_ctx->mem_pool_, T_SP_CLAUSE_LIST, (yyvsp[(1) - (1)].node));
    ;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 911 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = 0; ;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 912 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = 1; ;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 916 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 918 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      merge_nodes((yyval.node), parse_ctx->mem_pool_, T_PACKAGE_STMTS, (yyvsp[(1) - (1)].node));
    ;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 925 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_LINK_NODE, 2, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node));
    ;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 928 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 931 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 932 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 933 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 938 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      const char *stmt_str = parse_ctx->stmt_str_ + (yylsp[(1) - (7)]).first_column;
      int32_t str_len = (yylsp[(7) - (7)]).last_column - (yylsp[(1) - (7)]).first_column + 1;
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SUB_FUNC_DECL, 5, (yyvsp[(2) - (7)].node), (yyvsp[(4) - (7)].node), (yyvsp[(7) - (7)].node), NULL, NULL);
      check_ptr((yyval.node));
      (yyval.node)->str_value_ = parse_strndup(stmt_str, str_len, parse_ctx->mem_pool_);
      check_ptr((yyval.node)->str_value_);
      (yyval.node)->str_len_ = str_len;
    ;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 951 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      const char *stmt_str = parse_ctx->stmt_str_ + (yylsp[(1) - (5)]).first_column;
      int32_t str_len = (yylsp[(5) - (5)]).last_column - (yylsp[(1) - (5)]).first_column + 1;
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SUB_PROC_DECL, 3, (yyvsp[(2) - (5)].node), (yyvsp[(4) - (5)].node), NULL);
      check_ptr((yyval.node));
      (yyval.node)->str_value_ = parse_strndup(stmt_str, str_len, parse_ctx->mem_pool_);
      check_ptr((yyval.node)->str_value_);
      (yyval.node)->str_len_ = str_len;
    ;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 963 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 964 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 974 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      check_ptr((yyvsp[(3) - (3)].node));
      const char *stmt_str = parse_ctx->orig_stmt_str_ + (yylsp[(3) - (3)]).first_column;
      int32_t str_len = (yylsp[(3) - (3)]).last_column - (yylsp[(3) - (3)]).first_column + 1;
      (yyvsp[(3) - (3)].node)->str_value_ = parse_strndup(stmt_str, str_len, parse_ctx->mem_pool_);
      check_ptr((yyvsp[(3) - (3)].node)->str_value_);
      (yyvsp[(3) - (3)].node)->str_len_ = str_len;
      (yyvsp[(3) - (3)].node)->pl_str_off_ = (yylsp[(3) - (3)]).first_column;
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_PACKAGE_CREATE_BODY, 1, (yyvsp[(3) - (3)].node));
      (yyval.node)->int32_values_[0] = (yyvsp[(2) - (3)].ival);
      (yyval.node)->int32_values_[1] = 0;
    ;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 991 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      ParseNode *proc_stmts = NULL;
      ParseNode *decl_ext_list = NULL;
      merge_nodes(decl_ext_list, parse_ctx->mem_pool_, T_PACKAGE_BODY_STMTS, (yyvsp[(4) - (7)].node));
      merge_nodes(proc_stmts, parse_ctx->mem_pool_, T_SP_PROC_STMT_LIST, (yyvsp[(5) - (7)].node));
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_PACKAGE_BODY_BLOCK, 4, (yyvsp[(3) - (7)].node), decl_ext_list, proc_stmts, (yyvsp[(7) - (7)].node));
      if (parse_ctx->is_inner_parse_) {
        const char *stmt_str = parse_ctx->orig_stmt_str_ + (yylsp[(4) - (7)]).first_column;
        int32_t str_len = (yylsp[(7) - (7)]).last_column - (yylsp[(4) - (7)]).first_column + 1;
        (yyval.node)->str_value_ = parse_strndup(stmt_str, str_len, parse_ctx->mem_pool_);
        check_ptr((yyval.node)->str_value_);
        (yyval.node)->str_len_ = str_len;
        (yyval.node)->pl_str_off_ = (yylsp[(4) - (7)]).first_column;
      }
    ;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 1007 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      ParseNode *proc_stmts = NULL;
      ParseNode *decl_ext_list = NULL;
      merge_nodes(proc_stmts, parse_ctx->mem_pool_, T_SP_PROC_STMT_LIST, (yyvsp[(4) - (6)].node));
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_PACKAGE_BODY_BLOCK, 4, (yyvsp[(3) - (6)].node), decl_ext_list, proc_stmts, (yyvsp[(6) - (6)].node));
      if (parse_ctx->is_inner_parse_) {
        const char *stmt_str = parse_ctx->orig_stmt_str_ + (yylsp[(4) - (6)]).first_column;
        int32_t str_len = (yylsp[(6) - (6)]).last_column - (yylsp[(4) - (6)]).first_column + 1;
        (yyval.node)->str_value_ = parse_strndup(stmt_str, str_len, parse_ctx->mem_pool_);
        check_ptr((yyval.node)->str_value_);
        (yyval.node)->str_len_ = str_len;
        (yyval.node)->pl_str_off_ = (yylsp[(4) - (6)]).first_column;
      }
    ;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1022 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      ParseNode *proc_stmts = NULL;
      ParseNode *decl_ext_list = NULL;
      merge_nodes(decl_ext_list, parse_ctx->mem_pool_, T_PACKAGE_BODY_STMTS, (yyvsp[(4) - (6)].node));
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_PACKAGE_BODY_BLOCK, 4, (yyvsp[(3) - (6)].node), decl_ext_list, proc_stmts, (yyvsp[(6) - (6)].node));
      if (parse_ctx->is_inner_parse_) {
        const char *stmt_str = parse_ctx->orig_stmt_str_ + (yylsp[(4) - (6)]).first_column;
        int32_t str_len = (yylsp[(6) - (6)]).last_column - (yylsp[(4) - (6)]).first_column + 1;
        (yyval.node)->str_value_ = parse_strndup(stmt_str, str_len, parse_ctx->mem_pool_);
        check_ptr((yyval.node)->str_value_);
        (yyval.node)->str_len_ = str_len;
      }
    ;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 1036 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_PACKAGE_BODY_BLOCK, 4, (yyvsp[(3) - (5)].node), NULL, NULL, (yyvsp[(5) - (5)].node));
      if (parse_ctx->is_inner_parse_) {
        const char *stmt_str = parse_ctx->orig_stmt_str_ + (yylsp[(4) - (5)]).first_column;
        int32_t str_len = (yylsp[(5) - (5)]).last_column - (yylsp[(4) - (5)]).first_column + 1;
        (yyval.node)->str_value_ = parse_strndup(stmt_str, str_len, parse_ctx->mem_pool_);
        check_ptr((yyval.node)->str_value_);
        (yyval.node)->str_len_ = str_len;
        (yyval.node)->pl_str_off_ = (yylsp[(4) - (5)]).first_column;
      }
    ;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1056 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_PACKAGE_DROP, 1, (yyvsp[(3) - (3)].node));
      (yyval.node)->value_ = 0;
    ;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 1061 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_PACKAGE_DROP, 1, (yyvsp[(4) - (4)].node));
      (yyval.node)->value_ = 2;
    ;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 1069 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
    malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_PRAGMA_INTERFACE, 1, (yyvsp[(6) - (7)].node));
  ;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1075 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1077 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_LINK_NODE, 2, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node));
    ;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1083 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 1084 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1085 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1086 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1088 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      check_ptr((yyvsp[(2) - (2)].node));
      const char *stmt_str = parse_ctx->stmt_str_ + (yylsp[(1) - (2)]).first_column;
      int32_t str_len = (yylsp[(2) - (2)]).last_column - (yylsp[(1) - (2)]).first_column + 1;
      (yyvsp[(2) - (2)].node)->str_value_ = parse_strndup(stmt_str, str_len, parse_ctx->mem_pool_);
      check_ptr((yyvsp[(2) - (2)].node)->str_value_);
      (yyvsp[(2) - (2)].node)->str_len_ = str_len;
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SUB_FUNC_DEF, 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
    ;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1098 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      check_ptr((yyvsp[(2) - (2)].node));
      const char *stmt_str = parse_ctx->stmt_str_ + (yylsp[(1) - (2)]).first_column;
      int32_t str_len = (yylsp[(2) - (2)]).last_column - (yylsp[(1) - (2)]).first_column + 1;
      (yyvsp[(2) - (2)].node)->str_value_ = parse_strndup(stmt_str, str_len, parse_ctx->mem_pool_);
      check_ptr((yyvsp[(2) - (2)].node)->str_value_);
      (yyvsp[(2) - (2)].node)->str_len_ = str_len;
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SUB_PROC_DEF, 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
    ;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1116 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      check_ptr((yyvsp[(3) - (3)].node));
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_TG_CREATE, 2, (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node));
      (yyval.node)->int32_values_[0] = 0; // or_replace = false
      (yyval.node)->int32_values_[1] = 0; // editionable = false
    ;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1126 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      check_ptr((yyvsp[(4) - (4)].node));
      const char *stmt_str = parse_ctx->stmt_str_ + (yylsp[(1) - (4)]).first_column;
      int32_t str_len = (yylsp[(4) - (4)]).last_column - (yylsp[(1) - (4)]).first_column + 1;
      (yyvsp[(4) - (4)].node)->str_value_ = parse_strndup(stmt_str, str_len, parse_ctx->mem_pool_);
      check_ptr((yyvsp[(4) - (4)].node)->str_value_);
      (yyvsp[(4) - (4)].node)->str_len_ = str_len;
      (yyvsp[(4) - (4)].node)->pl_str_off_ = (yylsp[(1) - (4)]).first_column;
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_TG_SOURCE, 2, (yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].node));
      (yyval.node)->value_ = (yyvsp[(2) - (4)].ival);
    ;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 1141 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_TG_SIMPLE_DML, 4, (yyvsp[(2) - (8)].node), (yyvsp[(4) - (8)].node), NULL, (yyvsp[(8) - (8)].node));
      (yyval.node)->int16_values_[0] = (yyvsp[(1) - (8)].ival);
    ;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 1146 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_TG_ORDER, 1, (yyvsp[(9) - (10)].node));
      (yyval.node)->value_ = 1; // FOLLOWS
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_TG_SIMPLE_DML, 4, (yyvsp[(2) - (10)].node), (yyvsp[(4) - (10)].node), (yyval.node), (yyvsp[(10) - (10)].node));
      (yyval.node)->int16_values_[0] = (yyvsp[(1) - (10)].ival);
    ;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1153 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_TG_ORDER, 1, (yyvsp[(9) - (10)].node));
      (yyval.node)->value_ = 2; // PRECEDES
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_TG_SIMPLE_DML, 4, (yyvsp[(2) - (10)].node), (yyvsp[(4) - (10)].node), (yyval.node), (yyvsp[(10) - (10)].node));
      (yyval.node)->int16_values_[0] = (yyvsp[(1) - (10)].ival);
    ;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 1161 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = T_BEFORE; ;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1162 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = T_AFTER; ;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1166 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_INSERT); ;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1167 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_DELETE); ;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1168 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_UPDATE); ;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 1173 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
    const char *body_str = parse_ctx->stmt_str_ + (yylsp[(1) - (1)]).first_column;
    int32_t body_len = (yylsp[(1) - (1)]).last_column - (yylsp[(1) - (1)]).first_column + 1 + 2;
    char *dup_body = NULL;
    if (OB_LIKELY(NULL != (dup_body = (char *)parse_malloc(body_len + 1, parse_ctx->mem_pool_)))) {
      memmove(dup_body, body_str, body_len - 2);
      dup_body[body_len - 2] = ';';
      dup_body[body_len - 1] = '\n';
      dup_body[body_len] = '\0';
    }
    check_ptr(dup_body);
    (yyval.node)->str_value_ = dup_body;
    (yyval.node)->str_len_ = body_len;
    (yyval.node)->pl_str_off_ = (yylsp[(1) - (1)]).first_column;
  ;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1198 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_TG_DROP, 1, (yyvsp[(4) - (4)].node));
      (yyval.node)->value_ = (yyvsp[(3) - (4)].ival);
    ;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1211 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      check_ptr((yyvsp[(10) - (10)].node));
      ParseNode *sp_clause_node = NULL;
      merge_nodes(sp_clause_node, parse_ctx->mem_pool_, T_SP_CLAUSE_LIST, (yyvsp[(9) - (10)].node));
      const char *stmt_str = parse_ctx->stmt_str_ + (yylsp[(3) - (10)]).first_column;
      int32_t str_len = (yylsp[(10) - (10)]).last_column - (yylsp[(3) - (10)]).first_column + 1;
      (yyvsp[(10) - (10)].node)->str_value_ = parse_strndup(stmt_str, str_len, parse_ctx->mem_pool_);
      check_ptr((yyvsp[(10) - (10)].node)->str_value_);
      (yyvsp[(10) - (10)].node)->str_len_ = str_len;
      (yyvsp[(10) - (10)].node)->raw_text_ = (yyvsp[(10) - (10)].node)->str_value_ + (yylsp[(10) - (10)]).first_column - (yylsp[(3) - (10)]).first_column;
      (yyvsp[(10) - (10)].node)->text_len_ = str_len - ((yylsp[(10) - (10)]).first_column - (yylsp[(3) - (10)]).first_column);
      if (NULL != (yyvsp[(7) - (10)].node)) {
        const char *param_str = parse_ctx->stmt_str_ + (yylsp[(6) - (10)]).first_column + 1;
        int32_t param_len = (yylsp[(8) - (10)]).last_column - (yylsp[(6) - (10)]).last_column - 1;
        (yyvsp[(7) - (10)].node)->str_value_ = parse_strndup(param_str, param_len, parse_ctx->mem_pool_);
        check_ptr((yyvsp[(7) - (10)].node)->str_value_);
        (yyvsp[(7) - (10)].node)->str_len_ = param_len;
      }
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_CREATE, 5, (yyvsp[(2) - (10)].node), (yyvsp[(5) - (10)].node), (yyvsp[(7) - (10)].node), sp_clause_node, (yyvsp[(10) - (10)].node));
      (yyval.node)->value_ = (yyvsp[(4) - (10)].ival);
    ;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1233 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      check_ptr((yyvsp[(9) - (9)].node));
      const char *stmt_str = parse_ctx->stmt_str_ + (yylsp[(3) - (9)]).first_column;
      int32_t str_len = (yylsp[(9) - (9)]).last_column - (yylsp[(3) - (9)]).first_column + 1;
      (yyvsp[(9) - (9)].node)->str_value_ = parse_strndup(stmt_str, str_len, parse_ctx->mem_pool_);
      check_ptr((yyvsp[(9) - (9)].node)->str_value_);
      (yyvsp[(9) - (9)].node)->str_len_ = str_len;
      (yyvsp[(9) - (9)].node)->raw_text_ = (yyvsp[(9) - (9)].node)->str_value_ + (yylsp[(9) - (9)]).first_column - (yylsp[(3) - (9)]).first_column;
      (yyvsp[(9) - (9)].node)->text_len_ = str_len - ((yylsp[(9) - (9)]).first_column - (yylsp[(3) - (9)]).first_column);
      if (NULL != (yyvsp[(7) - (9)].node)) {
        const char *param_str = parse_ctx->stmt_str_ + (yylsp[(6) - (9)]).first_column + 1;
        int32_t param_len = (yylsp[(8) - (9)]).last_column - (yylsp[(6) - (9)]).last_column - 1;
        (yyvsp[(7) - (9)].node)->str_value_ = parse_strndup(param_str, param_len, parse_ctx->mem_pool_);
        check_ptr((yyvsp[(7) - (9)].node)->str_value_);
        (yyvsp[(7) - (9)].node)->str_len_ = param_len;
      }
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_CREATE, 5, (yyvsp[(2) - (9)].node), (yyvsp[(5) - (9)].node), (yyvsp[(7) - (9)].node), NULL, (yyvsp[(9) - (9)].node));
      (yyval.node)->value_ = (yyvsp[(4) - (9)].ival);
    ;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1256 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      check_ptr((yyvsp[(12) - (12)].node));
      ParseNode *sp_clause_node = NULL;
      merge_nodes(sp_clause_node, parse_ctx->mem_pool_, T_SP_CLAUSE_LIST, (yyvsp[(11) - (12)].node));
      const char *stmt_str = parse_ctx->stmt_str_ + (yylsp[(3) - (12)]).first_column;
      int32_t str_len = (yylsp[(12) - (12)]).last_column - (yylsp[(3) - (12)]).first_column + 1;
      (yyvsp[(12) - (12)].node)->str_value_ = parse_strndup(stmt_str, str_len, parse_ctx->mem_pool_);
      check_ptr((yyvsp[(12) - (12)].node)->str_value_);
      (yyvsp[(12) - (12)].node)->str_len_ = str_len;
      (yyvsp[(12) - (12)].node)->raw_text_ = (yyvsp[(12) - (12)].node)->str_value_ + (yylsp[(12) - (12)]).first_column - (yylsp[(3) - (12)]).first_column;
      (yyvsp[(12) - (12)].node)->text_len_ = str_len - ((yylsp[(12) - (12)]).first_column - (yylsp[(3) - (12)]).first_column);
      if (NULL != (yyvsp[(7) - (12)].node)) {
        const char *param_str = parse_ctx->stmt_str_ + (yylsp[(6) - (12)]).first_column + 1;
        int32_t param_len = (yylsp[(8) - (12)]).last_column - (yylsp[(6) - (12)]).last_column - 1;
        (yyvsp[(7) - (12)].node)->str_value_ = parse_strndup(param_str, param_len, parse_ctx->mem_pool_);
        check_ptr((yyvsp[(7) - (12)].node)->str_value_);
        (yyvsp[(7) - (12)].node)->str_len_ = param_len;
      }
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SF_CREATE, 6, (yyvsp[(2) - (12)].node), (yyvsp[(5) - (12)].node), (yyvsp[(7) - (12)].node), (yyvsp[(10) - (12)].node), sp_clause_node, (yyvsp[(12) - (12)].node));
      (yyval.node)->value_ = (yyvsp[(4) - (12)].ival);
    ;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1278 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      check_ptr((yyvsp[(11) - (11)].node));
      const char *stmt_str = parse_ctx->stmt_str_ + (yylsp[(3) - (11)]).first_column;
      int32_t str_len = (yylsp[(11) - (11)]).last_column - (yylsp[(3) - (11)]).first_column + 1;
      (yyvsp[(11) - (11)].node)->str_value_ = parse_strndup(stmt_str, str_len, parse_ctx->mem_pool_);
      check_ptr((yyvsp[(11) - (11)].node)->str_value_);
      (yyvsp[(11) - (11)].node)->str_len_ = str_len;
      (yyvsp[(11) - (11)].node)->raw_text_ = (yyvsp[(11) - (11)].node)->str_value_ + (yylsp[(11) - (11)]).first_column - (yylsp[(3) - (11)]).first_column;
      (yyvsp[(11) - (11)].node)->text_len_ = str_len - ((yylsp[(11) - (11)]).first_column - (yylsp[(3) - (11)]).first_column);
      if (NULL != (yyvsp[(7) - (11)].node)) {
        const char *param_str = parse_ctx->stmt_str_ + (yylsp[(6) - (11)]).first_column + 1;
        int32_t param_len = (yylsp[(8) - (11)]).last_column - (yylsp[(6) - (11)]).last_column - 1;
        (yyvsp[(7) - (11)].node)->str_value_ = parse_strndup(param_str, param_len, parse_ctx->mem_pool_);
        check_ptr((yyvsp[(7) - (11)].node)->str_value_);
        (yyvsp[(7) - (11)].node)->str_len_ = param_len;
      }
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SF_CREATE, 6, (yyvsp[(2) - (11)].node), (yyvsp[(5) - (11)].node), (yyvsp[(7) - (11)].node), (yyvsp[(10) - (11)].node), NULL, (yyvsp[(11) - (11)].node));
      (yyval.node)->value_ = (yyvsp[(4) - (11)].ival);
    ;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1300 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1302 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
    malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_USER_WITH_HOST_NAME, 2, (yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].node));
  ;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1306 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
    ParseNode *user_node = NULL;
    malloc_terminal_node(user_node, parse_ctx->mem_pool_, T_IDENT);
    user_node->str_value_ = "CURRENT_USER";
    user_node->str_len_ = strlen("CURRENT_USER");
    malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_USER_WITH_HOST_NAME, 2, user_node, NULL);
  ;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1317 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
  (yyval.node) = (yyvsp[(1) - (1)].node);
;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 1321 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
  (yyval.node) = (yyvsp[(1) - (1)].node);
;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 1327 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
  (yyval.node) = (yyvsp[(1) - (1)].node);
;}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1331 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
  (yyval.node) = NULL;
;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1338 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1339 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1343 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1345 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      merge_nodes((yyval.node), parse_ctx->mem_pool_, T_SP_PARAM_LIST, (yyvsp[(1) - (1)].node));
    ;}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1352 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_LINK_NODE, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1355 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1360 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_PARAM, 3, (yyvsp[(2) - (4)].node), (yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].node));
      (yyval.node)->value_ = (yyvsp[(1) - (4)].ival);
    ;}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1368 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1370 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      merge_nodes((yyval.node), parse_ctx->mem_pool_, T_SP_PARAM_LIST, (yyvsp[(1) - (1)].node));
    ;}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1377 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_LINK_NODE, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1380 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1385 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_PARAM, 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
      (yyval.node)->value_ = MODE_IN;
    ;}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1392 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = MODE_IN; ;}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1393 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = MODE_IN; ;}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 1394 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = MODE_OUT; ;}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1395 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = MODE_INOUT; ;}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1399 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1403 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_COLUMN_REF, 3, NULL, NULL, (yyvsp[(1) - (1)].node));
    ;}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1407 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_COLUMN_REF, 3, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1411 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_COLUMN_REF, 3, NULL, (yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node));
    ;}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1415 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_COLUMN_REF, 3, (yyvsp[(1) - (5)].node), (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node));
    ;}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1421 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1423 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_LINK_NODE, 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
    ;}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1429 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1431 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
    malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_DETERMINISTIC);
  ;}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1434 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { ;}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1439 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { 
    malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_COMMENT);
    (yyval.node)->str_value_ = (yyvsp[(2) - (2)].node)->str_value_;
    (yyval.node)->str_len_ = (yyvsp[(2) - (2)].node)->str_len_;
  ;}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 1444 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { /* Just parse it, we only have one language for now. */ (yyval.node) = NULL; ;}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1446 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
    malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_DATA_ACCESS);
    (yyval.node)->value_ = SP_NO_SQL;
  ;}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1451 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
    malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_DATA_ACCESS);
    (yyval.node)->value_ = SP_CONTAINS_SQL;
  ;}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1456 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { 
    malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_DATA_ACCESS);
    (yyval.node)->value_ = SP_READS_SQL_DATA;
  ;}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1461 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
    malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_DATA_ACCESS);
    (yyval.node)->value_ = SP_MODIFIES_SQL_DATA;
  ;}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1466 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
    malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_INVOKE);
    (yyval.node)->value_ = SP_DEFINER;
  ;}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1471 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
    malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_INVOKE);
    (yyval.node)->value_ = SP_INVOKER;
  ;}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1478 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1482 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1492 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_ALTER, 2, (yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].node));
    ;}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1499 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SF_ALTER, 2, (yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].node));
    ;}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1505 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1507 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      merge_nodes((yyval.node), parse_ctx->mem_pool_, T_SP_CLAUSE_LIST, (yyvsp[(1) - (1)].node));
    ;}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1513 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1515 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
    malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_LINK_NODE, 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
  ;}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1521 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.node) = (yyvsp[(1) - (1)].node);
      copy_node_abs_location((yyval.node)->stmt_loc_, (yylsp[(1) - (1)]));
    ;}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1526 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.node) = (yyvsp[(1) - (1)].node);
      copy_node_abs_location((yyval.node)->stmt_loc_, (yylsp[(1) - (1)]));
    ;}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1534 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.node) = (yyvsp[(1) - (1)].node);
      const char *stmt_str = parse_ctx->stmt_str_ + (yylsp[(1) - (1)]).first_column;
      int32_t str_len = (yylsp[(1) - (1)]).last_column - (yylsp[(1) - (1)]).first_column + 1;
      (yyvsp[(1) - (1)].node)->str_value_ = parse_strndup(stmt_str, str_len, parse_ctx->mem_pool_);
      check_ptr((yyvsp[(1) - (1)].node)->str_value_);
      (yyvsp[(1) - (1)].node)->str_len_ = str_len;
    ;}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1546 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.node) = (yyvsp[(1) - (1)].node);
      copy_node_abs_location((yyval.node)->stmt_loc_, (yylsp[(1) - (1)]));
    ;}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1551 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.node) = (yyvsp[(1) - (1)].node);
      copy_node_abs_location((yyval.node)->stmt_loc_, (yylsp[(1) - (1)]));
    ;}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1556 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.node) = (yyvsp[(1) - (1)].node);
      copy_node_abs_location((yyval.node)->stmt_loc_, (yylsp[(1) - (1)]));
    ;}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1561 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.node) = (yyvsp[(1) - (1)].node);
      copy_node_abs_location((yyval.node)->stmt_loc_, (yylsp[(1) - (1)]));
    ;}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1566 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.node) = (yyvsp[(1) - (1)].node);
      copy_node_abs_location((yyval.node)->stmt_loc_, (yylsp[(1) - (1)]));
    ;}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1571 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.node) = (yyvsp[(1) - (1)].node);
      copy_node_abs_location((yyval.node)->stmt_loc_, (yylsp[(1) - (1)]));
    ;}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1579 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.node) = (yyvsp[(1) - (1)].node);
    ;}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1583 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.node) = (yyvsp[(1) - (1)].node);
    ;}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1587 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.node) = (yyvsp[(1) - (1)].node);
    ;}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1591 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.node) = (yyvsp[(1) - (1)].node);
    ;}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1595 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.node) = (yyvsp[(1) - (1)].node);
    ;}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1599 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.node) = (yyvsp[(1) - (1)].node);
    ;}
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 1603 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.node) = (yyvsp[(1) - (1)].node);
    ;}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1609 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(2) - (4)].node); ;}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1614 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      if (NULL == (yyvsp[(1) - (4)].node)) {
        YYERROR;
      }
      ParseNode *proc_stmts = NULL;
      merge_nodes(proc_stmts, parse_ctx->mem_pool_, T_SP_PROC_STMT_LIST, (yyvsp[(3) - (4)].node));
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_IF, 3, (yyvsp[(1) - (4)].node), proc_stmts, (yyvsp[(4) - (4)].node));
    ;}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1623 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      if (NULL == (yyvsp[(1) - (3)].node)) {
        YYERROR;
      }
      ParseNode *proc_stmts = NULL;
      merge_nodes(proc_stmts, parse_ctx->mem_pool_, T_SP_PROC_STMT_LIST, (yyvsp[(3) - (3)].node));
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_IF, 3, (yyvsp[(1) - (3)].node), proc_stmts, NULL);
    ;}
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 1635 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      ParseNode *when_list = NULL;
      merge_nodes(when_list, parse_ctx->mem_pool_, T_WHEN_LIST, (yyvsp[(3) - (6)].node));
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_CASE, 3, (yyvsp[(2) - (6)].node), when_list, (yyvsp[(4) - (6)].node));
    ;}
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 1641 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      ParseNode *when_list = NULL;
      merge_nodes(when_list, parse_ctx->mem_pool_, T_WHEN_LIST, (yyvsp[(3) - (5)].node));
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_CASE, 3, (yyvsp[(2) - (5)].node), when_list, NULL);
    ;}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 1649 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 1651 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_LINK_NODE, 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
    ;}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 1658 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      ParseNode *proc_stmts = NULL;
      merge_nodes(proc_stmts, parse_ctx->mem_pool_, T_SP_PROC_STMT_LIST, (yyvsp[(4) - (4)].node));
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_WHEN, 2, (yyvsp[(2) - (4)].node), proc_stmts);
    ;}
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 1673 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      ParseNode *proc_stmts = NULL;
      merge_nodes(proc_stmts, parse_ctx->mem_pool_, T_SP_PROC_STMT_LIST, (yyvsp[(2) - (2)].node));
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_ELSE, 1, proc_stmts);
    ;}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 1679 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      ParseNode *proc_stmts = NULL;
      merge_nodes(proc_stmts, parse_ctx->mem_pool_, T_SP_PROC_STMT_LIST, (yyvsp[(2) - (2)].node));
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_ELSE, 1, proc_stmts);
    ;}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 1687 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 1692 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_BLOCK_CONTENT, 2, NULL, NULL);
    ;}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 1696 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      ParseNode *decl_list = NULL;
      merge_nodes(decl_list, parse_ctx->mem_pool_, T_SP_DECL_LIST, (yyvsp[(2) - (3)].node));
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_BLOCK_CONTENT, 2, decl_list, NULL);
    ;}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 1702 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      ParseNode *proc_stmts = NULL;
      merge_nodes(proc_stmts, parse_ctx->mem_pool_, T_SP_PROC_STMT_LIST, (yyvsp[(2) - (3)].node));
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_BLOCK_CONTENT, 2, NULL, proc_stmts);
    ;}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 1708 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      ParseNode *decl_list = NULL;
      ParseNode *proc_stmts = NULL;
      merge_nodes(decl_list, parse_ctx->mem_pool_, T_SP_DECL_LIST, (yyvsp[(2) - (4)].node));
      merge_nodes(proc_stmts, parse_ctx->mem_pool_, T_SP_PROC_STMT_LIST, (yyvsp[(3) - (4)].node));
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_BLOCK_CONTENT, 2, decl_list, proc_stmts);
    ;}
    break;

  case 297:

/* Line 1455 of yacc.c  */
#line 1719 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_LABELED_BLOCK, 3, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].node));
    ;}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 1725 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 1729 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL ;}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 1731 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.node) = (yyvsp[(1) - (1)].node);
    ;}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 1737 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 1739 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_LINK_NODE, 2, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node));
    ;}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 1746 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.node) = (yyvsp[(1) - (2)].node);
    ;}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 1750 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_LINK_NODE, 2, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node));
    ;}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 1757 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 1759 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_LINK_NODE, 2, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node));
    ;}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 1766 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      ParseNode *decl_idents = NULL;
      merge_nodes(decl_idents, parse_ctx->mem_pool_, T_SP_DECL_IDENT_LIST, (yyvsp[(2) - (4)].node));
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_DECL, 3, decl_idents, (yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].node));
      copy_node_abs_location((yyval.node)->stmt_loc_, (yylsp[(1) - (4)]));
    ;}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 1773 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_DECL_COND, 2, (yyvsp[(2) - (5)].node), (yyvsp[(5) - (5)].node));
      copy_node_abs_location((yyval.node)->stmt_loc_, (yylsp[(1) - (5)]));
    ;}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 1778 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      ParseNode *hcond_list = NULL;
      ParseNode *proc_stmts = NULL;
      malloc_non_terminal_node(proc_stmts, parse_ctx->mem_pool_, T_SP_PROC_STMT_LIST, 1, (yyvsp[(6) - (6)].node));
      merge_nodes(hcond_list, parse_ctx->mem_pool_, T_SP_HCOND_LIST, (yyvsp[(5) - (6)].node));
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_DECL_HANDLER, 2, hcond_list, proc_stmts);
      (yyval.node)->value_ = (yyvsp[(2) - (6)].ival);
      copy_node_abs_location((yyval.node)->stmt_loc_, (yylsp[(1) - (6)]));
    ;}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 1788 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      if ((yyvsp[(5) - (5)].node)->children_[0]->type_ != T_SELECT) {
        obpl_mysql_yyerror(&(yylsp[(5) - (5)]), parse_ctx, "Syntax Error\n");
        YYERROR;
      }
      const char *stmt_str = parse_ctx->stmt_str_ + (yylsp[(5) - (5)]).first_column;
      int32_t str_len = (yylsp[(5) - (5)]).last_column - (yylsp[(5) - (5)]).first_column + 1;
      (yyvsp[(5) - (5)].node)->str_value_ = parse_strndup(stmt_str, str_len, parse_ctx->mem_pool_);
      check_ptr((yyvsp[(5) - (5)].node)->str_value_);
      (yyvsp[(5) - (5)].node)->str_len_ = str_len;
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_DECL_CURSOR, 4, (yyvsp[(2) - (5)].node), NULL, NULL, (yyvsp[(5) - (5)].node)); // keep four-argument cursor layout
      copy_node_abs_location((yyval.node)->stmt_loc_, (yylsp[(1) - (5)]));
    ;}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 1804 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = SP_HANDLER_TYPE_EXIT; ;}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 1805 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = SP_HANDLER_TYPE_CONTINUE; ;}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 1809 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 1811 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_LINK_NODE, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 315:

/* Line 1455 of yacc.c  */
#line 1817 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 316:

/* Line 1455 of yacc.c  */
#line 1818 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 317:

/* Line 1455 of yacc.c  */
#line 1819 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SQL_WARNING); ;}
    break;

  case 318:

/* Line 1455 of yacc.c  */
#line 1820 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SQL_NOT_FOUND); ;}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 1821 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SQL_EXCEPTION); ;}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 1826 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_CONDITION, 1, (yyvsp[(1) - (1)].node));
    ;}
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 1830 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_CONDITION, 1, (yyvsp[(1) - (1)].node));
    ;}
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 1837 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (void)((yyvsp[(2) - (3)].node));
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SQL_STATE, 1, (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 1845 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_PROC_OPEN, 3, (yyvsp[(2) - (2)].node), NULL, NULL, NULL); // keep cursor open placeholders
    ;}
    break;

  case 324:

/* Line 1455 of yacc.c  */
#line 1852 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_PROC_CLOSE, 1, (yyvsp[(2) - (2)].node));
    ;}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 1859 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_PROC_FETCH, 2, (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 1863 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_PROC_FETCH, 2, (yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].node));
    ;}
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 1867 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_PROC_FETCH, 2, (yyvsp[(4) - (5)].node), (yyvsp[(5) - (5)].node));
    ;}
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 1874 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      ParseNode *vars_list = NULL;
      merge_nodes(vars_list, parse_ctx->mem_pool_, T_SP_INTO_LIST, (yyvsp[(2) - (2)].node));
      if (vars_list == NULL) {
        obpl_mysql_parse_fatal_error(OB_PARSER_ERR_PARSE_SQL, YYLEX_PARAM, "Syntax Error");
      } else {
        // The MySQL PL `FETCH INTO @user_var` syntax is not supported. Check if there is a
        // T_SELECT in the `var_list`, which is transformed from `@user_var` in the `expr` rule.
        for (int i = 0; i < vars_list->num_child_; ++i) {
          ParseNode *child = vars_list->children_[i];
          if (NULL != child && T_SELECT == child->type_) {
            obpl_mysql_parse_fatal_error(OB_PARSER_ERR_PARSE_SQL, YYLEX_PARAM, "Syntax Error");
          }
        }
      }
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_INTO_VARIABLES, 1, vars_list);
    ;}
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 1894 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 1895 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 1898 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 1900 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_LINK_NODE, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 1906 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 1910 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 1912 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      if (NULL == (yyvsp[(2) - (2)].node)) {
        YYERROR;
      }
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_DECL_DEFAULT, 1, (yyvsp[(2) - (2)].node));
    ;}
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 1921 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 1923 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      if (NULL == (yyvsp[(2) - (2)].node)) {
        YYERROR;
      }
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_DECL_DEFAULT, 1, (yyvsp[(2) - (2)].node));
      // 拷贝EXPR语句
      const char *expr_str = parse_ctx->stmt_str_ + (yylsp[(2) - (2)]).first_column;
      int32_t expr_str_len = (yylsp[(2) - (2)]).last_column - (yylsp[(2) - (2)]).first_column + 1;
      (yyval.node)->str_value_ = parse_strndup(expr_str, expr_str_len, parse_ctx->mem_pool_);
      check_ptr((yyval.node)->str_value_);
      (yyval.node)->str_len_ = expr_str_len;
      if (NULL != (yyvsp[(2) - (2)].node)) {
        copy_node_abs_location((yyvsp[(2) - (2)].node)->stmt_loc_, (yylsp[(2) - (2)]));
      }
    ;}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 1941 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      do_parse_sql_expr_rule((yyval.node), parse_ctx, 3, ',', ')', ';');
    ;}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 1947 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 1949 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_LINK_NODE, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 1955 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      //same as expr in sql rule, and terminate when read ';'
      do_parse_sql_expr_rule((yyval.node), parse_ctx, 9, INTO, USING, WHEN, THEN, ';', DO, LIMIT, ',', END_KEY);
      obpl_mysql_wrap_get_user_var_into_subquery(parse_ctx, (yyval.node));
    ;}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 1964 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      ParseNode *proc_stmts = NULL;
      merge_nodes(proc_stmts, parse_ctx->mem_pool_, T_SP_PROC_STMT_LIST, (yyvsp[(2) - (4)].node));
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_LOOP, 1, proc_stmts);
    ;}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 1970 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      ParseNode *proc_stmts = NULL;
      merge_nodes(proc_stmts, parse_ctx->mem_pool_, T_SP_PROC_STMT_LIST, (yyvsp[(4) - (6)].node));
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_WHILE, 2, (yyvsp[(2) - (6)].node), proc_stmts);
    ;}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 1976 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      ParseNode *proc_stmts = NULL;
      merge_nodes(proc_stmts, parse_ctx->mem_pool_, T_SP_PROC_STMT_LIST, (yyvsp[(2) - (6)].node));
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_REPEAT, 2, proc_stmts, (yyvsp[(4) - (6)].node));
    ;}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 1985 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_LABELED_CONTROL, 3, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].node));
    ;}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 1992 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      if (NULL == (yyvsp[(2) - (2)].node)) YYERROR;
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_RETURN, 1, (yyvsp[(2) - (2)].node));
    ;}
    break;

  case 347:

/* Line 1455 of yacc.c  */
#line 2000 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_ITERATE, 2, (yyvsp[(2) - (2)].node), NULL);
    ;}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 2007 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_LEAVE, 2, (yyvsp[(2) - (2)].node), NULL);
    ;}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 2014 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_DROP, 1, (yyvsp[(4) - (4)].node));
      (yyval.node)->value_ = (yyvsp[(3) - (4)].ival);
    ;}
    break;

  case 350:

/* Line 1455 of yacc.c  */
#line 2022 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SF_DROP, 1, (yyvsp[(4) - (4)].node));
      (yyval.node)->value_ = (yyvsp[(3) - (4)].ival);
    ;}
    break;

  case 351:

/* Line 1455 of yacc.c  */
#line 2029 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = 0; ;}
    break;

  case 352:

/* Line 1455 of yacc.c  */
#line 2030 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = 1; ;}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 2034 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = 0; ;}
    break;

  case 354:

/* Line 1455 of yacc.c  */
#line 2035 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = 1; ;}
    break;

  case 355:

/* Line 1455 of yacc.c  */
#line 2039 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 356:

/* Line 1455 of yacc.c  */
#line 2040 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 357:

/* Line 1455 of yacc.c  */
#line 2045 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, (yyvsp[(1) - (2)].ival));
      (yyval.node)->int16_values_[0] = (yyvsp[(2) - (2)].ival);
      (yyval.node)->int16_values_[2] = 0;   /* 2 is the same index as float or number. */
    ;}
    break;

  case 358:

/* Line 1455 of yacc.c  */
#line 2051 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, (yyvsp[(1) - (3)].ival) + (T_UTINYINT - T_TINYINT));
      (yyval.node)->int16_values_[0] = (yyvsp[(2) - (3)].ival);
      (yyval.node)->int16_values_[2] = 1;   /* 2 is the same index as float or number. */
    ;}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 2057 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, (yyvsp[(1) - (3)].ival));
      (yyval.node)->int16_values_[0] = (yyvsp[(2) - (3)].ival);
      (yyval.node)->int16_values_[2] = 0;   /* 2 is the same index as float or number. */
    ;}
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 2063 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, (yyvsp[(1) - (4)].ival) + (T_UTINYINT - T_TINYINT));
      (yyval.node)->int16_values_[0] = (yyvsp[(2) - (4)].ival);
      (yyval.node)->int16_values_[2] = 1;   /* 2 is the same index as float or number. */
    ;}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 2069 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, (yyvsp[(1) - (3)].ival) + (T_UTINYINT - T_TINYINT));
      (yyval.node)->int16_values_[0] = (yyvsp[(2) - (3)].ival);
      (yyval.node)->int16_values_[2] = 0;   /* 2 is the same index as float or number. */
    ;}
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 2075 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, (yyvsp[(1) - (4)].ival) + (T_UTINYINT - T_TINYINT));
      (yyval.node)->int16_values_[0] = (yyvsp[(2) - (4)].ival);
      (yyval.node)->int16_values_[2] = 1;   /* 2 is the same index as float or number. */
    ;}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 2081 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      if (T_FLOAT != (yyvsp[(1) - (2)].ival) && NULL != (yyvsp[(2) - (2)].node) && -1 == (yyvsp[(2) - (2)].node)->int16_values_[1]) {
        obpl_mysql_yyerror(&(yylsp[(2) - (2)]), parse_ctx, "double type not support double(M) syntax\n");
        YYERROR;
      }
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, (yyvsp[(1) - (2)].ival));
      if (NULL != (yyvsp[(2) - (2)].node)) {
        (yyval.node)->int16_values_[0] = (yyvsp[(2) - (2)].node)->int16_values_[0];
        (yyval.node)->int16_values_[1] = (yyvsp[(2) - (2)].node)->int16_values_[1];
      }
      /* malloc_terminal_node() has set memory to 0 filled, so there is no else. */
      (yyval.node)->int16_values_[2] = 0;
    ;}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 2095 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      if (T_FLOAT != (yyvsp[(1) - (3)].ival) && NULL != (yyvsp[(2) - (3)].node) && -1 == (yyvsp[(2) - (3)].node)->int16_values_[1]) {
        obpl_mysql_yyerror(&(yylsp[(2) - (3)]), parse_ctx, "double type not support double(M) syntax\n");
        YYERROR;
      }
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, (yyvsp[(1) - (3)].ival) + (T_UFLOAT - T_FLOAT));
      if (NULL != (yyvsp[(2) - (3)].node)) {
        (yyval.node)->int16_values_[0] = (yyvsp[(2) - (3)].node)->int16_values_[0];
        (yyval.node)->int16_values_[1] = (yyvsp[(2) - (3)].node)->int16_values_[1];
      }
      /* malloc_terminal_node() has set memory to 0 filled, so there is no else. */
      (yyval.node)->int16_values_[2] = 1;
    ;}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 2109 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      if (T_FLOAT != (yyvsp[(1) - (3)].ival) && NULL != (yyvsp[(2) - (3)].node) && -1 == (yyvsp[(2) - (3)].node)->int16_values_[1]) {
        obpl_mysql_yyerror(&(yylsp[(2) - (3)]), parse_ctx, "double type not support double(M) syntax\n");
        YYERROR;
      }
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, (yyvsp[(1) - (3)].ival));
      if (NULL != (yyvsp[(2) - (3)].node)) {
        (yyval.node)->int16_values_[0] = (yyvsp[(2) - (3)].node)->int16_values_[0];
        (yyval.node)->int16_values_[1] = (yyvsp[(2) - (3)].node)->int16_values_[1];
      }
      /* malloc_terminal_node() has set memory to 0 filled, so there is no else. */
      (yyval.node)->int16_values_[2] = 0;
    ;}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 2123 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      if (T_FLOAT != (yyvsp[(1) - (4)].ival) && NULL != (yyvsp[(2) - (4)].node) && -1 == (yyvsp[(2) - (4)].node)->int16_values_[1]) {
        obpl_mysql_yyerror(&(yylsp[(2) - (4)]), parse_ctx, "double type not support double(M) syntax\n");
        YYERROR;
      }
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, (yyvsp[(1) - (4)].ival) + (T_UFLOAT - T_FLOAT));
      if (NULL != (yyvsp[(2) - (4)].node)) {
        (yyval.node)->int16_values_[0] = (yyvsp[(2) - (4)].node)->int16_values_[0];
        (yyval.node)->int16_values_[1] = (yyvsp[(2) - (4)].node)->int16_values_[1];
      }
      /* malloc_terminal_node() has set memory to 0 filled, so there is no else. */
      (yyval.node)->int16_values_[2] = 1;
    ;}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 2137 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      if (T_FLOAT != (yyvsp[(1) - (3)].ival) && NULL != (yyvsp[(2) - (3)].node) && -1 == (yyvsp[(2) - (3)].node)->int16_values_[1]) {
        obpl_mysql_yyerror(&(yylsp[(2) - (3)]), parse_ctx, "double type not support double(M) syntax\n");
        YYERROR;
      }
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, (yyvsp[(1) - (3)].ival) + (T_UFLOAT - T_FLOAT));
      if (NULL != (yyvsp[(2) - (3)].node)) {
        (yyval.node)->int16_values_[0] = (yyvsp[(2) - (3)].node)->int16_values_[0];
        (yyval.node)->int16_values_[1] = (yyvsp[(2) - (3)].node)->int16_values_[1];
      }
      /* malloc_terminal_node() has set memory to 0 filled, so there is no else. */
      (yyval.node)->int16_values_[2] = 0;
    ;}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 2151 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      if (T_FLOAT != (yyvsp[(1) - (4)].ival) && NULL != (yyvsp[(2) - (4)].node) && -1 == (yyvsp[(2) - (4)].node)->int16_values_[1]) {
        obpl_mysql_yyerror(&(yylsp[(2) - (4)]), parse_ctx, "double type not support double(M) syntax\n");
        YYERROR;
      }
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, (yyvsp[(1) - (4)].ival) + (T_UFLOAT - T_FLOAT));
      if (NULL != (yyvsp[(2) - (4)].node)) {
        (yyval.node)->int16_values_[0] = (yyvsp[(2) - (4)].node)->int16_values_[0];
        (yyval.node)->int16_values_[1] = (yyvsp[(2) - (4)].node)->int16_values_[1];
      }
      /* malloc_terminal_node() has set memory to 0 filled, so there is no else. */
      (yyval.node)->int16_values_[2] = 1;
    ;}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 2165 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (void)((yyvsp[(1) - (2)].node));
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_NUMBER);
      if (NULL != (yyvsp[(2) - (2)].node)) {
        (yyval.node)->int16_values_[0] = (yyvsp[(2) - (2)].node)->int16_values_[0];
        (yyval.node)->int16_values_[1] = (yyvsp[(2) - (2)].node)->int16_values_[1];
      }
      /* malloc_terminal_node() has set memory to 0 filled, so there is no else. */
      (yyval.node)->int16_values_[2] = 0;
    ;}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 2176 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (void)((yyvsp[(1) - (3)].node));
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_UNUMBER);
      if (NULL != (yyvsp[(2) - (3)].node)) {
        (yyval.node)->int16_values_[0] = (yyvsp[(2) - (3)].node)->int16_values_[0];
        (yyval.node)->int16_values_[1] = (yyvsp[(2) - (3)].node)->int16_values_[1];
      }
      /* malloc_terminal_node() has set memory to 0 filled, so there is no else. */
      (yyval.node)->int16_values_[2] = 1;
    ;}
    break;

  case 371:

/* Line 1455 of yacc.c  */
#line 2187 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (void)((yyvsp[(1) - (3)].node));
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_NUMBER);
      if (NULL != (yyvsp[(2) - (3)].node)) {
        (yyval.node)->int16_values_[0] = (yyvsp[(2) - (3)].node)->int16_values_[0];
        (yyval.node)->int16_values_[1] = (yyvsp[(2) - (3)].node)->int16_values_[1];
      }
      /* malloc_terminal_node() has set memory to 0 filled, so there is no else. */
      (yyval.node)->int16_values_[2] = 0;
    ;}
    break;

  case 372:

/* Line 1455 of yacc.c  */
#line 2198 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (void)((yyvsp[(1) - (4)].node));
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_UNUMBER);
      if (NULL != (yyvsp[(2) - (4)].node)) {
        (yyval.node)->int16_values_[0] = (yyvsp[(2) - (4)].node)->int16_values_[0];
        (yyval.node)->int16_values_[1] = (yyvsp[(2) - (4)].node)->int16_values_[1];
      }
      /* malloc_terminal_node() has set memory to 0 filled, so there is no else. */
      (yyval.node)->int16_values_[2] = 1;
    ;}
    break;

  case 373:

/* Line 1455 of yacc.c  */
#line 2209 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (void)((yyvsp[(1) - (3)].node));
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_UNUMBER);
      if (NULL != (yyvsp[(2) - (3)].node)) {
        (yyval.node)->int16_values_[0] = (yyvsp[(2) - (3)].node)->int16_values_[0];
        (yyval.node)->int16_values_[1] = (yyvsp[(2) - (3)].node)->int16_values_[1];
      }
      /* malloc_terminal_node() has set memory to 0 filled, so there is no else. */
      (yyval.node)->int16_values_[2] = 0;
    ;}
    break;

  case 374:

/* Line 1455 of yacc.c  */
#line 2220 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (void)((yyvsp[(1) - (4)].node));
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_UNUMBER);
      if (NULL != (yyvsp[(2) - (4)].node)) {
        (yyval.node)->int16_values_[0] = (yyvsp[(2) - (4)].node)->int16_values_[0];
        (yyval.node)->int16_values_[1] = (yyvsp[(2) - (4)].node)->int16_values_[1];
      }
      /* malloc_terminal_node() has set memory to 0 filled, so there is no else. */
      (yyval.node)->int16_values_[2] = 1;
    ;}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 2231 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, (yyvsp[(1) - (2)].ival));
      (yyval.node)->int16_values_[1] = (yyvsp[(2) - (2)].ival);
    ;}
    break;

  case 376:

/* Line 1455 of yacc.c  */
#line 2236 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, (yyvsp[(1) - (1)].ival));
    ;}
    break;

  case 377:

/* Line 1455 of yacc.c  */
#line 2240 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_CHAR, 3, (yyvsp[(4) - (5)].node), (yyvsp[(5) - (5)].node), (yyvsp[(3) - (5)].node));
      if ((yyvsp[(2) - (5)].ival) < 0) {
        (yyvsp[(2) - (5)].ival) = 1;
      }
      (yyval.node)->int32_values_[0] = (yyvsp[(2) - (5)].ival);
      (yyval.node)->int32_values_[1] = 0; /* is char */
    ;}
    break;

  case 378:

/* Line 1455 of yacc.c  */
#line 2249 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      ParseNode *charset_node = NULL;
      malloc_terminal_node(charset_node, parse_ctx->mem_pool_, T_CHARSET);
      charset_node->str_value_ = parse_strdup("utf8mb4", parse_ctx->mem_pool_, &(charset_node->str_len_));
      if (OB_UNLIKELY(NULL == charset_node->str_value_)) {
        obpl_mysql_yyerror(NULL, parse_ctx, "memory space for string is not enough\n");
        YYERROR;
      }

      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, (yyvsp[(1) - (4)].ival), 3, charset_node, (yyvsp[(4) - (4)].node), (yyvsp[(3) - (4)].node));
      (yyval.node)->int32_values_[0] = (yyvsp[(2) - (4)].ival);
      (yyval.node)->int32_values_[1] = 0; /* is char */
    ;}
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 2270 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_VARCHAR, 3, (yyvsp[(5) - (6)].node), (yyvsp[(6) - (6)].node), (yyvsp[(4) - (6)].node));
      (yyval.node)->int32_values_[0] = (yyvsp[(3) - (6)].ival);
      (yyval.node)->int32_values_[1] = 0; /* is char */
    ;}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 2276 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_VARCHAR, 3, (yyvsp[(4) - (5)].node), (yyvsp[(5) - (5)].node), (yyvsp[(3) - (5)].node));
      (yyval.node)->int32_values_[0] = (yyvsp[(2) - (5)].ival);
      (yyval.node)->int32_values_[1] = 0; /* is char */
    ;}
    break;

  case 381:

/* Line 1455 of yacc.c  */
#line 2282 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      ParseNode *charset_node = NULL;
      malloc_terminal_node(charset_node, parse_ctx->mem_pool_, T_CHARSET);
      charset_node->str_value_ = parse_strdup("utf8mb4", parse_ctx->mem_pool_, &(charset_node->str_len_));
      if (OB_UNLIKELY(NULL == charset_node->str_value_)) {
        obpl_mysql_yyerror(NULL, parse_ctx, "memory space for string is not enough\n");
        YYERROR;
      }

      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, (yyvsp[(1) - (4)].ival), 3, charset_node, (yyvsp[(4) - (4)].node), (yyvsp[(3) - (4)].node));
      (yyval.node)->int32_values_[0] = (yyvsp[(2) - (4)].ival);
      (yyval.node)->int32_values_[1] = 0; /* is char */
    ;}
    break;

  case 382:

/* Line 1455 of yacc.c  */
#line 2296 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_CHAR);
      if ((yyvsp[(2) - (2)].ival) < 0) {
        (yyvsp[(2) - (2)].ival) = 1;
      }
      (yyval.node)->int32_values_[0] = (yyvsp[(2) - (2)].ival);
      (yyval.node)->int32_values_[1] = 1; /* is binary */
    ;}
    break;

  case 383:

/* Line 1455 of yacc.c  */
#line 2305 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_VARCHAR);
      (yyval.node)->int32_values_[0] = (yyvsp[(2) - (2)].ival);
      (yyval.node)->int32_values_[1] = 1; /* is binary */
    ;}
    break;

  case 384:

/* Line 1455 of yacc.c  */
#line 2311 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_INVALID);
      (yyval.node)->str_value_ = (yyvsp[(1) - (1)].node)->str_value_;
      (yyval.node)->str_len_ = (yyvsp[(1) - (1)].node)->str_len_;
    ;}
    break;

  case 385:

/* Line 1455 of yacc.c  */
#line 2317 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_BIT);
      (yyval.node)->int16_values_[0] = (yyvsp[(2) - (2)].ival);
    ;}
    break;

  case 386:

/* Line 1455 of yacc.c  */
#line 2322 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_TINYINT);
  	  (yyval.node)->int16_values_[0] = 1;
      (yyval.node)->int16_values_[2] = 0;  // zerofill always false
    ;}
    break;

  case 387:

/* Line 1455 of yacc.c  */
#line 2328 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_TINYINT);
      (yyval.node)->int16_values_[0] = 1;
      (yyval.node)->int16_values_[2] = 0; // zerofill always false
    ;}
    break;

  case 388:

/* Line 1455 of yacc.c  */
#line 2334 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, (yyvsp[(1) - (2)].ival));
      if ((yyvsp[(1) - (2)].ival) != T_TEXT && (yyvsp[(2) - (2)].ival) != 0) {
        obpl_mysql_yyerror(&(yylsp[(2) - (2)]), parse_ctx, "not support to specify the length in parentheses\n");
        YYERROR;
      }
      (yyval.node)->int32_values_[0] = (yyvsp[(2) - (2)].ival);
      (yyval.node)->int32_values_[1] = 1; /* is binary */
    ;}
    break;

  case 389:

/* Line 1455 of yacc.c  */
#line 2344 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, (yyvsp[(1) - (5)].ival), 3, (yyvsp[(4) - (5)].node), (yyvsp[(5) - (5)].node), (yyvsp[(3) - (5)].node));
      if ((yyvsp[(1) - (5)].ival) != T_TEXT && (yyvsp[(2) - (5)].ival) != 0) {
        obpl_mysql_yyerror(&(yylsp[(2) - (5)]), parse_ctx, "not support to specify the length in parentheses\n");
        YYERROR;
      }
      (yyval.node)->int32_values_[0] = (yyvsp[(2) - (5)].ival);
      (yyval.node)->int32_values_[1] = 0; /* is text */
    ;}
    break;

  case 390:

/* Line 1455 of yacc.c  */
#line 2354 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
    ParseNode *string_list_node = NULL;
    merge_nodes(string_list_node, parse_ctx->mem_pool_, T_STRING_LIST, (yyvsp[(3) - (7)].node));
    malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_ENUM, 4, (yyvsp[(6) - (7)].node), (yyvsp[(7) - (7)].node), (yyvsp[(5) - (7)].node), string_list_node);
    (yyval.node)->int32_values_[0] = 0;//not used so far
    (yyval.node)->int32_values_[1] = 0; /* is char */
  ;}
    break;

  case 391:

/* Line 1455 of yacc.c  */
#line 2362 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
    ParseNode *string_list_node = NULL;
    merge_nodes(string_list_node, parse_ctx->mem_pool_, T_STRING_LIST, (yyvsp[(3) - (7)].node));
    malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SET, 4, (yyvsp[(6) - (7)].node), (yyvsp[(7) - (7)].node), (yyvsp[(5) - (7)].node), string_list_node);
    (yyval.node)->int32_values_[0] = 0;//not used so far
    (yyval.node)->int32_values_[1] = 0; /* is char */
  ;}
    break;

  case 392:

/* Line 1455 of yacc.c  */
#line 2370 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
    malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_JSON);
    (yyval.node)->int32_values_[0] = 0;
  ;}
    break;

  case 393:

/* Line 1455 of yacc.c  */
#line 2375 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
    malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_GEOMETRY);
    (yyval.node)->int32_values_[0] = 0; /* length */
    (yyval.node)->int32_values_[1] = 0; /* geometry, geometry uses collation type value convey sub geometry type. */
  ;}
    break;

  case 394:

/* Line 1455 of yacc.c  */
#line 2381 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
    malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_GEOMETRY);
    (yyval.node)->int32_values_[0] = 0; /* length */
    (yyval.node)->int32_values_[1] = 1; /* point, geometry uses collation type value convey sub geometry type. */
  ;}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 2387 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
    malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_GEOMETRY);
    (yyval.node)->int32_values_[0] = 0; /* length */
    (yyval.node)->int32_values_[1] = 2; /* linestring, geometry uses collation type value convey sub geometry type. */
  ;}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 2393 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
    malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_GEOMETRY);
    (yyval.node)->int32_values_[0] = 0; /* length */
    (yyval.node)->int32_values_[1] = 3; /* polygon, geometry uses collation type value convey sub geometry type. */
  ;}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 2399 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
    malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_GEOMETRY);
    (yyval.node)->int32_values_[0] = 0; /* length */
    (yyval.node)->int32_values_[1] = 4; /* mutipoint, geometry uses collation type value convey sub geometry type. */
  ;}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 2405 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
    malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_GEOMETRY);
    (yyval.node)->int32_values_[0] = 0; /* length */
    (yyval.node)->int32_values_[1] = 5; /* multilinestring, geometry uses collation type value convey sub geometry type. */
  ;}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 2411 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
    malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_GEOMETRY);
    (yyval.node)->int32_values_[0] = 0; /* length */
    (yyval.node)->int32_values_[1] = 6; /* multipolygon, geometry uses collation type value convey sub geometry type. */
  ;}
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 2417 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
    UNUSED((yyvsp[(1) - (1)].node));
    malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_GEOMETRY);
    (yyval.node)->int32_values_[0] = 0; /* length */
    (yyval.node)->int32_values_[1] = 7; /* geometrycollection, geometry uses collation type value convey sub geometry type. */
  ;}
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 2424 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_UINT64);
      (yyval.node)->int16_values_[0] = -1;  // precision, default value -1
      (yyval.node)->int16_values_[2] = 0;   // zerofill always false for serial type
    ;}
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 2430 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
    if (parse_ctx->is_for_trigger_ && parse_ctx->is_inner_parse_) {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_ROWTYPE, 2, (yyvsp[(1) - (3)].node), NULL);
    } else {
      obpl_mysql_yyerror(&(yylsp[(3) - (3)]), parse_ctx, "Syntax Error\n");
      YYERROR;
    }
  ;}
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 2442 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_OBJ_ACCESS_REF, 2, (yyvsp[(1) - (1)].node), NULL);
    ;}
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 2447 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = T_TINYINT; ;}
    break;

  case 405:

/* Line 1455 of yacc.c  */
#line 2448 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = T_SMALLINT; ;}
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 2449 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = T_MEDIUMINT; ;}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 2450 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = T_INT32; ;}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 2451 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = T_INT; ;}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 2455 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = T_FLOAT; ;}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 2456 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = T_DOUBLE; ;}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 2457 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = T_DOUBLE; ;}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 2461 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = T_DATETIME; ;}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 2462 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = T_TIMESTAMP; ;}
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 2463 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = T_TIME; ;}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 2467 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 2468 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 2469 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 2470 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 419:

/* Line 1455 of yacc.c  */
#line 2473 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = T_DATE; ;}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 2474 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = T_YEAR; ;}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 2478 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = T_CHAR; ;}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 2479 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = T_CHAR; ;}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 2483 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = T_VARCHAR; ;}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 2484 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = T_VARCHAR; ;}
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 2485 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = T_VARCHAR; ;}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 2486 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = T_VARCHAR; ;}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 2490 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = (yyvsp[(2) - (3)].node)->value_; ;}
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 2491 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = -1; ;}
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 2495 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = (yyvsp[(2) - (3)].node)->value_; ;}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 2496 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = 1; ;}
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 2501 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_LINK_NODE);
      (yyval.node)->int16_values_[0] = (yyvsp[(2) - (5)].node)->value_;
      (yyval.node)->int16_values_[1] = (yyvsp[(4) - (5)].node)->value_;
    ;}
    break;

  case 432:

/* Line 1455 of yacc.c  */
#line 2507 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_LINK_NODE);
      (yyval.node)->int16_values_[0] = (yyvsp[(2) - (3)].node)->value_;
      (yyval.node)->int16_values_[1] = -1;
    ;}
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 2513 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
    malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_LINK_NODE);
    int err_no = 0;
    (yyvsp[(2) - (3)].node)->value_ = ob_strntoll((yyvsp[(2) - (3)].node)->str_value_, (yyvsp[(2) - (3)].node)->str_len_, 10, NULL, &err_no);
    (yyval.node)->int16_values_[0] = (yyvsp[(2) - (3)].node)->value_;
    (yyval.node)->int16_values_[1] = -1;
  ;}
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 2520 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 435:

/* Line 1455 of yacc.c  */
#line 2525 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_LINK_NODE);
      if((yyvsp[(2) - (5)].node)->value_ > OB_MAX_PARSER_INT16_VALUE) {
        (yyval.node)->int16_values_[0] = OB_MAX_PARSER_INT16_VALUE;
      } else {
        (yyval.node)->int16_values_[0] = (yyvsp[(2) - (5)].node)->value_;
      }
      if((yyvsp[(4) - (5)].node)->value_ > OB_MAX_PARSER_INT16_VALUE) {
        (yyval.node)->int16_values_[1] = OB_MAX_PARSER_INT16_VALUE;
      } else {
        (yyval.node)->int16_values_[1] = (yyvsp[(4) - (5)].node)->value_;
      }
      (yyval.node)->param_num_ = 2;
    ;}
    break;

  case 436:

/* Line 1455 of yacc.c  */
#line 2540 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_LINK_NODE);
      if((yyvsp[(2) - (3)].node)->value_ > OB_MAX_PARSER_INT16_VALUE) {
        (yyval.node)->int16_values_[0] = OB_MAX_PARSER_INT16_VALUE;
      } else {
        (yyval.node)->int16_values_[0] = (yyvsp[(2) - (3)].node)->value_;
      }
      (yyval.node)->int16_values_[1] = 0;
      (yyval.node)->param_num_ = 1;
    ;}
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 2551 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_LINK_NODE);
      (yyval.node)->int16_values_[0] = 10;
      (yyval.node)->int16_values_[1] = 0;
      (yyval.node)->param_num_ = 0;
    ;}
    break;

  case 438:

/* Line 1455 of yacc.c  */
#line 2560 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = (yyvsp[(2) - (3)].node)->value_; ;}
    break;

  case 439:

/* Line 1455 of yacc.c  */
#line 2561 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = 0; ;}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 2566 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.ival) = (yyvsp[(2) - (3)].node)->value_;
    ;}
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 2570 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.ival) = 0;
    ;}
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 2577 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.node) = (yyvsp[(1) - (1)].node);
      (yyval.node)->param_num_ = 1;
    ;}
    break;

  case 443:

/* Line 1455 of yacc.c  */
#line 2582 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.node) = (yyvsp[(1) - (1)].node);
      (yyval.node)->param_num_ = 1;
    ;}
    break;

  case 444:

/* Line 1455 of yacc.c  */
#line 2589 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 445:

/* Line 1455 of yacc.c  */
#line 2590 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 446:

/* Line 1455 of yacc.c  */
#line 2591 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 447:

/* Line 1455 of yacc.c  */
#line 2592 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 448:

/* Line 1455 of yacc.c  */
#line 2596 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = T_TINYTEXT; ;}
    break;

  case 449:

/* Line 1455 of yacc.c  */
#line 2597 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = T_TEXT; ;}
    break;

  case 450:

/* Line 1455 of yacc.c  */
#line 2598 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = T_MEDIUMTEXT; ;}
    break;

  case 451:

/* Line 1455 of yacc.c  */
#line 2599 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = T_LONGTEXT;  ;}
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 2600 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = T_MEDIUMTEXT; ;}
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 2601 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = T_MEDIUMTEXT; ;}
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 2605 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = T_TINYTEXT; ;}
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 2606 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = T_TEXT; ;}
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 2607 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = T_MEDIUMTEXT; ;}
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 2608 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = T_LONGTEXT;  ;}
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 2609 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {(yyval.ival) = T_MEDIUMTEXT; ;}
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 2613 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = (yyvsp[(1) - (1)].ival); ;}
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 2614 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = 0; ;}
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 2618 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
  // 在 `*` 处报语法错误
  // select cast('' as BINARY(-1));
  //                          *
  // select cast('' as CHARACTER(-1));
  //                             *
  int64_t val = 0;
  if (T_NUMBER == (yyvsp[(2) - (3)].node)->type_) {
    errno = 0;
    val = strtoll((yyvsp[(2) - (3)].node)->str_value_, NULL, 10);
    if (ERANGE == errno) {
      (yyval.ival) = OUT_OF_STR_LEN;// out of str_max_len
    } else if (val < 0) {
      obpl_mysql_yyerror(&(yylsp[(2) - (3)]), parse_ctx, "length cannot < 0\n");
      YYERROR;
    } else if (val > UINT32_MAX) {
      (yyval.ival) = OUT_OF_STR_LEN;// out of str_max_len
    } else if (val > INT32_MAX) {
      (yyval.ival) = DEFAULT_STR_LENGTH;
    } else {
      (yyval.ival) = val;
    }
  } else if ((yyvsp[(2) - (3)].node)->value_ < 0) {
    obpl_mysql_yyerror(&(yylsp[(2) - (3)]), parse_ctx, "length cannot < 0\n");
    YYERROR;
  } else if ((yyvsp[(2) - (3)].node)->value_ > UINT32_MAX) {
    (yyval.ival) = OUT_OF_STR_LEN;;
  } else if ((yyvsp[(2) - (3)].node)->value_ > INT32_MAX) {
    (yyval.ival) = DEFAULT_STR_LENGTH;
  } else {
    (yyval.ival) = (yyvsp[(2) - (3)].node)->value_;
  }
  // $$ = $2->param_num_;
;}
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 2656 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
   (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 2660 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
    malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_LINK_NODE, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
  ;}
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 2667 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 2671 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
    (yyval.node) = (yyvsp[(1) - (1)].node);
  ;}
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 2678 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.ival) = (yyvsp[(1) - (1)].ival);
    ;}
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 2682 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.ival) = 1;
    ;}
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 2689 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_BINARY);
      (yyval.node)->value_ = 1;
    ;}
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 2693 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {(yyval.node) = 0; ;}
    break;

  case 470:

/* Line 1455 of yacc.c  */
#line 2698 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.node) = (yyvsp[(1) - (1)].node);
      (yyval.node)->type_ = T_VARCHAR;
      (yyval.node)->param_num_ = 0;
    ;}
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 2704 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.node) = (yyvsp[(1) - (1)].node);
      (yyval.node)->param_num_ = 1;
    ;}
    break;

  case 472:

/* Line 1455 of yacc.c  */
#line 2712 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.node) = (yyvsp[(1) - (1)].node);
      (yyval.node)->type_ = T_VARCHAR;
      (yyval.node)->param_num_ = 0;
      (yyval.node)->is_hidden_const_ = 1;
    ;}
    break;

  case 473:

/* Line 1455 of yacc.c  */
#line 2719 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.node) = (yyvsp[(1) - (1)].node);
      (yyval.node)->param_num_ = 1;
      (yyval.node)->is_hidden_const_ = 0;
    ;}
    break;

  case 474:

/* Line 1455 of yacc.c  */
#line 2725 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_VARCHAR);
      (yyval.node)->str_value_ = parse_strdup("binary", parse_ctx->mem_pool_, &((yyval.node)->str_len_));
      if (OB_UNLIKELY(NULL == (yyval.node)->str_value_)) {
        YY_FATAL_ERROR("no more memory to malloc 'binary; string\n");
      }
      (yyval.node)->param_num_ = 0;
      (yyval.node)->is_hidden_const_ = 1;
    ;}
    break;

  case 475:

/* Line 1455 of yacc.c  */
#line 2738 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (void)((yyvsp[(1) - (2)].node));
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_CHARSET);
      (yyval.node)->str_value_ = (yyvsp[(2) - (2)].node)->str_value_;
      (yyval.node)->str_len_ = (yyvsp[(2) - (2)].node)->str_len_;
    ;}
    break;

  case 476:

/* Line 1455 of yacc.c  */
#line 2744 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 477:

/* Line 1455 of yacc.c  */
#line 2749 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.node) = NULL;
    ;}
    break;

  case 478:

/* Line 1455 of yacc.c  */
#line 2753 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.node) = NULL;
    ;}
    break;

  case 479:

/* Line 1455 of yacc.c  */
#line 2760 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_terminal_node((yyval.node), parse_ctx->mem_pool_, T_COLLATION);
      (yyval.node)->str_value_ = (yyvsp[(2) - (2)].node)->str_value_;
      (yyval.node)->str_len_ = (yyvsp[(2) - (2)].node)->str_len_;
      (yyval.node)->param_num_ = (yyvsp[(2) - (2)].node)->param_num_;
    ;}
    break;

  case 480:

/* Line 1455 of yacc.c  */
#line 2770 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      (yyval.node) = (yyvsp[(1) - (1)].node);
    ;}
    break;

  case 481:

/* Line 1455 of yacc.c  */
#line 2773 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 482:

/* Line 1455 of yacc.c  */
#line 2778 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_SIGNAL, 2, (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 483:

/* Line 1455 of yacc.c  */
#line 2785 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_RESIGNAL, 2, (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 484:

/* Line 1455 of yacc.c  */
#line 2791 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 485:

/* Line 1455 of yacc.c  */
#line 2792 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 486:

/* Line 1455 of yacc.c  */
#line 2796 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 487:

/* Line 1455 of yacc.c  */
#line 2797 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 488:

/* Line 1455 of yacc.c  */
#line 2801 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = NULL; ;}
    break;

  case 489:

/* Line 1455 of yacc.c  */
#line 2803 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      merge_nodes((yyval.node), parse_ctx->mem_pool_, T_SP_SIGNAL_INFO_LIST, (yyvsp[(2) - (2)].node));
    ;}
    break;

  case 490:

/* Line 1455 of yacc.c  */
#line 2809 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 491:

/* Line 1455 of yacc.c  */
#line 2811 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_LINK_NODE, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
    ;}
    break;

  case 492:

/* Line 1455 of yacc.c  */
#line 2818 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    {
      malloc_non_terminal_node((yyval.node), parse_ctx->mem_pool_, T_SP_SIGNAL_INFO_ITEM, 1, (yyvsp[(3) - (3)].node));
      (yyval.node)->value_ = (yyvsp[(1) - (3)].ival);
    ;}
    break;

  case 493:

/* Line 1455 of yacc.c  */
#line 2825 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 494:

/* Line 1455 of yacc.c  */
#line 2826 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 495:

/* Line 1455 of yacc.c  */
#line 2827 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 496:

/* Line 1455 of yacc.c  */
#line 2828 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 497:

/* Line 1455 of yacc.c  */
#line 2832 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 498:

/* Line 1455 of yacc.c  */
#line 2833 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 499:

/* Line 1455 of yacc.c  */
#line 2837 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = DIAG_CLASS_ORIGIN; ;}
    break;

  case 500:

/* Line 1455 of yacc.c  */
#line 2838 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = DIAG_SUBCLASS_ORIGIN; ;}
    break;

  case 501:

/* Line 1455 of yacc.c  */
#line 2839 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = DIAG_CONSTRAINT_CATALOG; ;}
    break;

  case 502:

/* Line 1455 of yacc.c  */
#line 2840 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = DIAG_CONSTRAINT_SCHEMA; ;}
    break;

  case 503:

/* Line 1455 of yacc.c  */
#line 2841 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = DIAG_CONSTRAINT_NAME; ;}
    break;

  case 504:

/* Line 1455 of yacc.c  */
#line 2842 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = DIAG_CATALOG_NAME; ;}
    break;

  case 505:

/* Line 1455 of yacc.c  */
#line 2843 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = DIAG_SCHEMA_NAME; ;}
    break;

  case 506:

/* Line 1455 of yacc.c  */
#line 2844 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = DIAG_TABLE_NAME; ;}
    break;

  case 507:

/* Line 1455 of yacc.c  */
#line 2845 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = DIAG_COLUMN_NAME; ;}
    break;

  case 508:

/* Line 1455 of yacc.c  */
#line 2846 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = DIAG_CURSOR_NAME; ;}
    break;

  case 509:

/* Line 1455 of yacc.c  */
#line 2847 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = DIAG_MESSAGE_TEXT; ;}
    break;

  case 510:

/* Line 1455 of yacc.c  */
#line 2848 "../../../src/pl/parser/pl_parser_mysql_mode.y"
    { (yyval.ival) = DIAG_MYSQL_ERRNO; ;}
    break;



/* Line 1455 of yacc.c  */
#line 8064 "../../../src/pl/parser/pl_parser_mysql_mode_tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, parse_ctx, YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (&yylloc, parse_ctx, yymsg);
	  }
	else
	  {
	    yyerror (&yylloc, parse_ctx, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc, parse_ctx);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp, parse_ctx);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, parse_ctx, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc, parse_ctx);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, parse_ctx);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 2851 "../../../src/pl/parser/pl_parser_mysql_mode.y"

/**
 * parser function
 * @param [out] pl_yychar, set the pl parser look-ahead token
 */
ParseNode *obpl_mysql_read_sql_construct(ObParseCtx *parse_ctx, const char *prefix, YYLookaheadToken *la_token, int end_token_cnt, ...)
{
  int errcode = OB_PARSER_SUCCESS;
  va_list va;
  bool is_break = false;
  int sql_str_len = -1;
  int parenlevel = (*(la_token->la_yychar) == '(' || *(la_token->la_yychar) == '[') ? 1 : 0;
  const char *sql_str = NULL;
  ParseResult parse_result;
  ParseNode *sql_node = NULL;
  if (*(la_token->la_yychar) != -2) { //#define YYEMPTY    (-2)
    parse_ctx->scanner_ctx_.sql_end_loc = la_token->la_yylloc->last_column;
    if (parse_ctx->scanner_ctx_.sql_start_loc < 0) {
      parse_ctx->scanner_ctx_.sql_start_loc = la_token->la_yylloc->first_column;
    }
  }
  while (!is_break) {
    *(la_token->la_yychar) = obpl_mysql_yylex(la_token->la_yylval, la_token->la_yylloc, parse_ctx->scanner_ctx_.yyscan_info_);
    if (parse_ctx->scanner_ctx_.sql_start_loc < 0) {
      //get sql rule start location
      parse_ctx->scanner_ctx_.sql_start_loc = la_token->la_yylloc->first_column;
    }
    va_start(va, end_token_cnt);
    int i = 0;
    for (; !is_break && i < end_token_cnt; ++i) {
      int end_token = va_arg(va, int);
      if (end_token == *(la_token->la_yychar) && parenlevel <= 0) { //正常应该用==0，但是可能外面已经读出了左括号，所以这里用<=
        is_break = true;
        if (END_P == end_token) {
          parse_ctx->scanner_ctx_.sql_end_loc = la_token->la_yylloc->last_column;
        } else {
          parse_ctx->scanner_ctx_.sql_end_loc = la_token->la_yylloc->first_column - 1;
        }
      }
    }
    va_end(va);
    if (*(la_token->la_yychar) == '(' || *(la_token->la_yychar) == '[') {
      ++parenlevel;
    } else if (*(la_token->la_yychar) == ')' || *(la_token->la_yychar) == ']') {
      --parenlevel;
    }
    if (END_P == *(la_token->la_yychar)) {
      is_break = true;
      parse_ctx->scanner_ctx_.sql_end_loc = la_token->la_yylloc->last_column;
    }
    if (!is_break) {
      //get sql rule end location
      parse_ctx->scanner_ctx_.sql_end_loc = la_token->la_yylloc->last_column;
    }
  }
  if (OB_PARSER_SUCCESS == errcode) {
    parse_ctx->scanner_ctx_.sql_end_loc = parse_ctx->stmt_len_ <= parse_ctx->scanner_ctx_.sql_end_loc ?
                                            parse_ctx->stmt_len_ - 1 : parse_ctx->scanner_ctx_.sql_end_loc;
    sql_str_len = parse_ctx->scanner_ctx_.sql_end_loc - parse_ctx->scanner_ctx_.sql_start_loc + 1;
  }
  if (OB_PARSER_SUCCESS == errcode && sql_str_len > 0) {
    sql_str = strndup_with_prefix(prefix, parse_ctx->stmt_str_ + parse_ctx->scanner_ctx_.sql_start_loc,
                                  sql_str_len, parse_ctx->mem_pool_);
    if (NULL == sql_str) {
      YY_FATAL_ERROR("no memory to strdup sql string\n");
    }
    //parse sql_str...
    memset(&parse_result, 0, sizeof(ParseResult));
    parse_result.input_sql_ = sql_str;
    parse_result.input_sql_len_ = sql_str_len + strlen(prefix);
    parse_result.malloc_pool_ = parse_ctx->mem_pool_;
    parse_result.pl_parse_info_.is_pl_parse_ = true;
    parse_result.pl_parse_info_.is_pl_parse_expr_ = false;
    parse_result.is_for_trigger_ = (1 == parse_ctx->is_for_trigger_);
    //将pl_parser的question_mark_size赋值给sql_parser，使得parser sql的question mark能够接着pl_parser的index
    parse_result.question_mark_ctx_ = parse_ctx->question_mark_ctx_;
    parse_result.charset_info_ = parse_ctx->charset_info_;
    parse_result.charset_info_nls_db_ = parse_ctx->charset_info_nls_db_;
    parse_result.is_not_utf8_connection_ = parse_ctx->is_not_utf8_connection_;
    parse_result.connection_collation_ = parse_ctx->connection_collation_;
    parse_result.sql_mode_ = parse_ctx->scanner_ctx_.sql_mode_;
    parse_result.semicolon_start_col_ = INT32_MAX;
  }
  if (sql_str_len <= 0) {
    //do nothing
  } else if (0 != parse_sql_stmt(&parse_result)) {
    if (parse_result.extra_errno_ != OB_PARSER_SUCCESS) {
      obpl_mysql_parse_fatal_error(parse_result.extra_errno_, YYLEX_PARAM, parse_result.error_msg_);
    } else {
      YYLTYPE sql_yylloc;
      memset(&sql_yylloc, 0, sizeof(YYLTYPE));
      sql_yylloc.first_column = parse_ctx->scanner_ctx_.sql_start_loc;
      sql_yylloc.last_column = parse_ctx->scanner_ctx_.sql_end_loc;
      sql_yylloc.first_line = la_token->la_yylloc->first_line;
      sql_yylloc.last_line = la_token->la_yylloc->last_line;
      obpl_mysql_yyerror(&sql_yylloc, parse_ctx, "Syntax Error\n");
    }
  } else {
    sql_node = parse_result.result_tree_->children_[0];
    //通过sql_parser的question_mark_size来更新pl_parser
    parse_ctx->question_mark_ctx_ = parse_result.question_mark_ctx_;
  }
  return sql_node;
}

void obpl_mysql_yyerror(YYLTYPE *yylloc, ObParseCtx *parse_ctx, char *s)
{
  if (OB_LIKELY(NULL != parse_ctx)) {
    strncpy(parse_ctx->global_errmsg_, s, MAX_ERROR_MSG);
    parse_ctx->global_errmsg_[MAX_ERROR_MSG - 1] = '\0';
    // vfprintf(stderr, s, ap);
    if (OB_LIKELY(NULL != yylloc)) {
      ObParseErrorInfo *error_info = (ObParseErrorInfo*)parse_malloc(sizeof(ObParseErrorInfo), parse_ctx->mem_pool_);
      if (NULL == error_info) {
        YY_FATAL_ERROR("No memory for malloc parse error info\n");
      } else {
        memset(error_info, 0, sizeof(ObParseErrorInfo));
        error_info->stmt_loc_.first_column_ = yylloc->first_column;
        error_info->stmt_loc_.last_column_ = yylloc->last_column;
        error_info->stmt_loc_.first_line_ = yylloc->first_line;
        error_info->stmt_loc_.last_line_ = yylloc->last_line;
        parse_ctx->cur_error_info_ = error_info;
      }
    }
  }
}

