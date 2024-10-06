%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exemple.tab.h"
#include "exemple_funcions.h"

%}

%option yylineno
%option noyywrap
%option noinput
%option nounput

lletra  [a-zA-Z]
alpha   ((a-zA-Z))+
digit   [0-9]

%%
{alpha}		                {sscanf(yytext, "%s", yylval.cadena); return (STRING);}
{digit}                     {yylval.enter = atoi(yytext); return (INTEGER);}
{lletra}({lletra}|{digit})* {
                              yylval.ident.lexema = strdup(yytext);
                              yylval.ident.lenght = yyleng;
                              yylval.ident.line = yylineno;
                              yylval.ident.id_val.val_type = UNKNOWN_TYPE;
                              return ID;
                            }

"="                         { return ASSIGN; }

{digit}({digit})*           {
                              yylval.enter = atoi(yytext);
                              return INTEGER;
                            }

";"                         { return SEMICOLON; }

"+"                         { return PLUS; }
"-"                         { return MINUS; }
"*"                         { return MULTIPLY; }
"/"                         { return DIVIDE; }



^[ \t]*[\n]                 {}

[\n]                        { return ENDLINE; }

.                           {}

