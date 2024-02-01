#include "lists.h"
/**
 * add_node - inserts a new node at the list
 * @head: the head
 * @str: the string
 * Return: addres of head
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *li;
	size_t i = 0;

	li = malloc(sizeof(list_t));
	if (li == NULL)
		return (NULL);

	while (str[i])
		i++;

	li->str = strdup(str);
	li->len = i;
	li->next = *head;
	*head = li;

	return (*head);
}
