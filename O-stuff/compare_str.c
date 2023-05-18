#include "onyxshell.h"

/**
 * string_compare - compares two strings
 * @str1: first string
 * @str2: second string
 * Return: 0 if the strings are equal, a negative value if str1 is less than str2,
 *         or a positive value if str1 is greater than str2
 */
int string_compare(char *str1, char *str2)
{
	int i;

	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
	{
		if (str1[i] != str2[i])
			return str1[i] - str2[i];
	}

	return (str1[i] - str2[i]);
}
