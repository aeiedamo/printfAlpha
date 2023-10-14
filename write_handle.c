#include "main.h"
/**
  * write_char
  *@c: charecter
  @Return: int
  */
int write_char(char c, char buf[])
{
int count = 0
buf[count] = c;
return (write(1, &buf[0], 1));
}
