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

	do {
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
	do {
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
 * print_pointer - prints a pointer value in hexadecimal
 * @ptr: void pointer
 *
 * Return: void
 * Convert the pointer value to a hexadecimal string using bitwise
 * operations and the lookup table
 */
int print_pointer(void *ptr)
{
	char table[] = "0123456789abcdef", digit;
	int index, i, j, padding;
	unsigned long val = (unsigned long)ptr;
	char hex_str[18], truncated[18] = {'0', 'x'};

	if (ptr == NULL)
		return (write(1, "(nil)", 6));
	for (i = 0; i < 16; i++)
	{
		index = val & 0xf;
		digit = table[index];
		hex_str[17 - i] = digit;
		val >>= 4;
	}

	j = 2;
	padding = 1;
	while (j < 18)
	{
		if (padding && hex_str[j] == '0')
		{
			j++;
			continue;
		}
		else if (padding)
		{
			padding = 0;
		}
		truncated[j] = hex_str[j];
		j++;
	}
	truncated[j] = '\0';
	return (write(1, truncated, j));
}
