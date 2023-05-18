#include "onyxshell.h"

/**
 * str_length - returns the length of a string
 * @str: string
 * Return: length of the string
 */
int str_length(char *str)
{
	int length = 0;

	for (; str[length] != '\0'; length++)
		;

	return (length);
}
