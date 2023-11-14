#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer
 * @types: List of arguments to be considered
 * @buff: Buffer array to handle print
 * @flag: Calculates active flag
 * @wid: Gets width
 * @prec: For precision specification
 * @area: for area specifier
 * Return: Always return number of unsigned integer printed
 */
int _print_unsigned(va_list types, char buff[],
int flag, int wid, int prec, int area)
{
int i = BUFF_AREA - 2;
unsigned long int num = va_arg(types, unsigned long int);

num = convert_area_unsigned(num, area);

if (num == 0)
buff[i--] = '0';

buff[BUFF_AREA - 1] = '\0';

while (num > 0)
{
buff[i--] = (num % 10) + '0';
num /= 10;
}

i++;

return (write_unsigned(0, i, buff, flag, wid, prec, area));
}

/**
 * _print_oct - Prints an octal character
 * @types: List of arguments to be considered
 * @buff: Buffer array to handle print
 * @flag: Calculates active flag
 * @wid: Gets width
 * @prec: For precision specification
 * @area: for area specifier
 * Return: Always return number of octal character printed
 */
int _print_oct(va_list types, char buff[],
int flag, int wid, int prec, int area)
{

int i = BUFF_AREA - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;

UNUSED(wid);

num = convert_area_unsigned(num, area);

if (num == 0)
buff[i--] = '0';

buff[BUFF_AREA - 1] = '\0';

while (num > 0)
{
buff[i--] = (num % 8) + '0';
num /= 8;
}

if (flag & F_HASH && init_num != 0)
buff[i--] = '0';

i++;

return (write_unsigned(0, i, buff, flag, wid, prec, area));
}

/**
 * _print_hex - Prints a hexadecimal number
 * @types: List of arguments to be considered
 * @buff: Buffer array to handle print
 * @flag: Calculates active flag
 * @wid: Gets width
 * @prec: For precision specification
 * @area: for area specifier
 * Return: Always return number of hexadecimals printed
 */
int _print_hex(va_list types, char buff[],
int flag, int wid, int prec, int area)
{
return (print_hex(types, "0123456789abcdef", buff,
flag, 'x', wid, prec, area));
}

/**
 * print_hexa_upper - Prints a hexadecimal uppercase
 * @types: List of arguments to be considered
 * @buff: Buffer array to handle print
 * @flag: Calculates active flag
 * @wid: Gets width
 * @prec: For precision specification
 * @area: for area specifier
 * Return: Always return number of hexadecimal uppercase printed
 */
int print_hexa_upper(va_list types, char buff[],
int flag, int wid, int prec, int area)
{
return (print_hex(types, "0123456789ABCDEF", buff,
flag, 'X', wid, prec, area));
}

/**
 * print_hex - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buff: buff array to handle print
 * @flag:  Calculates active flag
 * @flag_ch: Calculates active flag
 * @wid: gets width
 * @prec: for precision specification
 * @area: for area specifier
 * @area: for area specification
 * Return: Always return number of lower and upper hexadecimals printed
 */
int print_hex(va_list types, char map_to[], char buff[],
int flag, char flag_ch, int wid, int prec, int area)
{
int i = BUFF_AREA - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;

UNUSED(wid);

num = convert_area_unsigned(num, area);

if (num == 0)
buff[i--] = '0';

buff[BUFF_AREA - 1] = '\0';

while (num > 0)
{
buff[i--] = map_to[num % 16];
num /= 16;
}

if (flag & F_HASH && init_num != 0)
{
buff[i--] = flag_ch;
buff[i--] = '0';
}

i++;

return (write_unsigned(0, i, buff, flag, wid, prec, area));
}
