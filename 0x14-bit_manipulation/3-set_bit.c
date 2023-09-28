#include "main.h"

/**
 * set_bit - set the bit at the given index to 1
 * @n: pointer the number to change
 * @index: the index of a bit to set to 1
 * Return: 1 success, -1 failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
