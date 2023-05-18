#include "onyxshell.h"

/**
 * get_input - Reads a line of input from the user
 * @input: Pointer to store the input string
 *
 * Return: 0 on success, -1 on failure or end of input
 */
int get_input(char **input)
{
    ssize_t bytes_read;
    size_t bufsize = 0;

    if (input == NULL)
        return -1;

    bytes_read = getline(input, &bufsize, stdin);
    if (bytes_read == -1)
    {
        if (feof(stdin))
            return -1;
        else
        {
            perror("getline");
            return -1;
        }
    }

    if ((*input)[bytes_read - 1] == '\n')
        (*input)[bytes_read - 1] = '\0';

    return (0);
}
