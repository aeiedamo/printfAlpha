#ifndef MAIN_H
#define MAIN_H


#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define isdigit(c) ((c) >= '0' && c <= '9')
#define char2int(c) (c - '0')


#define MAXBUFFER (8 * sizeof(long int))

int _putchar(char c);

int _strlen(const char *str);

void printnum(unsigned int u, int base);

int _printf(const char *format, ...);

void doprint(const char *format, va_list *ptr, int radix);

void safeget(char *str, int maxlen);

int sprintf(char *buffer, const char *format, ...);


#endif
