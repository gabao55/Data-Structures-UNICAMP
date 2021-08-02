#include "dfs.h"
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

    G->print = (node_info *) calloc(size, sizeof(node_info));
    if (!G->print)
        return NULL;

    int i;
    for (i=0;i<size;i++) {
        G->list[i] = malloc(sizeof(node));
        G->list[i]->vertix = i+1;
        G->list[i]->next = NULL;
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
    free(G->print);
    free(G);
}

/*
 * This function inserts an edge into the list representation of a graph.
 * In case of memory allocation failure, returns 0, otherwise returns 1.
 */
int vertix_insert(graph *G, int first, int second) {
    node *n;

    n = G->list[first - 1];
    while (n->next)
        n = n->next;
    n->next = malloc(sizeof(node));
    n->next->vertix = second;
    n->next->next = NULL;

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
        if (!n->next) {
            printf("%d -> NULL\n", i+1);
        }
        else {
            printf("%d", n->vertix);
            n = n->next;
            while (n->next) {
                printf(" -> %d",n->vertix);
                n = n->next;
            }
            printf(" -> %d\n", n->vertix);
        }
    }
}

/*
 * This function initializes every node_info in the graph, setting it's color as white (0).
 * then it starts walking through all nodes of the graph. If the node's color is white,
 * it calls the function dfs_visit.
 */
void dfs(graph *G, queue *Q) {
    int i;
    node *n;
    for (i=0;i<G->vertices;i++) {
        G->print[i].color = 0;
    }

    G->time = 0;
    for (i=0;i<G->vertices;i++) {
        n = G->list[i];
        while (n->next) {
            if (G->print[n->vertix-1].color == 0)
                dfs_visit(G, n, Q);
            n=n->next;
        }
        if (G->print[n->vertix-1].color == 0)
            dfs_visit(G, n, Q);
    }
}

/*
 * This function pushes all white nodes to a queue, increases the time, sets the node's discovery
 * time on the respective node_info and sets it's color as grey (1). Then, the function starts
 * visiting the node's neighbourhood, in case any node is white, it calls recursively the
 * dfs_visit function, otherwise it increases the time again, sets the node's finish time
 * on the respective node_info and sets it's color as black (2).
 * The function also checks during iterations if the graph is cyclic or not.
 * In case it is cyclic, the function sets the graph's cyclic variable as 1, otherwise it sets as 0.
 */
void dfs_visit(graph *G, node *n, queue *Q) {
    G->time++;
    G->print[n->vertix-1].start_time = G->time;
    G->print[n->vertix-1].color++;
    G->print[n->vertix-1].vertix = n->vertix;
    Q->item[Q->position] = &G->print[n->vertix-1];
    Q->position++;
    node *beginning=n;
    while (n->next) {
        n = n->next;
        if (G->print[n->vertix-1].color == 1)
            G->cyclic = 1;
        if (G->print[n->vertix-1].color == 0) {
            dfs_visit(G, G->list[n->vertix-1], Q);
        }
    }

    if (G->print[n->vertix-1].color == 0) {
        dfs_visit(G, n, Q);
    }

    G->print[beginning->vertix-1].color++;
    G->time++;
    G->print[beginning->vertix-1].end_time = G->time;
}