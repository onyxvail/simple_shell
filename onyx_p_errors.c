#include "onyxshell.h"

/**
 *onyx_p_error - A Function that prints Error
 *@indexe: the number of the command line
 *@argss: Arguments
 *
 *Return: Always 0 on (SUCCESS)
 */

int onyx_p_error(int indexe, char **argss)
{
	char *index_str = itoa(indexe);
	char *ar = argss[0];

	write(STDERR_FILENO, "./hsh: ", 7);
	write(STDERR_FILENO, index_str, _strlen(index_str));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, ar, _strlen(ar));
	write(STDERR_FILENO, ": not found\n", 13);
	free(index_str);
	return (0);
}
