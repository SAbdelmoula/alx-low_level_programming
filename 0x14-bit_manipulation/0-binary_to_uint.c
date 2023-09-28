#include "main.h"

/**
 * binary_to_uint - convert the binary function number to unsigned int
 * @b: the containing string of binary number
 * Return: converte the number
 */
unsigned int binary_to_uint(const char *b)
{
	int m;
	unsigned int dec_val = 0;

	if (!b)
		return (0);

	for (m = 0; b[m]; m++)
	{
		if (b[m] < '0' || b[m] > '1')
			return (0);
		dec_val = 2 * dec_val + (b[m] - '0');
	}

	return (dec_val);
}
