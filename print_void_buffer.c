#include "main.h"

/**
 * _buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of characters to be printed
 * @buff_ind: Pointer to the buffer index, represents the length.
 *
 * Return: The number of characters printed
 */
int _buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, buffer, *buff_ind);
	}
	*buff_ind = 0;
	return (*buff_ind);
}
