#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 3
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1
/**
 * struct fmt - Struct op
 * @fmt: Format.
 * @fn: The function associated.
 * @fm_t: The function associated.
 */
typedef struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
} fmt_t;
int handle_print(const char *fmt, int *i, va_list list, char buffer[],
	int flags, int width, int precision, int size);

int _printf(const char *format, ...);
void printBuffer(char buffer[], int *bufferIndex);
int printChar(va_list types, char buffer[], int flags,
	int width, int precision, int size);
int printString(va_list types, char buffer[], int flags,
	int width, int precision, int size);
int printPercent(va_list types, char buffer[], int flags,
	int width, int precision, int size);
int printInt(va_list types, char buffer[], int flags,
	int width, int precision, int size);
int printBinary(va_list types, char buffer[], int flags,
	int width, int precision, int size);
int printUnsigned(va_list types, char buffer[], int flags,
	int width, int precision, int size);
int printOctal(va_list types, char buffer[], int flags,
	int width, int precision, int size);
int printHexadecimal(va_list types, char buffer[], int flags,
	int width, int precision, int size);
int printHexaUpper(va_list types, char buffer[], int flags,
	int width, int precision, int size);
int printHexa(va_list types, char map_to[], char buffer[], int flags,
	char flag_ch, int width, int precision, int size);
int printPointer(va_list types, char buffer[], int flags,
	int width, int precision, int size);
int printNonPrintable(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printReverse(va_list types, char buffer[], int flags,
	int width, int precision, int size);
int printRot13string(va_list types, char buffer[], int flags,
	int width, int precision, int size);
int getSize(const char *format, int *i);
int getPrecision(const char *format, int *i, va_list list);
int handle_write_char(char c, char buffer[], int flags,
	int width, int precision, int size);
int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char buffer[], int flags,
	int width, int prec, int length, char padd, char extra_c);
int write_unsgnd(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);
int is_printable(char c);
int append_hexa_code(char ascii_code, char buffer[], int i);
int is_digit(char c);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);
int getWidth(const char *format, int *i, va_list list);
int getFlags(const char *format, int *i);

#endif
