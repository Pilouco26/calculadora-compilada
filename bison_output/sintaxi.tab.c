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
#line 2 "bison_flex/sintaxi.y"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "../header_files/symtab.h"
extern FILE *yyin;
extern FILE *yyout;
extern FILE *file_ca3;
extern int yylineno;
extern int yylex();
extern int lines;
void yyrestart(FILE *input_file);
/*extern void yyerror(char*);*/
int comptador = 0;
int power = 0;
int delta = 0;
three_address_code list[1024];
char *id_list[1024];
int number_list[1024];
float float_list[1024];
float result_list[1024];
int list_size = 0;
int number_size = 0;
int float_size = 0;
int id_size=0;
int result_size = 0;
bool mode_assign = false;
int esp = 0;
int ifmode = 0;
int while_mode = 0;
int index_iterative = 0;
char program_lines[200][200];
int size_if = 0;

#line 108 "bison_output/sintaxi.tab.c"

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
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_IF = 13,                        /* IF  */
  YYSYMBOL_THEN = 14,                      /* THEN  */
  YYSYMBOL_FI = 15,                        /* FI  */
  YYSYMBOL_EXTRALINE = 16,                 /* EXTRALINE  */
  YYSYMBOL_DO = 17,                        /* DO  */
  YYSYMBOL_DONE = 18,                      /* DONE  */
  YYSYMBOL_OPENED_CLAUSE = 19,             /* OPENED_CLAUSE  */
  YYSYMBOL_CLOSED_CLAUSE = 20,             /* CLOSED_CLAUSE  */
  YYSYMBOL_COMMENT = 21,                   /* COMMENT  */
  YYSYMBOL_SUBSTR = 22,                    /* SUBSTR  */
  YYSYMBOL_COMMA = 23,                     /* COMMA  */
  YYSYMBOL_LEN = 24,                       /* LEN  */
  YYSYMBOL_SIN = 25,                       /* SIN  */
  YYSYMBOL_COS = 26,                       /* COS  */
  YYSYMBOL_TAN = 27,                       /* TAN  */
  YYSYMBOL_AND = 28,                       /* AND  */
  YYSYMBOL_OR = 29,                        /* OR  */
  YYSYMBOL_NOT = 30,                       /* NOT  */
  YYSYMBOL_PLUS = 31,                      /* PLUS  */
  YYSYMBOL_MINUS = 32,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 33,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 34,                    /* DIVIDE  */
  YYSYMBOL_MOD = 35,                       /* MOD  */
  YYSYMBOL_POWER = 36,                     /* POWER  */
  YYSYMBOL_CLOSED_PARENTHESIS = 37,        /* CLOSED_PARENTHESIS  */
  YYSYMBOL_OPEN_PARENTHESIS = 38,          /* OPEN_PARENTHESIS  */
  YYSYMBOL_ASSIGN = 39,                    /* ASSIGN  */
  YYSYMBOL_ENDLINE = 40,                   /* ENDLINE  */
  YYSYMBOL_SEMICOLON = 41,                 /* SEMICOLON  */
  YYSYMBOL_GREATER_THAN = 42,              /* GREATER_THAN  */
  YYSYMBOL_GREATER_EQUAL = 43,             /* GREATER_EQUAL  */
  YYSYMBOL_LESS_THAN = 44,                 /* LESS_THAN  */
  YYSYMBOL_LESS_EQUAL = 45,                /* LESS_EQUAL  */
  YYSYMBOL_EQUAL = 46,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 47,                 /* NOT_EQUAL  */
  YYSYMBOL_REPEAT = 48,                    /* REPEAT  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_programa = 50,                  /* programa  */
  YYSYMBOL_expressio_list = 51,            /* expressio_list  */
  YYSYMBOL_header = 52,                    /* header  */
  YYSYMBOL_if_header = 53,                 /* if_header  */
  YYSYMBOL_while_header = 54,              /* while_header  */
  YYSYMBOL_else_header = 55,               /* else_header  */
  YYSYMBOL_expressio = 56,                 /* expressio  */
  YYSYMBOL_OPERATION = 57,                 /* OPERATION  */
  YYSYMBOL_OPERATION2 = 58,                /* OPERATION2  */
  YYSYMBOL_OPERATION3 = 59,                /* OPERATION3  */
  YYSYMBOL_OPERATION4 = 60,                /* OPERATION4  */
  YYSYMBOL_OPERATION_BOOLEAN = 61,         /* OPERATION_BOOLEAN  */
  YYSYMBOL_OPERATION_BOOLEAN1 = 62,        /* OPERATION_BOOLEAN1  */
  YYSYMBOL_OPERATION_BOOLEAN2 = 63,        /* OPERATION_BOOLEAN2  */
  YYSYMBOL_OPERATION_BOOLEAN3 = 64         /* OPERATION_BOOLEAN3  */
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
#define YYFINAL  53
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   206

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  122

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   303


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    84,    84,    94,    95,   100,   134,   139,   144,   154,
     163,   170,   182,   189,   221,   250,   261,   276,   318,   344,
     351,   372,   423,   456,   490,   494,   530,   583,   599,   603,
     652,   655,   664,   673,   690,   700,   746,   753,   759,   763,
     789,   814,   833,   840,   843,   844,   852,   853,   860,   868,
     873,   888,   892,   910,   928,   944,   963,   979
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
  "TRUE", "MODE", "FLOAT", "ID", "ID_BOOL", "STRING", "WHILE", "ELSE",
  "IF", "THEN", "FI", "EXTRALINE", "DO", "DONE", "OPENED_CLAUSE",
  "CLOSED_CLAUSE", "COMMENT", "SUBSTR", "COMMA", "LEN", "SIN", "COS",
  "TAN", "AND", "OR", "NOT", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "MOD",
  "POWER", "CLOSED_PARENTHESIS", "OPEN_PARENTHESIS", "ASSIGN", "ENDLINE",
  "SEMICOLON", "GREATER_THAN", "GREATER_EQUAL", "LESS_THAN", "LESS_EQUAL",
  "EQUAL", "NOT_EQUAL", "REPEAT", "$accept", "programa", "expressio_list",
  "header", "if_header", "while_header", "else_header", "expressio",
  "OPERATION", "OPERATION2", "OPERATION3", "OPERATION4",
  "OPERATION_BOOLEAN", "OPERATION_BOOLEAN1", "OPERATION_BOOLEAN2",
  "OPERATION_BOOLEAN3", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-44)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      83,   -44,   -44,   -44,   -44,    -1,   -33,   -44,   121,   121,
     -21,   162,   162,   162,   162,   121,    15,   121,   -27,    30,
     -44,    22,    23,    31,    37,    45,     5,    27,   -44,    53,
      16,    25,   -44,   -44,   162,   130,   121,   -44,   -44,   132,
      17,    -4,   162,   162,   -44,   -44,   -44,   -44,   -44,   -44,
     159,   -13,   162,   -44,    55,    83,    83,    83,    83,   -44,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   121,   121,     0,    78,    36,    16,    16,   -44,
     -44,   162,    80,   -44,   -44,    38,    83,     7,    82,    86,
     -44,    27,    27,    38,    38,    38,    38,    38,    38,   -44,
     -44,   -44,   -44,    25,   -44,    65,   162,   -44,   162,    96,
     -44,   -44,   -44,   -44,   162,     9,    79,    87,    38,   -44,
     -44,   -44
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    36,    51,    49,    37,    39,    50,    38,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     0,     0,     0,     0,     0,    18,    24,    28,    30,
      19,    43,    44,    46,     0,     0,     0,    39,    50,     0,
       0,     0,     0,     0,    34,    31,    32,    33,    47,    40,
       0,     0,     0,     1,     0,     0,     0,     0,     3,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    39,    13,    15,    16,     7,
       6,     0,     0,    41,    48,     5,     0,     0,     0,     0,
       4,    22,    23,    55,    54,    56,    57,    52,    53,    25,
      26,    27,    29,    42,    45,     0,     0,    14,     0,     0,
       8,    10,    11,    12,     0,     0,     0,     0,    21,    20,
      35,     9
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -44,   -44,   -43,   -44,   -44,   -44,   -44,   -44,    -8,    13,
     112,    -9,    67,    46,    -7,   -44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      39,    39,    44,    45,    46,    47,    36,    39,    48,    50,
      80,    59,    87,    88,    89,    90,    72,    42,    34,   110,
     105,    52,   111,    49,    84,    72,    74,    76,    39,   119,
      53,    60,    61,    81,    79,    82,    60,    61,    35,    54,
      60,    61,   107,   109,    85,    72,    72,    62,    63,    64,
      65,    66,    67,    73,    93,    94,    95,    96,    97,    98,
      68,    69,    70,    55,    39,    39,   104,    60,    61,    60,
      61,    56,   108,    91,    92,    40,    41,    57,    62,    63,
      64,    65,    66,    67,    51,    58,     1,     2,     3,    71,
       4,     5,     6,     7,     8,    86,     9,   106,   115,   116,
     112,   113,    77,    78,   114,    10,   118,    11,    12,    13,
      14,    60,    61,    15,   117,    16,   120,    83,   103,     0,
       0,    17,     0,    18,     1,     2,     3,   121,     4,    37,
      38,     7,     0,     1,     2,     3,     0,     4,    75,    38,
       7,     0,     0,    10,     0,    11,    12,    13,    14,     0,
       0,    15,    10,    16,    11,    12,    13,    14,     0,    17,
      15,     0,    16,    60,    61,     1,     0,     0,    17,     4,
      37,     0,     7,     0,    62,    63,    64,    65,    66,    67,
      99,   100,   101,   102,    10,     0,    11,    12,    13,    14,
      60,    61,     0,     0,    16,     0,    83,     0,     0,     0,
      43,    62,    63,    64,    65,    66,    67
};

