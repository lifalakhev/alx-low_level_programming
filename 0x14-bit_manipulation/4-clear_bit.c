#include "main.h"
#include <stdlib.h>

/**
 * clear_bit - Function sets the value of bit to 0 @ given inder
 * @n: parameter
 * @index: index
 *
 * Returns: 1 if it worked, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > sizeof(n) * 8)
		return (-1);
	*n &= ~(1 << index);
	return (1);
}
