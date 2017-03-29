/* vonbwd14, Will von Behren
   parse.h */

#ifndef PARSE_H
#define PARSE_H

#include "token_production.h"
#include "error_handling.h"

void match(token * tok_list, int * list_count, token exp_tok);
void P(token * tok_list, int * list_count);
void S(token * tok_list, int * list_count);
void E(token * tok_list, int * list_count);
void E_prime(token * tok_list, int * list_count);
void T(token * tok_list, int * list_count);
void T_prime(token * tok_list, int * list_count);
void F(token * tok_list, int * list_count);
void F_prime(token * tok_list, int * list_count);
void X(token * tok_list, int * list_count);

#endif
