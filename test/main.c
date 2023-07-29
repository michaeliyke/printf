#include <limits.h>
#include <stdio.h>
#include "../main.h"

void others(void);

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;
	int len2;
	unsigned int ui;
	void *addr;
	(void)addr;
	(void)ui;

	ui = (unsigned int)INT_MAX + 1024;
	len = _printf("%");
	len2 = -1; /* That's what below result gives */
	/* len2 = printf("%"); */
	fflush(stdout);
	printf("len: %d, lenR: %d, len == lenR: %d\n", len, len2, len == len2);
	fflush(stdout);

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]R\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]R\n", -762534);
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]R\n", ui);
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]R\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]R\n", ui, ui);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]R\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]R\n", "I am a string !");
	others();
	return (0);
}

/**
 * others - other tests
 *
 * Return: void
 */
void others(void)
{
	int len;
	int len2;
	void *addr = (void *)NULL;

	_printf("Address:[%p]\n", addr);
	printf("Address:[%p]R\n", addr);
	addr = (void *)0x7ffe637541f0;
	/* addr = &len; */
	_printf("Address:[%p]\n", addr);
	printf("Address:[%p]R\n", addr);
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]R\n");
	_printf("Len:[%d]\n", len + 1);
	printf("Len:[%d]R\n", len2);
	_printf("Unknown:[%r]\n");
	printf("Unknown:[%%r]R\n"); /* An extra % added for error sake */
}
