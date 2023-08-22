#include "main.h"

/**
 * _printf - a function to print formatted strings
 * @format: The accepted formats are c, s, i, d
 * @return: The size of the string
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, len = 0;

	if (!format || format == NULL)
	{
		return (-1);
	}
	va_start(args, format);
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			_putchar(format[i]);
			i++;
			len++;
		}
		
		if (format[i] == '\0')
		{
			return (len);
		}
	}
}