static const yytype_int8 yycheck[] =
{
       8,     9,    11,    12,    13,    14,    39,    15,    15,    17,
      14,     6,    55,    56,    57,    58,    29,    38,    19,    12,
      20,    48,    15,     8,    37,    29,    34,    35,    36,    20,
       0,    31,    32,    42,    17,    43,    31,    32,    39,    17,
      31,    32,     6,    86,    52,    29,    29,    42,    43,    44,
      45,    46,    47,    28,    62,    63,    64,    65,    66,    67,
      33,    34,    35,    40,    72,    73,    73,    31,    32,    31,
      32,    40,    81,    60,    61,     8,     9,    40,    42,    43,
      44,    45,    46,    47,    17,    40,     3,     4,     5,    36,
       7,     8,     9,    10,    11,    40,    13,    19,   106,   108,
      18,    15,    35,    36,    39,    22,   114,    24,    25,    26,
      27,    31,    32,    30,    18,    32,    37,    37,    72,    -1,
      -1,    38,    -1,    40,     3,     4,     5,    40,     7,     8,
       9,    10,    -1,     3,     4,     5,    -1,     7,     8,     9,
      10,    -1,    -1,    22,    -1,    24,    25,    26,    27,    -1,
      -1,    30,    22,    32,    24,    25,    26,    27,    -1,    38,
      30,    -1,    32,    31,    32,     3,    -1,    -1,    38,     7,
       8,    -1,    10,    -1,    42,    43,    44,    45,    46,    47,
      68,    69,    70,    71,    22,    -1,    24,    25,    26,    27,
      31,    32,    -1,    -1,    32,    -1,    37,    -1,    -1,    -1,
      38,    42,    43,    44,    45,    46,    47
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     7,     8,     9,    10,    11,    13,
      22,    24,    25,    26,    27,    30,    32,    38,    40,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    19,    39,    39,     8,     9,    57,
      61,    61,    38,    38,    60,    60,    60,    60,    63,     8,
      57,    61,    48,     0,    17,    40,    40,    40,    40,     6,
      31,    32,    42,    43,    44,    45,    46,    47,    33,    34,
      35,    36,    29,    28,    57,     8,    57,    61,    61,    17,
      14,    60,    57,    37,    37,    57,    40,    51,    51,    51,
      51,    58,    58,    57,    57,    57,    57,    57,    57,    59,
      59,    59,    59,    62,    63,    20,    19,     6,    60,    51,
      12,    15,    18,    15,    39,    57,    60,    18,    57,    20,
      37,    40
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    53,    54,    55,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    57,    57,    57,    58,    58,    58,    58,    59,
      59,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    61,    61,    62,    62,    63,    63,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     3,     3,     3,     3,     4,     6,
       4,     4,     4,     3,     4,     3,     3,     2,     1,     1,
       6,     6,     3,     3,     1,     3,     3,     3,     1,     3,
       1,     2,     2,     2,     2,     6,     1,     1,     1,     1,
       2,     3,     3,     1,     1,     3,     1,     2,     3,     1,
       1,     1,     3,     3,     3,     3,     3,     3
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
#line 84 "bison_flex/sintaxi.y"
                          {
             fprintf(yyout, "End of input reached.\n");
             for (int i = 0; i < 200; i++) {
                     if (program_lines[i][0] != '\0') {  // Check if the line is not empty
                         fprintf(file_ca3, "%s", program_lines[i]);
                     }
                 }
           }
#line 1260 "bison_output/sintaxi.tab.c"
    break;

  case 5: /* header: ENDLINE REPEAT OPERATION  */
#line 100 "bison_flex/sintaxi.y"
                              {
                 if ((yyvsp[0].expr_val).val_type == INT_TYPE) {
                             if ((yyvsp[0].expr_val).val_int > 0) {
                                char special[50]; // Adjust size as needed for longer strings

                                    // Use snprintf to safely concatenate
                                snprintf(special, sizeof(special), "$t-esp0%d", ++esp+1);
                                print_list(list, list_size, number_list, number_size, float_list, float_size,  special);
                                (yyval.header).linea = lines;
                                char buffer[200];  // Buffer to hold the formatted output

                                // Formatting the string using snprintf
                                snprintf(buffer, sizeof(buffer), "%d : $t-esp0%d := 0\n", lines++, esp++);

                                // Appending the formatted string to the appropriate program line
                                strcat(program_lines[lines - 1], buffer);  // Append to program_lines[lines - 1]

                                list_size = 0;
                                number_size = 0;
                                float_size = 0;
                                id_size = 0;
                                result_size = 0;
                                comptador = (yyvsp[0].expr_val).val_int;
                             }
                             else {
                                fprintf(stderr, "Error: Counter needs to be bigger\n");
                                fprintf(file_ca3, "Error: Counter needs to be bigger\n");
                                YYABORT;
                             }
                 } else {
                     fprintf(stderr, "Error: Invalid type for repeat count\n");
                 }
     }
#line 1298 "bison_output/sintaxi.tab.c"
    break;

  case 6: /* if_header: IF OPERATION_BOOLEAN THEN  */
#line 134 "bison_flex/sintaxi.y"
                                      {
                (yyval.header).linea = lines;
                ifmode = 1;
                lines++;
           }
#line 1308 "bison_output/sintaxi.tab.c"
    break;

  case 7: /* while_header: WHILE OPERATION_BOOLEAN DO  */
#line 139 "bison_flex/sintaxi.y"
                                          {
                (yyval.header).linea = lines;
                while_mode = 1;
                lines++;
           }
#line 1318 "bison_output/sintaxi.tab.c"
    break;

  case 8: /* else_header: if_header ENDLINE expressio_list ELSE  */
#line 144 "bison_flex/sintaxi.y"
                                                   {
                 ifmode = 0;
                 char buffer[200];  // Buffer to hold the formatted output
                 int current_line = lines;
                 (yyval.header).linea = current_line;
                 snprintf(buffer, sizeof(buffer), "%d : GOTO %d\n", (yyvsp[-3].header).linea, current_line+1); //tenir en compte el goto
                 strcat(program_lines[(yyvsp[-3].header).linea], buffer);  // Append to program_lines[$1.linia]
                 lines++;
              }
#line 1332 "bison_output/sintaxi.tab.c"
    break;

  case 9: /* expressio: header DO ENDLINE expressio_list DONE ENDLINE  */
#line 154 "bison_flex/sintaxi.y"
                                                             {
                    delta = yylineno - (yyvsp[-5].header).linea;
                    char buffer[200];  // Buffer to hold the formatted output
                    snprintf(buffer, sizeof(buffer), "%d : $t-esp01 := t-esp01 ADDI 1\n", lines++);
                    strcat(program_lines[lines - 1], buffer);  // Append to program_lines[lines - 1]
                    snprintf(buffer, sizeof(buffer), "%d : if $t-esp01 LTI $t-esp02 GO TO %d \n", lines++, (yyvsp[-5].header).linea + 1);
                    strcat(program_lines[lines - 1], buffer);  // Append to program_lines[lines - 1]

                }
#line 1346 "bison_output/sintaxi.tab.c"
    break;

  case 10: /* expressio: if_header ENDLINE expressio_list FI  */
#line 163 "bison_flex/sintaxi.y"
                                                      {
                    ifmode = 0;
                    char buffer[200];  // Buffer to hold the formatted output
                    int current_line = lines;
                    snprintf(buffer, sizeof(buffer), "%d : GOTO %d\n", (yyvsp[-3].header).linea, current_line);
                    strcat(program_lines[(yyvsp[-3].header).linea], buffer);  // Append to program_lines[$1.linia]
                    }
#line 1358 "bison_output/sintaxi.tab.c"
    break;

  case 11: /* expressio: while_header ENDLINE expressio_list DONE  */
#line 170 "bison_flex/sintaxi.y"
                                                           {
                    while_mode = 0;
                    char buffer[200];  // Buffer to hold the formatted output
                    int current_line = lines;
                    snprintf(buffer, sizeof(buffer), "%d : GOTO %d\n", (yyvsp[-3].header).linea, current_line+1);
                    strcat(program_lines[(yyvsp[-3].header).linea], buffer);  // Append to program_lines[$1.linia]
                    current_line = lines;
                    char buffer2[200];  // Buffer to hold the formatted output
                    snprintf(buffer2, sizeof(buffer2), "%d : GOTO %d\n", current_line, (yyvsp[-3].header).linea-1);
                    strcat(program_lines[current_line], buffer2);  // Append to program_lines[$1.linia]
                    lines++;
                }
#line 1375 "bison_output/sintaxi.tab.c"
    break;

  case 12: /* expressio: else_header ENDLINE expressio_list FI  */
#line 182 "bison_flex/sintaxi.y"
                                                        {
                    ifmode = 0;
                    char buffer[200];  // Buffer to hold the formatted output
                    int current_line = lines;
                    snprintf(buffer, sizeof(buffer), "%d : GOTO %d\n", (yyvsp[-3].header).linea, current_line);
                    strcat(program_lines[(yyvsp[-3].header).linea], buffer);  // Append to program_lines[$1.linia]
                 }
#line 1387 "bison_output/sintaxi.tab.c"
    break;

  case 13: /* expressio: ID ASSIGN OPERATION  */
#line 189 "bison_flex/sintaxi.y"
                                      {
                      sym_value_type existing_value;
                      int lookup_result = sym_lookup((yyvsp[-2].ident).lexema, &existing_value);
                      if (lookup_result == SYMTAB_OK) {
                          if (existing_value.val_type != (yyvsp[0].expr_val).val_type) {
                              fprintf(stderr, "Error: Type mismatch for ID '%s' in line %d.\n", (yyvsp[-2].ident).lexema, yylineno);
                          }
                      }
                        char buffer[200];  // Buffer to hold the formatted output

                        // If the type is INT_TYPE
                        if ((yyvsp[0].expr_val).val_type == INT_TYPE && list_size == 0) {
                            snprintf(buffer, sizeof(buffer), "%d : %s := %d\n", lines, (yyvsp[-2].ident).lexema, (int)(yyvsp[0].expr_val).val_int);
                            strcat(program_lines[lines], buffer);  // Append the assignment statement
                            lines++;  // Increment the line counter
                        }
                        // If the type is FLOAT_TYPE
                        else if ((yyvsp[0].expr_val).val_type == FLOAT_TYPE && list_size == 0) {
                            snprintf(buffer, sizeof(buffer), "%d : %s := %f\n", lines, (yyvsp[-2].ident).lexema, (yyvsp[0].expr_val).val_float);
                            strcat(program_lines[lines], buffer);  // Append the assignment statement
                            lines++;  // Increment the line counter
                        }

                      print_list(list, list_size, number_list, number_size, float_list, float_size,  (yyvsp[-2].ident).lexema);
                      size_if = list_size;
                      list_size = 0;
                      number_size = 0;
                      result_size = 0;
                      float_size = 0;
                      id_size = 0;
                      sym_enter((yyvsp[-2].ident).lexema, &(yyvsp[0].expr_val));
                  }
#line 1424 "bison_output/sintaxi.tab.c"
    break;

  case 14: /* expressio: ID ASSIGN OPERATION MODE  */
#line 221 "bison_flex/sintaxi.y"
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
#line 1458 "bison_output/sintaxi.tab.c"
    break;

  case 15: /* expressio: ID ASSIGN OPERATION_BOOLEAN  */
#line 250 "bison_flex/sintaxi.y"
                                              {
                            sym_value_type value_to_store;
                            value_to_store.val_type = (yyvsp[0].expr_val).val_type;
                            value_to_store.val_bool = (yyvsp[0].expr_val).val_bool; // Assuming $3 is a boolean
                            // Check if the symbol already exists, if not, initialize a new entry
                            sym_enter((yyvsp[-2].ident).lexema, &value_to_store);
                            char buffer[200];  // Buffer to hold the formatted output
                            snprintf(buffer, sizeof(buffer), "%d : %s := %d\n", lines, (yyvsp[-2].ident).lexema, (yyvsp[0].expr_val).val_bool);
                            strcat(program_lines[lines], buffer);  // Append the assignment statement
                            lines++;  // Increment the line counter
                }
#line 1474 "bison_output/sintaxi.tab.c"
    break;

  case 16: /* expressio: ID_BOOL ASSIGN OPERATION_BOOLEAN  */
#line 261 "bison_flex/sintaxi.y"
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
#line 1494 "bison_output/sintaxi.tab.c"
    break;

  case 17: /* expressio: OPERATION MODE  */
#line 276 "bison_flex/sintaxi.y"
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
#line 1541 "bison_output/sintaxi.tab.c"
    break;

  case 18: /* expressio: OPERATION  */
#line 318 "bison_flex/sintaxi.y"
                            {
                    if ((yyvsp[0].expr_val).val_type == UNKNOWN_TYPE) {
                        fprintf(stderr, "Error: ID is not declared in line %d\n", yylineno);
                        YYABORT;
                    }
                    if ((yyvsp[0].expr_val).val_type == INT_TYPE) {
                       // fprintf(yyout, "(int) pren per valor: %d\n", (int)$1.val_int);
                        (yyvsp[0].expr_val).val_type = INT_TYPE;
                        (yyvsp[0].expr_val).val_int = (int)(yyvsp[0].expr_val).val_int;
                        call_put(list, &list_size, 0, (int)(yyvsp[0].expr_val).val_int, 0);
                        print_list(list, list_size, number_list, number_size, float_list, float_size, " ");


                    } else if ((yyvsp[0].expr_val).val_type == FLOAT_TYPE) {
                        fprintf(yyout, "(real) pren per valor: %f\n", (yyvsp[0].expr_val).val_float);
                        (yyvsp[0].expr_val).val_type = FLOAT_TYPE;
                        (yyvsp[0].expr_val).val_float = (yyvsp[0].expr_val).val_float;
                        call_put(list, &list_size, 0, (yyvsp[0].expr_val).val_float, 1);
                        print_list(list, list_size, number_list, number_size, float_list, float_size, " ");

                    } else if ((yyvsp[0].expr_val).val_type == STRING_TYPE) {
                        fprintf(yyout, " (string) pren per valor: %s\n", (yyvsp[0].expr_val).val_string);
                        (yyval.expr_val).val_type = STRING_TYPE;
                        (yyval.expr_val).val_string = (yyvsp[0].expr_val).val_string;
                    }
                }
#line 1572 "bison_output/sintaxi.tab.c"
    break;

  case 19: /* expressio: OPERATION_BOOLEAN  */
#line 344 "bison_flex/sintaxi.y"
                                    {
                            if((yyvsp[0].expr_val).val_type == BOOL_TYPE){
                                fprintf(yyout, " (bool) pren per valor: %s\n", (yyvsp[0].expr_val).val_bool ? "true" : "false");
                                (yyval.expr_val).val_type = BOOL_TYPE;
                                (yyval.expr_val).val_bool = (yyvsp[0].expr_val).val_bool;
                            }
                }
#line 1584 "bison_output/sintaxi.tab.c"
    break;

  case 20: /* expressio: ID ASSIGN ID OPENED_CLAUSE OPERATION CLOSED_CLAUSE  */
#line 351 "bison_flex/sintaxi.y"
                                                                     {
                     mode_assign = true;
                     if((yyvsp[-1].expr_val).id_name != NULL)
                        add_three_address_code(list, &list_size, (yyvsp[-1].expr_val).val_int, 8, "MULI", (yyvsp[-1].expr_val).id_name, NULL);
                     else
                        add_three_address_code(list, &list_size, (yyvsp[-1].expr_val).val_int, 8, "MULI", NULL, NULL);
                     int result = 8 * result;
                     add_to_float_list(result_list, &result_size,(float)result);
                     if((yyvsp[-1].expr_val).val_type == FLOAT_TYPE)
                        print_list_array(list, list_size, number_list, number_size, float_list, float_size,  (yyvsp[-5].ident).lexema, (yyvsp[-3].ident).lexema, (yyvsp[-1].expr_val).val_float, NULL);
                     else
                        print_list_array(list, list_size, number_list, number_size, float_list, float_size,  (yyvsp[-5].ident).lexema, (yyvsp[-3].ident).lexema, (float)(yyvsp[-1].expr_val).val_int, NULL);

                        list_size = 0;
                        number_size = 0;
                        result_size = 0;
                        float_size = 0;
                        id_size = 0;
                        mode_assign = false;

                 }
#line 1610 "bison_output/sintaxi.tab.c"
    break;

  case 21: /* expressio: ID OPENED_CLAUSE OPERATION CLOSED_CLAUSE ASSIGN OPERATION  */
#line 372 "bison_flex/sintaxi.y"
                                                                            {
                      sym_value_type existing_value;
                      int lookup_result = sym_lookup((yyvsp[-5].ident).lexema, &existing_value);
                      if ((yyvsp[-3].expr_val).val_type != INT_TYPE) {
                              fprintf(stderr, "Error: Type mismatch for index array '%s' in line %d.\n", (yyvsp[-5].ident).lexema, yylineno);
                              YYABORT;
                      }
                      if (lookup_result == SYMTAB_OK) {
                          if (existing_value.val_type != (yyvsp[0].expr_val).val_type) {
                              fprintf(stderr, "Error: Type mismatch for ID '%s' in line %d.\n", (yyvsp[-5].ident).lexema, yylineno);
                          }
                      }
                      if ((yyvsp[0].expr_val).val_type == INT_TYPE) {
                          (yyval.expr_val).val_type = INT_TYPE;
                          (yyval.expr_val).val_int = (int)(yyvsp[0].expr_val).val_int;
                          (yyvsp[-5].ident).id_val.val_type = INT_TYPE;
                          (yyvsp[-5].ident).id_val.val_int = (yyvsp[0].expr_val).val_int;

                      } else if ((yyvsp[0].expr_val).val_type == FLOAT_TYPE) {
                          (yyval.expr_val).val_type = FLOAT_TYPE;
                          (yyval.expr_val).val_float = (yyvsp[0].expr_val).val_float;
                          (yyvsp[-5].ident).id_val.val_type = FLOAT_TYPE;
                          (yyvsp[-5].ident).id_val.val_float = (yyvsp[0].expr_val).val_float;

                      }
                      if((yyvsp[-3].expr_val).id_name != NULL)
                        add_three_address_code(list, &list_size, (yyvsp[-3].expr_val).val_int, 8, "MULI", (yyvsp[-3].expr_val).id_name, NULL);
                      else
                        add_three_address_code(list, &list_size, (yyvsp[-3].expr_val).val_int, 8, "MULI", NULL, NULL);
                        int result = 8 * result;
                        add_to_float_list(result_list, &result_size,(float)result);

                      if((yyvsp[0].expr_val).val_type == FLOAT_TYPE)
                        print_list_array(list, list_size, number_list, number_size, float_list, float_size,  (yyvsp[-5].ident).lexema, (yyvsp[-3].expr_val).id_name, (yyvsp[0].expr_val).val_float, (yyvsp[0].expr_val).id_name);
                      else
                        print_list_array(list, list_size, number_list, number_size, float_list, float_size,  (yyvsp[-5].ident).lexema, (yyvsp[-3].expr_val).id_name, (float)(yyvsp[0].expr_val).val_int, (yyvsp[0].expr_val).id_name);

                      list_size = 0;
                      number_size = 0;
                      result_size = 0;
                      float_size = 0;
                      id_size = 0;
                }
#line 1658 "bison_output/sintaxi.tab.c"
    break;

  case 22: /* OPERATION: OPERATION PLUS OPERATION2  */
#line 423 "bison_flex/sintaxi.y"
                              {
        if ((yyvsp[-2].expr_val).val_type == FLOAT_TYPE || (yyvsp[0].expr_val).val_type == FLOAT_TYPE) {
            // Handle float addition
            if ((yyvsp[-2].expr_val).val_type == INT_TYPE) {
                (yyvsp[-2].expr_val).val_float = (float) (yyvsp[-2].expr_val).val_int; // Convert int to float
                add_to_float_list(result_list, &result_size,(yyvsp[-2].expr_val).val_float);
                (yyvsp[-2].expr_val).type_conversion = 1;

            }
            if ((yyvsp[0].expr_val).val_type == INT_TYPE) {
                (yyvsp[0].expr_val).val_float = (float) (yyvsp[0].expr_val).val_int; // Convert int to float
                add_to_float_list(result_list, &result_size,(yyvsp[0].expr_val).val_float);
                (yyvsp[0].expr_val).type_conversion = 1;

            }

            (yyval.expr_val).val_type = FLOAT_TYPE;
            (yyval.expr_val).val_float = (yyvsp[-2].expr_val).val_float + (yyvsp[0].expr_val).val_float;
            add_three_address_code_float(list, &list_size, (yyvsp[-2].expr_val).val_float, (yyvsp[0].expr_val).val_float, "ADDF", (yyvsp[-2].expr_val).id_name, (yyvsp[0].expr_val).id_name, (yyvsp[-2].expr_val).type_conversion, (yyvsp[0].expr_val).type_conversion);
            add_to_float_list(result_list, &result_size, (yyval.expr_val).val_float);


        } else {
            add_three_address_code(list, &list_size, (yyvsp[-2].expr_val).val_int, (yyvsp[0].expr_val).val_int, "ADDI", (yyvsp[-2].expr_val).id_name, (yyvsp[0].expr_val).id_name);
            (yyval.expr_val).val_type = INT_TYPE;
            (yyval.expr_val).val_int = (yyvsp[-2].expr_val).val_int + (yyvsp[0].expr_val).val_int;
            fprintf(stderr, " values %d, %d, %d", (yyvsp[-2].expr_val).val_int, (yyvsp[0].expr_val).val_int, (yyval.expr_val).val_int);

            add_to_float_list(result_list, &result_size, (float)(yyval.expr_val).val_int);
        }
            generate_power_logic(&power, &lines);

    }
#line 1696 "bison_output/sintaxi.tab.c"
    break;

  case 23: /* OPERATION: OPERATION MINUS OPERATION2  */
#line 456 "bison_flex/sintaxi.y"
                                 {
        if (((yyvsp[-2].expr_val).val_type == INT_TYPE || (yyvsp[-2].expr_val).val_type == FLOAT_TYPE) &&
            ((yyvsp[0].expr_val).val_type == INT_TYPE || (yyvsp[0].expr_val).val_type == FLOAT_TYPE)) {
            if ((yyvsp[-2].expr_val).val_type == FLOAT_TYPE || (yyvsp[0].expr_val).val_type == FLOAT_TYPE) {
                if ((yyvsp[-2].expr_val).val_type == INT_TYPE) {
                    (yyvsp[-2].expr_val).val_float = (float) (yyvsp[-2].expr_val).val_int;  // Convert $1 from int to float
                    add_to_float_list(result_list, &result_size,(yyvsp[-2].expr_val).val_float);
                    (yyvsp[-2].expr_val).type_conversion = 1;
                }
                if ((yyvsp[0].expr_val).val_type == INT_TYPE) {
                    (yyvsp[0].expr_val).val_float = (float) (yyvsp[0].expr_val).val_int;  // Convert $3 from int to float
                    add_to_float_list(result_list, &result_size,(yyvsp[0].expr_val).val_float);
                    (yyvsp[0].expr_val).type_conversion = 1;
                }
                add_three_address_code_float(list, &list_size, (yyvsp[-2].expr_val).val_float, (yyvsp[0].expr_val).val_float, "SUBF", (yyvsp[-2].expr_val).id_name, (yyvsp[0].expr_val).id_name, (yyvsp[-2].expr_val).type_conversion, (yyvsp[0].expr_val).type_conversion);
                (yyval.expr_val).val_type = FLOAT_TYPE;
                (yyval.expr_val).val_float = (yyvsp[-2].expr_val).val_float - (yyvsp[0].expr_val).val_float;
                add_to_float_list(result_list, &result_size,(yyval.expr_val).val_float);

            } else {
                // Both operands are integers
                add_three_address_code(list, &list_size, (yyvsp[-2].expr_val).val_int, (yyvsp[0].expr_val).val_int, "SUBI", (yyvsp[-2].expr_val).id_name, (yyvsp[0].expr_val).id_name);
                (yyval.expr_val).val_type = INT_TYPE;
                (yyval.expr_val).val_int = (yyvsp[-2].expr_val).val_int - (yyvsp[0].expr_val).val_int;
                add_to_float_list(result_list, &result_size,(float)(yyval.expr_val).val_int);

            }
            generate_power_logic(&power, &lines);

        } else {
            fprintf(stderr, "Error: Both operands must be numbers (int or float) in line %d\n", yylineno);
            YYABORT;
        }
    }
#line 1735 "bison_output/sintaxi.tab.c"
    break;

  case 25: /* OPERATION2: OPERATION2 MULTIPLY OPERATION3  */
#line 494 "bison_flex/sintaxi.y"
                                    {
        if (((yyvsp[-2].expr_val).val_type == INT_TYPE || (yyvsp[-2].expr_val).val_type == FLOAT_TYPE) &&
            ((yyvsp[0].expr_val).val_type == INT_TYPE || (yyvsp[0].expr_val).val_type == FLOAT_TYPE)) {

            if ((yyvsp[-2].expr_val).val_type == FLOAT_TYPE || (yyvsp[0].expr_val).val_type == FLOAT_TYPE) {
                if ((yyvsp[-2].expr_val).val_type == INT_TYPE) {
                    (yyvsp[-2].expr_val).val_float = (float) (yyvsp[-2].expr_val).val_int;  // Convert $1 from int to float
                    fprintf(stderr, "\n\nValue of FLOAT %f\n\n", (yyvsp[-2].expr_val).val_float);
                    add_to_float_list(result_list, &result_size,(yyvsp[-2].expr_val).val_float);
                    (yyvsp[-2].expr_val).type_conversion = 1;
                }
                if ((yyvsp[0].expr_val).val_type == INT_TYPE) {
                    (yyvsp[0].expr_val).val_float = (float) (yyvsp[0].expr_val).val_int;  // Convert $3 from int to float
                    add_to_float_list(result_list, &result_size,(yyvsp[0].expr_val).val_float);
                    (yyvsp[0].expr_val).type_conversion = 1;
                }

                (yyval.expr_val).val_type = FLOAT_TYPE;
                (yyval.expr_val).val_float = (yyvsp[-2].expr_val).val_float * (yyvsp[0].expr_val).val_float;
                add_three_address_code_float(list, &list_size, (yyvsp[-2].expr_val).val_float, (yyvsp[0].expr_val).val_float, "MULF", (yyvsp[-2].expr_val).id_name, (yyvsp[0].expr_val).id_name, (yyvsp[-2].expr_val).type_conversion, (yyvsp[0].expr_val).type_conversion);
                add_to_float_list(result_list, &result_size,(yyval.expr_val).val_float);

            } else {
                add_three_address_code(list, &list_size, (yyvsp[-2].expr_val).val_int, (yyvsp[0].expr_val).val_int, "MULI", (yyvsp[-2].expr_val).id_name, (yyvsp[0].expr_val).id_name);
                (yyval.expr_val).val_type = INT_TYPE;
                (yyval.expr_val).val_int = (yyvsp[-2].expr_val).val_int * (yyvsp[0].expr_val).val_int;
                add_to_float_list(result_list, &result_size, (float)(yyval.expr_val).val_int);


            }
            generate_power_logic(&power, &lines);
        } else {
            fprintf(stderr, "Error: Both operands must be numbers (int or float) in line %d\n", yylineno);
            YYABORT;
        }
    }
#line 1776 "bison_output/sintaxi.tab.c"
    break;

  case 26: /* OPERATION2: OPERATION2 DIVIDE OPERATION3  */
#line 530 "bison_flex/sintaxi.y"
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
                    add_to_float_list(result_list, &result_size,(yyvsp[-2].expr_val).val_float);
                    (yyvsp[-2].expr_val).type_conversion = 1;
                }
                if ((yyvsp[0].expr_val).val_type == INT_TYPE) {
                    (yyvsp[0].expr_val).val_float = (float) (yyvsp[0].expr_val).val_int;  // Convert $3 from int to float
                    add_to_float_list(result_list, &result_size,(yyvsp[0].expr_val).val_float);
                    (yyvsp[0].expr_val).type_conversion = 1;
                }
                add_three_address_code_float(list, &list_size, (yyvsp[-2].expr_val).val_float, (yyvsp[0].expr_val).val_float, "DIVF", (yyvsp[-2].expr_val).id_name, (yyvsp[0].expr_val).id_name, (yyvsp[-2].expr_val).type_conversion, (yyvsp[0].expr_val).type_conversion);
                (yyval.expr_val).val_type = FLOAT_TYPE;
                (yyval.expr_val).val_float = (yyvsp[-2].expr_val).val_float / (yyvsp[0].expr_val).val_float;
                add_to_float_list(result_list, &result_size,(yyval.expr_val).val_float);

            } else {
                if((yyvsp[-2].expr_val).val_int % (yyvsp[0].expr_val).val_int == 0){
                    add_three_address_code(list, &list_size, (yyvsp[-2].expr_val).val_int, (yyvsp[0].expr_val).val_int, "DIVI", (yyvsp[-2].expr_val).id_name, (yyvsp[0].expr_val).id_name);
                    (yyval.expr_val).val_type = INT_TYPE;
                    (yyval.expr_val).val_int = (yyvsp[-2].expr_val).val_int / (yyvsp[0].expr_val).val_int;
                    add_to_float_list(result_list, &result_size, (yyval.expr_val).val_int);

                }
                else {
                      (yyval.expr_val).val_type = FLOAT_TYPE;
                      (yyvsp[-2].expr_val).val_float = (float)(yyvsp[-2].expr_val).val_int;
                      (yyvsp[0].expr_val).val_float = (float)(yyvsp[0].expr_val).val_int;
                      (yyval.expr_val).val_float = (yyvsp[-2].expr_val).val_float / (yyvsp[0].expr_val).val_float;
                      add_to_float_list(result_list, &result_size, (yyvsp[-2].expr_val).val_float);
                      add_to_float_list(result_list, &result_size, (yyvsp[0].expr_val).val_float);
                      add_to_float_list(result_list, &result_size, (yyval.expr_val).val_float);
                      add_three_address_code_float(list, &list_size, (yyvsp[-2].expr_val).val_float, (yyvsp[0].expr_val).val_float, "DIVF", (yyvsp[-2].expr_val).id_name, (yyvsp[0].expr_val).id_name, (yyvsp[-2].expr_val).type_conversion, (yyvsp[0].expr_val).type_conversion);

                }
            }
        } else {
            fprintf(stderr, "Error: Both operands must be numbers (int or float) in line %d\n", yylineno);
            YYABORT;
        }
    }
