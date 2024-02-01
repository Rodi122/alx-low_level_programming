#include "lists.h"
/**
 * list_len - outputs number of elements in the list.
 * @h: the list
 * Return: number of elements
 */
size_t list_len(const list_t *h)
{
	size_t i;

	i = 0;
	while (h != NULL)
	{
		h = h->next;
		i++;
	}

	return (i);
}
