#include "lists.h"
/**
 * free_list - free the list
 * @head: the head
 * Return: none
 */
void free_list(list_t *head)
{
	list_t *li;

	while ((li = head) != NULL)
	{
		head = head->next;
		free(li->str);
		free(li);
	}
}
