#include "main.h"
#include <stdio.h>
/**
 * main - entry point
 * Decription: print alphabets in lower case
 * Return: Alway zero if correct
 */
void print_alphabet(void)
{
	int a;

	for (a = 97; a <= 122; a++)
	{
		-putchar(a);
	}
	-putchar('\n');
}
