/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "gramatica.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    #include "colores.h"
    #include "controladorDeTokens.h"
    #include "funciones.h"
    #ifndef longitud
        #define longitud 256
    #endif // !longitud
    #include "gofuncs/math_2.h"
#line 14 "gramatica.y"

    void yyerror(char* s);
    int yylex(void);
    extern char *yytext;
    extern FILE *yyin;
    extern int nlines; 

#line 91 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 262 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  121
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1209

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  7
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  269

#define YYUNDEFTOK  2
#define YYMAXUTOK   312


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      73,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,     2,     2,     2,    55,     2,     2,
      66,    67,    53,    51,    74,    52,     2,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    68,     2,    69,    57,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    70,    72,    71,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    58,    59,    60,    61,    62,
      63,    64,    65
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    71,    71,    72,    73,    74,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    88,    89,    90,    91,    92,
      93,    94,    97,    98,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "EXIT", "CONVERT_ALL", "TABLE", "PRINTL",
  "print", "ERROR", "HELP", "COMENTARIO", "TKN_ID", "TKN_NUM",
  "TKN_SUM_ASSIGN", "TKN_RES_ASSIGN", "TKN_MUL_ASSIGN", "TKN_DIV_ASSIGN",
  "DMAS", "DMENOS", "TKN_CBRT", "TKN_SQRT", "TKN_ABS", "deg", "TKN_COS",
  "TKN_SEN", "TKN_TAN", "TKN_SEC", "TKN_CSC", "TKN_CTG", "TKN_ACOS",
  "TKN_ASEN", "TKN_ATAN", "TKN_ATAN2", "TKN_COSH", "TKN_SENH", "TKN_TANH",
  "TKN_LOG", "TKN_LOG10", "TKN_EXP", "BIN", "TRN", "CTN", "PTL", "SNR",
  "HPT", "OCT", "NNR", "HXD", "DEC", "ROM", "'='", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'!'", "'^'", "TKN_LOG2", "TKN_ACOSH", "TKN_ASENH",
  "TKN_ATANH", "TKN_GAMMA", "TKN_HYPOT", "UNMINUS", "UNPLUS", "'('", "')'",
  "'['", "']'", "'{'", "'}'", "'|'", "'\\n'", "','", "$accept", "linea",
  "Comandos", "AsignacionDeVariable", "Termino", "Conversion", "NumExpr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
      61,    43,    45,    42,    47,    37,    33,    94,   305,   306,
     307,   308,   309,   310,   311,   312,    40,    41,    91,    93,
     123,   125,   124,    10,    44
};
# endif

