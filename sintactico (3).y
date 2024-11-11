%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <math.h>
    #include "./symtab/symtab.h"

    extern FILE* yyin;
    extern int yylineno;

    int yylex();
%}

%code requires {
    #include "types.h"
    #include "functions.h"
}

%error-verbose

%union {
    variable var;
};

%token ASIGN OPEN CLOSE CALC CERT FALS AND OR NOT IF THEN ELSE ELSIF FI WHILE DO DONE REPEAT UNTIL FOR IN DOTS DOTCOMMAS
%token <var> GREATER LESS GREATEREQUAL LESSEQUAL EQUAL NOTEQUAL
%token <var> SUM SUBS MULT DIV POW MOD
%token <var> VAR ID_BOOLEAN ID_ARITMETIC
%token <var> MODE NEWLINE

%type <var> ops opm op_bool expr_arit sum mul pow expr_bool and not expr aux m n sentence sentences elsif P Q

%start prog

%%

prog: calc sentences                         { if(mode) { complete($2.next_list, num_lines); emit("HALT"); }}          

calc: CALC MODE NEWLINE                      { if($2.string[1] == 'n') mode = MODECALC; else mode = MODEPROG; printf("MODE: %i\n", mode); }

sentences: sentences m sentence              { if(mode) complete($1.next_list, $2.enter); $$ = $3; }
    | sentence                               { $$ = $1; }
;

sentence: ID_ARITMETIC ASIGN expr NEWLINE    { sym_enter($1.string, &$3); if(mode) process_id($1.string, $3); else{ printf("Variable %s -> ", $1.string); show_result($3); }}
    | ID_BOOLEAN ASIGN expr NEWLINE          { sym_enter($1.string, &$3); if(mode) process_id($1.string, $3); else{ printf("Variable %s -> ", $1.string); show_result($3); }}
    | expr NEWLINE                           { if(mode) process_expr($1); else show_result($1); }
    | IF OPEN expr_bool CLOSE THEN NEWLINE m sentences elsif FI NEWLINE    { mode_error(); complete($3.true_list, $7.enter); if($9.enter == -1) $$.next_list = join($3.false_list, $8.next_list); else { $$.next_list = join($8.next_list, $9.next_list); complete($3.false_list, $9.enter); } }
    | WHILE OPEN m expr_bool CLOSE DO NEWLINE m sentences DONE NEWLINE     { mode_error(); complete($4.true_list, $8.enter); complete($9.next_list, $3.enter); $$.next_list = $4.false_list; char* aux; aux = malloc(50); sprintf(aux, "GOTO %d", $3.enter + 1); emit(aux); }
    | REPEAT NEWLINE m sentences UNTIL OPEN expr_bool CLOSE NEWLINE        { mode_error(); complete($7.true_list, $3.enter); $$.next_list = join($7.false_list, $4.next_list); }
    | WHILE OPEN CLOSE DO NEWLINE m sentences DONE NEWLINE                 { mode_error(); char* aux; aux = malloc(50); sprintf(aux, "GOTO %d", $6.enter + 1); emit(aux); $$.next_list = $7.next_list; }
    | FOR OPEN DOTCOMMAS CLOSE DO NEWLINE m sentences DONE NEWLINE         { mode_error(); char* aux; aux = malloc(50); sprintf(aux, "GOTO %d", $6.enter + 1); emit(aux); $$.next_list = $8.next_list; }
    | P DO NEWLINE sentences DONE NEWLINE                                          { mode_error(); complete($4.next_list, num_lines); char *aux, *aux2; aux = malloc(50); sprintf(aux, "%s = %s ADDI 1", $1.expr, $1.expr); emit(aux); aux2 = malloc(50); sprintf(aux2, "GOTO %d", $1.enter + 1); emit(aux2); $$.next_list = $1.next_list; }
;

P: Q DOTS expr_arit CLOSE                    { if($3.type != INT) yyerror("Values in range have to be integers."); $$.expr = $1.expr; $$.enter = num_lines; char *aux; aux = malloc(50); sprintf(aux, "IF %s LEI %s GOTO %d", $1.expr, $3.expr, ($$.enter+3)); emit(aux); $$.next_list = create_list(num_lines); emit("GOTO"); }

Q: FOR OPEN ID_ARITMETIC IN expr_arit        { variable v; if(sym_lookup($3.string, &v) != SYMTAB_NOT_FOUND) yyerror("Identifier declared previously. Has to be new."); if($5.type != INT) yyerror("Values in range have to be integers."); char *aux; aux = malloc(50); sprintf(aux, "%s := %s", $3.string, $5.expr); emit(aux); $$.expr = $3.string; }

m: { $$.enter = num_lines; }

n: { $$.next_list = create_list(num_lines); emit("GOTO"); }

