#include "main.h"
/**
 * execute - executes parsed commands
 * @tokens: pointer to the array of commands
 * Return: -1 on failure or 0 on succcess
 */

int execute(char **tokens)
{
	pid_t child_pid;
	int status;

	status = 0;

	if (tokens ==  NULL || tokens[0] == NULL)
	{
		return (-1);
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (execve(tokens[0], tokens, NULL) == -1)
		{
			perror("");
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(child_pid, &status, 0);
			if (WIFEXITED(status))
				return (WEXITSTATUS(status));
		}
	}
	return (0);


}