#define YYPACT_NINF (-40)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     254,   -40,   -26,   -40,   -24,   -17,   -40,   -40,   -40,   -12,
     -40,   316,   316,   -16,   -15,    -8,   -22,    -6,     3,     4,
       6,     7,     8,    12,    13,    14,    15,    44,    51,    53,
      55,    57,    59,    65,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,   316,   316,    80,    81,    87,    88,
      99,   100,   316,   316,   316,   316,   152,    94,    95,   -40,
     -40,  1108,   316,   135,   316,   316,   316,   316,   316,   -40,
     -40,   316,   -40,   -39,   -39,   316,   316,   316,   140,   141,
     142,   143,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   -39,
     -39,   316,   316,   316,   316,   316,   316,   175,   521,   528,
    1130,   -40,   144,   146,   -40,   -40,   316,   316,   316,   316,
     316,   -40,   316,   316,   316,   316,   316,   550,   -40,   557,
    1108,  1108,  1108,  1108,  1108,   579,   586,   608,   316,   316,
     316,   316,   183,   400,   407,   443,   465,   490,   615,   637,
     644,   -38,   666,   673,   695,   702,   724,   731,   753,   760,
     782,   789,   811,   818,   840,   847,   869,   876,   898,   905,
     927,   934,   956,   963,   -31,   -40,   -40,   -40,   378,   -40,
     -40,   377,   377,    -9,    -9,    52,    52,   985,   992,  1014,
    1137,   -40,   -40,   -40,   -40,   -40,  1021,  1043,  1050,   497,
     149,   -40,   154,   -40,   156,   -40,   166,   -40,   177,   -40,
     179,   -40,   -40,   -40,   -40,   316,   -40,   -40,   -40,   -40,
     -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,
     -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   316,   -40,
     -40,   -40,   378,   -40,   -40,   -40,   316,   -40,   -40,   -40,
     -40,   -40,   -40,  1072,  1079,  1101,   -40,   -40,   -40
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     6,     0,     8,     0,     0,     7,    11,    13,    23,
      22,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    36,
      12,     9,     0,     0,     0,     0,     0,     0,     0,    20,
      21,     0,    23,    40,    39,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
      38,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,     5,     3,     0,     0,     0,     0,
       0,    46,     0,     0,     0,     0,     0,     0,    14,     0,
      16,    17,    18,    19,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,    51,    52,    49,     4,
       2,    41,    42,    43,    44,    45,    47,     0,     0,     0,
       0,    35,    10,    80,    79,    48,     0,     0,     0,     0,
       0,    53,     0,    54,     0,    55,     0,    56,     0,    57,
       0,    58,    59,    60,    61,     0,    73,    74,    75,    82,
      83,    81,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    84,    76,    77,    78,    85,     0,    88,
      89,    90,    87,    69,    70,    71,     0,    63,    64,    65,
      66,    67,    68,     0,     0,     0,    62,    86,    72
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -40,   -40,   196,   198,   -40,   -40,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    56,    57,    58,    59,    60,   200
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      61,    65,    66,    67,    68,    69,    70,    78,    79,    80,
      81,    73,    74,   126,   127,   128,   129,   130,   131,   132,
     126,   127,   128,   129,   130,   131,   132,   133,   133,   134,
     134,   135,   135,   136,   136,   133,   225,   134,    71,   135,
      62,   136,    63,   248,   109,   110,   130,   131,   132,    64,
      75,    76,   117,   118,   119,   120,    61,   133,    77,   134,
      82,   135,   137,   136,   139,   140,   141,   142,   143,    83,
      84,   144,    85,    86,    87,   145,   146,   147,    88,    89,
      90,    91,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   132,
      92,   179,   180,   181,   182,   183,   184,    93,   133,    94,
     134,    95,   135,    96,   136,    97,   191,   192,   193,   194,
     195,    98,   196,   197,   198,   199,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   111,   112,   206,   207,
     208,   209,   121,   113,   114,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,   115,   116,   124,   125,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,   138,    44,    45,   210,   148,   149,   150,   151,
      46,    47,    48,    49,    50,    51,   257,   189,    52,   190,
      53,   258,    54,   259,    55,   263,   126,   127,   128,   129,
     130,   131,   132,   260,   126,   127,   128,   129,   130,   131,
     132,   133,   185,   134,   261,   135,   262,   136,   264,   133,
     211,   134,   122,   135,   123,   136,   265,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,     0,     0,     0,
       0,     0,    46,    47,    48,    49,    50,    51,     0,     0,
      52,     0,    53,     0,    54,     0,    55,    72,    10,     0,
       0,     0,     0,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,    45,     0,
       0,     0,     0,     0,    46,    47,    48,    49,    50,    51,
       0,     0,    52,     0,    53,     0,    54,     0,    55,    72,
      10,     0,     0,     0,     0,    11,    12,    13,    14,    15,
       0,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,     0,     0,     0,
       0,     0,   212,     0,     0,     0,     0,     0,     0,   214,
     128,   129,   130,   131,   132,     0,    46,    47,    48,    49,
      50,    51,     0,   133,     0,   134,     0,   135,     0,   136,
      55,   126,   127,   128,   129,   130,   131,   132,   126,   127,
     128,   129,   130,   131,   132,   216,   133,   213,   134,     0,
     135,     0,   136,   133,   215,   134,     0,   135,     0,   136,
       0,     0,     0,     0,     0,     0,     0,   218,     0,     0,
       0,     0,     0,     0,   126,   127,   128,   129,   130,   131,
     132,     0,     0,     0,     0,     0,     0,     0,     0,   133,
     217,   134,   220,   135,     0,   136,   126,   127,   128,   129,
     130,   131,   132,     0,     0,     0,     0,     0,     0,     0,
       0,   133,   219,   134,     0,   135,     0,   136,     0,     0,
       0,   126,   127,   128,   129,   130,   131,   132,   126,   127,
     128,   129,   130,   131,   132,     0,   133,   221,   134,     0,
     135,     0,   136,   133,     0,   134,     0,   135,     0,   136,
       0,   256,   126,   127,   128,   129,   130,   131,   132,   126,
     127,   128,   129,   130,   131,   132,     0,   133,     0,   134,
     186,   135,     0,   136,   133,     0,   134,     0,   135,   187,
     136,   126,   127,   128,   129,   130,   131,   132,   126,   127,
     128,   129,   130,   131,   132,     0,   133,   201,   134,     0,
     135,     0,   136,   133,   202,   134,     0,   135,     0,   136,
     126,   127,   128,   129,   130,   131,   132,   126,   127,   128,
     129,   130,   131,   132,     0,   133,   203,   134,     0,   135,
       0,   136,   133,   204,   134,     0,   135,     0,   136,   126,
     127,   128,   129,   130,   131,   132,   126,   127,   128,   129,
     130,   131,   132,     0,   133,   205,   134,     0,   135,     0,
     136,   133,   222,   134,     0,   135,     0,   136,   126,   127,
     128,   129,   130,   131,   132,   126,   127,   128,   129,   130,
     131,   132,     0,   133,   223,   134,     0,   135,     0,   136,
     133,   224,   134,     0,   135,     0,   136,   126,   127,   128,
     129,   130,   131,   132,   126,   127,   128,   129,   130,   131,
     132,     0,   133,   226,   134,     0,   135,     0,   136,   133,
     227,   134,     0,   135,     0,   136,   126,   127,   128,   129,
     130,   131,   132,   126,   127,   128,   129,   130,   131,   132,
       0,   133,   228,   134,     0,   135,     0,   136,   133,   229,
     134,     0,   135,     0,   136,   126,   127,   128,   129,   130,
     131,   132,   126,   127,   128,   129,   130,   131,   132,     0,
     133,   230,   134,     0,   135,     0,   136,   133,   231,   134,
       0,   135,     0,   136,   126,   127,   128,   129,   130,   131,
     132,   126,   127,   128,   129,   130,   131,   132,     0,   133,
     232,   134,     0,   135,     0,   136,   133,   233,   134,     0,
     135,     0,   136,   126,   127,   128,   129,   130,   131,   132,
     126,   127,   128,   129,   130,   131,   132,     0,   133,   234,
     134,     0,   135,     0,   136,   133,   235,   134,     0,   135,
       0,   136,   126,   127,   128,   129,   130,   131,   132,   126,
     127,   128,   129,   130,   131,   132,     0,   133,   236,   134,
       0,   135,     0,   136,   133,   237,   134,     0,   135,     0,
     136,   126,   127,   128,   129,   130,   131,   132,   126,   127,
     128,   129,   130,   131,   132,     0,   133,   238,   134,     0,
     135,     0,   136,   133,   239,   134,     0,   135,     0,   136,
     126,   127,   128,   129,   130,   131,   132,   126,   127,   128,
     129,   130,   131,   132,     0,   133,   240,   134,     0,   135,
       0,   136,   133,   241,   134,     0,   135,     0,   136,   126,
     127,   128,   129,   130,   131,   132,   126,   127,   128,   129,
     130,   131,   132,     0,   133,   242,   134,     0,   135,     0,
     136,   133,   243,   134,     0,   135,     0,   136,   126,   127,
     128,   129,   130,   131,   132,   126,   127,   128,   129,   130,
     131,   132,     0,   133,   244,   134,     0,   135,     0,   136,
     133,   245,   134,     0,   135,     0,   136,   126,   127,   128,
     129,   130,   131,   132,   126,   127,   128,   129,   130,   131,
     132,     0,   133,   246,   134,     0,   135,     0,   136,   133,
     247,   134,     0,   135,     0,   136,   126,   127,   128,   129,
     130,   131,   132,   126,   127,   128,   129,   130,   131,   132,
       0,   133,   249,   134,     0,   135,     0,   136,   133,     0,
     134,   250,   135,     0,   136,   126,   127,   128,   129,   130,
     131,   132,   126,   127,   128,   129,   130,   131,   132,     0,
     133,     0,   134,     0,   135,   251,   136,   133,   253,   134,
       0,   135,     0,   136,   126,   127,   128,   129,   130,   131,
     132,   126,   127,   128,   129,   130,   131,   132,     0,   133,
     254,   134,     0,   135,     0,   136,   133,   255,   134,     0,
     135,     0,   136,   126,   127,   128,   129,   130,   131,   132,
     126,   127,   128,   129,   130,   131,   132,     0,   133,   266,
     134,     0,   135,     0,   136,   133,   267,   134,     0,   135,
       0,   136,   126,   127,   128,   129,   130,   131,   132,   126,
     127,   128,   129,   130,   131,   132,     0,   133,   268,   134,
       0,   135,     0,   136,   133,     0,   134,     0,   135,     0,
     136,   126,   127,   128,   129,   130,   131,   132,   126,   127,
     128,   129,   130,   131,   132,     0,   133,     0,   134,     0,
     135,     0,   188,   133,     0,   134,     0,   135,     0,   252
};

