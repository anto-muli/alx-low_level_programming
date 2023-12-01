#include <string.h>
#include "hash_tables.h"


/**
 * hash_table_get - Retrieves the value associated with
 * a specific key in a hash table.
 * @ht: A ptr to the hash table.
 * @key: The key of the retrieved value
 *
 * Return: If the key can't be matched return NULL.
 * Otherwise  return the value of key in ht.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);

	node = ht->array[index];
	while (node && strcmp(node->key, key) != 0)
		node = node->next;

	return ((node == NULL) ? NULL : node->value);
}
