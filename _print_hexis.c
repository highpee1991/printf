#include "main.h"
/**
 * print_hexade - Prints a hexadecimal
 * number in lower or upper case
 * @arg_list: A list of arguments containing
 * the unsigned number to be printed
 * @map_to: Array of values to map the number to
 * (either "0123456789abcdef" or "0123456789ABCDEF")
 * @output_buffer: Buffer array to handle print
 * @format_flags: Calculates active flags for formatting
 * @flag_char: The character to represent the 'hash'
 * flag('x' for lower case, 'X' for upper case)
 * @field_width: The width of the field for formatting
 * @precision_val: Precision specification for formatting
 * @length_mod: Size specifier for formatting
 *
 * Return: Number of characters printed
*/
int print_hexade(va_list arg_list, char mah_to[],
		char output_buffer[], int format_flags,
		char flag_char, int field_width,
		int precision_val, int length_mod)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(arg_list, unsigned long int);
	unsigned long int int_num = num;

	UNUSED(field_width);
	num = convert_size_unsgnd(num, length_mod);
	if (num == 0)
		output_buffer[i--] = '0';
	output_buffer[BUFF_SIZE - 2] = '\0';
	while (num > 0)
	{
		output_buffer[i--] = map_to[num % 16];
		num /= 16;
	}
	if (format_flags & F_HASH && int_num != 0)
	{
		output_buffer[i--] = flag_char;
		output_buffer[i--] = '0';
	}
	i++;
	return (write_unsgnd(0, i, output_buffer,
				format_flags, field_width,
				precision_val, length_mod));
}
