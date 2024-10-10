%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "exemple.tab.h"
#include "exemple_funcions.h"
%}

%option yylineno
%option noyywrap
%option noinput
%option nounput

lletra  [a-zA-Z]
digit   [0-9]
exponent [eE][+-]?{digit}+
sign    [+-]?

%%

{sign}?{digit}+ { yylval.enter = atoi(yytext); return INTEGER; }
{sign}?{digit}"."{digit}+({exponent})? {
                              yylval.real = atof(yytext);
                              return FLOAT;
                            }

{lletra}({lletra}|{digit})* {
                              yylval.ident.lexema = strdup(yytext);
                              yylval.ident.length = yyleng;
                              yylval.ident.line = yylineno;
                              yylval.ident.id_val.val_type = UNKNOWN_TYPE;
                              return ID;
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
"+"                         { return PLUS; }
"-"                         { return MINUS; }
"*"                         { return MULTIPLY; }
"/"                         { return DIVIDE; }
"%"                         { return MOD; }
"**"                         { return POWER; }
"("                         { return OPEN_PARENTHESIS; }
")"                         { return CLOSED_PARENTHESIS; }

"//".*[\n]                  { /* Ignore comment and newline */ }
"#".*[\n]                   { /* Ignore comment and newline */ }
"/*"([^*]|\*+[^*/]|(\*+\/))*"\*/"[\n] { /* Ignore multi-line comments */ }





^[ \t]*[\n]                 { /* Ignore empty lines */ }


[\n]                        { return ENDLINE; }

.                           {}

<<EOF>>                     { return  0; }   /* Signal end of input to Bison */

%%

