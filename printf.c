#include "main.h"
/**
 * printBuffer - Prints to the buffer
 * @buffer: Array of chars
 * @bufferIndex: Index at which to add the next char
 */
void printBuffer(char buffer[], int *bufferIndex)
{
	if (*bufferIndex > 0)
		write(1, &buffer[0], *bufferIndex);
	*bufferIndex = 0;
}
/**
 * _printf - print function
 * @format: format
 * Return: Printed chars
 */
int _printf(const char *format, ...)
{
	int i, printed, printedChars = 0;
	int flags, width, percision, size, bufferINdex = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[bufferINdex++] = format[i];
			if (bufferINdex == BUFF_SIZE)
				printBuffer(buffer, &bufferINdex);
			printedChars++;
		}
		else
		{
			printBuffer(buffer, &bufferINdex);
			flags = getFlags(format, &i);
			width = getWidth(format, &i, args);
			percision = getPrecision(format, &i, args);
			size = getSize(format, &i);
			++i;
			printed = handle_print(format, &i, args, buffer,
				flags, width, percision, size);
			if (printed == 1)
				return (-1);
			printedChars += printed;
		}
	}
	printBuffer(buffer, &bufferINdex);
	va_end(args);
	return (printedChars);
}
