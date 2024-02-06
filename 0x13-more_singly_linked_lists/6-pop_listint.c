#include "lists.h"
/**
 * pop_listint - deletes the head
 * @head: the list
 * Return: value of the data
 */
int pop_listint(listint_t **head)
{
	listint_t *temporary;
	int head_data;

	if (!head || !*head)
		return (0);

	head_data = (*head)->n;
	temporary = *head;
	*head = (*head)->next;
	free(temporary);

	return (head_data);
}
