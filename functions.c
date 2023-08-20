#include "main.h"

/*****************************Printing number functions***********************/

/**
 * print_int - function that prints an integer
 * @value: contian number to print
 *
 * Return: number of the number of characters printed
 */

int print_int(va_list value)
{
	long int number = va_arg(value, int);
	int i = 19, cnt = 0;
	char tmp[20] = {0};

	if (number < 0)
	{
		_putchar('-');
		number *= -1;
		cnt++;
	}

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
 * print_binary - prints a binary number
 * @value: character to print
 *
 * Return: number of the number of characters printed
 */

int print_binary(va_list value)
{
	long int number = va_arg(value, unsigned int);
	int i;
	char *res = convert(number, 2);

	for (i = 0; i < _strlen(res); i++)
	{
		_putchar(res[i]);
	}

	return (i);
}

/**
 * print_octal - prints number in octal
 * @value: character to print
 *
 * Return: number of the number of characters printed
 */

int print_octal(va_list value)
{
	long int number = va_arg(value, unsigned int);
	int i;
	char *res = convert(number, 8);

	for (i = 0; i < _strlen(res); i++)
	{
		_putchar(res[i]);
	}

	return (i);
}

/***********************Printing string & char functions******************/

/**
 * print_string - function that prints a string
 * @value: string to print
 *
 * Return: number of the number of characters printed
 */

int print_string(va_list value)
{
	char *str = va_arg(value, char *);
	int i, chars = 0;

	if (str == NULL)
		str = "(null)";

	for (i = 0; i < _strlen(str); i++)
	{
		_putchar(str[i]);
		chars++;
	}

	return (chars);
}

/**
 * print_char - function that prints a char
 * @value: character to print
 *
 * Return: number of the number of characters printed
 */

int print_char(va_list value)
{
	char c = va_arg(value, int);

	return (_putchar(c));
}
