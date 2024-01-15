#include "main.h"
/**
 * argstostr - args to be printed
 * @ac: width
 * @av: height
 * Return: the args one line at a time
 */

char *argstostr(int ac, char **av)
{
	char *str;
	int num = 0;
	int x = 0;
	int y = 0;
	int z = 0;

	if (ac == 0 || av == NULL)
		return (NULL);
	while (x < ac)
	{
		y = 0;
		while (av[x][y] != '\0')
		{
			num++;
			y++;
		}
		x++;
	}
	num = num + ac + 1;
	str = malloc(sizeof(char) * num);
	if (str == NULL)
	{
		return (NULL);
	}
	for (x = 0; x < ac; x++)
	{
		for (y = 0; av[x][y] != '\0'; y++)
		{
			str[z] = av[x][y];
			z++;
		}
		str[z] = '\n';
		z++;
	}
	return (str);
}
