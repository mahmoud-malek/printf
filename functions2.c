#include "main.h"

/**
 * print_unsigned - function that prints unsigned integer
 * @value: contian number to print
 *
 * Return: number of the number of characters printed
 */

int print_unsigned(va_list value)
{
	unsigned int number = va_arg(value, unsigned int);
	int i = 19, cnt = 0;
	char tmp[20] = {0};

	if (number == 0)
	{
		tmp[i] = '0';
		cnt++;
	}
	else
	{
		while (number > 0)
		{
			tmp[i] = (number % 10) + '0';
			number /= 10;
			i--;
			cnt++;
		}
	}

	i = 0;
	while (tmp[i] == 0)
		i++;

	for (; tmp[i] != '\0'; i++)
		if (tmp[i] >= '0' && tmp[i] <= '9')
			_putchar(tmp[i]);

	return (cnt);
}

/**
 * print_hex - function that prints hex of a number
 * @value: contian number to print
 *
 * Return: number of the number of characters printed
 */

int print_hex(va_list value)
{
	long int number = va_arg(value, unsigned int);
	int i;
	char *res = convert_small(number, 16);

	for (i = 0; i < _strlen(res); i++)
	{
		_putchar(res[i]);
	}

	return (i);
}

/**
 * print_HEX - function that prints HEX of a number
 * @value: contian number to print
 *
 * Return: number of the number of characters printed
 */
int print_HEX(va_list value)
{

	long int number = va_arg(value, unsigned int);
	int i;
	char *res = convert(number, 16);

	for (i = 0; i < _strlen(res); i++)
	{
		_putchar(res[i]);
	}

	return (i);
}

/**
 * print_percent - function that prints HEX of a number
 * @value: contian number to print
 *
 * Return: number of the number of characters printed
 */

int print_percent(va_list value)
{
	UNUSED(value);

	return (_putchar('%'));
}

/**
 * print_STRING - function that prints a non-printable string
 * @value: string to print
 *
 * Return: number of the number of characters printed
 */

int print_STRING(va_list value)
{
	char *str = va_arg(value, char *);
	int cnt = 0;
	char *hex;

	if (!str)
		str = "(null)";

	while (*str)
	{
		if ((*str > 0 && *str < 32) || *str == 127)
		{
			hex = convert(*str, 16);
			cnt += _putchar('\\');
			cnt += _putchar('x');

			if (!hex[1])
				cnt += _putchar('0');
			cnt += _puts(hex);
		}
		else
			cnt += _putchar(*str);
	}

	return (cnt);
}
