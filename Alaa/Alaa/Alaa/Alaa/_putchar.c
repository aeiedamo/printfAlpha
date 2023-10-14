#include "main.h"

/**
 * _putchar - function to print char.
 * @c: the char to be printed.
 * Return: 1 on success, -1 on error.
 */

int _putchar(char c)
{
	return(write(1, &c, 1));
}
