#define BUFF_SIZE 255
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
   FILE * ifp;																	/* input file pointer */
   char read_buff[BUFF_SIZE];												/* input buffer */
   int count;																	/* counter */

   if(argc != 2)																/* error check for file arguments */
   {	
      fprintf(stderr, "usage: name file\n"); 
      exit(1);
   }

   ifp = fopen(argv[1], "r");												/* open file */
   if(ifp == NULL)															/* error check for opening file */
   {
      fprintf(stderr, "error: file does not exist\n");			/* error check for nonexistent file */
      exit(1);
   }

   count = 0;
   read_buff[count] = fgetc(ifp);										/* new character */
	while(read_buff[count] == ' '  ||									/* clear white-space */
			read_buff[count] == '\n' || 
			read_buff[count] == '\t')											
		read_buff[count] = fgetc(ifp);																		
	
   while(read_buff[count] != EOF)										/* read char one-by-one from input file into read_buff */
   {
   	count++;
   	read_buff[count] = fgetc(ifp);
	}

	read_buff[count] = '\0';
   
   fprintf(stdout, "%s", read_buff);

   return 0;
}


