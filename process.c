#include "shell.h"

int onyxshell_process(char **args)
{
pid_t pid;
int status;
pid = fork();
if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
perror("Onyxshell");
}
exit(EXIT_FAILURE);
    
} else if (pid < 0)
{
perror("Onyxshell");
}
else
{
do
{
waitpid(pid, &status, WUNTRACED);
}
while (!WIFEXITED(status) && !WIFSIGNALED(status));

return (WEXITSTATUS(status));

}
return (0);
}

