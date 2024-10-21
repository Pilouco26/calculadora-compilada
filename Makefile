######################################################################
#
#                           Compiladors
#
######################################################################

CC = gcc
LEX = flex
YACC = bison
LIB = -lfl -lm  # Added -lm to link the math library

SRC_LEX = lexic.l
SRC_YACC = sintaxi.y

LEX_OUT = lex.yy.c
YACC_OUT_C = sintaxi.tab.c
YACC_OUT_H = sintaxi.tab.h
YACC_OUT = $(YACC_OUT_C) $(YACC_OUT_H)

OTHERS = sintaxi.output
OBJ = *.o

SRC = main.c
BIN = calculadora.exe

SRC_EXTRA = dades.c funcions.c symtab.c

LFLAGS =
YFLAGS = -d -v
CFLAGS = -Wall -g

EG_IN = ex_entrada.txt
EG_OUT = ex_sortida.txt



######################################################################

all : yacc lex
	$(CC) -o $(BIN) $(CFLAGS) $(SRC) $(SRC_EXTRA) $(YACC_OUT_C) $(LEX_OUT) $(LIB)

yacc : $(SRC_YACC)
	$(YACC) $(YFLAGS) $(SRC_YACC)

lex : $(SRC_LEX)
	$(LEX) $(LFLAGS) $(SRC_LEX)

clean :
	rm -f *~ $(BIN) $(OBJ) $(YACC_OUT) $(LEX_OUT) $(OTHERS) $(EG_OUT)

eg : $(EG_IN)
	./$(BIN) $(EG_IN) $(EG_OUT)
	cat $(EG_OUT)
