#include "main.h"
/**
* handle_fs -
*@form: string
*@buf: buffer
*@ind: index track the buffer
*@para: va_list name
*Return num of printed char
*/

int handle_fs (char *form, int n,char buf[], int *ind, va_list para)
{
int count = 0, funcs = 'num of funcs'; 
HANDLE arr =
{
{'c', hand_char} {'%', handpercent} {'s', hand_str}
{'d', hand_int}
};

for (count = 0; count < funcs; count++)
{
if(arr[count].FS == form[n])
  return (arr[count].F(form, n, buf[], ind, para));
}

}
