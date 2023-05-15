#include "shell.h"
char read_line(void)
{
char *line = NULL;
ssize_t bufsize = 0;
if (getline(&line, &bufsize, stdin) == -1)
{
if (feof(stdin))
{
exit(EXIT_SUCCESS);
}
else
{
perror("Onyxshell: getline\n");
exit(EXIT_FAILURE);
}
}
return (*line);
}

int bufsize = Onyxshell_BUFSIZE;
int position = 0;
char *buffer = malloc(sizeof(char) * bufsize);
int c;

if (!buffer)
{
fprintf(stderr, "Onyxshell: allocation error\n");
exit(EXIT_FAILURE);
}
while (1)
{
c = getchar();
if (c = EOF)
{
exit(EXIT_SUCCESS);
}
else if (c == '\n')
{
buffer[position] = '\0' ;
return (buffer);
}
else
{
buffer[position] = c;
}
position++;
if (position >= bufsize)
{
bufsize += Onyxshell_BUFSIZE;
buffer = realloc(buffer, bufsize);
if (!buffer)
{
fprintf(stderr, "Onyxshell: aloocation error\n");
exit(EXIT_FAILURE);
}
}
}