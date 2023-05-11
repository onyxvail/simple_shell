#include <stdio.h>
#include <unistd.h>

int main()
{
printf("Parent process PID: %d\n", getppid());
return 0;
}
