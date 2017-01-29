/* vonbwd14, Will von Behren
   main.c   */
   
#include "token_production.h"

int main(int argc, char ** argv)
{
   FILE * ifp;                                                          /* input file pointer */
	token holder;                                                        /* take in token for each iteration */

   if(argc != 2)                       											/* error check for file arguments */
   {	
      fprintf(stderr, "usage: name file\n"); 
      fflush(stderr);
      exit(1);
   }

   ifp = fopen(argv[1], "r");                                           /* open file */

   if(ifp == NULL)                                                      /* error check for opening file */
   {
      fprintf(stderr, "\nerror: file does not exist\n");                /* error check for nonexistent file */
      fflush(stderr);
      exit(1);
   }

   do
   {
      holder = tokenizer(ifp);
      switch (holder)
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
            fprintf(stdout, "nomore ");
            fflush(stdout);
            break;
      }
   }while(holder != 13);

   fclose(ifp);

   return 0;
}
