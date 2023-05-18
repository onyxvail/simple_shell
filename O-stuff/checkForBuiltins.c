#include "onyxshell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BuiltInCommand builtInCommands[] = {
    {"env", printenvar},
    {"exit", exitshell},
    {NULL, NULL}
};

int checkForBuiltins(char **arguments, char **environment)
{
    int i;

    if (arguments[0] == NULL)
        return 0;

    for (i = 0; builtInCommands[i].command != NULL; i++)
    {
        if (strcmp(arguments[0], builtInCommands[i].command) == 0)
            return builtInCommands[i].function(arguments, environment);
    }

    return 0;
}
