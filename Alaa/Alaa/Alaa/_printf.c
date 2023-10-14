#include "main.h"

/**
 * _printf - function to print
 * @format: included formats
 * Return: number of elements printed
 */

int _printf(const char *format, ...)
{
	va_list ptr;

	va_start(ptr, format);
	doprint(format, &ptr, 16);
	va_end(ptr);

	return (0);
}
