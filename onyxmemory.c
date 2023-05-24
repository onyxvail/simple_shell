#include "onyxshell.h"

/**
 * _reallocate - reallocates the memory blocks
 * @ptrs: pointer of previous memo
 * @o_size: the old size
 * @n_size: the new size
 *
 * Return: A Pointer of the newly allocated memo
 */
void *_reallocate(void *ptrs, unsigned int o_size, unsigned int n_size)
{
	void *result;

	if (n_size == o_size)
		return (ptrs);
	if (n_size == 0 && ptrs)
	{
		free(ptrs);
		return (NULL);
	}
	result = malloc(n_size);
	if (result == NULL)
		return (NULL);
	if (ptrs == NULL)
	{
		fill_arr(result, '\0', n_size);
		free(ptrs);
	}
	else
	{
		_memcpyy(result, ptrs, o_size);
		free(ptrs);
	}
	return (result);
}
/**
 * _memsett - Filling the memo with constant bytes
 * @s: pointer of the memory area
 * @n: the first n bytes
 * @byt: the constant byte
 *
 * Return: A pointer to a character
 */
char *_memsett(char *s, char byt, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = byt;
	}
	return (s);
}
/**
 * free_datas - frees data
 * @data: the data structure
 *
 * Return: A Positive number on SUCCESS
 * In case of FAILURE return a negative number
 */
int free_datas(shl_t *data)
{
	free(data->line);
	data->line = NULL;
	free(data->args);
	data->args = NULL;
	free(data->cmd);
	data->cmd = NULL;
	free(data->error_msg);
	data->error_msg = NULL;
	return (0);
}
/**
 * _memcpyy - copies thememory area
 * @destn: Destination of the memory area
 * @srcs: Source OF THE memory area
 * @nb: Amount OF THE memory byte
 *
 * Return: A pointer to destination
 */
char *_memcpyy(char *destn, char *srcs, unsigned int nb)
{
	unsigned int i;

	for (i = 0; i < nb; i++)
	{
		destn[i] = srcs[i];
	}
	return (destn);
}
