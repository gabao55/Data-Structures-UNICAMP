#include <stdio.h>
#include "darray.h"
#include "stdlib.h"
#include "string.h"

darray *da_alloc(int capacity) {
    darray *darray1;
    darray1 = malloc(sizeof(darray));
    if (!darray1)
        return NULL;
    darray1->capacity = capacity;
    darray1->data = (char **) malloc(capacity*sizeof(char*));
    darray1->first = 0;
    darray1->size = 0;
    darray1->min_cap = capacity;
    if (!darray1->data)
        return NULL;

    return darray1;
}

void da_free(darray *A) {
    free(A->data);
    free(A);
}

int da_inject(darray* A, char* string) {
    int i;

    if (A->first == 0) {
        if (A->size == A->capacity) {
            darray *aux = da_alloc(2 * A->capacity);
            if (!aux)
                return 0;
            aux->first = A->first;
            aux->size = A->size;
            aux->min_cap = A->min_cap;
            for (i = 0; i < A->size; i++) {
                aux->data[i] = (char *) malloc(sizeof(A->data[i]));
                aux->data[i] = A->data[i];
            }
            da_free(A);
            A = da_alloc(aux->capacity);
            if (!A)
                return 0;
            A->first = aux->first;
            A->size = aux->size;
            A->min_cap = aux->min_cap;
            for (i = 0; i < A->size; i++) {
                A->data[i] = (char *) malloc(sizeof(aux->data[i]));
                A->data[i] = aux->data[i];
            }
            A->data[A->capacity - 1] = (char *) malloc(sizeof(char) * (strlen(string) + 1));
            strcpy(A->data[A->capacity - 1], string);
            A->first = A->capacity - 1;
            da_free(aux);
        }
        else {
            A->data[A->capacity - 1] = (char *) malloc(sizeof(char) * (strlen(string) + 1));
            strcpy(A->data[A->capacity - 1], string);
            A->first = A->capacity - 1;
        }
    }
    else {
        if (A->size == A->capacity) {
            darray *aux = da_alloc(2 * A->capacity);
            if (!aux)
                return 0;
            aux->first = 0;
            aux->size = A->size;
            aux->min_cap = A->min_cap;
            for (i = 0; i < A->size; i++) {
                if (A->first + i >= A->capacity) {
                    aux->data[i] = (char *) malloc(
                            sizeof(A->data[A->first + i - A->capacity]));
                    aux->data[i] = A->data[A->first + i - A->capacity];
                }
                else {
                    aux->data[i] = (char *) malloc(sizeof(A->data[A->first + i]));
                    aux->data[i] = A->data[A->first + i];
                }
            }
            da_free(A);
            A = da_alloc(aux->capacity);
            if (!A)
                return 0;
            A->first = aux->first;
            A->size = aux->size;
            A->min_cap = aux->min_cap;
            for (i = 0; i < A->size; i++) {
                A->data[i] = (char *) malloc(sizeof(aux->data[i]));
                A->data[i] = aux->data[i];
            }
            A->data[A->capacity - 1] = (char *) malloc(sizeof(char) * (strlen(string) + 1));
            strcpy(A->data[A->capacity - 1], string);
            A->first = A->capacity - 1;
            da_free(aux);
        }
        else {
            A->data[A->first - 1] = (char *) malloc(sizeof(char) * (strlen(string) + 1));
            strcpy(A->data[A->first - 1], string);
            A->first--;
        }
    }

    A->size++;

    return 1;
}

int da_is_empty(darray* A) {
    if (!A->size)
        return 1;
    else
        return 0;
}

char* da_first(darray* A) {
    if (A->size != 0)
        return (char *) A->data[A->first];
    return NULL;
}

char* da_last(darray* A) {
    if (A->size != 0 && (A->first + A->size <= A->capacity))
        return (char *) A->data[A->first + A->size - 1];
    if (A->size != 0 && (A->first + A->size > A->capacity))
        return (char *) A->data[A->first + A->size - A->capacity - 1];
    return NULL;
}

