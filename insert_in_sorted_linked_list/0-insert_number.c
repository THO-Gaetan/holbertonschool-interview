#include <stdlib.h>
#include <stdio.h>
#include "lists.h"
/**
* insert_node - insert an integer in a single linked list
* @head: pointer to the head of the list
* @number: the integer who need to be insert in the list
*
* Description: This program is inserting a number in
* a single linked list
*
* Return: return head
*/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
	{
		printf("Error");
		return (NULL);
	}
	while (*head != NULL && (*head)->n < number)
	{
		head = &(*head)->next;
	}
	new->n = number;
	new->next = *head;
	*head = new;
	return (*head);
}
