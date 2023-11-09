
#include "main.h"
/**
 * main - this is the main entry point of the shell program
 * Return: NULL
 */

int main(void)

{
	char *input, **tokens, *delim;
	int status;
	
	status = 0;

	delim = " \t\n";

	while(1)
	{
		if(isatty(STDIN_FILENO))
			display_prompt();
		input = get_input();


		if (input == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			break;
	
		}
		tokens = parser(input, delim);
		status = execute(tokens);
		free_tokens(tokens);
		free(input);
		if (status != 0)
		{
			continue;
		}

	}
	return (0);
}
