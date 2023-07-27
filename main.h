#ifndef _MAIN_H
#define _MAIN_H

#include <stdarg.h>
#include <stdbool.h>
#include <unistd.h>

#define BUFF_SIZE 1024

/**
 * struct Flags - Represents a flags for _printf function
 * flag: description of the purpose of the flag
 *
 * @flag1: First flag (description of the purpose of the flag)
 * @flag2: Second flag (description of the purpose of the flag)
 * @flag3: Third flag (description of the purpose of the flag)
 */
typedef struct Flags
{
	bool flag1;
	bool flag2;
	bool flag3;
} Flags;

int _printf(const char *format, ...);
int get_flags(const char *format, int *index);
int get_width(const char *format, int *index, va_list args);
int get_precision(const char *format, int *index, va_list args);
int get_size(const char *format, int *index);
int handle_print(const char *format, int *index, va_list args, char buffer[],
		int flags, int width, int precision, int size);

int _buffer(char buffer[], int *buff_ind);
int _char(va_list types, char buffer[], int flags,
		int width, int precision, int size);
int _string(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int _percent(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[], char buffer[], int flags,
		char flag_ch, int width, int precision, int size);

#endif /* _MAIN_H */
