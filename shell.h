#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>


#define INITIAL_BUFFER_SIZE 64
#define BUFFER_GROWING_FACTOR 2
#define MAX_COMMAND_LENGHT 100

void executeCommand(char *command);

#endif