#line 1834 "bison_output/sintaxi.tab.c"
    break;

  case 27: /* OPERATION2: OPERATION2 MOD OPERATION3  */
#line 583 "bison_flex/sintaxi.y"
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
#line 1855 "bison_output/sintaxi.tab.c"
    break;

  case 29: /* OPERATION3: OPERATION4 POWER OPERATION3  */
#line 603 "bison_flex/sintaxi.y"
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
                        char special[50];
                        snprintf(special, sizeof(special), "$t-esp0%d", esp+2);
                        char buffer[200];  // Buffer to hold the formatted output

                        // Formatting the string using snprintf
                        snprintf(buffer, sizeof(buffer), "%d : $t-esp0%d := %d\n", lines++, esp + 2, (yyvsp[0].expr_val).val_int);

                        // Appending the formatted string to the appropriate program line
                        strcat(program_lines[lines - 1], buffer);  // Append to program_lines[lines - 1]

                        print_list(list, list_size, number_list, number_size, float_list, float_size,  special);
                        snprintf(special, sizeof(special), "$t-esp0%d", ++esp+1);
                        print_list(list, list_size, number_list, number_size, float_list, float_size,  special);
                        // Formatting the string using snprintf
                        snprintf(buffer, sizeof(buffer), "%d : $t-esp0%d := 0\n", lines++, esp++);

                        // Appending the formatted string to the appropriate program line
                        strcat(program_lines[lines - 1], buffer);  // Append to program_lines[lines - 1]
                        add_three_address_code(list, &list_size, (yyvsp[-2].expr_val).val_int, (yyvsp[-2].expr_val).val_int, "MULI",  NULL, NULL);
                        snprintf(special, sizeof(special), "$t%d", list_size-1);
                        print_list(list, list_size, number_list, number_size, float_list, float_size, special);
                        list_size = 0;
                        number_size = 0;
                        float_size = 0;
                        id_size = 0;
                        result_size = 0;
                        power = yylineno;
                        add_to_float_list(result_list, &result_size,(float)(yyval.expr_val).val_int);

                    }


        }
