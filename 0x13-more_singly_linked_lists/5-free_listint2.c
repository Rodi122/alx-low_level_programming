#include "lists.h"
/**
 * free_listint2 - frese the list
 * @head: list to be freed
 * Return: none
 */
void free_listint2(listint_t **head)
{
	listint_t *temporary;

	if (head == NULL)
		return;

	while (*head)
	{
		temporary = (*head)->next;
		free(*head);
		*head = temporary;
	}

	*head = NULL;
}
