#include "onyxshell.h"

/**
 * freeArray - Free an array of strings
 * @array: Pointer to the array
 * Return: None
 */
void freeArray(char **array)
{
	int i = 0;

	if (!array)
		exit(0);

	while (array[i])
	{
		free(array[i]);
		i++;
	}

	free(array);
}
