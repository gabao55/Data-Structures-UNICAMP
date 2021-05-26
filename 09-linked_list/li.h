#include <stdlib.h>
#include <stdio.h>
#include <errno.h>


struct node {
  int data;
  struct node* next;
};

typedef struct node node;


struct li {
  node* head;
};

typedef struct li li;


/*
  Allocate an empty list of ints.  Return a pointer to the new list or NULL if
  memory allocation fails.
*/
li* li_alloc();


/*
  Release a list of ints and all its nodes.
*/
void li_free(li* L);


/*
  Insert a new node at the beginning of a list of ints.  Return 1 on success or
  0 if memory allocation fails.
*/
int li_insert(li* L, int data);


/*
  Print the contents of a list of ints.
*/
void li_print(li* L);


/*
  Evaluate the union of lists of ints A and B.  Return a new list on success.
  If memory allocation fails any partially constructed list is freed and it
  returns NULL.
*/
li* li_union(li* A, li* B);


/*
  Evaluate the intersection of lists of ints A and B.  Return a new list on
  success.  If memory allocation fails any partially constructed list is freed
  and it returns NULL.
*/
li* li_intersection(li* A, li* B);


/*
  Evaluate the difference A-B of lists of ints.  Return a new list on success.
  If memory allocation fails any partially constructed list is freed and it
  returns NULL.
*/
li* li_difference(li* A, li* B);
