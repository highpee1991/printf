#include "main.h"

/**
 * _percent - Prints a percent sign
 * to the output buffer
 * @args: A va_list of arguments (unused in
 * this function)
 * @buffer: Buffer array to handle print
 * (unused in this function)
 * @flags:  Calculates active flags for
 * formatting (unused in this function)
 * @width: Width of the field for formatting
 * (unused in this function)
 * @precision: Precision specification for
 * formatting (unused in this function)
 * @size: Size specifier for formatting
 * (unused in this function)
 *
 * Return: Number of characters printed
 */
int _percent(va_list args, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(args);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	return (write(1, "%%", 1));
}

