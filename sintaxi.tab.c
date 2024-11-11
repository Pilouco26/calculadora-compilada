/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "sintaxi.y"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "symtab.h"
extern FILE *yyin;
extern FILE *yyout;
extern int yylineno;
extern int yylex();
void yyrestart(FILE *input_file);
/*extern void yyerror(char*);*/
int contador_initialized = 0;
int comptador = 0;

#line 88 "sintaxi.tab.c"

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

#include "sintaxi.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTEGER = 3,                    /* INTEGER  */
  YYSYMBOL_FALSE = 4,                      /* FALSE  */
  YYSYMBOL_TRUE = 5,                       /* TRUE  */
  YYSYMBOL_MODE = 6,                       /* MODE  */
  YYSYMBOL_FLOAT = 7,                      /* FLOAT  */
  YYSYMBOL_ID = 8,                         /* ID  */
  YYSYMBOL_ID_BOOL = 9,                    /* ID_BOOL  */
  YYSYMBOL_STRING = 10,                    /* STRING  */
  YYSYMBOL_REPEAT = 11,                    /* REPEAT  */
  YYSYMBOL_DO = 12,                        /* DO  */
  YYSYMBOL_DONE = 13,                      /* DONE  */
  YYSYMBOL_COMMENT = 14,                   /* COMMENT  */
  YYSYMBOL_SUBSTR = 15,                    /* SUBSTR  */
  YYSYMBOL_COMMA = 16,                     /* COMMA  */
  YYSYMBOL_LEN = 17,                       /* LEN  */
  YYSYMBOL_SIN = 18,                       /* SIN  */
  YYSYMBOL_COS = 19,                       /* COS  */
  YYSYMBOL_TAN = 20,                       /* TAN  */
  YYSYMBOL_AND = 21,                       /* AND  */
  YYSYMBOL_OR = 22,                        /* OR  */
  YYSYMBOL_NOT = 23,                       /* NOT  */
  YYSYMBOL_PLUS = 24,                      /* PLUS  */
  YYSYMBOL_MINUS = 25,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 26,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 27,                    /* DIVIDE  */
  YYSYMBOL_MOD = 28,                       /* MOD  */
  YYSYMBOL_POWER = 29,                     /* POWER  */
  YYSYMBOL_CLOSED_PARENTHESIS = 30,        /* CLOSED_PARENTHESIS  */
  YYSYMBOL_OPEN_PARENTHESIS = 31,          /* OPEN_PARENTHESIS  */
  YYSYMBOL_ASSIGN = 32,                    /* ASSIGN  */
  YYSYMBOL_ENDLINE = 33,                   /* ENDLINE  */
  YYSYMBOL_SEMICOLON = 34,                 /* SEMICOLON  */
  YYSYMBOL_GREATER_THAN = 35,              /* GREATER_THAN  */
  YYSYMBOL_GREATER_EQUAL = 36,             /* GREATER_EQUAL  */
  YYSYMBOL_LESS_THAN = 37,                 /* LESS_THAN  */
  YYSYMBOL_LESS_EQUAL = 38,                /* LESS_EQUAL  */
  YYSYMBOL_EQUAL = 39,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 40,                 /* NOT_EQUAL  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_programa = 42,                  /* programa  */
  YYSYMBOL_expressio_list = 43,            /* expressio_list  */
  YYSYMBOL_header = 44,                    /* header  */
  YYSYMBOL_expressio = 45,                 /* expressio  */
  YYSYMBOL_OPERATION = 46,                 /* OPERATION  */
  YYSYMBOL_OPERATION2 = 47,                /* OPERATION2  */
  YYSYMBOL_OPERATION3 = 48,                /* OPERATION3  */
  YYSYMBOL_OPERATION4 = 49,                /* OPERATION4  */
  YYSYMBOL_OPERATION_BOOLEAN = 50,         /* OPERATION_BOOLEAN  */
  YYSYMBOL_OPERATION_BOOLEAN1 = 51,        /* OPERATION_BOOLEAN1  */
  YYSYMBOL_OPERATION_BOOLEAN2 = 52,        /* OPERATION_BOOLEAN2  */
  YYSYMBOL_OPERATION_BOOLEAN3 = 53         /* OPERATION_BOOLEAN3  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  45
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   241

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  52
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  91

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    63,    63,    67,    71,    75,    81,   116,   121,   154,
     183,   194,   209,   251,   271,   287,   352,   379,   382,   383,
     407,   439,   455,   459,   476,   478,   479,   488,   497,   514,
     524,   570,   576,   582,   586,   611,   636,   659,   665,   668,
     669,   677,   678,   685,   693,   697,   709,   713,   727,   741,
     755,   772,   786
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER", "FALSE",
  "TRUE", "MODE", "FLOAT", "ID", "ID_BOOL", "STRING", "REPEAT", "DO",
  "DONE", "COMMENT", "SUBSTR", "COMMA", "LEN", "SIN", "COS", "TAN", "AND",
  "OR", "NOT", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "MOD", "POWER",
  "CLOSED_PARENTHESIS", "OPEN_PARENTHESIS", "ASSIGN", "ENDLINE",
  "SEMICOLON", "GREATER_THAN", "GREATER_EQUAL", "LESS_THAN", "LESS_EQUAL",
  "EQUAL", "NOT_EQUAL", "$accept", "programa", "expressio_list", "header",
  "expressio", "OPERATION", "OPERATION2", "OPERATION3", "OPERATION4",
  "OPERATION_BOOLEAN", "OPERATION_BOOLEAN1", "OPERATION_BOOLEAN2",
  "OPERATION_BOOLEAN3", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-29)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-26)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     114,   -29,   -29,   -29,   -29,   -28,   -19,   -29,     2,   -15,
     197,   197,   197,   197,   172,    10,   172,    28,   -29,    20,
      13,     5,    24,   -29,     6,    33,    45,   -29,   -29,   172,
     172,   -29,     2,     1,   197,   -29,   -29,   -29,   -29,   -29,
     201,   -29,   -29,   194,   -16,   -29,   143,    84,   -29,     2,
       2,     2,     2,     2,     2,     2,     2,   197,   197,   197,
     197,   172,   172,    43,    33,    33,    40,   197,   -29,   -29,
      56,   -29,    24,    24,     1,     1,     1,     1,     1,     1,
     -29,   -29,   -29,   -29,    45,   -29,   -29,   197,   -29,    55,
     -29
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      18,    31,    46,    44,    32,    34,    45,    33,    18,     0,
      25,    25,    25,    25,    18,     0,    18,     0,     2,     0,
       0,    13,    17,    22,    24,    14,    38,    39,    41,    18,
      18,    34,    18,     6,    25,    29,    26,    27,    28,    45,
       0,    42,    35,     0,     0,     1,    18,    18,    12,    18,
      18,    18,    18,    18,    18,    18,    18,    25,    25,    25,
      25,    18,    18,     8,    10,    11,     0,    25,    36,    43,
       0,     4,    15,    16,    50,    49,    51,    52,    47,    48,
      19,    20,    21,    23,    37,    40,     9,    25,     7,     0,
      30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -29,   -29,    -9,   -29,   -29,     7,    26,    14,   -10,    18,
      25,    -6,   -29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    17,    18,    19,    20,    40,    22,    23,    24,    25,
      26,    27,    28
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      35,    36,    37,    38,    29,     1,    61,    21,    41,     4,
      31,    48,     7,    30,    69,    33,    34,     9,    42,    10,
      11,    12,    13,    43,    67,    49,    50,    15,    45,    49,
      50,   -25,    46,    32,    44,    60,    63,    70,    71,    66,
      51,    52,    53,    54,    55,    56,    47,    64,    65,    86,
      57,    58,    59,    21,    21,    61,    85,    87,    74,    75,
      76,    77,    78,    79,    49,    50,    62,    49,    50,    88,
      68,    80,    81,    82,    83,    72,    73,    89,    51,    52,
      53,    54,    55,    56,    -3,    90,    84,     1,     2,     3,
       0,     4,     5,     6,     7,     8,     0,    -3,     0,     9,
       0,    10,    11,    12,    13,     0,     0,    14,     0,    15,
       0,     0,     0,   -25,    -5,    16,     0,     1,     2,     3,
       0,     4,     5,     6,     7,     8,     0,     0,     0,     9,
       0,    10,    11,    12,    13,     0,     0,    14,     0,    15,
       0,     0,     0,   -25,     0,    16,     1,     2,     3,     0,
       4,     5,     6,     7,     8,     0,    -5,     0,     9,     0,
      10,    11,    12,    13,     0,     0,    14,     0,    15,     0,
       0,     0,   -25,     0,    16,     1,     2,     3,     0,     4,
      31,    39,     7,     0,     0,     0,     0,     9,     0,    10,
      11,    12,    13,     0,     0,    14,     0,    15,     0,     0,
       1,   -25,     0,    16,     4,    31,     0,     7,     0,     0,
       0,     0,     9,     0,    10,    11,    12,    13,    49,    50,
       0,     0,    15,     0,    68,    49,    50,     0,    32,    51,
      52,    53,    54,    55,    56,     0,    51,    52,    53,    54,
      55,    56
};

static const yytype_int8 yycheck[] =
{
      10,    11,    12,    13,    32,     3,    22,     0,    14,     7,
       8,     6,    10,    32,    30,     8,    31,    15,     8,    17,
      18,    19,    20,    16,    34,    24,    25,    25,     0,    24,
      25,    29,    12,    31,    16,    29,    29,    46,    47,    32,
      35,    36,    37,    38,    39,    40,    33,    29,    30,     6,
      26,    27,    28,    46,    47,    22,    62,    67,    51,    52,
      53,    54,    55,    56,    24,    25,    21,    24,    25,    13,
      30,    57,    58,    59,    60,    49,    50,    87,    35,    36,
      37,    38,    39,    40,     0,    30,    61,     3,     4,     5,
      -1,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      -1,    17,    18,    19,    20,    -1,    -1,    23,    -1,    25,
      -1,    -1,    -1,    29,     0,    31,    -1,     3,     4,     5,
      -1,     7,     8,     9,    10,    11,    -1,    -1,    -1,    15,
      -1,    17,    18,    19,    20,    -1,    -1,    23,    -1,    25,
      -1,    -1,    -1,    29,    -1,    31,     3,     4,     5,    -1,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    -1,
      17,    18,    19,    20,    -1,    -1,    23,    -1,    25,    -1,
      -1,    -1,    29,    -1,    31,     3,     4,     5,    -1,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    15,    -1,    17,
      18,    19,    20,    -1,    -1,    23,    -1,    25,    -1,    -1,
       3,    29,    -1,    31,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    15,    -1,    17,    18,    19,    20,    24,    25,
      -1,    -1,    25,    -1,    30,    24,    25,    -1,    31,    35,
      36,    37,    38,    39,    40,    -1,    35,    36,    37,    38,
      39,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     7,     8,     9,    10,    11,    15,
      17,    18,    19,    20,    23,    25,    31,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    32,
      32,     8,    31,    46,    31,    49,    49,    49,    49,     9,
      46,    52,     8,    46,    50,     0,    12,    33,     6,    24,
      25,    35,    36,    37,    38,    39,    40,    26,    27,    28,
      29,    22,    21,    46,    50,    50,    46,    49,    30,    30,
      43,    43,    47,    47,    46,    46,    46,    46,    46,    46,
      48,    48,    48,    48,    51,    52,     6,    49,    13,    49,
      30
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    43,    44,    45,    45,    45,
      45,    45,    45,    45,    45,    46,    46,    46,    47,    47,
      47,    47,    47,    48,    48,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    50,    50,    51,
      51,    52,    52,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     3,     0,     2,     4,     3,     4,
       3,     3,     2,     1,     1,     3,     3,     1,     0,     3,
       3,     3,     1,     3,     1,     0,     2,     2,     2,     2,
       6,     1,     1,     1,     1,     2,     3,     3,     1,     1,
       3,     1,     2,     3,     1,     1,     1,     3,     3,     3,
       3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* programa: expressio_list  */
