#include "main.h"

/**
*
*
*/
int hand_char(buf[], va_list para)
{
char ch = va_arg(para, int);
return (write_char (ch, buf));
}

/**
*
*
*/
int hand_str (buf[], va_list para)
{
int length = 0;
char *str = va_arg(para, char*);

if (str == NULL)
	return (-1);
UNUSED (buf);
length = strlen(str);

return (write (1, &str, length));
}

/**
*
*
*/
int hand_percent(char buf[], va_list para)
{
UNUSED (buf);
UNUSED (para);
char per = '%';
return(write (1, &per, 1));
}
