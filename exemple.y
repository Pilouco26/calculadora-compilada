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
}

%token <sense_valor> ASSIGN ENDLINE PLUS
%token <enter> INTEGER
%token <ident> ID

%type <sense_valor> programa
%type <expr_val> expressio

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
          | expressio PLUS expressio {
              fprintf(yyout, "expressio -> expressio + expressio : %d + %d = %d\n", $1.val_int, $3.val_int, $1.val_int + $3.val_int);
              $$.val_type = INT_TYPE;
              $$.val_int = $1.val_int + $3.val_int;
            }

%%
