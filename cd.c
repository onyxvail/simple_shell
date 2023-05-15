#include "shell.h"

int onyxshell_cd(char **args)
{
if (args[1] == NULL)
{
fprintf(stderr, "Onyxshell: expected argument to cd\n");
}
else
{
if (chdir(args[1]) != 0)
{
perror("Onyxhsell");
}
}
return (1);
}