#line 1908 "bison_output/sintaxi.tab.c"
    break;

  case 31: /* OPERATION4: SIN OPERATION4  */
#line 655 "bison_flex/sintaxi.y"
                    {
        if ((yyvsp[0].expr_val).val_type == FLOAT_TYPE) {
            (yyval.expr_val).val_type = FLOAT_TYPE;
            (yyval.expr_val).val_float = sin((yyvsp[0].expr_val).val_float);
        } else if ((yyvsp[0].expr_val).val_type == INT_TYPE) {
            (yyval.expr_val).val_type = FLOAT_TYPE;
            (yyval.expr_val).val_float = sin((yyvsp[0].expr_val).val_int);
        }
    }
#line 1922 "bison_output/sintaxi.tab.c"
    break;

  case 32: /* OPERATION4: COS OPERATION4  */
#line 664 "bison_flex/sintaxi.y"
                     {
        if ((yyvsp[0].expr_val).val_type == FLOAT_TYPE) {
            (yyval.expr_val).val_type = FLOAT_TYPE;
            (yyval.expr_val).val_float = cos((yyvsp[0].expr_val).val_float);
        } else if ((yyvsp[0].expr_val).val_type == INT_TYPE) {
            (yyval.expr_val).val_type = FLOAT_TYPE;
            (yyval.expr_val).val_float = cos((yyvsp[0].expr_val).val_int);
        }
    }
