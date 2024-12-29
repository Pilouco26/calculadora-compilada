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
  BOOL_TYPE,
  IDS_TYPE,
  LIST_TYPE,
} data_type;

typedef enum {
  POW_TYPE = 1,
  ADD_TYPE,
  MUL_TYPE,
  SUB_TYPE,
  DIV_TYPE
} op_type;

typedef enum {
  OPERATOR_TYPE =0,
  OPERAND_TYPE,
  ID_TYPE
} list_type;

typedef struct {
  data_type val_type;
  int val_int;
  float val_float;
  char *val_string;    // To store strings
  bool val_bool;    // To store strings
  char *id_name;
  int linea;
  char *id_name_copy;
  int type_conversion;
  int temp;
} value_info;

typedef struct {
  char *lexema;
  int length;
  int line;
  value_info id_val;
} ident;

typedef struct{
  ident id;
  value_info op;
} array;


typedef struct{
  value_info val_info;
  value_info val_info2;
  list_type val_type_list;
  char *val_op;
  char type_op;
  char *id_name;
  int delta;
  int repeat;
} three_address_code;


typedef struct {
  value_info expr_val[MAX_EXPRESSIONS];  // Array of expressions
  int index;  // Index to follow the array
} expression_list;

typedef struct{
  int contador;
  int linea;
  int end;
} heading;

char *type_to_str(data_type val_type);
char *value_info_to_str(value_info value);


#endif
