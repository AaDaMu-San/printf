#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.H>
#include <limits.h>
#include <stdarg.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct parameters - ..
 * @unsign: flag of unsigned val.
 * @plus_flag: on if flag is present.
 * @space_flag: on if flag is present.
 * @hashtag_flag: on if flag is present.
 * @zero_flag: on if flag is present.
 * @minus_flag: on if flag is present.
 *
 * @width: field specified width.
 * @precision: field specified precision.
 *
 * @h_modifier: on if field is present.
 * @l_modifier: on if field is present.
 */
typedef struct parameters
{
	unsigned int unsign		: 1;
	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} params_t;

/**
 * struct specifier - ..
 * @specifier: format token.
 * @f: associated func.
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/* __put.c file */
int _puts(char *str);
int _putchar(int c);

/* print_functions.c file */
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_S(va_list ap, param_t *params);

/* number.c mod */
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

/* specifier.c file */
int (*get_specifer(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);

/* convert_number.c file */
int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);

/* simple_pointers.c file */
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);

/* print_number.c file */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

/* params.c file */
void init_params(params_t *params, va_list ap);

/* string_fields.c file */
char *get_precision(char *p, params_t *params, va_list ap);

/* _printf.c file */
int _printf(const char *format. ...);

#endif
