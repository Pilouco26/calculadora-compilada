#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include "../header_files/dades.h"



extern FILE *yyin;
extern FILE *yyout;
extern int yylineno;
extern int lines;
extern char *yytext;
extern float result_list[];
extern three_address_code list[];
extern int result_size;
extern int list_size;
extern int comptador;
extern int delta;
extern int ifmode;
extern int do_mode;

extern bool mode_assign;
extern char program_lines[200][200];
int last_temporal = -1;
float last_transformation = -1.0;
char *last_op = "X";
FILE *file_ca3 = NULL; // Global variable for the file


int is_number_in_list(int list[], int *size, int number) {
    // Loop through the list to check if the number is present
    for (int i = 0; i < *size; i++) {
        if (list[i] == number) {
            for (int j = i; j < *size - 1; j++) {
                list[j] = list[j + 1];  // Shift elements left
            }
            (*size)--;  // Decrease the size of the list
            return 1;   // Number found and removed
        }
    }
    return 0;   // Number not found in the list
}
int is_real_in_list(float list[], int *size, float real) {
    for (int i = 0; i < *size; i++) {
        if (list[i] == real) {
            for (int j = i; j < *size - 1; j++) {
                list[j] = list[j + 1];  // Shift elements left
            }
            (*size)--;  // Decrease the size of the list
            return 1;   // Number found and removed
        }
    }
    return 0;   // Number not found in the list
}
int is_result_in_list(float list[], int *size, float real) {
    for (int i = 0; i < *size; i++) {
        if (list[i] == real) {

            list[i] = -1;
            return i;   // Number found and removed
        }
    }
    return -1;   // Number not found in the list
}
int is_number_in_list_without_retrieving(int list[], int size, int number) {
    // Loop through the list to check if the number is present
    for (int i = 0; i < size; i++) {
        if (list[i] == number) {
            return 1;   // Number found and removed
        }
    }
    return 0;   // Number not found in the list
}
// Function to process id_name and set last_id, return if it's not null
bool process_id_name(char *last_id, const char *id_name) {
    bool null = true;
    if (id_name != NULL) {
        if (strcmp(id_name, "NULL") != 0) {
            strcpy(last_id, id_name);
            null = false;
        }

    }
    return null;
}

// Function to set id_name to "NULL" in the list based on last_id
void update_id_name_to_null(three_address_code list[], int size, const char *last_id, const char *last_id2) {
    for (int j = 0; j < size; j++) {
        if (list[j].val_info.id_name != NULL) {
            if (strcmp(last_id, list[j].val_info.id_name) == 0) {
                strcpy(list[j].val_info.id_name, "NULL");
            }
            if (strcmp(last_id2, list[j].val_info.id_name) == 0) {
                strcpy(list[j].val_info.id_name, "NULL");
            }
        }
        if (list[j].val_info2.id_name != NULL) {
            if (strcmp(last_id, list[j].val_info2.id_name) == 0) {
                strcpy(list[j].val_info2.id_name, "NULL");
            }
            if (strcmp(last_id2, list[j].val_info2.id_name) == 0) {
                strcpy(list[j].val_info2.id_name, "NULL");
            }
        }
    }
}

void process_val_info(three_address_code *item, int number_list[], int number_size, float float_list[], int *float_size, float result_list[], int *result_size) {
    char buffer[200];

    if (strcmp(item->val_info.id_name, "NULL") != 0) {
        snprintf(buffer, sizeof(buffer), "%s ", item->val_info.id_name);
        strcat(program_lines[lines], buffer);  // Append to the current line
        strcpy(item->val_info.id_name, "NULL");
    } else if (!(item->val_info.val_float == -1 || is_real_in_list(float_list, float_size, item->val_info.val_float))) {
        int temporal = is_result_in_list(result_list, result_size, item->val_info.val_float);
        if (temporal != -1 && !is_number_in_list_without_retrieving(number_list, number_size, (int)item->val_info.val_float)) {
            snprintf(buffer, sizeof(buffer), "$t%d ", temporal);
        } else {
            if (strcmp(item->val_info.id_name, "NULL") != 0) {
                snprintf(buffer, sizeof(buffer), "%s ", item->val_info.id_name_copy);
            } else {
                snprintf(buffer, sizeof(buffer), "%f ", item->val_info.val_float);
            }
        }
        strcat(program_lines[lines], buffer);  // Append to the current line
    } else if (item->val_info.val_float != -1) {
        snprintf(buffer, sizeof(buffer), "%f ", item->val_info.val_float);
        strcat(program_lines[lines], buffer);  // Append to the current line
    }
}

