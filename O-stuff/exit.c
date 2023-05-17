#include "onyxshell.h"

/**
 * exitshell - Exit from the shell
 * @arguments: Array of arguments
 * @environment: Array of environment variables
 * Return: 1
 */
int exitshell(char **arguments)
{
	int status;
	

	status = 0;
	if (arguments[1])
		status = convertStringToInteger(arguments[1]);
	free_resources(NULL);
	exit(status);
}
