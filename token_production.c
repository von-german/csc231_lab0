#include "token_production.h"


void tokenizer(const char * const file_name)
{
	FILE * ifp;																			/* input file pointer */
	char read_buff[BUFF_SIZE];															/* input buffer */
	int count;																			/* counter */
	int decimal_used;																	/* boolean for decimal check */

	ifp = fopen(file_name, "r");														/* open file */
	if(ifp == NULL)																		/* error check for opening file */
	{
	fprintf(stderr, "error: file does not exist\n");									/* error check for nonexistent file */
	fflush(stderr);
	exit(1);
	}

	count = 0;
	read_buff[count] = fgetc(ifp);														/* new character */	

	while(read_buff[count] != EOF)														/* read char one-by-one from input file into read_buff */
	{
		while(read_buff[count] == ' '  ||												/* clear white-space */
			  read_buff[count] == '\n' || 
		  	  read_buff[count] == '\t')											
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
								fprintf(stdout, "output ");
								fflush(stdout);
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

	   	if(isalpha(read_buff[count]))														/* produce token for ID */
	   	{	
	   		while(isalpha(read_buff[count]) ||												/* letter, digit, or underscore? */
	   				isdigit(read_buff[count]) ||
	   				read_buff[count] == '_'	)
		   	{
		   		count++;
		   		read_buff[count] = fgetc(ifp);
		   	}

		   	fprintf(stdout, "id ");
		   	fflush(stdout);
		   	count = 0;
		   }

		   else if(isdigit(read_buff[count]))												/* produce token for NUMBER */
		   {
		   	decimal_used = 0;
		   	count++;
		   	read_buff[count] = fgetc(ifp);
		   	if(read_buff[count] == '.')														/* check for first decimal */
		   	{
		   		decimal_used = 1;
		   		count++;
		   		read_buff[count] = fgetc(ifp);
		   		if(read_buff[count] == '.')													/* decimal error check */
		   		{
		   			fprintf(stderr, "error: multiple decimals in number");
		   			fflush(stderr);
		   			exit(1);
		   		}
		   	}
		   	while(isdigit(read_buff[count]))												/* continue reading digits */
		   	{
		   		count++;
		   		read_buff[count] = fgetc(ifp);
					if(read_buff[count] == '.' && decimal_used)								/* decimal error check */
		   		{
		   			fprintf(stderr, "error: multiple decimals in number");
		   			fflush(stderr);
		   			exit(1);
		   		}
		   		else if(read_buff[count] == '.')											/* first decimal - allowed */
			   	{
			   		decimal_used = 1;
			   		count++;
			   		read_buff[count] = fgetc(ifp);
			   		if(read_buff[count] == '.')												/* decimal error check */
			   		{
			   			fprintf(stderr, "error: multiple decimals in number");
			   			fflush(stderr);
			   			exit(1);
			   		}
			   	}
		    	}
		    	if(read_buff[count] != ' '  &&												/* incorrect character usage */
		    		read_buff[count] != '\n' &&
		    		read_buff[count] != '\t' &&
		    		read_buff[count] != EOF)									
		    	{
		    		fprintf(stderr, "error: unrecognized token");
		    		fflush(stderr);
		    		exit(1);
		    	}
		    	
		    	fprintf(stdout, "number ");
		    	fflush(stdout);
		    	count = 0;
		   }

			else switch(read_buff[count])
			{
				case '-':																	/* case '_' */

					count++;
					read_buff[count] = fgetc(ifp);
					
					if(read_buff[count] == ' ')												/* produce token for SUBTRACT */
					{												
						fprintf(stdout, "subtract ");
						fflush(stdout);
					}
					else 
					{
						if(isdigit(read_buff[count]))										/* produce token for NUMBER */
						{
						   	decimal_used = 0;
						   	count++;
						   	read_buff[count] = fgetc(ifp);
						   	if(read_buff[count] == '.')											/* check for first decimal */
						   	{
						   		decimal_used = 1;
						   		count++;
						   		read_buff[count] = fgetc(ifp);
						   		if(read_buff[count] == '.')										/* decimal error check */
						   		{
						   			fprintf(stderr, "error: multiple decimals in number");
						   			fflush(stderr);
						   			exit(1);
						   		}
						   	}
						   	while(isdigit(read_buff[count]))									/* continue reading digits */
						   	{
						   		count++;
						   		read_buff[count] = fgetc(ifp);
									if(read_buff[count] == '.' && decimal_used)					/* decimal error check */
						   		{
						   			fprintf(stderr, "error: multiple decimals in number");
						   			fflush(stderr);
						   			exit(1);
						   		}
						   		else if(read_buff[count] == '.')								/* first decimal - allowed */
							   	{
							   		decimal_used = 1;
							   		count++;
							   		read_buff[count] = fgetc(ifp);
							   		if(read_buff[count] == '.')									/* decimal error check */
							   		{
							   			fprintf(stderr, "error: multiple decimals in number");
							   			fflush(stderr);
							   			exit(1);
							   		}
							   	}
						    	}
						    	if(read_buff[count] != ' '  &&									/* incorrect character usage */
						    		read_buff[count] != '\n' &&
						    		read_buff[count] != '\t' &&
						    		read_buff[count] != EOF)									
						    	{
						    		fprintf(stderr, "error: unrecognized token");
						    		fflush(stderr);
						    		exit(1);
						    	}
						    	
						    	fprintf(stdout, "number ");
						    	fflush(stdout);
						    	count = 0;
							}

						if(read_buff[count] == '.')										
						{
					   		decimal_used = 1;
					   		count++;
					   		read_buff[count] = fgetc(ifp);
						   	if(read_buff[count] == '.')											/* decimal error check */
						   	{
						   		fprintf(stderr, "error: multiple decimals in number");
						   		fflush(stderr);
						   		exit(1);
						   	}
						   
						   	while(isdigit(read_buff[count]))									/* continue reading digits */
						   	{
						   		count++;
						   		read_buff[count] = fgetc(ifp);
								if(read_buff[count] == '.' && decimal_used)					/* decimal error check */
						   		{
						   			fprintf(stderr, "error: multiple decimals in number");
						   			fflush(stderr);
						   			exit(1);
						   		}
						   		else if(read_buff[count] == '.')								/* first decimal - allowed */
							   	{
							   		decimal_used = 1;
							   		count++;
							   		read_buff[count] = fgetc(ifp);
							   		if(read_buff[count] == '.')									/* decimal error check */
							   		{
							   			fprintf(stderr, "error: multiple decimals in number");
							   			fflush(stderr);
							   			exit(1);
							   		}
							   	}
						    }
						    if(read_buff[count] != ' '  &&									/* incorrect character usage */
						       read_buff[count] != '\n' &&
							   read_buff[count] != '\t' &&
							   read_buff[count] != EOF)									
						    {
						    	fprintf(stderr, "error: unrecognized token");
						    	fflush(stderr);
						    	exit(1);
						    }
						    	
						    fprintf(stdout, "number ");
						    fflush(stdout);
						    count = 0;
						}		   
					}
					break;

				case '*':																	/* case '*' or '**' */
					count++;
					read_buff[count] = fgetc(ifp);
					if(read_buff[count] == '*')
					{
						fprintf(stdout, "exponent ");
						fflush(stdout);
					}
					else
					{
						fseek(ifp, -1, SEEK_CUR);
						count--;
						fprintf(stdout, "multiply ");
						fflush(stdout);
					}
					break;

				case '(':																	/* case '(' */
					fprintf(stdout, "lparen ");
					fflush(stdout);
					count++;															/* check for imaginary expression */
					read_buff[count] = fgetc(ifp);
					if(read_buff[count] == '-')
					{
						count++;
						read_buff[count] = fgetc(ifp);
						while(isdigit(read_buff[count]) || read_buff[count] == '.')
						{
							if(read_buff[count] == '.' && !decimal_used)
							{
								decimal_used = 1;
							}
							else if(read_buff[count] == '.' && decimal_used)
							{
								fprintf(stderr, "error: multiple decimals in number");
								fflush(stderr);
								exit(1);
							}

							count++;
							read_buff[count] = fgetc(ifp);
						}

						if(read_buff[count] != ')')								/* assume "(-" pair is met with only number and ending ')' */
						{
							fprintf(stderr, "error: missing rparen token");
							fflush(stderr);
							exit(1);
						}

						fprintf(stdout, "number ");
						fprintf(stdout, "rparen ");
						fflush(stdout);

						count++;
						read_buff[count] = fgetc(ifp);
						if(read_buff[count] == '*')
						{
							count++;
							read_buff[count] = fgetc(ifp);
							if(read_buff[count] == '*')
							{
								fprintf(stdout, "exponent ");
								fflush(stdout);
								count++;
								read_buff[count] = fgetc(ifp);
								if(read_buff[count] == '(')
								{
									fprintf(stdout, "lparen ");
									fflush(stdout);
									count++;
									read_buff[count] = fgetc(ifp);
									if(read_buff[count] == '1')
									{
										fprintf(stdout, "number ");
										fflush(stdout);
										count++;
										read_buff[count] = fgetc(ifp);
										if(read_buff[count] == '/')
										{
											fprintf(stdout, "division ");
											fflush(stdout);
											count++;
											read_buff[count] = fgetc(ifp);
											if(read_buff[count] != '1')
											{
												fprintf(stderr, "error: imaginary expression"); /* very, very crude imaginary expression check */
												fflush(stderr);
												exit(1);
											}
											else
											{
												count--;
												fseek(ifp, -1, SEEK_CUR);
											}
										}
										else
										{
											count--;
											fseek(ifp, -1, SEEK_CUR);
										}
									}
									else
									{
										count--;
										fseek(ifp, -1, SEEK_CUR);
									}
								}
								else
								{
									count--;
									fseek(ifp, -1, SEEK_CUR);
								}
							}
							else
							{
								count--;
								fseek(ifp, -1, SEEK_CUR);
								fprintf(stdout, "multiply ");
								fflush(stdout);
							}
						}
						else
						{
							count--;
							fseek(ifp, -1, SEEK_CUR);
						}
					}
					else
					{
						fseek(ifp, -1, SEEK_CUR);
						count--;
					}
					break;

				case ')':																	/* case ')' */
					fprintf(stdout, "rparen ");
					fflush(stdout);
					break;

				case '+':																	/* case '+' */
					fprintf(stdout, "add ");
					fflush(stdout);
					break;

				case '/':																	/* case '/' */
					fprintf(stdout, "divide ");
					fflush(stdout);
					fgetc(ifp);
					count += 2;
					read_buff[count] = fgetc(ifp);
					if(read_buff[count] == '0')
					{
						fprintf(stderr, "error: division by zero\n");
						fflush(stderr);
						exit(1);
					}
					else
					{
						fseek(ifp, -2, SEEK_CUR);
						count -= 2;
					}
					break;

				case '=':																	/* case '=' */
					fprintf(stdout, "assign ");
					fflush(stdout);
					break;

				case ';':																	/* case ';' */
					fprintf(stdout, "semi ");
					fflush(stdout);
					break;


			} /* switch */

			count = 0;
			read_buff[count] = fgetc(ifp);

		}    /* while */

		fclose(ifp);
		fprintf(stdout, "nomore\n");
		fflush(stdout);
}	/* end class tokenizer */
