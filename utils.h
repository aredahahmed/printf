#ifndef UTILS_FUNCTIONS_H
#define UTILS_FUNCTIONS_H

#include <stdarg.h>

/**
 * printTypeStruct - Map definition of types
 * @type: the type of the variables
 * @printer: the function pointer that handles the print
 */
typedef struct printTypeStruct
{
	char * type;
	int (*printer)(va_list);
}printTypeStruct;

int print_int(va_list args);
int print_float(va_list args);
int print_char(va_list args);
int print_str(va_list args);

int (*get_function(const char *format))(va_list);

#endif /* UTILS_FUNCTIONS_H*/
