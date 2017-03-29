/* vonbwd14, Will von Behren
   parse.c */

#include "parse.h" 

void match(token * tok_list, int * list_count, token exp_tok)
{
	if(tok_list[(*list_count)] == exp_tok)
		(*list_count)++;
	else
		match_error(tok_list[(*list_count)], exp_tok);
}

void P(token * tok_list, int * list_count)
{
	if(tok_list[(*list_count)] == id || tok_list[(*list_count)] == output)
	{
		S(tok_list, list_count);
		P(tok_list, list_count);
	}
	else if(tok_list[(*list_count)] == nomore)
		return;
	else
		grammar_error(24, tok_list[(*list_count)]);
}

void S(token * tok_list, int * list_count)
{
	if(tok_list[(*list_count)] == id)
	{
		match(tok_list, list_count, id);
		match(tok_list, list_count, assign);
		E(tok_list, list_count);
		match(tok_list, list_count, semi);
	}
	else if(tok_list[(*list_count)] == output)
	{
		match(tok_list, list_count, output);
		match(tok_list, list_count, id);
		match(tok_list, list_count, semi);
	}
	else
		grammar_error(43, tok_list[(*list_count)]);
}

void E(token * tok_list, int * list_count)
{
	if(tok_list[(*list_count)] == lparen || 
	   tok_list[(*list_count)] == id || 
	   tok_list[(*list_count)] == number)
	{
		T(tok_list, list_count);
		E_prime(tok_list, list_count);
	}
	else
		grammar_error(56, tok_list[(*list_count)]);
}

void E_prime(token * tok_list, int * list_count)
{
	if(tok_list[(*list_count)] == add)
	{
		match(tok_list, list_count, add);
		T(tok_list, list_count);
		E_prime(tok_list, list_count);
	}
	else if(tok_list[(*list_count)] == subtract)
	{
		match(tok_list, list_count, subtract);
		T(tok_list, list_count);
		E_prime(tok_list, list_count);
	}
	else if(tok_list[(*list_count)] == semi || tok_list[(*list_count)] == rparen)
		return;
	else
		grammar_error(76, tok_list[(*list_count)]);
}

void T(token * tok_list, int * list_count)
{
	if(tok_list[(*list_count)] == lparen || 
	   tok_list[(*list_count)] == id || 
	   tok_list[(*list_count)] == number)
	{
		F(tok_list, list_count);
		T_prime(tok_list, list_count);
	}
	else
		grammar_error(89, tok_list[(*list_count)]);
}

void T_prime(token * tok_list, int * list_count)
{
	if(tok_list[(*list_count)] == multiply)
	{
		match(tok_list, list_count, multiply);
		F(tok_list, list_count);
		T_prime(tok_list, list_count);
	}
	else if(tok_list[(*list_count)] == divide)
	{
		match(tok_list, list_count, divide);
		F(tok_list, list_count);
		T_prime(tok_list, list_count);
	}
	else if(tok_list[(*list_count)] == semi ||
		    tok_list[(*list_count)] == add ||
		    tok_list[(*list_count)] == subtract || 
		    tok_list[(*list_count)] == rparen)
		return;
	else
		grammar_error(112, tok_list[(*list_count)]);
}

void F(token * tok_list, int * list_count)
{
	if(tok_list[(*list_count)] == lparen || 
	   tok_list[(*list_count)] == id || 
	   tok_list[(*list_count)] == number)
	{
		X(tok_list, list_count);
		F_prime(tok_list, list_count);
	}
	else
		grammar_error(125, tok_list[(*list_count)]);
}

void F_prime(token * tok_list, int * list_count)
{
	if(tok_list[(*list_count)] == exponent)
	{
		match(tok_list, list_count, exponent);
		X(tok_list, list_count);
		F_prime(tok_list, list_count);
	}
	else if(tok_list[(*list_count)] == semi || 
		    tok_list[(*list_count)] == add || 
		    tok_list[(*list_count)] == subtract || 
		    tok_list[(*list_count)] == multiply || 
		    tok_list[(*list_count)] == divide || 
		    tok_list[(*list_count)] == rparen)
		return;
	else
		grammar_error(144, tok_list[(*list_count)]);
}

void X(token * tok_list, int * list_count)
{
	if(tok_list[(*list_count)] == lparen)
	{
		match(tok_list, list_count, lparen);
		E(tok_list, list_count);
		match(tok_list, list_count, rparen);
	}
	else if(tok_list[(*list_count)] == id)
		match(tok_list, list_count, id);
	else if(tok_list[(*list_count)] == number)
		match(tok_list, list_count, number);
	else
		grammar_error(160, tok_list[(*list_count)]);
}
