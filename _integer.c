#include "main.h"

/**
 * print_intergers - Prints an integer to the output buffer
 * @arg_list: A va_list of arguments
 * @buffer: Buffer array to handle print
 * @format_flags: Calculates active flags for formatting
 * @field_width: Width of the field for formatting
 * @precision: Precision specification for formatting
 * @length_modifier: Size specifier for formatting
 *
 * Return: Number of characters printed
 */
int print_intergers(va_list arg_list, char buffer[],
		int format_flags, int field_width,
		int precision, int length_modifier)
{
	int index = BUFF_SIZE - 2;
	int is_negative = 0;
	long int number = va_arg(arg_list, long int);
	unsigned long int num;

	number = convert_size_number(number, length_modifier);
	if (number == 0)
		buffer[index--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)number;
	if (number < 0)
	{
		num = (unsigned long int)((-1) * number);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[index--] = (num % 10) + '0';
		num /= 10;
	}
	index++;
	return (write_number(is_negative, index, buffer,
				format_flags, field_width,
				precision, length_modifier));
}

