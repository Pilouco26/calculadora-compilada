%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"  // Include the Bison header file
%}

%option yylineno
%option noyywrap
%option noinput
%option nounput

%%
[0-9]+          { yylval.ival = atoi(yytext); return INTEGER; }
[0-9]+\.[0-9]+  { yylval.fval = atof(yytext); return REAL; }
\"[^\"]*\"      { yylval.sval = strdup(yytext); return STRING; }
true|false      { yylval.bval = (strcmp(yytext, "true") == 0); return BOOLEAN; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.sval = strdup(yytext); return IDENTIFIER; }
\/\/.*          { /* skip single-line comments */ }
\/\*([^*]|\*+[^*/])*\*\/ { /* skip multi-line comments */ }
%%
