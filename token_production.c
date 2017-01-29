/* vonbwd14, Will von Behren 
   token_production.h */

#include "token_production.h"

token tokenizer(FILE * ifp)
{
	char read_buff[BUFF_SIZE];															/* input buffer */
	int count;																			/* counter */
	int decimal_used;																	/* boolean for decimal check */

	count = 0;
	read_buff[count] = fgetc(ifp);														/* new character */	

	while(read_buff[count] != EOF)														/* read char one-by-one from input file into read_buff */
	{
		while(isspace(read_buff[count]))												/* clear white-space */										
			  read_buff[count] = fgetc(ifp);
	   	
		if(read_buff[count] == 'p')														/* produce token for OUTPUT */
		{
			count++;
			read_buff[count] = fgetc(ifp);

			if(read_buff[count] == 'r')
			{
				count++;
				read_buff[count] = fgetc(ifp);
				
				if(read_buff[count] == 'i')
				{
					count++;
					read_buff[count] = fgetc(ifp);
					
					if(read_buff[count] == 'n')
					{
						count++;
						read_buff[count] = fgetc(ifp);
						
						if(read_buff[count] == 't')
						{
							count++;
							read_buff[count] = fgetc(ifp);
						
							if(read_buff[count] == ' ')
							{
								count++;
								read_buff[count] = fgetc(ifp);
								return 10;
							}
							else
							{
								fseek(ifp, -1, SEEK_CUR);
								count--;
							}
						}
						else
						{
							fseek(ifp, -1, SEEK_CUR);
							count--;
						}
					}
					else
					{
						fseek(ifp, -1, SEEK_CUR);
						count--;
					}
				}
				else
				{
					fseek(ifp, -1, SEEK_CUR);
					count--;
				}
			}
			else
			{
				fseek(ifp, -1, SEEK_CUR);
				count--;
			}
		}

	   	if(isalpha(read_buff[count]))													/* produce token for ID */ 
		{	
			do
		   	{
		   		if(count < 256)
		   		{
		   			count++;
		   			read_buff[count] = fgetc(ifp);
		   		}
		   		else
		   		{
		   			fprintf(stderr, "error: buffer overflow");
		   			fflush(stderr);
		   			exit(1);
		   		}
		   	}
		   	while(isalpha(read_buff[count]) ||											/* letter, digit, or underscore? */
	   			  isdigit(read_buff[count]) ||
	   			  read_buff[count] == '_'	);

		   	if(isspace(read_buff[count]))
		   		return 11;
		   	else
		   	{
		   		fprintf(stderr, "\nerror: unrecognized token\n");
		   		fflush(stderr);
		   		exit(1);
		   	}
		}
		else if(isdigit(read_buff[count]))												/* produce token for NUMBER */
		{
			decimal_used = 0;
		   	count++;
		   	read_buff[count] = fgetc(ifp);
		   
		   	if(read_buff[count] == '.')													/* check for first decimal */
		   	{
		   		decimal_used = 1;
		   		count++;
		   		read_buff[count] = fgetc(ifp);
		   		
		   		if(read_buff[count] == '.')												/* decimal error check */
		   		{
		   			fprintf(stderr, "\nerror: multiple decimals in number\n");
		   			fflush(stderr);
		   			exit(1);
		   		}
			}

		   	while(isdigit(read_buff[count]))											/* continue reading digits */
		   	{
		   		if(count < 256)
		   		{
		   			count++;
		   			read_buff[count] = fgetc(ifp);
		   		}
		   		else
		   		{
		   			fprintf(stderr, "error: buffer overflow");
		   			fflush(stderr);
		   			exit(1);
		   		}

				if(read_buff[count] == '.' && decimal_used)								/* decimal error check */
		   		{
		   			fprintf(stderr, "\nerror: multiple decimals in number\n");
		   			fflush(stderr);
		   			exit(1);
		   		}
		   		else if(read_buff[count] == '.')										/* first decimal - allowed */
			   	{
			   		decimal_used = 1;
				   	if(count < 256)
			   		{
			   			count++;
			   			read_buff[count] = fgetc(ifp);
			   		}
			   		else
			   		{
			   			fprintf(stderr, "error: buffer overflow");
			   			fflush(stderr);
			   			exit(1);
			   		}
			   		
			   		if(read_buff[count] == '.')											/* decimal error check */
			   		{
			   			fprintf(stderr, "\nerror: multiple decimals in number\n");
			   			fflush(stderr);
			   			exit(1);
			   		}
			   	}
		    }
		    
		    if(!isspace(read_buff[count]) &&											/* incorrect character usage */
				  read_buff[count] != '(' &&
				  read_buff[count] != ')' &&
				  read_buff[count] != '+' &&											/* function to check for operators? */
				  read_buff[count] != '-' &&
				  read_buff[count] != '*' &&
				  read_buff[count] != '/' &&
				  read_buff[count] != '=' &&
				  read_buff[count] != ';')									
		    {
		    	fprintf(stderr, "\nerror: unrecognized token\n");
		    	fflush(stderr);
		    	exit(1);
		    }
		    
		    return 12;
		}
		else switch(read_buff[count])
		{
			case '-':																	/* case '-' */

			if(count < 256)
		   	{
		   		count++;
		   		read_buff[count] = fgetc(ifp);
		   	}
		   	else
		   	{
		   		fprintf(stderr, "error: buffer overflow");
		   		fflush(stderr);
		   		exit(1);
		   	}
			
			if(read_buff[count] == ' ')													/* produce token for SUBTRACT */	
				return 4;
			else 
			{
				if(isdigit(read_buff[count]))											/* produce token for NUMBER */
				{
				   	decimal_used = 0;
				   	
				   	if(count < 256)
			   		{
			   			count++;
			   			read_buff[count] = fgetc(ifp);
			   		}
			   		else
			   		{
			   			fprintf(stderr, "error: buffer overflow");
			   			fflush(stderr);
			   			exit(1);
			   		}
				   
				   	if(read_buff[count] == '.')											/* check for first decimal */
				   	{
						decimal_used = 1;
						
						if(count < 256)
				   		{
				   			count++;
				   			read_buff[count] = fgetc(ifp);
				   		}
				   		else
				   		{
				   			fprintf(stderr, "error: buffer overflow");
				   			fflush(stderr);
				   			exit(1);
				   		}

						if(read_buff[count] == '.')										/* decimal error check */
						{
							fprintf(stderr, "\nerror: multiple decimals in number\n");
							fflush(stderr);
							exit(1);
						}
					}
					
					while(isdigit(read_buff[count]))									/* continue reading digits */
					{		   		
						if(count < 256)
				   		{
				   			count++;
				   			read_buff[count] = fgetc(ifp);
				   		}
				   		else
				   		{
				   			fprintf(stderr, "error: buffer overflow");
				   			fflush(stderr);
				   			exit(1);
				   		}

						if(read_buff[count] == '.' && decimal_used)						/* decimal error check */
						{
							fprintf(stderr, "\nerror: multiple decimals in number\n");
							fflush(stderr);
							exit(1);
						}
						else if(read_buff[count] == '.')								/* first decimal - allowed */
						{
							decimal_used = 1;
							
							if(count < 256)
					   		{
					   			count++;
					   			read_buff[count] = fgetc(ifp);
					   		}
					   		else
					   		{
					   			fprintf(stderr, "error: buffer overflow");
					   			fflush(stderr);
					   			exit(1);
					   		}
							
							if(read_buff[count] == '.')									/* decimal error check */
							{
								fprintf(stderr, "\nerror: multiple decimals in number\n");
								fflush(stderr);
								exit(1);
							}
						}
					}
					
					if(!isspace(read_buff[count]) &&									/* incorrect character usage */
					      read_buff[count] != '(' &&
					      read_buff[count] != ')' &&
						  read_buff[count] != '+' &&									/* function to check for operators? */
						  read_buff[count] != '-' &&
						  read_buff[count] != '*' &&
						  read_buff[count] != '/' &&
						  read_buff[count] != '=' &&
						  read_buff[count] != ';')									
					{
						fprintf(stderr, "\nerror: unrecognized token\n");
						fflush(stderr);
						exit(1);
					}
					
					return 12;
				}

				if(read_buff[count] == '.')										
				{
					decimal_used = 1;
					
					if(count < 256)
			   		{
			   			count++;
			   			read_buff[count] = fgetc(ifp);
			   		}
			   		else
			   		{
			   			fprintf(stderr, "error: buffer overflow");
			   			fflush(stderr);
			   			exit(1);
			   		}

					if(read_buff[count] == '.')											/* decimal error check */
					{
						fprintf(stderr, "\nerror: multiple decimals in number\n");
						fflush(stderr);
						exit(1);
					}
						   
					while(isdigit(read_buff[count]))									/* continue reading digits */
					{
						if(count < 256)
				   		{
				   			count++;
				   			read_buff[count] = fgetc(ifp);
				   		}
				   		else
				   		{
				   			fprintf(stderr, "error: buffer overflow");
				   			fflush(stderr);
				   			exit(1);
				   		}

						if(read_buff[count] == '.' && decimal_used)						/* decimal error check */
						{
							fprintf(stderr, "\nerror: multiple decimals in number\n");
							fflush(stderr);
							exit(1);
						}
						else if(read_buff[count] == '.')								/* first decimal - allowed */
						{
							decimal_used = 1;
							
							if(count < 256)
					   		{
					   			count++;
					   			read_buff[count] = fgetc(ifp);
					   		}
					   		else
					   		{
					   			fprintf(stderr, "error: buffer overflow");
					   			fflush(stderr);
					   			exit(1);
					   		}

							if(read_buff[count] == '.')									/* decimal error check */
							{
								fprintf(stderr, "\nerror: multiple decimals in number\n");
								fflush(stderr);
								exit(1);
							}
						}
					}
					
					if(!isspace(read_buff[count]) &&									/* incorrect character usage */
					      read_buff[count] != '(' &&
					      read_buff[count] != ')' &&
						  read_buff[count] != '+' &&									/* function to check for operators? */
						  read_buff[count] != '-' &&
						  read_buff[count] != '*' &&
						  read_buff[count] != '/' &&
						  read_buff[count] != '=' &&
						  read_buff[count] != ';')									
					{
						fprintf(stderr, "\nerror: unrecognized token\n");
						fflush(stderr);
						exit(1);
					}

					return 12;
				}		   
			}   /* end else */
				break;

			case '*':																	/* case '*' or '**' */
				count++;
				read_buff[count] = fgetc(ifp);
		
				if(read_buff[count] == '*')
					return 7;
				else
				{
					fseek(ifp, -1, SEEK_CUR);
					count--;
					return 5;
				}
				break;

			case '(':																	/* case '(' */
				return 1;
				break;

			case ')':																	/* case ')' */
				return 2;
				break;

			case '+':																	/* case '+' */
				return 3;
				break;

			case '/':																	/* case '/' */
				return 4;
				break;

			case '=':																	/* case '=' */
				return 8;
				break;

			case ';':																	/* case ';' */
				return 9;
				break;
		} /* end switch */

		count = 0;
		read_buff[count] = fgetc(ifp);
	}   /* end while */

	return 13;
}	/* end function tokenizer */
