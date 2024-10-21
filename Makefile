CC = gcc
CFLAGS = -Wall -g
LEX = flex
YACC = bison

all: calc

calc: main.o parser.tab.o lex.yy.o
	$(CC) $(CFLAGS) -o calc main.o parser.tab.o lex.yy.o -lm

main.o: main.c datos.h
	$(CC) $(CFLAGS) -c main.c

parser.tab.o: parser.tab.c datos.h
	$(CC) $(CFLAGS) -c parser.tab.c

parser.tab.c parser.tab.h: parser.y
	$(YACC) -d parser.y

lex.yy.c: lexer.l
	$(LEX) lexer.l

clean:
	rm -f *.o calc parser.tab.c parser.tab.h lex.yy.c
