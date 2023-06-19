#include <stdio.h>
/**
 * main - entry point
 * description - print numbers separated by commas and a space
 * Return: Always zero if correct
 */
int main(void)
{
	int a;

	for (a = 48; a <= 57; a++)
	{
		putchar(a);
		if (a == 57)
		{
			continue;
		}
		putchar(',');
		putchar(' ');
	}
	putchar('\n');
	return (0);
}