void process_val_info2(three_address_code *item, int number_list[], int number_size, float float_list[], int *float_size, float result_list[], int *result_size, bool four_ac, int temporal_aux) {
    char buffer[200];

    if (strcmp(item->val_info2.id_name, "NULL") != 0) {
        snprintf(buffer, sizeof(buffer), "%s\n", item->val_info2.id_name);
        strcat(program_lines[lines], buffer);  // Append to the current line
        strcpy(item->val_info2.id_name, "NULL");
    } else if (!is_real_in_list(float_list, float_size, item->val_info2.val_float)) {
        int temporal = is_result_in_list(result_list, result_size, item->val_info2.val_float);
        snprintf(buffer, sizeof(buffer), "$t%d \n", temporal);
        if (temporal != -1 && !is_number_in_list_without_retrieving(number_list, number_size, (int)item->val_info2.val_float)) {
            snprintf(buffer, sizeof(buffer), "$t%d \n", temporal);
        } else {
            if (strcmp(item->val_info2.id_name, "NULL") != 0) {
                snprintf(buffer, sizeof(buffer), "%s\n", item->val_info2.id_name_copy);
            } else {
                snprintf(buffer, sizeof(buffer), "%f\n", item->val_info2.val_float);
            }
        }
        strcat(program_lines[lines], buffer);  // Append to the current line
    } else {
        snprintf(buffer, sizeof(buffer), "%f\n", item->val_info2.val_float);
        strcat(program_lines[lines], buffer);  // Append to the current line
    }

    if (four_ac) {
        if (item->val_info.id_name != NULL) {
            snprintf(buffer, sizeof(buffer), "%d : %s := $t%d \n", lines++, item->val_info.id_name_copy, temporal_aux);
        } else {
            snprintf(buffer, sizeof(buffer), "%d : %s := $t%d \n", lines++, item->val_info2.id_name_copy, temporal_aux);
        }
        strcat(program_lines[lines], buffer);  // Append to the current line
    }
}

void handle_float_operation(three_address_code *item, int i, char *id_name, int number_list[], int number_size, float float_list[], int *float_size, float result_list[], int *result_size, bool four_ac, int temporal_aux) {
    char buffer[200];
	if(strcmp(last_op, "IDF") == 0 && last_transformation == item->val_info.val_float){
      snprintf(buffer, sizeof(buffer), "$t%d ", last_temporal);
      strcat(program_lines[lines], buffer);  // Append to the current line
    }
    else
    	process_val_info(item, number_list, number_size, float_list, float_size, result_list, result_size);

    // Append the operation
    snprintf(buffer, sizeof(buffer), "%s ", item->val_op);
    strcat(program_lines[lines], buffer);  // Append to the current line
    // Process the second value info
    if(strcmp(last_op, "IDF") == 0 && last_transformation == item->val_info2.val_float){
      snprintf(buffer, sizeof(buffer), "$t%d \n", last_temporal);
      strcat(program_lines[lines], buffer);  // Append to the current line
    }
    else
    	process_val_info2(item, number_list, number_size, float_list, float_size, result_list, result_size, four_ac, temporal_aux);
    last_op = item->val_op;
	if(strcmp("IDF", item->val_op) == 0) last_transformation = item->val_info2.val_float;

}