int da_push(darray* A, char* string) {
    int i;

    if (A->first == 0) {
        if (A->size == A->capacity) {
            darray *aux = da_alloc(2 * A->capacity);
            if (!aux)
                return 0;
            aux->first = A->first;
            aux->size = A->size;
            aux->min_cap = A->min_cap;
            for (i = 0; i < A->size; i++) {
                aux->data[i] = (char *) malloc(sizeof(A->data[i]));
                aux->data[i] = A->data[i];
            }
            da_free(A);
            A = da_alloc(aux->capacity);
            if (!A)
                return 0;
            A->first = aux->first;
            A->size = aux->size;
            A->min_cap = aux->min_cap;
            for (i = 0; i < A->size; i++) {
                A->data[i] = (char *) malloc(sizeof(aux->data[i]));
                A->data[i] = aux->data[i];
            }
            A->data[i] = (char *) malloc(sizeof(char) * (strlen(string) + 1));
            strcpy(A->data[i], string);
            da_free(aux);
        }
        else {
            A->data[A->first + A->size] = (char *) malloc(sizeof(char) * (strlen(string) + 1));
            strcpy(A->data[A->first + A->size], string);
        }
    }
    else {
        if (A->size == A->capacity) {
            darray *aux = da_alloc(2 * A->capacity);
            if (!aux)
                return 0;
            aux->first = 0;
            aux->size = A->size;
            aux->min_cap = A->min_cap;
            for (i = 0; i < A->size; i++) {
                if (A->first + i >= A->capacity) {
                    aux->data[i] = (char *) malloc(
                            sizeof(A->data[A->first + i - A->capacity]));
                    aux->data[i] = A->data[A->first + i - A->capacity];
                }
                else {
                    aux->data[i] = (char *) malloc(sizeof(char) * (strlen(string) + 1));
                    aux->data[i] = A->data[A->first + i];
                }
            }
            da_free(A);
            A = da_alloc(aux->capacity);
            if (!A)
                return 0;
            A->first = aux->first;
            A->size = aux->size;
            A->min_cap = aux->min_cap;
            for (i = 0; i < A->size; i++) {
                A->data[i] = (char *) malloc(sizeof(aux->data[i]));
                A->data[i] = aux->data[i];
            }
            A->data[i] = (char *) malloc(sizeof(char) * (strlen(string) + 1));
            strcpy(A->data[i], string);
            da_free(aux);
        }
        else {
            if (A->first + A->size >= A->capacity) {
                A->data[A->first + A->size - A->capacity] = (char *) malloc(sizeof(char) * (strlen(string) + 1));
                strcpy(A->data[A->first + A->size - A->capacity], string);
            }
            else {
                A->data[A->first + A->size] = (char *) malloc(sizeof(char) * (strlen(string) + 1));
                strcpy(A->data[A->first + A->size], string);
            }
        }
    }

    A->size++;

    return 1;
}

