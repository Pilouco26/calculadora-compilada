#ifndef EXEMPLE_FUNCIONS_H
#define EXEMPLE_FUNCIONS_H


int init_analisi_lexica(char *);
int end_analisi_lexica();

int init_analisi_sintactica(char *);
int end_analisi_sintactica(void);

int analisi_semantica(void);
void int_to_binary(int, char *);
void float_to_binary(float, char *);
char *substr(const char *string, int start, int length);
void yyerror(char *explanation);


#endif
