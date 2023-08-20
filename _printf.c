#include "main.h"

/**
 * _printf - a function that printf different types of data
 * @format: is the string, modifiers, and flags to print
 *
 * Return: number of the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list vals;
	int i, len = 0;
	int (*func)(va_list);

	va_start(vals, format);
	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
			len += _putchar(format[i]);

		else
		{

			func = get_f(format[i + 1]);
			if (func != NULL)
			{
				len += func(vals);
				i++;
			}
			else
			{
				len += _putchar(format[i]);
			}
		}
	}

	va_end(vals);
	return (len);
}

/**
 * get_f - a function that printf different types of data
 * @format: is the string, modifiers, and flags to print
 *
 * Return: number of the number of characters printed
 */

int (*get_f(char format))(va_list)
{

	int j;
	specifier types[] = {

		{'s', print_string},
		{'d', print_int},
		{'i', print_int},
		{'c', print_char},
		{'b', print_binary},
		{'o', print_octal},
		{'u', print_unsigned},
		{'x', print_hex},
		{'X', print_HEX},
		{'%', print_percent},
		{'\0', NULL}

	};

	for (j = 0; types[j].c != '\0'; j++)
	{
		if (format == types[j].c)
		{
			return (types[j].f);
		}
	}

	return (NULL);
}
