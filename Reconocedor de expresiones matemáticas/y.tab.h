/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
    EXIT = 258,
    CONVERT_ALL = 259,
    TABLE = 260,
    PRINTL = 261,
    print = 262,
    ERROR = 263,
    HELP = 264,
    COMENTARIO = 265,
    TKN_ID = 266,
    TKN_NUM = 267,
    TKN_SUM_ASSIGN = 268,
    TKN_RES_ASSIGN = 269,
    TKN_MUL_ASSIGN = 270,
    TKN_DIV_ASSIGN = 271,
    DMAS = 272,
    DMENOS = 273,
    TKN_CBRT = 274,
    TKN_SQRT = 275,
    TKN_ABS = 276,
    deg = 277,
    TKN_COS = 278,
    TKN_SEN = 279,
    TKN_TAN = 280,
    TKN_SEC = 281,
    TKN_CSC = 282,
    TKN_CTG = 283,
    TKN_ACOS = 284,
    TKN_ASEN = 285,
    TKN_ATAN = 286,
    TKN_ATAN2 = 287,
    TKN_COSH = 288,
    TKN_SENH = 289,
    TKN_TANH = 290,
    TKN_LOG = 291,
    TKN_LOG10 = 292,
    TKN_EXP = 293,
    BIN = 294,
    TRN = 295,
    CTN = 296,
    PTL = 297,
    SNR = 298,
    HPT = 299,
    OCT = 300,
    NNR = 301,
    HXD = 302,
    DEC = 303,
    ROM = 304,
    TKN_LOG2 = 305,
    TKN_ACOSH = 306,
    TKN_ASENH = 307,
    TKN_ATANH = 308,
    TKN_GAMMA = 309,
    TKN_HYPOT = 310,
    UNMINUS = 311,
    UNPLUS = 312
  };
#endif
/* Tokens.  */
#define EXIT 258
#define CONVERT_ALL 259
#define TABLE 260
#define PRINTL 261
#define print 262
#define ERROR 263
#define HELP 264
#define COMENTARIO 265
#define TKN_ID 266
#define TKN_NUM 267
#define TKN_SUM_ASSIGN 268
#define TKN_RES_ASSIGN 269
#define TKN_MUL_ASSIGN 270
#define TKN_DIV_ASSIGN 271
#define DMAS 272
#define DMENOS 273
#define TKN_CBRT 274
#define TKN_SQRT 275
#define TKN_ABS 276
#define deg 277
#define TKN_COS 278
#define TKN_SEN 279
#define TKN_TAN 280
#define TKN_SEC 281
#define TKN_CSC 282
#define TKN_CTG 283
#define TKN_ACOS 284
#define TKN_ASEN 285
#define TKN_ATAN 286
#define TKN_ATAN2 287
#define TKN_COSH 288
#define TKN_SENH 289
#define TKN_TANH 290
#define TKN_LOG 291
#define TKN_LOG10 292
#define TKN_EXP 293
#define BIN 294
#define TRN 295
#define CTN 296
#define PTL 297
#define SNR 298
#define HPT 299
#define OCT 300
#define NNR 301
#define HXD 302
#define DEC 303
#define ROM 304
#define TKN_LOG2 305
#define TKN_ACOSH 306
#define TKN_ASENH 307
#define TKN_ATANH 308
#define TKN_GAMMA 309
#define TKN_HYPOT 310
#define UNMINUS 311
#define UNPLUS 312

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "gramatica.y"

    long double real;
    char id[256];

#line 176 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
