#include "onyxshell.h"
/**
 * _strcpyy - cp a string
 * from source to destin
 * @source: source of the string
 * @destn: destination of the string
 *
 * Return: the pointer to the destination
 */
char *_strcpyy(char *destn, char *source)
{
	int i;

	for (i = 0; source[i] != '\0'; i++)
	{
		destn[i] = source[i];
	}
	destn[i] = '\0';
	return (destn);
}
/**
 * _isitalpha - check if the input is a letter
 * @cc: the character to be checked
 *
 * Return: 1 if its a letter, 0  otherwise
 */
int _isitalpha(int cc)
{
	if ((cc >= 65 && cc <= 90) || (cc >= 97 && cc <= 122))
	{
		return (SUCCESS);
	}
	return (FAILURE);
}