#line 63 "sintaxi.y"
                          {
             fprintf(yyout, "End of input reached.\n");
           }
#line 1220 "sintaxi.tab.c"
    break;

  case 3: /* expressio_list: expressio ENDLINE  */
#line 67 "sintaxi.y"
                                   {
    (yyval.expr_list) = (expression_list){ .index = 0 };
    (yyval.expr_list).expr_val[(yyval.expr_list).index++] = (yyvsp[-1].expr_val);
}
#line 1229 "sintaxi.tab.c"
    break;

  case 4: /* expressio_list: expressio ENDLINE expressio_list  */
#line 71 "sintaxi.y"
                                   {
    (yyval.expr_list) = (yyvsp[0].expr_list);
    (yyval.expr_list).expr_val[(yyval.expr_list).index++] = (yyvsp[-2].expr_val);
}
#line 1238 "sintaxi.tab.c"
    break;

  case 5: /* expressio_list: %empty  */
#line 75 "sintaxi.y"
              {
    (yyval.expr_list) = (expression_list){ .index = 0 };
}
#line 1246 "sintaxi.tab.c"
    break;

  case 6: /* header: REPEAT OPERATION  */
#line 81 "sintaxi.y"
                     {
        if (!contador_initialized) {
            contador_initialized = 1;
            fprintf(yyout, "linia %d\n", (yyval.header).linea);

            (yyval.header).linea = yylineno;  // Save the current line number
            comptador = 0;
        }
        if ((yyvsp[0].expr_val).val_type == INT_TYPE) {
            if (comptador < (yyvsp[0].expr_val).val_int) {
                comptador++;

                fprintf(yyout, "passo per segon if comptador: %d, operacio: %d\n", comptador, (yyvsp[0].expr_val).val_int);
                // Restart lexer at saved line number
                rewind(yyin);  // Reset file pointer to the beginning
                // Reset file pointer to the beginning
                long offset = find_line_offset(yyin, (yyval.header).linea);
                fprintf(yyout, "linia loop %d\n", (yyval.header).linea);
                   if (offset != -1) {
                       fseek(yyin, offset, SEEK_SET);  // Go back to the saved line
                       yyrestart(yyin);  // Restart the scanner with the new input file
                    } else {
                         printf("Error: Line %d not found\n", (yyval.header).linea);
                    }


            }
        } else {
            // Handle error for invalid type
        }
    }
#line 1282 "sintaxi.tab.c"
    break;

  case 7: /* expressio: header DO expressio_list DONE  */
#line 116 "sintaxi.y"
                                 {
           contador_initialized = 0;
            comptador = 0;
    }
#line 1291 "sintaxi.tab.c"
    break;

  case 8: /* expressio: ID ASSIGN OPERATION  */
