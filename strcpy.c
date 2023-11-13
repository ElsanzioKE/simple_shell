#include "main.h"
/**
 * _strcpy - Copies a string from source to destination.
 * @dest: The destination string where the copy will be stored.
 * @src: The source string to be copied.
 *
 * Return: Pointer to the destination string (dest).
 */
char *_strcpy(char *dest, const char *src)
{
	char *result = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (result);
}

