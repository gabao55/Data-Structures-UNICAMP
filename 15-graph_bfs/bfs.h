#ifndef INC_15_BREATH_FIRST_SEARCH_GRAPHS_BFS_H
#define INC_15_BREATH_FIRST_SEARCH_GRAPHS_BFS_H

typedef struct node {
    int vertix;
    struct node *next;
    int distance;
    struct node *predecessor;
    int marked;
} node;

typedef struct graph {
    int vertices;
    node **list;
} graph;

typedef struct queue {
    int *list;
    int first;
    int last;
}queue;

/*
 * This functions allocs a graph and returns a pointer to it.
 * In case of memory allocation failure, returns NULL.
 */
graph *graph_alloc(int size);

/*
 * This functions frees all graph's list of vertices and the vertices.
 */
void graph_free(graph *G);

/*
 * This function inserts an edge into the list representation of a graph.
 * In case of memory allocation failure, returns 0, otherwise returns 1.
 */
int vertix_insert(graph *G, int first, int second);

/*
 * This function prints the adjacency list representation of a graph.
 */
void graph_print(graph *G);

/*
 * This function performs a Breadth First Search and prints the search's origin,
 * the vertices and the distance of the path from that vertix to the origin
 * in an ascending order.
 */
void bfs(graph *G, int origin);

#endif //INC_15_BREATH_FIRST_SEARCH_GRAPHS_BFS_H
