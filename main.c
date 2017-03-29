/* vonbwd14, Will von Behren
   main.c   */

#include "token_production.h" 
#include "error_handling.h"
#include "print_aux.h"
#include "parse.h"

int main(int argc, char ** argv)
{
   FILE * ifp;                                       /* input file pointer */
	int list_count;                                   /* list count */
   token cur_tok;                                    /* take in token for each iteration */
   token tok_list[BUFF_SIZE];                        /* list of tokens */
   

   if(argc != 2)                       				  /* error check for file arguments */
      arg_incorrect();

   ifp = fopen(argv[1], "r");                        /* open file */

   if(ifp == NULL)                                   /* error check for opening file */
      file_nonexist();

   list_count = 0;

   do
   {
      cur_tok = tokenizer(ifp);
      if(list_count < 256)
      { 
         tok_list[list_count] = cur_tok;
         list_count++;
      }
      else
         buffer_overflow();

      print_token(cur_tok);

   } while(cur_tok != 13);

   list_count = 0;

   P(tok_list, & list_count);
   
   fclose(ifp);

   return 0;
}
