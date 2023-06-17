#include <stdio.h>
/**
 * main - entry point
 * description - print single numbers of base 10
 * Return: Always zero if successful
 */
int main(void)
{
	int n;

	for (n = 0; n <= 9; n++)
	{
		putchar(n + 48);
	}
	putchar('\n');
	return (0);
}
