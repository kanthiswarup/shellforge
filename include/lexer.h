#ifndef LEXER_H
#define LEXER_H

#include "token.h"

#define MAX_TOKENS 100

void lexer_tokenize(const char *input, Token tokens[], int *token_count);

#endif

