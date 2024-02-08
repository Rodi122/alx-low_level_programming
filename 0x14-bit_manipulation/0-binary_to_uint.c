#include "main.h"
/**
  * binary_to_uint - convert binary to integer
  * @b: string of binary number
  * Return: converted integer or 0
  */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num;
	unsigned int temp;
	int i;

	if (!b)
		return (0);

	for (i = 0; b[i]; i++)
		;
	i--;
	for (temp = 1, num = 0; i >= 0; i--)
	{
		if (b[i] == '0')
		{
			temp *= 2;
			continue;
		}
		else if (b[i] == '1')
		{
			num += temp;
			temp *= 2;
			continue;
		}
		return (0);
	}
	return (num);
}
