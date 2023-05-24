#include "shell.h"

/**
 * av - av
 *
 * Return: Always 0.
 */
int av(int ac, char **av)
{
    int i;

    i = 0;
    while (av[i])
    {
        printf("%s\n", av[i]);
        i++;
    }
    return (0);
}
