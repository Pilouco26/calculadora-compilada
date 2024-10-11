
%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

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
    value_info expr_val;
    void *sense_valor;
    char *cadena;
    bool boolean;
}

%token <enter> INTEGER
%token <boolean> FALSE TRUE
%token <real> FLOAT
%token <ident> ID
%token <cadena> STRING
%token <sense_valor> SIN COS TAN AND OR NOT PLUS MINUS MULTIPLY DIVIDE MOD POWER CLOSED_PARENTHESIS OPEN_PARENTHESIS ASSIGN ENDLINE SEMICOLON GREATER_THAN GREATER_EQUAL LESS_THAN LESS_EQUAL EQUAL NOT_EQUAL
%type <sense_valor> programa
%type <expr_val> expressio OPERATION OPERATION2 OPERATION3 OPERATION4 OPERATION_BOOLEAN1 OPERATION_BOOLEAN2 OPERATION_BOOLEAN3 OPERATION_BOOLEAN


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

expressio :   ID ASSIGN OPERATION  {
                  if ($3.val_type == INT_TYPE) {
                      fprintf(yyout, "ID: %s (int) pren per valor: %d\n", $1.lexema, (int)$3.val_int);
                      $3.val_type = INT_TYPE;
                      $3.val_int = (int)$3.val_int;
                  } else if($3.val_type == FLOAT_TYPE){
                      fprintf(yyout, "ID: %s (real) pren per valor: %f\n", $1.lexema, $3.val_float);
                      $3.val_type = FLOAT_TYPE;
                      $3.val_float = $3.val_int;
                  }
                  else{
                       fprintf(yyout, "ID: %s (string) pren per valor: %s\n", $1.lexema, $3.val_string);
                       $$.val_type = STRING_TYPE;
                       $$.val_string = $3.val_string;
                  }
                }
                | ID ASSIGN OPERATION_BOOLEAN {
                            fprintf(yyout, "ID: %s (bool) pren per valor: %s\n", $1.lexema, $3.val_bool ? "true" : "false");

                            $$.val_type = BOOL_TYPE;
                            $$.val_bool = $3.val_bool;
                }



