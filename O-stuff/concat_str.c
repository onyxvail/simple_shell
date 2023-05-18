#include "onyxshell.h"

/**
 * str_concat - concatenates two strings
 * @str1: first string
 * @str2: second string
 * Return: pointer to the concatenated string
 */
char *str_concat(char *str1, char *str2)
{
	int len1 = 0;
	int len2 = 0;
	int i, j;
	char *result;

	if (str1 == NULL)
		str1 = "";
	if (str2 == NULL)
		str2 = "";

	for (i = 0; str1[i] != '\0'; i++)
		len1++;

	for (j = 0; str2[j] != '\0'; j++)
		len2++;

	result = malloc((len1 + len2 + 1) * sizeof(char));
	if (result == NULL)
		return NULL;

	for (i = 0; i < len1; i++)
		result[i] = str1[i];

	for (j = 0; j < len2; j++)
		result[len1 + j] = str2[j];

	result[len1 + len2] = '\0';

	return (result);
}
