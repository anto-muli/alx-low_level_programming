#include <stdio.h>
/**
 * main - entry point
 * description - print alphabetical numbers in reverse
 * Return: Always zero
 */
int main(void)
{
	int n = 122;

	while (n >= 97)
	{
		putchar(n);
		n--;
	}
	putchar('\n');
	return (0);
}
