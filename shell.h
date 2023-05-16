#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int getpid();
int getppid();
void _prompt();
void execmd(char *av);

#define INITIAL_BUFFER_SIZE 64
#define BUFFER_GROWING_FACTOR 2
#define MAX_COMMAND_LENGHT 100


#endif