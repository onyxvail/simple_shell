#include "onyxshell.h"

struct BuiltInCommand builtInCommands[] = {
		{"env", printenvar},
		{"exit", exitshell},
		{NULL, NULL}
	};
	
/**
 * builtInCheck - Checks for built-in commands and executes them
 * @arguments: Array of arguments
 * @environment: Array of environment variables
 * Return: 1 if successful, 0 otherwise
 */
int builtInCheck(char **arguments, char **environment)
{
	
	
	
	
	int i;

	if (arguments[0] == NULL)
		return (0);

	for (i = 0; builtInCommands[i].command != NULL; i++)
	{
		if (strcmp(arguments[0], builtInCommands[i].command) == 0)
			return (builtInCommands[i].function(arguments, environment));
	}

	return (0);
}
