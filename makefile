# vonbwd14, Will von Behren
# makefile

all: lexer

lexer: main.o token_production.o error_handling.o print_aux.o parse.o
	gcc main.o token_production.o error_handling.o print_aux.o parse.o -o lexer

main.o: main.c token_production.h error_handling.h print_aux.h parse.h
	gcc -Wall -pedantic -c main.c

token_production.o: token_production.c token_production.h error_handling.h
	gcc -Wall -pedantic -c token_production.c 

error_handling.o: error_handling.c error_handling.h token_production.h
	gcc -Wall -pedantic -c error_handling.c

print_aux.o: print_aux.c print_aux.h error_handling.h token_production.h
	gcc -Wall -pedantic -c print_aux.c

parse.o: parse.c parse.h token_production.h error_handling.h print_aux.h
	gcc -Wall -pedantic -c parse.c


clean: 
	rm *o lexer
