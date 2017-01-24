/* vonbwd14, Will von Behren
   main.c   */
   
#include "token_production.h"

int main(int argc, char ** argv)
{
															
   if(argc != 2)											/* error check for file arguments */
   {	
      fprintf(stderr, "usage: name file\n"); 
      fflush(stderr);
      exit(1);
   }

   tokenizer(argv[1]);

   return 0;
}
