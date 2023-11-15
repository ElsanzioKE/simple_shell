
#include "main.h"
/**
 * main - this is the main entry point of the shell program
 * Return: NULL
 */

int main(void)

{
	char *input, **tokens, *delim;
	int status, builtin;

	status = 0;

	delim = " \n\t";

	while (1)
	{
		if (isatty(STDIN_FILENO))
			display_prompt();
		input = get_input();


		if (input == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			continue;

		}
		tokens = parser(input, delim);
		builtin = find_builtin(tokens);
		if (builtin == -1)
			status = execute(tokens);
		free_tokens(tokens);
		free(input);
		if (status != 0)
			continue;
		if (isatty(STDIN_FILENO))
			continue;
	}
	return (0);
}
