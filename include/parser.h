#ifndef PARSER_H
#define PARSER_H

#include "token.h"

#define MAX_ARGS     64
#define MAX_COMMANDS 16
#define MAX_PATH     1024

typedef struct {
    int  argc;
    char *argv[MAX_ARGS];
    char input[MAX_PATH];
    char output[MAX_PATH];
    int  append;
    int  background;
} command_t;

typedef struct {
    command_t commands[MAX_COMMANDS];
    int command_count;
} pipeline_t;

void command_init(command_t *cmd);
int  parse(Token tokens[], int token_count, pipeline_t *pipeline);
void pipeline_print(const pipeline_t *pipeline);

#endif
