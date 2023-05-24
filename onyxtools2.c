#include "onyxshell.h"

/**
 * _itoa - convert int to array
 * @nt: the inputed number
 *
 * Return: A Pointer to the null terminated string
 */
char *_itoa(unsigned int nt)
{
	int len = 0, i = 0;
	char *s;

	len = intleng(nt);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (nt / 10)
	{
		s[i] = (nt % 10) + '0';
		nt /= 10;
		i++;
	}
	s[i] = (nt % 10) + '0';
	array_revs(s, len);
	s[i + 1] = '\0';
	return (s);
}
/**
 * _atoi - converts the character to int
 * @c: the given character
 *
 * Return: An int
 */
int _atoi(char *c)
{
	unsigned int val = 0;
	int sign = 1;

	if (c == NULL)
		return (0);
	while (*c)
	{
		if (*c == '-')
			sign *= (-1);
		else
			val = (val * 10) + (*c - '0');
		c++;
	}
	return (sign * val);
}

/**
 * intleng - Determine the number of digit int integer
 * @numb: the given number
 *
 * Return: the length of the integer
 */
int intleng(int numb)
{
	int len = 0;

	while (numb != 0)
	{
		len++;
		numb /= 10;
	}
	return (len);
}
/**
 * printing_error - prints the errors
 * @data: the data structure pointer
 *
 * Return: A Positive number on SUCCESS
 * In case of FAILURE return a negative number
 */
int printing_error(shl_t *data)
{
	char *idx = _itoa(data->index);

	PRINT("hsh: ");
	PRINT(idx);
	PRINT(": ");
	PRINT(data->args[0]);
	PRINT(": ");
	PRINT(data->error_msg);
	free(idx);
	return (0);
}

/**
 * write_hist - prints error
 * @data: the data structure pointer
 *
 * Return: A Positive number on SUCCESS
 * In case of FAILURE return a negative number
 */
int write_hist(shl_t *data __attribute__((unused)))
{
	char *filename = "history";
	char *line_of_history = "this is a line of history";
	ssize_t fd, w;
	int len;

	if (!filename)
		return (-1);
	fd = open(filename, O_RDWR | O_APPEND);
	if (fd < 0)
		return (-1);
	if (line_of_history)
	{
		while (line_of_history[len])
			len++;
		w = write(fd, line_of_history, len);
		if (w < 0)
			return (-1);
	}
	return (1);
}
