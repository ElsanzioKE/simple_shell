#include "main.h"
/**
 * display_prompt - displays the prompt in interactive mode
 * Return: nothing
 */

void display_prompt(void)
{
	char *prompt;

	prompt = "my_shell ";
	write(STDOUT_FILENO, prompt, _strlen(prompt));
}	
