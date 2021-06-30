#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

/*
 * Frees all the tree's nodes
 */
void free_nodes(node* p) {

    if (p == NULL)
        return;

    free_nodes(p->left);
    free_nodes(p->right);
    free(p);
}

/*
 * Frees all the tree's nodes and the tree itself.
 */
void bst_free(tree* T) {
    free_nodes(T->root);
    free(T);
}

/*
 * If the pointer is equal to NULL it allocates a tree, otherwise it frees the current
 * tree and nodes that belong to it and allocates a new tree with no nodes.
 * Returns a pointer to the tree allocated. In case of memory allocation failure returns NULL.
 */
tree *create(tree *T) {
    if (T != NULL) {
        bst_free(T);
    }

    T = (tree *) calloc(1, sizeof(tree));
    if (T == NULL)
        return NULL;

    T->root = NULL;

    return T;
}

/*
 * Searches for a key in the tree nodes.
 * In case it founds a node containing the key, it returns a pointer to this node,
 * otherwise it returns NULL.
 */
node *search(node *p, int number) {

    if (p == NULL)
        return NULL;

    if (p->key == number)
        return p;

    if (p->key < number)
        return search(p->right, number);
    else
        return search(p->left, number);
}

/*
 * Inserts a key into the BST. Returns 1 on success.
 * In case of memory insuficiency, returns 0.
 * In case the key already exists in the tree, it doesn't insert another key and returns 1.
 */
int insert(tree *T, int data) {
    node* n = calloc(1,sizeof(node));
    if (!n) {
        return 0;
    }

    n->key = data;

    if (T->root == NULL) {
        n->parent = NULL;
        T->root = n;
        return 1;
    }

    if (search(T->root, data) != NULL)
        return 1;

    node* p = T->root;
    node* pp = NULL;

    while (p != NULL) {
        if (p->key == data)
            return 1;
        pp = p;
        if (p->key > data)
            p = p->left;
        else
            p = p->right;
    }


    if (pp->key > data)
        pp->left = n;
    else
        pp->right = n;

    n->parent = pp;

    return 1;
}

/*
 * Prints the keys in the order they are visited by a pre-order deep path.
 */
void pre_order_print(node *n) {
    if (n != NULL) {
        printf("%d ", n->key);
        pre_order_print(n->left);
        pre_order_print(n->right);
    }
}

/*
 * Prints the keys in the order they are visited by a pre-order deep path.
 * In case there are no keys, it prints "arvore vazia".
 */
void pre_order(tree *T) {
    if (T->root == NULL) {
        printf("arvore vazia\n");
        return ;
    }

    printf("pre-ordem: ");
    pre_order_print(T->root);
    printf("\n");
}

/*
 * Prints the keys in the order they are visited by a in-order deep path.
 */
void in_order_print(node *n) {
    if (n != NULL) {
        in_order_print(n->left);
        printf("%d ", n->key);
        in_order_print(n->right);
    }
}

/*
 * Prints the keys in the order they are visited by a in-order deep path.
 * In case there are no keys, it prints "arvore vazia".
 */
void in_order(tree *T) {
    if (T->root == NULL) {
        printf("arvore vazia\n");
        return ;
    }

    printf("em-ordem: ");
    in_order_print(T->root);
    printf("\n");
}

/*
 * Prints the keys in the order they are visited by a post-order deep path.
 */
void post_order_print(node *n) {
    if (n != NULL) {
        post_order_print(n->left);
        post_order_print(n->right);
        printf("%d ", n->key);
    }
}

/*
 * Prints the keys in the order they are visited by a post-order deep path.
 * In case there are no keys, it prints "arvore vazia".
 */
void post_order(tree *T) {
    if (T->root == NULL) {
        printf("arvore vazia\n");
        return ;
    }

    printf("pos-ordem: ");
    post_order_print(T->root);
    printf("\n");
}

/*
 * Returns the minimum key of a tree.
 * In case the tree is empty it returns 0.
 */
node *minimum(node *n) {
    if (n == NULL) {
        return NULL;
    }

    while (n->left != NULL)
        n = n->left;

    return n;
}

/*
 * Returns the successor of a key in the BST.
 * In case there is no successor or this key in the BST it returns 0.
 */
node *successor(tree *T, int key) {
    if (T->root == NULL)
        return NULL;

    node *p;
    node *n;
    n = search(T->root, key);
    if (n == NULL)
        return NULL;
    if (n->right != NULL)
        return minimum(n->right);
    p = n->parent;
    while (p != NULL && n == p->right) {
        n = p;
        p = p->parent;
    }

    if (!p)
        return NULL;

    return p;
}

