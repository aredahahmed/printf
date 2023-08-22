#include <stdio.h>

/**
 * print_int - prints int
 * @args: arguments from print_all
 * @return: length of printed string
 */
int print_int(va_list args)
{
	// handle print int
}

/**
 * print_float - prints float
 * @args: arguments from print_all
 * @return: The length of printed string
 */
int print_float(va_list args)
{
	// handle print float
}

/**
 * print_char - prints char
 * @args: arguments from print_all
 * @return: The length of printed string
 */
int print_char(va_list args)
{
	int ch = va_arg(args, int);
	_putchar(ch);
	return (1);
}

/**
 * print_str - prints string
 * @args: arguments from print_all
 * @return: The length of the printed string
 */
int print_str(va_list args)
{
	int i = 0;
	char *s = va_arg(args, char *);

	if (s == NULL)
	{
		char *nil_str = "(nil)";
		while (*nil_str)
		{
			_putchar(*nil_str++);
		}
		return (0);
	}
	else
	{
		while (*s)
		{
			_putchar(*s++);
			i++;
		}
		return (i);
	}
}

static printTypeStruct printType[] =
{
	{ "i", print_int },
	{ "f", print_float },
	{ "c", print_char },
	{ "s", print_str },
	{ NULL, NULL }
};

int (*get_function(const char *format))(va_list args)
{
	int i = 0;

	while (printType[i].type)
	{
		if (printType[i].type[0] == (*format))
		{
			return (printType[i].printer);
		}

		i++;
	}
	return NULL;
}

