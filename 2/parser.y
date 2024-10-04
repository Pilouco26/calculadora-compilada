%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"
%}

%union {
  int ival;
  float fval;
  char *sval;
  int bval;
  int expr_val;  // Assuming expression evaluates to an int for simplicity
}

%token <ival> INTEGER
%token <fval> REAL
%token <sval> STRING IDENTIFIER
%token <bval> BOOLEAN
%type <expr_val> expression

%left '+' '-'
%left '*' '/'
%right '^'

%%
program: statement_list { /* handle program */ }
;

statement_list: statement
              | statement_list statement
;

statement: expression ';' { /* handle expression */ }
         | IDENTIFIER ":=" expression ';' { /* handle assignment */ }
;

expression: INTEGER { $$ = $1; }
          | REAL { $$ = $1; }
          | STRING { $$ = $1; }
          | BOOLEAN { $$ = $1; }
          | IDENTIFIER { $$ = lookup($1); }
          | expression '+' expression { $$ = $1 + $3; }
          | expression '-' expression { $$ = $1 - $3; }
          | expression '*' expression { $$ = $1 * $3; }
          | expression '/' expression { $$ = $1 / $3; }
          | '(' expression ')' { $$ = $2; }
;
%%
