#ifndef INC_15_BREATH_FIRST_SEARCH_GRAPHS_BFS_H
#define INC_15_BREATH_FIRST_SEARCH_GRAPHS_BFS_H

typedef struct node {
    int vertix;
    struct node *next;
} node;

typedef struct node_info {
    int color; // 0 = white, 1 = grey, 2 = black
    int start_time;
    int end_time;
    int vertix;
} node_info;

typedef struct graph {
    int vertices;
    int time;
    int cyclic;
    node **list;
    node_info *print;
} graph;

typedef struct queue {
    node_info **item;
    int position;
} queue;

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
 * This function initializes every node_info in the graph, setting it's color as white (0).
 * then it starts walking through all nodes of the graph. If the node's color is white,
 * it calls the function dfs_visit.
 */
void dfs(graph *G, queue *Q);

/*
 * This function pushes all white nodes to a queue, increases the time, sets the node's discovery
 * time on the respective node_info and sets it's color as grey (1). Then, the function starts
 * visiting the node's neighbourhood, in case any node is white, it calls recursively the
 * dfs_visit function, otherwise it increases the time again, sets the node's finish time
 * on the respective node_info and sets it's color as black (2).
 * The function also checks during iterations if the graph is cyclic or not.
 * In case it is cyclic, the function sets the graph's cyclic variable as 1, otherwise it sets as 0.
 */
void dfs_visit(graph *G, node *n, queue *Q);

#endif //INC_15_BREATH_FIRST_SEARCH_GRAPHS_BFS_H
