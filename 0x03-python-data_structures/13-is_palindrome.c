#include "lists.h"
#include <stdio.h>

void reverse(listint_t **head);
int compare_lists(listint_t *head, listint_t *middle, int len);

/**
 * is_palindrome - A funct that checks for palindrome in a singly linked list.
 * @head: A pointer to the pointer of the first node in the passed list.
 * Return: 0 if a palidrome and 1 upon success.
 */

int is_palindrome(listint_t **head)
{
	int len, index;
	listint_t *tmp;
	listint_t *middle;

	if (head == NULL || *head == NULL)
		return (1);
	tmp = *head;
	middle = *head;

	for (len = 0; tmp != NULL; len++)
		tmp = tmp->next;

	len = len / 2;

	for (index = 1; index < len; index++)
		middle = middle->next;
	if (len % 2 != 0 && len != 1)
	{
		middle = middle->next;
		len = len - 1;
	}
	reverse(&middle);
	index = compare_lists(*head, middle, len);

	return (index);
}

/**
 * compare_lists - A funct that compare two lists.
 * @head: A pointer to the head node.
 * @middle: A pointer to the middle node.
 * @len: The length of the list.
 * Return: 1 if identical and 0 if not.
 */

int compare_lists(listint_t *head, listint_t *middle, int len)
{
	int index;

	if (head == NULL || middle == NULL)
		return (1);
	for (index = 0; index < len; index++)
	{
		if (head->n != middle->n)
			return (0);
		head = head->next;
		middle = middle->next;
	}
	return (1);
}

/**
 * reverse - A funct that reverses a list.
 * @head: A pointer to the head to reverse.
 */

void reverse(listint_t **head)
{
	listint_t *current;
	listint_t *next;
	listint_t *prev;

	if (head == NULL || *head == NULL)
		return;

	prev = NULL;
	current = *head;
	while (current != NULL)
	{
	
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}
