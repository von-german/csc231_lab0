/* vonbwd14, Will von Behren
   error_handling.h */

#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

#include "token_production.h"

void arg_incorrect();
void file_nonexist();
void buffer_overflow();
void unrecognized_token();
void multiple_decimals();
void match_error(token cur_tok, token exp_tok);
void grammar_error(int line_num, token cur_tok);


#endif
