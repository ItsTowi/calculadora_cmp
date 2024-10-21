CC = gcc
CFLAGS = -Wall -g
LEX = flex
YACC = bison
LEX_FILE = lexer.l
YACC_FILE = parser.y
OBJ_FILES = main.o parser.tab.o lex.yy.o

all: calc

calc: $(OBJ_FILES)
	$(CC) $(CFLAGS) -o calc $(OBJ_FILES)

parser.tab.c: $(YACC_FILE)
	$(YACC) -d $(YACC_FILE)

lex.yy.c: $(LEX_FILE)
	$(LEX) $(LEX_FILE)

clean:
	rm -f calc $(OBJ_FILES) parser.tab.c parser.tab.h lex.yy.c