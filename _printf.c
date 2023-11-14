#include "main.h"

void print_buff(char buff[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: Format string.
 * Return: Always return number of characters printed.
 */
int _printf(const char *format, ...)
{
int i, printed = 0, printed_chars = 0;
int flag, wid, prec, area, buff_ind = 0;
va_list list;
char buff[BUFF_AREA];

if (format == NULL)
return (-1);

va_start(list, format);

for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
buff[buff_ind++] = format[i];
if (buff_ind == BUFF_AREA)
print_buff(buff, &buff_ind);
printed_chars++;
}
else
{
print_buff(buff, &buff_ind);
flag = _flag(format, &i);
wid = _wid(format, &i, list);
prec = _prec(format, &i, list);
area = _area(format, &i);
++i;
printed = get_print(format, &i, list, buff,
flag, wid, prec, area);
if (printed == -1)
return (-1);
printed_chars += printed;
}
}

print_buff(buff, &buff_ind);

va_end(list);

return (printed_chars);
}

/**
 * print_buff - Prints the contents of the buffer if it exists
 * @buff: Array of characters.
 * @buff_ind: Index at which to add the next character, represents the length.
 */
void print_buff(char buff[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &buff[0], *buff_ind);

*buff_ind = 0;
}
