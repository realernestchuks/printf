#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_AREA 1024

#define S_LONG 2
#define S_SHORT 1

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/**
 * struct fmt - Struct operation.
 * @fmt: The format specifier character.
 * @fn: The function associated with the format specifier.
 */
struct fmt
{
char fmt;
int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct operation
 * @fmt: The format specifier character.
 * @fm_t: The function associated
 */

typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int print_percent(va_list types, char buff[],
int flag, int wid, int prec, int area);
int print_str(va_list types, char buff[],
int flag, int wid, int prec, int area);
int print_char(va_list types, char buff[],
int flag, int wid, int prec, int area);

int get_print(const char *fmt, int *i,
va_list list, char buff[], int flag, int wid, int prec, int area);

int _print_oct(va_list types, char buff[],
int flag, int wid, int prec, int area);
int _print_unsigned(va_list types, char buff[],
int flag, int wid, int prec, int area);
int print_int(va_list types, char buff[],
int flag, int wid, int prec, int area);
int print_hexa_upper(va_list types, char buff[],
int flag, int wid, int prec, int area);
int _print_hex(va_list types, char buff[],
int flag, int wid, int prec, int area);
int _print_ptr(va_list types, char buff[],
int flag, int wid, int prec, int area);
int _print_binary(va_list types, char buff[],
int flag, int wid, int prec, int area);
int print_hex(va_list types, char map_to[],
char buff[], int flag, char flag_ch, int wid, int prec, int area);
int _print_nonprint(va_list types, char buff[],
int flag, int wid, int prec, int area);

int _flag(const char *format, int *i);
int _wid(const char *format, int *i, va_list list);
int _prec(const char *format, int *i, va_list list);
int _area(const char *format, int *i);

int write_char(char c, char buff[],
int flag, int wid, int prec, int area);
int _write_number(int is_positive, int ind, char buff[],
int flag, int wid, int prec, int area);
int write_num(int ind, char bff[], int flag, int wid, int prec,
int range, char padd, char extra_c);
int _write_ptr(char buff[], int ind, int range,
int wid, int flag, char padd, char extra_c, int padd_start);

int _print_rev(va_list types, char buff[],
int flag, int wid, int prec, int area);

long int convert_area_number(long int num, int area);
long int convert_area_unsigned(unsigned long int num, int area);

int _print_rot13_strg(va_list types, char buff[],
int flag, int wid, int prec, int area);

int write_unsigned(int is_negative, int ind,
char buff[],
int flag, int wid, int prec, int area);

int to_print(char);
int embed_hexa(char, char[], int);
int get_digits(char);

#endif
