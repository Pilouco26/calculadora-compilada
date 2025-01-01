#ifndef FUNCIONS_H
#define FUNCIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include "dades.h"
FILE *open_file_ca3();
void close_file_ca3();
void print_list(three_address_code [], int, int [], int, float float_list[], int float_size,char * );
void print_list_array(three_address_code [], int, int [], int, float float_list[], int float_size,char *, char *pos_id, float val_float, char *result_id);
void add_three_address_code(three_address_code[], int *, int , int, char *, char* id1, char * id2);
void add_three_address_code_bool(three_address_code list[], int *list_size, int value1, int value2, char* op, char* id1, char * id2);
void add_lines_length(int lines_length);
void add_three_address_code_repeat(three_address_code[], int *, int , int, char *, char* id1, char * id2, int repeat_length);
void print_repeat_list(three_address_code [], int, int [], int, float float_list[], int float_size,char * );
int is_number_in_list(int list[],  int *size, int number);
int is_number_in_list_without_retrieving(int list[],  int size, int number);
void add_to_float_list(float float_list[], int *float_size, float value);
void call_put(three_address_code list[], int *list_size, char *id);
void add_three_address_code_float(three_address_code list[], int *list_size, float value1, float value2, char* op, char* id1, char * id2, int conversion1, int conversion2);
void generate_power_logic( int *power, int *lines);
void generate_if_statement(value_info val1, value_info val3, const char *op, int integer, int lines);
void generate_if_statement_simple(int val1, int val3, const char *op);
int if_headers(int line);
void or_if_headers(int if_statements, int line, int line_to_go);
#endif