#line 1936 "bison_output/sintaxi.tab.c"
    break;

  case 33: /* OPERATION4: TAN OPERATION4  */
#line 673 "bison_flex/sintaxi.y"
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
#line 1958 "bison_output/sintaxi.tab.c"
    break;

  case 34: /* OPERATION4: LEN OPERATION4  */
#line 690 "bison_flex/sintaxi.y"
                     {
        if ((yyvsp[0].expr_val).val_type == STRING_TYPE) {
            (yyval.expr_val).val_int = strlen((yyvsp[0].expr_val).val_string);
            (yyval.expr_val).val_type = INT_TYPE;
        } else {
            fprintf(stderr, "Error: LEN operation requires a string type in line %d\n", yylineno);
            YYABORT;
        }
    }
#line 1972 "bison_output/sintaxi.tab.c"
    break;

  case 35: /* OPERATION4: SUBSTR OPEN_PARENTHESIS OPERATION4 OPERATION4 OPERATION4 CLOSED_PARENTHESIS  */
#line 700 "bison_flex/sintaxi.y"
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
#line 2022 "bison_output/sintaxi.tab.c"
    break;

  case 36: /* OPERATION4: INTEGER  */
#line 746 "bison_flex/sintaxi.y"
              {
            number_list[number_size] = (yyvsp[0].enter);
            number_size++;
            (yyval.expr_val).val_type = INT_TYPE;
            (yyval.expr_val).val_int = (yyvsp[0].enter);

        }