void handle_integer_operation(three_address_code *item, int i, char *id_name, int number_list[], int *number_size, float result_list[], int *result_size, bool four_ac, int temporal_aux) {
    char buffer[200];
    if (strcmp(item->val_info.id_name, "NULL") != 0) {
        snprintf(buffer, sizeof(buffer), "%s ", item->val_info.id_name);
        strcpy(item->val_info.id_name, "NULL");
    } else if (!is_number_in_list(number_list, number_size, item->val_info.val_int)) {
        int temporal = is_result_in_list(result_list, result_size, (float)item->val_info.val_int);
        if (temporal != -1) {
            snprintf(buffer, sizeof(buffer), "$t%d ", temporal);
        } else {
            if (item->val_info.id_name_copy != NULL) {
                snprintf(buffer, sizeof(buffer), "%s ", item->val_info.id_name_copy);
            } else {
                snprintf(buffer, sizeof(buffer), "%d ", item->val_info.val_int);
            }
        }
    } else {
        snprintf(buffer, sizeof(buffer), "%d ", item->val_info.val_int);
    }

    strcat(program_lines[lines], buffer);  // Append to the current line

    snprintf(buffer, sizeof(buffer), "%s ", item->val_op);
    strcat(program_lines[lines], buffer);  // Append to the current line

    if (strcmp(item->val_info2.id_name, "NULL") != 0) {
        snprintf(buffer, sizeof(buffer), "%s\n", item->val_info2.id_name);
        strcpy(item->val_info2.id_name, "NULL");
    } else if (!is_number_in_list(number_list, number_size, item->val_info2.val_int)) {
        int temporal = is_result_in_list(result_list, result_size, (float)item->val_info2.val_int);
        if (temporal != -1 && strcmp(item->val_op, "IDF") != 0) {
            snprintf(buffer, sizeof(buffer), "$t%d \n", temporal);
        } else {
            if (item->val_info2.id_name_copy != NULL) {
                snprintf(buffer, sizeof(buffer), "%s\n", item->val_info2.id_name_copy);
            } else {
                snprintf(buffer, sizeof(buffer), "%d\n", item->val_info2.val_int);
            }
        }
    } else {
        snprintf(buffer, sizeof(buffer), "%d\n", item->val_info2.val_int);
    }

    strcat(program_lines[lines], buffer);  // Append to the current line

    if (four_ac) {
        if (item->val_info.id_name != NULL) {
            snprintf(buffer, sizeof(buffer), "%d : %s := $t%d \n", lines++, item->val_info.id_name_copy, temporal_aux);
        } else {
            snprintf(buffer, sizeof(buffer), "%d : %s := $t%d \n", lines++, item->val_info2.id_name_copy, temporal_aux);
        }
        strcat(program_lines[lines], buffer);  // Append to the current line
    }
}

