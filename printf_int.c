#include "main.h"

/**
 * print_u_int - Print an integer to the std output
 * @n: interger to print
 *
 * Return: void
 */
int print_u_int(unsigned int n)
{
	char buff[10], temp;
	int i = 0, j;

	do
	{
		buff[i++] = '0' + n % 10;
		n /= 10;
	} while (n > 0);
	buff[i] = '\0';
	j = 0;
	i--;
	while (i > j)
	{
		temp = buff[j];
		buff[j] = buff[i];
		buff[i] = temp;
		i--;
		j++;
	}
	return (_writestring(buff));
}

/**
 * print_int - Print an integer to the std output
 * @n: interger to print
 *
 * Return: void
 */
int print_int(long int n)
{
	char buff[10], temp;
	int i = 0, sign = 1, j;

	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	do
	{
		buff[i++] = '0' + n % 10;
		n /= 10;
	} while (n > 0);
	if (sign < 0)
		buff[i++] = '-';
	buff[i] = '\0';
	j = 0;
	i--;
	while (i > j)
	{
		temp = buff[j];
		buff[j] = buff[i];
		buff[i] = temp;
		i--;
		j++;
	}
	return (_writestring(buff));
}

/**
 * print_octal - converts an integer in base 10 to base 8 and print
 * @b: a number in base 10
 *
 * Return: number of bytes written or -1 if error
 */
int print_octal(unsigned int b)
{
	char *xyz = malloc(sizeof(*xyz) * 40);
	int i = 0;

	if (xyz == NULL)
		return (-1);
	while (b > 0)
	{
		xyz[i] = '0' + b % 8;
		b /= 8;
	}
	return (_writestring(xyz));
}
