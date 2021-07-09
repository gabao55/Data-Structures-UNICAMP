#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "bst.h"
#define MAX 50

int main() {
    char cmd[MAX];
    int keep_running = 1;
    int number;
    tree *T = NULL;
    node *n;

    while (keep_running) {
        scanf("%s%*c", cmd);
        if (strcmp(cmd, "inserir") == 0 || strcmp(cmd, "remover") == 0 || strcmp(cmd, "buscar") == 0 ||
            strcmp(cmd, "sucessor") == 0 || strcmp(cmd, "predecessor") == 0)
            scanf(" %d", &number);

        if (strcmp(cmd, "criar") == 0) {
            T = create(T);
            if (!T)
                exit(errno);
        }

        if (strcmp(cmd, "buscar") == 0) {
            n = search(T->root, number);
            if (!n)
                printf("%d nao esta na arvore\n", number);
            else
                printf("%d esta na arvore\n", number);
        }

        if (strcmp(cmd, "inserir") == 0) {
            keep_running = insert(T, number);
            if (!keep_running) {
                printf("memoria insuficiente");
                keep_running = 1;
            }
        }

        if (strcmp(cmd, "pre-ordem") == 0)
            pre_order(T);

        if (strcmp(cmd, "em-ordem") == 0)
            in_order(T);

        if (strcmp(cmd, "pos-ordem") == 0)
            post_order(T);

        if (strcmp(cmd, "sucessor") == 0) {
            n = successor(T, number);
            if (!n)
                printf("nao ha sucessor de %d\n", number);
            else
                printf("sucessor de %d: %d\n", number, n->key);
        }

        if (strcmp(cmd, "predecessor") == 0) {
            n = predecessor(T, number);
            if (!n)
                printf("nao ha predecessor de %d\n", number);
            else
                printf("predecessor de %d: %d\n", number, n->key);
        }

        if (strcmp(cmd, "remover") == 0)
            delete(T, number);

        if (strcmp(cmd, "terminar") == 0) {
            bst_free(T);
            keep_running = 0;
        }
    }

    return 1;
}
