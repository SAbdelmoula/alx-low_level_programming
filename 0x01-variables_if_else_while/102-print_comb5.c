#include<stdio.h>
/**
 * main - Entry point
 * description: print comb of two digits
 * Return: Always 0
 */
int main(void)
{
	int FirstD = 0, SecondD;

	while (FirstD <= 99)
	{
		SecondD = FirstD;
		while (SecondD <= 99)
		{
			if (SecondD != FirstD)
			{
				putchar((FirstD / 10) + 48);
				putchar((FirstD % 10) + 48);
				putchar(' ');
				putchar((SecondD / 10) + 48);
				putchar((SecondD % 10) + 48);

				if (FirstD != 98 || SecondD != 99)
				{
					putchar(',');
					putchar(' ');
				}
			}
			SecondD++;
		}
		FirstD++;
	}
	putchar('\n');
	return (0);
}
