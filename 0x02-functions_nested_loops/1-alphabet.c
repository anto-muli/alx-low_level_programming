#include "main.h"
#include <stdio.h>
/**
 *Print alphabet in lowercases followed by a new line
 */
void print_alphabet(void)
{
	char ch;

	ch = 'a';
	while (ch <= 'z');
	{
		putchar(ch);
		ch++;
	}
	putchar('\n');
}
