#include "lists.h"
/**
 * print_listint_safe - prints the linked list with a loop
 * @head: the list
 * Return: number of nodes
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *tmp = NULL;
	const listint_t *lis = NULL;
	size_t count = 0;
	size_t new;

	tmp = head;
	while (tmp)
	{
		printf("[%p] %d\n", (void *)tmp, tmp->n);
		count++;
		tmp = tmp->next;
		lis = head;
		new = 0;
		while (new < count)
		{
			if (tmp == lis)
			{
				printf("-> [%p] %d\n", (void *)tmp, tmp->n);
				return (count);
			}
			lis = lis->next;
			new++;
		}
		if (!head)
			exit(98);
	}
	return (count);
}
