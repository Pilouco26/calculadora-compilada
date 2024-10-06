%{

#include <stdio.h>
#include <stdlib.h>

extern FILE *yyout;
extern int yylineno;
extern int yylex();
/*extern void yyerror(char*);*/

%}

%code requires {
  /* Les definicions que s'utilitzen al %union han d'estar aqui */
  #include "exemple_dades.h"
  #include "exemple_funcions.h"
}

%union{
    struct {
        char *lexema;
        int lenght;
        int line;
        value_info id_val;
    } ident;
    int enter;
    float real;
    value_info expr_val;
    void *sense_valor;
    char cadena;
}

%token <sense_valor> ASSIGN ENDLINE SEMICOLON
%token <enter> INTEGER
%token <ident> ID
%token <cadena> STRING
%token <sense_valor> PLUS MINUS MULTIPLY DIVIDE

%type <sense_valor> programa
%type <expr_val> expressio
%type <enter> OPERATION

%start programa

%%

programa : expressio_list {
             fprintf(yyout, "programa -> expressio_list\n");
           }

expressio_list : expressio ENDLINE {
                   fprintf(yyout, "expressio_list -> expressio\n");
                }
               | expressio_list expressio ENDLINE {
                   fprintf(yyout, "expressio_list -> expressio_list expressio\n");
                }

expressio : ID ASSIGN INTEGER {
              fprintf(yyout, "ID: %s pren per valor: %d\n", $1.lexema, $3);
              $$.val_type = INT_TYPE;
              $$.val_int = $3;
            }
            | ID ASSIGN OPERATION {
              fprintf(yyout, "ID: %s pren per valor: %d\n", $1.lexema, $3);
              $$.val_type = INT_TYPE;
              $$.val_int = $3;
            }
            ;

OPERATION:
    OPERATION PLUS INTEGER {
        $$ = $1 + $3;
        fprintf(yyout, "Debug: %d + %d = %d\n", $1, $3, $$);
    }
    | OPERATION MINUS INTEGER {
        $$ = $1 - $3;
        fprintf(yyout, "Debug: %d - %d = %d\n", $1, $3, $$);
    }
    | OPERATION MULTIPLY INTEGER {
        $$ = $1 * $3;
        fprintf(yyout, "Debug: %d * %d = %d\n", $1, $3, $$);
    }
    | OPERATION DIVIDE INTEGER {
        $$ = $1 / $3;
        fprintf(yyout, "Debug: %d / %d = %d\n", $1, $3, $$);
    }
    | INTEGER PLUS INTEGER {
        $$ = $1 + $3;
        fprintf(yyout, "Debug: %d + %d = %d\n", $1, $3, $$);
    }
    | INTEGER MINUS INTEGER {
        $$ = $1 - $3;
        fprintf(yyout, "Debug: %d - %d = %d\n", $1, $3, $$);
    }
    | INTEGER MULTIPLY INTEGER {
        $$ = $1 * $3;
        fprintf(yyout, "Debug: %d * %d = %d\n", $1, $3, $$);
    }
    | INTEGER DIVIDE INTEGER {
        $$ = $1 / $3;
        fprintf(yyout, "Debug: %d / %d = %d\n", $1, $3, $$);
    }
    ;


%%
