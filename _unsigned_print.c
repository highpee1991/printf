#include "main.h"
/**
 * _octal - Prints an unsigned number in octal notation
 * @arg_list: List of arguments
 * @output_buffer: Buffer array to handle print
 * @format_flags: Calculates active flags for formatting
 * @field_width: Width of the field for formatting
 * @precision_val: Precision specification for formatting
 * @length_mod: Size specifier for formatting
 *
 * Return: Numberof characters printed
*/
int _octal(va_list arg_list, char output_buffer[],
		int format_flags, int field_width,
		int precision_val, int length_mod)
{
	int buffer_index = BUFF_SIZE - 2;
	unsigned long int num = va_arg(arg_list, unsigned long int);
	unsigned long int int_num = num;

	UNUSED(field_width);
	num = convert_size_unsgnd(num, length_mod);

	if (num == 0)
		output_buffer[buffer_index--] = '0';
	output_buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
		output_buffer[buffer_index--] = (num % 8) + '0';
	num /= 8;

	if (format_flags & F_HASH && int_nmu != 0)
			output_buffer[buffer_index--] = '0';
	buffer_index++;
	return (write_ungnd(0, buffer_index, output_buffer,
			       format_flags, field_width,
			       precision_val, length_mod));
}