void print_list(three_address_code list[], int size, int number_list[], int number_size, float float_list[], int float_size, char *id_name) {
    int temporal_aux = result_size + 1;
    bool four_ac = false;

    for (int i = 0; i < size; i++) {
        four_ac = false;
        if (strcmp(list[i].val_op, "CALL") == 0) {
            char buffer[200];
            snprintf(buffer, sizeof(buffer), "%d : CALL PUTF, $t%d\n", lines++, temporal_aux - 2);
            strcat(program_lines[lines], buffer);  // Append to the current line
        } else {
            if (size == 1 || size == i + 1) {
                if (strcmp(list[i].val_info.id_name, id_name) == 0 || strcmp(list[i].val_info2.id_name, id_name) == 0) {
                    char buffer[200];
                    snprintf(buffer, sizeof(buffer), "%d : $t%d := ", lines++, temporal_aux);
                    strcat(program_lines[lines], buffer);  // Append to the current line
                    four_ac = true;
                } else {
                    char buffer[200];
                    snprintf(buffer, sizeof(buffer), "%d : %s := ", lines++, id_name);
                    strcat(program_lines[lines], buffer);  // Append to the current line
                }
            } else {
                char buffer[200];
                snprintf(buffer, sizeof(buffer), "%d : $t%d := ", lines++, i);
                strcat(program_lines[lines], buffer);  // Append to the current line

            }

            char last_id[256];
            char last_id2[256];
            bool null = process_id_name(last_id, list[i].val_info.id_name);
            bool null2 = process_id_name(last_id2, list[i].val_info2.id_name);
            if (list[i].type_op == 'I') {
                handle_integer_operation(&list[i], i, id_name, number_list, &number_size, result_list, &result_size, four_ac, temporal_aux);
                if (!null) {
                    if (strcmp(list[i].val_info.id_name, "NULL") == 0) {
                        update_id_name_to_null(list, size, last_id, last_id2);
                    }
                }
                if (!null2) {
                    if (strcmp(list[i].val_info2.id_name, "NULL") == 0) {
                        update_id_name_to_null(list, size, last_id, last_id2);
                    }
                }
            } else if (list[i].type_op == 'F') {
                handle_float_operation(&list[i], i, id_name, number_list, number_size, float_list, &float_size, result_list, &result_size, four_ac, temporal_aux);
                if (!null) {
                    if (strcmp(list[i].val_info.id_name, "NULL") == 0) {
                        update_id_name_to_null(list, size, last_id, last_id2);
                    }
                }
                if (!null2) {
                    if (strcmp(list[i].val_info2.id_name, "NULL") == 0) {
                        update_id_name_to_null(list, size, last_id, last_id2);
                    }
                }
            }
        }
                        last_temporal = i;

    }
}
void print_list_array(three_address_code list[], int size, int number_list[], int number_size, float float_list[], int float_size, char *id_name, char *pos_id, float result_val_float, char *result_id) {
    int temporal_aux = result_size + 1;
    bool four_ac = false;

    for (int i = 0; i < size; i++) {
        four_ac = false;
        if (strcmp(list[i].val_op, "CALL") == 0) {
            char buffer[200];
            snprintf(buffer, sizeof(buffer), "CALL PUT, %d\n", list[i].val_info2.val_int);
            strcat(program_lines[lines], buffer);  // Append to the current line
            lines++;
        } else {
            if (size == 1 || size == i + 1) {
                if (strcmp(list[i].val_info.id_name, id_name) == 0 || strcmp(list[i].val_info2.id_name, id_name) == 0) {
                    char buffer[200];
                    snprintf(buffer, sizeof(buffer), "%d : $t%d := ", lines++, temporal_aux);
                    strcat(program_lines[lines], buffer);  // Append to the current line
                    four_ac = true;
                } else {
                    char buffer[200];
                    snprintf(buffer, sizeof(buffer), "%d : $t%d := ", lines++, temporal_aux);
                    strcat(program_lines[lines], buffer);  // Append to the current line
                }
            } else {
                char buffer[200];
                snprintf(buffer, sizeof(buffer), "%d : $t%d := ", lines++, i);
                strcat(program_lines[lines], buffer);  // Append to the current line
            }

            char last_id[256];
            char last_id2[256];
            bool null = process_id_name(last_id, list[i].val_info.id_name);
            bool null2 = process_id_name(last_id2, list[i].val_info2.id_name);

            if (list[i].type_op == 'I') {
                handle_integer_operation(&list[i], i, id_name, number_list, &number_size, result_list, &result_size, four_ac, temporal_aux);
                if (!null) {
                    if (strcmp(list[i].val_info.id_name, "NULL") == 0) {
                        update_id_name_to_null(list, size, last_id, last_id2);
                    }
                }
                if (!null2) {
                    if (strcmp(list[i].val_info2.id_name, "NULL") == 0) {
                        update_id_name_to_null(list, size, last_id, last_id2);
                    }
                }
            } else if (list[i].type_op == 'F') {
                handle_float_operation(&list[i], i, id_name, number_list, number_size, float_list, &float_size, result_list, &result_size, four_ac, temporal_aux);
                if (!null) {
                    if (strcmp(list[i].val_info.id_name, "NULL") == 0) {
                        update_id_name_to_null(list, size, last_id, last_id2);
                    }
                }
                if (!null2) {
                    if (strcmp(list[i].val_info2.id_name, "NULL") == 0) {
                        update_id_name_to_null(list, size, last_id, last_id2);
                    }
                }
            }
        }
    }

    if (mode_assign) {
        char buffer[200];
        snprintf(buffer, sizeof(buffer), "%d : %s := %s[$t%d]\n", lines++, id_name, pos_id, temporal_aux);
        strcat(program_lines[lines], buffer);  // Append to the current line
    } else {
        int temporal = is_result_in_list(result_list, &result_size, result_val_float);
        if (temporal != -1 && !is_number_in_list_without_retrieving(number_list, number_size, (int)result_val_float)) {
            char buffer[200];
            snprintf(buffer, sizeof(buffer), "%d : %s[$t%d] := $t%d\n", lines++, id_name, temporal_aux, temporal);
            strcat(program_lines[lines], buffer);  // Append to the current line
        } else {
            char buffer[200];
            if (result_id == NULL) {
                snprintf(buffer, sizeof(buffer), "%d : %s[$t%d] := %f\n", lines++, id_name, temporal_aux, result_val_float);
            } else {
                snprintf(buffer, sizeof(buffer), "%d : %s[$t%d] := %s\n", lines++, id_name, temporal_aux, result_id);
            }
            strcat(program_lines[lines], buffer);  // Append to the current line
        }
    }
}

