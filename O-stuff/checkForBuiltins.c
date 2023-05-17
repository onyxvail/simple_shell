#include "onyxshell.h"

typedef int (*BuiltinFunction)(char **arguments);

typedef struct {
    const char *command;
    BuiltinFunction function;
} BuiltInCommand;

int printenvar(char **arguments);
int exitshell(char **arguments);

BuiltInCommand builtInCommands[] = {
    {"env", printenvar},
    {"exit", exitshell},
    {NULL, NULL}
};
int i;
int builtInCheck(char **arguments, char **environment)
{
	(void)environment;

    if (arguments[0] == NULL)
        return 0;


    for (i = 0; builtInCommands[i].command != NULL; i++)
    {
        if (strcmp(arguments[0], builtInCommands[i].command) == 0)
            return builtInCommands[i].function(arguments);
    }

    return 0;
}


