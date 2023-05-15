#include "shell.h"

/**
 * onyxshell_builtins - Get the number of built-in commands.
 *
 * Return: The number of built-in commands.
 */



int onyxshell_builtins(void)
{
return sizeof(builtin_str) / sizeof(char *);
}
