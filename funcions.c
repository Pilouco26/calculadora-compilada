#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include "dades.h"


// Declare yy_scan_string directly
extern void yy_scan_string(const char *str);
extern void yyrestart(FILE *input_file);
extern int yyparse();
extern FILE *yyin;
extern FILE *yyout;
extern int yylineno;
extern char *yytext;


static long saved_position = -1;

// Function declarations
void save_line();
void reparse_line();

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

void save_line() {
    if (yyin) {
        saved_position = ftell(yyin);
        fprintf(stderr, "Debug: Saved position: %ld\n", saved_position);
    }
}

void reparse_line() {
    if (saved_position != -1 && yyin) {
        fseek(yyin, saved_position, SEEK_SET);
        fprintf(stderr, "Debug: Reparse from position: %ld\n", saved_position);
        yyrestart(yyin); // Restart the lexer to read from the new position
        yyparse();
    }
}
long find_line_offset(FILE *file, int target_line) {
    int linecount = 0;
    long offset = 0;
    char ch;

    rewind(file); // Reset file pointer to the beginning
    while (linecount < target_line - 1 && (ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            linecount++;
        }
        offset++;
    }

    if (linecount < target_line - 1) {
        return -1; // Line not found
    }

    return offset; // +1 to move past the newline character
}

FILE *open_file_ca3() {
    FILE *file_ca3 = fopen("./CA3.txt", "w"); // Change "w" to "r" if you need to read from it
    if (file_ca3 == NULL) {
        fprintf(stderr, "Error: Could not open ./CA3.txt\n");
        exit(EXIT_FAILURE);
    }
    fprintf(file_ca3, "START\n");
    return file_ca3;
}

void close_file_ca3(FILE *file_ca3) {
    if (file_ca3 != NULL) {
        fprintf(file_ca3, "END\n");
        fclose(file_ca3);
    }
}
void print_list(three_address_code list[], int size, int number_list[], int number_size) {
	int temporals = 0;

    for (int i = 0; i < size; i++) {
        // Print the current list item value
        fprintf(yyout, "t%d: ", i);

        if(list[i].val_info.id_name != NULL) {
          fprintf(yyout, "%s ", strdup(list[i].val_info.id_name));
        }
		else if(!is_number_in_list(number_list, &number_size, list[i].val_info.val_int)){
               fprintf(yyout, "t%d ", temporals++);
		}
        else fprintf(yyout, "%d ", list[i].val_info.val_int);
        fprintf(stderr, "abans de op\n" );
    	// Print the operation character
    	fprintf(yyout, "%s ", list[i].val_op);
        if(list[i].val_info2.id_name != NULL) {
          fprintf(yyout, "%s\n", strdup(list[i].val_info2.id_name));
        }
		if(!is_number_in_list(number_list, &number_size, list[i].val_info2.val_int)){
               fprintf(yyout, "t%d\n", temporals++);
		}
        else fprintf(yyout, "%d\n", list[i].val_info2.val_int);
    }
}


void add_three_address_code(three_address_code list[], int *list_size, int value1, int value2, char* op, char* id1, char * id2) {
    three_address_code integer;

      integer.val_type_list = INT_TYPE;
      integer.val_info.val_type = INT_TYPE;

	integer.val_op = op;
    if(id1 == NULL){
    integer.val_info.val_int = value1;
    integer.val_info.id_name = NULL;
    }
    else  { integer.val_info.id_name = strdup(id1);
}

	if(id2 == NULL){
    integer.val_info2.val_int = value2;
    integer.val_info2.id_name = NULL;
	}
    else  {
          integer.val_info2.id_name = strdup(id2);
    }
    integer.val_type_list = OPERAND_TYPE;
    list[*list_size] = integer;

    (*list_size)++;


}

