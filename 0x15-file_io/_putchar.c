#include <unistd.h>

/**
 * _putchar - Writes a character to the standard output (stdout).
 * @c: The character to write.
 *
 * Return: On success, returns the character written as an unsigned char cast
 * to an int. On error, -1 is returned.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
