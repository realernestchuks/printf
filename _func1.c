#include "main.h"

/**
 * print_char - Prints a character
 * @types: List of arguments to be considered
 * @buff: Buffer array to handle print
 * @flag: Calculates active flag
 * @wid: Gets width
 * @prec: For precision specification
 * @area: for area specifier
 * Return: Always return number of characters printed
 */
int print_char(va_list types, char buff[],
int flag, int wid, int prec, int area)
{
char c = va_arg(types, int);

return (write_char(c, buff, flag, wid, prec, area));
}

/**
 * print_str - Prints a string
 * @types: List of arguments to be considered
 * @buff: Buffer array to handle print
 * @flag: Calculates active flag
 * @wid: Gets width
 * @prec: For precision specification
 * @area: for area specifier
 * Return: Always return number of characters printed
 */
int print_str(va_list types, char buff[],
int flag, int wid, int prec, int area)
{
int range = 0, i;
char *ptr = va_arg(types, char *);

UNUSED(buff);
UNUSED(flag);
UNUSED(wid);
UNUSED(prec);
UNUSED(area);
if (ptr == NULL)
{
ptr = "(null)";
if (prec >= 6)
ptr = "      ";
}

while (ptr[range] != '\0')
range++;

if (prec >= 0 && prec < range)
range = prec;

if (wid > range)
{
if (flag & F_MINUS)
{
write(1, &ptr[0], range);
for (i = wid - range; i > 0; i--)
write(1, " ", 1);
return (wid);
}
else
{
for (i = wid - range; i > 0; i--)
write(1, " ", 1);
write(1, &ptr[0], range);
return (wid);
}
}
return (write(1, ptr, range));
}

/**
 * print_percent - Prints a percentage
 * @types: List of arguments to be considered
 * @buff: Buffer array to handle print
 * @flag: Calculates active flag
 * @wid: Gets width
 * @prec: For precision specification
 * @area: for area specifier
 * Return: Always return number of percentage printed
 */
int print_percent(va_list types, char buff[],
int flag, int wid, int prec, int area)
{
UNUSED(types);
UNUSED(buff);
UNUSED(flag);
UNUSED(wid);
UNUSED(prec);
UNUSED(area);
return (write(1, "%%", 1));
}

/**
 * print_int - Prints an integer
 * @types: List of arguments to be considered
 * @buff: Buffer array to handle print
 * @flag: Calculates active flag
 * @wid: Gets width
 * @prec: For precision specification
 * @area: for area specifier
 * Return: Always return number of integers printed
 */
int print_int(va_list types, char buff[],
int flag, int wid, int prec, int area)
{
int i = BUFF_AREA - 2;
int negative = 0;
long int n = va_arg(types, long int);
unsigned long int num;

n = convert_area_number(n, area);

if (n == 0)
buff[i--] = '0';

buff[BUFF_AREA - 1] = '\0';
num = (unsigned long int)n;

if (n < 0)
{
num = (unsigned long int)((-1) * n);
negative = 1;
}

while (num > 0)
{
buff[i--] = (num % 10) + '0';
num /= 10;
}
i++;

return (_write_number(negative, i, buff, flag, wid, prec, area));
}

/**
 * print_binary - Prints a binary
 * @types: List of arguments to be considered
 * @buff: Buffer array to handle print
 * @flag: Calculates active flag
 * @wid: Gets width
 * @prec: For precision specification
 * @area: for area specifier
 * Return: Always return number of binary printed
 */
int _print_binary(va_list types, char buff[],
int flag, int wid, int prec, int area)
{
unsigned int n, m, i, sum;
unsigned int a[32];
int read;

UNUSED(buff);
UNUSED(flag);
UNUSED(wid);
UNUSED(prec);
UNUSED(area);

n = va_arg(types, unsigned int);
m = 2147483648; /* (2 ^ 31) */
a[0] = n / m;
for (i = 1; i < 32; i++)
{
m /= 2;
a[i] = (n / m) % 2;
}
for (i = 0, sum = 0, read = 0; i < 32; i++)
{
sum += a[i];
if (sum || i == 31)
{
char z = '0' + a[i];

write(1, &z, 1);
read++;
}
}
return (read);
}
