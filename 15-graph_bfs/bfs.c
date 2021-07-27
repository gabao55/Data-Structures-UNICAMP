#include "bfs.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * This functions allocs a graph and returns a pointer to it.
 * In case of memory allocation failure, returns NULL.
 */
graph *graph_alloc(int size) {
    graph *G = (graph *) calloc(1, sizeof(graph));
    if (!G)
        return NULL;

    G->vertices = size;
    G->list = (node **) calloc(size, sizeof(node *));
    if (!G->list)
        return NULL;

    int i;
    for (i=0;i<size;i++) {
        G->list[i] = NULL;
    }

    return G;
}

/*
 * This functions frees all graph's list of vertices and the vertices.
 */
void graph_free(graph *G) {
    int i;
    node *n, *next;
    for (i=0;i<G->vertices;i++) {
        if (G->list[i]) {
            n = G->list[i];
            while (n->next){
                next = n->next;
                free(n);
                n = next;
            }
            free(n);
        }
    }
    free(G->list);
    free(G);
}

/*
 * This function inserts an edge into the list representation of a graph.
 * In case of memory allocation failure, returns 0, otherwise returns 1.
 */
int vertix_insert(graph *G, int first, int second) {
    node *n;

    n = G->list[first - 1];
    if (G->list[first - 1] == NULL) {
        G->list[first - 1] = malloc(sizeof(node));
        if (!G->list[first - 1])
            return 0;
        G->list[first - 1]->vertix = second;
        G->list[first - 1]->next = NULL;
    }
    else {
        while (n->next)
            n = n->next;
        n->next = malloc(sizeof(node));
        n->next->vertix = second;
        n->next->next = NULL;
    }

    n = G->list[second - 1];
    if (G->list[second - 1] == NULL) {
        G->list[second - 1] = malloc(sizeof(node));
        if (!G->list[second - 1])
            return 0;
        G->list[second - 1]->vertix = first;
        G->list[second - 1]->next = NULL;
    }
    else {
        while (n->next)
            n = n->next;
        n->next = malloc(sizeof(node));
        n->next->vertix = first;
        n->next->next = NULL;
    }

    return 1;
}

/*
 * This function prints the adjacency list representation of a graph.
 */
void graph_print(graph *G) {
    int i;
    node *n;
    printf("Adjacency list representation:\n");
    for (i=0;i<G->vertices;i++) {
        n = G->list[i];
        if (!n) {
            printf("%d -> NULL\n", i+1);
        }
        else {
            printf("%d", i+1);
            while (n->next) {
                printf(" -> %d",n->vertix);
                n = n->next;
            }
            printf(" -> %d\n", n->vertix);
        }
    }
}

/*
 * This function performs a Breadth First Search and prints the search's origin,
 * the vertices and the distance of the path from that vertix to the origin
 * in an ascending order.
 */
void bfs(graph *G, int origin) {
    queue Q;
    int i;

    Q.list = malloc(G->vertices * sizeof(int));
    Q.first = 0;
    Q.last = 0;

    node *n;
    for (i=0;i<G->vertices;i++) {
        if (G->list[i]) {
            n = G->list[i];
            while (n->next){
                n->distance = G->vertices + 1;
                n->predecessor = NULL;
                n->marked = 0;
                n = n->next;
            }
            n->distance = G->vertices + 1;
            n->predecessor = NULL;
            n->marked = 0;
        }
    }

    G->list[origin - 1]->distance = 0;
    G->list[origin - 1]->marked = 1;
    Q.list[Q.last] = origin;
    Q.last++;
    node *u, *v;
    printf("Origem da busca: %d\n", origin);
    printf("Vertices alcancados e distancias:\n");
    while (Q.last - Q.first > 0) {
        u = G->list[Q.list[Q.first] - 1];
        u->marked = 1;
        printf("%d %d\n", Q.list[Q.first], u->distance);
        Q.first++;
        while (u->next) {
            u->next->distance = u->distance;
            v = G->list[u->vertix - 1];
            if (v->marked == 0) {
                v->distance = u->distance + 1;
                v->predecessor = u;
                Q.list[Q.last] = u->vertix;
                Q.last++;
                v->marked = 1;
            }
            u = u->next;
        }
        v = G->list[u->vertix - 1];
        if (v->marked == 0) {
            v->distance = u->distance + 1;
            v->predecessor = u;
            Q.list[Q.last] = u->vertix;
            Q.last++;
            v->marked = 1;
        }
    }
}