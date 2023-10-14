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

int hand_str (char *forma, buf[], int *ind, va_list para)
{

int length = 0, prntd_num;
char *str = va_arg(para, char*);

if (str == NULL)
	return (0);

length = strlen(str);

write (1, &str, length);

return (length);
}

int hand_percent(char buf[], int *ind)
{
char per = '%';
write (1, &per, 1)
}
