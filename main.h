#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>

int _putchar(char c);
int _printf(char *format, ...);
int _writeline(char *str);
int _putstring(char *str);
int _strlen(char *string);
int _writestring(char *str);
char *_strcpy(char *dest, char *src);
<<<<<<< Updated upstream
int print_int(long int n);
int print_u_int(unsigned int n);
int print_octal(unsigned int b);
char *_str_rev(char *str);
=======
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
};
>>>>>>> Stashed changes
#endif
