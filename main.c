#define BUFF_SIZE 255
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char ** argv)
{
   FILE * ifp;																	/* input file pointer */
   char read_buff[BUFF_SIZE];												/* input buffer */
   int count;																	/* counter */
   int decimal_used;															/* boolean for decimal check */

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
   	if(isalpha(read_buff[count]))										/* produce token for id */
   	{	
   		while(isalpha(read_buff[count]) ||							/* letter, digit, or underscore? */
   				isdigit(read_buff[count]) ||
   				read_buff[count] == '_'	)
	   	{
	   		count++;
	   		read_buff[count] = fgetc(ifp);
	   	}

	   	fprintf(stdout, "id ");
	   	count = 0;
	   }

	   if(isdigit(read_buff[count]))										/* produce token for number */
	   {
	   	decimal_used = 0;
	   	count++;
	   	read_buff[count] = fgetc(ifp);
	   	if(read_buff[count] == '.')									/* check for first decimal */
	   	{
	   		decimal_used = 1;
	   		count++;
	   		read_buff[count] = fgetc(ifp);
	   		if(read_buff[count] == '.')								/* decimal error check */
	   		{
	   			fprintf(stderr, "error: multiple decimals in number");
	   			exit(1);
	   		}
	   	}
	   	while(isdigit(read_buff[count]))								/* continue reading digits */
	   	{
	   		count++;
	   		read_buff[count] = fgetc(ifp);
				if(read_buff[count] == '.' && decimal_used)			/* decimal error check */
	   		{
	   			fprintf(stderr, "error: multiple decimals in number");
	   			exit(1);
	   		}
	   		else if(read_buff[count] == '.')							/* first decimal - allowed */
		   	{
		   		decimal_used = 1;
		   		count++;
		   		read_buff[count] = fgetc(ifp);
		   		if(read_buff[count] == '.')							/* decimal error check */
		   		{
		   			fprintf(stderr, "error: multiple decimals in number");
		   			exit(1);
		   		}
		   	}
	    	}
	    	if(read_buff[count] != ' '  &&								/* incorrect character usage */
	    		read_buff[count] != '\n' &&
	    		read_buff[count] != '\t' &&
	    		read_buff[count] != EOF)									
	    	{
	    		fprintf(stderr, "error: unrecognized token");
	    		exit(1);
	    	}
	    	
	    	fprintf(stdout, "number ");
	    	count = 0;
	   }

   	read_buff[count] = fgetc(ifp);
	}

	switch(read_buff[count])
	{
		case '-':																/* case '_' */

		count++;
		read_buff[count] = fgetc(ifp);
		
		if(read_buff[count] == ' ')										/* produce token for substract */
			fprintf(stdout, "subtract ");

		if(isdigit(read_buff[count]))										/* produce token for number */
		{
	   	decimal_used = 0;
	   	count++;
	   	read_buff[count] = fgetc(ifp);
	   	if(read_buff[count] == '.')									/* check for first decimal */
	   	{
	   		decimal_used = 1;
	   		count++;
	   		read_buff[count] = fgetc(ifp);
	   		if(read_buff[count] == '.')								/* decimal error check */
	   		{
	   			fprintf(stderr, "error: multiple decimals in number");
	   			exit(1);
	   		}
	   	}
	   	while(isdigit(read_buff[count]))								/* continue reading digits */
	   	{
	   		count++;
	   		read_buff[count] = fgetc(ifp);
				if(read_buff[count] == '.' && decimal_used)			/* decimal error check */
	   		{
	   			fprintf(stderr, "error: multiple decimals in number");
	   			exit(1);
	   		}
	   		else if(read_buff[count] == '.')							/* first decimal - allowed */
		   	{
		   		decimal_used = 1;
		   		count++;
		   		read_buff[count] = fgetc(ifp);
		   		if(read_buff[count] == '.')							/* decimal error check */
		   		{
		   			fprintf(stderr, "error: multiple decimals in number");
		   			exit(1);
		   		}
		   	}
	    	}
	    	if(read_buff[count] != ' '  &&								/* incorrect character usage */
	    		read_buff[count] != '\n' &&
	    		read_buff[count] != '\t' &&
	    		read_buff[count] != EOF)									
	    	{
	    		fprintf(stderr, "error: unrecognized token");
	    		exit(1);
	    	}
	    	
	    	fprintf(stdout, "number ");
	    	count = 0;
	   }

		if(read_buff[count] == '.')										/* check for first decimal */
	   {
	   	decimal_used = 1;
	   	count++;
	   	read_buff[count] = fgetc(ifp);
	   	if(read_buff[count] == '.')									/* decimal error check */
	   	{
	   		fprintf(stderr, "error: multiple decimals in number");
	   		exit(1);
	   	}
	   
	   	while(isdigit(read_buff[count]))								/* continue reading digits */
	   	{
	   		count++;
	   		read_buff[count] = fgetc(ifp);
				if(read_buff[count] == '.' && decimal_used)			/* decimal error check */
	   		{
	   			fprintf(stderr, "error: multiple decimals in number");
	   			exit(1);
	   		}
	   		else if(read_buff[count] == '.')							/* first decimal - allowed */
		   	{
		   		decimal_used = 1;
		   		count++;
		   		read_buff[count] = fgetc(ifp);
		   		if(read_buff[count] == '.')							/* decimal error check */
		   		{
		   			fprintf(stderr, "error: multiple decimals in number");
		   			exit(1);
		   		}
		   	}
	    	}
	    	if(read_buff[count] != ' '  &&								/* incorrect character usage */
	    		read_buff[count] != '\n' &&
	    		read_buff[count] != '\t' &&
	    		read_buff[count] != EOF)									
	    	{
	    		fprintf(stderr, "error: unrecognized token");
	    		exit(1);
	    	}
	    	
	    	fprintf(stdout, "number ");
	    	count = 0;
	   }


	} /* switch */



	fclose(ifp);
	fprintf(stdout, "nomore\n");

   return 0;
}


