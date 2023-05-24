#include "onyxshell.h"
/**
 * ispath_form - check if the given file
 * name is a path
 * @data: the data strucct pointer
 *
 * Return: SUCCESS
 * otherwise FAILURE
 */
int ispath_form(shl_t *data)
{
	if (_strchr(data->args[0], '/') != 0)
	{
		data->cmd = _strdupl(data->args[0]);
		return (SUCCESS);
	}
	return (FAILURE);
}
#define DELIMITER ":"
/**
 * isshort_form - check if the given file name
 * is short form
 * @data: pointer of the data struct
 *
 * Return: SUCCESS
 * otherwise FAILURE
 */
void isshort_form(shl_t *data)
{
	char *path, *token, *_path;
	struct stat st;
	int exist_flag = 0;

	path = _getenv("PATH");
	_path = _strdupl(path);
	token = strtok(_path, DELIMITER);
	while (token)
	{
		data->cmd = _strcatt(token, data->args[0]);
		if (stat(data->cmd, &st) == 0)
		{
			exist_flag += 1;
			break;
		}
		free(data->cmd);
		token = strtok(NULL, DELIMITER);
	}
	if (exist_flag == 0)
	{
		data->cmd = _strdupl(data->args[0]);
	}
	free(_path);
}
#undef DELIMITER
/**
 * is_builtin - checks if the command is builtin
 * @data:  the data structure's pointer
 *
 * Return: A Positive number on SUCCESS
 * In case of FAILURE return a negative number
 */
int is_builtin(shl_t *data)
{
	blt_t blt[] = {
		{"exit", aborting_prgm},
		{"cd", changing_dir},
		{"help", displaying_help},
		{NULL, NULL}
	};
	int i = 0;

	while ((blt + i)->cmd)
	{
		if (_strcmp(data->args[0], (blt + i)->cmd) == 0)
			return (SUCCESS);
		i++;
	}
	return (NEUTRAL);
}
