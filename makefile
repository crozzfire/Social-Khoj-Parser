# Version
VERSION = 0.0.1

# Compiler flags
CFLAGS = -Wall -W -O2 -s -pipe
CLMFLAGS = -Wall -W -O2 -s -pipe -lm
LFLAGS =  -O2 -s -pipe

all: parser lexer

parser: main.cpp lexer
	g++ -o parser $(LFLAGS) main.cpp lexer.o -lgearman

lexer: lexer.l grammar.h lexglobal.h
	flex -i lexer.l
	test -e lex.yy.c && mv lex.yy.c lexer.c
	gcc -o lexer.o -c lexer.c 
	
clean: 
	rm -f lemon grammar.c grammar.h grammar.out parser *.o


