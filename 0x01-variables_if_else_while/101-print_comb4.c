#include <stdio.h>
/**
 * main - Entry point
 * description: 'print comb of two digits'
 * Return: Always 0
 */
int main(void)
{
	int n = '0';
	int m = '0';

	for (n = '0'; n <= '9'; n++)
	{
		for (m = '0'; m <= '9'; m++)
		{
			if (!((n == m) || (m > n)))
			{
				putchar(m);
				putchar(n);
				if (!(n == '9' && m == '8'))
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
