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
<<<<<<< HEAD
return 0;
=======
return (onyxshell_process(args));
>>>>>>> 22842b6673bd98efaf39975e257960f0f2fd30fa
}
