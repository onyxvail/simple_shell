#include "shell.h"

/**
 * _getpid - get my pid
 * Return: 0
 */

int _getpid()
{
	pid_t my_pid;
	my_pid = getpid();
	printf("%u", my_pid);
	return (0);
}
