#include "onyxshell.h"

/**
 *_strlen - A Function that calculates the length of a string
 *@str: the string that will be calculated
 *
 *Return: lenghth
 */
int _strlen(char *str)
{
int i;

for (i = 0; str[i];)
i++;
return (i);
}

/**
 *_strcpy - A Function that cp strings
 *@destn: the destination of the string
 *@srcs: the source of t he string
 *
 *Return: string
*/
char *_strcpy(char *destn, char *srcs)
{
    int i;

    for (i = 0; srcs[i] != '\0'; i++)
    {
        destn[i] = srcs[i];
    }
    destn[i] = '\0';
    return (destn);
}
/**
 *_strdupt - A Function that return pointer to
 * a newly allocated spot in memory
 *@strt: pointer type char
 *Return: pointer type char
 */

char *_strdupt(char *strt)
{
int i = 0;
char *ings;
char *temp;

if (strt == NULL)
return (NULL);
while (strt[i])
i++;
ings = malloc(i + 1);
temp = ings;
if (ings == NULL)
return (NULL);
while (*strt)
*temp++ = *strt++;
*temp = '\0';
return (ings);
}
/**
 *_strcmpr - A Function that compares  2 strings
 *@ss1: pointer of type char
 *@ss2: pointer of type char
 *Return: integer
 */

int _strcmpr(char *ss1, char *ss2)
{
    int cmp = 0, i;

    if (ss1 == NULL || ss2 == NULL)
        return (1);
    for (i = 0; ss1[i]; i++)
    {
        if (ss1[i] != ss2[i])
        {
            cmp = ss1[i] - ss2[i];
            break;
        }
        else
            continue;
    }
    return (cmp);
}

/**
 *_strcate - A Function that concatinate 2 strings
 *@strg1: first string to concatinate
 *@strg2: second string to concatinate
 *Return: char
 */

char *_strcate(char *strg1, char *strg2)
{
int strg1_len, strg2_len, i = 0, j = 0;
char *conc;

strg1_len = _strlen(strg1);
strg2_len = _strlen(strg2);
conc = malloc((strg1_len + strg2_len + 2)*sizeof(char));
if (!conc)
	return (NULL);
*conc = '\0';
while (strg1[j])
	conc[i++] = strg1[j++];
conc[i++] = '/';
j = 0;
while (strg2[j])
conc[i++] = strg2[j++];
conc[i] = '\0';
return (conc);
}
