#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * reverse_list - Reverses a linked list
 * @head: Pointer to pointer of the first node of the list
 * Return: Pointer to the new head of the reversed list
 */
listint_t *reverse_list(listint_t *head)
{
    listint_t *prev = NULL;
    listint_t *current = head;
    listint_t *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

/**
 * is_palindrome - Checks if a linked list is a palindrome
 * @head: Pointer to pointer of the first node of the list
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head, *fast = *head, *second_half, *first_half;
    listint_t *copy_of_second_half;
    int palindrome = 1;

    // If list is empty or has only one element
    if (*head == NULL || (*head)->next == NULL)
        return 1;

    // Find the middle of the list
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    // Reverse the second half
    second_half = reverse_list(slow);
    copy_of_second_half = second_half; // Save the start of the reversed list

    // Compare the first half and the reversed second half
    first_half = *head;
    while (second_half != NULL)
    {
        if (first_half->n != second_half->n)
        {
            palindrome = 0;
            break;
        }
        first_half = first_half->next;
        second_half = second_half->next;
    }

    // Restore the original list (optional)
    reverse_list(copy_of_second_half);

    return palindrome;
}

