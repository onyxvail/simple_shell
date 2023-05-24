#include "onyxshell.h"

/**
 * main - the main function
 *
 * Return: 0 always (SUCCESS)
 *
 */
int main(void)
{
	shl_t datas;
	int pll;

	_memsett((void *)&datas, 0, sizeof(datas));
	signal(SIGINT, sig_handler);
	while (1)
	{
		index_cmds(&datas);
		if (reading_line(&datas) < 0)
		{
			if (isatty(STDIN_FILENO))
				PRINT("\n");
			break;
		}
		if (spliting_line(&datas) < 0)
		{
			free_datas(&datas);
			continue;
		}
		pll = parsing_line(&datas);
		if (pll == 0)
		{
			free_datas(&datas);
			continue;
		}
		if (pll < 0)
		{
			printing_error(&datas);
			continue;
		}
		if (processing_cmd(&datas) < 0)
		{
			printing_error(&datas);
			break;
		}
		free_datas(&datas);
	}
	free_datas(&datas);
	exit(EXIT_SUCCESS);
}

/**
 * reading_line - read a line from the standard input
 * @datas: A pointer to the data struct
 *
 * Return: A Positive number on SUCCESS
 * In case of FAILURE return a negative number
 */
int reading_line(shl_t *datas)
{
	char *csr_ptr, *end_ptr, c;
	size_t size = BUFSIZE, read_st, length, n_size;

	datas->line = malloc(size * sizeof(char));
	if (datas->line == NULL)
		return (FAILURE);
	if (isatty(STDIN_FILENO))
		PRINT(ONYXPROMPT);
	for (csr_ptr = datas->line, end_ptr = datas->line + size;;)
	{
		read_st = read(STDIN_FILENO, &c, 1);
		if (read_st == 0)
			return (FAILURE);
		*csr_ptr++ = c;
		if (c == '\n')
		{
			*csr_ptr = '\0';
			return (SUCCESS);
		}
		if (csr_ptr + 2 >= end_ptr)
		{
			n_size = size * 2;
			length = csr_ptr - datas->line;
			datas->line = _reallocate(datas->line, size * sizeof(char),
						n_size * sizeof(char));
			if (datas->line == NULL)
				return (FAILURE);
			size = n_size;
			end_ptr = datas->line + size;
			csr_ptr = datas->line + length;
		}
	}
}
#define DELIMITER " \n\t\r\a\v"
/**
 * spliting_line - splits the line into tokens
 * @datas: A pointer to the data struct
 *
* Return: A Positive number on SUCCESS
 * In case of FAILURE return a negative number
 */
int spliting_line(shl_t *datas)
{
	char *token;
	size_t size = TOKENSIZE, n_size, i = 0;

	if (_strcmp(datas->line, "\n") == 0)
		return (FAILURE);
	datas->args = malloc(size * sizeof(char *));
	if (datas->args == NULL)
		return (FAILURE);
	token = strtok(datas->line, DELIMITER);
	if (token == NULL)
		return (FAILURE);
	while (token)
	{
		datas->args[i++] =  token;
		if (i + 2 >= size)
		{
			n_size = size * 2;
			datas->args = _reallocate(datas->args, size * sizeof(char *),
					n_size * sizeof(char *));
			if (datas->args == NULL)
				return (FAILURE);
			size = n_size;
		}
		token = strtok(NULL, DELIMITER);
	}
	datas->args[i] = NULL;
	return (0);
}
#undef DELIMITER
#define DELIMITER ":"
/**
 * parsing_line - Parsethe args to a VALID CMD
 * @datas: A Pointer of a data struct
 *
 * Return: A Positive number on SUCCESS
 * In case of FAILURE return a negative number
 */
int parsing_line(shl_t *datas)
{
	if (ispath_form(datas) > 0)
		return (SUCCESS);
	if (is_builtin(datas) > 0)
	{
		if (handling_builtins(datas) < 0)
			return (FAILURE);
		return (NEUTRAL);
	}
	isshort_form(datas);
	return (SUCCESS);
}
#undef DELIMITER
/**
 * processing_cmd - processing cmds and executing the process
 * @datas: A Pointer of the data struct
 *
 * Return: A Positive number on SUCCESS
 * In case of FAILURE return a negative number
 */
int processing_cmd(shl_t *datas)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		if (execve(datas->cmd, datas->args, environ) < 0)
		datas->error_msg = _strdupl("not found\n");
			return (FAILURE);
	}
	else
	{
		waitpid(pid, &status, WUNTRACED);
	}
	return (0);
}
