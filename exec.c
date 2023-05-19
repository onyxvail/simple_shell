#include "shell.h"


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
