#include "minimum_heap.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * This function allocates a minimum heap dinamically.
 * In case of allocation failure, it returns NULL.
 */
heap *heap_alloc(int size) {
    int i;
    heap *hp;
    hp = (heap *) calloc(1, sizeof(heap));
    if (!hp)
        return NULL;
    hp->size = 0;
    hp->capacity = size;
    hp->H = (vertex *) calloc(size, sizeof(vertex));
    if (!hp->H)
        return NULL;
    hp->I = (int *) calloc(size, sizeof(int));
    if (!hp->I)
        return NULL;

    for (i=0;i<hp->capacity;i++)
        hp->I[i] = size + 1;

    return hp;
}

/*
 * This function frees the heap's H and I for terminating the program and the heap itself.
 */
void heap_free(heap *hp) {
    free(hp->H);
    free(hp->I);
    free(hp);
}

/*
 * This functions switches two vertexes' positions in the heap based on it's index.
 * It updates both H and I arrays.
 */
void swap(heap *hp, int first, int second) {
    int temporary_key, temporary_cost;
    temporary_key = hp->H[first].key;
    temporary_cost = hp->H[first].cost;

    hp->H[first].key = hp->H[second].key;
    hp->H[first].cost = hp->H[second].cost;

    hp->H[second].key = temporary_key;
    hp->H[second].cost = temporary_cost;

    hp->I[hp->H[first].key] = first;
    hp->I[hp->H[second].key] = second;
}

/*
 * This function inserts a vertex in the minimum heap.
 */
void heap_insert(heap *hp, int k, int c) {
    if (hp->I[k] != hp->capacity + 1)
        return ;
    int i = hp->size;
    hp->H[hp->size].key = k;
    hp->H[hp->size].cost = c;

    hp->I[k] = hp->size;

    while (i > 0) {
        if (hp->H[i].cost < hp->H[(i-1)/2].cost) {
            swap(hp, i, (i-1)/2);
            i = (i-1)/2;
        }
        else
            break ;
    }

    hp->size++;
}

/*
 * This function reduces the cost value of k's vertex in the heap to the inserted c value.
 */
void heap_reduce(heap *hp, int k, int c) {
    int index = hp->I[k];
    hp->H[index].cost = c;

    while (index > 0) {
        if (hp->H[index].cost < hp->H[(index-1)/2].cost) {
            swap(hp, index, (index-1)/2);
            index = (index-1)/2;
        }
        else
            break ;
    }
}

/*
 * This function removes the minimum heap and prints it's data inline.
 * In case the heap is empty, it prints "heap vazio".
 */
void heap_remove(heap *hp) {
    if (!hp->size) {
        printf("heap vazio\n");
        return ;
    }

    printf("minimo {%d,%d}\n", hp->H[0].key, hp->H[0].cost);


    hp->I[hp->H[0].key] = hp->capacity + 1;

    if (hp->size - 1 == 0) {
        hp->size--;
        return ;
    }

    hp->size--;
    hp->H[0].key = hp->H[hp->size].key;
    hp->H[0].cost = hp->H[hp->size].cost;
    hp->I[hp->H[0].key] = 0;

    int i = 0;

    while (2*i + 1 < hp->size) {
        if (2*i + 2 >= hp->size ||
        hp->H[2*i+1].cost < hp->H[2*i+2].cost) {
            if (hp->H[i].cost > hp->H[2*i+1].cost) {
                swap(hp, i, 2*i+1);
                i = 2*i + 1;
            }
            else
                break ;
        }
        else {
            if ((hp->H[i].cost > hp->H[2*i+2].cost)){
                swap(hp, i, 2*i+2);
                i = 2*i + 2;
            }
            else
                break ;
        }
    }
}

/*
 * This function prints the heap's H vector.
 */
void print_H(heap *hp) {
    int i;
    for (i=0;i<hp->size;i++)
        printf("{%d,%d} ", hp->H[i].key, hp->H[i].cost);
    printf("\n");
}

/*
 * This function prints the heap's I vector.
 */
void print_I(heap *hp) {
    int i;
    for (i=0;i<hp->size;i++)
        printf("{%d,%d} ", hp->H[i].key, hp->I[hp->H[i].key]);
    printf("\n");
}