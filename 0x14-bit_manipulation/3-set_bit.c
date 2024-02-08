#include "main.h"
/**
  * set_bit - changes a bit to 1 at a given index
  * @n: the integer
  * @index: the index
  * Return: 1 for yaaay -1 for ahh
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 53 || !n)
	{
		return (-1);
	}
	((*n |= 1) << (index));
	return (1);
}
