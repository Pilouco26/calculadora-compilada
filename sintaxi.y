
%{
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
%}

%code requires {
  #include "dades.h"
  #include "funcions.h"
}

%union {
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

}

%token <enter> INTEGER
%token <boolean> FALSE TRUE
%token <mode> MODE
%token <real> FLOAT
%token <ident> ID ID_BOOL
%token <cadena> STRING
%token <sense_valor>  REPEAT DO DONE COMMENT SUBSTR COMMA LEN SIN COS TAN AND OR NOT PLUS MINUS MULTIPLY DIVIDE MOD POWER CLOSED_PARENTHESIS OPEN_PARENTHESIS ASSIGN ENDLINE SEMICOLON GREATER_THAN GREATER_EQUAL LESS_THAN LESS_EQUAL EQUAL NOT_EQUAL
%type <sense_valor> programa
%type <expr_val>  expressio OPERATION OPERATION2 OPERATION3 OPERATION4 OPERATION_BOOLEAN1 OPERATION_BOOLEAN2 OPERATION_BOOLEAN3 OPERATION_BOOLEAN
%type <expr_list> expressio_list
%type <header> header

%start programa

%%


programa : expressio_list {
             fprintf(yyout, "End of input reached.\n");
           }

expressio_list : expressio ENDLINE {
    $$ = (expression_list){ .index = 0 };
    $$.expr_val[$$.index++] = $1;
}
| expressio ENDLINE expressio_list {
    $$ = $3;
    $$.expr_val[$$.index++] = $1;
}
| /* empty */ {
    $$ = (expression_list){ .index = 0 };
}


header:
    REPEAT OPERATION {
        if (!contador_initialized) {
            contador_initialized = 1;
            fprintf(yyout, "linia %d\n", $$.linea);

            $$.linea = yylineno;  // Save the current line number
            comptador = 0;
        }
        if ($2.val_type == INT_TYPE) {
            if (comptador < $2.val_int) {
                comptador++;

                fprintf(yyout, "passo per segon if comptador: %d, operacio: %d\n", comptador, $2.val_int);
                // Restart lexer at saved line number
                rewind(yyin);  // Reset file pointer to the beginning
                // Reset file pointer to the beginning
                long offset = find_line_offset(yyin, $$.linea);
                fprintf(yyout, "linia loop %d\n", $$.linea);
                   if (offset != -1) {
                       fseek(yyin, offset, SEEK_SET);  // Go back to the saved line
                       yyrestart(yyin);  // Restart the scanner with the new input file
                    } else {
                         printf("Error: Line %d not found\n", $$.linea);
                    }

            }
        } else {
            // Handle error for invalid type
        }
    }

;

expressio:
    REPEAT OPERATION DO expressio_list DONE{
           contador_initialized = 0;
            comptador = 0;
    }

