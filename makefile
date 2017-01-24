# vonbwd14, Will von Behren
# makefile

all: lexer

lexer: main.o token_production.o
	gcc main.o token_production.o -o lexer

main.o: main.c token_production.h
	gcc -Wall -pedantic -c main.c

token_production.o: token_production.c token_production.h
	gcc -Wall -pedantic -c token_production.c 


clean: 
	rm *o lexer
