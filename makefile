all: lexer

lexer: main.o
	gcc main.o -o lexer

main.o: main.c 
	gcc -c main.c


clean: 
	rm *o lexer