|ID ASSIGN OPERATION {
                      sym_value_type existing_value;
                      int lookup_result = sym_lookup($1.lexema, &existing_value);
                      if (lookup_result == SYMTAB_OK) {
                          // ID already exists, check if the new value matches the existing type
                          if (existing_value.val_type != $3.val_type) {
                              fprintf(stderr, "Error: Type mismatch for ID '%s' in line %d.\n", $1.lexema, yylineno);
                              YYABORT;
                          }
                      }
                      // Assign the new value
                      if ($3.val_type == INT_TYPE) {
                          fprintf(yyout, "ID: %s (int) pren per valor: %d\n", $1.lexema, (int)$3.val_int);
                          $$.val_type = INT_TYPE;
                          $$.val_int = (int)$3.val_int;
                          $1.id_val.val_type = INT_TYPE;
                          $1.id_val.val_int = $3.val_int;
                      } else if ($3.val_type == FLOAT_TYPE) {
                          fprintf(yyout, "ID: %s (real) pren per valor: %f\n", $1.lexema, $3.val_float);
                          $$.val_type = FLOAT_TYPE;
                          $$.val_float = $3.val_float;
                          $1.id_val.val_type = FLOAT_TYPE;
                          $1.id_val.val_float = $3.val_float;
                      } else {
                          fprintf(yyout, "ID: %s (string) pren per valor: %s\n", $1.lexema, $3.val_string);
                          $$.val_type = STRING_TYPE;
                          $$.val_string = $3.val_string;
                          $1.id_val.val_type = STRING_TYPE;
                          $1.id_val.val_string = $3.val_string;
                      }

                      sym_enter($1.lexema, &$3);
                  }
                | ID ASSIGN OPERATION MODE {
                if ($3.val_type == UNKNOWN_TYPE) {
                        fprintf(stderr, "Error: ID is not declared in line %d\n", yylineno);
                        YYABORT;
                    }
                                if ($3.val_type == INT_TYPE) {
                                    if (!$4.set || strcmp($4.representacio, "dec") == 0) {
                                        // Default case: print the integer value
                                        fprintf(yyout, "(int)(hex) pren per valor: %d\n", (int)$3.val_int);
                                        $3.val_type = INT_TYPE;
                                        $3.val_int = (int)$3.val_int;
                                    } else if (strcmp($4.representacio, "oct") == 0) {
                                        fprintf(yyout, "checkpoint oct\n");
                                        fprintf(yyout, "(int)(oct) pren per valor: %o\n", (int)$3.val_int);
                                    } else if (strcmp($4.representacio, "hex") == 0) {
                                        // Hexadecimal representation (lowercase)
                                        fprintf(yyout, "(int)(hex) pren per valor: %x\n", (int)$3.val_int);
                                    } else if (strcmp($4.representacio, "bin") == 0) {
                                        // Binary representation (using custom function)
                                        char binary[65]; // 32 bits + null terminator
                                        int_to_binary((int)$3.val_int, binary);
                                        fprintf(yyout, "(int)(bin) pren per valor: %s\n", binary);
                                        sym_enter($1.lexema, &$3);

                                    }
                              } else {
                                 fprintf(stderr, "Mode only supported in INTEGER, error declared in line %d\n", yylineno);
                              }
                }
                | ID ASSIGN OPERATION_BOOLEAN {
                            fprintf(yyout, "ID: %s (bool) pren per valor: %s\n", $1.lexema, $3.val_bool ? "true" : "false");
                            fprintf(stderr, "ID: %s (bool) pren per valor: %s\n", $1.lexema, $3.val_bool ? "true" : "false");
                            sym_value_type value_to_store;
                            value_to_store.val_type = $3.val_type;
                            value_to_store.val_bool = $3.val_bool; // Assuming $3 is a boolean
                            // Check if the symbol already exists, if not, initialize a new entry

                            sym_enter($1.lexema, &value_to_store);

                }
                | ID_BOOL ASSIGN OPERATION_BOOLEAN {
                if ($3.val_type == UNKNOWN_TYPE) {
                        fprintf(stderr, "Error: ID is not declared in line %d\n", yylineno);
                        YYABORT;
                }
                                            fprintf(yyout, "ID: %s (bool) pren per valor: %s\n", $1.lexema, $3.val_bool ? "true" : "false");
                                            $$.val_type = BOOL_TYPE;
                                            $$.val_bool = $3.val_bool;
                                            sym_value_type value_to_store;
                                            value_to_store.val_type = $3.val_type;
                                            value_to_store.val_bool = $3.val_bool; // Assuming $3 is a boolean
                                            sym_enter($1.lexema, &value_to_store);


                }
                | OPERATION MODE {
                if ($1.val_type == UNKNOWN_TYPE) {
                        fprintf(stderr, "Error: ID is not declared in line %d\n", yylineno);
                        YYABORT;
                    }
                            if ($1.val_type == INT_TYPE) {
                                if (strcmp($2.representacio, "dec") == 0) {
                                    // Default case: print the integer value
                                    fprintf(yyout, "(int)(hex) pren per valor: %d\n", (int)$1.val_int);
                                    $1.val_type = INT_TYPE;
                                    $1.val_int = (int)$1.val_int;
                                } else if (strcmp($2.representacio, "oct") == 0) {
                                    fprintf(yyout, "(int)(oct) pren per valor: %o\n", (int)$1.val_int);
                                } else if (strcmp($2.representacio, "hex") == 0) {
                                    // Hexadecimal representation (lowercase)
                                    fprintf(yyout, "(int)(hex) pren per valor: %x\n", (int)$1.val_int);
                                } else if (strcmp($2.representacio, "bin") == 0) {
                                    // Binary representation (using custom function)
                                   char binary[65]; // 32 bits + null terminator
                                    int_to_binary((int)$1.val_int, binary);
                                    fprintf(yyout, "(int)(bin) pren per valor: %s\n", binary);
                                }
                              } else if($1.val_type == FLOAT_TYPE){
                                          if (!$2.set || strcmp($2.representacio, "dec") == 0) {
                                              // Default case: print the float value in decimal format
                                              fprintf(yyout, "(float)(dec) pren per valor: %f\n", $1.val_float);
                                          } else if (strcmp($2.representacio, "hex") == 0) {
                                              // Hexadecimal representation for floats
                                              fprintf(yyout, "(float)(hex) pren per valor: %a\n", $1.val_float);
                                          } else if (strcmp($2.representacio, "bin") == 0) {
                                              // Binary representation (using custom function)
                                              char binary[65]; // 32 bits for the float's bit pattern + null terminator
                                              float_to_binary($1.val_float, binary);
                                              fprintf(yyout, "(float)(bin) pren per valor: %s\n", binary);
                                          }
                                      }
                               else {
                                       fprintf(yyout, " (string) pren per valor: %s\n", $1.val_string);
                                       $$.val_type = STRING_TYPE;
                                       $$.val_string = $1.val_string;
                                       }
                }
                | OPERATION {
                    if ($1.val_type == UNKNOWN_TYPE) {
                        fprintf(stderr, "Error: ID is not declared in line %d\n", yylineno);
                        YYABORT;
                    }

                    if ($1.val_type == INT_TYPE) {
                        fprintf(yyout, "(int) pren per valor: %d\n", (int)$1.val_int);
                        $1.val_type = INT_TYPE;
                        $1.val_int = (int)$1.val_int;
                    } else if ($1.val_type == FLOAT_TYPE) {
                        fprintf(yyout, "(real) pren per valor: %f\n", $1.val_float);
                        $1.val_type = FLOAT_TYPE;
                        $1.val_float = $1.val_int;
                    } else {
                        fprintf(yyout, " (string) pren per valor: %s\n", $1.val_string);
                        $$.val_type = STRING_TYPE;
                        $$.val_string = $1.val_string;
                    }
                }
                | OPERATION_BOOLEAN {
                            fprintf(yyout, " (bool) pren per valor: %s\n", $1.val_bool ? "true" : "false");
                            $$.val_type = BOOL_TYPE;
                            $$.val_bool = $1.val_bool;
                }










