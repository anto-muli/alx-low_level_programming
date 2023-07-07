#include <stdio.h>
#include "main.h"

/**
 * main - prints all arguments received by the program
 * @argc: number of arguments received by the program
 * @argv: array of arguments in the program
 * Return: Always 0 when successful
 */
int main(int argc, char *argv[])
{
	int a;

	for (a = 0; a < argc; a++)
	{
		printf("%s\n", argv[a]);
	}
	return (0);
}
