#include"shell.h"


char **split_line(char *line)
{
int bufsize = TOKEN_BUFSIZE, position = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token, **tokens_backup;
if (!tokens)
{
fprintf(stderr, "Onyxshell: allocation error\n");
exit(EXIT_FAILURE);
}
token = strtok(line, TOKEN_DELIM);
while (token != NULL)
{
tokens[position] = token;
position++;
if (position >= bufsize)
{
bufsize += TOKEN_BUFSIZE;
tokens_backup = tokens;
tokens = realloc(tokens, bufsize * sizeof(char *));
if (!tokens)
{
free(tokens_backup);
fprintf(stderr, "Onyxshell: allocation error\n");
exit(EXIT_FAILURE);
}
}
token = strtok(NULL, TOKEN_DELIM);
}
tokens[position] = NULL;
return (tokens);
}
