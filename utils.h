#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * printTypeStruct - Map definition of types
 * @type: the type of the variables
 * @printer: the function pointer that handles the print
 */
typedef struct printTypeStruct
{
	char * type;
	void (*printer)(va_list);
}printTypeStruct;

/**
 * print_int - prints int
 * @list: arguments from print_all
 */
void print_int(va_list list)
{
	// handle int
}

/**
 * print_float - prints float
 * @list: arguments from print_all
 */
void print_float(va_list list)
{
	// handle float
}

/**
 * print_char - prints int
 * @list: arguments from print_all
 */
void print_char(va_list list)
{
	int ch = va_arg(list, int);
	_putchar(ch);
}

/**
 * print_str - prints string
 * @list: arguments from print_all
 */
void print_str(va_list list) {
	char *s = va_arg(list, char *);

	if (s == NULL) 
	{
		char *nil_str = "(nil)";
		while (*nil_str)
		{
			_putchar(*nil_str++);
		}
	} 
	else 
	{
		while (*s)
		{
			_putchar(*s++);
		}
	}
}


static printTypeStruct printType[] = 
{
	{ "i", print_int },
	{ "f", print_float },
	{ "c", print_char },
	{ "s", print_str },
	{ NULL, NULL }
}

int (*get_function(const char *format))(va_list)
{
	int i = 0;

	while(printType.type)
	{
		if (printType[i].type[0] == (*format))
		{
			return (printType[i].printer);
		}
		i++;
	}
	return NULL;
}
