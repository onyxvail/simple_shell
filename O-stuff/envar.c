#include "onyxshell.h"

/**
 * printenvar - Print environment variables
 * @arguments: Array of arguments
 * @environment: Array of environment variables
 * Return: 1
 */
int printenvar(char **arguments, char **environment)
{
	int i, length;

	i = 0;
	while (environment[i] != NULL)
	{
		length = stringLength(environment[i]);
		write(STDOUT_FILENO, environment[i], length);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	freeResources(arguments);
	return (1);
}
