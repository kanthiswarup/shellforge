#include <stdio.h>
#include <string.h>

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
    char input[1024];

    Token tokens[MAX_TOKENS];

    int token_count;

    printf("====================================\n");
    printf("          Shellforge\n");
    printf("    A Unix Style Shell written in C\n");
    printf("====================================\n");

    while (1)
    {
        printf("shellforge$ ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            break;
        }

        /* Remove newline */
        input[strcspn(input, "\n")] = '\0';

        /* Exit shell */
        if (strcmp(input, "exit") == 0)
        {
            break;
        }

        /* Ignore empty input */
        if (strlen(input) == 0)
        {
            continue;
        }

        /* Tokenize input */
        lexer_tokenize(input, tokens, &token_count);

        /* Display tokens */
        print_tokens(tokens, token_count);
    }

    return 0;
}
