#include "main.h"

/**
 * _strlen - to find length of string
 * @str: pointer to string
 * Return: length of string
 */

int _strlen(const char *str)
{
	const char *s;

	for (s = str; *s; ++s);
	return (s - str);
}
