#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <errno.h>
#include <stdbool.h>

#define MAX_LENGTH 1024
#define MAX_ARGS 64

int read_command(char *command);
int tokenize_command(char *command, char *args[]);
void execute_command(char *args[], int num_args, char *program_name);

#endif
