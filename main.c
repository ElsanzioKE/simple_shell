#include "main.h"
void print_tokens(char **tokens)
{
	int i;
	for (i = 0; tokens[i] != NULL; i++)
	{
        	printf("%s\n", tokens[i]);
	}
}


#include "main.h"
/**
 * main - this is the main entry point of the shell program
 * Return: NULL
 */

int main(void)

{
	char *input, **tokens, *delim;

	delim = " \t\n";

	while(1)
	{
		if(isatty(STDIN_FILENO))
			display_prompt();
		input = get_input();
		tokens = parser(input, delim);
		print_tokens(tokens);
		break;

	}
	return (0);
}
