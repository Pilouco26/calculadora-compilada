#ifndef EXEMPLE_FUNCIONS_H
#define EXEMPLE_FUNCIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "dades.h"

int init_analisi_lexica(char *);
int end_analisi_lexica();

int init_analisi_sintactica(char *);
int end_analisi_sintactica(void);
void save_line();
FILE *open_file_ca3();
void print_list(three_address_code [], int, int [], int, float float_list[], int float_size,char * );
void add_three_address_code(three_address_code[], int *, int , int, char *, char* id1, char * id2);
void close_file_ca3();
void reparse_line();
long find_line_offset(FILE *file, int number);
int analisi_semantica(void);
void int_to_binary(int, char *);
void float_to_binary(float, char *);
char *substr(const char *string, int start, int length);
void yyerror(char *explanation);
int is_number_in_list(int list[],  int *size, int number);
int is_number_in_list_without_retrieving(int list[],  int size, int number);
void add_to_float_list(float float_list[], int *float_size, float value);
void add_three_address_code_float(three_address_code list[], int *list_size, float value1, float value2, char* op, char* id1, char * id2, int conversion1, int conversion2);
#endif
