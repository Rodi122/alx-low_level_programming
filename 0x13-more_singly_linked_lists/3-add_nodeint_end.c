#include "lists.h"

/**
 * add_nodeint_end - adds a node at the end
 * @head: the list
 * @n: the num
 * Return: the new list
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *temp = malloc(sizeof(listint_t));
	listint_t *p = *head;

	if (!temp)
		return (NULL);
	temp->n = n;
	temp->next = NULL;
	if (*head == NULL)
	{
		*head = temp;
		return (*head);
	}
	while (p->next)
	{
		p = p->next;
	}
	p->next = temp;
	return (*head);
}
