#include "hash_tables.h"
/**
 * key_index- Func (returns array key index)
 * @key: key
 * @size: array size
 * Return: (key )
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_val;

	hash_val = hash_djb2(key);
	return (hash_val % size);
}
