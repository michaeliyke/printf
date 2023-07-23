#include "main.h"
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
	    {"%ing%%%s", "ing%"},
	    {"Js %ddo%gs %%%ss%%%ing%%%s", "Js dogs %s%ing%"},
	    {"Js %ddo%gs% %%ss%%ing%s%", "Js %ddo%gs% %%ss%%ing%s%"},
	    {"michael %d %s %f", "michael %d %s %f"},
	    {"%d, %0hls %s", ""},
	};

	int i, tests = 1;
	struct pairs p;

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
