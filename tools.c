#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1 or 0 otherwise
 */

int _putchar(int c)
{
	static int i;
	static char buffer[BUFFSIZE];

	if (c == FLUSH || i >= BUFFSIZE)
	{
		write(1, buffer, i);
		i = 0;
	}
	if (c != FLUSH)
		buffer[i++] = c;

	return (1);
}

/**
 * _puts - prints string to stdout
 * @s: string to print
 *
 * Return: length
 */

int _puts(char *s)
{
	char *p = s;

	while (*s)
		_putchar(*s++);

	return (s - p);
}

/**
 * _strlen - function returns the length of string
 * @str: is the string
 *
 * Return: length of the string
 */

int _strlen(char *str)
{
	int i = 0;

	if (!str)
		return (0);

	while (str[i] != '\0')
	{
		i++;
	}

	return (i++);
}

/**
 * convert - function converts decimal to any base
 * @num: number to convert
 * @base: the base to convert to
 *
 * Return: result in a string
 */

char *convert(unsigned long int num, int base)
{
	const char rep[] = "0123456789ABCDEF"; /*represntation*/
	static char buffer[50];
	char *result;

	result = &buffer[49];
	*result = '\0';

	if (num == 0)
	{
		*--result = '0';
		return (result);
	}

	do {
		*--result = rep[num % base]; /*getting the corrsponding value*/
		num /= base;
	} while (num != 0);

	return (result);
}

/**
 * convert_small - function converts decimal to any base
 * @num: number to convert
 * @base: the base to convert to
 *
 * Return: result in a string
 */
char *convert_small(unsigned long int num, int base)
{
	const char rep[] = "0123456789abcdef"; /*represntation*/
	static char buffer[50];
	char *result;

	result = &buffer[49];
	*result = '\0';

	do {
		*--result = rep[num % base]; /*getting the corrsponding value*/
		num /= base;
	} while (num != 0);

	return (result);
}
