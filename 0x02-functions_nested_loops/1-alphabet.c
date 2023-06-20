#include <stdio.h>
#include "main.h"
/**
 * main - entry point
 * Decription: print alphabets in lower case
 * Return: Alway zero if correct
 */
int main(void)
{
	char ch;

	ch = 'a';
	while (ch <= 'z')
	{
		putchar(ch);
		ch++;
	}
	putchar('\n');
}