#line 121 "sintaxi.y"
                     {
                      sym_value_type existing_value;
                      int lookup_result = sym_lookup((yyvsp[-2].ident).lexema, &existing_value);
                      if (lookup_result == SYMTAB_OK) {
                          // ID already exists, check if the new value matches the existing type
                          if (existing_value.val_type != (yyvsp[0].expr_val).val_type) {
                              fprintf(stderr, "Error: Type mismatch for ID '%s' in line %d.\n", (yyvsp[-2].ident).lexema, yylineno);
                              YYABORT;
                          }
                      }
                      // Assign the new value
                      if ((yyvsp[0].expr_val).val_type == INT_TYPE) {
                          fprintf(yyout, "ID: %s (int) pren per valor: %d\n", (yyvsp[-2].ident).lexema, (int)(yyvsp[0].expr_val).val_int);
                          (yyval.expr_val).val_type = INT_TYPE;
                          (yyval.expr_val).val_int = (int)(yyvsp[0].expr_val).val_int;
                          (yyvsp[-2].ident).id_val.val_type = INT_TYPE;
                          (yyvsp[-2].ident).id_val.val_int = (yyvsp[0].expr_val).val_int;
                      } else if ((yyvsp[0].expr_val).val_type == FLOAT_TYPE) {
                          fprintf(yyout, "ID: %s (real) pren per valor: %f\n", (yyvsp[-2].ident).lexema, (yyvsp[0].expr_val).val_float);
                          (yyval.expr_val).val_type = FLOAT_TYPE;
                          (yyval.expr_val).val_float = (yyvsp[0].expr_val).val_float;
                          (yyvsp[-2].ident).id_val.val_type = FLOAT_TYPE;
                          (yyvsp[-2].ident).id_val.val_float = (yyvsp[0].expr_val).val_float;
                      } else {
                          fprintf(yyout, "ID: %s (string) pren per valor: %s\n", (yyvsp[-2].ident).lexema, (yyvsp[0].expr_val).val_string);
                          (yyval.expr_val).val_type = STRING_TYPE;
                          (yyval.expr_val).val_string = (yyvsp[0].expr_val).val_string;
                          (yyvsp[-2].ident).id_val.val_type = STRING_TYPE;
                          (yyvsp[-2].ident).id_val.val_string = (yyvsp[0].expr_val).val_string;
                      }

                      sym_enter((yyvsp[-2].ident).lexema, &(yyvsp[0].expr_val));
                  }
#line 1329 "sintaxi.tab.c"
    break;

  case 9: /* expressio: ID ASSIGN OPERATION MODE  */
#line 154 "sintaxi.y"
                                           {
                if ((yyvsp[-1].expr_val).val_type == UNKNOWN_TYPE) {
                        fprintf(stderr, "Error: ID is not declared in line %d\n", yylineno);
                        YYABORT;
                    }
                                if ((yyvsp[-1].expr_val).val_type == INT_TYPE) {
                                    if (!(yyvsp[0].mode).set || strcmp((yyvsp[0].mode).representacio, "dec") == 0) {
                                        // Default case: print the integer value
                                        fprintf(yyout, "(int)(hex) pren per valor: %d\n", (int)(yyvsp[-1].expr_val).val_int);
                                        (yyvsp[-1].expr_val).val_type = INT_TYPE;
                                        (yyvsp[-1].expr_val).val_int = (int)(yyvsp[-1].expr_val).val_int;
                                    } else if (strcmp((yyvsp[0].mode).representacio, "oct") == 0) {
                                        fprintf(yyout, "checkpoint oct\n");
                                        fprintf(yyout, "(int)(oct) pren per valor: %o\n", (int)(yyvsp[-1].expr_val).val_int);
                                    } else if (strcmp((yyvsp[0].mode).representacio, "hex") == 0) {
                                        // Hexadecimal representation (lowercase)
                                        fprintf(yyout, "(int)(hex) pren per valor: %x\n", (int)(yyvsp[-1].expr_val).val_int);
                                    } else if (strcmp((yyvsp[0].mode).representacio, "bin") == 0) {
                                        // Binary representation (using custom function)
                                        char binary[65]; // 32 bits + null terminator
                                        int_to_binary((int)(yyvsp[-1].expr_val).val_int, binary);
                                        fprintf(yyout, "(int)(bin) pren per valor: %s\n", binary);
                                        sym_enter((yyvsp[-3].ident).lexema, &(yyvsp[-1].expr_val));

                                    }
                              } else {
                                 fprintf(stderr, "Mode only supported in INTEGER, error declared in line %d\n", yylineno);
                              }
                }
#line 1363 "sintaxi.tab.c"
    break;

  case 10: /* expressio: ID ASSIGN OPERATION_BOOLEAN  */
#line 183 "sintaxi.y"
                                              {
                            fprintf(yyout, "ID: %s (bool) pren per valor: %s\n", (yyvsp[-2].ident).lexema, (yyvsp[0].expr_val).val_bool ? "true" : "false");
                            fprintf(stderr, "ID: %s (bool) pren per valor: %s\n", (yyvsp[-2].ident).lexema, (yyvsp[0].expr_val).val_bool ? "true" : "false");
                            sym_value_type value_to_store;
                            value_to_store.val_type = (yyvsp[0].expr_val).val_type;
                            value_to_store.val_bool = (yyvsp[0].expr_val).val_bool; // Assuming $3 is a boolean
                            // Check if the symbol already exists, if not, initialize a new entry

                            sym_enter((yyvsp[-2].ident).lexema, &value_to_store);

                }
#line 1379 "sintaxi.tab.c"
    break;

  case 11: /* expressio: ID_BOOL ASSIGN OPERATION_BOOLEAN  */
#line 194 "sintaxi.y"
                                                   {
                if ((yyvsp[0].expr_val).val_type == UNKNOWN_TYPE) {
                        fprintf(stderr, "Error: ID is not declared in line %d\n", yylineno);
                        YYABORT;
                }
                                            fprintf(yyout, "ID: %s (bool) pren per valor: %s\n", (yyvsp[-2].ident).lexema, (yyvsp[0].expr_val).val_bool ? "true" : "false");
                                            (yyval.expr_val).val_type = BOOL_TYPE;
                                            (yyval.expr_val).val_bool = (yyvsp[0].expr_val).val_bool;
                                            sym_value_type value_to_store;
                                            value_to_store.val_type = (yyvsp[0].expr_val).val_type;
                                            value_to_store.val_bool = (yyvsp[0].expr_val).val_bool; // Assuming $3 is a boolean
                                            sym_enter((yyvsp[-2].ident).lexema, &value_to_store);


                }
#line 1399 "sintaxi.tab.c"
    break;

  case 12: /* expressio: OPERATION MODE  */
