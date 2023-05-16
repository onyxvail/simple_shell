#include "onyxshell.h"

/**
 * freeStrings - Free a variable number of strings
 * @status: Status
 * @count: Number of strings to free
 * @...: Variable number of string arguments
 * Return: Nothing
 */
void freeStrings(int status, const unsigned int count, ...)
{
	unsigned int i;
	char *str;
	va_list args;

	va_start(args, count);
	for (i = 0; i < count; i += 1)
	{
		str = va_arg(args, char *);
		free(str);
	}
	va_end(args);

	if (status == 99)
		return;

	exit(0);
}
