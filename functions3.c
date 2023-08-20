#include "main.h"

/**
 * print_pointer - function that prints the an addresss
 * @value: contian address to print
 *
 * Return: number of the number of characters printed
 */

int print_pointer(va_list value)
{
	unsigned long int num = va_arg(value, unsigned long int);
	char *address;

	if (!num)
		return (_puts("(nil)"));

	address = convert_small(num, 16);
	*(--address) = 'x';
	*(--address) = '0';
	return (_puts(address));
}
