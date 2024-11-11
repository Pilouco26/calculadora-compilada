#ifndef EXEMPLE_FUNCIONS_H
#define EXEMPLE_FUNCIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int init_analisi_lexica(char *);
int end_analisi_lexica();

int init_analisi_sintactica(char *);
int end_analisi_sintactica(void);
void save_line();
void reparse_line();
long find_line_offset(FILE *file, int number);
int analisi_semantica(void);
void int_to_binary(int, char *);
void float_to_binary(float, char *);
char *substr(const char *string, int start, int length);
void yyerror(char *explanation);


#endif
