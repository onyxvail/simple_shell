#include "onyxshell.h"

/**
 * convertStringToInteger - convert a string to an integer
 * @str: string to be converted
 * Return: integer value
 */
int convertStringToInteger(char *str)
{
	int i, sign;
	unsigned int num;

	num = i = 0;
	sign = 1;

	while ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}

	for (; str[i] != '\0' && str[i] >= '0' && str[i] <= '9'; i++)
	{
		num = num * 10 + (str[i] - '0');
	}

	num *= sign;
	return (num);
}
