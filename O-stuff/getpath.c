#include "onyxshell.h"

/**
 * checkpath - Check if the command is in the PATH
 * @command: Array of strings representing the command
 * @environment: Array of strings representing the environment variables
 * Return: None
 **/
void checkpath(char **command, char **environment)
{
	char *command_with_slash, *path;
	int i, start, last;

	command_with_slash = concatenateStrings("/", command[0]);
	path = getEnvironmentVariable("PATH", environment);
	if (path == NULL)
	{
		free(command_with_slash);
		exit(0);
	}
	start = i = last = 0;
	while (path[i])
	{
		if (path[i] == ':' || path[i + 1] == '\0')
		{
			if (path[i + 1] == '\0')
			{
				i += 1;
				last = 1;
			}
			else
				path[i] = '\0';
			char *command_with_path = concatenateStrings(path + start, command_with_slash);
			if (access(command_with_path, F_OK) == 0)
			{
				free(command[0]);
				command[0] = command_with_path;
				free(command_with_slash);
				return;
			}
			free(command_with_path);
			if (last)
				break;
			path[i] = ':';
			start = i + 1;
		}
		i += 1;
	}
	free(command_with_slash);
}
