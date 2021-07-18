#ifndef INC_14_HEAP_MINIMUM_HEAP_H
#define INC_14_HEAP_MINIMUM_HEAP_H

typedef struct vertex {
    int key;
    int cost;
} vertex;

typedef struct heap {
    int capacity;
    int size;
    vertex *H;
    int *I;
} heap;

/*
 * This function allocates a minimum heap dinamically.
 * In case of allocation failure, it returns NULL.
 */
heap *heap_alloc(int size);

/*
 * This function frees all heap's vertexes for terminating the program and the heap itself.
 */
void heap_free(heap *hp);

/*
 * This functions switches two vertexes' positions in the heap.
 * It updates both H and I arrays.
 */
void swap(heap *hp, int first, int second);

/*
 * This function inserts a vertex in the minimum heap.
 */
void heap_insert(heap *hp, int k, int c);

/*
 * This function reduces the cost value of k's vertex in the heap to the inserted c value.
 */
void heap_reduce(heap *hp, int k, int c);

/*
 * This function removes the minimum heap and prints it's data inline.
 * In case the heap is empty, it prints "heap vazio".
 */
void heap_remove(heap *hp);

/*
 * This function prints the heap's H vector.
 */
void print_H(heap *hp);

/*
 * This function prints the heap's I vector.
 */
void print_I(heap *hp);

#endif //INC_14_HEAP_MINIMUM_HEAP_H
