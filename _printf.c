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
			writes += _abs(_putchar(fmt[i]));
		else
		{
			i++;
			if (fmt[i] == '%')
				writes += _abs(_putchar('%'));
			else if (fmt[i] == 'c')
				writes += _abs(_putchar(va_arg(ap, int)));
			else if (fmt[i] == 's')
				writes += _abs(_putstring(va_arg(ap, char *)));
			else if (fmt[i] == 'd')
				writes += _abs(print_int(va_arg(ap, int)));
			else if (fmt[i] == 'i')
				writes += _abs(print_int(va_arg(ap, int)));
			else if (fmt[i] == 'u')
				writes += _abs(print_u_int(va_arg(ap, int)));
			else if (fmt[i] == 'o')
				writes += _abs(print_octal(va_arg(ap, int)));
			else
			{
				writes += _abs(_printf_cont(fmt[i], ap));
			}
		}
		i++;
	}
	va_end(ap);
	return (writes);
}

/**
 * _printf_cont - continue the conditional branching of _printf
 * @c: the char being tested
 * @ap: va_list variable used for getting the next argument
 *
 * Return: number of chars written
 */
int _printf_cont(char c, va_list ap)
{
	if (c == 'x')
		return (print_hexadecimal(va_arg(ap, int), 0));
	else if (c == 'X')
		return (print_hexadecimal(va_arg(ap, int), 1));
	else if (c == 'p')
		return (print_pointer(va_arg(ap, char *)));
}

/**
 * _abs - get the number of written bytes
 * @written: number of bytes written or -1
 *
 * Return: 0 or number of bytes written
 */
int _abs(int written)
{
	return (written > 0 ? written : 0);
}