void generate_power_logic(int *power, int *lines) {
    if (*power != 0) {
        char buffer[200];  // Buffer to hold the formatted output

        // Generate the first line of logic
        snprintf(buffer, sizeof(buffer), "%d : $t-esp01 := t-esp01 ADDI 1\n", (*lines)++);
        strcat(program_lines[*lines - 1], buffer);  // Append to the current line

        // Generate the second line of logic
        snprintf(buffer, sizeof(buffer), "%d : if $t-esp01 LTI $t-esp02 GO TO %d\n", (*lines)++, *power + 1);
        strcat(program_lines[*lines - 1], buffer);  // Append to the current line

        *power = 0;  // Reset power to 0
    }
}




void add_three_address_code(three_address_code list[], int *list_size, int value1, int value2, char* op, char* id1, char * id2) {
    three_address_code integer;

    integer.val_type_list = INT_TYPE;
    integer.val_info.val_type = INT_TYPE;
    integer.val_op = op;
    integer.type_op = 'I';

    if (id1 == NULL) {
        integer.val_info.val_int = value1;
        integer.val_info.id_name = "NULL";
        integer.val_info.id_name_copy = NULL;

    } else {
        integer.val_info.val_int = value1;
        integer.val_info.id_name = strdup(id1);
        integer.val_info.id_name_copy = strdup(id1);
    }

    if (id2 == NULL) {
        integer.val_info2.val_int = value2;
        integer.val_info2.id_name = "NULL";
        integer.val_info2.id_name_copy = NULL;

    } else {
        integer.val_info2.val_int = value2;
        integer.val_info2.id_name = strdup(id2);
        integer.val_info2.id_name_copy = strdup(id2);
    }

    integer.val_type_list = OPERAND_TYPE;
    list[*list_size] = integer;

    (*list_size)++;
}
void add_three_address_code_bool(three_address_code list[], int *list_size, int value1, int value2, char* op, char* id1, char * id2) {
    three_address_code integer;

    integer.val_type_list = INT_TYPE;
    integer.val_info.val_type = INT_TYPE;
    integer.val_op = op;
    integer.type_op = 'B';

    if (id1 == NULL) {
        integer.val_info.val_int = value1;
        integer.val_info.id_name = "NULL";
        integer.val_info.id_name_copy = NULL;

    } else {
        integer.val_info.val_int = value1;
        integer.val_info.id_name = strdup(id1);
        integer.val_info.id_name_copy = strdup(id1);
    }

    if (id2 == NULL) {
        integer.val_info2.val_int = value2;
        integer.val_info2.id_name = "NULL";
        integer.val_info2.id_name_copy = NULL;

    } else {
        integer.val_info2.val_int = value2;
        integer.val_info2.id_name = strdup(id2);
        integer.val_info2.id_name_copy = strdup(id2);
    }

    integer.val_type_list = OPERAND_TYPE;
    list[*list_size] = integer;

    (*list_size)++;
}

void add_three_address_code_float(three_address_code list[], int *list_size, float value1, float value2, char* op, char* id1, char * id2, int conversion1, int conversion2) {
    three_address_code real;

    real.val_type_list = FLOAT_TYPE;
    real.val_info.val_type = FLOAT_TYPE;
    real.val_op = op;
    real.type_op = 'F';

    if (id1 == NULL) {
        real.val_info.val_float = value1;
        real.val_info.id_name = "NULL";
    } else {
        real.val_info.val_float = value1;
        real.val_info.id_name = strdup(id1);
        real.val_info.id_name_copy = strdup(id1);
    }

    if (id2 == NULL) {
        real.val_info2.val_float = value2;
        real.val_info2.id_name = "NULL";
    } else {
        real.val_info2.val_float = value2;
        real.val_info2.id_name = strdup(id2);
        real.val_info2.id_name_copy = strdup(id2);
    }

    if (conversion1 == 1) {
        three_address_code change;
        change.val_info.val_float = -1;
        if (id1 == NULL) {
            change.val_info.id_name = "NULL";
            change.val_info2.id_name = "NULL";
        } else {
            change.val_info.id_name = "NULL";
            change.val_info2.id_name = strdup(id1);
            change.val_info2.id_name_copy = strdup(id1);
        }
        change.val_info2.val_float = value1;
        change.type_op = 'F';
        change.val_type_list = FLOAT_TYPE;
        change.val_info.val_type = FLOAT_TYPE;
        change.val_op = "IDF";

        list[*list_size] = change;
        (*list_size)++;
    }

    if (conversion2 == 1) {
        three_address_code change;
        change.val_info.val_float = -1;
        change.val_info2.val_float = value2;
        change.type_op = 'F';
        change.val_type_list = FLOAT_TYPE;
        change.val_info.val_type = FLOAT_TYPE;
        change.val_op = "IDF";

        if (id2 == NULL) {
            change.val_info.id_name = "NULL";
            change.val_info2.id_name = "NULL";
        } else {
            change.val_info.id_name = "NULL";
            change.val_info2.id_name = strdup(id2);
            change.val_info2.id_name_copy = strdup(id2);
        }

        list[*list_size] = change;
        (*list_size)++;
    }

    real.val_type_list = OPERAND_TYPE;
    real.val_info.type_conversion = conversion1;
    real.val_info2.type_conversion = conversion2;
    list[*list_size] = real;

    (*list_size)++;
}


