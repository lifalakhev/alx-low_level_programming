#include <stdio.h>

/**
 * main - prints all possible combinations of single-digit numbers
 * Return: Always 0 (Succss)
 */
int main(void)
{
	int i;

	for (i = '0'; i <= '9'; i++)
	{
		putchar(i);
		if (i <= '8')
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');

	return (0);
}