#line 2034 "bison_output/sintaxi.tab.c"
    break;

  case 37: /* OPERATION4: FLOAT  */
#line 753 "bison_flex/sintaxi.y"
            {
            fprintf(yyout, "float");
            add_to_float_list(float_list, &float_size, (yyvsp[0].real));
            (yyval.expr_val).val_type = FLOAT_TYPE;
            (yyval.expr_val).val_float = (yyvsp[0].real);
        }
#line 2045 "bison_output/sintaxi.tab.c"
    break;

  case 38: /* OPERATION4: STRING  */
#line 759 "bison_flex/sintaxi.y"
             {
                (yyval.expr_val).val_type = STRING_TYPE;
                (yyval.expr_val).val_string = (yyvsp[0].cadena);
        }
#line 2054 "bison_output/sintaxi.tab.c"
    break;

  case 39: /* OPERATION4: ID  */
#line 763 "bison_flex/sintaxi.y"
         {
            sym_value_type value;
            int lookup_result;

            /* Call sym_lookup to find the identifier in the symbol table */
            lookup_result = sym_lookup((yyvsp[0].ident).lexema, &value);

            if (lookup_result == SYMTAB_OK) {
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
                (yyval.expr_val).id_name = (yyvsp[0].ident).lexema;
                id_list[id_size]= (yyvsp[0].ident).lexema;
                id_size++;
            } else {
                fprintf(stderr, "Error: ID '%s' not declared\n", (yyvsp[0].ident).lexema);
                exit(EXIT_FAILURE);  // Exit the program
            }
        }
