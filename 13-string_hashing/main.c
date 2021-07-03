#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "hashing.h"

// For switching the table capacity, just change this number
# define CAPACITY 6257

int main() {
    char cmd;
    char *key;
    char string[252];
    node *n;
    key = malloc(251*sizeof(char));

    int test, i;

    hash_table *table = table_alloc(CAPACITY);
    if (!table)
        exit(1);

    while (1) {
        scanf( " %c%[^\n]", &cmd, string);

        if (cmd == 'f') {
            free(key);
            table_free(table);
            break;
        }

        for (i = 1; i < strlen(string);i++)
            key[i-1] = string[i];
        key[i-1] = '\0';

        if (cmd == 'i') {
            n = table_search(table, (unsigned char*) key);
            if (!n) {
                test = table_insert(table, (unsigned char*) key);
                if (!test)
                    exit(errno);
                printf("[%s] foi inserida", key);
            }
            else {
                if (n->timestamp == -1) {
                    test = table_insert(table, (unsigned char*) key);
                    if (!test)
                        exit(errno);
                    printf("[%s] foi inserida", key);
                }
                else {
                    printf("[%s] ja esta na tabela", key);
                }
            }
        }

        if (cmd == 'b') {
            n = table_search(table, (unsigned char *) key);
            if (!n)
                printf("[%s] nao esta na tabela", key);
            else {
                if (n->timestamp == -1)
                    printf("[%s] nao esta na tabela", key);
                else
                    printf("[%s] esta na tabela, timestamp %d", key, n->timestamp);
            }
        }

        if (cmd == 'r') {
            n = table_search(table, (unsigned char *) key);
            if (!n)
                printf("[%s] nao esta na tabela", key);
            else {
                if (n->timestamp == -1)
                    printf("[%s] nao esta na tabela", key);
                else {
                    n->timestamp = -1;
                    printf("[%s] foi removida", key);
                }
            }
        }

        printf("\n");
    }

    return 1;
}
