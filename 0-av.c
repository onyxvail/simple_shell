#include <stdio.h>

/**
 * av - Entry point for the program.
 * @argc: The number of command line arguments.
 * @argv: A null-terminated array of strings
 * containing the command line arguments.
 *
 * Return: Always 0 (success).
 */

int av(int argc, char **argv)
{
int i = 1;
while (i < argc)
{
printf("%s ", argv[i]);
i++;
}
printf("\n");

return (0);
}
