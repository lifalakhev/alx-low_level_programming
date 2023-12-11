#include <stdio.h>
#include "main.h"

/**
* _atoi - Functions changes a string to an int.
* @s: the string to be changed
*
* Return: the converted int
*/

int _atoi(char *s)
{
	int i = 1;
	unsigned int k = 0;

	do {
		if (*s == '-')
			i *= -1;
		else if (*s >= '0' && *s <= '9')
			k = k * 10 + (*s - '0');
		else if (k > 0)
			break;
	} while (*s++);

	return (k * i);
}
