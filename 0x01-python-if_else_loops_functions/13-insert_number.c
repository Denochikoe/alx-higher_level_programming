#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a new node with a given number into a
 * sorted list
 * @head: double pointer to the head of the linked list
 * @number: number to insert into the new node
 *
 * Return: The address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node;
	listint_t *current;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = number;
	new_node->next = NULL;

	if (*head == NULL || (*head)->n >= number)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	current = *head;
	while (current->next != NULL && current->next->n >
		       	number)
	{
		current = current->next;
	}

	if (current->next == NULL)
	{
		current->next = new_node;
	}

	else
	{
		new_node->next = current->next;
		current->next = new_node;
	}

	return (new_node);
}
