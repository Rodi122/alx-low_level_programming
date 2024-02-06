#include "lists.h"
/**
 * get_nodeint_at_index - returns the node
 * @head: the list
 * @index: index of the nodee
 * Return: pointer to the required node
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	size_t i = 0;
	listint_t *temporary = head;

	while (temporary && i < index)
	{
		temporary = temporary->next;
		i++;
	}
	if (temporary)
	{
		return (temporary);
	}
	else
	{
		return (NULL);
	}
}
