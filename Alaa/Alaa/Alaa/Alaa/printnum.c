#include "main.h"

/**
 * printnum - function to print numbers.
 * @u: number to print
 * @base: base of system to print in.
 */

void printnum(unsigned int u, int base)
{
	char buffer[MAXBUFFER];
	char *p = &buffer[MAXBUFFER - 1];
	char digs[] = "0123456789abcdef";

	do
	{
		*p-- = digs[u % base];
		u /= base;
	} while (u != 0);

	while (++p != &buffer[MAXBUFFER])
		_putchar(*p);
}
