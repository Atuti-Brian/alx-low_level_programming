#include "hash_tables.h"

/**
 * hash_table_print - Prints table's elements
 * @ht: hash table to print
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *tmp;
	int comma = 0;

	if (!ht)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			if (comma == 1)
				printf(", ");
		}
		tmp = ht->array[i];

		while (tmp)
		{
			if (ht->array)
			{
				while (tmp)
				{
					printf("'%s': '%s'", tmp->key, tmp->value);
					tmp = tmp->next;
					if (tmp)
						printf(", ");
				}
				comma = 1;
			}
		}
	}
	printf("}\n");
}
