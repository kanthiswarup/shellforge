#include <stdio.h>
#include "token.h"

static const char *token_type_name(TokenType type) {
    switch (type) {
        case TOKEN_WORD:            return "WORD";
        case TOKEN_PIPE:            return "PIPE";
        case TOKEN_REDIRECT_IN:     return "REDIRECT_IN";
        case TOKEN_REDIRECT_OUT:    return "REDIRECT_OUT";
        case TOKEN_REDIRECT_APPEND: return "REDIRECT_APPEND";
        case TOKEN_AND:             return "AND";
        case TOKEN_OR:              return "OR";
        case TOKEN_BACKGROUND:      return "BACKGROUND";
        case TOKEN_END:             return "END";
        default:                    return "UNKNOWN";
    }
}

void token_print(Token tokens[], int token_count) {
    printf("-------------- TOKENS --------------\n");
    for (int i = 0; i < token_count; i++) {
        printf(" %d : %-14s %s\n", i, token_type_name(tokens[i].type), tokens[i].value);
    }
    printf("-------------------------------------\n");
}
