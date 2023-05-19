#include "shell.h"

/**
* main - Entry point for the simple shell program
* Description: This function implements a simple shell program that reads
* commands from the user, executes them using the system()
* function, and displays any errors that occur during execution.
* It uses the getline() function to read input lines from the user.
* The loop continues until the user enters EOF (Ctrl+D).
* Return: Always returns 0.
*/

int main(void)
{
char *command = NULL;
size_t bufsize = 0;
ssize_t getline_result;
int status;

while (1)
{
printf("onyxshell>> ");
fflush(stdout);
getline_result = getline(&command, &bufsize, stdin);
if (getline_result == -1)
{
break;
}
status = system(command);
if (status != 0)
{
printf("Error executing command: %d\n", status);
}
}
free(command);
return (0);
}
