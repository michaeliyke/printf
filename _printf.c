#include <stdlib.h>
#include <stdarg.h>
#include "main.h"
#include <stdio.h>

int _printf_cont(char c, va_list ap);

/**
 * _printf - the base printf entry function
 * @fmt: the format string
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
				writes += _printf_cont(fmt[i], ap);
			}
		}
		i++;
	}
	va_end(ap);
	return (writes);
}

int _printf_cont(char c, va_list ap)
{
	if (c == 'x')
		return (print_hexadecimal(va_arg(ap, int), 0));
	else if (c == 'X')
		return (print_hexadecimal(va_arg(ap, int), 1));
	else if (c == 'p')
		return (print_pointer(va_arg(ap, char *)));
	else
	{
	}
}
// void print_pointer(void *ptr)