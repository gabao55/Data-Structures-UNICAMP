/**
  darray.h
  Declarations for a sequence of strings stored in an array that swells and
  shrinks by a factor of 2 as needed.
**/


#ifndef DARRAY_H
#define DARRAY_H


typedef struct darray {

    char** data; // The array of pointers to char, that is, the array of string.

    int first; // The index of the first element in the sequence.
    int size;  // The sequence size.

    int capacity; // The array size.
    int min_cap;  // The minimum array size.

} darray;



/**
   Allocate a darray and the array of pointers to strings with
   initial capacity.  Set the initial state of the darray properly.

   capacity is the initial array size.  It is also the minimum array size.

   It returns the address of a new darray.  On failure it returns NULL.
**/
darray* da_alloc(int capacity);



/**
  Release all the strings in a darray and the darray itself.
**/
void da_free(darray* A);



/**
   Add a copy of a string to the end of the sequence.

   If the array is full, it tries to double its capacity and then adds the
   string.

   On success it returns 1.  When resizing the array is not possible it will not
   push and will return 0.
**/
int da_push(darray* A, char* string);



/**
   Remove a string from the end of the sequence and return a pointer to it.

   If the array is 1/4 full, this function halves its capacity and then removes
   the string.  The capacity will never be smaller than the initial capacity.
**/
char* da_pop(darray* A);



/**
   Add a copy of a string to the beginning of the sequence.

   If the array is full, it tries to double its capacity and then adds the
   string.

   On success it returns 1.  When resizing the array is not possible it will not
   inject and will return 0.
**/
int da_inject(darray* A, char* string);



/**
   Remove a string from the beginning of the sequence and return a pointer to it.

   If the array is 1/4 full, this function halves its capacity and then removes
   the string.  The capacity will never be smaller than the initial capacity.
**/
char* da_eject(darray* A);



/**
   Return a pointer to the first string in the sequence.
**/
char* da_first(darray* A);



/**
   Return a pointer to the last string in the sequence.
**/
char* da_last(darray* A);



/**
   Return 1 if the sequence is empty, otherwise return 0.
**/
int da_is_empty(darray* A);


#endif