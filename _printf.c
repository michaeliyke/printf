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
	int i, j, writes = 0, len = _strlen(format);
	char *cpy = malloc(_strlen(format));

	va_start(ap, format);
	_strcpy(cpy, format);
	for (i = 0; i < len; i++)
	{
		if (cpy[i] == '%')
		{ /* move i to the next print point */
			j = getoffset(cpy, i);
			if (j == 0)
				break;
			i = j;
		}

		_putchar(cpy[i]);
		writes++;
	}
	va_end(ap);
	return (writes);
}
