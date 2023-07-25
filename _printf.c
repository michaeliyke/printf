#include <stdlib.h>
#include <stdarg.h>
#include "main.h"
#include <stdio.h>

/**
 * _printf - the base printf entry function
 * @format: the format string
 *
 * Return: interger count of printed charaters
 */
int _printf(char *fmt, ...)
{
	va_list ap;
	int i = 0, writes = 0;

	va_start(ap, fmt);
	while (fmt[i] != '\0')
	{
		if (fmt[i] != '%')
			writes += _putchar(fmt[i]);
		else
		{
			i++;
			if (fmt[i] == '%')
				writes += _putchar('%');
			else if (fmt[i] == 'c')
				writes += _putchar(va_arg(ap, int));
			else if (fmt[i] == 's')
				writes += _putstring(va_arg(ap, char *));
			else if (fmt[i] == 'd')
				writes += print_int(va_arg(ap, int));
			else if (fmt[i] == 'i')
				writes += print_int(va_arg(ap, int));
			else if (fmt[i] == 'u')
				writes += print_u_int(va_arg(ap, int));
			else if (fmt[i] == 'o')
				writes += print_octal(va_arg(ap, int));
			else
			{
			}
		}
		i++;
	}
	va_end(ap);
	return (writes);
}
