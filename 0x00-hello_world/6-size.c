#include <stdio.h>
/**
 * main - entry point
 * Return: Always zero
 */
int main(void)
{
	printf("Size of a char: %d byte(s)", sizeof(char));
	printf("Size of an int: %d byte(s)", sizeof(int));
	printf("Size of a long int:%d bytes(s)", sizeof(long int));
	printf("Size of a long long int:%d bytes(s)", sizeof(long long int));
	printf("Size of a float:%d bytes(s)", sizeof(float));
	return (0);
}
