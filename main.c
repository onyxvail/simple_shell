#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
/**
 * prompt - Entry point for the program.
 *
 * This function prints "$"
 *  waits for the user to enter a command,
 * and then prints it on the next line.
 *
 * Return: Always 0 (success).
 */

int main(void)
{
char *line = NULL;
size_t len = 0;
ssize_t read;

printf("$ ");

while ((read = getline(&line, &len, stdin)) != -1)
{
printf("%s$ ", line);
free(line);
line = NULL;
len = 0;
}

return (0);
}
