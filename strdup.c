#include "main.h"
/**
 * _strdup - duplicates a string
 * @str: string to be duplicated
 * Return: duplicate
 */

char *_strdup(const char *str)
{
	size_t len, i;
	char *duplicate;
	if (str == NULL)
	{
		return (NULL);
	}

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}

	duplicate = (char *)malloc(len + 1);
	if (duplicate == NULL)
	{
		return (NULL);
	}

	for (i = 0; i <= len; i++)
	{
		duplicate[i] = str[i];
	}

	return (duplicate);
}

