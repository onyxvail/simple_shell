#include <stdio.h>
#include "shell.h"
/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
    unsigned int i = 0;

    (void)ac;
    (void)av;

    while (env[i] != NULL)
    {
        printf("%s\n", env[i]);
        i++;
    }

    return (0);
}
