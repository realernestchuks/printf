#include "main.h"

/**
 * to_print - Evaluates if a character is printable
 * @c: Character to be evaluated.
 * Return: Always return 1 if c is printable, 0 otherwise.
 */
int to_print(char c)
{
if (c >= 32 && c < 127)
return (1);

return (0);
}

/**
 * embed_hexa - Append ASCII in hexadecimal code to buff
 * @buff: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASCII code.
 * Return: Always return 3.
 */
int embed_hexa(char ascii_code, char buff[], int i)
{
char map_to[] = "0123456789ABCDEF";
if (ascii_code < 0)
ascii_code *= -1;

buff[i++] = '\\';
buff[i++] = 'x';

buff[i++] = map_to[ascii_code / 16];
buff[i] = map_to[ascii_code % 16];

return (3);
}

/**
 * get_digits - Verifies if a character is a digit
 * @c: Character to be evaluated.
 * Return: Always return 1 if c is a digit, 0 otherwise.
 */
int get_digits(char c)
{
if (c >= '0' && c <= '9')
return (1);

return (0);
}

/**
 * convert_area_number - Casts a number to the specified area
 * @num: Number to be casted.
 * @area: Number indicating the type to be casted.
 * Return: Always return casted value of num.
 */
long int convert_area_number(long int num, int area)
{
if (area == S_LONG)
return (num);
else if (area == S_SHORT)
return ((short)num);

return ((int)num);
}

/**
 * convert_area_unsigned - Casts a number to the specified area
 * @num: Number to be casted.
 * @area: Number indicating the type to be casted.
 * Return: Always return casted value of num.
 */
long int convert_area_unsigned(unsigned long int num, int area)
{
if (area == S_LONG)
return (num);
else if (area == S_SHORT)
return ((unsigned short)num);

return ((unsigned int)num);
}
