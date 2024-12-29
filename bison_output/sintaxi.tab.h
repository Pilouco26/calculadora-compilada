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

#ifndef YY_YY_BISON_OUTPUT_SINTAXI_TAB_H_INCLUDED
# define YY_YY_BISON_OUTPUT_SINTAXI_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 41 "bison_flex/sintaxi.y"

  #include "../header_files/dades.h"
  #include "../header_files/funcions.h"
  #include "../header_files/funcions_ca3.h"

#line 55 "bison_output/sintaxi.tab.h"

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
    MODE = 261,                    /* MODE  */
    FLOAT = 262,                   /* FLOAT  */
    ID = 263,                      /* ID  */
    ID_BOOL = 264,                 /* ID_BOOL  */
    STRING = 265,                  /* STRING  */
    FOR = 266,                     /* FOR  */
    IN = 267,                      /* IN  */
    UNTIL = 268,                   /* UNTIL  */
    WHILE = 269,                   /* WHILE  */
    ELSE = 270,                    /* ELSE  */
    IF = 271,                      /* IF  */
    THEN = 272,                    /* THEN  */
    FI = 273,                      /* FI  */
    EXTRALINE = 274,               /* EXTRALINE  */
    DO = 275,                      /* DO  */
    DONE = 276,                    /* DONE  */
    OPENED_CLAUSE = 277,           /* OPENED_CLAUSE  */
    CLOSED_CLAUSE = 278,           /* CLOSED_CLAUSE  */
    COMMENT = 279,                 /* COMMENT  */
    SUBSTR = 280,                  /* SUBSTR  */
    COMMA = 281,                   /* COMMA  */
    LEN = 282,                     /* LEN  */
    SIN = 283,                     /* SIN  */
    COS = 284,                     /* COS  */
    TAN = 285,                     /* TAN  */
    AND = 286,                     /* AND  */
    OR = 287,                      /* OR  */
    NOT = 288,                     /* NOT  */
    PLUS = 289,                    /* PLUS  */
    MINUS = 290,                   /* MINUS  */
    MULTIPLY = 291,                /* MULTIPLY  */
    DIVIDE = 292,                  /* DIVIDE  */
    MOD = 293,                     /* MOD  */
    POWER = 294,                   /* POWER  */
    CLOSED_PARENTHESIS = 295,      /* CLOSED_PARENTHESIS  */
    OPEN_PARENTHESIS = 296,        /* OPEN_PARENTHESIS  */
    ASSIGN = 297,                  /* ASSIGN  */
    ENDLINE = 298,                 /* ENDLINE  */
    SEMICOLON = 299,               /* SEMICOLON  */
    GREATER_THAN = 300,            /* GREATER_THAN  */
    GREATER_EQUAL = 301,           /* GREATER_EQUAL  */
    LESS_THAN = 302,               /* LESS_THAN  */
    LESS_EQUAL = 303,              /* LESS_EQUAL  */
    EQUAL = 304,                   /* EQUAL  */
    NOT_EQUAL = 305,               /* NOT_EQUAL  */
    REPEAT = 306                   /* REPEAT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 47 "bison_flex/sintaxi.y"

    struct {
        char *lexema;
        int length;
        int line;
        value_info id_val;
    } ident;
    struct {
            char *representacio;
            bool set;
    } mode;
    int enter;
    float real;
    value_info expr_val;
    void *sense_valor;
    char *cadena;
    bool boolean;
    expression_list expr_list;
    heading header;

#line 144 "bison_output/sintaxi.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_BISON_OUTPUT_SINTAXI_TAB_H_INCLUDED  */
