#include "main.h"

/**
 * print_octal - converts an integer in base 10 to base 8 and print
 * @b: a number in base 10
 *
 * Return: number of bytes written or -1 if error
 */
int print_octal(unsigned int b)
{
	char *xyz = malloc(sizeof(*xyz) * 40);
	int i = 0, bytes_written;

	if (xyz == NULL)
		return (-1);
	if (b == 0) /* 2147484671 */
		xyz[0] = '0';
	while (b > 0)
	{
		xyz[i++] = '0' + b % 8;
		b /= 8;
	}
	bytes_written = _writestring(_str_rev(xyz));
	free(xyz);
	return (bytes_written);
}

/**
 * print_bin - converts an integer in base 10 to binary and print
 * @b: a number in base 10
 *
 * Return: number of bytes written or -1 if error
 */
int print_bin(unsigned int b)
{
	char *xyz = malloc(sizeof(*xyz) * 100);
	int i = 0, bytes_written;

	if (xyz == NULL)
		return (-1);
	if (b == 0)
		xyz[0] = '0';
	while (b > 0)
	{
		xyz[i++] = '0' + b % 8;
		b /= 8;
	}
	bytes_written = _writestring(_str_rev(xyz));
	free(xyz);
	return (bytes_written);
}

/**
 * print_hexadecimal - Convert an int in base 10 to base 16 and print.
 * @b: A number in base 10.
 * @CAP: whether output is capitalized or not
 *
 * Return: Number of bytes written or -1 if there's an error.
 */
int print_hexadecimal(unsigned int b, int CAP)
{
	char *xyz = malloc(sizeof(*xyz) * 40);
	int i = 0, bytes_written, remainder;

	if (xyz == NULL)
		return (-1);
	if (b == 0)
		xyz[0] = '0';
	while (b > 0)
	{
		remainder = b % 16;
		if (remainder < 10)
			xyz[i++] = '0' + remainder;
		else
			xyz[i++] = (CAP ? 'A' : 'a') + (remainder - 10);
		b /= 16;
	}
	bytes_written = _writestring(_str_rev(xyz));
	free(xyz);
	return (bytes_written);
}
