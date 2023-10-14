#include "main.h"

/**
* _printf - print strings to standerd output
*@format: string to be printed
*@Return: num of char printed.
*/
int _printf(const char *format, ...)
{
int prntd_char = 0, index = 0, fs_prntd = 0, i = 0;
char buffer[BUF_LEN];
va_list para;

if (!format)
return (-1);

va_start(para, format);

  while (format[i] != '\0')
  {
    if (format[i] != '%')
    {
      buffer[index++] = format[i];
      if (index == BUF_LEN)
      prnt_buf(buffer, &index);
      ++prntd_char;
    }
      
    else
    {
  fs_prntd = handle_fs(format, int i, buffer, &index, para);

      prntd_char += fs_prntd;
    }
    
++i;
  }
  // prnt_buf(buffer, &index);
  
return (prntd_char);
}

/**
  * prnt_buf - print buffer.
  *@buffer : is container contains charecter that will be printed.
  *@index: index to handle buffer size
  */
void prnt_buf (char buffer[], int *index)
{
if(*index > 0)
  write(1, buffer, *index);
  *index = 0;
}