#line 209 "sintaxi.y"
                                 {
                if ((yyvsp[-1].expr_val).val_type == UNKNOWN_TYPE) {
                        fprintf(stderr, "Error: ID is not declared in line %d\n", yylineno);
                        YYABORT;
                    }
                            if ((yyvsp[-1].expr_val).val_type == INT_TYPE) {
                                if (strcmp((yyvsp[0].mode).representacio, "dec") == 0) {
                                    // Default case: print the integer value
                                    fprintf(yyout, "(int)(hex) pren per valor: %d\n", (int)(yyvsp[-1].expr_val).val_int);
                                    (yyvsp[-1].expr_val).val_type = INT_TYPE;
                                    (yyvsp[-1].expr_val).val_int = (int)(yyvsp[-1].expr_val).val_int;
                                } else if (strcmp((yyvsp[0].mode).representacio, "oct") == 0) {
                                    fprintf(yyout, "(int)(oct) pren per valor: %o\n", (int)(yyvsp[-1].expr_val).val_int);
                                } else if (strcmp((yyvsp[0].mode).representacio, "hex") == 0) {
                                    // Hexadecimal representation (lowercase)
                                    fprintf(yyout, "(int)(hex) pren per valor: %x\n", (int)(yyvsp[-1].expr_val).val_int);
                                } else if (strcmp((yyvsp[0].mode).representacio, "bin") == 0) {
                                    // Binary representation (using custom function)
                                   char binary[65]; // 32 bits + null terminator
                                    int_to_binary((int)(yyvsp[-1].expr_val).val_int, binary);
                                    fprintf(yyout, "(int)(bin) pren per valor: %s\n", binary);
                                }
                              } else if((yyvsp[-1].expr_val).val_type == FLOAT_TYPE){
                                          if (!(yyvsp[0].mode).set || strcmp((yyvsp[0].mode).representacio, "dec") == 0) {
                                              // Default case: print the float value in decimal format
                                              fprintf(yyout, "(float)(dec) pren per valor: %f\n", (yyvsp[-1].expr_val).val_float);
                                          } else if (strcmp((yyvsp[0].mode).representacio, "hex") == 0) {
                                              // Hexadecimal representation for floats
                                              fprintf(yyout, "(float)(hex) pren per valor: %a\n", (yyvsp[-1].expr_val).val_float);
                                          } else if (strcmp((yyvsp[0].mode).representacio, "bin") == 0) {
                                              // Binary representation (using custom function)
                                              char binary[65]; // 32 bits for the float's bit pattern + null terminator
                                              float_to_binary((yyvsp[-1].expr_val).val_float, binary);
                                              fprintf(yyout, "(float)(bin) pren per valor: %s\n", binary);
                                          }
                                      }
                               else {
                                       fprintf(yyout, " (string) pren per valor: %s\n", (yyvsp[-1].expr_val).val_string);
                                       (yyval.expr_val).val_type = STRING_TYPE;
                                       (yyval.expr_val).val_string = (yyvsp[-1].expr_val).val_string;
                                       }
                }
#line 1446 "sintaxi.tab.c"
    break;

  case 13: /* expressio: OPERATION  */
#line 251 "sintaxi.y"
                            {
                    if ((yyvsp[0].expr_val).val_type == UNKNOWN_TYPE) {
                        fprintf(stderr, "Error: ID is not declared in line %d\n", yylineno);
                        YYABORT;
                    }

                    if ((yyvsp[0].expr_val).val_type == INT_TYPE) {
                        fprintf(yyout, "(int) pren per valor: %d\n", (int)(yyvsp[0].expr_val).val_int);
                        (yyvsp[0].expr_val).val_type = INT_TYPE;
                        (yyvsp[0].expr_val).val_int = (int)(yyvsp[0].expr_val).val_int;
                    } else if ((yyvsp[0].expr_val).val_type == FLOAT_TYPE) {
                        fprintf(yyout, "(real) pren per valor: %f\n", (yyvsp[0].expr_val).val_float);
                        (yyvsp[0].expr_val).val_type = FLOAT_TYPE;
                        (yyvsp[0].expr_val).val_float = (yyvsp[0].expr_val).val_int;
                    } else {
                        fprintf(yyout, " (string) pren per valor: %s\n", (yyvsp[0].expr_val).val_string);
                        (yyval.expr_val).val_type = STRING_TYPE;
                        (yyval.expr_val).val_string = (yyvsp[0].expr_val).val_string;
                    }
                }
#line 1471 "sintaxi.tab.c"
    break;

  case 14: /* expressio: OPERATION_BOOLEAN  */
#line 271 "sintaxi.y"
                                    {
                            fprintf(yyout, " (bool) pren per valor: %s\n", (yyvsp[0].expr_val).val_bool ? "true" : "false");
                            (yyval.expr_val).val_type = BOOL_TYPE;
                            (yyval.expr_val).val_bool = (yyvsp[0].expr_val).val_bool;
                }
#line 1481 "sintaxi.tab.c"
    break;

  case 15: /* OPERATION: OPERATION PLUS OPERATION2  */
#line 287 "sintaxi.y"
                              {
        char* result;
        fprintf(yyout, " op %d %d \n", (yyvsp[-2].expr_val).val_int, (yyvsp[0].expr_val).val_int);
        // Check if either operand is a string
        if ((yyvsp[-2].expr_val).val_type == STRING_TYPE || (yyvsp[0].expr_val).val_type == STRING_TYPE) {

            // Convert the first operand to string if it's an integer or float
            if ((yyvsp[-2].expr_val).val_type == INT_TYPE) {
                char int_str[12]; // Buffer to hold the string representation of the integer
                sprintf(int_str, "%d", (yyvsp[-2].expr_val).val_int); // Convert int to string
                (yyvsp[-2].expr_val).val_string = strdup(int_str); // Allocate memory for the string
                (yyvsp[-2].expr_val).val_type = STRING_TYPE; // Treat it as a string from now on
            } else if ((yyvsp[-2].expr_val).val_type == FLOAT_TYPE) {
                char float_str[20]; // Buffer to hold the string representation of the float
                sprintf(float_str, "%.6f", (yyvsp[-2].expr_val).val_float); // Convert float to string
                (yyvsp[-2].expr_val).val_string = strdup(float_str); // Allocate memory for the string
                (yyvsp[-2].expr_val).val_type = STRING_TYPE; // Treat it as a string from now on
            }

            // Convert the second operand to string if it's an integer or float
            if ((yyvsp[0].expr_val).val_type == INT_TYPE) {
                char int_str[12]; // Buffer to hold the string representation of the integer
                sprintf(int_str, "%d", (yyvsp[0].expr_val).val_int); // Convert int to string
                (yyvsp[0].expr_val).val_string = strdup(int_str); // Allocate memory for the string
                (yyvsp[0].expr_val).val_type = STRING_TYPE; // Treat it as a string from now on
            } else if ((yyvsp[0].expr_val).val_type == FLOAT_TYPE) {
                char float_str[20]; // Buffer to hold the string representation of the float
                sprintf(float_str, "%.6f", (yyvsp[0].expr_val).val_float); // Convert float to string
                (yyvsp[0].expr_val).val_string = strdup(float_str); // Allocate memory for the string
                (yyvsp[0].expr_val).val_type = STRING_TYPE; // Treat it as a string from now on
            }

            // Now, concatenate the two string operands
            result = (char*) malloc(strlen((yyvsp[-2].expr_val).val_string) + strlen((yyvsp[0].expr_val).val_string) + 1);
            if (!result) {
                fprintf(stderr, "Error: Memory allocation failed\n");
                exit(1);
            }

            // Perform the concatenation
            strcpy(result, (yyvsp[-2].expr_val).val_string);
            strcat(result, (yyvsp[0].expr_val).val_string);

            // Set the result
            (yyval.expr_val).val_type = STRING_TYPE;
            (yyval.expr_val).val_string = result;

        } else if ((yyvsp[-2].expr_val).val_type == FLOAT_TYPE || (yyvsp[0].expr_val).val_type == FLOAT_TYPE) {
            // Handle float addition
            if ((yyvsp[-2].expr_val).val_type == INT_TYPE) {
                (yyvsp[-2].expr_val).val_float = (float) (yyvsp[-2].expr_val).val_int; // Convert int to float
            }
            if ((yyvsp[0].expr_val).val_type == INT_TYPE) {
                (yyvsp[0].expr_val).val_float = (float) (yyvsp[0].expr_val).val_int; // Convert int to float
            }

            (yyval.expr_val).val_type = FLOAT_TYPE;
            (yyval.expr_val).val_float = (yyvsp[-2].expr_val).val_float + (yyvsp[0].expr_val).val_float;

        } else {
            // Both operands are integers, add them
            (yyval.expr_val).val_type = INT_TYPE;
            (yyval.expr_val).val_int = (yyvsp[-2].expr_val).val_int + (yyvsp[0].expr_val).val_int;
        }
    }
