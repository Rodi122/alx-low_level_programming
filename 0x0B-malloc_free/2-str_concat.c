#include "main.h"
/**
 *_strlen - length
 *@s: array
 *Return: j
 */

int _strlen(char *s)
{
	unsigned int j;

	j = 0;
	while (s[j] != '\0')
	{
		j++;
	}

	return (j);
}

/**
 *str_concat - pointer to array
 *@s1: first array
 *@s2: second array
 *Return: an array
 */

char *str_concat(char *s1, char *s2)
{
	char *t;
	unsigned int i;
	int j;
	int size;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	size = (_strlen(s1) + _strlen(s2) + 1);
	t = (char *) malloc(size * sizeof(char));
	if (t == 0)
	{
		return (NULL);
	}
	for (i = 0; *(s1 + i) != '\0'; i++)
	{
		*(t + i) = *(s1 + i);
	}
	for (j = 0; *(s2 + j) != '\0'; j++)
	{
		*(t + i) = *(s2 + j);
		i++;
	}

	return (t);
}