static const yytype_int16 yycheck[] =
{
       0,    13,    14,    15,    16,    17,    18,    29,    30,    31,
      32,    11,    12,    51,    52,    53,    54,    55,    56,    57,
      51,    52,    53,    54,    55,    56,    57,    66,    66,    68,
      68,    70,    70,    72,    72,    66,    74,    68,    50,    70,
      66,    72,    66,    74,    44,    45,    55,    56,    57,    66,
      66,    66,    52,    53,    54,    55,    56,    66,    66,    68,
      66,    70,    62,    72,    64,    65,    66,    67,    68,    66,
      66,    71,    66,    66,    66,    75,    76,    77,    66,    66,
      66,    66,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,    57,
      66,   111,   112,   113,   114,   115,   116,    66,    66,    66,
      68,    66,    70,    66,    72,    66,   126,   127,   128,   129,
     130,    66,   132,   133,   134,   135,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,   148,   149,
     150,   151,     0,    66,    66,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    66,    66,    73,    73,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    67,    51,    52,    22,    66,    66,    66,    66,
      58,    59,    60,    61,    62,    63,    67,    73,    66,    73,
      68,    67,    70,    67,    72,   225,    51,    52,    53,    54,
      55,    56,    57,    67,    51,    52,    53,    54,    55,    56,
      57,    66,    67,    68,    67,    70,    67,    72,   248,    66,
      67,    68,    56,    70,    56,    72,   256,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    51,    52,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    62,    63,    -1,    -1,
      66,    -1,    68,    -1,    70,    -1,    72,    11,    12,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,
      -1,    -1,    -1,    -1,    58,    59,    60,    61,    62,    63,
      -1,    -1,    66,    -1,    68,    -1,    70,    -1,    72,    11,
      12,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      53,    54,    55,    56,    57,    -1,    58,    59,    60,    61,
      62,    63,    -1,    66,    -1,    68,    -1,    70,    -1,    72,
      72,    51,    52,    53,    54,    55,    56,    57,    51,    52,
      53,    54,    55,    56,    57,    22,    66,    67,    68,    -1,
      70,    -1,    72,    66,    67,    68,    -1,    70,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      67,    68,    22,    70,    -1,    72,    51,    52,    53,    54,
      55,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    -1,    70,    -1,    72,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    51,    52,
      53,    54,    55,    56,    57,    -1,    66,    67,    68,    -1,
      70,    -1,    72,    66,    -1,    68,    -1,    70,    -1,    72,
      -1,    74,    51,    52,    53,    54,    55,    56,    57,    51,
      52,    53,    54,    55,    56,    57,    -1,    66,    -1,    68,
      69,    70,    -1,    72,    66,    -1,    68,    -1,    70,    71,
      72,    51,    52,    53,    54,    55,    56,    57,    51,    52,
      53,    54,    55,    56,    57,    -1,    66,    67,    68,    -1,
      70,    -1,    72,    66,    67,    68,    -1,    70,    -1,    72,
      51,    52,    53,    54,    55,    56,    57,    51,    52,    53,
      54,    55,    56,    57,    -1,    66,    67,    68,    -1,    70,
      -1,    72,    66,    67,    68,    -1,    70,    -1,    72,    51,
      52,    53,    54,    55,    56,    57,    51,    52,    53,    54,
      55,    56,    57,    -1,    66,    67,    68,    -1,    70,    -1,
      72,    66,    67,    68,    -1,    70,    -1,    72,    51,    52,
      53,    54,    55,    56,    57,    51,    52,    53,    54,    55,
      56,    57,    -1,    66,    67,    68,    -1,    70,    -1,    72,
      66,    67,    68,    -1,    70,    -1,    72,    51,    52,    53,
      54,    55,    56,    57,    51,    52,    53,    54,    55,    56,
      57,    -1,    66,    67,    68,    -1,    70,    -1,    72,    66,
      67,    68,    -1,    70,    -1,    72,    51,    52,    53,    54,
      55,    56,    57,    51,    52,    53,    54,    55,    56,    57,
      -1,    66,    67,    68,    -1,    70,    -1,    72,    66,    67,
      68,    -1,    70,    -1,    72,    51,    52,    53,    54,    55,
      56,    57,    51,    52,    53,    54,    55,    56,    57,    -1,
      66,    67,    68,    -1,    70,    -1,    72,    66,    67,    68,
      -1,    70,    -1,    72,    51,    52,    53,    54,    55,    56,
      57,    51,    52,    53,    54,    55,    56,    57,    -1,    66,
      67,    68,    -1,    70,    -1,    72,    66,    67,    68,    -1,
      70,    -1,    72,    51,    52,    53,    54,    55,    56,    57,
      51,    52,    53,    54,    55,    56,    57,    -1,    66,    67,
      68,    -1,    70,    -1,    72,    66,    67,    68,    -1,    70,
      -1,    72,    51,    52,    53,    54,    55,    56,    57,    51,
      52,    53,    54,    55,    56,    57,    -1,    66,    67,    68,
      -1,    70,    -1,    72,    66,    67,    68,    -1,    70,    -1,
      72,    51,    52,    53,    54,    55,    56,    57,    51,    52,
      53,    54,    55,    56,    57,    -1,    66,    67,    68,    -1,
      70,    -1,    72,    66,    67,    68,    -1,    70,    -1,    72,
      51,    52,    53,    54,    55,    56,    57,    51,    52,    53,
      54,    55,    56,    57,    -1,    66,    67,    68,    -1,    70,
      -1,    72,    66,    67,    68,    -1,    70,    -1,    72,    51,
      52,    53,    54,    55,    56,    57,    51,    52,    53,    54,
      55,    56,    57,    -1,    66,    67,    68,    -1,    70,    -1,
      72,    66,    67,    68,    -1,    70,    -1,    72,    51,    52,
      53,    54,    55,    56,    57,    51,    52,    53,    54,    55,
      56,    57,    -1,    66,    67,    68,    -1,    70,    -1,    72,
      66,    67,    68,    -1,    70,    -1,    72,    51,    52,    53,
      54,    55,    56,    57,    51,    52,    53,    54,    55,    56,
      57,    -1,    66,    67,    68,    -1,    70,    -1,    72,    66,
      67,    68,    -1,    70,    -1,    72,    51,    52,    53,    54,
      55,    56,    57,    51,    52,    53,    54,    55,    56,    57,
      -1,    66,    67,    68,    -1,    70,    -1,    72,    66,    -1,
      68,    69,    70,    -1,    72,    51,    52,    53,    54,    55,
      56,    57,    51,    52,    53,    54,    55,    56,    57,    -1,
      66,    -1,    68,    -1,    70,    71,    72,    66,    67,    68,
      -1,    70,    -1,    72,    51,    52,    53,    54,    55,    56,
      57,    51,    52,    53,    54,    55,    56,    57,    -1,    66,
      67,    68,    -1,    70,    -1,    72,    66,    67,    68,    -1,
      70,    -1,    72,    51,    52,    53,    54,    55,    56,    57,
      51,    52,    53,    54,    55,    56,    57,    -1,    66,    67,
      68,    -1,    70,    -1,    72,    66,    67,    68,    -1,    70,
      -1,    72,    51,    52,    53,    54,    55,    56,    57,    51,
      52,    53,    54,    55,    56,    57,    -1,    66,    67,    68,
      -1,    70,    -1,    72,    66,    -1,    68,    -1,    70,    -1,
      72,    51,    52,    53,    54,    55,    56,    57,    51,    52,
      53,    54,    55,    56,    57,    -1,    66,    -1,    68,    -1,
      70,    -1,    72,    66,    -1,    68,    -1,    70,    -1,    72
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    51,    52,    58,    59,    60,    61,
      62,    63,    66,    68,    70,    72,    76,    77,    78,    79,
      80,    81,    66,    66,    66,    13,    14,    15,    16,    17,
      18,    50,    11,    81,    81,    66,    66,    66,    29,    30,
      31,    32,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    81,
      81,    66,    66,    66,    66,    66,    66,    81,    81,    81,
      81,     0,    77,    78,    73,    73,    51,    52,    53,    54,
      55,    56,    57,    66,    68,    70,    72,    81,    67,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    66,    66,
      66,    66,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    67,    69,    71,    72,    73,
      73,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    67,    67,    67,    67,    67,    81,    81,    81,    81,
      22,    67,    22,    67,    22,    67,    22,    67,    22,    67,
      22,    67,    67,    67,    67,    74,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    74,    67,
      69,    71,    72,    67,    67,    67,    74,    67,    67,    67,
      67,    67,    67,    81,    81,    81,    67,    67,    67
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    75,    76,    76,    76,    76,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    78,    78,    78,    78,    78,
      78,    78,    79,    79,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     3,     2,     1,     1,     1,     1,
       4,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       2,     2,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     1,     2,     2,     2,
       2,     3,     3,     3,     3,     3,     2,     3,     4,     3,
       3,     3,     3,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     6,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     7,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     6,     4,     4,     4,
       4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 71 "gramatica.y"
                                        {;}
#line 1792 "y.tab.c"
    break;

  case 3:
#line 72 "gramatica.y"
                                        {;}
#line 1798 "y.tab.c"
    break;

  case 4:
#line 73 "gramatica.y"
                                {;}
#line 1804 "y.tab.c"
    break;

  case 5:
#line 74 "gramatica.y"
                                {;}
#line 1810 "y.tab.c"
    break;

  case 6:
#line 77 "gramatica.y"
                    { exit(EXIT_SUCCESS); }
#line 1816 "y.tab.c"
    break;

  case 7:
#line 78 "gramatica.y"
                    { printf("%sError léxico detectado%s\n", PROJO, NORMAL); }
#line 1822 "y.tab.c"
    break;

  case 8:
#line 79 "gramatica.y"
                    { printTableValues(); }
#line 1828 "y.tab.c"
    break;

  case 9:
#line 80 "gramatica.y"
                    { printf("%s\t>>\t%s%.16Lf%s\n", NAMARILLO, CAZUL, (yyvsp[0].real), NORMAL); }
#line 1834 "y.tab.c"
    break;

  case 10:
#line 81 "gramatica.y"
                               { printf("%s\t>>\t%s%.16Lf%s\n", NAMARILLO, CAZUL, (yyvsp[-1].real), NORMAL); }
#line 1840 "y.tab.c"
    break;

  case 11:
#line 82 "gramatica.y"
                    {;}
#line 1846 "y.tab.c"
    break;

  case 12:
#line 83 "gramatica.y"
                    {;}
#line 1852 "y.tab.c"
    break;

  case 13:
#line 84 "gramatica.y"
                    {;}
#line 1858 "y.tab.c"
    break;

  case 14:
#line 85 "gramatica.y"
                       { printf("%s-------------------------------%s\n", HCELESTE, NORMAL); }
#line 1864 "y.tab.c"
    break;

  case 15:
#line 88 "gramatica.y"
                                            { agregarTokenValor((yyvsp[-2].id),(yyvsp[0].real)); }
#line 1870 "y.tab.c"
    break;

  case 16:
#line 89 "gramatica.y"
                                            { agregarTokenValor((yyvsp[-2].id),valorDelToken((yyvsp[-2].id))+(yyvsp[0].real)); }
#line 1876 "y.tab.c"
    break;

  case 17:
#line 90 "gramatica.y"
                                            { agregarTokenValor((yyvsp[-2].id),valorDelToken((yyvsp[-2].id))-(yyvsp[0].real)); }
#line 1882 "y.tab.c"
    break;

  case 18:
#line 91 "gramatica.y"
                                            { agregarTokenValor((yyvsp[-2].id),valorDelToken((yyvsp[-2].id))*(yyvsp[0].real)); }
#line 1888 "y.tab.c"
    break;

  case 19:
#line 92 "gramatica.y"
                                            { agregarTokenValor((yyvsp[-2].id),valorDelToken((yyvsp[-2].id))/(yyvsp[0].real)); }
#line 1894 "y.tab.c"
    break;

  case 20:
#line 93 "gramatica.y"
                                            { agregarTokenValor((yyvsp[-1].id),valorDelToken((yyvsp[-1].id))+1);  }
#line 1900 "y.tab.c"
    break;

  case 21:
#line 94 "gramatica.y"
                                            { agregarTokenValor((yyvsp[-1].id),valorDelToken((yyvsp[-1].id))-1);  }
#line 1906 "y.tab.c"
    break;

  case 22:
#line 97 "gramatica.y"
                            { (yyval.real) = (yyvsp[0].real); }
#line 1912 "y.tab.c"
    break;

  case 23:
#line 98 "gramatica.y"
                            { (yyval.real) = valorDelToken((yyvsp[0].id)); }
#line 1918 "y.tab.c"
    break;

  case 24:
#line 101 "gramatica.y"
                            { toBin((yyvsp[-1].real)); }
#line 1924 "y.tab.c"
    break;

  case 25:
#line 102 "gramatica.y"
                            { toTrn((yyvsp[-1].real)); }
#line 1930 "y.tab.c"
    break;

  case 26:
#line 103 "gramatica.y"
                            { toCtn((yyvsp[-1].real)); }
#line 1936 "y.tab.c"
    break;

  case 27:
#line 104 "gramatica.y"
                            { toPtl((yyvsp[-1].real)); }
#line 1942 "y.tab.c"
    break;

  case 28:
#line 105 "gramatica.y"
                            { toSnr((yyvsp[-1].real)); }
#line 1948 "y.tab.c"
    break;

  case 29:
#line 106 "gramatica.y"
                            { toHpt((yyvsp[-1].real)); }
#line 1954 "y.tab.c"
    break;

  case 30:
#line 107 "gramatica.y"
                            { toOct((yyvsp[-1].real)); }
#line 1960 "y.tab.c"
    break;

  case 31:
#line 108 "gramatica.y"
                            { toNnr((yyvsp[-1].real)); }
#line 1966 "y.tab.c"
    break;

  case 32:
#line 109 "gramatica.y"
                            { toHxd((yyvsp[-1].real)); }
#line 1972 "y.tab.c"
    break;

  case 33:
#line 110 "gramatica.y"
                            { toDec((yyvsp[-1].real)); }
#line 1978 "y.tab.c"
    break;

  case 34:
#line 111 "gramatica.y"
                            { toRom((yyvsp[-1].real)); }
#line 1984 "y.tab.c"
    break;

  case 35:
#line 112 "gramatica.y"
                                    { mostrarResultadoEnTodasLasBases((yyvsp[-1].real)); }
#line 1990 "y.tab.c"
    break;

  case 36:
#line 115 "gramatica.y"
                                        { (yyval.real) = (yyvsp[0].real);      }
#line 1996 "y.tab.c"
    break;

  case 37:
#line 116 "gramatica.y"
                                        { (yyval.real) = (yyvsp[0].real);      }
#line 2002 "y.tab.c"
    break;

  case 38:
#line 117 "gramatica.y"
                                        { (yyval.real) = (-1)*(yyvsp[0].real); }
#line 2008 "y.tab.c"
    break;

  case 39:
#line 118 "gramatica.y"
                                        { (yyval.real) = (yyvsp[0].real);      }
#line 2014 "y.tab.c"
    break;

  case 40:
#line 119 "gramatica.y"
                                        { (yyval.real) = (yyvsp[0].real);      }
#line 2020 "y.tab.c"
    break;

  case 41:
#line 120 "gramatica.y"
                                        { (yyval.real) = (yyvsp[-2].real) + (yyvsp[0].real); }
#line 2026 "y.tab.c"
    break;

  case 42:
#line 121 "gramatica.y"
                                        { (yyval.real) = (yyvsp[-2].real) - (yyvsp[0].real); }
#line 2032 "y.tab.c"
    break;

  case 43:
#line 122 "gramatica.y"
                                        { (yyval.real) = (yyvsp[-2].real) * (yyvsp[0].real); }
#line 2038 "y.tab.c"
    break;

  case 44:
#line 123 "gramatica.y"
                                        { (yyval.real) = (yyvsp[-2].real) / (yyvsp[0].real); }
#line 2044 "y.tab.c"
    break;

  case 45:
#line 124 "gramatica.y"
                                        { (yyval.real) = fmod((yyvsp[-2].real),(yyvsp[0].real));     }
#line 2050 "y.tab.c"
    break;

  case 46:
#line 125 "gramatica.y"
                                        { (yyval.real) = factorial((yyvsp[-1].real));   }
#line 2056 "y.tab.c"
    break;

  case 47:
#line 126 "gramatica.y"
                                        { (yyval.real) = pow((yyvsp[-2].real),(yyvsp[0].real));     }
#line 2062 "y.tab.c"
    break;

  case 48:
#line 127 "gramatica.y"
                                        { (yyval.real) = fabs((yyvsp[-1].real)); }
#line 2068 "y.tab.c"
    break;

  case 49:
#line 128 "gramatica.y"
                                        { (yyval.real) = fabs((yyvsp[-1].real)); }
#line 2074 "y.tab.c"
    break;

  case 50:
#line 129 "gramatica.y"
                                        { (yyval.real) = (yyvsp[-1].real);  }
#line 2080 "y.tab.c"
    break;

  case 51:
#line 130 "gramatica.y"
                                        { (yyval.real) = (yyvsp[-1].real);  }
#line 2086 "y.tab.c"
    break;

  case 52:
#line 131 "gramatica.y"
                                        { (yyval.real) = (yyvsp[-1].real);  }
#line 2092 "y.tab.c"
    break;

  case 53:
#line 132 "gramatica.y"
                                        { (yyval.real) = cos((yyvsp[-1].real));     }
#line 2098 "y.tab.c"
    break;

  case 54:
#line 133 "gramatica.y"
                                        { (yyval.real) = sin((yyvsp[-1].real));     }
#line 2104 "y.tab.c"
    break;

  case 55:
#line 134 "gramatica.y"
                                        { (yyval.real) = tan((yyvsp[-1].real));     }
#line 2110 "y.tab.c"
    break;

  case 56:
#line 135 "gramatica.y"
                                        { (yyval.real) = 1/cos((yyvsp[-1].real));   }
#line 2116 "y.tab.c"
    break;

  case 57:
#line 136 "gramatica.y"
                                        { (yyval.real) = 1/sin((yyvsp[-1].real));   }
#line 2122 "y.tab.c"
    break;

  case 58:
#line 137 "gramatica.y"
                                        { (yyval.real) = 1/tan((yyvsp[-1].real));   }
#line 2128 "y.tab.c"
    break;

  case 59:
#line 138 "gramatica.y"
                                        { (yyval.real) = acos((yyvsp[-1].real));    }
#line 2134 "y.tab.c"
    break;

  case 60:
#line 139 "gramatica.y"
                                        { (yyval.real) = asin((yyvsp[-1].real));    }
#line 2140 "y.tab.c"
    break;

  case 61:
#line 140 "gramatica.y"
                                        { (yyval.real) = atan((yyvsp[-1].real));    }
#line 2146 "y.tab.c"
    break;

  case 62:
#line 141 "gramatica.y"
                                                  { (yyval.real) = atan2((yyvsp[-3].real),(yyvsp[-1].real)); }
#line 2152 "y.tab.c"
    break;

  case 63:
#line 142 "gramatica.y"
                                        { (yyval.real) = cos((yyvsp[-2].real)*M_PI/180); }
#line 2158 "y.tab.c"
    break;

  case 64:
#line 143 "gramatica.y"
                                        { (yyval.real) = sin((yyvsp[-2].real)*M_PI/180); }
#line 2164 "y.tab.c"
    break;

  case 65:
#line 144 "gramatica.y"
                                        { (yyval.real) = tan((yyvsp[-2].real)*M_PI/180); }
#line 2170 "y.tab.c"
    break;

  case 66:
#line 145 "gramatica.y"
                                        { (yyval.real) = 1/cos((yyvsp[-2].real)*M_PI/180); }
#line 2176 "y.tab.c"
    break;

  case 67:
#line 146 "gramatica.y"
                                        { (yyval.real) = 1/sin((yyvsp[-2].real)*M_PI/180); }
#line 2182 "y.tab.c"
    break;

  case 68:
#line 147 "gramatica.y"
                                        { (yyval.real) = 1/tan((yyvsp[-2].real)*M_PI/180); }
#line 2188 "y.tab.c"
    break;

  case 69:
#line 148 "gramatica.y"
                                        { (yyval.real) = acos((yyvsp[-1].real))*180/M_PI; }
#line 2194 "y.tab.c"
    break;

  case 70:
#line 149 "gramatica.y"
                                        { (yyval.real) = asin((yyvsp[-1].real))*180/M_PI; }
#line 2200 "y.tab.c"
    break;

  case 71:
#line 150 "gramatica.y"
                                        { (yyval.real) = atan((yyvsp[-1].real))*180/M_PI; }
#line 2206 "y.tab.c"
    break;

  case 72:
#line 151 "gramatica.y"
                                                      { (yyval.real) = atan2((yyvsp[-3].real),(yyvsp[-1].real))*180/M_PI; }
#line 2212 "y.tab.c"
    break;

  case 73:
#line 152 "gramatica.y"
                                        { (yyval.real) = cosh((yyvsp[-1].real)); }
#line 2218 "y.tab.c"
    break;

  case 74:
#line 153 "gramatica.y"
                                        { (yyval.real) = sinh((yyvsp[-1].real)); }
#line 2224 "y.tab.c"
    break;

  case 75:
#line 154 "gramatica.y"
                                        { (yyval.real) = tanh((yyvsp[-1].real)); }
#line 2230 "y.tab.c"
    break;

  case 76:
#line 155 "gramatica.y"
                                        { (yyval.real) = acoshF((yyvsp[-1].real)); }
#line 2236 "y.tab.c"
    break;

  case 77:
#line 156 "gramatica.y"
                                        { (yyval.real) = asenhF((yyvsp[-1].real)); }
#line 2242 "y.tab.c"
    break;

  case 78:
#line 157 "gramatica.y"
                                        { (yyval.real) = atanhF((yyvsp[-1].real)); }
#line 2248 "y.tab.c"
    break;

  case 79:
#line 158 "gramatica.y"
                                        { (yyval.real) = sqrtF((yyvsp[-1].real)); }
#line 2254 "y.tab.c"
    break;

  case 80:
#line 159 "gramatica.y"
                                        { (yyval.real) = cbrtF((yyvsp[-1].real)); }
#line 2260 "y.tab.c"
    break;

  case 81:
#line 160 "gramatica.y"
                                        { (yyval.real) = exp((yyvsp[-1].real)); }
#line 2266 "y.tab.c"
    break;

  case 82:
#line 161 "gramatica.y"
                                        { (yyval.real) = log((yyvsp[-1].real)); }
#line 2272 "y.tab.c"
    break;

  case 83:
#line 162 "gramatica.y"
                                        { (yyval.real) = log10((yyvsp[-1].real)); }
#line 2278 "y.tab.c"
    break;

  case 84:
#line 163 "gramatica.y"
                                        { (yyval.real) = log2F((yyvsp[-1].real)); }
#line 2284 "y.tab.c"
    break;

  case 85:
#line 164 "gramatica.y"
                                        { (yyval.real) = gammaF((yyvsp[-1].real)); }
#line 2290 "y.tab.c"
    break;

  case 86:
#line 165 "gramatica.y"
                                                { (yyval.real) = hypotF((yyvsp[-3].real),(yyvsp[-1].real));}
#line 2296 "y.tab.c"
    break;

  case 87:
#line 166 "gramatica.y"
                                        { (yyval.real) = (yyvsp[-3].real) * fabs((yyvsp[-1].real)); }
#line 2302 "y.tab.c"
    break;

  case 88:
#line 167 "gramatica.y"
                                        { (yyval.real) = (yyvsp[-3].real) * (yyvsp[-1].real); }
#line 2308 "y.tab.c"
    break;

  case 89:
#line 168 "gramatica.y"
                                        { (yyval.real) = (yyvsp[-3].real) * (yyvsp[-1].real); }
#line 2314 "y.tab.c"
    break;

  case 90:
#line 169 "gramatica.y"
                                        { (yyval.real) = (yyvsp[-3].real) * (yyvsp[-1].real); }
#line 2320 "y.tab.c"
    break;


#line 2324 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
                      yytoken, &yylval);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 171 "gramatica.y"

void yyerror(char *s) { fprintf(stderr, "%s%s%s\n", PROJO, s, NORMAL); }
int main()
{
    config.cantidadDeTokens = 0;
    printf("\t\t%sRECONOCEDOR DE EXPRESIONES MATEMÁTICAS%s\n", SCELESTE, NORMAL);
    yyparse();
    printf("Se han analizado %s%d%s líneas.\n", NVERDE, nlines, NORMAL);
    return 0;
}
