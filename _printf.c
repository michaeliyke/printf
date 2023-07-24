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
int _printf(char *format, ...)
{
	va_list ap;
	int i, j, writes = 0, len = _strlen(format);
	char *cpy = malloc(sizeof(*cpy) * _strlen(format));
	struct offset_info f = {0, 0};
	// struct spec sp = {};

	va_start(ap, format);
	_strcpy(cpy, format);
	for (i = 0; j = i, i < len; i++)
	{
		if (cpy[i] == '%')
		{ /* move i to the next print point */
			j = get_offset(cpy, i, &f);
			print_spec(cpy, &f);
			if (j == 0)
				break;
		}

		/* _putchar(cpy[i]); */
		writes++;
	}
	free(cpy);
	va_end(ap);
	return (writes);
}
