######################################################################
#                            Compiladors
######################################################################

# Compiler and tools
CC = gcc
LEX = flex
YACC = bison

# Libraries
LIB = -lfl -lm  # Math and Flex libraries

# Source files
SRC_LEX = lexic.l
SRC_YACC = sintaxi.y
SRC_MAIN = main.c
SRC_EXTRA = dades.c funcions.c symtab.c

# Bison outputs
YACC_OUT_C = sintaxi.tab.c
YACC_OUT_H = sintaxi.tab.h
YACC_OUT = $(YACC_OUT_C) $(YACC_OUT_H)
OTHERS = sintaxi.output

# Flex output
LEX_OUT = lex.yy.c

# Object files and binary
BIN = calculadora.exe

# Flags
LFLAGS =
YFLAGS = -d -v
CFLAGS = -Wall -g

# Example inputs/outputs
EG_IN = ex_entrada.txt
EG_OUT = ex_sortida.txt
EG_3AC = CA3.txt

# Debug logs
DEBUG_LOG = debug.log

######################################################################
# Targets
######################################################################

.PHONY: all yacc lex clean eg run

# Default target
all: $(BIN)

# Build binary
$(BIN): yacc lex $(SRC_MAIN) $(SRC_EXTRA)
	$(CC) -o $(BIN) $(CFLAGS) $(SRC_MAIN) $(SRC_EXTRA) $(YACC_OUT_C) $(LEX_OUT) $(LIB)

# Generate parser files
yacc: $(SRC_YACC)
	$(YACC) $(YFLAGS) $(SRC_YACC) 2> $(DEBUG_LOG)

# Generate lexer files
lex: $(SRC_LEX)
	$(LEX) $(LFLAGS) $(SRC_LEX) 2>> $(DEBUG_LOG)

# Clean build artifacts
clean:
	rm -f *~ $(BIN) $(YACC_OUT) $(LEX_OUT) $(OTHERS) $(EG_OUT) $(DEBUG_LOG)

# Run example
eg: $(EG_IN)
	./$(BIN) $(EG_IN) $(EG_OUT)
	cat $(EG_OUT)

# Run example
run: all
	# Create or truncate ./CA3.txt to ensure it's ready
	> ./CA3.txt
	# Run the program with example input and output files
	./$(BIN) $(EG_IN) $(EG_OUT) > $(DEBUG_LOG) 2>&1
	# Show the output on the console
	cat $(EG_3AC)
