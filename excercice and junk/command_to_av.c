#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS 10
#define MAX_LENGTH 100

/**
 * CmdToAv - Command line to av
 *
 * Return: Always 0.
 */
int CmdToAv(void)
{
    char command[MAX_LENGTH];
    char *args[MAX_ARGS];
    char *token;
    int num_args = 0;

    printf("Enter a command: ");
    fgets(command, MAX_LENGTH, stdin);

    // Tokenize the command string
    token = strtok(command, " \n");
    while (token != NULL && num_args < MAX_ARGS)
    {
        args[num_args++] = strdup(token);
        token = strtok(NULL, " \n");
    }

    // Print the arguments
    for (int i = 0; i < num_args; i++)
    {
        printf("arg[%d]: %s\n", i, args[i]);
        free(args[i]);
    }

    return 0;
}
