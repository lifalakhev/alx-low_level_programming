#include "main.h"

/**
 * _strlen - Function that finds the length of a string.
 * @s: pointer to the string to check
 * Return: void
*/

int _strlen(char *s)
{
int len = 0;
while (s[len])
	len++;

return (len);
}
