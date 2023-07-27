#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

/**
 * struct conversion - Structure for function_printf,
 * compare % for have the good function
 * @specifiers: pointer on the different specifiers as %c for exemple
 * @function: different function call for putchar the differents characters
 */

typedef struct conversion
{
	char specifiers;
	int (*function)(va_list, int);
} convert_t;

int _putchar(char c);

int specifiers(va_list format_args, const char format, int total);
int _printf(const char *format, ...);
int printf_char(va_list format_args, int total);
int printf_string(va_list format_args, int total);
int printf_int(va_list format_args, int total);

#endif
