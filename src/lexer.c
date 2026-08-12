#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "lexer.h"

void lexer_tokenize(const char *input, Token tokens[], int *token_count)
{
    int count = 0;
    int i = 0;

    while (input[i] != '\0')
    {
        /* Skip spaces and tabs */
        while (input[i] == ' ' || input[i] == '\t')
        {
            i++;
        }

        /* End of input */
        if (input[i] == '\0' || input[i] == '\n')
        {
            break;
        }

        /* Create WORD token */
        tokens[count].type = TOKEN_WORD;

        int j = 0;

        while (input[i] != '\0' &&
               input[i] != '\n' &&
               input[i] != ' ' &&
               input[i] != '\t')
        {
            if (j < MAX_TOKEN_LENGTH - 1)
            {
                tokens[count].value[j++] = input[i];
            }

            i++;
        }

        tokens[count].value[j] = '\0';

        count++;

        if (count >= MAX_TOKENS - 1)
        {
            break;
        }
    }

    /* Add END token */
    tokens[count].type = TOKEN_END;
    strcpy(tokens[count].value, "END");

    count++;

    *token_count = count;
}
