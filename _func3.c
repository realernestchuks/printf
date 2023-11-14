#include "main.h"

/**
 * _print_ptr - Prints a pointer
 * @types: List of arguments to be considered
 * @buff: Buffer array to handle print
 * @flag: Calculates active flag
 * @wid: Gets width
 * @prec: For precision specification
 * @area: for area specifier
 * Return: Always return a pointer
 */
int _print_ptr(va_list types, char buff[],
int flag, int wid, int prec, int area)
{
char extra_c = 0, padd = ' ';
int ind = BUFF_AREA - 2, range = 2, padd_start = 1;
unsigned long num_addrs;
char map_to[] = "0123456789abcdef";
void *addrs = va_arg(types, void *);

UNUSED(wid);
UNUSED(area);

if (addrs == NULL)
return (write(1, "(nil)", 5));

buff[BUFF_AREA - 1] = '\0';
UNUSED(prec);

num_addrs = (unsigned long)addrs;

while (num_addrs > 0)
{
buff[ind--] = map_to[num_addrs % 16];
num_addrs /= 16;
range++;
}

if ((flag & F_ZERO) && !(flag & F_MINUS))
padd = '0';
if (flag & F_PLUS)
extra_c = '+', range++;
else if (flag & F_SPACE)
extra_c = ' ', range++;

ind++;

return (_write_ptr(buff, ind, range,
wid, flag, padd, extra_c, padd_start));
}

/**
 * _print_nonprint - Prints ASCII in both hexadecimal and non.
 * @types: List of arguments to be considered
 * @buff: Buffer array to handle print
 * @flag: Calculates active flag
 * @wid: Gets width
 * @prec: For precision specification
 * @area: for area specifier
 * Return: Always return number of hexadecimals and non hexa printed
 */
int _print_nonprint(va_list types, char buff[],
int flag, int wid, int prec, int area)
{
int i = 0, offset = 0;
char *str = va_arg(types, char *);

UNUSED(flag);
UNUSED(wid);
UNUSED(prec);
UNUSED(area);

if (str == NULL)
return (write(1, "(null)", 6));

while (str[i] != '\0')
{
if (to_print(str[i]))
buff[i + offset] = str[i];
else
offset += embed_hexa(str[i], buff, i + offset);

i++;
}

buff[i + offset] = '\0';

return (write(1, buff, i + offset));
}

/**
 * _print_rev - Prints a string in reverse
 * @types: List of arguments to be considered
 * @buff: Buffer array to handle print
 * @flag: Calculates active flag
 * @wid: Gets width
 * @prec: For precision specification
 * @area: for area specifier
 * Return: Always return string in reverse
 */

int _print_rev(va_list types, char buff[],
int flag, int wid, int prec, int area)
{
char *str;
int i, count = 0;

UNUSED(buff);
UNUSED(flag);
UNUSED(wid);
UNUSED(area);

str = va_arg(types, char *);

if (str == NULL)
{
UNUSED(prec);

str = ")Null(";
}
for (i = 0; str[i]; i++)
;

for (i = i - 1; i >= 0; i--)
{
char z = str[i];

write(1, &z, 1);
count++;
}
return (count);
}
/**
 * _print_rot13_strg - Prints a character using the ROT13 cipher
 * @types: List of arguments to be considered
 * @buff: Buffer array to handle print
 * @flag: Calculates active flag
 * @wid: Gets width
 * @prec: For precision specification
 * @area: For area specifier
 * Return: Always returns the number of characters printed
 */
int _print_rot13_strg(va_list types, char buff[],
int flag, int wid, int prec, int area)
{
char x;
char *str;
unsigned int i, j;
int count = 0;
char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

str = va_arg(types, char *);
UNUSED(buff);
UNUSED(flag);
UNUSED(wid);
UNUSED(prec);
UNUSED(area);

if (str == NULL)
str = "(AHYY)";
for (i = 0; str[i]; i++)
{
for (j = 0; in[j]; j++)
{
if (in[j] == str[i])
{
x = out[j];
write(1, &x, 1);
count++;
break;
}
}
if (!in[j])
{
x = str[i];
write(1, &x, 1);
count++;
}
}
return (count);
}
