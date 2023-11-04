#include "shell.h"
/*
 * print_prompt - prints a prompt.
 * @prompt - stores the prompt.
 * Return - Always 0.
 */
int print_prompt(void)
{
	char *prompt;

	prompt = ":) ";
	write(1, prompt, strlen(prompt));

	return (0);
}
