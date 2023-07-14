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
	int j = '0';

	while (n <= '7')
	{
		while (m <= '8')
		{
			while (j <= '9')
			{
				if (n < m && m < j)
				{
					putchar(n);
					putchar(m);
					putchar(j);
					if (!(n == '7' && m == '8' && j == '9'))
					{
						putchar(',');
						putchar(' ');
					}
				}
				j++;
			}
			j = '0';
			m++;
		}
		m = '0';
		n++;
	}
	putchar('\n');
	return (0);
}
