#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * isdigits - reports if eachchars of a string is a digit beween 0 and 9
 * @x: input string
 *
 * Return: 1 if true and 0 if false
 */
int isdigits(char *x)
{
	while (*x != '\0')
	{
		if (isdigit_(*x) == 0)
			return (0);
		++x;
	}
	return (1);
}

/**
 * isdigit - reports if eachchars of a string is a digit beween 0 and 9
 * @x: input char
 *
 * Return: 1 if true and 0 if false
 */
int isdigit_(char x)
{
	return (x > 47 && x < 58);
}

/**
 * atoi - convert a string into number
 * -check null and return 0
 * skip leading white spaces using while and ptr++
 * determine the sign if provided from the frist char
 * initialize result
 * Loop on if digit
 * set digit
 * check if result > INT_MAX / 10 || (result == IN_MAX / 10 && digit > INT_MAX %10)
 *       then return if sign is 1 INT_MAX else INT_MIN
 * result = (result * 10) + digit
 * p++
 * end loop
 * return sign * result
 */

/**
 *  atoi - convert a string into number
 * returns 0 if str is not numeric
 * @str: string input
 *
 * Return: integer value on the string
 */
int atoi_(char *str)
{
	int sign, result, digit;

	if (str == NULL || *str == '\0')
		return (0);
	while (isspace_(*str))
		++str;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	else if (*str == '+')
	{
		++str;
	}
	result = 0;
	while (isdigit_(*str))
	{
		digit = *str - '0';
		if (result > INT_MAX / 10 ||
		    (result == INT_MAX / 10 && digit > INT_MAX % 10))
		{
			return (sign == 1 ? INT_MAX : INT_MIN);
		}
		result = ((result * 10) + digit);
		++str;
	}
	return (sign * result);
}

/**
 * isspace_ - report if a given char token is a space char
 * @c: char token to check
 *
 * Return: 1 if true and 0 if false
 */
int isspace_(char c)
{
	int i;
	char sp_chars[7] = {'\n', ' ', '\t', '\f', '\r', '\v', '\0'};

	for (i = 0; i < 7; i++)
	{
		if (sp_chars[i] == c)
			return (1);
	}
	return (0);
}

/**
 * convert intiger into a string and print it
 * create buffer of 20 slots
 * init iterator to 0
 * init sign to 1
 * if num is neg, set sign to neg and make num postive
 * use do while loop to generate digits in reverse order as follows
 * do add '0'+ num % 10 to buffer on slot i++
 * set num to num divided by 10
 * while num is greater than 0
 * if sign is neg, include the - sign
 * end with null-terminator
 *
 * Reverse the string using two pointers
 * use i, and j to reverse the string - i is lready at the end of the string
 * reset j to 0
 * using j, loop through the string and print it using putchar
 */
