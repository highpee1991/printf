#include "main.h"
/**
 * _binary - Prints an unsigned number in binary format
 * @arg_list: A va_list of arguments
 * @buffer: Buffer array to handle print
 * @format_flags: Calculate active flags for formatting
 * @field_width: Width of the field for formatting
 * @precision: Precision specification for formatting
 * @length_modifier: Size specifier for formatting
 *
 * Return: Number of characters printed
*/
int _binary(va_list arg_list, char buffer[], int format_flags, int field_width, int precision, int length_modifier)
{
unsigned int num, mask, i, sum;
unsigned int binary_digits[32];
int count;
UNUSED(buffer);
UNUSED(format_flags);
UNUSED(field_width);
UNUSED(precision);
UNUSED(precision);
UNUSED(length_modifier);
num = va_arg(arg_list, unsigned int);
mask = 214783648;/* (2 ^ 31) */
binary_digits[0] = num / mask;
for (i = 1; i < 32; i++)
{
sum += binary_digits[i];
if (sum || i == 31)
{
char digit = '0' + binary_digits[i];
write(1, &digit, 1);
count++;
}
}
return (count);
}
