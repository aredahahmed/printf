#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

include <stdarg.h>

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

void print_int(va_list args);
void print_float(va_list args);
int print_char(va_list args);
int print_str(va_list args);

int (*get_function(const char *format))(va_list);

#endif // VARIADIC_FUNCTIONS_H
