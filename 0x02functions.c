#include "main.h"

/*___________________ PRINT UNSIGNED NUMBER _______________________*/
/**
 * print_octal - Print an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
num = convert_size_unsgnd(num, size);
if (num == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buffer[i--] = (num % 10) + '0';
num /= 10;
}
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/*___________________ PRINT UNSIGNED NUMBER IN OCTAL  ________________*/
/**
 * print_hexadecimal - print an unsigned number in octal
 * @types: list of an arguments
 * @buffer: buffer array to handle print
 * @flags:  calculateing active the flags
 * @width: shows width
 * @precision: precision specification
 * @size: spacify size
 * Return: number of chars printed
 */

int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;
UNUSED(width);
num = convert_size_unsgnd(num, size);
if (num == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buffer[i--] = (num % 8) + '0';
num /= 8;
}
if (flags & F_HASH && init_num != 0)
buffer[i--] = '0';
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/*______________ PRINT UNSIGNED NUMBER IN HEXADECIMAL ____________________*/
/**
 * print_hexadecimal - prints an unsigned number in hexadecimal
 * @types: list of an arguments
 * @buffer: buffer array to handle print
 * @flags:  calculateing active the flags
 * @width: shows width
 * @precision: precision specification
 * @size: spacify size
 * Return: number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789abcdef", buffer,
flags, 'x', width, precision, size));
}
/*___________ PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL ___________*/
/**
 * print_hexa_upper - prints an unsigned number in upper hexadecimal
 * @types: lista of an arguments
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: shows width
 * @precision: precision specification
 * @size: spacify size
 * Return: number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789ABCDEF", buffer,
flags, 'X', width, precision, size));
}
/*______________ PRINT HEXX NUM IN LOWER OR UPPER __________________*/
/**
 * print_hexa - prints a hexadecimal numbers in upper or lower
 * @types: list of an arguments
 * @map_to: array of values to map the number to
 * @buffer: buffer array to handle print
 * @flags:  calculateing the active flags
 * @flag_ch: calculateing the active flags
 * @width: shows width
 * @precision: spacify precision
 * @size: spacify Size
 * Return: number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;
UNUSED(width);
num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[i--] = '0';
		buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
	buffer[i--] = map_to[num % 16];
	num /= 16;
	}
	if (flags & F_HASH && init_num != 0)
	{
	buffer[i--] = flag_ch;
	buffer[i--] = '0';
	}
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