elsif: { $$.enter = -1; }
    | ELSE NEWLINE n m sentences { $$.next_list = join($3.next_list, $5.next_list); $$.enter = $4.enter; }
    | ELSIF OPEN n m expr_bool CLOSE THEN NEWLINE m sentences elsif { $$.enter = $4.enter; complete($5.true_list, $9.enter); if($11.enter == -1) $$.next_list = join($3.next_list, join($5.false_list, $10.next_list)); else { $$.next_list = join($3.next_list, join($10.next_list, $11.next_list)); complete($5.false_list, $11.enter); }}
;

expr: expr_arit                             { $$ = $1; }
    | expr_bool                             { $$ = $1; }
;

/* Expresions booleanes */

expr_bool: expr_bool OR m and               { $$.boolean = $1.boolean || $3.boolean; $$.type = BOOLEAN; if(mode){ $$.true_list = join($1.true_list, $4.true_list); $$.false_list = $4.false_list; complete($1.false_list, $3.enter); }}
    | and                                   { $$ = $1; }
;

and: and AND m not                          { $$.boolean = $1.boolean && $3.boolean; $$.type = BOOLEAN; if(mode){ $$.true_list = $4.true_list; $1.false_list = join($1.false_list, $4.false_list); complete($1.true_list, $3.enter); }}
    | not                                   { $$ = $1; }
;

not: NOT aux                                { $$ = $2; $$.boolean = !$$.boolean; $$.type = BOOLEAN; if(mode){ $$.true_list = $2.false_list; $$.false_list = $2.true_list; }}
    | aux                                   { $$ = $1; }
;

aux: expr_arit op_bool expr_arit            { $$ = check_boolean($1, $2, $3); } 
    | CERT                                  { $$.boolean = true; $$.type = BOOLEAN; if(mode){ $$.expr = "TRUE"; $$.true_list = create_list(num_lines); emit("GOTO"); $$.false_list = NULL; }}
    | FALS                                  { $$.boolean = false; $$.type = BOOLEAN; if(mode){ $$.expr = "FALSE"; $$.false_list = create_list(num_lines); emit("GOTO"); $$.true_list = NULL; }}
    | OPEN expr_bool CLOSE                  { $$ = $2; if(mode){ $$.expr = malloc(50); sprintf($$.expr, "(%s)", $2.expr); }}
    | ID_BOOLEAN                            { if(mode) $$.expr = $1.string; if(sym_lookup($1.string, &$$) == SYMTAB_NOT_FOUND) yyerror("Identifier does not exist"); }
;

/* Expresions aritmetiques */

expr_arit: expr_arit ops sum                { $$ = calculate($1, $2, $3); } 
    | sum                                   { $$ = $1; }
;

sum: sum opm mul                            { $$ = calculate($1, $2, $3); } 
    | mul                                   { $$ = $1; }
;

mul: mul POW pow                            { $$ = calculate($1, $2, $3); } 
    | pow                                   { $$ = $1; }
;

pow: ID_ARITMETIC                           { if(sym_lookup($1.string, &$$) == SYMTAB_NOT_FOUND) yyerror("Identifier does not exist"); if(mode) $$.expr = $1.string; }
    | VAR                                   { $$ = $1; if(mode) $$.expr = get_var($1); }
    | OPEN expr_arit CLOSE                  { $$ = $2; if(mode){ $$.expr = malloc(50); sprintf($$.expr, "%s", $2.expr); }}
    | SUBS VAR                              { change_symbol(&$$, $2); if(mode){ $$.expr = malloc(50); if($2.type == INT) sprintf($$.expr, "CHSI %s", get_var($2)); else sprintf($$.expr, "CHSF %s", get_var($2)); }}
    | SUBS ID_ARITMETIC                     { variable v; if(sym_lookup($2.string, &v) == SYMTAB_NOT_FOUND) yyerror("Identifier does not exist"); change_symbol(&$$, v); if(mode) {$$.expr = malloc(50); if(v.type == INT) sprintf($$.expr, "CHSI %s", $2.string); else sprintf($$.expr, "CHSF %s", $2.string); }}
;

/* Operadors */

ops: SUM                                    { $$ = $1; }
    | SUBS                                  { $$ = $1; }
;

opm: MULT                                   { $$ = $1; }
    | DIV                                   { $$ = $1; }
    | MOD                                   { $$ = $1; }
;

op_bool: GREATER                            { $$ = $1; }
    | LESS                                  { $$ = $1; }
    | GREATEREQUAL                          { $$ = $1; }
    | LESSEQUAL                             { $$ = $1; }
    | EQUAL                                 { $$ = $1; }
    | NOTEQUAL                              { $$ = $1; }
;

%%

void yyerror(const char *msg)
{
    printf("[ERROR] %s in line: %i", msg, yylineno);
    exit(1);
}

int main(int argc, char **argv)
{
    var_count = 0;
    num_lines = 0;
    lines = (char **) malloc(50);
    if (argc > 1)
        yyin = fopen(argv[1],"r");
    else
        yyin = stdin;
    yyparse();
    if (!mode) return 0;
    for (int i = 0; i < num_lines; i++)
    {
        printf("%s\n", lines[i]);
    }
    return 0;
}
