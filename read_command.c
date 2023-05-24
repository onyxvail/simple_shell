#include "shell.h"

/**
 * read_command - Read a command from the user
 * @command: Buffer to store the command
 *
 * This function prompts the user for a command and reads it from
 * the standard input.
 * The command is stored in the provided command buffer.
 *
 * Return: 1 if end-of-file (EOF) is reached, 0 otherwise.
 */
int read_command(char *command)
{
if (isatty(STDIN_FILENO)) /* Check if input is from a terminal */
printf("Onyxshell$ ");

if (fgets(command, MAX_LENGTH, stdin) == NULL)
return (1); /* EOF */

/* remove trailing new line character */
command[strcspn(command, "\n")] = '\0';

if (strlen(command) == 0)
return (0); /* empty input */

return (0);
}
