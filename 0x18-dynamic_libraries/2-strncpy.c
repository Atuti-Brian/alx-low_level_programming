#include "main.h"

/**
 * _strncpy- Entry
 * @dest: d
 * @src: e
 * @n: n
 * Return: 0
 */

char *_strncpy(char *dest, char *src, int n)
{
	int j = 0;

	while (j < n && src[j] != '\0')
	{
		dest[j] = src[j];
		j++;
	}
	while (j < n)
	{
		dest[j] = '\0';
		j++;
	}
	return (dest);
}