OPERATION:
    OPERATION PLUS OPERATION2 {
        if ($1.val_type == STRING_TYPE || $3.val_type == STRING_TYPE) {
            // One or both operands are strings, we need to concatenate them
            char* result;

            // Allocate enough space for the concatenated string
            // +1 for the null terminator
            result = (char*) malloc(strlen($1.val_string) + strlen($3.val_string) + 1);
            if (!result) {
                fprintf(stderr, "Error: Memory allocation failed\n");
                exit(1);
            }

            // Copy the first string and concatenate the second one
            strcpy(result, $1.val_string);
            strcat(result, $3.val_string);

            $$.val_type = STRING_TYPE;
            $$.val_string = result;

        } else if ($1.val_type == FLOAT_TYPE || $3.val_type == FLOAT_TYPE) {
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
    | OPERATION2 MOD OPERATION3 {

    //NOMES PER INT
            if ($1.val_type == INT_TYPE || $3.val_type == INT_TYPE) {
                // Both operands are integers
                $$.val_type = INT_TYPE;
                $$.val_int = $1.val_int % $3.val_int;
            }
        }
    | OPERATION3
    ;

OPERATION3:
    OPERATION3 POWER OPERATION4 {
            if ($1.val_type == FLOAT_TYPE || $3.val_type == FLOAT_TYPE) {
                        if ($1.val_type == INT_TYPE) {
                            $1.val_float = (float) $1.val_int;  // Convert $1 from int to float
                        }
                        if ($3.val_type == INT_TYPE) {
                            $3.val_float = (float) $3.val_int;  // Convert $3 from int to float
                        }

                        $$.val_type = FLOAT_TYPE;
                        $$.val_float = pow($1.val_float, $3.val_float);
                    } else {
                        // Both operands are integers
                        $$.val_type = INT_TYPE;
                        $$.val_int = pow($1.val_int,$3.val_int);
                    }
        }
    | OPERATION4
       ;
OPERATION4:
        SIN OPERATION3 {
            if( $2.val_type == FLOAT_TYPE  ) {
                $$.val_type = FLOAT_TYPE;
                $$.val_float = sin($2.val_float);  // Casting the result of sin($2) to an integer
            }
            else if($2.val_type == INT_TYPE) {
                $$.val_type = FLOAT_TYPE;
                $$.val_float = sin($2.val_int);  // Casting the result of sin($2) to an integer
            }

        }
        | COS OPERATION3 {
            if( $2.val_type == FLOAT_TYPE  ) {
                printf("Evaluating COS(%d)\n", $2.val_float);
                $$.val_type = FLOAT_TYPE;
                $$.val_float = cos($2.val_float);  // Casting the result of sin($2) to an integer
            }
            else if($2.val_type == INT_TYPE) {
                printf("Evaluating COS(%d)\n", $2.val_int);
                $$.val_type = FLOAT_TYPE;
                $$.val_float = cos($2.val_int);  // Casting the result of sin($2) to an integer
            }

        }
        | TAN OPERATION3 {
            if( $2.val_type == FLOAT_TYPE  ) {
                $$.val_type = FLOAT_TYPE;
                $$.val_float = cos($2.val_float);  // Casting the result of sin($2) to an integer
            }
            else if($2.val_type == INT_TYPE) {
                $$.val_type = FLOAT_TYPE;
                $$.val_float = cos($2.val_int);  // Casting the result of sin($2) to an integer
            }
        }
        | INTEGER {
            $$.val_type = INT_TYPE;
            $$.val_int = $1;
        }
        | FLOAT {
            $$.val_type = FLOAT_TYPE;
            $$.val_float = $1;
        }
        | STRING {
                $$.val_type = STRING_TYPE;
                $$.val_string = $1;
        }
        | OPEN_PARENTHESIS OPERATION CLOSED_PARENTHESIS {
            $$.val_type = $2.val_type;
            if ($2.val_type == INT_TYPE) {
                $$.val_int = $2.val_int;
            } else {
                $$.val_float = $2.val_float;
            }
        }
;

OPERATION_BOOLEAN:
    OPERATION_BOOLEAN OR OPERATION_BOOLEAN1{
                                $$.val_type = BOOL_TYPE;
                                if ($1.val_type == BOOL_TYPE && $3.val_type == BOOL_TYPE) {
                                    $$.val_bool = $1.val_bool || $3.val_bool; }
    }
    | OPERATION_BOOLEAN1
;
OPERATION_BOOLEAN1:
    OPERATION_BOOLEAN2
    | OPERATION_BOOLEAN1 AND OPERATION_BOOLEAN2{
            $$.val_type = BOOL_TYPE;
            if ($1.val_type == BOOL_TYPE && $3.val_type == BOOL_TYPE) {
                $$.val_bool = $1.val_bool && $3.val_bool;
            }
    }
OPERATION_BOOLEAN2:
    OPERATION_BOOLEAN3
    | NOT OPERATION_BOOLEAN2{
            $$.val_type = BOOL_TYPE;
            if ($2.val_type == BOOL_TYPE) {
                $$.val_bool = !$2.val_bool;
            }
    }
OPERATION_BOOLEAN3:
    OPEN_PARENTHESIS OPERATION_BOOLEAN CLOSED_PARENTHESIS {
            $$.val_type = $2.val_type;
            if ($2.val_type == BOOL_TYPE) {
                $$.val_bool = $2.val_bool;
            } else {
                $$.val_bool = $2.val_bool;
            }
        }
    | TRUE {
            $$.val_type = BOOL_TYPE;
            $$.val_bool = true;  // Use bool `true` instead of string "true"

            // Debug print
            fprintf(stderr, "Debug: TRUE encountered, val_bool set to true\n");
        }
    | FALSE {
            $$.val_type = BOOL_TYPE;
            $$.val_bool = false;  // Use bool `false` instead of string "false"

            // Debug print
            fprintf(stderr, "Debug: FALSE encountered, val_bool set to false\n");
     }
     | OPERATION EQUAL OPERATION {
                     $$.val_type = BOOL_TYPE;
                     if ($1.val_type == FLOAT_TYPE || $3.val_type == FLOAT_TYPE) {
                         if ($1.val_type == INT_TYPE) {
                             $1.val_float = (float) $1.val_int;  // Convert $1 from int to float
                         }
                         if ($3.val_type == INT_TYPE) {
                             $3.val_float = (float) $3.val_int;  // Convert $3 from int to float
                         }
                         $$.val_bool = $1.val_float == $3.val_float;
                     } else {
                         $$.val_bool = $1.val_int == $3.val_int;
                     }
         }
         | OPERATION NOT_EQUAL OPERATION {
                         $$.val_type = BOOL_TYPE;
                         if ($1.val_type == FLOAT_TYPE || $3.val_type == FLOAT_TYPE) {
                             if ($1.val_type == INT_TYPE) {
                                 $1.val_float = (float) $1.val_int;  // Convert $1 from int to float
                             }
                             if ($3.val_type == INT_TYPE) {
                                 $3.val_float = (float) $3.val_int;  // Convert $3 from int to float
                             }
                             $$.val_bool = $1.val_float != $3.val_float;
                         } else {
                             $$.val_bool = $1.val_int != $3.val_int;
                         }
         }
         | OPERATION GREATER_EQUAL OPERATION {
                                             $$.val_type = BOOL_TYPE;
                                             if ($1.val_type == FLOAT_TYPE || $3.val_type == FLOAT_TYPE) {
                                                 if ($1.val_type == INT_TYPE) {
                                                     $1.val_float = (float) $1.val_int;  // Convert $1 from int to float
                                                 }
                                                 if ($3.val_type == INT_TYPE) {
                                                     $3.val_float = (float) $3.val_int;  // Convert $3 from int to float
                                                 }
                                                 $$.val_bool = $1.val_float >= $3.val_float;
                                             } else {
                                                 $$.val_bool = $1.val_int >= $3.val_int;
                                             }
         }
         | OPERATION GREATER_THAN OPERATION {
                             $$.val_type = BOOL_TYPE;
                             if ($1.val_type == FLOAT_TYPE || $3.val_type == FLOAT_TYPE) {
                                 if ($1.val_type == INT_TYPE) {
                                     $1.val_float = (float) $1.val_int;  // Convert $1 from int to float
                                 }
                                 if ($3.val_type == INT_TYPE) {
                                     $3.val_float = (float) $3.val_int;  // Convert $3 from int to float
                                 }
                                 $$.val_bool = $1.val_float > $3.val_float;
                             } else {
                                 $$.val_bool = $1.val_int > $3.val_int;
                             }
         }
         | OPERATION LESS_THAN OPERATION {
                                 $$.val_type = BOOL_TYPE;
                                 if ($1.val_type == FLOAT_TYPE || $3.val_type == FLOAT_TYPE) {
                                     if ($1.val_type == INT_TYPE) {
                                         $1.val_float = (float) $1.val_int;  // Convert $1 from int to float
                                     }
                                     if ($3.val_type == INT_TYPE) {
                                         $3.val_float = (float) $3.val_int;  // Convert $3 from int to float
                                     }
                                     $$.val_bool = $1.val_float < $3.val_float;
                                 } else {
                                     $$.val_bool = $1.val_int < $3.val_int;
                                 }
         }
         | OPERATION LESS_EQUAL OPERATION {
                                     $$.val_type = BOOL_TYPE;
                                     if ($1.val_type == FLOAT_TYPE || $3.val_type == FLOAT_TYPE) {
                                         if ($1.val_type == INT_TYPE) {
                                             $1.val_float = (float) $1.val_int;  // Convert $1 from int to float
                                         }
                                         if ($3.val_type == INT_TYPE) {
                                             $3.val_float = (float) $3.val_int;  // Convert $3 from int to float
                                         }
                                         $$.val_bool = $1.val_float <= $3.val_float;
                                     } else {
                                         $$.val_bool = $1.val_int <= $3.val_int;
                                     }
         }
%%

