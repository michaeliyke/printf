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
int is_fspec(char *c);
int recognized(char c);
char *getspecend(char *start);
void variadic_test(char *, ...);
char *_strcpy(char *dest, char *src);
int get_offset(char *cpy, int i, struct offset_info *f);
int comp_offset(char *cpy, int i, struct offset_info *f);
int print_spec(char *cpy, struct offset_info *f);
/**
 * struct offset_info - offset info returned by computoffset
 * @pos: Holds last value of index i
 * @end: Holds boolean value 0 or 1 indicating if it's end of str or not
 *
 * While end is a boolean, pos is the index of next print position or end
 */
struct offset_info
{
	int pos;
	int end;
}
#endif
