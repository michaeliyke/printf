#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
va_list list, char buffer[], int flags, int width, int precision, int size);
#endif
