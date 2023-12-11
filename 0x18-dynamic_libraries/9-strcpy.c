#include "main.h"

/**
 * *_strcpy - Function copies the string pointed to by src,
 * and terminating NULL byte
 * @dest: Pointer to the character array to write to.
 * @src: Pointer to the null-terminated byte string to copy from.
 *
 * Return: Pointer to `dest`
 */

char *_strcpy(char *dest, char *src)
{
	int i = -1;

	do {
		i++;
		dest[i] = src[i];
	} while (src[i] != '\0');

	return (dest);
}
