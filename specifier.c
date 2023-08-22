#include "main.h"

/**
 * get_specifier - finds func format.
 * @s: format str.
 * Return: printed bytes count.
 */
int (*get_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t specifires[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifiers)
	{
		if (*s == specifiers[i].specifier[0])
			return (specifiers[i].f);
		i++
	}
	return (NULL);
}

/**
 * get_print_func - find func format.
 * @s: format str.
 * @ap: arg ptr.
 * @params: ..
 *
 * Return: printed bytes count.
 */
int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(ap, params));
	return (0);
}

/**
 * get_flag - find flag func
 * @s: format str.
 * @params: parameters struct.
 *
 * Return: if input is a valid flag.
 */
int get_flag(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '#':
			i = params->hashtag_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - find mod func.
 * @s: format str.
 * @params: parameters struct.
 * Return: if input is a valid flag.
 */
int get_modifier(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = params->h_modifier = 1;
			break;
		case 'l':
			i = params->l_modifier = 1;
			break;
	}
	return (i);
}

/**
 * get_width - find width.
 * @s: format str.
 * @params: parameters struct.
 * @ap: arg ptr.
 * Return: new ptr.
 */
char *get_width(char *s, params_t *params, va_list ap)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return (s);
}