#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - Entry point for the shell program
 *
 * This function reads user commands, tokenizes them,
 * and executes the commands.
 * It continues to do so until the user enters the "exit" command.
 *
 * Return: Always 0.
 */
int main(void)
{
char command[MAX_LENGTH];
char *args[MAX_ARGS];
int num_args;
int is_eof = 0;
int i;

while (!is_eof)
{
is_eof = read_command(command);
num_args = tokenize_command(command, args);

if (num_args > 0)
{
if (strcmp(args[0], "exit") == 0)
break;
else
execute_command(args, num_args);
}

/* Free memory for arguments */
for (i = 0; i < num_args; i++)
free(args[i]);
}

return (0);
}
