#include "shell.h"

/**
 * tokenize_command - Tokenize the command string
 * @command: Command string to tokenize
 * @args: Array to store the arguments
 *
 * This function tokenizes the command string into individual arguments.
 * It splits the command string based on space and newline characters,
 * and stores the resulting tokens in the args array.
 *
 * Return: The number of arguments tokenized.
 */
int tokenize_command(char *command, char *args[])
{
char *token;
int num_args = 0;

token = strtok(command, " \n");
while (token != NULL && num_args < MAX_ARGS - 1)
{
/* limit lenght of each token to MAX_LENGHT - 1*/
if (strlen(token) > MAX_LENGTH - 1)
token[MAX_LENGTH - 1] = '\0';

args[num_args++] = strdup(token);
token = strtok(NULL, " \n");
}
args[num_args] = NULL;

return (num_args);
}
