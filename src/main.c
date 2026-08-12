#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <readline/readline.h>
#include <readline/history.h>

#include "lexer.h"
#include "token.h"

void print_tokens(Token tokens[], int token_count)
{
    printf("\n------------- TOKENS -------------\n");

    for (int i = 0; i < token_count; i++)
    {
        if (tokens[i].type == TOKEN_WORD)
        {
            printf("%d : WORD    %s\n",
                   i,
                   tokens[i].value);
        }
        else if (tokens[i].type == TOKEN_PIPE)
        {
            printf("%d : PIPE    %s\n",
                   i,
                   tokens[i].value);
        }
        else if (tokens[i].type == TOKEN_REDIRECT_IN)
        {
            printf("%d : REDIR_IN %s\n",
                   i,
                   tokens[i].value);
        }
        else if (tokens[i].type == TOKEN_REDIRECT_OUT)
        {
            printf("%d : REDIR_OUT %s\n",
                   i,
                   tokens[i].value);
        }
        else if (tokens[i].type == TOKEN_REDIRECT_APPEND)
        {
            printf("%d : REDIR_APPEND %s\n",
                   i,
                   tokens[i].value);
        }
        else if (tokens[i].type == TOKEN_AND)
        {
            printf("%d : AND     %s\n",
                   i,
                   tokens[i].value);
        }
        else if (tokens[i].type == TOKEN_OR)
        {
            printf("%d : OR      %s\n",
                   i,
                   tokens[i].value);
        }
        else if (tokens[i].type == TOKEN_END)
        {
            printf("%d : END     END\n",
                   i);
        }
    }

    printf("----------------------------------\n");
}

int main()
{
    Token tokens[MAX_TOKENS];
    int token_count;

    printf("====================================\n");
    printf("          Shellforge\n");
    printf("    A Unix Style Shell written in C\n");
    printf("====================================\n");

    while (1)
    {
        char *input = readline("shellforge$ ");

        /* Ctrl+D */
        if (input == NULL)
        {
            printf("\n");
            break;
        }

        /* Ignore empty commands */
        if (strlen(input) == 0)
        {
            free(input);
            continue;
        }

        /* Exit shell */
        if (strcmp(input, "exit") == 0)
        {
            free(input);
            break;
        }

        /* Save command in history */
        add_history(input);

        /* Tokenize input */
        lexer_tokenize(input, tokens, &token_count);

        /* Display tokens */
        print_tokens(tokens, token_count);

        free(input);
    }

    return 0;
}
