#include "error_handling.h"
#include "token_production.h"

void arg_incorrect()												/* incorrect number of args */
{
	fprintf(stderr, "\nusage: name file\n"); 
    fflush(stderr);
    exit(1);
}

void file_nonexist()												/* file does not exist */
{
	fprintf(stderr, "\nerror: file does not exist\n");
	fflush(stderr);
	exit(1);
}

void buffer_overflow()												/* buffer overflow */
{
	fprintf(stderr, "\nerror: buffer overflow\n");
	fflush(stderr);
	exit(1);
}

void unrecognized_token()
{
	fprintf(stderr, "\nerror: unrecognized token\n");				/* unrecognized token */
	fflush(stderr);
	exit(1);
}

void multiple_decimals()
{
	fprintf(stderr, "\nerror: multiple decimals in number\n");		/* multiple decimals in number */
	fflush(stderr);
	exit(1);
}

