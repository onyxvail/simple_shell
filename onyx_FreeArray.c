#include "onyxshell.h"

/**
 *free_arrays - A Function that frees Arrays
 *@arrs: Array of strings
 *
 *Return: VOID
 */

void free_arrays(char **arrs)
{
	int i = 0;

	if (arrs == NULL)
		return;
	while (arrs[i])
	{
		free(arrs[i]);
		arrs[i] = NULL;
		i++;
	}
	free(arrs);
	arrs = NULL;
}
