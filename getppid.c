#include "shell.h"

/**
 * _getppid - get my ppid
 * Return: 0
 */

int _getppid()
{
	pid_t my_ppid;
	my_ppid = getppid();
	printf("%u", my_ppid);
	return(0);
}
