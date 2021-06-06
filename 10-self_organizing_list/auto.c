#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "auto.h"

/*
 Allocates a list with the head pointing to a NULL value and cost equals to zero.
 Returns a pointer to the list or NULL if memory allocation fails
 */
list *list_alloc() {
    list *li = malloc(sizeof(list));
    if (!li)
        return NULL;
    node* n = malloc(sizeof(node));
    if (!n)
        return NULL;

    n->next = NULL;
    li->head = n;
    li->tail = n;

    return li;
}

/*
 Pushes a new node to the end of a list of ints.
 Returns 1 on success or 0 if memory allocation fails.
 */
int list_push(list *li, int data) {
    node *n = malloc(sizeof(node));
    if (!n)
        return 0;

    n->data = data;
    n->count = 0;
    n->next = NULL;

    li->tail->next = n;
    li->tail = n;

    return 1;
}

/*
 Resets the order of a list to the original one given in the beginning of the problem.
 */
void list_reset(list *current, int N) {
    node* p = current->head->next;
    int i = 1;

    while (i <= N) {
        p->data = i;
        i++;
        p = p->next;
    }
}

/*
 Makes the consulting of the referred list using the MTF method.
 Returns the cost of the operation for this method.
 */
int MTF(list *li, int *consult, int R) {
    int i, item, cost = 0;
    node *n = li->head;
    node *previous;
    node *backup = li->head->next;

    for (i = 0; i < R; i++) {
        item = consult[i];
        do {
            previous = n;
            n = n->next;
            cost++;
        } while (n->data != item && n->next != NULL);
        if (n->data != backup->data) {
            backup = n;
            n = n->next;
            previous->next = n;
            backup->next = li->head->next;
            li->head->next = backup;
        }

        n = li->head;
        backup = li->head->next;
    }

    return cost;
}

/*
 Makes the consulting of the referred list using the Transpose method.
 Returns the cost of the operation for this method.
 */
int transpose(list *li, int *consult, int R) {
    int i, item, cost = 0;
    node *n = li->head->next;
    node *previous = li->head;
    node *before_previous;

    for (i = 0; i < R; i++) {
        item = consult[i];
        cost++;
        while (n->data != item) {
            before_previous = previous;
            previous = n;
            n = n->next;
            cost++;
        }
        if (n->data != li->head->next->data) {
            previous->next = n->next;
            n->next = previous;
            before_previous->next = n;
        }

        n = li->head->next;
        previous = li->head;
    }

    return cost;
}

/*
 Makes the consulting of the referred list using the Count method.
 Returns the cost of the operation for this method.
 */
int count(list *li, int *consult, int R) {
    int i, item, cost = 0;
    node *n = li->head;
    node *previous;
    node *backup = li->head;

    for (i = 0; i < R; i++) {
        item = consult[i];
        do {
            previous = n;
            n = n->next;
            cost++;
        } while (n->data != item && n->next != NULL);
        n->count++;

        if (n->data != li->head->next->data) {
            while (backup->next->count > n->count && backup->next != NULL) {
                backup = backup->next;
            }
            previous->next = n->next;
            n->next = backup->next;
            backup->next = n;
        }

        n = li->head;
        backup = li->head;
    }

    return cost;
}

// Printing to check:
void list_print(list* L) {

    node* p = L->head->next;

    while (p->next != NULL) {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("%d\n",p->data);
}