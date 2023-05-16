#include "onyxshell.h"

/**
 * builtInCheck - Checks for built-in commands and executes them
 * @arguments: Array of arguments
 * @environment: Array of environment variables
 * Return: 1 if successful, 0 otherwise
 */
int builtInCheck(char **arguments, char **environment)
{
	BuiltInCommand builtInCommands[] = {
		{"env", printenvar},
		{"exit", exitshell},
		{NULL, NULL}
	};
	int i;

	if (arguments[0] == NULL)
		return (0);

	for (i = 0; builtInCommands[i].command != NULL; i++)
	{
		if (_strcmp(arguments[0], builtInCommands[i].command) == 0)
			return (builtInCommands[i].function(arguments, environment));
	}

	return (0);
}
