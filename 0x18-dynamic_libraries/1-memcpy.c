#include "main.h"

/**
 * _memcpy - Entry
 * @dest: dest
 * @src: src
 * @n: int
 * Return: 0
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	int r;
	int i = n;

	for (r = 0; r < i; r++)
	{
		dest[r] = src[r];
		n--;
	}
	return (dest);
}
