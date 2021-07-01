#include <stdio.h>
#include <stdlib.h>

#ifndef INC_12_AVL_TREE_AVL_H
#define INC_12_AVL_TREE_AVL_H

typedef struct node {
    int key;
    int bf;
    struct node *parent; // ascendent in the tree
    struct node *left; // left descendent in the tree
    struct node *right; // right descendente in the tree
} node;

typedef struct tree {
    node *root;
} tree;

/*
 * Frees all the tree's nodes.
 */
void free_nodes(node* p);

/*
 * Frees all the tree's nodes and the tree itself.
 */
void bst_free(tree* T);

/*
 * If the pointer is equal to NULL it allocates a tree, otherwise it frees the current
 * tree and nodes that belong to it and allocates a new tree with no nodes.
 * Returns a pointer to the tree allocated. In case of fail returns NULL.
 */
tree *create(tree *T);

/*
 * Searches for a key in the tree nodes.
 * In case it founds a node containing the key, it returns a pointer to this node,
 * otherwise it returns NULL.
 */
node *search(node *p, int number);

/*
 * Inserts a key into the BST. Returns 1 on success.
 * In case of memory insuficiency, returns 0.
 * In case the key already exists in the tree, it doesn't insert another key and returns 1.
 */
int insert(tree *T, int data);

/*
 * Prints the keys in the order they are visited by a pre-order deep path.
 */
void pre_order_print(node *n);

/*
 * Prints the keys in the order they are visited by a pre-order deep path.
 * In case there are no keys, it prints "arvore vazia".
 */
void pre_order(tree *T);

/*
 * Prints the keys in the order they are visited by a in-order deep path.
 */
void in_order_print(node *n);

/*
 * Prints the keys in the order they are visited by a in-order deep path.
 * In case there are no keys, it prints "arvore vazia".
 */
void in_order(tree *T);

/*
 * Prints the keys in the order they are visited by a post-order deep path.
 */
void post_order_print(node *n);

/*
 * Prints the keys in the order they are visited by a post-order deep path.
 * In case there are no keys, it prints "arvore vazia".
 */
void post_order(tree *T);

/*
 * Returns the node that contains the minimum key of a tree.
 * In case the tree is empty it returns 0.
 */
node *minimum(node *n);

/*
 * Returns the successor of a key in the BST.
 * In case there is no successor or this key in the BST it returns 0.
 */
node *successor(tree *T, int key);

/*
 * Returns the maximum key of a tree.
 * In case the tree is empty it returns 0.
 */
node *maximum(node *n);

/*
 * Returns the predecessor of a key in the BST.
 * In case there is no predecessor or this key in the BST it returns 0.
 */
node *predecessor(tree *T, int key);

/*
 * Removes a node from the BST and places its successor in that position instead.
 * In case there is no node with the referred key in the BST, keeps running the program.
 */
void delete(tree *T, int key);

/*
 * Returns the height of a tree or sub-tree.
 */
int height(node *n);

/*
 * Returns the number of nodes within a tree or sub-tree.
 */
int nodes_number(node *n);

/*
 * Returns the number of leaves within a tree.
 */
int leaves_number(node *n);

/*
 * Counts the balance factor of each node within the tree and sets the fb value with that count.
 */
void count_bf(node *n);

/*
 * Inspects every node's balance factor within the tree.
 * In case the tree is an AVL tree (for every node -2 < bf < 2) it prints "sim".
 * Otherwise it prints "nao".
 */
int is_avl(node *n);

/*
 * Prints each node that is part of the longest path from the tree's root to a leaf.
 * In cases of ties, it always gets the path that goes through the right child.
 */
void longest_path(node *n);

#endif //INC_12_AVL_TREE_AVL_H
