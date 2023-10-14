#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

#define BUF_LEN 1024
#define UNUSED(x) (void)(x) /* tell that anything after unused will cast to void so that even if we didn't used parametes it compile fine

/**
  * struct format - is strucure to handle
  *@FS: format specifer
  *@F: pointer to function that print specific kind of argument
  */
typedef struct format
{
char FS;
int (*F) (char *, buf[], int, va_list)
} HANDLE;

int _printf(const char *format, ...);
void prnt_buf (char buffer[], int *index);


#endif
