#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define BUFF_SIZE 1024

int _putchar(char c);
int is_digit(char);
int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/* Handlers */
int helper_flags(const char *format, int *i);
int helper_width(const char *format, int *i, va_list list);
int helper_precision(const char *format, int *i, va_list list);
int helper_size(const char *format, int *i);

/* Variable Sizes */
#define S_LONG 2
#define S_SHORT 1

/*Flag Macros */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#endif
