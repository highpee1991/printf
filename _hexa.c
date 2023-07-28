#include "main.h"
/**
 * _hexadecimal - Converts and prints an unsigned number to hexadecimal notation
 * @arg_list: A list of arguments
 * @output_buffer: The buffer array to handle printing
 * @format_flags: FLags that determine the formatting options
 * @field_width: The width of the field for formatting
 * @precision_val: The precision specification for formatting
 * @length_mod: The size specifier for formatting
 *
 * Return: Thw number of characters printed
*/
int _hexadecimal(va_list arg_list, char output_buffer[], int format_flags, int field_width, int precision_val, int length_mod)
{
return (print_hexa(arg_list, "0123456789abcdef", output_buffer, format_flags, 'X', field_width, precision_val, length_mod));
}
