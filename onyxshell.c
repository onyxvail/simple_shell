#include "onyxshell.h"

/**
 *main - Entry point
 *
 *Return: Always 0 on SUCCESS
 *And Error on FAILURE
 */

int main(void)
{
	char *cmd, *line = NULL, **args = NULL;
	size_t size = 0;
	int in_line = 0;
	unsigned int index = 0;

	signal(SIGINT, sig_hand);
	while (1)
	{
		free(args);
		args = NULL;
		index++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		in_line = getline(&line, &size, stdin);
		if (in_line < 0)
		{
			free(line);
			line = NULL;
			write(STDIN_FILENO, "\n", 1);
			break;
		}
		args = onyx_token(line);
		if (args == NULL || *args == NULL)
			continue;
		if (onyx_builtins(args, line))
			continue;
		cmd = findthepath(args[0]);
		if (onyx_exec(cmd, args) < 0)
		{
			onyx_p_error(index, args);
			free(*args);
			free(args);
			exit(EXIT_FAILURE);
		}
		if (cmd != args[0])
			free(cmd);
	}
	return (0);
}
