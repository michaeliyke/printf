#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1 since only one char is needed to be written.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * writeline - write a string to the stdout followed by newline
 * @str - string to write
 *
 * Return: number of bytes written or -1 on error
 * On error, -1 is returned, and errno is set appropriately.
 */
int _writeline(char *str)
{

	ssize_t bytes_written;

	bytes_written = _writestring(str);
	if (bytes_written > 0)
	{
		if (_putchar('\n') != 1)
			return (-1);
		return (bytes_written + 1);
	}
	return (-1);
}

/**
 * write_string - write a string to the stdout followed by newline
 * @str - string to write
 *
 * Return: number of bytes written or -1 on error
 * On error, -1 is returned, and errno is set appropriately.
 */
int _writestring(char *str)
{

	ssize_t bytes_written;

	if (str == NULL)
		return (-1);
	bytes_written = write(STDOUT_FILENO, str, _strlen(str));
	return (bytes_written > 0 ? bytes_written : -1);
}

/**
 * _putstring - write a string to the stdout followed by newline
 * @str - string to write
 *
 * Return: number of bytes written or -1 on error
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putstring(char *str)
{
	return _writestring(str);
}
