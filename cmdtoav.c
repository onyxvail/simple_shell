#include "shell.h"

/**
 * main - entry point of the program
 *
 * Return: always 0 (success)
 */
int main(int argc, char **argv)
{
char **words = split_string(argv[0], " ");
int i;
for (i = 0; words[i] != NULL; i++)
{
printf("%s\n", words[i]);
}
free(words);
return (0);
}