/*
 * Returns the maximum key of a tree.
 * In case the tree is empty it returns 0.
 */
node *maximum(node *n) {
    if (n == NULL) {
        return 0;
    }

    while (n->right)
        n = n->right;

    return n;
}

/*
 * Returns the predecessor of a key in the BST.
 * In case there is no predecessor or this key in the BST it returns 0.
 */
node *predecessor(tree *T, int key) {
    if (!T->root)
        return 0;

    node *p;
    node *n;
    n = search(T->root, key);
    if (!n)
        return 0;
    if (n->left)
        return maximum(n->left);
    p = n->parent;
    while (p != NULL && n == p->left) {
        n = p;
        p = p->parent;
    }

    if (!p)
        return 0;

    return p;
}

/*
 * Removes a node from the BST and places its successor in that position instead.
 * In case there is no node with the referred key in the BST, keeps running the program.
 */
void delete(tree *T, int key) {
    node *n;
    n = search(T->root, key);

    if (!n)
        return ;

    if (!n->right && !n->left) {
        if (n == T->root) {
            T->root = NULL;
            free(n);
            return ;
        }
        if (n == n->parent->left)
            n->parent->left = NULL;
        if (n == n->parent->right)
            n->parent->right = NULL;
        free(n);
        return ;
    }

    if (n->right && !n->left) {
        if (n == T->root) {
            T->root = n->right;
            n->right->parent = NULL;
            free(n);
            return ;
        }
        if (n == n->parent->right) {
            n->parent->right = n->right;
            n->right->parent = n->parent;
            free(n);
            return ;
        }
        if (n == n->parent->left) {
            n->parent->left = n->right;
            n->right->parent = n->parent;
            free(n);
            return ;
        }
    }

    if (n->left && !n->right) {
        if (n == T->root) {
            T->root = n->left;
            n->left->parent = NULL;
            free(n);
            return ;
        }
        if (n == n->parent->right) {
            n->parent->right = n->left;
            n->left->parent = n->parent;
            free(n);
            return ;
        }
        if (n == n->parent->left) {
            n->parent->left = n->left;
            n->left->parent = n->parent;
            free(n);
            return ;
        }
    }

    if (n->right && n->left) {
        node *y = successor(T, key);
        n->key = y->key;
        if (y == n->right) {
            n->right = y->right;
            if (y->right)
                y->right->parent = n;
            free(y);
            return ;
        }
        if (!y->right) {
            y->parent->left = NULL;
        }
        else {
            y->parent->left = y->right;
            y->right->parent = y->parent;
        }
        free(y);
        return ;
    }
}

/*
 * Returns the height of a tree or sub-tree.
 */
int height(node *n) {
    if (n == NULL)
        return 0;

    int left_height = 1;
    int right_height = 1;

    left_height = left_height + height(n->left);
    right_height = right_height + height(n->right);

    if (left_height > right_height)
        return left_height;
    else
        return right_height;

}

/*
 * Returns the number of nodes within a tree or sub-tree.
 */
int nodes_number(node *n) {
    if (n == NULL)
        return 0;

    int count = 1;

    count = count + nodes_number(n->left);
    count = count + nodes_number(n->right);

    return count;
}

/*
 * Returns the number of leaves within a tree.
 */
int leaves_number(node *n) {
    if (n == NULL)
        return 0;

    if (n->left == NULL && n->right == NULL)
        return 1;

    int leaves;
    leaves = leaves_number(n->left) + leaves_number(n->right);

    return leaves;
}

/*
 * Counts the balance factor of each node within the tree and sets the fb value with that count.
 */
void count_bf(node *n) {

    if (n == NULL)
        return ;

    n->bf = height(n->left) - height(n->right);
    count_bf(n->left);
    count_bf(n->right);
}

/*
 * Inspects every node's balance factor within the tree.
 * In case the tree is an AVL tree (for every node -2 < bf < 2) it returns 1.
 * Otherwise it returns 0.
 */
int is_avl(node *n) {
    int avl = 1;

    if (n == NULL)
        return 1;

    if (n->bf >= 2 || n->bf <= -2)
        return 0;
    if (n->left)
        avl = is_avl(n->left);
    if (avl && n->right)
        avl = is_avl(n->right);

    return avl;
}

/*
 * Prints each node that is part of the longest path from the tree's root to a leaf.
 * In cases of ties, it always gets the path that goes through the right child.
 */
void longest_path(node *n) {
    if (n == NULL)
        return ;

    printf("%d ", n->key);
    if (height(n->right) == height(n) - 1)
        longest_path(n->right);
    else
        longest_path(n->left);
}