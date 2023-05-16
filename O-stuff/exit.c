#include "onyxshell.h"

/**
 * exitshell - Exit from the shell
 * @arguments: Array of arguments
 * @environment: Array of environment variables
 * Return: 1
 */
int exitshell(char **arguments, char **environment)
{
	int status;
	(void)environment;

	status = 0;
	if (arguments[1])
		status = convertStringToInteger(arguments[1]);
	freeResources(arguments);
	exit(status);
}
