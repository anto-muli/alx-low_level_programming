#include <stdio.h>
#include "main.h"

/**
 * main - prints the name of the program followed by a new line
 * @argc: number of arguments in the program
 * @argv: array of arguments
 * Return: Always 0 when successful
 */
int main(int argc __attribute__((unused)), char *argv[])
{
		printf("%s\n", *argv);

			return (0);
}
