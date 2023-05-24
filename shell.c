#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - Entry point for the shell program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * This function reads user commands, tokenizes them,
 * and executes the commands.
 * It continues to do so until the user enters the "exit" command.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{

char command[MAX_LENGTH];
char *args[MAX_ARGS];
int num_args;
int is_eof = 0;
int i;

(void)argc;

while (!is_eof)
{


is_eof = read_command(command);
num_args = tokenize_command(command, args);

if (num_args > 0)
{
if (strcmp(args[0], "exit") == 0)
break;
else
execute_command(args, num_args, argv[0]);
}

/* Free memory for arguments */
for (i = 0; i < num_args; i++)
free(args[i]);
}

/* check if in interractive mode before printing prompt */
if (isatty(STDIN_FILENO))
printf("\n");
return (0);
}
