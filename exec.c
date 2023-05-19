#include "shell.h"

/**
* executeCommand - Execute a command using fork and exec
* @command: The command to execute
* Description: This function creates a child process using fork and then
* uses the exec function to replace the child process with
* the specified command. If the execution fails, an error
* message is displayed. The parent process waits for the
* child process to complete before continuing.
*/

void executeCommand(char *command)
{
pid_t pid = fork();
if (pid == 0)
{
int status = execl(command, command, NULL);
if (status == -1)
{
printf("Error executing command: %s\n", command);
exit(1);
}
}
else if (pid > 0)
{
/* Parent process */
wait(NULL);
}
else
{
/* Fork failed */
printf("Fork failed\n");
}
}
