/* vonbwd14, Will von Behren
   error_handling.c */

#include "error_handling.h"
#include "print_aux.h"

void arg_incorrect()												/* incorrect number of args */
{
	fprintf(stderr, "\nusage: name file\n"); 
    exit(1);
}

void file_nonexist()												/* file does not exist */
{
	fprintf(stderr, "\nerror: file does not exist\n");
	exit(1);
}

void buffer_overflow()												/* buffer overflow */
{
	fprintf(stderr, "\nerror: buffer overflow\n");
	exit(1);
}

void unrecognized_token()
{
	fprintf(stderr, "\nerror: unrecognized token\n");				/* unrecognized token */
	exit(1);
}

void multiple_decimals()
{
	fprintf(stderr, "\nerror: multiple decimals in number\n");		/* multiple decimals in number */
	exit(1);
}

void match_error(token cur_tok, token exp_tok)						/* error in match() function */
{
	fprintf(stderr, "\nmatch: expected ");
	print_token(exp_tok);
	fprintf(stderr, "but encountered ");
	print_token(cur_tok);
	fprintf(stderr, "\n");
	exit(1);
}

void grammar_error(int line_num, token cur_tok)						/* error in input with regard to grammar */
{
	fprintf(stderr, "\ntoken: encountered ");
	print_token(cur_tok);
	fprintf(stderr, "on line %d\n", line_num);
	exit(1);
}


