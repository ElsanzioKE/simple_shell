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
	char *command, *full_path;

	status = 0;

	if (tokens ==  NULL || tokens[0] == NULL)
	{
		return (0);
	}

	command = tokens[0];
	full_path = find_path(command);
	if (full_path == NULL)
	{
		perror("command not found");
		return(1);
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (execve(full_path, tokens, environ) == -1)
		{
			perror("execve");
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
