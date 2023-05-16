#include "onyxshell.h"

/**
 * getenv - Get the value of an environment variable
 * @name: Name of the requested variable
 * @env_list: Environment variable list
 * Return: Pointer to the environment variable value
 **/
char *getenv(char *name, char **env_list)
{
	int i = 0, j = 0;
	int result, length;

	while (env_list[i] != NULL)
	{
		result = compareStrings(name, env_list[i]);
		if (result == 1)
		{
			length = stringLength(env_list[i]);
			while (env_list[i][j] != '=')
				j++;
			length -= j;
			return (env_list[i] + j + 1);
		}
		i++;
	}
	return (NULL);
}
