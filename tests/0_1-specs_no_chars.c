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
	    {"%ing%%%s", "%s"},
	    {"michael %d %s %fee", "%d%s"},

	    {"Js do %s%ing%", "%d%gs%s%s"},
	    {"%d, %0hls %s", "%d%0hls%s"},

	    {"Js %ddo%gs% %%ss%%ing%s%", "%d%gs%s"},
	};

	int i, tests = 1;
	struct pairs p;
	_writeline("\nTEST: Print The Format Specs skipping other Chars.");
	_writeline("----------\n");

	for (i = 0; i < tests; i++)
	{
		p = cases[i];
		_writestring("Input:\"");
		_writestring(p.a);
		_writestring("\"\nExpect:\"");
		_writestring(p.b);
		_writestring("\"\nOUTPUT:\"");
		_printf(p.a);
		_writestring("\"\n----------\n");
	}
}
