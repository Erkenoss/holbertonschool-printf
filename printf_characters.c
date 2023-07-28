#include "main.h"
#include <stdarg.h>

/**
 * specifiers - print a string
 *
 * @format: formatr give by _printf
 * @total: total characters in the output
 * @format_args: argument in the list
 *
 * Return: no return, void function
 */

int specifiers(va_list format_args, const char format, int total)
{
	convert_t tab_spec[] = {
		{'c', printf_char},
		{'s', printf_string},
		{'i', printf_int},
		{'d', printf_int},
		{0, NULL}
	};
	int check_tab = 0;

	if (format == '%')
	{
		_putchar('%');
		total++;
		return (total);
	}

	while (tab_spec[check_tab].specifiers != 0)
	{
		if (tab_spec[check_tab].specifiers == format)
		{
			total = tab_spec[check_tab].function(format_args, total);
			return (total);
		}
		check_tab++;
	}
	_putchar('%');
	_putchar(format);
	total += 2;
	return (total);
}

/**
 * printf_string - print a string
 *
 * @total: total characters in the output
 * @format_args: argument in the list
 *
 * Return: total
 */

int printf_string(va_list format_args, int total)
{
	char *args = va_arg(format_args, char *);
	int putchar_string = 0;

	if (args == NULL)
		args = "(null)";

	while (args[putchar_string] != '\0')
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
 * @total: total characters in the output
 * @format_args: argument in the list
 *
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
 * printf_int - print an int give in the format
 *
 * @format_args: it's the actual format from specifiers
 * @total: total characters int the output
 *
 * Return: total
 */

int printf_int(va_list format_args, int total)
{
	long int display_int = va_arg(format_args, int); /** No need long int if you do the instrcution later in comment */
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
		display_int = display_int * -1; /** or without this line, check the while after. It's for the case INT_MIN */
		total++;
	}
	while (display_int != 0)
	{
		last_digit = display_int % 10;
		/**
		 * if (last_digit < 0)
		 *	last_digit *= -1;
		*/
		buffer[add_in] = last_digit;
		add_in++;
		display_int = display_int / 10;
	}
	while (add_in > 0)
	{
		_putchar('0' + buffer[add_in - 1]);
		add_in--;
		total++;
	}
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

	if (format == NULL)
		return (-1);

	va_start(format_args, format);

	while (_for[check] != '\0')
	{
		if (_for[check] == '%' && _for[check + 1] == '\0')
			return (-1);
		if (_for[check] == '%')
		{
			total = specifiers(format_args, _for[check + 1], total);
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
