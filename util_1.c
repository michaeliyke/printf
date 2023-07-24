#include <stdlib.h>
#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * isfspec - checks if a region contains a valid format spec
 * @c: addess of first char in the region
 *
 * Return: 1 if true and 0 if not
 */
int is_fspec(char *c)
{
	/**
	 * eg: %kjq0j %d, %d075 %0hls %s
	 */
	char space = ' ';
	int i = 0;

	if (c == NULL || *c != '%')
		return (0);

	while (c[i] != '\0' && c[i] != space)
	{
		if (recognized(c[i]))
			return (1);
		i++;
	}
	return (0);
}

/**
 * recognized - checks a char against a list of recognized chars
 * @c: char to check
 * Return: returns 1 if true and 0 if fals
 */
int recognized(char c)
{
	char *chars = "csd";
	int i;

	for (i = 0; i < _strlen(chars); i++)
		if (chars[i] == c)
			return (1);
	return (0);
}

/**
 * getspecend - gets the end address of a spec region
 * @start: the first char of the region
 *
 * Return: address of the last char of the region
 */
char *getspecend(char *start)
{
	int i = 1;
	/**
	 * eg: %kjq0j %d, %d075 %0hls %s
	 */
	while (recognized(start[i]) == 0)
		i++;
	return (&start[i]);
}

/**
 * printspec - nothing now
 */
int print_spec(char *cpy, struct offset_info *f)
{
	char *s;
	int i, pos, len = 0;

	pos = f->pos; /* from print char inclusive to % exclusive */
	while (cpy[pos--] != '%')
		len++;

	s = malloc(sizeof(*s) * len);
	for (i = 0; i < len; i++)
		s[i] = cpy[pos++];
	s[i] = '\0';
	_putstring(s);
	free(s);
	return (len);
}

/**
 * getoffset - returns thr next print point skipping spec a region
 * @cpy: pointer to the string
 * @i: current position of index in loop
 *
 * Return: integer value of next print position
 */
int get_offset(char *cpy, int i, struct offset_info *f)
{
	int j;

	j = comp_offset(cpy, i, f);
	if (cpy[j] == '%' && j - i > 1)
	{ /* print chars between two % signs */
		if (!recognized(cpy[j - 1]))
			j = (i += 1); /* skip only if no match */
	}
	/* printspec(j, i, cpy); */
	return (j);
}

/**
 * compoffset - perfoms most of the computation details of getoffset
 * @cpy: pointer to the string
 * @i: current position of index in loop
 * @f: struct to hold offset info
 *
 * Return: integer value indicating possible next print position
 */
int comp_offset(char *cpy, int i, struct offset_info *f)
{
	f->pos = i + 1; /* most common return value is i+1 not i */
	if (cpy[i] == '\0')
	{
		f->end = 1;
		if (cpy[i - 1] != '%' && !recognized(cpy[i - 1]))
		{
			while (cpy[i - 1] != '%' && !recognized(cpy[i - 1]))
				i--;
			return (i);
		}
		f->end = 0;
		f->pos = i;
		return (0);
	}
	if (cpy[i] == '%' && cpy[i + 1] == '%')
		return (i + 1);
	if (cpy[i] == '%')
		return (comp_offset(cpy, i + 1, f));
	if (cpy[i] == ' ')
	{
		f->pos--;
		return (i);
	}
	if (recognized(cpy[i]))
		if (cpy[i + 1] == '\0')
		{
			f->end = 1;
			return (0);
		}
	return (i + 1);
	return (comp_offset(cpy, i + 1, f));
}

/**
 * variadic - tests variadic functions args list behavious
 * @str: first string
 *
 * Return: void
 */
void variadic_test(char *str, ...)
{
	va_list ap;
	int i;
	int d;

	va_start(ap, str);
	for (i = 0; i < 30; i++)
	{
		d = va_arg(ap, int);
		/* should necessarily test if d is NULL */
		printint(d);
		_putchar('\n');
	}
	va_end(ap);
}
