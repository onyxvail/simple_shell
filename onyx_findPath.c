#include "onyxshell.h"

/**
 *findthepath - A Function that locates the file of env
 *@thefilename:  enviornment variable "PATH" 's name
 *
 *Return: FULLPATH
 */

char *findthepath(char *thefilename)
{
	int i = 0, flag = 0;
	char *_path, *pathdup;
	char **tokens;
	char *conc;
	struct stat st;

	if (_strchrs(thefilename, '/') != 0)
		return (thefilename);
	pathdup = onyx_env("PATH");
	if (pathdup == NULL)
		return (thefilename);
	_path = _strdupt(pathdup);
	tokens = onyx_token(_path);
	if (tokens == NULL)
		return (thefilename);
	while (tokens[i])
	{
		conc = _strcate(tokens[i], thefilename);
		if (stat(conc, &st) == 0)
		{
			flag += 1;
			break;
		}
		i++;
		free(conc);
	}
	free(tokens);
	tokens = NULL;
	free(_path);
	_path = NULL;
	pathdup = NULL;
	if (flag > 0)
		return (conc);
	else
		return (thefilename);
}