#line 1551 "sintaxi.tab.c"
    break;

  case 16: /* OPERATION: OPERATION MINUS OPERATION2  */
#line 352 "sintaxi.y"
                                 {
                printf("operacio menos\n");
                printf("%d, %d, \n", (yyvsp[-2].expr_val).val_type,(yyvsp[0].expr_val).val_type);

        if (((yyvsp[-2].expr_val).val_type == INT_TYPE || (yyvsp[-2].expr_val).val_type == FLOAT_TYPE) &&
            ((yyvsp[0].expr_val).val_type == INT_TYPE || (yyvsp[0].expr_val).val_type == FLOAT_TYPE)) {
            if ((yyvsp[-2].expr_val).val_type == FLOAT_TYPE || (yyvsp[0].expr_val).val_type == FLOAT_TYPE) {
                printf("operacio float menos\n");
                if ((yyvsp[-2].expr_val).val_type == INT_TYPE) {
                    (yyvsp[-2].expr_val).val_float = (float) (yyvsp[-2].expr_val).val_int;  // Convert $1 from int to float
                }
                if ((yyvsp[0].expr_val).val_type == INT_TYPE) {
                    (yyvsp[0].expr_val).val_float = (float) (yyvsp[0].expr_val).val_int;  // Convert $3 from int to float
                }

                (yyval.expr_val).val_type = FLOAT_TYPE;
                (yyval.expr_val).val_float = (yyvsp[-2].expr_val).val_float - (yyvsp[0].expr_val).val_float;
            } else {
                // Both operands are integers
                (yyval.expr_val).val_type = INT_TYPE;
                (yyval.expr_val).val_int = (yyvsp[-2].expr_val).val_int - (yyvsp[0].expr_val).val_int;
            }
        } else {
            fprintf(stderr, "Error: Both operands must be numbers (int or float) in line %d\n", yylineno);
            YYABORT;
        }
    }
#line 1583 "sintaxi.tab.c"
    break;

  case 19: /* OPERATION2: OPERATION2 MULTIPLY OPERATION3  */
#line 383 "sintaxi.y"
                                     {
        if (((yyvsp[-2].expr_val).val_type == INT_TYPE || (yyvsp[-2].expr_val).val_type == FLOAT_TYPE) &&
            ((yyvsp[0].expr_val).val_type == INT_TYPE || (yyvsp[0].expr_val).val_type == FLOAT_TYPE)) {

            if ((yyvsp[-2].expr_val).val_type == FLOAT_TYPE || (yyvsp[0].expr_val).val_type == FLOAT_TYPE) {
                if ((yyvsp[-2].expr_val).val_type == INT_TYPE) {
                    (yyvsp[-2].expr_val).val_float = (float) (yyvsp[-2].expr_val).val_int;  // Convert $1 from int to float
                }
                if ((yyvsp[0].expr_val).val_type == INT_TYPE) {
                    (yyvsp[0].expr_val).val_float = (float) (yyvsp[0].expr_val).val_int;  // Convert $3 from int to float
                }

                (yyval.expr_val).val_type = FLOAT_TYPE;
                (yyval.expr_val).val_float = (yyvsp[-2].expr_val).val_float * (yyvsp[0].expr_val).val_float;
            } else {
                // Both operands are integers
                (yyval.expr_val).val_type = INT_TYPE;
                (yyval.expr_val).val_int = (yyvsp[-2].expr_val).val_int * (yyvsp[0].expr_val).val_int;
            }
        } else {
            fprintf(stderr, "Error: Both operands must be numbers (int or float) in line %d\n", yylineno);
            YYABORT;
        }
    }
#line 1612 "sintaxi.tab.c"
    break;

  case 20: /* OPERATION2: OPERATION2 DIVIDE OPERATION3  */
#line 407 "sintaxi.y"
                                   {
        if (((yyvsp[-2].expr_val).val_type == INT_TYPE || (yyvsp[-2].expr_val).val_type == FLOAT_TYPE) &&
            ((yyvsp[0].expr_val).val_type == INT_TYPE || (yyvsp[0].expr_val).val_type == FLOAT_TYPE)) {

            if ((yyvsp[0].expr_val).val_type == INT_TYPE && (yyvsp[0].expr_val).val_int == 0) {
                fprintf(stderr, "Error: Division by zero in line %d\n", yylineno);
                YYABORT;
            } else if ((yyvsp[0].expr_val).val_type == FLOAT_TYPE && (yyvsp[0].expr_val).val_float == 0.0) {
                fprintf(stderr, "Error: Division by zero in line %d\n", yylineno);
                YYABORT;
            }

            if ((yyvsp[-2].expr_val).val_type == FLOAT_TYPE || (yyvsp[0].expr_val).val_type == FLOAT_TYPE) {
                if ((yyvsp[-2].expr_val).val_type == INT_TYPE) {
                    (yyvsp[-2].expr_val).val_float = (float) (yyvsp[-2].expr_val).val_int;  // Convert $1 from int to float
                }
                if ((yyvsp[0].expr_val).val_type == INT_TYPE) {
                    (yyvsp[0].expr_val).val_float = (float) (yyvsp[0].expr_val).val_int;  // Convert $3 from int to float
                }

                (yyval.expr_val).val_type = FLOAT_TYPE;
                (yyval.expr_val).val_float = (yyvsp[-2].expr_val).val_float / (yyvsp[0].expr_val).val_float;
            } else {
                // Both operands are integers
                (yyval.expr_val).val_type = INT_TYPE;
                (yyval.expr_val).val_int = (yyvsp[-2].expr_val).val_int / (yyvsp[0].expr_val).val_int;
            }
        } else {
            fprintf(stderr, "Error: Both operands must be numbers (int or float) in line %d\n", yylineno);
            YYABORT;
        }
    }
#line 1649 "sintaxi.tab.c"
    break;

  case 21: /* OPERATION2: OPERATION2 MOD OPERATION3  */
#line 439 "sintaxi.y"
                                {
    //NOMES PER INT
            if ((yyvsp[-2].expr_val).val_type == INT_TYPE || (yyvsp[0].expr_val).val_type == INT_TYPE) {
                if ((yyvsp[0].expr_val).val_int > 0) {
                    // Both operands are integers and divisor is greater than 0
                    (yyval.expr_val).val_type = INT_TYPE;
                    (yyval.expr_val).val_int = (yyvsp[-2].expr_val).val_int % (yyvsp[0].expr_val).val_int;
                } else {
                    fprintf(stderr, "Error: Modulus by zero or negative number in line %d\n", yylineno);
                    YYABORT;
                }
            }
            else {
                fprintf(stderr, "Error: Modulus is not made by integers as expected in line %d\n", yylineno-1);
            }
        }
