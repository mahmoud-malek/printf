#ifndef MAIN_H
#define MAIN_H

#define UNUSED(x) (void)(x)
#define BUFFSIZE (1024)
#define FLUSH (-1)
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/*tools for facilitate job*/
int _putchar(int c);
int _strlen(char *str);
char *convert(unsigned long int num, int base);
char *convert_small(unsigned long int num, int base);
int _puts(char *s);

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
int print_STRING(va_list value);
int print_pointer(va_list value);

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

/**
 * struct parameters - is strcut to handle specifiers
 * @usign: sign
 * @plus: plus flag
 * @space: space flag
 * @hashtag: # flag
 * @minus: - flag
 * @zero: 0 flag
 * @width: the width
 * @precision: the precision
 * @h_mod: h modifier
 * @l_mod: l modifier
 */

typedef struct parameters
{

	int usign;

	/*FLAGS*/
	int plus;
	int space;
	int hashtag;
	int minus;
	int zero;
	/*Width & precision*/
	int width;
	int precision;

	/*length of modifiers*/
	int h_mod;
	int l_mod;

} prm;

#endif /*MAIN HEADER*/