char* da_pop(darray* A) {
    int i;

    if (A->first == 0) {
        if (A->size - 1 <= A->capacity / 4 && A->capacity != A->min_cap) {
            darray *aux = da_alloc(A->capacity / 2);
            aux->first = A->first;
            aux->size = A->size;
            aux->min_cap = A->min_cap;
            for (i = 0; i < A->size; i++) {
                aux->data[i] = (char *) malloc(sizeof(A->data[i]));
                aux->data[i] = A->data[i];
            }
            da_free(A);
            A = da_alloc(aux->capacity);
            if (!A)
                return 0;
            A->first = aux->first;
            A->size = aux->size;
            A->min_cap = aux->min_cap;
            for (i = 0; i < A->size; i++) {
                A->data[i] = (char *) malloc(sizeof(aux->data[i]));
                A->data[i] = aux->data[i];
            }
            da_free(aux);
            A->size--;
            return A->data[A->size];
        }
        else {
            A->size--;
            return A->data[A->size];
        }
    }
    else {
        if (A->size - 1 <= A->capacity / 4 && A->capacity != A->min_cap) {
            darray *aux = da_alloc(A->capacity / 2);
            aux->first = 0;
            aux->size = A->size;
            aux->min_cap = A->min_cap;
            for (i = 0; i < A->size; i++) {
                if (A->first + i >= A->capacity) {
                    aux->data[i] = (char *) malloc(sizeof(A->data[A->first + i - A->capacity]));
                    aux->data[i] = A->data[A->first + i - A->capacity];
                }
                else {
                    aux->data[i] = (char *) malloc(sizeof(A->data[A->first + i]));
                    aux->data[i] = A->data[A->first + i];
                }
            }
            da_free(A);
            A = da_alloc(aux->capacity);
            if (!A)
                return 0;
            A->first = aux->first;
            A->size = aux->size;
            A->min_cap = aux->min_cap;
            for (i = 0; i < A->size; i++) {
                A->data[i] = (char *) malloc(sizeof(aux->data[i]));
                A->data[i] = aux->data[i];
            }
            da_free(aux);
            A->size--;
            return A->data[A->size];
        } else {
            A->size--;
            if (A->first + A->size >= A->capacity)
                return A->data[A->first + A->size - A->capacity];
            else
                return A->data[A->first + A->size];
        }
    }
}

char* da_eject(darray* A) {
    int i;

    if (A->first == 0) {
        if (A->size - 1 <= A->capacity / 4 && A->capacity != A->min_cap) {
            darray *aux = da_alloc(A->capacity / 2);
            aux->first = A->first;
            aux->size = A->size;
            aux->min_cap = A->min_cap;
            for (i = 0; i < A->size; i++) {
                aux->data[i] = (char *) malloc(sizeof(A->data[i]));
                aux->data[i] = A->data[i];
            }
            da_free(A);
            A = da_alloc(aux->capacity);
            if (!A)
                return 0;
            A->first = aux->first;
            A->size = aux->size;
            A->min_cap = aux->min_cap;
            for (i = 0; i < A->size; i++) {
                A->data[i] = (char *) malloc(sizeof(aux->data[i]));
                A->data[i] = aux->data[i];
            }
            da_free(aux);
            A->size--;
            A->first++;
            return A->data[0];
        }
        else {
            A->size--;
            A->first++;
            return A->data[0];
        }
    }
    else {
        if (A->size - 1 <= A->capacity / 4 && A->capacity != A->min_cap) {
            darray *aux = da_alloc(A->capacity / 2);
            aux->first = 0;
            aux->size = A->size;
            aux->min_cap = A->min_cap;
            for (i = 0; i < A->size; i++) {
                if (A->first + i >= A->capacity) {
                    aux->data[i] = (char *) malloc(sizeof(A->data[A->first + i - A->capacity]));
                    aux->data[i] = A->data[A->first + i - A->capacity];
                }
                else {
                    aux->data[i] = (char *) malloc(sizeof(A->data[A->first + i]));
                    aux->data[i] = A->data[A->first + i];
                }
            }
            da_free(A);
            A = da_alloc(aux->capacity);
            if (!A)
                return 0;
            A->first = aux->first;
            A->size = aux->size;
            A->min_cap = aux->min_cap;
            for (i = 0; i < A->size; i++) {
                A->data[i] = (char *) malloc(sizeof(aux->data[i]));
                A->data[i] = aux->data[i];
            }
            da_free(aux);
            A->size--;
            A->first++;
            return A->data[A->first - 1];
        } else {
            A->size--;
            if (A->first == A->capacity - 1) {
                A->first = 0;
                return A->data[A->capacity - 1];
            }
            else {
                A->first++;
                return A->data[A->first - 1];
            }
        }
    }
}