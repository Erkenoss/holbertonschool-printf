#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * specifiers - print a string
 *
 * @format: formatr give by _printf
 * @total: total characters in the ouput
 * @format_args: argument in the list
 * Return: no return, void function
 *
 */

int specifiers(va_list format_args, const char format, int total)
{
	convert_t tab_spec[] = {
		{'c', printf_char},
		{'s', printf_string},
		{0, NULL}
	};
	int check_tab = 0;

	while (tab_spec[check_tab].specifiers != 0)
	{
		if (tab_spec[check_tab].specifiers == format)
		{
			tab_spec[check_tab].function(format_args, total);
			return (total);
		}
		check_tab++;
	}
	if (format == '%')
	{
		_putchar('%');
		return (total);
	}
	_putchar('%');
	_putchar(format);
	return (total);
}

/**
 * printf_string - print a string
 *
 * @total: total characters in the ouput
 * @format_args: argument in the list
 * Return: total
 *
 */

int printf_string(va_list format_args, int total)
{
	const char *args = va_arg(format_args, char *);
	int putchar_string = 0;

	while (args != NULL && args[putchar_string] != '\0')
	{
		_putchar(args[putchar_string]);
		putchar_string++;
		total++;
	}
	return (total);
}

/**
 * printf_char - print a simple char
 *
 * @total: total characters in the ouput
 * @format_args: argument in the list
 * Return: total
 */

int printf_char(va_list format_args, int total)
{
	char args = va_arg(format_args, int);

	_putchar(args);
	total++;

	return (total);
}

/**
 * _printf - print the character give in imput
 * check exemple in man page
 *
 * @format: it's the pattern use for _print
 * for ex: %c or %s for char and string respectively
 *
 * Return: total
 */

int _printf(const char *format, ...)
{
	int total = 0, check = 0;
	const char *_for = format;
	va_list format_args;

	va_start(format_args, format);
	if (format == NULL)
		return (0);
	while (_for[check] != '\0')
	{
		if (_for[check] == '%')
		{
			specifiers(format_args, _for[check + 1], total);
			check++;
		}
		else
		{
			_putchar(_for[check]);
			total++;
		}
		check++;
	}
	va_end(format_args);
	return (total);
}
