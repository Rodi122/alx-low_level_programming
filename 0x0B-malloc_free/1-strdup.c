#include <stdlib.h>
#include "main.h"

/**
 * _strdup - returns the duplicate
 * @str: the character to be duplicated
 * Return: the duplicated memory
 */

char *_strdup(char *str)
{
	char *temp;
	int size = 0;
	int i;

	if (str == NULL)
	{
		return (NULL);
	}
	while (str[size] != '\0')
	{
		size++;
	}
	temp = malloc(size + 1);
	if (temp == 0)
	{
		return (NULL);
	}
	for (i = 0; i < size + 1; i++)
	{
		temp[i] = str[i];
	}
	return (temp);
}

