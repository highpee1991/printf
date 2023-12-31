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

/* Function prototypes for print functions */
int print_buffer(char buffer[], int *buff_ind);
int print_char(va_list arg_list, char output_buffer[],
                int active_flags, int field_width,
                int precision_spec, int size_spec);
int print_string(va_list arg_list, char output_buffer[],
                int active_flags, int field_width,
                int precision_spec, int size_spec);
int print_percent(va_list args, char buffer[],
                int flags, int width, int precision, int size);
int print_intergers(va_list arg_list, char buffer[],
		int format_flags, int field_width,
		int precision, int length_modifier);
int _binary(va_list arg_list, char buffer[],
		int format_flags, int field_width,
		int precision, int length_modifier);
int _unsigned(va_list arg_list, char output_buffer[],
		int format_flags, int field_width,
		int precision_val, int length_mod);
int _octal(va_list arg_list, char output_buffer[],
	int format_flags, int field_width,
	int precision_val, int length_mod);
int _hexadecimal(va_list arg_list, char output_buffer[],
		int format_flags, int field_width, int precision_val,
		int length_mod);
int _hexade_upper(va_list arg_list,
                char output_buf[], int format_fl,
                int field_wid, int prec_val, int len_mod);
int print_hexade(va_list arg_list, char map_to[],
		char output_buffer[], int format_flags,
		char flag_char, int field_width,
		int precision_val, int length_mod);

#endif /* _MAIN_H */
