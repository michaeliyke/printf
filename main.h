#ifndef MAIN_H
#define MAIN_H
int _putchar(char c);
int _printf(char *format, ...);
int writeline(char *str);
int _putstring(char *str);
void printint(int n);
int isdigits(char *x);
int isdigit_(char x);
int atoi_(char *str);
int isspace_(char c);
int _strlen(char *string);
int isfspec(char *c);
int recognized(char c);
char *getspecend(char *start);
void variadic_test(char *, ...);
char *_strcpy(char *dest, char *src);
int getoffset(char *cpy, int i);
int compoffset(char *cpy, int i);
#endif
