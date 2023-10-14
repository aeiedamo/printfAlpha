#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

#define BUF_LEN 1024

/**
  * struct format - is strucure to handle
  *@FS: format specifer
  *@F: pointer to function that print specific kind of argument
  */
typedef struct format
{
char FS;
int (*F) ()
} HANDLE;

#endif
