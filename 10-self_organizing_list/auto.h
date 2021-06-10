/**
 auto.h
 Declarations for different types of self-organizing lists for efficiency comparing purpose.
 Permutation Strategies:
 - Move-to-front (MTF)
 - Transpose
 - Count
 **/
#ifndef INC_10_AUTO_AUTO_H
#define INC_10_AUTO_AUTO_H

struct node {
    int data;
    int count;
    struct node *next;
};

typedef struct node node;

struct list {
    node *head;
    node *tail;
};

typedef struct list list;

/*
 Allocates a list with the head pointing to a NULL value and cost equals to zero.
 Returns a pointer to the list or NULL if memory allocation fails
 */
list *list_alloc();

/*
 Pushes a new node to the end of a list of ints.
 Returns 1 on success or 0 if memory allocation fails.
 */
int list_push(list *li, int data);

/*
 Resets the order of a list to the original one given in the beginning of the problem.
 */
void list_reset(list *current, int N);

/*
 Makes the consulting of the referred list using the MTF method.
 Returns the cost of the operation for this method.
 */
int MTF(list *li, int *consult, int R);

/*
 Makes the consulting of the referred list using the Transpose method.
 Returns the cost of the operation for this method.
 */
int transpose(list *li, int *consult, int R);

/*
 Makes the consulting of the referred list using the Count method.
 Returns the cost of the operation for this method.
 */
int count(list *li, int *consult, int R);

// Printing to check:
void list_print(list* L);

#endif //INC_10_AUTO_AUTO_H
