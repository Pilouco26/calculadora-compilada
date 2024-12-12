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
    // Loop through the list to check if the real is present
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


void handle_integer_operation(three_address_code item, int i, char *id_name, int number_list[], int *number_size, float result_list[], int *result_size) {
    if (strcmp(item.val_info.id_name, "NULL") != 0) {
        fprintf(file_ca3, "%s ", item.val_info.id_name);
    } else if (!is_number_in_list(number_list, number_size, item.val_info.val_int)) {
        int temporal = is_result_in_list(result_list, result_size, (float)item.val_info.val_int);
        if (temporal != -1) {
            fprintf(file_ca3, "t%d ", temporal);
        } else {
            fprintf(file_ca3, "%d ", item.val_info.val_int);
        }
    } else {
        fprintf(file_ca3, "%d ", item.val_info.val_int);
    }

    fprintf(file_ca3, "%s ", item.val_op);

    if (strcmp(item.val_info2.id_name, "NULL") != 0) {
        fprintf(file_ca3, "%s \n", item.val_info2.id_name);
    } else if (!is_number_in_list(number_list, number_size, item.val_info2.val_int)) {
        int temporal = is_result_in_list(result_list, result_size, (float)item.val_info2.val_int);
        if (temporal != -1 && strcmp(item.val_op, "IDF") != 0) {
            fprintf(file_ca3, "t%d \n", temporal);
        } else {
            fprintf(file_ca3, "%d\n", item.val_info2.val_int);
        }
    } else {
        fprintf(file_ca3, "%d\n", item.val_info2.val_int);
    }
}
void process_val_info(three_address_code item, int number_list[], int number_size, float float_list[], int *float_size, float result_list[], int *result_size) {
    if(strcmp(item.val_info.id_name, "NULL") != 0) {
        fprintf(file_ca3, "%s ", item.val_info.id_name);
    }
    if (!(item.val_info.val_float == -1 || is_real_in_list(float_list, float_size, item.val_info.val_float))) {
        int temporal = is_result_in_list(result_list, result_size, item.val_info.val_float);
        if (temporal != -1 && !is_number_in_list_without_retrieving(number_list, number_size, (int)item.val_info.val_float)) {
            fprintf(file_ca3, "t%d ", temporal);
        } else {
            fprintf(file_ca3, "%d ", (int)item.val_info.val_float);
        }
    } else if (item.val_info.val_float != -1) {
        fprintf(file_ca3, "%f ", item.val_info.val_float);
    }
}
void process_val_info2(three_address_code item, int number_list[], int number_size, float float_list[], int *float_size, float result_list[], int *result_size) {
    if (strcmp(item.val_info2.id_name, "NULL") != 0) {
        fprintf(file_ca3, "%s \n", item.val_info2.id_name);
    } else if (!is_real_in_list(float_list, float_size, item.val_info2.val_float)) {
        int temporal = is_result_in_list(result_list, result_size, item.val_info2.val_float);
        if (temporal != -1 && !is_number_in_list_without_retrieving(number_list, number_size, (int)item.val_info2.val_float)) {
            fprintf(file_ca3, "t%d \n", temporal);
        } else {
            fprintf(file_ca3, "%d\n", (int)item.val_info2.val_float);
        }
    } else {
        fprintf(file_ca3, "%f\n", item.val_info2.val_float);
    }
}

void handle_float_operation(three_address_code item, int i, char *id_name, int number_list[], int number_size, float float_list[], int *float_size, float result_list[], int *result_size) {
    process_val_info(item, number_list, number_size, float_list, float_size, result_list, result_size);
    fprintf(file_ca3, "%s ", item.val_op);
    process_val_info2(item, number_list, number_size, float_list, float_size, result_list, result_size);
}



void print_list(three_address_code list[], int size, int number_list[], int number_size, float float_list[], int float_size, char *id_name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(list[i].val_op, "CALL") == 0) {
            // Add logic for CALL
            // fprintf(file_ca3, "CALL PUT, %d\n", list[i].val_info2.val_int);
        } else {
            if (size == 1 || size == i + 1) {
                fprintf(file_ca3, "%d : %s := ", lines++, id_name);
            } else {
                fprintf(file_ca3, "%d : $t%d := ", lines++, i);
            }

            if (list[i].type_op == 'I') {
                handle_integer_operation(list[i], i, id_name,  number_list, &number_size, result_list, &result_size);
            } else if (list[i].type_op == 'F') {
                handle_float_operation(list[i], i, id_name,  number_list, number_size, float_list, &float_size, result_list, &result_size);
            }
        }
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
    } else {
        integer.val_info.id_name = strdup(id1);
    }

    if (id2 == NULL) {
        integer.val_info2.val_int = value2;
        integer.val_info2.id_name = "NULL";
    } else {
        integer.val_info2.id_name = strdup(id2);
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
        real.val_info.id_name = strdup(id1);
    }

    if (id2 == NULL) {
        real.val_info2.val_float = value2;
        real.val_info2.id_name = "NULL";
    } else {
        real.val_info2.id_name = strdup(id2);
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
        change.type_op = 'F';
        change.val_type_list = INT_TYPE;
    	change.val_info.val_type = INT_TYPE;
        change.val_op = "CALL PUT, ";
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
