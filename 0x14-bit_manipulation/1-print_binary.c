#include "main.h"
/**
 * print_binary - converts decimal to binary
 * @n: the number or decimal to be converted
 * Return: none
 */
void print_binary(unsigned long int n)
{
	if (n > 1)
	{
		print_binary(n >> 1);
	}
	if (n & 1)
	{
		_putchar('1');
	}
	else
	{
		_putchar('0');
	}
}
