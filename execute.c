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
	printf("%s: \n", full_path);
	if (full_path == NULL)
		print_command_not_found_error(command, 127);
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_SUCCESS);
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
#include "main.h"
/**
 * print_command_not_found_error - prints to
 * stderr the error statement when command is not found
 * @command: command to be executed
 * @exit_status: exit status after execution
 * Return: nothing
 */

void print_command_not_found_error(char *command, int exit_status)
{
	char *error_message;

	error_message = "not found\n";
	write(STDERR_FILENO, "./hsh: ", 7);
	write(STDERR_FILENO, "1: ", 3);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, error_message, _strlen(error_message));
	exit(exit_status);
}

