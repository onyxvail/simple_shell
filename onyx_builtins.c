#include "onyxshell.h"

/**
 *onyx_builtins - function for builtin commands
 *@args: arguments
 *@line: command line
 *
 *Return: Always 0 on (success)
 */

int onyx_builtins(char **args, char *line)
{
int i, switch_args = 0;
char *onyx_list[3];

onyx_list[0] = "exit";
onyx_list[1] = "cd";
onyx_list[2] = "help";
onyx_list[3] = "env";

for (i = 0; i < 4; i++)
{
if (_strcmpr(args[0], onyx_list[i]) == 0)
{
switch_args = i + 1;
break;
}
}
switch (switch_args)
{
case 1:
onyx_abort(args, line);
break;
case 2:
cd(args[1], args);
return (1);
break;
case 3:
help();
return (1);
break;
case 4:
env();
return (1);
break;
default:
break;
}
return (0);
}
/**
 *onyx_abort - exiting the onyxshell function
 *@args: args
 *@line: cmd line
 *
 *Return: VOID
 */

void onyx_abort(char **args, char *line)
{
free(line);
line = NULL;
free(args);
args = NULL;
exit(0);
}

/**
 *cd - changing the  working directory
 *@path: path
 *@args: argument
 *
 *Return: Returning a new working directory
 */

int cd(char *path, char **args)
{
char *home;
char *old;

old = onyx_env("OLDPWD");
home = onyx_env("HOME");
if (!args[1])
{
return (chdir(home));
}
if (_strcmpr(args[1], "-") == 0)
return (chdir(old));
else
return (chdir(path));
return (0);
}

/**
 *help - this is a help function
 *
 *Return: Always 0 (SUCCESS)
 */

int help(void)
{
	write(STDOUT_FILENO, "Onyx Simple Shell\n", 14);
	write(STDOUT_FILENO, "Help:\n", 7);
	write(STDOUT_FILENO, "The Builtin commands:\n", 19);
	write(STDOUT_FILENO, "cd: Changing the  current working directory\n", 38);
	write(STDOUT_FILENO, "exit: exiting onyxshell\n", 18);
	write(STDOUT_FILENO, "help: displaying help\n", 21);
	return (0);
}

/**
 *env - A Function that prints env
 *
 *Return: VOID
 */

void env(void)
{
int i;

for (i = 0; environ[i]; i++)
{
write(STDOUT_FILENO, (const void *) environ[i], _strlen(environ[i]));
write(STDOUT_FILENO, "\n", 2);
}
}
