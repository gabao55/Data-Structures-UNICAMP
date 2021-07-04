#include <stdlib.h>
#include <string.h>
#include "hashing.h"

/*
 * The function djb2 converts a string into a natural number with a good hashing.
 */
unsigned long djb2(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) ^ c;	// hash * 33 XOR c

    return hash;
}

/*
 * This function allocates a hash dinamically table.
 * In case of allocation failure, it returns NULL.
 */
hash_table *table_alloc(int size) {
    hash_table *table;
    table = (hash_table *) calloc(1, sizeof(hash_table));
    if (!table)
        return NULL;
    table->size = size;
    table->time = 0;
    table->nodes = (node **) calloc(table->size, sizeof(node *));
    if (!table->nodes)
        return NULL;

    return table;
}

/*
 * This function frees all table's nodes for terminating the program and the table itself.
 */
void table_free(hash_table * table)
{
    int i;
    for (i = 0; i < table->size; i++) {
        if (table->nodes[i]) {
            if (table->nodes[i]->data)
                free(table->nodes[i]->data);
            free(table->nodes[i]);
        }
    }
    free(table);
}

/*
 * This functions inserts an register in the hash table and returns the current timestamp.
 * In case of memory allocation failute, returns 0. Otherwise it returns 1.
 * If the key is already inserted in the table, returns -1.
 */
int table_insert(hash_table * table, unsigned char *key)
{
    unsigned long index;
    unsigned long hash = djb2(key);
    int i = 1;

    index = hash % table->size;

    while (table->nodes[index]) {
        if (table->nodes[index]->timestamp == -1) {
            free(table->nodes[index]->data);
            free(table->nodes[index]);
            break;
        }

        index =
                (hash % table->size +
                 (i) * (1 + hash % (table->size - 1))) % table->size;
        i++;
    }

    node *n = malloc(sizeof(node));
    if (!n)
        return 0;
    n->timestamp = table->time++;
    n->data = malloc((strlen((const char *) key) + 1) * sizeof(char));
    strcpy(n->data, (const char *) key);

    table->nodes[index] = n;

    return 1;
}

/*
 * This function searches for a key in the hash table.
 * In case it finds the key, returns the node. Otherwise returns NULL.
 */
node *table_search(hash_table * table, unsigned char *key)
{
    unsigned long index;
    unsigned long hash = djb2(key);
    int i = 1;

    index = hash % table->size;

    while (table->nodes[index]) {
        if (strcmp(table->nodes[index]->data, (const char *) key) == 0)
            return table->nodes[index];

        index = (hash % table->size + i * (1 + hash % (table->size - 1))) % table->size;
        i++;
    }

    return NULL;
}