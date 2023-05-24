#include "onyxshell.h"
/**
 * _getenv - gets the path
 * @path_nm: a pointer to the struct of data
 *
 * Return: A Positive number on SUCCESS
 * In case of FAILURE return a negative number
 */
char *_getenv(char *path_nm)
{
	char **environ_cursor, *env_ptr, *name_ptr;

	environ_cursor = environ;
	while (*environ_cursor)
	{
		env_ptr = *environ_cursor;
		name_ptr = path_nm;
		while (*env_ptr == *name_ptr)
		{
			if (*env_ptr == '=')
				break;
			env_ptr++;
			name_ptr++;
		}
		if ((*env_ptr == '=') && (*name_ptr == '\0'))
			return (env_ptr + 1);
		environ_cursor++;
	}
	return (NULL);
}
/**
 * sig_handler - handle the process interrept signal
 * @sig: the signal identifier
 *
 * Return: VOID
 */
void sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		PRINT("\n");
		PRINT(ONYXPROMPT);
	}
}
/**
 * fill_arr - fill an array with elements
 * @ar: the given array
 * @elm: the given element
 * @leng: the length of the array
 *
 * Return: pointer to filled array
 */
void *fill_arr(void *ar, int elm, unsigned int leng)
{
	char *p = ar;
	unsigned int i = 0;

	while (i < leng)
	{
		*p = elm;
		p++;
		i++;
	}
	return (ar);
}

/**
 * array_revs - reverses the  array
 * @arrs: the given array
 * @leng: the array length
 *
 * Return: void
 */
void array_revs(char *arrs, int leng)
{
	int i;
	char tmp;

	for (i = 0; i < (leng / 2); i++)
	{
		tmp = arrs[i];
		arrs[i] = arrs[(leng - 1) - i];
		arrs[(leng - 1) - i] = tmp;
	}
}
/**
 * index_cmds - The indexed cmds
 * @datas: A Pointer to data struct
 *
 * Return: VOID
 */
void index_cmds(shl_t *datas)
{
	datas->index += 1;
}
