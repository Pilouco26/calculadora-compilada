#ifndef FUNCIONS_H
#define FUNCIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "dades.h"
FILE *open_file_ca3();
void close_file_ca3();
void print_list(three_address_code [], int, int [], int, float float_list[], int float_size,char * );
void print_list_array(three_address_code [], int, int [], int, float float_list[], int float_size,char *, char *pos_id, float val_float);
void add_three_address_code(three_address_code[], int *, int , int, char *, char* id1, char * id2);
void add_lines_length(int lines_length);
void add_three_address_code_repeat(three_address_code[], int *, int , int, char *, char* id1, char * id2, int repeat_length);
void print_repeat_list(three_address_code [], int, int [], int, float float_list[], int float_size,char * );
int is_number_in_list(int list[],  int *size, int number);
int is_number_in_list_without_retrieving(int list[],  int size, int number);
void add_to_float_list(float float_list[], int *float_size, float value);
void call_put(three_address_code list[], int *list_size, float value_float, int value_int, int op);
void add_three_address_code_float(three_address_code list[], int *list_size, float value1, float value2, char* op, char* id1, char * id2, int conversion1, int conversion2);
#endif
