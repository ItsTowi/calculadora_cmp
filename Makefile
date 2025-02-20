######################################################################
#
#                           Compiladors
#
######################################################################

CC = gcc
LEX = flex
YACC = bison
LIB = -lfl

SRC_LEX = lexer.l
SRC_YACC = parser.y

LEX_OUT = lex.yy.c
YACC_OUT_C = parser.tab.c
YACC_OUT_H = parser.tab.h
YACC_OUT = $(YACC_OUT_C) $(YACC_OUT_H)

OTHERS = exemple.output
OBJ = *.o

SRC = main.c
BIN = calc.exe

SRC_EXTRA = datos.c funciones.c symtab.c

LFLAGS =
YFLAGS = -d -v
CFLAGS = -Wall -g

EG_IN = ex_entrada2.txt
EG_OUT = salida.txt

######################################################################

all : yacc lex
	$(CC) -o $(BIN) $(CFLAGS) $(SRC) $(SRC_EXTRA) $(YACC_OUT_C) $(LEX_OUT) $(LIB) -lm
	./$(BIN) $(EG_IN) $(EG_OUT)

yacc : $(SRC_YACC)
	$(YACC) $(YFLAGS) $(SRC_YACC)

lex : $(SRC_LEX)
	$(LEX) $(LFLAGS) $(SRC_LEX)

clean :
	rm -f *~ $(BIN) $(OBJ) $(YACC_OUT) $(LEX_OUT) $(OTHERS) $(EG_OUT) log.txt

eg : $(EG_IN)
	./$(BIN) $(EG_IN) $(EG_OUT)
	cat $(EG_OUT)

debug : 
	$(YACC) $(YFLAGS) -Wcounterexamples $(SRC_YACC)

######################################################################
