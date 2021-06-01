#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "li.h"


li* li_alloc() {
  return calloc(1,sizeof(li));
}

void li_free(li* L) {

  node* p = L->head;
  node* n = NULL;

  while (p != NULL) {
    n = p->next;
    free(p);
    p = n;
  }

  free(L);
}

int li_insert(li* L, int data) {

  node* n = malloc(sizeof(node));
  if (n == NULL)
    return 0;

  n->data = data;
  n->next = L->head;
  L->head = n;

  return 1;
}

void li_print(li* L) {

  node* p = L->head;
  printf("{");

  while (p != NULL && p->next != NULL) {
    printf("%d, ",p->data);
    p = p->next;
  }

  if (p != NULL)
    printf("%d",p->data);

  printf("}");
}

li* li_union(li* A, li* B) {
    li *uni = li_alloc();
    int test;

    node *p = A->head;
    while (p != NULL) {
        test = li_insert(uni, p->data);
        if (!test) {
            li_free(A);
            li_free(B);
            li_free(uni);
            return NULL;
        }
        p = p->next;
    }

    p = B->head;
    node *check = uni->head;
    int approve = 1;
    while (p != NULL) {
        while (check != NULL && approve) {
            if (p->data == check->data)
                approve = 0;
                check = check->next;
        }
        check = uni->head;
        if (approve) {
            test = li_insert(uni, p->data);
            if (!test) {
                li_free(A);
                li_free(B);
                li_free(uni);
                return NULL;
            }
        }
        approve = 1;
        p = p->next;
    }

    return uni;
}

li* li_intersection(li* A, li* B) {
    li *intersection = li_alloc();
    int test;

    node *p = A->head;
    node *check = B->head;
    int approve = 0;
    while (p != NULL) {
        while (check != NULL && !approve) {
            if (p->data == check->data)
                approve = 1;
            check = check->next;
        }
        check = B->head;
        if (approve) {
            test = li_insert(intersection, p->data);
            approve = 0;
            if (!test) {
                li_free(A);
                li_free(B);
                li_free(intersection);
                return NULL;
            }
        }
        p = p->next;
    }

    return intersection;
}

li* li_difference(li* A, li* B) {
    li *diff = li_alloc();
    int test;

    node *p = A->head;
    node *check = B->head;
    int approve = 1;
    while (p != NULL) {
        while (check != NULL && approve) {
            if (p->data == check->data)
                approve = 0;
            check = check->next;
        }
        check = B->head;
        if (approve) {
            test = li_insert(diff, p->data);
            if (!test) {
                li_free(A);
                li_free(B);
                li_free(diff);
                return NULL;
            }
        }
        approve = 1;
        p = p->next;
    }

    return diff;
}