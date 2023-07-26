#include <stdarg.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int print_character(va_list args, bool flag1, bool flag2, bool flag3);
int print_string(va_list args);
int print_percent(void);
int print_integer(va_list args);
int print_invalid(char c);
int (*find_print_function(char specifier))(va_list, bool, bool, bool);

/**
 * _printf - Custom implementation of printf function
 * @format: The format string with optional format specifiers
 * Return: The number of characters printed (excluding the null terminator)
 * Description: This function is a custom implementation of printf, which
 * prints the formatted output to the standard output stream.
 * It supports conversion specifiers: %c (character), %s (string),
 * %%, %d and %i (integer). It also handles optional flags 1, 2, and 3.
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	char buffer[MAX_BUFFER_SIZE];
	int count = 0, index = 0;
	for (const char *p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			bool flag1 = false, flag2 = false, flag3 = false;
			while (*p == '1' || *p == '2' || *p == '3')
			{
				switch (*p)
				{
					case '1': flag1 = true;
						  break;
					case '2': flag2 = true;
						  break;
					case '3': flag3 = true;
						  break;
					default: len = 1;
						 break;
				}
				p++;
			}
			int (*print_func)(va_list, bool, bool, bool) = find_print_function(*p);
			count += (print_func) ? print_func(args, flag1, flag2, flag3) : 0;;
		}
		else
		{
			buffer[index++] = *p;
			count++;
		}
		if (index >= MAX_BUFFER_SIZE - 1)
		{
			write(1, buffer, index);
			index = 0;
		}
	}
	if (index > 0)
		write(1, buffer, index);
	va_end(args);
	return (count);
}

/**
 * _print_char - Print a character
 * @args: The argument list containing the character to be printed
 * @flag1: Flag for optional flag '1'
 * @flag2: Flag for optional flag '2'
 * @flag3: Flag for optional flag '3'
 * Return: The number of characters printed (1 in this case)
 * Description: This function is responsible for printing a single character
 * from the argument list. If any of the optional flags '1', '2',
 * or '3' is set, the behavior can be modified accordingly.
 */
int _print_char(va_list args, bool flag1, bool flag2, bool flag3)
{
	char c = va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

/**
 * _print_string - Print a string
 * @args: The argument list containing the string to be printed
 * @flag1: Flag for optional flag '1'
 * @flag2: Flag for optional flag '2'
 * @flag3: Flag for optional flag '3'
 * Return: The number of characters printed
 * Description: This function prints a string from the argument list. If the
 * string is NULL, it prints "(null)" instead. The behavior can
 * be modified using the optional flags '1', '2', and '3'.
 */
int _print_string(va_list args)
{
	char *str = va_arg(args, char *);
	if (!str) str = "(null)";
	int count = 0;
	for (; *str; str++)
	{
		write(1, str, 1); count++;
	}
	return (count);
}

/**
 * _print_percent - Print a percent sign
 * @args: The argument list (not used in this function)
 * @flag1: Flag for optional flag '1'
 * @flag2: Flag for optional flag '2'
 * @flag3: Flag for optional flag '3'
 * Return: The number of characters printed (always 1 in this case)
 * Description: This function prints a percent sign (%). It does not use the
 * argument list and is not affected by any optional flags.
 */
int _print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

/**
 * _print_integer - Print an integer
 * @args: The argument list containing the integer to be printed
 * @flag1: Flag for optional flag '1'
 * @flag2: Flag for optional flag '2'
 * @flag3: Flag for optional flag '3'
 * Return: The number of characters printed
 * Description: This function prints an integer from the argument list. If
 * the integer is negative, it prints a minus sign. The behavior
 * can be modified using the optional flags '1', '2', and '3'.
 */
int _print_integer(va_list args)
{
	int n = va_arg(args, int), count = 0;
	if (n < 0)
	{
	       	write(1, "-", 1);
		n = -n;
		count++;
	}
	int reversed = 0;
	while (n)
	       	reversed = reversed * 10 + n % 10; n /= 10;
	if (reversed == 0)
		write(1, "0", 1);
	(return 1);
	while (reversed)
	{
		char d = '0' + reversed % 10;
		write(1, &d, 1);
		reversed /= 10; count++;
	}
	return (count);
}

/**
 * _print_invalid - Print an invalid format specifier
 * @args: The argument list containing the invalid format specifier
 * @flag1: Flag for optional flag '1'
 * @flag2: Flag for optional flag '2'
 * @flag3: Flag for optional flag '3'
 * Return: The number of characters printed (1 in this case)
 * Description: This function is called when an invalid format specifier is
 * encountered. It simply prints the invalid character from the
 * argument list. The behavior is not affected by any optional flags.
 */
int _print_invalidchar (char c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * find_print_function - Find the appropriate print function for a specifier
 * @specifier: The format specifier to find the print function for
 * Return: Pointer to the appropriate print function
 * Description: This function takes a format specifier and returns a pointer
 * to the corresponding print function. If an unknown specifier
 * is provided, it returns the print_invalid function by default.
 */
int (*find_print_function(char specifier))(va_list, bool, bool, bool)
{
	switch (specifier)
	{
		case 'c': return (_print_char);
		case 's': return (_print_string);
		case '%': return (_print_percent);
	   	case 'd': case 'i': return (_print_integer);
		default: return (_print_invalid);
	}
}
