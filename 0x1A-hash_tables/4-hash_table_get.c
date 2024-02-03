#include "hash_tables.h"

/**
 * hash_table_get- Gets the value from a hash table
 * @ht: Table to look from
 * @key: key to look up
 * Return: value
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int i;
	hash_node_t *tmp;

	if (!ht || !key || strlen(key) == 0)
		return (NULL);

	i = key_index((unsigned char *)key, ht->size);
	tmp = ht->array[i];

	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}