OPERATION:
    OPERATION PLUS OPERATION2 {
        char* result;
        fprintf(yyout, " op %d %d \n", $1.val_int, $3.val_int);
        // Check if either operand is a string
        if ($1.val_type == STRING_TYPE || $3.val_type == STRING_TYPE) {

            // Convert the first operand to string if it's an integer or float
            if ($1.val_type == INT_TYPE) {
                char int_str[12]; // Buffer to hold the string representation of the integer
                sprintf(int_str, "%d", $1.val_int); // Convert int to string
                $1.val_string = strdup(int_str); // Allocate memory for the string
                $1.val_type = STRING_TYPE; // Treat it as a string from now on
            } else if ($1.val_type == FLOAT_TYPE) {
                char float_str[20]; // Buffer to hold the string representation of the float
                sprintf(float_str, "%.6f", $1.val_float); // Convert float to string
                $1.val_string = strdup(float_str); // Allocate memory for the string
                $1.val_type = STRING_TYPE; // Treat it as a string from now on
            }

            // Convert the second operand to string if it's an integer or float
            if ($3.val_type == INT_TYPE) {
                char int_str[12]; // Buffer to hold the string representation of the integer
                sprintf(int_str, "%d", $3.val_int); // Convert int to string
                $3.val_string = strdup(int_str); // Allocate memory for the string
                $3.val_type = STRING_TYPE; // Treat it as a string from now on
            } else if ($3.val_type == FLOAT_TYPE) {
                char float_str[20]; // Buffer to hold the string representation of the float
                sprintf(float_str, "%.6f", $3.val_float); // Convert float to string
                $3.val_string = strdup(float_str); // Allocate memory for the string
                $3.val_type = STRING_TYPE; // Treat it as a string from now on
            }

            // Now, concatenate the two string operands
            result = (char*) malloc(strlen($1.val_string) + strlen($3.val_string) + 1);
            if (!result) {
                fprintf(stderr, "Error: Memory allocation failed\n");
                exit(1);
            }

            // Perform the concatenation
            strcpy(result, $1.val_string);
            strcat(result, $3.val_string);

            // Set the result
            $$.val_type = STRING_TYPE;
            $$.val_string = result;

        } else if ($1.val_type == FLOAT_TYPE || $3.val_type == FLOAT_TYPE) {
            // Handle float addition
            if ($1.val_type == INT_TYPE) {
                $1.val_float = (float) $1.val_int; // Convert int to float
            }
            if ($3.val_type == INT_TYPE) {
                $3.val_float = (float) $3.val_int; // Convert int to float
            }

            $$.val_type = FLOAT_TYPE;
            $$.val_float = $1.val_float + $3.val_float;

        } else {
            // Both operands are integers, add them
            $$.val_type = INT_TYPE;
            $$.val_int = $1.val_int + $3.val_int;
        }
    }
    | OPERATION MINUS OPERATION2 {
                printf("operacio menos\n");
                printf("%d, %d, \n", $1.val_type,$3.val_type);

        if (($1.val_type == INT_TYPE || $1.val_type == FLOAT_TYPE) &&
            ($3.val_type == INT_TYPE || $3.val_type == FLOAT_TYPE)) {
            if ($1.val_type == FLOAT_TYPE || $3.val_type == FLOAT_TYPE) {
                printf("operacio float menos\n");
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
        } else {
            fprintf(stderr, "Error: Both operands must be numbers (int or float) in line %d\n", yylineno);
            YYABORT;
        }
    }
    | OPERATION2
    ;

OPERATION2:
    | OPERATION2 MULTIPLY OPERATION3 {
        if (($1.val_type == INT_TYPE || $1.val_type == FLOAT_TYPE) &&
            ($3.val_type == INT_TYPE || $3.val_type == FLOAT_TYPE)) {

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
        } else {
            fprintf(stderr, "Error: Both operands must be numbers (int or float) in line %d\n", yylineno);
            YYABORT;
        }
    }
    | OPERATION2 DIVIDE OPERATION3 {
        if (($1.val_type == INT_TYPE || $1.val_type == FLOAT_TYPE) &&
            ($3.val_type == INT_TYPE || $3.val_type == FLOAT_TYPE)) {

            if ($3.val_type == INT_TYPE && $3.val_int == 0) {
                fprintf(stderr, "Error: Division by zero in line %d\n", yylineno);
                YYABORT;
            } else if ($3.val_type == FLOAT_TYPE && $3.val_float == 0.0) {
                fprintf(stderr, "Error: Division by zero in line %d\n", yylineno);
                YYABORT;
            }

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
        } else {
            fprintf(stderr, "Error: Both operands must be numbers (int or float) in line %d\n", yylineno);
            YYABORT;
        }
    }
    | OPERATION2 MOD OPERATION3 {
    //NOMES PER INT
            if ($1.val_type == INT_TYPE || $3.val_type == INT_TYPE) {
                if ($3.val_int > 0) {
                    // Both operands are integers and divisor is greater than 0
                    $$.val_type = INT_TYPE;
                    $$.val_int = $1.val_int % $3.val_int;
                } else {
                    fprintf(stderr, "Error: Modulus by zero or negative number in line %d\n", yylineno);
                    YYABORT;
                }
            }
            else {
                fprintf(stderr, "Error: Modulus is not made by integers as expected in line %d\n", yylineno-1);
            }
        }
    | OPERATION3
    ;

OPERATION3:
    OPERATION4 POWER  OPERATION3{
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
    | SIN OPERATION4 {
        if ($2.val_type == FLOAT_TYPE) {
            $$.val_type = FLOAT_TYPE;
            $$.val_float = sin($2.val_float);
        } else if ($2.val_type == INT_TYPE) {
            $$.val_type = FLOAT_TYPE;
            $$.val_float = sin($2.val_int);
        }
    }
    | COS OPERATION4 {
        if ($2.val_type == FLOAT_TYPE) {
            $$.val_type = FLOAT_TYPE;
            $$.val_float = cos($2.val_float);
        } else if ($2.val_type == INT_TYPE) {
            $$.val_type = FLOAT_TYPE;
            $$.val_float = cos($2.val_int);
        }
    }
    | TAN OPERATION4 {
        if ($2.val_type == FLOAT_TYPE) {
            if (fmod($2.val_float, M_PI) == M_PI / 2) {
                fprintf(stderr, "Error: tan is undefined at %f in line %d\n", $2.val_float, yylineno);
                YYABORT;
            }
            $$.val_type = FLOAT_TYPE;
            $$.val_float = tan($2.val_float);
        } else if ($2.val_type == INT_TYPE) {
            if ($2.val_int % (int)M_PI == M_PI / 2) {
                fprintf(stderr, "Error: tan is undefined at %d in line %d\n", $2.val_int, yylineno);
                YYABORT;
            }
            $$.val_type = FLOAT_TYPE;
            $$.val_float = tan($2.val_int);
        }
    }
    | LEN OPERATION4 {
        if ($2.val_type == STRING_TYPE) {
            $$.val_int = strlen($2.val_string);
            $$.val_type = INT_TYPE;
        } else {
            fprintf(stderr, "Error: LEN operation requires a string type in line %d\n", yylineno);
            YYABORT;
        }
    }

| SUBSTR OPEN_PARENTHESIS OPERATION4 OPERATION4 OPERATION4 CLOSED_PARENTHESIS {
    // OPERATION4 $2 is the string input
    // OPERATION4 $3 is the starting index
    // OPERATION4 $4 is the length of the substring
    // ARREGLAR AIXO

    if ($3.val_type == STRING_TYPE && $4.val_type == INT_TYPE && $5.val_type == INT_TYPE) {
        // Ensure that the starting index and length are non-negative
        if ($4.val_int < 0 || $5.val_int < 0) {
            fprintf(stderr, "Error: Starting index and length must be non-negative\n");
            exit(1);
        }

        // Get the length of the input string
        int input_length = strlen($3.val_string);

        // Validate the starting index
        if ($4.val_int >= input_length) {
            fprintf(stderr, "Error: Starting index exceeds string length\n");
            exit(1);
        }

        // Calculate the effective length for the substring
        int effective_length = ($4.val_int + $5.val_int > input_length) ?
            input_length - $4.val_int : $5.val_int;

        // Allocate memory for the substring
        char *substring = (char *)malloc(effective_length + 1);
        if (substring == NULL) {
            fprintf(stderr, "Error: Memory allocation failed\n");
            exit(1);
        }

        // Copy the substring
        strncpy(substring, $3.val_string + $4.val_int, effective_length);
        substring[effective_length] = '\0'; // Null-terminate the substring

        // Set the result
        $$.val_string = substring; // Assign the resulting substring
        $$.val_type = STRING_TYPE;  // Set the type to STRING_TYPE
    } else {
        fprintf(stderr, "Error: Invalid types for SUBSTR\n");
        exit(1);
    }
}

    | INTEGER {


            $$.val_type = INT_TYPE;
            $$.val_int = $1;
        }
    | FLOAT {
            $$.val_type = FLOAT_TYPE;
            $$.val_float = $1;
            printf("%f \n", $1);

        }
    | STRING {
                $$.val_type = STRING_TYPE;
                $$.val_string = $1;
        }
    | ID {
            sym_value_type value;
            int lookup_result;

            /* Call sym_lookup to find the identifier in the symbol table */
            lookup_result = sym_lookup($1.lexema, &value);

            if (lookup_result == SYMTAB_OK) {
                fprintf(yyout, "symtab trobat\n");
                $$.val_type = value.val_type;  // Store the value for later use
                if($$.val_type == STRING_TYPE){
                     $$.val_string = value.val_string;  // Store the value for later use
                }
                else if($$.val_type == INT_TYPE){
                     $$.val_int = value.val_int;  // Store the value for later use
                }
                else if($$.val_type == FLOAT_TYPE){
                     $$.val_float = value.val_float;  // Store the value for later use
                }

            } else {
                fprintf(stderr, "Error: ID '%s' not declared\n", $1.lexema);
                exit(EXIT_FAILURE);  // Exit the program
            }
        }
    | MINUS ID {
        sym_value_type value;
        int lookup_result;

        /* Call sym_lookup to find the identifier in the symbol table */
        lookup_result = sym_lookup($2.lexema, &value);

        if (lookup_result == SYMTAB_OK) {
            $$.val_type = value.val_type;  // Store the value for later use
            if($$.val_type == STRING_TYPE){
                //TODO: PRINTAR ERROR
                 $$.val_string = value.val_string;  // Store the value for later use
            }
            else if($$.val_type == INT_TYPE){
                 $$.val_int = -value.val_int;  // Store the value for later use
            }
            else if($$.val_type == FLOAT_TYPE){
                 $$.val_float = -value.val_float;  // Store the value for later use
            }

        } else {
            fprintf(yyout, "ID '%s' not found, inserted with initial unknown type\n", $2.lexema);
        }

    }
    | OPEN_PARENTHESIS OPERATION CLOSED_PARENTHESIS {
        $$.val_type = $2.val_type;

        if ($2.val_type == INT_TYPE) {
            // Handle integer type
            $$.val_int = $2.val_int;

        } else if ($2.val_type == FLOAT_TYPE) {
            // Handle float type
            $$.val_float = $2.val_float;

        } else if ($2.val_type == STRING_TYPE) {
            // Handle string type
            $$.val_string = strdup($2.val_string);  // Duplicate the string to avoid pointer issues
        }
    }


;



OPERATION_BOOLEAN:
    OPERATION_BOOLEAN OR OPERATION_BOOLEAN1{
                                $$.val_type = BOOL_TYPE;
                                if ($1.val_type == BOOL_TYPE && $3.val_type == BOOL_TYPE) {
                                $$.val_bool = $1.val_bool || $3.val_bool;
                                }
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
        }
    | ID_BOOL {
        sym_value_type value;
        int lookup_result;
        /* Call sym_lookup to find the identifier in the symbol table */
        lookup_result = sym_lookup($1.lexema, &value);
        if (lookup_result == SYMTAB_OK) {
            $$.val_type = value.val_type;  // Store the value for later use
            $$.val_bool = value.val_bool;
        }
        else {
        }
    }
    | FALSE {
            $$.val_type = BOOL_TYPE;
            $$.val_bool = false;  // Use bool `false` instead of string "false"
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
    printf("hola");
    printf("%d, %d less_equal \n", $1.val_type, $1.val_type);

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
    printf("%d, %d less_equal \n", $1.val_type, $1.val_type);

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

