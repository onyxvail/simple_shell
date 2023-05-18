#include "onyxshell.h"

#define MAX_ARGS 100

/**
 * split_input - Splits an input string into an array of arguments
 * @input: Input string to split
 *
 * Return: Array of arguments
 */
char **split_input(char *input)
{
    char **arguments = NULL;
    char *token;
    int i = 0;
    const char *delimiters = " \t\n";
    
    if (input == NULL)
        return NULL;

    arguments = malloc(sizeof(char *) * (MAX_ARGS + 1));
    if (arguments == NULL)
    {
        perror("malloc");
        return NULL;
    }

    token = strtok(input, delimiters);
    while (token != NULL)
    {
        arguments[i] = strdup(token);
        if (arguments[i] == NULL)
        {
            perror("strdup");
            free_resources(arguments);
            return NULL;
        }
        i++;

        token = strtok(NULL, delimiters);
    }

    arguments[i] = NULL;
    return arguments;
}
