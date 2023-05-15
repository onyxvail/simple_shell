#include "shell.h"

void prompt(void)
{
char *line;
char **args;
int status;
do
{
    printf("Onyxhsell>> ");
    line = malloc((size_t)read_line());
    args = split_line(line);
    status = onyxshell_execute(args);
    free(line);
    free(args);
} while (status);
}
