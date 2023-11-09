#include "main.h"
/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string to be concatenated.
 *
 * Return: Pointer to the concatenated string (dest).
 */
char *_strcat(char *dest, const char *src) 
{
	char *result = dest;

	while (*dest != '\0')
	{
		dest++;
	}


	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (result);
}
