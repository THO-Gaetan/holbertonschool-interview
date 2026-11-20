#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * create_node - allocates a new node with a copy of str
 * @str: the string to copy into the new node
 *
 * Return: address of the new node, or NULL on failure
 */
static List *create_node(char *str)
{
	List *new;

	if (str == NULL)
		return (NULL);
	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}
	new->prev = new;
	new->next = new;
	return (new);
}

/**
 * add_node_end - adds a new node at the end of a double circular list
 * @list: the list to modify
 * @str: the string to copy into the new node
 *
 * Return: address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new, *head, *last;

	if (list == NULL)
		return (NULL);
	new = create_node(str);
	if (new == NULL)
		return (NULL);
	if (*list == NULL)
	{
		*list = new;
		return (new);
	}
	head = *list;
	last = head->prev;
	new->next = head;
	new->prev = last;
	last->next = new;
	head->prev = new;
	return (new);
}

/**
 * add_node_begin - adds a new node at the beginning of a double circular list
 * @list: the list to modify
 * @str: the string to copy into the new node
 *
 * Return: address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new;

	new = add_node_end(list, str);
	if (new == NULL)
		return (NULL);
	*list = new;
	return (new);
}
