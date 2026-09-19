#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expand.h"

static char *copy_word(const char *word) {
    size_t length = strlen(word) + 1;
    char *copy = malloc(length);

    if (copy != NULL)
        memcpy(copy, word, length);
    return copy;
}

static char *expand_token(const char *word) {
    if (word[0] != '$' || word[1] == '\0')
        return copy_word(word);

    const char *val = getenv(word + 1);
    return copy_word(val ? val : "");
}

void expand_variables(pipeline_t *pipeline) {
    for (int c = 0; c < pipeline->command_count; c++) {
        command_t *cmd = &pipeline->commands[c];
        for (int j = 0; j < cmd->argc; j++) {
            char *expanded = expand_token(cmd->argv[j]);
            if (expanded != NULL)
                cmd->argv[j] = expanded;
        }
    }
}
