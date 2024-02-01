#include "lists.h"
/**
 * add_node_end - adds a node at the end
 * @head: the head
 * @str: the string
 * Return: adres of head.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *li, *buff;
	size_t nchar = 0;

	li = malloc(sizeof(list_t));

	if (li == NULL)
		return (NULL);

	li->str = strdup(str);

	while (str[nchar])
		nchar++;

	li->len = nchar;
	li->next = NULL;
	buff = *head;

	if (buff == NULL)
		*head = li;

	else
	{
		while (buff->next != NULL)
		buff = buff->next;
		buff->next = li;
	}

	return (*head);
}
