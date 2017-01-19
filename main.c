#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
   FILE *ifp;				/* input file pointer */

   if(argc != 2)			/*error check for file arguments*/
   {	
	fprintf(stderr, "usage: name file\n"); 
	exit(1);
   }

   ifp = fopen(argv[1], "r");		/*open file*/
   if(ifp == NULL)			/*error check for opening file*/
   {
	fprintf(stderr, "error: file does not exist\n");
	exit(1);
   }

   return 0;
}






