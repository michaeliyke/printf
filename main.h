#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdarg.h>

int _putchar(char c);
int _printf(char *format, ...);
int _writeline(char *str);
int _putstring(char *str);
int _strlen(char *string);
int _writestring(char *str);
char *_strcpy(char *dest, char *src);
int print_int(long int n);
int print_u_int(unsigned int n);
int print_octal(unsigned int b);
char *_str_rev(char *str);
int print_hexadecimal(unsigned int b, int CAP);
int print_pointer(void *ptr);
int _printf_cont(char c, va_list ap);
int is_digit(char c);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int _abs(int written);

/* width handler */
int handle_write_char(char c, char buffer[],
		      int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
		 int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	      int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
		  int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
		 char buffer[],
		 int flags, int width, int precision, int size);

#endif
