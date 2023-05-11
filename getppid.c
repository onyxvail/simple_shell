#include <stdio.h>
#include <unistd.h>

int getppid(void)
{
printf("Parent process PID: %d\n", getppid());
return 0;
}
