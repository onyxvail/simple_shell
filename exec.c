#include "shell.h"

int onyxshell_execute(char **args)
{
int i;
if (args[0] == NULL)
{
return (1);
}
for (i = 0; i < onyxshell_builtins(); i++)
{
if (strcmp(args[0], builtin_str[i]) == 0)
{
return ((*builtin_function[i])(args));
}
}
return (onyxshell_process(args));
}
