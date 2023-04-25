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
int _printf (const char *format, ...)
{
	int i, printed, printedChars = 0;
	int flags, width, percision, size, bufferINdex = 0;
	va_list args;
	char buffer [BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[bufferIndex++] = format[i];
			if (bufferIndex == BUFF_SIZE)
				printBuffer(buffer, &bufferIndex);
			printedChars++;
		}
		else
		{
			printBuffer(buffer, bufferIndex);
			flags = getFlags(format, &i);
			width = getWidth(format, &i, args);
			precision = get_precision(format, &i, args);
			size = getSize(format, &i);
			++i;
			printed = handlePrint(format, &i, args, buffer, flags, width, precision, size);
			if (printed == 1)
				return (-1);
			printedChars += printed;
		}
	}
	pritnBuffer(buffer, &bufferIndex);
	va_end(args);
	return (pritned_chars);
}
