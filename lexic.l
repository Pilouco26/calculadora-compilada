%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "symtab.h"
#include "sintaxi.tab.h"
#include "funcions.h"
%}

%option yylineno
%option noyywrap
%option noinput
%option nounput
%option debug


lletra  [a-zA-Z]
digit   [0-9]
exponent [eE][+-]?{digit}+
sign    [+-]?

%%

{sign}?{digit}+ { yylval.enter = atoi(yytext); return INTEGER; }
"PI"                        {
                              yylval.real = M_PI;  // Set yylval to the value of pi
                              return FLOAT;        // Return the FLOAT token
                            }

"E"                         {
                              yylval.real = M_E;   // Set yylval to the value of e
                              return FLOAT;        // Return the FLOAT token
                            }




{sign}?{digit}+"."{digit}+({exponent})? {
    yylval.real = atof(yytext);
    return FLOAT;
}

{sign}?{digit}+"."{digit}+"-"({exponent})? {
    yylval.real = atof(yytext);
    return FLOAT;
}

"false"                     {
                              return FALSE;
                            }
"true"                      {
                              return TRUE;
                            }
"and"                       {
                              return AND;
                            }
"or"                        {
                              return OR;
                            }
"not"                       {
                              return NOT;
                            }
"sin"                       {
                              return SIN;
                            }
"cos"                        {
                              return COS;
                            }
"tan"                       {
                              return TAN;
                            }
"len" {
    return LEN;
}

"substr"                       {return SUBSTR;}

"oct"                       {
                                yylval.mode.representacio = "oct";
                                yylval.mode.set = true;
                                return MODE;
                            }
"hex"                       {
                                yylval.mode.representacio = "hex";
                                yylval.mode.set = true;
                                return MODE;
                            }
"dec"                       {
                                yylval.mode.representacio = "dec";
                                yylval.mode.set = true;
                                return MODE;
                            }
"bin"                       {
                                yylval.mode.representacio = "bin";
                                yylval.mode.set = true;
                                return MODE;
                            }

{lletra}({lletra}|{digit})* {
        yylval.ident.lexema = strdup(yytext);
        if (yylval.ident.lexema == NULL) {
            fprintf(stderr, "Memory allocation failed for lexema\n");
            exit(EXIT_FAILURE);
        }
        value_info value;
        if (sym_lookup(yylval.ident.lexema, &value) == SYMTAB_NOT_FOUND) {
                    yylval.ident.length = yyleng;
                    yylval.ident.line = yylineno;
                    yylval.ident.id_val.val_type = UNKNOWN_TYPE;
                    return ID;

        }
        else {
                if(value.val_type == BOOL_TYPE){
                 return ID_BOOL;
                }
                else return ID;
        }
}
\"([^\\"\n\r]*)\" {
    yylval.ident.lexema = strdup(yytext + 1);  // Copy the string starting from the second character (skip the opening quote)
    yylval.ident.lexema[yyleng - 2] = '\0';    // Replace the closing quote with null terminator
    yylval.ident.length = yyleng - 2;          // Adjust the length to exclude the quotes
    yylval.ident.line = yylineno;              // Store the line number
    yylval.ident.id_val.val_type = STRING_TYPE; // Set the type to STRING_TYPE (assuming it's defined)
    return STRING;                             // Return STRING token
}



":="                        { return ASSIGN; }
";"                         { return SEMICOLON; }
","                         { return COMMA; }
"+"                         { return PLUS; }
"-"                         { return MINUS; }
"*"                         { return MULTIPLY; }
"/"                         { return DIVIDE; }
"%"                         { return MOD; }
"**"                        { return POWER; }
"("                         { return OPEN_PARENTHESIS; }
")"                         { return CLOSED_PARENTHESIS; }

">"                         { return GREATER_THAN; }
">="                        { return GREATER_EQUAL; }
"<"                         { return LESS_THAN; }
"<="                        { return LESS_EQUAL; }
"="                         { return EQUAL; }
"<>"                        { return NOT_EQUAL; }

"//".*               { /* Ignore everything after '//' until the end of the line */ }
"#".*[\n]                   { /* Ignore comment and newline */  yylineno++;}
"/*"([^*]|\*+[^*/]|(\*+\/))*"\*/".*[\n] { /* Ignore multi-line comments */}

^[ \t]*[\n]                 { /* Ignore empty lines */ }

[\n]                        { return ENDLINE; }

.                           {}

<<EOF>>                     { return  0; }   /* Signal end of input to Bison */

%%