#line 2085 "bison_output/sintaxi.tab.c"
    break;

  case 40: /* OPERATION4: MINUS ID  */
#line 789 "bison_flex/sintaxi.y"
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
#line 2115 "bison_output/sintaxi.tab.c"
    break;

  case 41: /* OPERATION4: OPEN_PARENTHESIS OPERATION CLOSED_PARENTHESIS  */
#line 814 "bison_flex/sintaxi.y"
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
#line 2136 "bison_output/sintaxi.tab.c"
    break;

  case 42: /* OPERATION_BOOLEAN: OPERATION_BOOLEAN OR OPERATION_BOOLEAN1  */
#line 833 "bison_flex/sintaxi.y"
                                           {
                                (yyval.expr_val).val_type = BOOL_TYPE;
                                if ((yyvsp[-2].expr_val).val_type == BOOL_TYPE && (yyvsp[0].expr_val).val_type == BOOL_TYPE) {
                                (yyval.expr_val).val_bool = (yyvsp[-2].expr_val).val_bool || (yyvsp[0].expr_val).val_bool;
                                }

    }
#line 2148 "bison_output/sintaxi.tab.c"
    break;

  case 45: /* OPERATION_BOOLEAN1: OPERATION_BOOLEAN1 AND OPERATION_BOOLEAN2  */
#line 844 "bison_flex/sintaxi.y"
                                               {
            (yyval.expr_val).val_type = BOOL_TYPE;
            if ((yyvsp[-2].expr_val).val_type == BOOL_TYPE && (yyvsp[0].expr_val).val_type == BOOL_TYPE) {
                (yyval.expr_val).val_bool = (yyvsp[-2].expr_val).val_bool && (yyvsp[0].expr_val).val_bool;
            }

    }
#line 2160 "bison_output/sintaxi.tab.c"
    break;

  case 47: /* OPERATION_BOOLEAN2: NOT OPERATION_BOOLEAN2  */
#line 853 "bison_flex/sintaxi.y"
                            {
            (yyval.expr_val).val_type = BOOL_TYPE;
            if ((yyvsp[0].expr_val).val_type == BOOL_TYPE) {
                (yyval.expr_val).val_bool = !(yyvsp[0].expr_val).val_bool;
            }
    }
#line 2171 "bison_output/sintaxi.tab.c"
    break;

  case 48: /* OPERATION_BOOLEAN3: OPEN_PARENTHESIS OPERATION_BOOLEAN CLOSED_PARENTHESIS  */
