#include "onyxshell.h"

/**
 *_strchrs - A Function that spot a character in a string
 *@st: pointer type char
 *@ch: char
 *Return: sm or NULL if the character is  not found
 */

char *_strchrs(char *st, char ch)
{
    char *ptr;

    if (st == NULL)
        return (NULL);
    for (ptr = st; *ptr; ptr++)
        if (*ptr == ch)
            return (ptr);
    return (NULL);
}
/**
 * itoa - A Function that converts an int to an array
 * @nm: the given number
 *
 * Return: a pointer to the null terminated string
 */
char *itoa(unsigned int nm)
{
int len = 0, i = 0;
char *sm;

len = intleng(nm);
sm = malloc(len + 1);
if (!sm)
return (NULL);
while (nm / 10)
{
sm[i] = (nm % 10) + '0';
nm /= 10;
i++;
}
sm[i] = (nm % 10) + '0';
rev_array(sm, len);
sm[i + 1] = '\0';
return (sm);
}

/**
 * intleng - Determine the number of digit int
 * @nums: the given number
 *
 * Return: the length of the int
 */

int intleng(int nums)
{
int leng = 0;

while (nums != 0)
{
leng++;
nums /= 10;
}
return (leng);
}

/**
 *rev_array - A Function that reverse the arrays
 *@arrs: array to be reversed;
 *@leng: lenght
 *
 *Return: Void
 */

void rev_array(char *arrs, int leng)
{
int i;
char tmp;

for (i = 0; i < (leng / 2); i++)
{
tmp = arrs[i];
arrs[i] = arrs[(leng - 1) - i];
arrs[(leng - 1) - i] = tmp;
}
}
