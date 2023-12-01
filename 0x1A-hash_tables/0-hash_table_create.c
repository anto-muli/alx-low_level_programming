#include "hash_tables.h"

/**
 * hash_table_create - creates a new hash table
 * @size: the size of the array to be created in
 * in the hash table
 * Return: a new ptr to the newly created hash table, or NULL
 * if there is a  failure
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table = NULL;
	unsigned long int inno;

	if (size == 0)
	{
		return (NULL);
	}

	/* Allocate memory for hash table struct using malloc */
	hash_table = malloc(sizeof(hash_table_t));
	if (hash_table == NULL)
	{
		return (NULL);
	}

	/* Allocate memory for array in the # nodes */
	hash_table->array = malloc(sizeof(hash_node_t *) * size);
	if (hash_table->array == NULL)
	{
		free(hash_table);
		return (NULL);
	}

	hash_table->size = size;

	/* Initialize all new hash node ptrs to NULL */
	for (inno = 0; inno < size; inno++)
	{
		hash_table->array[inno] = NULL;
	}

	return (hash_table);
}