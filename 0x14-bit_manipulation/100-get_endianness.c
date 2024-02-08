#include "main.h"
/**
 *get_endianness - checks for endianness
 *Return: 0 for large endian, 1 for small endian
 */
int get_endianness(void)
{
	unsigned int num = 1;
	char *lett = (char *)&num;

	if (*lett)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
