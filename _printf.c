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
	int i, w = 0, state = 0, breaker;
	char c;

	if (fmt == NULL)
		return (0);
	va_start(ap, fmt);
	for (i = 0; c = fmt[i], c != '\0'; i++)
	{
		if (w == -1) /* if last write goes bad return */
			return (w);
		state = state == 0 && c == '%';
		if (state == 1)
		{
			state = 0;
			c = fmt[++i];
			if (c == '\0') /* % at pos \0 means no formatter */
				return (-1);
			switch (c)
			{
			case '%':
				_abs(_putchar('%'), &w);
				break;
			case 'd':
				_abs(print_int(va_arg(ap, int)), &w);
				break;
			default:
				/* other/unknown format */
				_abs(_printf_cont(c, ap), &w);
			}
			continue;
		}
		_abs(_putchar(c), &w);
	}
	return (w);
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
	switch (c)
	{
	case 's':
		return (_putstring(va_arg(ap, char *)));
	case 'c':
		return (_putchar(va_arg(ap, int)));
	case 'i':
		return (print_int(va_arg(ap, int)));
	case 'x':
		return (print_hexadecimal(va_arg(ap, int), 0));
	case 'u':
		return (print_u_int(va_arg(ap, int)));
	case 'o':
		return (print_octal(va_arg(ap, int)));
	case 'X':
		return (print_hexadecimal(va_arg(ap, int), 1));
	case 'p':
		return (print_pointer(va_arg(ap, char *)));
	default:
		/* Return error because % was provided without any format */
		return (_putchar('%') && _putchar(c) ? 2 : -1);
	}
	return (-1);
}

/**
 * _abs - get the number of written bytes
 * @written: number of bytes written or -1
 *@w: pointer the total written
 * Return: -1 for error or number of bytes written
 */
int _abs(int written, int *w)
{
	if (written < 0)
		return (-1);
	*w += written;
	return (*w);
}
