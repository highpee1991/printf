#include "main.h"

/**
 * _char - Prints a character to the output buffer
 * @arg_list: A va_list of arguments containing the character to print
 * @output_buffer: Buffer array to handle print
 * @active_flags: Calculates active flags for formatting
 * @field_width: Width of the field for formatting
 * @precision_spec: Precision specification for formatting
 * @size_spec: Size specifier for formatting
 *
 * Return: Number of characters printed (1) or -1 on failure
 */
int _char(va_list arg_list, char output_buffer[],
		int active_flags, int field_width,
		int precision_spec, int size_spec)
{
	char c = va_arg(arg_list, int);

	return (handle_write_char(c, output_buffer,
		active_flags, field_width, precision_spec, size_spec));
}

