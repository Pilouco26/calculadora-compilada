#ifndef SYMTAB_H
#define SYMTAB_H

#include <stddef.h>

/* Define types used in symtab.c */
typedef const char* sym_name_type;
typedef int sym_value_type;
typedef int sym_scope_id;

/* Define constants used in symtab.c */
#define SYM_BUCKET_MAX 256
#define SYM_ROOT_SCOPE 0
#define SYMTAB_OK 0
#define SYMTAB_DUPLICATE 1
#define SYMTAB_NO_MEMORY 2
#define SYMTAB_NOT_FOUND 3
#define SYMTAB_STACK_OVERFLOW 4
#define SYMTAB_STACK_UNDERFLOW 5
#define SYMTAB_NOT_TOP 6

/* Function prototypes */
int sym_add(sym_name_type name, sym_value_type *value
#ifdef SYM_MULTIPLE_NAME_SPACES
, unsigned name_space
#endif
);

int sym_enter(sym_name_type name, sym_value_type *value
#ifdef SYM_MULTIPLE_NAME_SPACES
, unsigned name_space
#endif
);

int sym_lookup(sym_name_type name, sym_value_type *value
#ifdef SYM_POINTS_TO_VALUE
, sym_value_type **value
#endif
#ifdef SYM_MULTIPLE_NAME_SPACES
, unsigned name_space
#endif
);

int sym_remove(sym_name_type name
#ifdef SYM_MULTIPLE_NAME_SPACES
, unsigned name_space
#endif
);

#ifdef SYM_DEEP_BINDING
int sym_push_scope(void);
int sym_pop_scope(void);
#endif

#ifdef SYM_HISTOGRAM
void sym_histogram(void);
#endif

#ifdef SYM_REQUIRE_SET_SCOPE
void sym_set_scope(sym_scope_id scope);
#endif

#ifdef SYM_REQUIRE_GLOBAL
int sym_global_add(sym_name_type name, sym_value_type *value
#ifdef SYM_MULTIPLE_NAME_SPACES
, unsigned name_space
#endif
);

int sym_global_enter(sym_name_type name, sym_value_type *value
#ifdef SYM_MULTIPLE_NAME_SPACES
, unsigned name_space
#endif
);

int sym_global_lookup(sym_name_type name, sym_value_type *value
#ifdef SYM_POINTS_TO_VALUE
, sym_value_type **value
#endif
#ifdef SYM_MULTIPLE_NAME_SPACES
, unsigned name_space
#endif
);

int sym_global_remove(sym_name_type name
#ifdef SYM_MULTIPLE_NAME_SPACES
, unsigned name_space
#endif
);
#endif

#endif /* SYMTAB_H */
