# Version
VERSION = 0.0.1

# Compiler flags
CFLAGS = -Wall -W -O2 -s -pipe
CLMFLAGS = -Wall -W -O2 -s -pipe -lm
LFLAGS =  -O2 -s -pipe

all: lemon grammar parser lexer

parser: grammar.c lexer
	cat main.cpp >> grammar.c
	g++ -o parser $(LFLAGS) grammar.c lexer.o -lgearman

grammar: grammar.y lemon
	  ./lemon grammar.y

lemon: lemon.c
	  gcc -o $@ $(LFLAGS)  $<

lexer: lexer.l grammar lexglobal.h
	flex -i lexer.l
	test -e lex.yy.c && mv lex.yy.c lexer.c
	gcc -o lexer.o -c lexer.c 
	
clean: 
	rm -f grammar.c grammar.h grammar.out parser *.o
	  

