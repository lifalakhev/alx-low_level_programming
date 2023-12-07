#include "lists.h"

/**
 * dlistint_len - Func that returns number of elements in linked dlistint_t list
 * @h: poiner to the head of the list
 *
 * Return: number of elements
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}
