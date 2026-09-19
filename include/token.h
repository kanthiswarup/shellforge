#ifndef TOKEN_H
#define TOKEN_H

#define MAX_TOKEN_LENGTH 256

typedef enum
{
    TOKEN_WORD,
    TOKEN_PIPE,
    TOKEN_REDIRECT_IN,
    TOKEN_REDIRECT_OUT,
    TOKEN_REDIRECT_APPEND,
    TOKEN_AND,
    TOKEN_OR,
    TOKEN_BACKGROUND,
    TOKEN_END
} TokenType;

typedef struct
{
    TokenType type;
    char value[MAX_TOKEN_LENGTH];
} Token;

void token_print(Token tokens[], int token_count);

#endif
