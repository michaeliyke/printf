#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - the base printf entry function
 * @format: the format string
 *
 * Return: interger count of printed charaters
 */
int _printf(char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	int len, i;
	char c;

	len = _strlen(format);
	for (i = 0; i < len; i++)
	{
		c = format[i];
		_putchar(c);
	}
	va_end(ap);
	return (0);
}