#line 1670 "sintaxi.tab.c"
    break;

  case 23: /* OPERATION3: OPERATION4 POWER OPERATION3  */
#line 459 "sintaxi.y"
                                {
            if ((yyvsp[-2].expr_val).val_type == FLOAT_TYPE || (yyvsp[0].expr_val).val_type == FLOAT_TYPE) {
                        if ((yyvsp[-2].expr_val).val_type == INT_TYPE) {
                            (yyvsp[-2].expr_val).val_float = (float) (yyvsp[-2].expr_val).val_int;  // Convert $1 from int to float
                        }
                        if ((yyvsp[0].expr_val).val_type == INT_TYPE) {
                            (yyvsp[0].expr_val).val_float = (float) (yyvsp[0].expr_val).val_int;  // Convert $3 from int to float
                        }

                        (yyval.expr_val).val_type = FLOAT_TYPE;
                        (yyval.expr_val).val_float = pow((yyvsp[-2].expr_val).val_float, (yyvsp[0].expr_val).val_float);
                    } else {
                        // Both operands are integers
                        (yyval.expr_val).val_type = INT_TYPE;
                        (yyval.expr_val).val_int = pow((yyvsp[-2].expr_val).val_int,(yyvsp[0].expr_val).val_int);
                    }
        }
#line 1692 "sintaxi.tab.c"
    break;

  case 26: /* OPERATION4: SIN OPERATION4  */
#line 479 "sintaxi.y"
                     {
        if ((yyvsp[0].expr_val).val_type == FLOAT_TYPE) {
            (yyval.expr_val).val_type = FLOAT_TYPE;
            (yyval.expr_val).val_float = sin((yyvsp[0].expr_val).val_float);
        } else if ((yyvsp[0].expr_val).val_type == INT_TYPE) {
            (yyval.expr_val).val_type = FLOAT_TYPE;
            (yyval.expr_val).val_float = sin((yyvsp[0].expr_val).val_int);
        }
    }
#line 1706 "sintaxi.tab.c"
    break;

  case 27: /* OPERATION4: COS OPERATION4  */
#line 488 "sintaxi.y"
                     {
        if ((yyvsp[0].expr_val).val_type == FLOAT_TYPE) {
            (yyval.expr_val).val_type = FLOAT_TYPE;
            (yyval.expr_val).val_float = cos((yyvsp[0].expr_val).val_float);
        } else if ((yyvsp[0].expr_val).val_type == INT_TYPE) {
            (yyval.expr_val).val_type = FLOAT_TYPE;
            (yyval.expr_val).val_float = cos((yyvsp[0].expr_val).val_int);
        }
    }
#line 1720 "sintaxi.tab.c"
    break;

  case 28: /* OPERATION4: TAN OPERATION4  */
#line 497 "sintaxi.y"
                     {
        if ((yyvsp[0].expr_val).val_type == FLOAT_TYPE) {
            if (fmod((yyvsp[0].expr_val).val_float, M_PI) == M_PI / 2) {
                fprintf(stderr, "Error: tan is undefined at %f in line %d\n", (yyvsp[0].expr_val).val_float, yylineno);
                YYABORT;
            }
            (yyval.expr_val).val_type = FLOAT_TYPE;
            (yyval.expr_val).val_float = tan((yyvsp[0].expr_val).val_float);
        } else if ((yyvsp[0].expr_val).val_type == INT_TYPE) {
            if ((yyvsp[0].expr_val).val_int % (int)M_PI == M_PI / 2) {
                fprintf(stderr, "Error: tan is undefined at %d in line %d\n", (yyvsp[0].expr_val).val_int, yylineno);
                YYABORT;
            }
            (yyval.expr_val).val_type = FLOAT_TYPE;
            (yyval.expr_val).val_float = tan((yyvsp[0].expr_val).val_int);
        }
    }
#line 1742 "sintaxi.tab.c"
    break;

  case 29: /* OPERATION4: LEN OPERATION4  */
#line 514 "sintaxi.y"
                     {
        if ((yyvsp[0].expr_val).val_type == STRING_TYPE) {
            (yyval.expr_val).val_int = strlen((yyvsp[0].expr_val).val_string);
            (yyval.expr_val).val_type = INT_TYPE;
        } else {
            fprintf(stderr, "Error: LEN operation requires a string type in line %d\n", yylineno);
            YYABORT;
        }
    }
#line 1756 "sintaxi.tab.c"
    break;

  case 30: /* OPERATION4: SUBSTR OPEN_PARENTHESIS OPERATION4 OPERATION4 OPERATION4 CLOSED_PARENTHESIS  */
#line 524 "sintaxi.y"
                                                                              {
    // OPERATION4 $2 is the string input
    // OPERATION4 $3 is the starting index
    // OPERATION4 $4 is the length of the substring
    // ARREGLAR AIXO

    if ((yyvsp[-3].expr_val).val_type == STRING_TYPE && (yyvsp[-2].expr_val).val_type == INT_TYPE && (yyvsp[-1].expr_val).val_type == INT_TYPE) {
        // Ensure that the starting index and length are non-negative
        if ((yyvsp[-2].expr_val).val_int < 0 || (yyvsp[-1].expr_val).val_int < 0) {
            fprintf(stderr, "Error: Starting index and length must be non-negative\n");
            exit(1);
        }

        // Get the length of the input string
        int input_length = strlen((yyvsp[-3].expr_val).val_string);

        // Validate the starting index
        if ((yyvsp[-2].expr_val).val_int >= input_length) {
            fprintf(stderr, "Error: Starting index exceeds string length\n");
            exit(1);
        }

        // Calculate the effective length for the substring
        int effective_length = ((yyvsp[-2].expr_val).val_int + (yyvsp[-1].expr_val).val_int > input_length) ?
            input_length - (yyvsp[-2].expr_val).val_int : (yyvsp[-1].expr_val).val_int;

        // Allocate memory for the substring
        char *substring = (char *)malloc(effective_length + 1);
        if (substring == NULL) {
            fprintf(stderr, "Error: Memory allocation failed\n");
            exit(1);
        }

        // Copy the substring
        strncpy(substring, (yyvsp[-3].expr_val).val_string + (yyvsp[-2].expr_val).val_int, effective_length);
        substring[effective_length] = '\0'; // Null-terminate the substring

        // Set the result
        (yyval.expr_val).val_string = substring; // Assign the resulting substring
        (yyval.expr_val).val_type = STRING_TYPE;  // Set the type to STRING_TYPE
    } else {
        fprintf(stderr, "Error: Invalid types for SUBSTR\n");
        exit(1);
    }
}
#line 1806 "sintaxi.tab.c"
    break;

  case 31: /* OPERATION4: INTEGER  */
#line 570 "sintaxi.y"
              {


            (yyval.expr_val).val_type = INT_TYPE;
            (yyval.expr_val).val_int = (yyvsp[0].enter);
        }
#line 1817 "sintaxi.tab.c"
    break;

  case 32: /* OPERATION4: FLOAT  */
#line 576 "sintaxi.y"
            {
            (yyval.expr_val).val_type = FLOAT_TYPE;
            (yyval.expr_val).val_float = (yyvsp[0].real);
            printf("%f \n", (yyvsp[0].real));

        }
#line 1828 "sintaxi.tab.c"
    break;

  case 33: /* OPERATION4: STRING  */
