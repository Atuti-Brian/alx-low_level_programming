#include "hash_tables.h"

/**
 * hash_table_set - function that adds a new node to the table
 * @ht: hash table to add new node to
 * @key: They key
 * @value: value
 * Return: 1, if successful, 0 if it fails
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node, *tmp;
	unsigned long int i;

	if (!ht || !key || !*key || !value)
	{
		return (0);
	}

	i = key_index((unsigned char *)key, ht->size);
	tmp = ht->array[i];
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = strdup(value);
			return (1);
		}
		tmp = tmp->next;
	}
	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
		return (0);
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = ht->array[i];
	ht->array[i] = new_node;
	return (1);
}
