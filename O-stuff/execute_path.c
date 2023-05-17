#include "onyxshell.h"

/**
 * execute_path - Executes a command using the PATH environment variable
 * @arguments: Array of command arguments
 * @envp: Array of environment variables
 *
 * Return: None
 */
void execute_path(char **arguments, char **envp)
{
	char *path = getenv("PATH");
	char *token, *command;
	char *path_copy = strdup(path);
	int executed = 0;

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		command = malloc(strlen(token) + strlen(arguments[0]) + 2);
		sprintf(command, "%s/%s", token, arguments[0]);

		if (access(command, X_OK) == 0)
		{

			execve(command, arguments, envp);
			perror("execve");
			free(command);
			executed = 1;
			break;
		}

		free(command);
		token = strtok(NULL, ":");
	}

	free(path_copy);

	if (!executed)
		printf("%s: command not found\n", arguments[0]);
}
