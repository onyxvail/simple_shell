#include "onyxshell.h"

/**
 * onyx_env - A Function that gets an enviroment variable
 * by its name
 * @nameof: the variable's name
 *
 * Return: Environment when SUCCESS
 * NULL when FAILURE
 */

char *onyx_env(char *nameof)
{
char **env_pt;
char *ch_pt;
char *name_pt;

env_pt = environ;
while (*env_pt != NULL)
{
for (ch_pt = *env_pt, name_pt = nameof; *ch_pt == *name_pt; ch_pt++, name_pt++)
{
if (*ch_pt == '=')
break;
}
if ((*ch_pt == '=') && (*name_pt == '\0'))
return (ch_pt + 1);
env_pt++;
}
return (NULL);
}
