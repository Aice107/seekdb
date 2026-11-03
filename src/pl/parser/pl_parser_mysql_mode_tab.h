
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* "%code requires" blocks.  */

/* Line 1676 of yacc.c  */
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



/* Line 1676 of yacc.c  */
#line 76 "../../../src/pl/parser/pl_parser_mysql_mode_tab.h"

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

/* Line 1676 of yacc.c  */
#line 31 "../../../src/pl/parser/pl_parser_mysql_mode.y"

  struct _ParseNode *node;
  const struct _NonReservedKeyword *non_reserved_keyword;
  int64_t ival;



/* Line 1676 of yacc.c  */
#line 305 "../../../src/pl/parser/pl_parser_mysql_mode_tab.h"
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



