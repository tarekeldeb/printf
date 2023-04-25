#include "main.h"

/**
<<<<<<< HEAD
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * Return: Precision.
=======
 *get_size - Calculates the size to cast the argument
 *@format: Formatted string in which to print the arguments
 *@i: List of arguments to be printed.
 *Return: Precision.
>>>>>>> 4191bb2c89ae74a4e498330d0fd7188e960fd590
 */

int getSize(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;
	if (size == 0)
	*i = curr_i - 1;
	else
	*i = curr_i;
	return (size);
}
