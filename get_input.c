#include "main.h"
/**
 * is_empty - checks for spaces without command
 * @str - string to test
 * Return: true
 */

bool is_empty(const char *str)
{
	size_t i;
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] != ' ')
		{
			return (false);
		}
	}
	return (true);
}
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

	if (input == -1)
	{
		free(buffer);
		exit(EXIT_FAILURE);
	}
	if (is_empty(buffer))
	{
		free(buffer);
		return (NULL);
	}
	if (buffer[input - 1] == '\n')
		buffer[input - 1] = '\0';
	return (buffer);
}
