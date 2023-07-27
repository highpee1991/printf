#include "main.h"

int flush_buffer(char buffer[], int *buff_ind);
/**
 * _print - Custom print function that handles formatting and writes to stdout
 * @format: The format string containing the text and format specifiers
 * Return: The number of characters printed, or -1 on failure
 */
int _print(const char *format, ...)
{
	if (format == NULL)
		return (-1);
	int _chars = 0;
	va_list _list;
	char buffer[BUFF_SIZE] = {0};
	int _ind = 0;

	va_start(_list, format);

	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[_ind++] = format[i];
			if (_ind == BUFF_SIZE)
				_chars += flush_buffer(buffer, &_ind);
		}
		else
		{
			_chars += flush_buffer(buffer, &_ind);
			int flags = get_flags(format, &i);
			int width = get_width(format, &i, _list);
			int precision = get_precision(format, &i, _list);
			int _size = get_size(format, &i);

			i++;
			int printed = handle_print(format, &i, _list, buffer,
					flags, width, precision, _size);
			if (printed == -1)
				return (-1);
			_chars += printed;
		}
	}
	_chars += flush_buffer(buffer, &_ind);
	va_end(_list);
	return (_chars);
}
