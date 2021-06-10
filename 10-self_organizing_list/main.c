#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "auto.h"

int main() {
    int N, R, i, value, check;

    // Receiving parameters:
    scanf("%d", &N);
    scanf("%d", &R);

    int consult[R];
    for (i = 0; i < R; i++)
        scanf(" %d", &consult[i]);

    list *current_list = list_alloc();
    if (!current_list)
        exit(errno);

    // Generating the list:
    for (i = 1; i <= N; i++) {
        check = list_push(current_list, i);
        if (!check)
            exit(errno);
    }

    value = MTF(current_list, consult, R);
    printf("MTF: %d\n", value);

    list_reset(current_list, N);

    value = transpose(current_list, consult, R);
    printf("Transpose: %d\n", value);

    list_reset(current_list, N);

    value = count(current_list, consult, R);
    printf("Count: %d\n", value);

    return 1;
}
