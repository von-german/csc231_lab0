#include "print_aux.h"

void print_token(token tok)
{
	switch(tok)
      {
         case 1:
            fprintf(stdout, "lparen ");
            fflush(stdout);
            break;
         case 2:
            fprintf(stdout, "rparen ");
            fflush(stdout);
            break;
         case 3:
            fprintf(stdout, "add ");
            fflush(stdout);
            break;
         case 4:
            fprintf(stdout, "subtract ");
            fflush(stdout);
            break;
         case 5:
            fprintf(stdout, "multiply ");
            fflush(stdout);
            break;
         case 6:
            fprintf(stdout, "divide ");
            fflush(stdout);
            break;
         case 7:
            fprintf(stdout, "exponent ");
            fflush(stdout);
            break;
         case 8:
            fprintf(stdout, "assign ");
            fflush(stdout);
            break;
         case 9:
            fprintf(stdout, "semi ");
            fflush(stdout);
            break;
         case 10:
            fprintf(stdout, "output ");
            fflush(stdout);
            break;
         case 11:
            fprintf(stdout, "id ");
            fflush(stdout);
            break;
         case 12:
            fprintf(stdout, "number ");
            fflush(stdout);
            break;
         case 13:
            fprintf(stdout, "nomore\n");
            fflush(stdout);
            break;
         default:
         	unrecognized_token();
      }
}
