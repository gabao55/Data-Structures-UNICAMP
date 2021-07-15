#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "minimum_heap.h"

int main() {
    int n, k, c;
    char cmd;

    scanf("%d", &n);

    heap *hp = heap_alloc(n);
    if (!hp)
        exit(errno);

    scanf(" %c", &cmd);

    while (cmd != 't') {
        if (cmd == 'i') {
            scanf(" %d %d", &k, &c);
            heap_insert(hp, k, c);
        }

        if (cmd == 'd') {
            scanf(" %d %d", &k, &c);
            heap_reduce(hp, k, c);
        }

        if (cmd == 'm')
            heap_remove(hp);

        scanf(" %c", &cmd);
    }

    heap_free(hp);

    return 1;
}
