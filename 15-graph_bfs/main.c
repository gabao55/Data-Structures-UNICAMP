#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "bfs.h"

int main() {
    int vertices, first, second, origin;

    scanf("Vertices:\n %d", &vertices);
    graph *G = graph_alloc(vertices);
    if (!G)
        exit(errno);

    scanf(" Arestas:\n %d,%d", &first, &second);

    while (first != 0 && second != 0) {
        origin = vertix_insert(G, first, second);
        if (!origin)
            exit(errno);

        scanf(" %d,%d", &first, &second);
    }

    scanf(" Origem:\n%d", &origin);

    bfs(G, origin);

    graph_free(G);

    return 1;
}
