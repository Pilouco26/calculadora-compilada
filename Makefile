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
SRC_LEX = bison_flex/lexic.l
SRC_YACC = bison_flex/sintaxi.y
SRC_MAIN = main.c
SRC_EXTRA = c_files/dades.c c_files/funcions.c c_files/symtab.c c_files/funcions_ca3.c

# Bison outputs
YACC_OUT_C = bison_output/sintaxi.tab.c
YACC_OUT_H = bison_output/sintaxi.tab.h
YACC_OUT = $(YACC_OUT_C) $(YACC_OUT_H)
OTHERS = bison_output/sintaxi.output

# Flex output
LEX_OUT = bison_output/lex.yy.c

# Object files and binary
BIN = calculadora.exe

# Flags
LFLAGS =
YFLAGS = -d -v
CFLAGS = -Wall -g

# Example inputs/outputs
EG_IN = text/ex_entrada.txt
EG_OUT = text/ex_sortida.txt
EG_3AC = text/CA3.txt

# Debug logs
DEBUG_LOG = log/debug.log

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
	mkdir -p bison_output
	$(YACC) $(YFLAGS) -o $(YACC_OUT_C) $(SRC_YACC) 2> $(DEBUG_LOG)

# Generate lexer files
lex: $(SRC_LEX)
	mkdir -p bison_output
	$(LEX) $(LFLAGS) -o $(LEX_OUT) $(SRC_LEX) 2>> $(DEBUG_LOG)

# Clean build artifacts
clean:
	rm -f *~ $(BIN) $(YACC_OUT) $(LEX_OUT) $(OTHERS) $(EG_OUT) $(DEBUG_LOG) c_files/*~ bison_flex/*~ bison_output/*

# Run example
eg: $(EG_IN)
	./$(BIN) $(EG_IN) $(EG_OUT)
	cat $(EG_OUT)

# Run example
run: all
	# Ensure the text directory exists
	mkdir -p text
	# Create or truncate text/CA3.txt to ensure it's ready
	> $(EG_3AC)
	# Run the program with example input and output files
	./$(BIN) $(EG_IN) $(EG_OUT) > $(DEBUG_LOG) 2>&1
	# Show the output on the console
	cat $(EG_3AC)
