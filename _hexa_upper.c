#include "main.h"
/**
 * _hexadecimal_upper -Prints an unsigned number in upper hexadecimal format
 * @arg_list: A list of arguments containing the unsigned number to be printed
 * @output_buffer: Buffer array to handle the printing
 * @format_flags: Calculates active flags for formatting
 * @field_width: The width of the field for formatting
 * @precision_val: Precision specification for fromatting
 * @lenght_mod: Size specifier for formatting
 *
 * Return: Number of characters printed
*/
int _hexadecimal_upper(va_list arg_list, char output_buffer[], int format_flags, int field_width, int precision_val, int length_mod)
{
return (print_hexa(arg_list, "0123456789ABCDEF", output_buffer, format_flags, 'X', field_width, precision_val, length_mod));
}
