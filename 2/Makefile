# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Flex and Bison
FLEX = flex
BISON = bison

# Source files
LEXER_SRC = lexer.l
PARSER_SRC = parser.y
SYMTAB_SRC = symtab.c
MAIN_SRC = main.c

# Generated files
LEXER_C = lex.yy.c
PARSER_C = parser.tab.c
PARSER_H = parser.tab.h

# Output executable
OUTPUT = calculator

# Default target
all: $(OUTPUT)

# Build the executable
$(OUTPUT): $(LEXER_C) $(PARSER_C) $(SYMTAB_SRC) $(MAIN_SRC)
	$(CC) $(CFLAGS) -o $@ $^

# Generate lexer C file from Flex source
$(LEXER_C): $(LEXER_SRC)
	$(FLEX) -o $@ $<

# Generate parser C and header files from Bison source
$(PARSER_C) $(PARSER_H): $(PARSER_SRC)
	$(BISON) -d $<

# Clean up generated files
clean:
	rm -f $(LEXER_C) $(PARSER_C) $(PARSER_H) $(OUTPUT)

# Phony targets
.PHONY: all clean
