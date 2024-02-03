#include "hash_tables.h"

/**
 * shash_table_create - Creating sorted out hash table
 * @size: hash table size
 * Return: hash--table
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *nt;

	new_table = malloc(sizeof(shash_table_t));

	if (!nt)
		return (NULL);
	
	nt->array = calloc(size, sizeof(shash_table_t));
	if (!nt->array)
	{
		free(nt);
		return (NULL);
	}
	nt->size = size;
	nt->shead = NULL;
	nt->stail = NULL;

	return (nt);
}
