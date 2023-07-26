#include <stdlib.h>
#include <stdarg.h>
#include "main.h"
#include <stdio.h>

int _printf_cont(char c, int field_width, va_list ap);

/**
 * _printf - the base printf entry function
 * @fmt: the format string
 *
 * Return: integer count of printed characters
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
			else if (fmt[i] == 'd' || fmt[i] == 'i')
				writes += print_int(va_arg(ap, int));
			else if (fmt[i] == 'u')
				writes += print_u_int(va_arg(ap, int));
			else if (fmt[i] == 'o')
				writes += print_octal(va_arg(ap, int));
			else
			{
				int field_width = 0;
				/* Parse field width */
				while (fmt[i] >= '0' && fmt[i] <= '9')
				{
					field_width = field_width * 10 + (fmt[i] - '0');
					i++;
				}
				if (fmt[i] == 'x')
					writes += print_hexadecimal(va_arg(ap, int), 0, field_width);
				else if (fmt[i] == 'X')
					writes += print_hexadecimal(va_arg(ap, int), 1, field_width);
				else if (fmt[i] == 'p')
					writes += _writestring(va_arg(ap, char *));
				else
				{
					/* Invalid specifier, skip it */
				}
			}
		}
		i++;
	}
	va_end(ap);
	return (writes);
}
