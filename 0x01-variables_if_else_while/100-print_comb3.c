#include <stdio.h>
/**
 * main - entry point
 * combine new numbers
 * Return: Always zero
 */
int main(void)
{
	int a;
	int b;

	for (a = 48; a <= 57; a++)
	{
		for (b = 48; b <= 57; b++)
		{
			if (b > a)
			{
				putchar(a);
				putchar (b);
	if (a != 57 || b != 57)
	{
		putchar (',');
		putchar(' ');
	}
			}
		}
	}
	putchar('\n');
	return (0);
}
