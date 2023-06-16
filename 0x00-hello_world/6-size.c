#include <stdio.h>
/**
 * main - entry point
 *
 * Return: Always zero
 */
int main(void)
{
	printf("Size of a char:%ld 1 byte(s)\n", sizeof(char));
	printf("Size of an int:%ld 4 byte(s)\n", sizeof(int));
	printf("Size of a long int:%ld 4 bytes(s)\n", sizeof(long int));
	printf("Size of a long long int:%ld 8 bytes(s)\n", sizeof(long long int));
	printf("Size of a float:%ld 4 bytes(s)\n", sizeof(float));
	return (0);
}
