#ifndef MAIN_H
#define MAIN_H

#define UNUSED(x) (void)(x)
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>


/*tools for facilitate job*/
int _putchar(char c);
int _strlen(char *str);
char *convert(unsigned int num, int base);
char *convert_small(unsigned int num, int base);

/*the real work*/
int _printf(const char *format, ...);
int print_string(va_list value);
int print_int(va_list value);
int print_char(va_list value);
int print_binary(va_list value);
int print_octal(va_list value);
int print_unsigned(va_list value);
int print_hex(va_list value);
int print_HEX(va_list value);
int print_percent(va_list value);

int (*get_f(char format))(va_list);

/**
 * struct specifiers - is strcut to handle specifiers
 * @c: is the specifier
 * @f: pointer to function
 */

typedef struct specifiers
{

	char c;
	int (*f)(va_list);

} specifier;

#endif /*MAIN HEADER*/
