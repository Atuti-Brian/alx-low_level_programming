#include "main.h"

/**
 * _memset - Entry
 * @s: pointer
 * @b: constant
 * @n: int
 * Return: 0
 */

char *_memset(char *s, char b, unsigned int n)
{
	int i;

	for (i = 0; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}
