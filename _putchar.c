#include <stdlib.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * writeline - write a string to the stdout followed by newline
 * @str - string to write
 *
 * Return: on successful return 1
 * On error, -1 is returned, and errno is set appropriately.
 */
int writeline(char *str)
{
	int n = _putstring(str);

	if (n == 1)
		_putchar('\n');
	return (n);
}

/**
 * _putstring - write a string to the stdout
 * @str - string to write
 *
 * Return: on successful return 1
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putstring(char *str)
{
	char *p = str;
	int n;

	if (str == NULL)
		return (-1);

	while (*p != '\0')
		n = _putchar(*p++);
	if (n != 1)
		return (n);
	return (1);
}

/**
 * printint - Print an integer to the std output
 * @n: interger to print
 *
 * Return: void
 */
void printint(int n)
{
	char buff[20], temp;
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
	j = 0;
	while (buff[j] != '\0')
	{
		_putchar(buff[j]);
		j++;
	}
}
