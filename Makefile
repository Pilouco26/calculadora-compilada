######################################################################
#
#                           Compiladors
#
######################################################################

CC = gcc
LEX = flex
YACC = bison
LIB = -lfl -lm

SRC_LEX = ./fitxers/lexic.l
SRC_YACC = ./fitxers/sintaxi.y

LEX_OUT = ./out/lex.yy.c
SYMTAB = ./fitxers/symtab.c
YACC_OUT_C = ./fitxers/tab.c
YACC_OUT_H = ./fitxers/tab.h
YACC_OUT = $(YACC_OUT_C) $(YACC_OUT_H)

OTHERS = ./out/exemple.output
OBJ = ./out/*.o

SRC = ./fitxers/main.c
BIN = calculador.exe

SRC_EXTRA = ./fitxers/dades.c ./fitxers/funcions.c

LFLAGS = -d
YFLAGS = -d -v --debug
CFLAGS = -Wall -g -I./fitxers  # Include path for headers

EG_IN = ex_entrada.txt
EG_OUT = ex_sortida.txt

######################################################################

# Ensure the output directory exists
$(shell mkdir -p ./out)

all: $(BIN)

$(BIN): $(YACC_OUT_C) $(YACC_OUT_H) $(LEX_OUT) $(SRC) $(SRC_EXTRA) $(SYMTAB)
	$(CC) -o $(BIN) $(CFLAGS) $(SRC) $(SRC_EXTRA) $(YACC_OUT_C) $(LEX_OUT) $(SYMTAB) $(LIB)

$(YACC_OUT_C) $(YACC_OUT_H): $(SRC_YACC)
	$(YACC) $(YFLAGS) $(SRC_YACC) -o $(YACC_OUT_C)

$(LEX_OUT): $(SRC_LEX)
	$(LEX) $(LFLAGS) $(SRC_LEX)

clean:
	rm -f *~ $(BIN) $(OBJ) $(YACC_OUT) $(OTHERS) $(EG_OUT)

eg: $(EG_IN)
	./$(BIN) $(EG_IN) $(EG_OUT)
	cat $(EG_OUT)
