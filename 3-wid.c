#include "main.h"

/**
 * _wid - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: List of arguments.
 * Return: Always return width.
 */
int _wid(const char *format, int *i, va_list list)
{
int curr_i;
int wid = 0;

for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
{
if (get_digits(format[curr_i]))
{
wid *= 10;
wid += format[curr_i] - '0';
}
else if (format[curr_i] == '*')
{
curr_i++;
wid = va_arg(list, int);
break;
}
else
break;
}

*i = curr_i - 1;

return (wid);
}
