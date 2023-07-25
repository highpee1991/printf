#include <stdi.h>
#include <stdarg.h>

/**
 * _print_char - Prints a single character to the standard output
 * @c: The character to be printed
 *
 * Return: Number of characters printed (1 if successful, 0 if error)
 */
static int _print_character(char c)
{
	putchar(c);
	return;
}

/**
 * _print_str - Prints a string to the standard output
 * @str: The string to be printed
 *
 * Return: Number of characters printed (excluding the null terminator)
 */
static int _print_string(char *string)
{
	if (string == NULL)
	{
		string = "(null)";
	}

	int chars_printable = 0;
	while (*string)
	{
		chars_printable += _print_character(*string);
		string++;
	}
	return chars_printable;
}

/**
 * _printf - Custom implementation of printf function
 * @format: The format string with optional format specifiers
 *
 * Return: Number of characters printed (excluding the null terminator)
 */
int _printf(const char *format, ...)
{
	va_list list;
	va_start(list, format);

	int chars_printable = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					chars_printable += _print_character((char))va_arg(list int);
					break;
				case 's':
					chars_printable += _print_string(va_arg(list, char*));
					break;
				case '%':
					chars_printable += _print_character('%');
					break;
				default:
					break;
			}
		}
		else
		{
			chars_printable += _print_character(*format);
		}
		format++;
	}
	va_end(list);
	return chars_printable;
}
