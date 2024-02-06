#include "lists.h"
/**
 * sum_listint - adds the data in the list
 * @head: the linked list
 * Return: sum of the datas
 */
int sum_listint(listint_t *head)
{
	int add = 0;
	listint_t *temporary = head;

	while (temporary)
	{
		add += temporary->n;
		temporary = temporary->next;
	}

	return (add);
}
