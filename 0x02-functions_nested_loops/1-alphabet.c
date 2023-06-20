#include <stdio.h>
#include "main.h"
/**
 * main - entry point
 * Decription: print alphabets in lower case
 * Return: Alway zero if correct
 */
int main(void)
{
	int a;

	for (a = 97; a <= 122; a++)
	{
		putchar(a);
	}
	putchar('\n');
}
