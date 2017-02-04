# vonbwd14, Will von Behren
# makefile

all: lexer

lexer: main.o token_production.o error_handling.o
	gcc main.o token_production.o error_handling.o -o lexer

main.o: main.c token_production.h error_handling.h
	gcc -Wall -pedantic -c main.c

token_production.o: token_production.c token_production.h error_handling.h
	gcc -Wall -pedantic -c token_production.c 

error_handling.o: error_handling.c error_handling.h token_production.h
	gcc -Wall -pedantic -c error_handling.c


clean: 
	rm *o lexer
