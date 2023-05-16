#include "onyxshell.h"

/**
 * copyMemory - Copy a memory area
 * @destination: Destination char array
 * @source: Source char array
 * @n: Number of bytes to copy
 * Return: Pointer to destination
 */
char *copyMemory(char *destination, const char *source, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		destination[i] = source[i];
	}

	return (destination);
}
