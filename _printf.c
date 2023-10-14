#include "main.h"

/**
* _printf - print string to standerd out put
*@format: string to be printed
*@Return: num of char printed
*/
int _printf(const char *format, ...)
{
int prntd_char, index = 0, fs_prntd = 0;
char buffer[BUF_LEN];
va_list para;
if (!format)
return (0);

va_start(para, format);
  
  while (format && *format)
  {
    if (*format != '%' && *format != '\0')
    {
      buffer[index++] = *format;
      if (index == BUF_LEN)
        prnt_buf(bufer, &index);
      
      ++prntd_char;
    }
      
    else
    {
  fs_prntd = hand_fs(format, buffer, &index, para);

    }

    
  }
  
return (prntd_char)
}

/**
  * prnt_buf - print buffer.
  *@buffer[] : is container contains charecter that will be printed.
  *@index: index to handle buffer size
  */
void prnt_buf (char buffer[], int *index)
{
if(index > 0)
  write(1, buffer, index)
  
  *index = 0;
}
