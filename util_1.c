#include <stdlib.h>
#include "main.h"
#include <stdarg.h>

/**
 * isfspec - checks if a region contains a valid format spec
 * @c: addess of first char in the region
 *
 * Return: 1 if true and 0 if not
 */
int isfspec(char *c)
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
 * getoffset - returns thr next print point skipping spec a region
 * @cpy: pointer to the string
 * @i: current position of index in loop
 *
 * Return: integer value of next print position
 */
int getoffset(char *cpy, int i)
{
	int j;

	j = compoffset(cpy, i);
	if (cpy[j] == '%' && j - i > 1)
	{ /* print chars between two % signs */
		if (!recognized(cpy[j - 1]))
			return (i += 1); /* skip only if no match */
	}
	return (j);
}

/**
 * compoffset - perfoms most of the computation details of getoffset
 * @cpy: pointer to the string
 * @i: current position of index in loop
 *
 * Return: integer value indicating possible next print position
 */
int compoffset(char *cpy, int i)
{
	if (cpy[i] == '\0')
	{
		if (cpy[i - 1] != '%' && !recognized(cpy[i - 1]))
		{
			while (cpy[i - 1] != '%' && !recognized(cpy[i - 1]))
				i--;
			return (i);
		}
		return (0);
	}
	if (cpy[i] == '%' && cpy[i + 1] == '%')
		return (i + 1);
	if (cpy[i] == '%')
		return (compoffset(cpy, i + 1));
	if (cpy[i] == ' ')
		return (i);
	if (recognized(cpy[i]))
		return (cpy[i + 1] == '\0' ? 0 : i + 1);
	return (compoffset(cpy, i + 1));
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
