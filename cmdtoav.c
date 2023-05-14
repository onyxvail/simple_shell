#include "shell.h"

/**
 * main - Entry point for the program
 *
 * @argc: Number of arguments passed to the program
 * @argv: Array of string arguments passed to the program
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
(void)argc;
char **words = split_string(argv[0], " ");
int i;
for (i = 0; words[i] != NULL; i++)
{
printf("%s\n", words[i]);
}
free(words);
return (0);
}
