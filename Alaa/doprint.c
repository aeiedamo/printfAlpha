#include "main.h"

/**
 * doprint - the actual printer
 * @format: included formats
 * @ptr: pointer to arguments
 * @radix: default radix
 */

void doprint(const char *format, va_list *ptr, int radix)
{
	bool doprint_trunc = false;
	int length = 0;
	int prec = -1;
	bool ladjust = false;
	char padc = ' ';
	long n;
	unsigned long u;
	int plus_sign = 0;
	int sign_char = 0;
	bool altformat = false, truncate;
	int base;
	char c;
	int capitals;

	while ((c = *format) != 0)
	{
		if (c != '%')
		{
			_putchar(c);
			format++;
			continue;
		}
	}

	format++;

	while (true)
	{
		c = *format;
		if (c == '#')
			altformat = true;
		else if (c == '-')
			ladjust = true;
		else if (c == '+')
			plus_sign = '+';
		else if (c == ' ')
		{
			if (plus_sign == 0)
				plus_sign = ' ';
		}
		else
			break;
		format++;
	}

	if (c == '0')
	{
		padc = '0';
		c = *++format;
	}

	if (isdigit(c))
	{
		while (isdigit(c))
		{
			length = 10 * length + char2int(c);
			c = *++format;
		}
	}

	else if (c == '*')
	{
		length = va_arg(*ptr, int);
		c = *++format;

		if (length < 0)
		{
			ladjust = !ladjust;
			length = -length;
		}
	}

	if (c == '.')
	{
		c = *++format;
		if (isdigit(c))
		{
			prec = 0;
			while (isdigit(c))
			{
				prec = 10 * prec + char2int(c);
				c = *++format;
			}
		}

		else if (c == '*')
		{
			prec = va_arg(*ptr, int);
			c = *++format;
		}
	}

	if (c == '1')
		c = *++format;

	truncate = false;
	capitals = 0;

	switch (c)
	{
		case 'b':
		case 'B':
			{
				char *p;
				bool any;
				int i;

				u = va_arg(*ptr, unsigned long);
				p = va_arg(*ptr, char *);

				base = *p++;
				printnum(u, base);

				if (u == 0)
					break;

				any = false;

				while ((i = *p++) != 0)
				{
					if (*format == 'B')
						i = 33 - i;

					if (*p <= 32)
					{
						int j;

						if (any)
							_putchar(',');
						else
						{
							_putchar('<');
							any = true;
						}
						j = *p++;
						if (*format == 'B')
							j = 32 - j;
						
						for (; (c = *p) > 32; p++)
							_putchar(c);

						printnum((unsigned)( (u>>(j-1)) & ((2<<(i-j))-1)),base);
					}

					else if (u & (i << (i - 1)))
					{
						if (any)
							_putchar(',');

						else
						{
							_putchar('<');
							any = true;
						}
						for (; (c = *p) > 32; p++)
							_putchar(c);
					}

					else
					{
						for (; *p > 32; p++)
							continue;
					}
				}

				if (any)
					_putchar('>');
				break;
			}
		case 'c':
			c = va_arg(*ptr, int);
			_putchar(c);
			break;
		case 's':
			{
				char *p1, *p2;

				if (prec == -1)
					prec = 0x7fffffff;

				p1 = va_arg(*ptr, char *);

				if (p1 == (char *)0)
					p1 = "";

				if (length > 0 && !ladjust)
				{
					n = 0;
					p2 = p1;
					for (; *p1 != 0 && n < prec; p1++)
						n++;
					p1 = p2;
					while (n < length)
					{
						_putchar(' ');
						n++;
					}
				}

				n = 0;
				if (*p1 != 0)
				{
					if (++n > prec || (length > 0 && n > length))
						break;
					_putchar(*p1++);
				}

				if (n < length && ladjust)
				{
					while (n < length)
					{
						_putchar(' ');
						n++;
					}
				}

				break;
			}
		case 'o':
			truncate = doprint_trunc;
			break;
		case 'O':
			base = 8;
			goto print_unsigned;
			break;
		
		
		case 'd':
			truncate = doprint_trunc;
			break;
		case 'D':
			base = 10;
			goto print_signed;

		case 'u':
			truncate = doprint_trunc;
			break;
		case 'U':
			base = 10;
			goto print_unsigned;
		case 'p':
			altformat = true;
			break;
		case 'x':
			truncate = doprint_trunc;
			base = 16;
			goto print_unsigned;
		case 'X':
			base = 16;
			capitals = 16;
			goto print_unsigned;
		case 'z':
			truncate = doprint_trunc;
			base = 16;
			goto print_signed;
		case 'Z':
			base = 16;
			capitals = 16;
			goto print_signed;

		case 'r':
			truncate = doprint_trunc;
			break;
		case 'R':
			base = radix;
			goto print_signed;

		case 'n':
			truncate = doprint_trunc;
			break;
		case 'N':
			base = radix;
			goto print_unsigned;

print_signed:
			n = va_arg(*ptr, long);
			if (n >= 0)
			{
				u = n;
				sign_char = plus_sign;
			}
			else
			{
				u = -n;
				sign_char = '-';
			}
			goto print_num;

print_unsigned:
			u = va_arg(*ptr, unsigned long);
			goto print_num;

print_num:
			{
				char buffer[MAXBUFFER];
				char *p = &buffer[MAXBUFFER - 1];
				char digits[] = "0123456789abcdef0123456789ABCEDF";
				char *prefix = 0;

				if (truncate)
					u = (long)((int)(u));

				if (u != 0 && altformat)
				{
					if (base == 8)
						prefix = "0";
					else if (base == 16)
						prefix = "0x";
				}

				do
				{
					*p-- = digits[(u % base) + capitals];
					u /= base;
				} while (u != 0);

				length -= (&buffer[MAXBUFFER - 1] - p);
				if (sign_char)
					length--;
				if (prefix)
					length -= _strlen((const char *) prefix);

				if (padc == ' ' && !ladjust)
					while (--length >= 0)
						_putchar(' ');

				if (sign_char)
					_putchar(sign_char);

				if (prefix)
					while (*prefix)
						_putchar(*prefix++);

				if (padc == '0')
					while (--length >= 0)
						_putchar('0');

				while (++p != &buffer[MAXBUFFER])
					_putchar(*p);

				if (ladjust)
					while (--length >= 0)
						_putchar(' ');
				break;
			}

		case '\0':
			format--;
			break;

		default:
			_putchar(c);
	
		}
	format++;

}
