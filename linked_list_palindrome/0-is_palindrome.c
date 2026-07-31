#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer of first node of listint_t list
 * Return: 1 if it is a palindrome, 0 if not
 */

int is_palindrome(listint_t **head)
{
	listint_t *current;
	int n = 0, i;
	int *arr;

	current = *head;

	while (current != NULL)
	{
		n++;
		current = current->next;
	}
	if (n == 0 || n == 1)
		return (1);

	arr = malloc(sizeof(int) * n);

	if (arr == NULL)
		return (0);
	current = *head;
	for (i = 0; i < n; i++)
	{
		arr[i] = current->n;
		current = current->next;
	}
	for (i = 0; i < n / 2; i++)
	{
		if (arr[i] != arr[n - 1 - i])
		{
			free(arr);
			return (0);
		}
	}
	free(arr);
	return (1);
}