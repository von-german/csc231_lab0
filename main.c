/* vonbwd14, Will von Behren
   main.c   */

#include "token_production.h" 
#include "error_handling.h"
#include "print_aux.h"

int main(int argc, char ** argv)
{
   FILE * ifp;                                       /* input file pointer */
	token cur_tok;                                    /* take in token for each iteration */
   token tok_list[BUFF_SIZE];                        /* list of tokens */
   int list_size;                                    /* list count */

   if(argc != 2)                       				  /* error check for file arguments */
      arg_incorrect();

   ifp = fopen(argv[1], "r");                        /* open file */

   if(ifp == NULL)                                   /* error check for opening file */
      file_nonexist();

   list_size = 0;

   do
   {
      cur_tok = tokenizer(ifp);
      if(list_size < 256)
      { 
         tok_list[list_size] = cur_tok;
         list_size++;
      }
      else
         buffer_overflow();

      print_token(cur_tok);

   } while(cur_tok != 13);

   fclose(ifp);

   return 0;
}
