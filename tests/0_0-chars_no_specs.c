#include "../main.h"
#include <stdio.h>

/**
 * main - entry point
 *
 * Return: void
 */
int main(void)
{
	/**
	 * struct pairs - output test struct
	 * @a: - input text
	 * @b: expected text
	 */
	struct pairs
	{
		char *a;
		char *b;
	};

	struct pairs cases[] = {
	    {"michael %d %s %fee", "michael   fee"},
	    {"%ing%%%s", "ing%"},

	    {"Js %ddo%gs %%%ss%%%ing%%%s", "Js do %s%ing%"},
	    {"%d, %0hls %s", ",  "},

	    {"Js %ddo%gs% %%ss%%ing%s%", "Js do% %ss%ing%"},
	};

	int i, tests = 5;
	struct pairs p;
	writeline("\nTEST: Print Chars Without The Format Specs.");
	writeline("----------\n");

	for (i = 0; i < tests; i++)
	{
		p = cases[i];
		_putstring("Input:\"");
		_putstring(p.a);
		_putstring("\"\nExpect:\"");
		_putstring(p.b);
		_putstring("\"\nOUTPUT:\"");
		_printf(p.a);
		_putstring("\"\n----------\n");
	}
}
