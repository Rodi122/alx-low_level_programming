#include "lists.h"
/**
 * insert_nodeint_at_index - adds a node at a given index
 * @head: the list
 * @idx: the index
 * @n: the data
 * Return: address of list
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *nod;
	listint_t *temporary = *head;
	size_t i = 0;

	nod = malloc(sizeof(listint_t));
	if (!nod)
		return (NULL);

	nod->n = n;
	nod->next = NULL;

	if (!*head && !idx)
	{
		*head = nod;
		return (nod);
	}

	else if (!*head && idx)
		return (NULL);

	else if (!idx)
	{
		nod->next = temporary;
		*head = nod;
		return (nod);
	}

	while (i < (idx - 1))
	{
		temporary = temporary->next;
		i++;
	}
	nod->next = temporary->next;
	temporary->next = nod;

	return (nod);
}
