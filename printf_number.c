#include "main.h"
#include <stdarg.h>

/**
 * printf_binary - transform an unisgned int in binary
 *
 * @format_args: argument passed from printf_characters
 * @total: argument which possess the characters to print on output
 *
 * Return: total
 */


int printf_binary(va_list format_args, int total)
{
	unsigned int display_int = va_arg(format_args, int);
	int add_in = 0;
	int buffer[20];
	int last_digit;

	if (display_int == 0)
	{
		_putchar('0');
		total++;
	}
	if (display_int < 0)
	{
		_putchar('-');
		display_int = display_int * -1;
		total++;
	}
	while (display_int != 0)
	{
		last_digit = display_int % 2;
		buffer[add_in] = last_digit;
		add_in++;
		display_int = display_int / 2;
	}
	while (add_in > 0)
	{
		_putchar('0' + buffer[add_in - 1]);
		total++;
		add_in--;
	}

	return (total);
}
