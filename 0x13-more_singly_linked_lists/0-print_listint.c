#include "lists.h"

/**
 * print_listint - It prints the elements of linked list.
 * @h: To print linked list of type listint_t
 *
 * Return: number of nodes(On success)
 */
size_t print_listint(const listint_t *h)
{
	size_t num = 0;

	while (h)
	{
		printf("%d\n", h->n);
		num++;
		h = h->next;
	}

	return (num);
}
