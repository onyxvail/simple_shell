#include "onyxshell.h"

/**
 * _strcatt - concatenates 2 string
 * @fst: the first given destination
 * @snd: the second given source
 *
 * Return: A new string on SUCCESS
 * In case of FAILURE return FAILURE
 */
char *_strcatt(char *fst, char *snd)
{
	int len1, len2, i = 0, j = 0;
	char *result;

	len1 = _strlen(fst);
	len2 = _strlen(snd);
	result = malloc((len1 + len2 + 2) * sizeof(char));
	if (!result)
		return (NULL);
	*result = '\0';
	while (fst[j])
		result[i++] = fst[j++];
	result[i++] = '/';
	j = 0;
	while (snd[j])
		result[i++] = snd[j++];
	result[i] = '\0';
	return (result);
}
/**
 * _strlen - finds the length of a given string
 * @str: the given string
 *
 * Return: the length of string on SUCCESS
 * In case of FAILURE return a negative number
 *
 */
int _strlen(char *str)
{
	int len;

	for (len = 0; str[len]; len++)
		;
	return (len);
}
/**
 * _strcmp - compare two strings
 * @s1: the first given string
 * @s2: the second given string
 *
 * Return: A Positive number on SUCCESS
 * In case of FAILURE return a negative number
 */
int _strcmp(char *s1, char *s2)
{
	int cmp = 0, i;

	if (s1 == NULL || s2 == NULL)
		return (1);
	for (i = 0; s1[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			cmp = s1[i] - s2[i];
			break;
		}
		else
			continue;
	}
	return (cmp);
}
/**
 * _strchr - locates a character in a given string
 * @str: the given string
 * @c: the given string
 *
 * Return: A Pointer when the first c occurs (SUCCESS)
 *a null pointer in case of (FAILURE)
 */
char *_strchr(char *str, char c)
{
	char *ptr;

	if (str == NULL)
		return (NULL);
	for (ptr = str; *ptr; ptr++)
		if (*ptr == c)
			return (ptr);
	return (NULL);
}
/**
 * _strdupl - dupicates string
 * @str: the given string
 *
 * Return: A Pointer to the duplicated string (SUCCESS)
 * A null pointer in case of (FAILURE)
 */
char *_strdupl(char *str)
{
	char *dupl;

	if (str == NULL)
		return (NULL);
	dupl = malloc(_strlen(str) + 1);
	if (dupl == NULL)
		return (NULL);
	_strcpyy(dupl, str);
	return (dupl);
}
