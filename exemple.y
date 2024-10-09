
%{
#include <stdio.h>
#include <stdlib.h>

extern FILE *yyout;
extern int yylineno;
extern int yylex();
/*extern void yyerror(char*);*/
%}

%code requires {
  #include "exemple_dades.h"
  #include "exemple_funcions.h"
}

%union {
    struct {
        char *lexema;
        int length;
        int line;
        value_info id_val;
    } ident;
    int enter;
    float real;
    double number;
    value_info expr_val;
    void *sense_valor;
    char cadena;
}

%token <sense_valor> ASSIGN ENDLINE SEMICOLON
%token <enter> INTEGER
%token <real> FLOAT
%token <ident> ID
%token <cadena> STRING
%token <sense_valor> PLUS MINUS MULTIPLY DIVIDE

%type <sense_valor> programa
%type <expr_val> expressio
%type <expr_val> OPERATION
%type <expr_val> OPERATION2
%type <expr_val> OPERATION3


%start programa

%%


programa : expressio_list {
             fprintf(yyout, "End of input reached.\n");
           }

expressio_list : expressio ENDLINE {
                  fprintf(yyout, "expressio_list -> expressio ENDLINE\n");
                }
                | expressio ENDLINE expressio_list {
                  fprintf(yyout, "expressio_list -> expressio ENDLINE expressio_list\n");
                }
                ;

expressio : ID ASSIGN INTEGER  {
              fprintf(yyout, "ID: %s pren per valor: %d\n", $1.lexema, $3);
              $$.val_type = INT_TYPE;
              $$.val_int = $3;
            }
            | ID ASSIGN FLOAT  {
                fprintf(yyout, "ID: %s pren per valor: %f\n", $1.lexema, $3);
                $$.val_type = FLOAT_TYPE;
                $$.val_float = $3;
            }
            | ID ASSIGN OPERATION  {
              if ($3.val_type == INT_TYPE) {
                  fprintf(yyout, "ID: %s pren per valor: %d\n", $1.lexema, (int)$3.val_int);
                  $3.val_type = INT_TYPE;
                  $3.val_int = (int)$3.val_int;
              } else {
                  fprintf(yyout, "ID: %s pren per valor: %f\n", $1.lexema, $3.val_float);
                  $3.val_type = FLOAT_TYPE;
                  $3.val_float = $3.val_int;
              }
            }


OPERATION:
    OPERATION PLUS OPERATION2 {
        if ($1.val_type == FLOAT_TYPE || $3.val_type == FLOAT_TYPE) {
            // Ensure both operands are treated as floats
            if ($1.val_type == INT_TYPE) {
                $1.val_float = (float) $1.val_int;  // Convert $1 from int to float
            }
            if ($3.val_type == INT_TYPE) {
                $3.val_float = (float) $3.val_int;  // Convert $3 from int to float
            }

            $$.val_type = FLOAT_TYPE;
            $$.val_float = $1.val_float + $3.val_float;
        } else {
            // Both operands are integers
            $$.val_type = INT_TYPE;
            $$.val_int = $1.val_int + $3.val_int;
        }
    }
    | OPERATION MINUS OPERATION2 {
        if ($1.val_type == FLOAT_TYPE || $3.val_type == FLOAT_TYPE) {
            if ($1.val_type == INT_TYPE) {
                $1.val_float = (float) $1.val_int;  // Convert $1 from int to float
            }
            if ($3.val_type == INT_TYPE) {
                $3.val_float = (float) $3.val_int;  // Convert $3 from int to float
            }

            $$.val_type = FLOAT_TYPE;
            $$.val_float = $1.val_float - $3.val_float;
        } else {
            // Both operands are integers
            $$.val_type = INT_TYPE;
            $$.val_int = $1.val_int - $3.val_int;
        }
    }
    | OPERATION2
    ;

OPERATION2:
    OPERATION2 MULTIPLY OPERATION3 {
        if ($1.val_type == FLOAT_TYPE || $3.val_type == FLOAT_TYPE) {
            if ($1.val_type == INT_TYPE) {
                $1.val_float = (float) $1.val_int;  // Convert $1 from int to float
            }
            if ($3.val_type == INT_TYPE) {
                $3.val_float = (float) $3.val_int;  // Convert $3 from int to float
            }

            $$.val_type = FLOAT_TYPE;
            $$.val_float = $1.val_float * $3.val_float;
        } else {
            // Both operands are integers
            $$.val_type = INT_TYPE;
            $$.val_int = $1.val_int * $3.val_int;
        }
    }
    | OPERATION2 DIVIDE OPERATION3 {
        if ($1.val_type == FLOAT_TYPE || $3.val_type == FLOAT_TYPE) {
            if ($1.val_type == INT_TYPE) {
                $1.val_float = (float) $1.val_int;  // Convert $1 from int to float
            }
            if ($3.val_type == INT_TYPE) {
                $3.val_float = (float) $3.val_int;  // Convert $3 from int to float
            }

            $$.val_type = FLOAT_TYPE;
            $$.val_float = $1.val_float / $3.val_float;
        } else {
            // Both operands are integers
            $$.val_type = INT_TYPE;
            $$.val_int = $1.val_int / $3.val_int;
        }
    }
    | OPERATION3
    ;

OPERATION3:
    INTEGER{$$.val_type = INT_TYPE;
                    $$.val_int = $1;} | OPERATION | FLOAT{$$.val_type = FLOAT_TYPE;
                                                                  $$.val_float = $1;}


%%

