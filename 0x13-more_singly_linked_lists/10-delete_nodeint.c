#include "lists.h"
/**
 * delete_nodeint_at_index - deletes node at a given index
 * @head: the list
 * @index: the index
 * Return: 1 or -1
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temporary = *head;
	listint_t *nod = NULL;
	size_t i = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(temporary);
		return (1);
	}

	while (i < index - 1)
	{
		if (!temporary || !(temporary->next))
			return (-1);

		temporary = temporary->next;
		i++;
	}

	nod = temporary->next;
	temporary->next = nod->next;
	free(nod);

	return (1);
}
