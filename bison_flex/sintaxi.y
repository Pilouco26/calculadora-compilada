
%{
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
int index_iterative = 0;
char program_lines[200][200];
int size_if = 0;
%}

%code requires {
  #include "../header_files/dades.h"
  #include "../header_files/funcions.h"
  #include "../header_files/funcions_ca3.h"
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
%token <sense_valor> IF THEN FI EXTRALINE DO DONE OPENED_CLAUSE CLOSED_CLAUSE COMMENT SUBSTR COMMA LEN SIN COS TAN AND OR NOT PLUS MINUS MULTIPLY DIVIDE MOD POWER CLOSED_PARENTHESIS OPEN_PARENTHESIS ASSIGN ENDLINE SEMICOLON GREATER_THAN GREATER_EQUAL LESS_THAN LESS_EQUAL EQUAL NOT_EQUAL
%type <sense_valor> programa
%type <expr_val>  expressio OPERATION OPERATION2 OPERATION3 OPERATION4 OPERATION_BOOLEAN1 OPERATION_BOOLEAN2 OPERATION_BOOLEAN3 OPERATION_BOOLEAN
%type <expr_list> expressio_list
%type <header> header if_header
%token <header> REPEAT

%start programa

%%


programa : expressio_list {
             fprintf(yyout, "End of input reached.\n");
             for (int i = 0; i < 200; i++) {
                     if (program_lines[i][0] != '\0') {  // Check if the line is not empty
                         fprintf(file_ca3, "%s", program_lines[i]);
                     }
                 }
           }

expressio_list:
    expressio ENDLINE
    | expressio ENDLINE expressio_list;



header:
     ENDLINE REPEAT OPERATION {
                 if ($3.val_type == INT_TYPE) {
                             if ($3.val_int > 0) {
                                char special[50]; // Adjust size as needed for longer strings

                                    // Use snprintf to safely concatenate
                                snprintf(special, sizeof(special), "$t-esp0%d", ++esp+1);
                                print_list(list, list_size, number_list, number_size, float_list, float_size,  special);
                                $$.linea = lines;
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
                                comptador = $3.val_int;
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

if_header:  IF OPERATION_BOOLEAN THEN {
                $$.linea = lines;
                ifmode = 1;
                lines++;
           }
expressio:
                header DO ENDLINE expressio_list DONE ENDLINE{
                    delta = yylineno - $1.linea;
                    char buffer[200];  // Buffer to hold the formatted output
                    snprintf(buffer, sizeof(buffer), "%d : $t-esp01 := t-esp01 ADDI 1\n", lines++);
                    strcat(program_lines[lines - 1], buffer);  // Append to program_lines[lines - 1]
                    snprintf(buffer, sizeof(buffer), "%d : if $t-esp01 LTI $t-esp02 GO TO %d \n", lines++, $1.linea + 1);
                    strcat(program_lines[lines - 1], buffer);  // Append to program_lines[lines - 1]

                }
                | if_header ENDLINE expressio_list FI {
                    ifmode = 0;
                    char buffer[200];  // Buffer to hold the formatted output
                    int current_line = lines;
                    snprintf(buffer, sizeof(buffer), "%d : GOTO %d\n", $1.linea, current_line);
                    strcat(program_lines[$1.linea], buffer);  // Append to program_lines[$1.linia]
                    }
                | ID ASSIGN OPERATION {
                      sym_value_type existing_value;
                      int lookup_result = sym_lookup($1.lexema, &existing_value);
                      if (lookup_result == SYMTAB_OK) {
                          if (existing_value.val_type != $3.val_type) {
                              fprintf(stderr, "Error: Type mismatch for ID '%s' in line %d.\n", $1.lexema, yylineno);
                          }
                      }
                        char buffer[200];  // Buffer to hold the formatted output

                        // If the type is INT_TYPE
                        if ($3.val_type == INT_TYPE) {
                            //snprintf(buffer, sizeof(buffer), "%d : %s := %d\n", lines, $1.lexema, (int)$3.val_int);
                            //strcat(program_lines[lines], buffer);  // Append the assignment statement
                            //lines++;  // Increment the line counter
                        }
                        // If the type is FLOAT_TYPE
                        else if ($3.val_type == FLOAT_TYPE) {
                            //snprintf(buffer, sizeof(buffer), "%d : %s := %f\n", lines, $1.lexema, $3.val_float);
                            //strcat(program_lines[lines], buffer);  // Append the assignment statement
                            //lines++;  // Increment the line counter
                        }
                        // For STRING_TYPE
                        else {
                            strcat(program_lines[lines], buffer);  // Append to program_lines
                            snprintf(buffer, sizeof(buffer), "%d : %s := %s\n", lines, $1.lexema, $3.val_string);
                            strcat(program_lines[lines], buffer);  // Append the assignment statement
                            lines++;  // Increment the line counter
                        }

                      print_list(list, list_size, number_list, number_size, float_list, float_size,  $1.lexema);
                      size_if = list_size;
                      list_size = 0;
                      number_size = 0;
                      result_size = 0;
                      float_size = 0;
                      id_size = 0;
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
                       // fprintf(yyout, "(int) pren per valor: %d\n", (int)$1.val_int);
                        $1.val_type = INT_TYPE;
                        $1.val_int = (int)$1.val_int;
                        call_put(list, &list_size, 0, (int)$1.val_int, 0);
                        print_list(list, list_size, number_list, number_size, float_list, float_size, " ");


                    } else if ($1.val_type == FLOAT_TYPE) {
                        fprintf(yyout, "(real) pren per valor: %f\n", $1.val_float);
                        $1.val_type = FLOAT_TYPE;
                        $1.val_float = $1.val_float;
                        call_put(list, &list_size, 0, $1.val_float, 1);
                        print_list(list, list_size, number_list, number_size, float_list, float_size, " ");

                    } else if ($1.val_type == STRING_TYPE) {
                        fprintf(yyout, " (string) pren per valor: %s\n", $1.val_string);
                        $$.val_type = STRING_TYPE;
                        $$.val_string = $1.val_string;
                    }
                }
                | OPERATION_BOOLEAN {
                            if($1.val_type == BOOL_TYPE){
                                fprintf(yyout, " (bool) pren per valor: %s\n", $1.val_bool ? "true" : "false");
                                $$.val_type = BOOL_TYPE;
                                $$.val_bool = $1.val_bool;
                            }
                }
                | ID ASSIGN ID OPENED_CLAUSE OPERATION CLOSED_CLAUSE {
                     mode_assign = true;
                     if($5.id_name != NULL)
                        add_three_address_code(list, &list_size, $5.val_int, 8, "MULI", $5.id_name, NULL);
                     else
                        add_three_address_code(list, &list_size, $5.val_int, 8, "MULI", NULL, NULL);
                     int result = 8 * result;
                     add_to_float_list(result_list, &result_size,(float)result);
                     if($5.val_type == FLOAT_TYPE)
                        print_list_array(list, list_size, number_list, number_size, float_list, float_size,  $1.lexema, $3.lexema, $5.val_float, NULL);
                     else
                        print_list_array(list, list_size, number_list, number_size, float_list, float_size,  $1.lexema, $3.lexema, (float)$5.val_int, NULL);

                        list_size = 0;
                        number_size = 0;
                        result_size = 0;
                        float_size = 0;
                        id_size = 0;
                        mode_assign = false;

                 }
                | ID OPENED_CLAUSE OPERATION CLOSED_CLAUSE ASSIGN OPERATION {
                      sym_value_type existing_value;
                      int lookup_result = sym_lookup($1.lexema, &existing_value);
                      if ($3.val_type != INT_TYPE) {
                              fprintf(stderr, "Error: Type mismatch for index array '%s' in line %d.\n", $1.lexema, yylineno);
                              YYABORT;
                      }
                      if (lookup_result == SYMTAB_OK) {
                          if (existing_value.val_type != $6.val_type) {
                              fprintf(stderr, "Error: Type mismatch for ID '%s' in line %d.\n", $1.lexema, yylineno);
                          }
                      }
                      if ($6.val_type == INT_TYPE) {
                          $$.val_type = INT_TYPE;
                          $$.val_int = (int)$6.val_int;
                          $1.id_val.val_type = INT_TYPE;
                          $1.id_val.val_int = $6.val_int;

                      } else if ($6.val_type == FLOAT_TYPE) {
                          $$.val_type = FLOAT_TYPE;
                          $$.val_float = $6.val_float;
                          $1.id_val.val_type = FLOAT_TYPE;
                          $1.id_val.val_float = $6.val_float;

                      }
                      if($3.id_name != NULL)
                        add_three_address_code(list, &list_size, $3.val_int, 8, "MULI", $3.id_name, NULL);
                      else
                        add_three_address_code(list, &list_size, $3.val_int, 8, "MULI", NULL, NULL);
                        int result = 8 * result;
                        add_to_float_list(result_list, &result_size,(float)result);

                      if($6.val_type == FLOAT_TYPE)
                        print_list_array(list, list_size, number_list, number_size, float_list, float_size,  $1.lexema, $3.id_name, $6.val_float, $6.id_name);
                      else
                        print_list_array(list, list_size, number_list, number_size, float_list, float_size,  $1.lexema, $3.id_name, (float)$6.val_int, $6.id_name);

                      list_size = 0;
                      number_size = 0;
                      result_size = 0;
                      float_size = 0;
                      id_size = 0;
                }







OPERATION:
    OPERATION PLUS OPERATION2 {
        if ($1.val_type == FLOAT_TYPE || $3.val_type == FLOAT_TYPE) {
            // Handle float addition
            if ($1.val_type == INT_TYPE) {
                $1.val_float = (float) $1.val_int; // Convert int to float
                add_to_float_list(result_list, &result_size,$1.val_float);
                $1.type_conversion = 1;

            }
            if ($3.val_type == INT_TYPE) {
                $3.val_float = (float) $3.val_int; // Convert int to float
                add_to_float_list(result_list, &result_size,$3.val_float);
                $3.type_conversion = 1;

            }

            $$.val_type = FLOAT_TYPE;
            $$.val_float = $1.val_float + $3.val_float;
            add_three_address_code_float(list, &list_size, $1.val_float, $3.val_float, "ADDF", $1.id_name, $3.id_name, $1.type_conversion, $3.type_conversion);
            add_to_float_list(result_list, &result_size, $$.val_float);


        } else {
            add_three_address_code(list, &list_size, $1.val_int, $3.val_int, "ADDI", $1.id_name, $3.id_name);
            $$.val_type = INT_TYPE;
            $$.val_int = $1.val_int + $3.val_int;
            fprintf(stderr, " values %d, %d, %d", $1.val_int, $3.val_int, $$.val_int);

            add_to_float_list(result_list, &result_size, (float)$$.val_int);
        }
            generate_power_logic(&power, &lines);

    }
    | OPERATION MINUS OPERATION2 {
        if (($1.val_type == INT_TYPE || $1.val_type == FLOAT_TYPE) &&
            ($3.val_type == INT_TYPE || $3.val_type == FLOAT_TYPE)) {
            if ($1.val_type == FLOAT_TYPE || $3.val_type == FLOAT_TYPE) {
                if ($1.val_type == INT_TYPE) {
                    $1.val_float = (float) $1.val_int;  // Convert $1 from int to float
                    add_to_float_list(result_list, &result_size,$1.val_float);
                    $1.type_conversion = 1;
                }
                if ($3.val_type == INT_TYPE) {
                    $3.val_float = (float) $3.val_int;  // Convert $3 from int to float
                    add_to_float_list(result_list, &result_size,$3.val_float);
                    $3.type_conversion = 1;
                }
                add_three_address_code_float(list, &list_size, $1.val_float, $3.val_float, "SUBF", $1.id_name, $3.id_name, $1.type_conversion, $3.type_conversion);
                $$.val_type = FLOAT_TYPE;
                $$.val_float = $1.val_float - $3.val_float;
                add_to_float_list(result_list, &result_size,$$.val_float);

            } else {
                // Both operands are integers
                add_three_address_code(list, &list_size, $1.val_int, $3.val_int, "SUBI", $1.id_name, $3.id_name);
                $$.val_type = INT_TYPE;
                $$.val_int = $1.val_int - $3.val_int;
                add_to_float_list(result_list, &result_size,(float)$$.val_int);

            }
            generate_power_logic(&power, &lines);

        } else {
            fprintf(stderr, "Error: Both operands must be numbers (int or float) in line %d\n", yylineno);
            YYABORT;
        }
    }
    | OPERATION2
    ;

OPERATION2:
     OPERATION2 MULTIPLY OPERATION3 {
        if (($1.val_type == INT_TYPE || $1.val_type == FLOAT_TYPE) &&
            ($3.val_type == INT_TYPE || $3.val_type == FLOAT_TYPE)) {

            if ($1.val_type == FLOAT_TYPE || $3.val_type == FLOAT_TYPE) {
                if ($1.val_type == INT_TYPE) {
                    $1.val_float = (float) $1.val_int;  // Convert $1 from int to float
                    fprintf(stderr, "\n\nValue of FLOAT %f\n\n", $1.val_float);
                    add_to_float_list(result_list, &result_size,$1.val_float);
                    $1.type_conversion = 1;
                }
                if ($3.val_type == INT_TYPE) {
                    $3.val_float = (float) $3.val_int;  // Convert $3 from int to float
                    add_to_float_list(result_list, &result_size,$3.val_float);
                    $3.type_conversion = 1;
                }

                $$.val_type = FLOAT_TYPE;
                $$.val_float = $1.val_float * $3.val_float;
                add_three_address_code_float(list, &list_size, $1.val_float, $3.val_float, "MULF", $1.id_name, $3.id_name, $1.type_conversion, $3.type_conversion);
                add_to_float_list(result_list, &result_size,$$.val_float);

            } else {
                add_three_address_code(list, &list_size, $1.val_int, $3.val_int, "MULI", $1.id_name, $3.id_name);
                $$.val_type = INT_TYPE;
                $$.val_int = $1.val_int * $3.val_int;
                add_to_float_list(result_list, &result_size, (float)$$.val_int);


            }
            generate_power_logic(&power, &lines);
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
                    add_to_float_list(result_list, &result_size,$1.val_float);
                    $1.type_conversion = 1;
                }
                if ($3.val_type == INT_TYPE) {
                    $3.val_float = (float) $3.val_int;  // Convert $3 from int to float
                    add_to_float_list(result_list, &result_size,$3.val_float);
                    $3.type_conversion = 1;
                }
                add_three_address_code_float(list, &list_size, $1.val_float, $3.val_float, "DIVF", $1.id_name, $3.id_name, $1.type_conversion, $3.type_conversion);
                $$.val_type = FLOAT_TYPE;
                $$.val_float = $1.val_float / $3.val_float;
                add_to_float_list(result_list, &result_size,$$.val_float);

            } else {
                if($1.val_int % $3.val_int == 0){
                    add_three_address_code(list, &list_size, $1.val_int, $3.val_int, "DIVI", $1.id_name, $3.id_name);
                    $$.val_type = INT_TYPE;
                    $$.val_int = $1.val_int / $3.val_int;
                    add_to_float_list(result_list, &result_size, $$.val_int);

                }
                else {
                      $$.val_type = FLOAT_TYPE;
                      $1.val_float = (float)$1.val_int;
                      $3.val_float = (float)$3.val_int;
                      $$.val_float = $1.val_float / $3.val_float;
                      add_to_float_list(result_list, &result_size, $1.val_float);
                      add_to_float_list(result_list, &result_size, $3.val_float);
                      add_to_float_list(result_list, &result_size, $$.val_float);
                      add_three_address_code_float(list, &list_size, $1.val_float, $3.val_float, "DIVF", $1.id_name, $3.id_name, $1.type_conversion, $3.type_conversion);

                }
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
                        char special[50];
                        snprintf(special, sizeof(special), "$t-esp0%d", esp+2);
                        char buffer[200];  // Buffer to hold the formatted output

                        // Formatting the string using snprintf
                        snprintf(buffer, sizeof(buffer), "%d : $t-esp0%d := %d\n", lines++, esp + 2, $3.val_int);

                        // Appending the formatted string to the appropriate program line
                        strcat(program_lines[lines - 1], buffer);  // Append to program_lines[lines - 1]

                        print_list(list, list_size, number_list, number_size, float_list, float_size,  special);
                        snprintf(special, sizeof(special), "$t-esp0%d", ++esp+1);
                        print_list(list, list_size, number_list, number_size, float_list, float_size,  special);
                        // Formatting the string using snprintf
                        snprintf(buffer, sizeof(buffer), "%d : $t-esp0%d := 0\n", lines++, esp++);

                        // Appending the formatted string to the appropriate program line
                        strcat(program_lines[lines - 1], buffer);  // Append to program_lines[lines - 1]
                        add_three_address_code(list, &list_size, $1.val_int, $1.val_int, "MULI",  NULL, NULL);
                        snprintf(special, sizeof(special), "$t%d", list_size-1);
                        print_list(list, list_size, number_list, number_size, float_list, float_size, special);
                        list_size = 0;
                        number_size = 0;
                        float_size = 0;
                        id_size = 0;
                        result_size = 0;
                        power = yylineno;
                        add_to_float_list(result_list, &result_size,(float)$$.val_int);

                    }


        }

    | OPERATION4
;
OPERATION4:
     SIN OPERATION4 {
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
            number_list[number_size] = $1;
            number_size++;
            $$.val_type = INT_TYPE;
            $$.val_int = $1;

        }
    | FLOAT {
            fprintf(yyout, "float");
            add_to_float_list(float_list, &float_size, $1);
            $$.val_type = FLOAT_TYPE;
            $$.val_float = $1;
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
                $$.id_name = $1.lexema;
                id_list[id_size]= $1.lexema;
                id_size++;
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
                         generate_if_statement($1.val_int, $3.val_int, "EQ");

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
                         generate_if_statement($1.val_int, $3.val_int, "NE");

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
                             generate_if_statement($1.val_int, $3.val_int, "NE");

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

