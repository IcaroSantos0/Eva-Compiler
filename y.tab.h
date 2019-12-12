/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_MAIN = 258,
    TK_IF = 259,
    TK_ELSE = 260,
    TK_TERN = 261,
    TK_THEN = 262,
    TK_END_LOOP = 263,
    TK_WHILE = 264,
    TK_DO = 265,
    TK_FOR = 266,
    TK_BREAK = 267,
    TK_CONTINUE = 268,
    TK_ENTRADA = 269,
    TK_SAIDA = 270,
    TK_ID = 271,
    TK_DEC_VAR = 272,
    TK_GLOBAL = 273,
    TK_TIPO_INT = 274,
    TK_TIPO_FLOAT = 275,
    TK_TIPO_BOOL = 276,
    TK_TIPO_CHAR = 277,
    TK_TIPO_STRING = 278,
    TK_CONV_FLOAT = 279,
    TK_CONV_INT = 280,
    TK_LE = 281,
    TK_HE = 282,
    TK_EQ = 283,
    TK_DIFF = 284,
    TK_UN_SUM = 285,
    TK_UN_SUB = 286,
    TK_NUN_SUM = 287,
    TK_NUN_SUB = 288,
    TK_NUN_MUL = 289,
    TK_NUN_DIV = 290,
    TK_CHAR = 291,
    TK_FLOAT = 292,
    TK_BOOL = 293,
    TK_NUM = 294,
    TK_STRING = 295,
    TK_FIM = 296,
    TK_ERROR = 297
  };
#endif
/* Tokens.  */
#define TK_MAIN 258
#define TK_IF 259
#define TK_ELSE 260
#define TK_TERN 261
#define TK_THEN 262
#define TK_END_LOOP 263
#define TK_WHILE 264
#define TK_DO 265
#define TK_FOR 266
#define TK_BREAK 267
#define TK_CONTINUE 268
#define TK_ENTRADA 269
#define TK_SAIDA 270
#define TK_ID 271
#define TK_DEC_VAR 272
#define TK_GLOBAL 273
#define TK_TIPO_INT 274
#define TK_TIPO_FLOAT 275
#define TK_TIPO_BOOL 276
#define TK_TIPO_CHAR 277
#define TK_TIPO_STRING 278
#define TK_CONV_FLOAT 279
#define TK_CONV_INT 280
#define TK_LE 281
#define TK_HE 282
#define TK_EQ 283
#define TK_DIFF 284
#define TK_UN_SUM 285
#define TK_UN_SUB 286
#define TK_NUN_SUM 287
#define TK_NUN_SUB 288
#define TK_NUN_MUL 289
#define TK_NUN_DIV 290
#define TK_CHAR 291
#define TK_FLOAT 292
#define TK_BOOL 293
#define TK_NUM 294
#define TK_STRING 295
#define TK_FIM 296
#define TK_ERROR 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
