#include "shell.h"

/**
 * onyxshell_builtins - Get the number of built-in commands.
 *
 * Return: The number of built-in commands.
 */

char *builtin_str[] = {"cd", "exit"};
int (*builtin_function[]) (char **) = {&onyxshell_cd, &onyxshell_exit};

int onyxshell_builtins(void)
{
return sizeof(builtin_str) / sizeof(char *);
}
