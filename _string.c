#include "main.h"

/**
 * _string - Prints a string to the output buffer
 * @arg_list: A va_list of arguments containing the string to print
 * @output_buffer: Buffer array to handle print
 * @active_flags: Calculates active flags for formatting
 * @field_width: Width of the field for formatting
 * @precision_spec: Precision specification for formatting
 * @size_spec: Size specifier for formatting
 * Return: Number of characters printed
 */
int _string(va_list arg_list, char output_buffer[],
		int active_flags, int field_width,
		int precision_spec, int size_spec)
{
	int length = 0, i;
	char *str = va_arg(arg_list, char *);

	UNUSED(output_buffer);
	UNUSED(active_flags);
	UNUSED(field_width);
	UNUSED(precision_spec);
	UNUSED(size_spec);

	if (str == NULL)
	{
		str = "(null)";
		if (precision_spec >= 6)
			str = "";
	}

	while (str[length] != '\0')
		length++;
	if (precision_spec >= 0 && precision_spec < length)
		length = precision_spec;
	if (field_width > length)
	{
		if (active_flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = field_width - length; i > 0; i--)
				write(1, " ", 1);
			return (field_width);
		}
		else
		{
			for (i = field_width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (field_width);
		}
	}
	return (write(1, str, length));
}

