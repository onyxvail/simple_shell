#include <stdio.h>

#define MAX_LENGTH 100

/**
 * read_line - Read line
 *
 * Return: Always 0.
 */
int read_line(void)
{
    char line[MAX_LENGTH];

    while (1)
    {
        printf("$ ");
        if (fgets(line, MAX_LENGTH, stdin) == NULL)
        {
            printf("\n");
            break;
        }
        printf("%s", line);
    }
    return (0);
}
