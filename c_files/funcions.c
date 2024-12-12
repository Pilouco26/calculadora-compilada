#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include "../header_files/dades.h"



extern void yy_scan_string(const char *str);
extern void yyrestart(FILE *input_file);
extern int yyparse();
extern FILE *yyin;
extern FILE *yyout;
extern int yylineno;
extern int lines;
extern char *yytext;



int init_analisi_lexica(char *filename)
{
    int error;
    yyin = fopen(filename, "r");
    if (yyin == NULL) {
        error = EXIT_FAILURE;
    } else {
        error = EXIT_SUCCESS;
    }
    return error;
}

void float_to_binary(float val, char *binary) {
    union {
        float f;
        uint32_t u;
    } float_union;

    float_union.f = val;
    for (int i = 31; i >= 0; i--) {
        binary[31 - i] = (float_union.u & (1U << i)) ? '1' : '0';
    }
    binary[32] = '\0'; // Null terminator for the string
}

char* substr(const char* str, int start, int length) {
    if (start < 0 || length < 0 || start + length > strlen(str)) {
        return NULL; // Handle invalid input
    }
    char* substr = (char*)malloc(length + 1);
    if (!substr) {
        return NULL; // Handle memory allocation failure
    }
    strncpy(substr, str + start, length);
    substr[length] = '\0'; // Null-terminate the string
    return substr;
}

// Function to convert an integer to a binary string
void int_to_binary(int n, char *binary) {
    binary[0] = '\0'; // Initialize the string
    int i;
    for (i = 31; i >= 0; i--) {
        strcat(binary, (n & (1 << i)) ? "1" : "0");
    }
    // Trim leading zeros for a more compact binary representation
    char *trimmed = binary;
    while (*trimmed == '0' && *(trimmed + 1) != '\0') {
        trimmed++;
    }
    strcpy(binary, trimmed);
}

int end_analisi_lexica()
{
    int error;
    error = fclose(yyin);
    if (error == 0) {
        error = EXIT_SUCCESS;
    } else {
        error = EXIT_FAILURE;
    }
    return error;
}

int init_analisi_sintactica(char* filename)
{
    int error = EXIT_SUCCESS;
    yyout = fopen(filename, "w");
    if (yyout == NULL) {
        error = EXIT_FAILURE;
    }
    return error;
}

int end_analisi_sintactica(void)
{
    int error;
    error = fclose(yyout);
    if (error == 0) {
        error = EXIT_SUCCESS;
    } else {
        error = EXIT_FAILURE;
    }
    return error;
}

int analisi_semantica(void)
{
    int error;
    if (yyparse() == 0) {
        error = EXIT_SUCCESS;
    } else {
        error = EXIT_FAILURE;
    }
    return error;
}

void yyerror(char *explanation)
{
    fprintf(stderr, "Error: %s , in line %d\n", explanation, yylineno);
}

