#include "main.h"
/**
 * _hexade_upper -Prints an unsigned
 * @arg_list: A list of arguments containing
 * the unsigned number to be printed
 * @output_buf: Buffer array to handle the printing
 * @format_fl: Calculates active flags for formatting
 * @field_wid The width of the field for formatting
 * @prec_val: Precision specification for fromatting
 * @len_mod: Size specifier for formatting
 * @field_wid: the width of the field
 *
 * Return: Number of characters printed
*/
int _hexade_upper(va_list arg_list,
		char output_buf[], int format_fl,
		int field_wid, int prec_val, int len_mod)
{
	return (print_hexa(arg_list, "0123456789ABCDEF",
				output_buf, format_fl, 'X',
				field_wid, prec_val, len_mod));
}
