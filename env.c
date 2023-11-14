#include "main.h"
/**
 * my_env - prints current working environment
 * @args: unused arguments parameter
 * Return: 0 if successful, -1 otherwise
 */
int my_env(char **args)
{

	char **envp;
	(void)args;
	envp = environ;

	while (*envp != NULL)
	{
		write(STDOUT_FILENO, *envp, _strlen(*envp));
		write(STDOUT_FILENO, "\n", 1);
		envp++;
	}

	return (0);
}

