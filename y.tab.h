/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
    TK_ID = 259,
    TK_IF = 260,
    TK_ELSE = 261,
    TK_THEN = 262,
    TK_END_LOOP = 263,
    TK_WHILE = 264,
    TK_DO = 265,
    TK_FOR = 266,
    TK_DEC_VAR = 267,
    TK_TIPO_INT = 268,
    TK_TIPO_FLOAT = 269,
    TK_TIPO_BOOL = 270,
    TK_TIPO_CHAR = 271,
    TK_TIPO_STRING = 272,
    TK_UN_POS = 273,
    TK_CONV_FLOAT = 274,
    TK_CONV_INT = 275,
    TK_LE = 276,
    TK_HE = 277,
    TK_EQ = 278,
    TK_DIFF = 279,
    TK_CHAR = 280,
    TK_FLOAT = 281,
    TK_BOOL = 282,
    TK_NUM = 283,
    TK_STRING = 284,
    TK_FIM = 285,
    TK_ERROR = 286
  };
#endif
/* Tokens.  */
#define TK_MAIN 258
#define TK_ID 259
#define TK_IF 260
#define TK_ELSE 261
#define TK_THEN 262
#define TK_END_LOOP 263
#define TK_WHILE 264
#define TK_DO 265
#define TK_FOR 266
#define TK_DEC_VAR 267
#define TK_TIPO_INT 268
#define TK_TIPO_FLOAT 269
#define TK_TIPO_BOOL 270
#define TK_TIPO_CHAR 271
#define TK_TIPO_STRING 272
#define TK_UN_POS 273
#define TK_CONV_FLOAT 274
#define TK_CONV_INT 275
#define TK_LE 276
#define TK_HE 277
#define TK_EQ 278
#define TK_DIFF 279
#define TK_CHAR 280
#define TK_FLOAT 281
#define TK_BOOL 282
#define TK_NUM 283
#define TK_STRING 284
#define TK_FIM 285
#define TK_ERROR 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
