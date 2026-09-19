#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "token.h"
#include "lexer.h"
#include "parser.h"
#include "expand.h"

int main(void) {
    printf("===================================\n");
    printf("      Shellforge\n");
    printf(" A Unix Style Shell written in C\n");
    printf("===================================\n");

    Token tokens[MAX_TOKENS];
    int token_count;
    pipeline_t pipeline;
    char *line;

    while (1) {
        line = readline("shellforge$ ");

        if (line == NULL) {
            printf("\nGoodbye!\n");
            break;
        }
        if (strlen(line) == 0) {
            free(line);
            continue;
        }

        add_history(line);
        lexer_tokenize(line, tokens, &token_count);
        token_print(tokens, token_count);

        if (parse(tokens, token_count, &pipeline)) {
            expand_variables(&pipeline);
            pipeline_print(&pipeline);
        }

        if (strcmp(line, "exit") == 0) {
            free(line);
            printf("Exiting...\n");
            break;
        }
        free(line);
    }
    return 0;
}
