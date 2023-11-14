#include "main.h"

/**
 * write_char - Prints a character
 * @c: Character to be printed.
 * @buff: Buffer array to handle print.
 * @flag: Calculates active flag.
 * @wid: Width.
 * @prec: Precision specifier.
 * @area: Area specifier.
 * Return: Always return number of characters printed.
 */
int write_char(char c, char buff[],
int flag, int wid, int prec, int area)
{ /* char is stored at left and paddind at buff's right */
int i = 0;
char padd = ' ';

UNUSED(prec);
UNUSED(area);

if (flag & F_ZERO)
padd = '0';

buff[i++] = c;
buff[i] = '\0';

if (wid > 1)
{
buff[BUFF_AREA - 1] = '\0';
for (i = 0; i < wid - 1; i++)
buff[BUFF_AREA - i - 2] = padd;

if (flag & F_MINUS)
return (write(1, &buff[0], 1) +
write(1, &buff[BUFF_AREA - i - 1], wid - 1));
else
return (write(1, &buff[BUFF_AREA - i - 1], wid - 1) +
write(1, &buff[0], 1));
}

return (write(1, &buff[0], 1));
}

/**
 * _write_number - Prints a negative number
 * @is_negative: List of arguments
 * @ind: char types.
 * @buff: buff array to handle print
 * @flag:  Calculates active flag
 * @wid: get wid.
 * @prec: prec specifier
 * @area: area specifier
 * Return: Always return negative numbers printed.
 */
int _write_number(int is_negative, int ind, char buff[],
int flag, int wid, int prec, int area)
{
int range = BUFF_AREA - ind - 1;
char padd = ' ', extra_ch = 0;

UNUSED(area);

if ((flag & F_ZERO) && !(flag & F_MINUS))
padd = '0';
if (is_negative)
extra_ch = '-';
else if (flag & F_PLUS)
extra_ch = '+';
else if (flag & F_SPACE)
extra_ch = ' ';

return (write_num(ind, buff, flag, wid, prec,
range, padd, extra_ch));
}

/**
 * write_num - Write a number using a buffer
 * @ind: Index at which the number starts on the buffer.
 * @buff: Buffer.
 * @flag: Flag.
 * @wid: Width.
 * @prec: Precision specifier.
 * @range: Number range.
 * @padd: Padding character.
 * @extra_c: Extra character.
 * Return: Always return number of printed characters.
 */
int write_num(int ind, char buff[],
int flag, int wid, int prec,
int range, char padd, char extra_c)
{
int i, padd_start = 1;

if (prec == 0 && ind == BUFF_AREA - 2 && buff[ind] == '0' && wid == 0)
return (0);
if (prec == 0 && ind == BUFF_AREA - 2 && buff[ind] == '0')
buff[ind] = padd = ' ';
if (prec > 0 && prec < range)
padd = ' ';
while (prec > range)
buff[--ind] = '0', range++;
if (extra_c != 0)
range++;
if (wid > range)
{
for (i = 1; i < wid - range + 1; i++)
buff[i] = padd;
buff[i] = '\0';
if (flag & F_MINUS && padd == ' ')
{
if (extra_c)
buff[--ind] = extra_c;
return (write(1, &buff[ind], range) + write(1, &buff[1], i - 1));
}
else if (!(flag & F_MINUS) && padd == ' ')
{
if (extra_c)
buff[--ind] = extra_c;
return (write(1, &buff[1], i - 1) + write(1, &buff[ind], range));
}
else if (!(flag & F_MINUS) && padd == '0')
{
if (extra_c)
buff[--padd_start] = extra_c;
return (write(1, &buff[padd_start], i - padd_start) +
write(1, &buff[ind], range - (1 - padd_start)));
}
}
if (extra_c)
buff[--ind] = extra_c;
return (write(1, &buff[ind], range));
}

/**
 * write_unsigned - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buff: Array of chars
 * @flag: Flag specifiers
 * @wid: Width specifier
 * @prec: Precision specifier
 * @area: Area specifier
 * Return: Always return number of written characters.
 */
int write_unsigned(int is_negative, int ind,
char buff[],
int flag, int wid, int prec, int area)
{
int range = BUFF_AREA - ind - 1, i = 0;
char padd = ' ';

UNUSED(is_negative);
UNUSED(area);

if (prec == 0 && ind == BUFF_AREA - 2 && buff[ind] == '0')
return (0);

if (prec > 0 && prec < range)
padd = ' ';

while (prec > range)
{
buff[--ind] = '0';
range++;
}

if ((flag & F_ZERO) && !(flag & F_MINUS))
padd = '0';

if (wid > range)
{
for (i = 0; i < wid - range; i++)
buff[i] = padd;

buff[i] = '\0';

if (flag & F_MINUS)
{
return (write(1, &buff[ind], range) + write(1, &buff[0], i));
}
else
{
return (write(1, &buff[0], i) + write(1, &buff[ind], range));
}
}

return (write(1, &buff[ind], range));
}

/**
 * _write_ptr - Write a memory address
 * @buff: Arrays of chars.
 * @ind: Index at which the number starts in the buff.
 * @range: Range of the number.
 * @wid: Width specifier.
 * @flag: Flag specifier.
 * @padd: Char representing the padding.
 * @extra_c: Char representing extra char.
 * @padd_start: Index at which padding should start.
 * Return: Always return number of written characters.
 */
int _write_ptr(char buff[], int ind, int range,
int wid, int flag, char padd, char extra_c, int padd_start)
{
int i;

if (wid > range)
{
for (i = 3; i < wid - range + 3; i++)
buff[i] = padd;
buff[i] = '\0';
if (flag & F_MINUS && padd == ' ')
{
buff[--ind] = 'x';
buff[--ind] = '0';
if (extra_c)
buff[--ind] = extra_c;
return (write(1, &buff[ind], range) + write(1, &buff[3], i - 3));
}
else if (!(flag & F_MINUS) && padd == ' ')
{
buff[--ind] = 'x';
buff[--ind] = '0';
if (extra_c)
buff[--ind] = extra_c;
return (write(1, &buff[3], i - 3) + write(1, &buff[ind], range));
}
else if (!(flag & F_MINUS) && padd == '0')
{
if (extra_c)
buff[--padd_start] = extra_c;
buff[1] = '0';
buff[2] = 'x';
return (write(1, &buff[padd_start], i - padd_start) +
write(1, &buff[ind], range - (1 - padd_start) - 2));
}
}
buff[--ind] = 'x';
buff[--ind] = '0';
if (extra_c)
buff[--ind] = extra_c;
return (write(1, &buff[ind], BUFF_AREA - ind - 1));
}