void call_put(three_address_code list[], int *list_size, float value_float, int value_int, int op){
    if(op == 1){
        three_address_code change;
        change.val_info.val_float = -1;
        change.val_info2.val_float = value_float;
        change.type_op = 'F';
        change.val_type_list = FLOAT_TYPE;
    	change.val_info.val_type = FLOAT_TYPE;
        change.val_op = "CALL";
        list[*list_size] = change;
    	(*list_size)++;
    }
    else{
        three_address_code change;
        change.val_info.val_int = -1;
        change.val_info2.val_int = value_int;
        change.type_op = 'I';
        change.val_type_list = INT_TYPE;
    	change.val_info.val_type = INT_TYPE;
        change.val_op = "CALL";
        list[*list_size] = change;
    	(*list_size)++;
    }

}

void add_to_float_list(float float_list[], int *float_size, float value) {
    float_list[*float_size] = value;
    (*float_size)++;
}

FILE *open_file_ca3() {
    file_ca3 = fopen("./text/CA3.txt", "w"); // Change "w" to "r" if you need to read from it
    if (file_ca3 == NULL) {
        fprintf(stderr, "Error: Could not open ./CA3.txt\n");
        exit(EXIT_FAILURE);
    }
    fprintf(file_ca3, "%d : START\n", lines++);
    return file_ca3;
}

void close_file_ca3(FILE *file_ca3) {
    if (file_ca3 != NULL) {
        fprintf(file_ca3, "%d : HALT\n", lines++);
        fclose(file_ca3);
    }
}
void generate_if_statement(value_info val1, value_info val3, const char *op, int integer, int line) {
    char buffer[200];

    if (integer == 1) {

        if (val1.id_name != NULL && val3.id_name != NULL) {
            snprintf(buffer, sizeof(buffer), "%d : IF %s %s %s GOTO %d\n", lines, val1.id_name, op, val3.id_name, line);
        } else if (val1.id_name != NULL) {
            snprintf(buffer, sizeof(buffer), "%d : IF %s %s %d GOTO %d\n", lines, val1.id_name, op, val3.val_int, line);
        } else if (val3.id_name != NULL) {
            snprintf(buffer, sizeof(buffer), "%d : IF %d %s %s GOTO %d\n", lines, val1.val_int, op, val3.id_name, line);
        } else {
            snprintf(buffer, sizeof(buffer), "%d : IF %d %s %d GOTO %d\n", lines, val1.val_int, op, val3.val_int, line);
        }

    } else {

        if (val1.id_name != NULL && val3.id_name != NULL) {
            snprintf(buffer, sizeof(buffer), "%d : IF %s %s %s GOTO %d\n", lines, val1.id_name, op, val3.id_name, line);
        } else if (val1.id_name != NULL) {
            snprintf(buffer, sizeof(buffer), "%d : IF %s %s %f GOTO %d\n", lines, val1.id_name, op, val3.val_float, line);
        } else if (val3.id_name != NULL) {
            snprintf(buffer, sizeof(buffer), "%d : IF %f %s %s GOTO %d\n", lines, val1.val_float, op, val3.id_name, line);
        } else {
            snprintf(buffer, sizeof(buffer), "%d : IF %f %s %f GOTO %d\n", lines, val1.val_float, op, val3.val_float, line);
        }

    }

    // Append the string to the current line in program_line
    strcat(program_lines[lines], buffer);

    // Increment lines after appending
    lines++;
}
void generate_if_statement_simple(int val1, int val3, const char *op) {

  char buffer[200];

    snprintf(buffer, sizeof(buffer), "%d : IF %d %s %d GOTO %d\n", lines, val1, op, val3, lines + 2);
    // Append the string to the current line in program_lines
    strcat(program_lines[lines], buffer);

    // Increment lines after appending
    lines++;

}