#line 860 "bison_flex/sintaxi.y"
                                                          {
            (yyval.expr_val).val_type = (yyvsp[-1].expr_val).val_type;
            if ((yyvsp[-1].expr_val).val_type == BOOL_TYPE) {
                (yyval.expr_val).val_bool = (yyvsp[-1].expr_val).val_bool;
            } else {
                (yyval.expr_val).val_bool = (yyvsp[-1].expr_val).val_bool;
            }
        }
#line 2184 "bison_output/sintaxi.tab.c"
    break;

  case 49: /* OPERATION_BOOLEAN3: TRUE  */
#line 868 "bison_flex/sintaxi.y"
           {
            (yyval.expr_val).val_type = BOOL_TYPE;
            (yyval.expr_val).val_bool = true;  // Use bool `true` instead of string "true"

    }
#line 2194 "bison_output/sintaxi.tab.c"
    break;

  case 50: /* OPERATION_BOOLEAN3: ID_BOOL  */
#line 873 "bison_flex/sintaxi.y"
              {
        sym_value_type value;
        int lookup_result;
        /* Call sym_lookup to find the identifier in the symbol table */
        lookup_result = sym_lookup((yyvsp[0].ident).lexema, &value);
        if (lookup_result == SYMTAB_OK) {
            (yyval.expr_val).val_type = value.val_type;  // Store the value for later use
            (yyval.expr_val).val_bool = value.val_bool;
        }


        generate_if_statement_simple((yyval.expr_val).val_bool, 1, "EQ");


    }
#line 2214 "bison_output/sintaxi.tab.c"
    break;

  case 51: /* OPERATION_BOOLEAN3: FALSE  */
#line 888 "bison_flex/sintaxi.y"
            {
            (yyval.expr_val).val_type = BOOL_TYPE;
            (yyval.expr_val).val_bool = false;  // Use bool `false` instead of string "false"
     }
#line 2223 "bison_output/sintaxi.tab.c"
    break;

  case 52: /* OPERATION_BOOLEAN3: OPERATION EQUAL OPERATION  */
#line 892 "bison_flex/sintaxi.y"
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
             generate_if_statement((yyvsp[-2].expr_val), (yyvsp[0].expr_val), "EQ", 0);

         } else {
             (yyval.expr_val).val_bool = (yyvsp[-2].expr_val).val_int == (yyvsp[0].expr_val).val_int;
             generate_if_statement((yyvsp[-2].expr_val), (yyvsp[0].expr_val), "EQ", 1);

         }
    }
#line 2246 "bison_output/sintaxi.tab.c"
    break;

  case 53: /* OPERATION_BOOLEAN3: OPERATION NOT_EQUAL OPERATION  */
#line 910 "bison_flex/sintaxi.y"
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
                 generate_if_statement((yyvsp[-2].expr_val), (yyvsp[0].expr_val), "NE", 0);

             } else {
                 (yyval.expr_val).val_bool = (yyvsp[-2].expr_val).val_int != (yyvsp[0].expr_val).val_int;
             generate_if_statement((yyvsp[-2].expr_val), (yyvsp[0].expr_val), "NE", 1);

             }
         }
#line 2269 "bison_output/sintaxi.tab.c"
    break;

  case 54: /* OPERATION_BOOLEAN3: OPERATION GREATER_EQUAL OPERATION  */
#line 928 "bison_flex/sintaxi.y"
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
                 generate_if_statement((yyvsp[-2].expr_val), (yyvsp[0].expr_val), "GTE", 0);
             }
             generate_if_statement((yyvsp[-2].expr_val), (yyvsp[0].expr_val), "GTE", 1);
         }
#line 2290 "bison_output/sintaxi.tab.c"
    break;

  case 55: /* OPERATION_BOOLEAN3: OPERATION GREATER_THAN OPERATION  */
#line 944 "bison_flex/sintaxi.y"
                                       {
         (yyval.expr_val).val_type = BOOL_TYPE;
         if ((yyvsp[-2].expr_val).val_type == FLOAT_TYPE || (yyvsp[0].expr_val).val_type == FLOAT_TYPE) {
             if ((yyvsp[-2].expr_val).val_type == INT_TYPE) {
                 (yyvsp[-2].expr_val).val_float = (float) (yyvsp[-2].expr_val).val_int;  // Convert $1 from int to float
             }
             if ((yyvsp[0].expr_val).val_type == INT_TYPE) {
                 (yyvsp[0].expr_val).val_float = (float) (yyvsp[0].expr_val).val_int;  // Convert $3 from int to float
             }
             (yyval.expr_val).val_bool = (yyvsp[-2].expr_val).val_float > (yyvsp[0].expr_val).val_float;
             generate_if_statement((yyvsp[-2].expr_val), (yyvsp[0].expr_val), "GTF", 0);

         } else {
             (yyval.expr_val).val_bool = (yyvsp[-2].expr_val).val_int > (yyvsp[0].expr_val).val_int;
             generate_if_statement((yyvsp[-2].expr_val), (yyvsp[0].expr_val), "GTI", 1);

         }

    }
#line 2314 "bison_output/sintaxi.tab.c"
    break;

  case 56: /* OPERATION_BOOLEAN3: OPERATION LESS_THAN OPERATION  */
#line 963 "bison_flex/sintaxi.y"
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
             generate_if_statement((yyvsp[-2].expr_val), (yyvsp[0].expr_val), "LTF", 0);
         } else {
             (yyval.expr_val).val_bool = (yyvsp[-2].expr_val).val_int < (yyvsp[0].expr_val).val_int;
             generate_if_statement((yyvsp[-2].expr_val), (yyvsp[0].expr_val), "LTI", 1);
         }
    }
#line 2335 "bison_output/sintaxi.tab.c"
    break;

  case 57: /* OPERATION_BOOLEAN3: OPERATION LESS_EQUAL OPERATION  */
#line 979 "bison_flex/sintaxi.y"
                                     {
         (yyval.expr_val).val_type = BOOL_TYPE;
         if ((yyvsp[-2].expr_val).val_type == FLOAT_TYPE || (yyvsp[0].expr_val).val_type == FLOAT_TYPE) {
             if ((yyvsp[-2].expr_val).val_type == INT_TYPE) {
                 (yyvsp[-2].expr_val).val_float = (float) (yyvsp[-2].expr_val).val_int;  // Convert $1 from int to float
             }
             if ((yyvsp[0].expr_val).val_type == INT_TYPE) {
                 (yyvsp[0].expr_val).val_float = (float) (yyvsp[0].expr_val).val_int;  // Convert $3 from int to float
             }
             (yyval.expr_val).val_bool = (yyvsp[-2].expr_val).val_float <= (yyvsp[0].expr_val).val_float;
             generate_if_statement((yyvsp[-2].expr_val), (yyvsp[0].expr_val), "LTE", 0);
         } else {
             (yyval.expr_val).val_bool = (yyvsp[-2].expr_val).val_int <= (yyvsp[0].expr_val).val_int;
             generate_if_statement((yyvsp[-2].expr_val), (yyvsp[0].expr_val), "LTE", 1);

         }

    }
#line 2358 "bison_output/sintaxi.tab.c"
    break;


#line 2362 "bison_output/sintaxi.tab.c"

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

#line 998 "bison_flex/sintaxi.y"


