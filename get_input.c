#include "main.h"
/**
 * get_input - gets input from the commandline
 * using getline function
 * Return: buffer
 */

char *get_input()
{
	ssize_t input;
	size_t n;
	char *buffer;

	buffer = NULL;
	n = 0;

	input = getline(&buffer, &n, stdin);

	if (input < 0)
	{
		free(buffer);
		exit(EXIT_FAILURE);
	}
	if (buffer[input - 1] == '\n')
		buffer[input - 1] = '\0';
	return (buffer);
}
