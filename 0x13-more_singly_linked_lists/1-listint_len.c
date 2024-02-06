#include "lists.h"

/**
 * listint_len - counts number of elements
 * @h: the list
 * Return: the number of nodes
 */

size_t listint_len(const listint_t *h)
{
	size_t nodes = 0;

	while (h)
	{
		nodes++;
		h = h->next;
	}
	return (nodes);
}
