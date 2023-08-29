#include "lists.h"

/**
 * listint_len - Returns the number of elements in a linked lists.
 * @h: Traverse linked list of type listint_t
 *
 * Return: number of nodes(Success)
 */
size_t listint_len(const listint_t *h)
{
	size_t num = 0;

	while (h)
	{
		num++;
		h = h->next;
	}

	return (num);
}
