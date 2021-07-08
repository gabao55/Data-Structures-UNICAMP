#ifndef INC_13_HASHING_HASHING_H
#define INC_13_HASHING_HASHING_H

typedef struct node {
    int timestamp;
    char *data;
} node;

typedef struct hash_table {
    int size;
    int time;
    node **nodes;
} hash_table;

/*
 * The function djb2 converts a string into a natural number with a good hashing.
 */
unsigned long djb2(unsigned char *str);

/*
 * This function allocates dinamically a hash table and its nodes.
 * In case of allocation failure, it returns NULL.
 */
hash_table *table_alloc(int size);

/*
 * This function frees all table's nodes for terminating the program and the table itself.
 */
void table_free(hash_table * table);

/*
 * This functions inserts an register in the hash table and returns the current timestamp.
 * In case of memory allocation failute, returns 0. Otherwise it returns 1.
 * If the key is already inserted in the table, returns -1.
 */
int table_insert(hash_table * table, unsigned char *key);

/*
 * This function searches for a key in the hash table.
 * In case it finds the key, returns the node. Otherwise returns NULL.
 */
node *table_search(hash_table * table, unsigned char *key);

#endif				//INC_13_HASHING_HASHING_H