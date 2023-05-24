#include "onyxshell.h"

/**
 *onyx_token - A Function that tokenizes strings
 *@strg: a string to tokenize
 *
 *Return: the array of tokens
 */

char **onyx_token(char *strg)
{

int i = 0;
char *token;
char  **tokens;
char *delm = " \t\r\n\a\v:";

tokens = malloc(sizeof(char *) * 64);
if (tokens == NULL)
return (NULL);
*tokens = NULL;
token = strtok(strg, delm);
while (token != NULL)
{
tokens[i] = token;
i++;
token = strtok(NULL, delm);
}
if (token == NULL && *tokens == NULL)
{
free(tokens);
free(token);
return (NULL);
}
tokens[i] = NULL;
return (tokens);
}