#line 582 "sintaxi.y"
             {
                (yyval.expr_val).val_type = STRING_TYPE;
                (yyval.expr_val).val_string = (yyvsp[0].cadena);
        }
#line 1837 "sintaxi.tab.c"
    break;

  case 34: /* OPERATION4: ID  */
#line 586 "sintaxi.y"
         {
            sym_value_type value;
            int lookup_result;

            /* Call sym_lookup to find the identifier in the symbol table */
            lookup_result = sym_lookup((yyvsp[0].ident).lexema, &value);

            if (lookup_result == SYMTAB_OK) {
                fprintf(yyout, "symtab trobat\n");
                (yyval.expr_val).val_type = value.val_type;  // Store the value for later use
                if((yyval.expr_val).val_type == STRING_TYPE){
                     (yyval.expr_val).val_string = value.val_string;  // Store the value for later use
                }
                else if((yyval.expr_val).val_type == INT_TYPE){
                     (yyval.expr_val).val_int = value.val_int;  // Store the value for later use
                }
                else if((yyval.expr_val).val_type == FLOAT_TYPE){
                     (yyval.expr_val).val_float = value.val_float;  // Store the value for later use
                }

            } else {
                fprintf(stderr, "Error: ID '%s' not declared\n", (yyvsp[0].ident).lexema);
                exit(EXIT_FAILURE);  // Exit the program
            }
        }
#line 1867 "sintaxi.tab.c"
    break;

  case 35: /* OPERATION4: MINUS ID  */
#line 611 "sintaxi.y"
               {
        sym_value_type value;
        int lookup_result;

        /* Call sym_lookup to find the identifier in the symbol table */
        lookup_result = sym_lookup((yyvsp[0].ident).lexema, &value);

        if (lookup_result == SYMTAB_OK) {
            (yyval.expr_val).val_type = value.val_type;  // Store the value for later use
            if((yyval.expr_val).val_type == STRING_TYPE){
                //TODO: PRINTAR ERROR
                 (yyval.expr_val).val_string = value.val_string;  // Store the value for later use
            }
            else if((yyval.expr_val).val_type == INT_TYPE){
                 (yyval.expr_val).val_int = -value.val_int;  // Store the value for later use
            }
            else if((yyval.expr_val).val_type == FLOAT_TYPE){
                 (yyval.expr_val).val_float = -value.val_float;  // Store the value for later use
            }

        } else {
            fprintf(yyout, "ID '%s' not found, inserted with initial unknown type\n", (yyvsp[0].ident).lexema);
        }

    }
#line 1897 "sintaxi.tab.c"
    break;

  case 36: /* OPERATION4: OPEN_PARENTHESIS OPERATION CLOSED_PARENTHESIS  */
#line 636 "sintaxi.y"
                                                    {
        (yyval.expr_val).val_type = (yyvsp[-1].expr_val).val_type;

        if ((yyvsp[-1].expr_val).val_type == INT_TYPE) {
            // Handle integer type
            (yyval.expr_val).val_int = (yyvsp[-1].expr_val).val_int;

        } else if ((yyvsp[-1].expr_val).val_type == FLOAT_TYPE) {
            // Handle float type
            (yyval.expr_val).val_float = (yyvsp[-1].expr_val).val_float;

        } else if ((yyvsp[-1].expr_val).val_type == STRING_TYPE) {
            // Handle string type
            (yyval.expr_val).val_string = strdup((yyvsp[-1].expr_val).val_string);  // Duplicate the string to avoid pointer issues
        }
    }
#line 1918 "sintaxi.tab.c"
    break;

  case 37: /* OPERATION_BOOLEAN: OPERATION_BOOLEAN OR OPERATION_BOOLEAN1  */
#line 659 "sintaxi.y"
                                           {
                                (yyval.expr_val).val_type = BOOL_TYPE;
                                if ((yyvsp[-2].expr_val).val_type == BOOL_TYPE && (yyvsp[0].expr_val).val_type == BOOL_TYPE) {
                                (yyval.expr_val).val_bool = (yyvsp[-2].expr_val).val_bool || (yyvsp[0].expr_val).val_bool;
                                }
    }
#line 1929 "sintaxi.tab.c"
    break;

  case 40: /* OPERATION_BOOLEAN1: OPERATION_BOOLEAN1 AND OPERATION_BOOLEAN2  */
#line 669 "sintaxi.y"
                                               {
            (yyval.expr_val).val_type = BOOL_TYPE;
            if ((yyvsp[-2].expr_val).val_type == BOOL_TYPE && (yyvsp[0].expr_val).val_type == BOOL_TYPE) {
                (yyval.expr_val).val_bool = (yyvsp[-2].expr_val).val_bool && (yyvsp[0].expr_val).val_bool;
            }

    }
#line 1941 "sintaxi.tab.c"
    break;

  case 42: /* OPERATION_BOOLEAN2: NOT OPERATION_BOOLEAN2  */
#line 678 "sintaxi.y"
                            {
            (yyval.expr_val).val_type = BOOL_TYPE;
            if ((yyvsp[0].expr_val).val_type == BOOL_TYPE) {
                (yyval.expr_val).val_bool = !(yyvsp[0].expr_val).val_bool;
            }
    }
#line 1952 "sintaxi.tab.c"
    break;

  case 43: /* OPERATION_BOOLEAN3: OPEN_PARENTHESIS OPERATION_BOOLEAN CLOSED_PARENTHESIS  */
#line 685 "sintaxi.y"
                                                          {
            (yyval.expr_val).val_type = (yyvsp[-1].expr_val).val_type;
            if ((yyvsp[-1].expr_val).val_type == BOOL_TYPE) {
                (yyval.expr_val).val_bool = (yyvsp[-1].expr_val).val_bool;
            } else {
                (yyval.expr_val).val_bool = (yyvsp[-1].expr_val).val_bool;
            }
        }
#line 1965 "sintaxi.tab.c"
    break;

  case 44: /* OPERATION_BOOLEAN3: TRUE  */
#line 693 "sintaxi.y"
           {
            (yyval.expr_val).val_type = BOOL_TYPE;
            (yyval.expr_val).val_bool = true;  // Use bool `true` instead of string "true"
        }
#line 1974 "sintaxi.tab.c"
    break;

  case 45: /* OPERATION_BOOLEAN3: ID_BOOL  */
#line 697 "sintaxi.y"
              {
        sym_value_type value;
        int lookup_result;
        /* Call sym_lookup to find the identifier in the symbol table */
        lookup_result = sym_lookup((yyvsp[0].ident).lexema, &value);
        if (lookup_result == SYMTAB_OK) {
            (yyval.expr_val).val_type = value.val_type;  // Store the value for later use
            (yyval.expr_val).val_bool = value.val_bool;
        }
        else {
        }
    }
#line 1991 "sintaxi.tab.c"
    break;

  case 46: /* OPERATION_BOOLEAN3: FALSE  */
#line 709 "sintaxi.y"
            {
            (yyval.expr_val).val_type = BOOL_TYPE;
            (yyval.expr_val).val_bool = false;  // Use bool `false` instead of string "false"
     }
#line 2000 "sintaxi.tab.c"
    break;

  case 47: /* OPERATION_BOOLEAN3: OPERATION EQUAL OPERATION  */
