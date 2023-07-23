#include <stdlib.h>

/**
 * strlen_ - returns length of a string
 * string - input string whose length is needed
 *
 * Return: length of string
 */
int _strlen(char *string)
{
	char *pointer = string;

	if (string == NULL || *string == '\0')
		return (0);
	while (*string != '\0')
		++string;
	return ((string - pointer));
}

/**
 * _strcpy - copies *src, including the \0 char,to dest
 * @dest: the destination of copy operation
 * @src: the source of copy operation
 *
 * Return: pointer to str
 */
char *_strcpy(char *dest, char *src)
{
	int i = _strlen(src);
	char *ptr = dest;

	while (i > 0 && *src != '\0')
	{
		*dest++ = *src++;
		i--;
	}
	*dest++ = '\0';
	return (ptr);
}
