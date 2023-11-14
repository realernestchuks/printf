#include "main.h"

/**
 * _area - Calculates the area to cast the argument
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * Return: Always return area.
 */
int _area(const char *format, int *i)
{
int curr_i = *i + 1;
int area = 0;

if (format[curr_i] == 'l')
area = S_LONG;
else if (format[curr_i] == 'h')
area = S_SHORT;

if (area == 0)
*i = curr_i - 1;
else
*i = curr_i;

return (area);
}
