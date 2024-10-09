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

":="                        { return ASSIGN; }
";"                         { return SEMICOLON; }
"+"                         { return PLUS; }
"-"                         { return MINUS; }
"*"                         { return MULTIPLY; }
"/"                         { return DIVIDE; }

"//".*[\n]                  { /* Ignore comment and newline */ }
"#".*[\n]                   { /* Ignore comment and newline */ }
"/*"([^*]|\*+[^*/])*\*+\/  { /* Ignore multi-line comments */ }


^[ \t]*[\n]                 {}

[\n]                        { return ENDLINE; }

.                           {}

<<EOF>>                     { return  0; }   /* Signal end of input to Bison */

%%

