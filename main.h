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
#endif
