#include "main.h"

/**
 * get_bit - return the bit value at the index in a decimal number
 * @n: Number to search
 * @index: the bit of the index
 * Return: the bit of the value
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_value;

	if (index > 63)
		return (-1);

	bit_value = (n >> index) & 1;

	return (bit_value);
}
