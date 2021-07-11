#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "li.h"


int main(void) {

    int i;

    li* A = li_alloc();
    if (A == NULL)
        exit(errno);

    // Load A:
    scanf("{");
    while (scanf("%d",&i) == 1) {
        int st = li_insert(A,i);
        if (!st) exit(errno);
        scanf(", ");
    }
    scanf("} ");


    li* B = li_alloc();
    if (B == NULL)
        exit(errno);

    // Load B:
    scanf("{");
    while (scanf("%d",&i) == 1) {
        int st = li_insert(B,i);
        if (!st) exit(errno);
        scanf(", ");
    }
    scanf("}");


    printf("A: ");
    li_print(A);
    printf("\n");

    printf("B: ");
    li_print(B);
    printf("\n");


    li* C;

    C = li_union(A,B);
    if (!C) exit(errno);

    printf("A u B: ");
    li_print(C);
    printf("\n");
    li_free(C);

    C = li_intersection(A,B);
    if (!C) exit(errno);

    printf("A i B: ");
    li_print(C);
    printf("\n");
    li_free(C);

    C = li_difference(A,B);
    if (!C) exit(errno);

    printf("A - B: ");
    li_print(C);
    printf("\n");
    li_free(C);

    C = li_difference(B,A);
    if (!C) exit(errno);

    printf("B - A: ");
    li_print(C);
    printf("\n");
    li_free(C);

    li_free(A);
    li_free(B);

    return 1;
}
