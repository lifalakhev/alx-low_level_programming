#include <stdio.h>

/**
 * main - prints numbers between 0 to 9 and letters between a to f.
 *
 * Return: Always 0 (Success)
 */

int main()
{
	int i;
	        for (i = 0; i < 10; i++) 
		{
			        putchar('0' + i);				    }
		    for (i = 0; i < 6; i++)
		    {
			            putchar('a' + i);
		    }			    putchar('\n')
			    return 0;
}

