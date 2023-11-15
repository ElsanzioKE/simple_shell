#include "main.h"

/**
 * my_exit - exits the shell with status
 * @args: arguments;
 * Return: nothing
 */

int my_exit(char **args)
{
	int exit_status;

	if (args[1] != NULL)
	{
		exit_status = atoi(args[1]);
		exit(exit_status);
	}
	else
	{
		exit(0);
	}
	return (0);
}
