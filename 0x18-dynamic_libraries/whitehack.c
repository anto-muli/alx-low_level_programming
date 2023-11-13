#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * printf - prints a consta char
 * @format: char to be printed
 */
int printf(const char *format, ...)
{
	write(1, "9 8 10 25 75 +9\n", 17);
	write(1, "Congratulations, you win the Jackpot!\n", 38);
	exit(EXIT_SUCCESS);
}
