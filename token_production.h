/* vonbwd14, Will von Behren 
   token_production.h */

#ifndef TOKEN_PRODUCTION_H
#define TOKEN_PRODUCTION_H

typedef enum {lparen=1, rparen, add, subtract, multiply, divide, 
			  exponent, assign, semi, output, id, number, nomore} token;

#define BUFF_SIZE 256
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

token tokenizer(FILE * ifp);

#endif
