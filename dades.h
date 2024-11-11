#ifndef EXEMPLE_DADES_H
#define EXEMPLE_DADES_H
#include <stdbool.h>

#define STR_MAX_LENGTH 200
#define MAX_EXPRESSIONS 100  // Define a maximum number of expressions


typedef enum {
  UNKNOWN_TYPE = 1,
  INT_TYPE,
  FLOAT_TYPE,
  STRING_TYPE,
  BOOL_TYPE
} data_type;


typedef struct {
  data_type val_type;
  int val_int;
  float val_float;
  char *val_string;    // To store strings
  bool val_bool;    // To store strings
} value_info;


typedef struct {
  value_info expr_val[MAX_EXPRESSIONS];  // Array of expressions
  int index;  // Index to follow the array
} expression_list;

typedef struct{
  int contador;
  int linea;

} heading;

char *type_to_str(data_type val_type);
char *value_info_to_str(value_info value);


#endif
