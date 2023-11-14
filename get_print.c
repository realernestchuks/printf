#include "main.h"

/**
 * get_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: Index.
 * @buff: Buffer array to handle print.
 * @flag: Calculates active flag.
 * @wid: Width.
 * @prec: Precision specification.
 * @area: Area specifier.
 * Return: Always return 1 or 2.
 */
int get_print(const char *fmt, int *ind, va_list list, char buff[],
int flag, int wid, int prec, int area)
{
int i, unknow_len = 0, printed_chars = -1;
fmt_t fmt_types[] = {
{'c', print_char}, {'s', print_str}, {'%', print_percent},
{'i', print_int}, {'d', print_int}, {'b', _print_binary},
{'u', _print_unsigned}, {'o', _print_oct}, {'x', _print_hex},
{'X', print_hexa_upper}, {'p', _print_ptr}, {'S', _print_nonprint},
{'r', _print_rev}, {'R', _print_rot13_strg}, {'\0', NULL}
};
for (i = 0; fmt_types[i].fmt != '\0'; i++)
if (fmt[*ind] == fmt_types[i].fmt)
return (fmt_types[i].fn(list, buff, flag, wid, prec, area));

if (fmt_types[i].fmt == '\0')
{
if (fmt[*ind] == '\0')
return (-1);
unknow_len += write(1, "%%", 1);
if (fmt[*ind - 1] == ' ')
unknow_len += write(1, " ", 1);
else if (wid)
{
--(*ind);
while (fmt[*ind] != ' ' && fmt[*ind] != '%')
--(*ind);
if (fmt[*ind] == ' ')
--(*ind);
return (1);
}
unknow_len += write(1, &fmt[*ind], 1);
return (unknow_len);
}
return (printed_chars);
}
