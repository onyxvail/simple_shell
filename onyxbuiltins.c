#include "onyxshell.h"

#define SETOWD(V) (V = _strdupl(_getenv("OLDPWD")))
/**
 * changing_dir - it changes the directory
 * @datas: a pointer to the data structure
 *
 * Return: A Positive number on SUCCESS
 * In case of FAILURE return a negative number
 */
int changing_dir(shl_t *datas)
{
	char *home;

	home = _getenv("HOME");
	if (datas->args[1] == NULL)
	{
		SETOWD(datas->oldpwd);
		if (chdir(home) < 0)
			return (FAILURE);
		return (SUCCESS);
	}
	if (_strcmp(datas->args[1], "-") == 0)
	{
		if (datas->oldpwd == 0)
		{
			SETOWD(datas->oldpwd);
			if (chdir(home) < 0)
				return (FAILURE);
		}
		else
		{
			SETOWD(datas->oldpwd);
			if (chdir(datas->oldpwd) < 0)
				return (FAILURE);
		}
	}
	else
	{
		SETOWD(datas->oldpwd);
		if (chdir(datas->args[1]) < 0)
			return (FAILURE);
	}
	return (SUCCESS);
}
#undef GETCWD
/**
 * aborting_prgm - exiting the prg
 * @datas: a pointer to the data structure
 *
 * Return: A Positive number on SUCCESS
 * In case of FAILURE return a negative number
 */
int aborting_prgm(shl_t *datas __attribute__((unused)))
{
	int code, i = 0;

	if (datas->args[1] == NULL)
	{
		free_datas(datas);
		exit(errno);
	}
	while (datas->args[1][i])
	{
		if (_isitalpha(datas->args[1][i++]) < 0)
		{
			datas->error_msg = _strdupl("Illegal number\n");
			return (FAILURE);
		}
	}
	code = _atoi(datas->args[1]);
	free_datas(datas);
	exit(code);
}
/**
 * displaying_help - display the help menu
 * @datas: a pointer to the data structure
 *
 * Return: A Positive number on SUCCESS
 * In case of FAILURE return a negative number
 */
int displaying_help(shl_t *datas)
{
	int fd, fw, rd = 1;
	char c;

	fd = open(datas->args[1], O_RDONLY);
	if (fd < 0)
	{
		datas->error_msg = _strdupl("no help topics match\n");
		return (FAILURE);
	}
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		fw = write(STDOUT_FILENO, &c, rd);
		if (fw < 0)
		{
			datas->error_msg = _strdupl("cannot write: permission denied\n");
			return (FAILURE);
		}
	}
	PRINT("\n");
	return (SUCCESS);
}
/**
 * handling_builtins - handle and manage the builtins cmd
 * @datas: a pointer to the data structure
 *
 * Return: A Positive number on SUCCESS
 * In case of FAILURE return a negative number
 */
int handling_builtins(shl_t *datas)
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
		if (_strcmp(datas->args[0], (blt + i)->cmd) == 0)
			return ((blt + i)->f(datas));
		i++;
	}
	return (FAILURE);
}
