#include "main.h"
/**
 * get_bit - outputs the value of the bit with a given index
 * @n: long unsigned int
 * @index: the index
 * Return: the bit or -1
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index > 53)
	{
		return (-1);
	}
	return ((n >> index) & 1);
}
