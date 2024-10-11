/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_EXEMPLE_TAB_H_INCLUDED
# define YY_YY_EXEMPLE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 15 "exemple.y"

  #include "exemple_dades.h"
  #include "exemple_funcions.h"

#line 54 "exemple.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INTEGER = 258,                 /* INTEGER  */
    FALSE = 259,                   /* FALSE  */
    TRUE = 260,                    /* TRUE  */
    FLOAT = 261,                   /* FLOAT  */
    ID = 262,                      /* ID  */
    STRING = 263,                  /* STRING  */
    AND = 264,                     /* AND  */
    OR = 265,                      /* OR  */
    NOT = 266,                     /* NOT  */
    PLUS = 267,                    /* PLUS  */
    MINUS = 268,                   /* MINUS  */
    MULTIPLY = 269,                /* MULTIPLY  */
    DIVIDE = 270,                  /* DIVIDE  */
    MOD = 271,                     /* MOD  */
    POWER = 272,                   /* POWER  */
    CLOSED_PARENTHESIS = 273,      /* CLOSED_PARENTHESIS  */
    OPEN_PARENTHESIS = 274,        /* OPEN_PARENTHESIS  */
    ASSIGN = 275,                  /* ASSIGN  */
    ENDLINE = 276,                 /* ENDLINE  */
    SEMICOLON = 277,               /* SEMICOLON  */
    GREATER_THAN = 278,            /* GREATER_THAN  */
    GREATER_EQUAL = 279,           /* GREATER_EQUAL  */
    LESS_THAN = 280,               /* LESS_THAN  */
    LESS_EQUAL = 281,              /* LESS_EQUAL  */
    EQUAL = 282,                   /* EQUAL  */
    NOT_EQUAL = 283                /* NOT_EQUAL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "exemple.y"

    struct {
        char *lexema;
        int length;
        int line;
        value_info id_val;
    } ident;
    int enter;
    float real;
    value_info expr_val;
    void *sense_valor;
    char *cadena;
    bool boolean;

#line 114 "exemple.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_EXEMPLE_TAB_H_INCLUDED  */
