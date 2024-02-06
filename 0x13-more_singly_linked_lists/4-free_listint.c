#include "lists.h"

/**
 * free_listint - frees a list
 * @head: list to be freed
 * Return: none
 */

void free_listint(listint_t *head)
{
	listint_t *temporary;

	while (head)
	{
		temporary = head->next;
		free(head);
		head = temporary;
	}
}
