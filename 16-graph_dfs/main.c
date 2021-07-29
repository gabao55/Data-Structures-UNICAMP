#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "dfs.h"

int main() {
    int vertices, first, second, check, i;

    scanf("Vertices:\n %d", &vertices);
    graph *G = graph_alloc(vertices);
    if (!G)
        exit(errno);

    // Dynamically allocating the queue of vertices
    queue *Q = malloc(sizeof(queue));
    if (!Q)
        exit(errno);
    Q->item = malloc(G->vertices * sizeof(node_info *));
    if (!Q->item)
        exit(errno);
    Q->position = 0;

    scanf(" Arestas:\n %d,%d", &first, &second);

    while (first != 0 && second != 0) {
        check = vertix_insert(G, first, second);
        if (!check)
            exit(errno);

        scanf(" %d,%d", &first, &second);
    }

    dfs(G, Q);

    //Printing the output
    printf("Vertices e tempos:\n");
    for (i=0;i<G->vertices;i++) {
        printf("%d [%d,%d]\n", Q->item[i]->vertix, Q->item[i]->start_time, Q->item[i]->end_time);
    }
    printf("Grafo aciclico: ");
    if (G->cyclic == 0)
        printf("sim\n");
    else
        printf("nao\n");

    //Freeing all dynamic allocations of memory
    graph_free(G);
    free(Q->item);
    free(Q);

    return 1;
}
