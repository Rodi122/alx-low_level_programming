#include "lists.h"

/**
 * add_nodeint - adds new node at the start
 * @head: pointer to the list
 * @n: the num
 * Return: address of the first element
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *temp;

	temp = malloc(sizeof(listint_t));
	if (!temp)
		return (NULL);
	temp->n = n;
	if (*head)
	{
		temp->next = *head;
		*head = temp;
	}
	else
	{
		temp->next = NULL;
		*head = temp;
	}
	return (*head);
}