#line 713 "sintaxi.y"
                                {
                     (yyval.expr_val).val_type = BOOL_TYPE;
                     if ((yyvsp[-2].expr_val).val_type == FLOAT_TYPE || (yyvsp[0].expr_val).val_type == FLOAT_TYPE) {
                         if ((yyvsp[-2].expr_val).val_type == INT_TYPE) {
                             (yyvsp[-2].expr_val).val_float = (float) (yyvsp[-2].expr_val).val_int;  // Convert $1 from int to float
                         }
                         if ((yyvsp[0].expr_val).val_type == INT_TYPE) {
                             (yyvsp[0].expr_val).val_float = (float) (yyvsp[0].expr_val).val_int;  // Convert $3 from int to float
                         }
                         (yyval.expr_val).val_bool = (yyvsp[-2].expr_val).val_float == (yyvsp[0].expr_val).val_float;
                     } else {
                         (yyval.expr_val).val_bool = (yyvsp[-2].expr_val).val_int == (yyvsp[0].expr_val).val_int;
                     }
         }
#line 2019 "sintaxi.tab.c"
    break;

  case 48: /* OPERATION_BOOLEAN3: OPERATION NOT_EQUAL OPERATION  */
#line 727 "sintaxi.y"
                                    {
                         (yyval.expr_val).val_type = BOOL_TYPE;
                         if ((yyvsp[-2].expr_val).val_type == FLOAT_TYPE || (yyvsp[0].expr_val).val_type == FLOAT_TYPE) {
                             if ((yyvsp[-2].expr_val).val_type == INT_TYPE) {
                                 (yyvsp[-2].expr_val).val_float = (float) (yyvsp[-2].expr_val).val_int;  // Convert $1 from int to float
                             }
                             if ((yyvsp[0].expr_val).val_type == INT_TYPE) {
                                 (yyvsp[0].expr_val).val_float = (float) (yyvsp[0].expr_val).val_int;  // Convert $3 from int to float
                             }
                             (yyval.expr_val).val_bool = (yyvsp[-2].expr_val).val_float != (yyvsp[0].expr_val).val_float;
                         } else {
                             (yyval.expr_val).val_bool = (yyvsp[-2].expr_val).val_int != (yyvsp[0].expr_val).val_int;
                         }
         }
#line 2038 "sintaxi.tab.c"
    break;

  case 49: /* OPERATION_BOOLEAN3: OPERATION GREATER_EQUAL OPERATION  */
#line 741 "sintaxi.y"
                                        {
                                             (yyval.expr_val).val_type = BOOL_TYPE;
                                             if ((yyvsp[-2].expr_val).val_type == FLOAT_TYPE || (yyvsp[0].expr_val).val_type == FLOAT_TYPE) {
                                                 if ((yyvsp[-2].expr_val).val_type == INT_TYPE) {
                                                     (yyvsp[-2].expr_val).val_float = (float) (yyvsp[-2].expr_val).val_int;  // Convert $1 from int to float
                                                 }
                                                 if ((yyvsp[0].expr_val).val_type == INT_TYPE) {
                                                     (yyvsp[0].expr_val).val_float = (float) (yyvsp[0].expr_val).val_int;  // Convert $3 from int to float
                                                 }
                                                 (yyval.expr_val).val_bool = (yyvsp[-2].expr_val).val_float >= (yyvsp[0].expr_val).val_float;
                                             } else {
                                                 (yyval.expr_val).val_bool = (yyvsp[-2].expr_val).val_int >= (yyvsp[0].expr_val).val_int;
                                             }
         }
#line 2057 "sintaxi.tab.c"
    break;

  case 50: /* OPERATION_BOOLEAN3: OPERATION GREATER_THAN OPERATION  */
#line 755 "sintaxi.y"
                                       {
    printf("hola");
    printf("%d, %d less_equal \n", (yyvsp[-2].expr_val).val_type, (yyvsp[-2].expr_val).val_type);

                             (yyval.expr_val).val_type = BOOL_TYPE;
                             if ((yyvsp[-2].expr_val).val_type == FLOAT_TYPE || (yyvsp[0].expr_val).val_type == FLOAT_TYPE) {
                                 if ((yyvsp[-2].expr_val).val_type == INT_TYPE) {
                                     (yyvsp[-2].expr_val).val_float = (float) (yyvsp[-2].expr_val).val_int;  // Convert $1 from int to float
                                 }
                                 if ((yyvsp[0].expr_val).val_type == INT_TYPE) {
                                     (yyvsp[0].expr_val).val_float = (float) (yyvsp[0].expr_val).val_int;  // Convert $3 from int to float
                                 }
                                 (yyval.expr_val).val_bool = (yyvsp[-2].expr_val).val_float > (yyvsp[0].expr_val).val_float;
                             } else {
                                 (yyval.expr_val).val_bool = (yyvsp[-2].expr_val).val_int > (yyvsp[0].expr_val).val_int;
                             }
         }
#line 2079 "sintaxi.tab.c"
    break;

  case 51: /* OPERATION_BOOLEAN3: OPERATION LESS_THAN OPERATION  */
#line 772 "sintaxi.y"
                                    {
                                 (yyval.expr_val).val_type = BOOL_TYPE;
                                 if ((yyvsp[-2].expr_val).val_type == FLOAT_TYPE || (yyvsp[0].expr_val).val_type == FLOAT_TYPE) {
                                     if ((yyvsp[-2].expr_val).val_type == INT_TYPE) {
                                         (yyvsp[-2].expr_val).val_float = (float) (yyvsp[-2].expr_val).val_int;  // Convert $1 from int to float
                                     }
                                     if ((yyvsp[0].expr_val).val_type == INT_TYPE) {
                                         (yyvsp[0].expr_val).val_float = (float) (yyvsp[0].expr_val).val_int;  // Convert $3 from int to float
                                     }
                                     (yyval.expr_val).val_bool = (yyvsp[-2].expr_val).val_float < (yyvsp[0].expr_val).val_float;
                                 } else {
                                     (yyval.expr_val).val_bool = (yyvsp[-2].expr_val).val_int < (yyvsp[0].expr_val).val_int;
                                 }
         }
#line 2098 "sintaxi.tab.c"
    break;

  case 52: /* OPERATION_BOOLEAN3: OPERATION LESS_EQUAL OPERATION  */
#line 786 "sintaxi.y"
                                     {
    printf("%d, %d less_equal \n", (yyvsp[-2].expr_val).val_type, (yyvsp[-2].expr_val).val_type);

                                     (yyval.expr_val).val_type = BOOL_TYPE;
                                     if ((yyvsp[-2].expr_val).val_type == FLOAT_TYPE || (yyvsp[0].expr_val).val_type == FLOAT_TYPE) {
                                         if ((yyvsp[-2].expr_val).val_type == INT_TYPE) {
                                             (yyvsp[-2].expr_val).val_float = (float) (yyvsp[-2].expr_val).val_int;  // Convert $1 from int to float
                                         }
                                         if ((yyvsp[0].expr_val).val_type == INT_TYPE) {
                                             (yyvsp[0].expr_val).val_float = (float) (yyvsp[0].expr_val).val_int;  // Convert $3 from int to float
                                         }
                                         (yyval.expr_val).val_bool = (yyvsp[-2].expr_val).val_float <= (yyvsp[0].expr_val).val_float;
                                     } else {
                                         (yyval.expr_val).val_bool = (yyvsp[-2].expr_val).val_int <= (yyvsp[0].expr_val).val_int;
                                     }
    }
#line 2119 "sintaxi.tab.c"
    break;


#line 2123 "sintaxi.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 803 "sintaxi.y"


