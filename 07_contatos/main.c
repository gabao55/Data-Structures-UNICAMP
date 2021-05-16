#include <stdio.h>
#include <string.h>

struct contacts{
    int id;
    char name[51];
    char address[101];
    char phone[13];
    char birthday[9];
};

// This function inserts data into the struct contacts called list (limit of 1000 contacts):
int insert(struct contacts *p, int *index) {

    char fake_info[101];

    if (*index < 1000) {
        scanf(" %[^\n]s", (*p).name);
        scanf(" %[^\n]", (*p).address);
        scanf(" %[^\n]", (*p).phone);
        scanf(" %[^\n]", (*p).birthday);
        *index = *index + 1;
        (*p).id = *index;
        printf("Contato para %s inserido.\n\n", (*p).name);
    }
    else {
        scanf(" %[^\n]s", fake_info);
        scanf(" %[^\n]s", fake_info);
        scanf(" %[^\n]s", fake_info);
        scanf(" %[^\n]s", fake_info);
        printf("O contato nao foi inserido.\n\n");
    }

    return 1;
}

/* This function removes all the contacts that correspond to the inputed name
 * of the struct contacts called list and prints how many were contacts were deleted:
 * */
int remove_contact(struct contacts *p, int *index) {
    int i, removed = 0;
    char key[51];

    scanf(" %[^\n]s", key);

    for ( i = 0 ; i < *index ; i++ ) {
        while (!strcmp(p[i].name, key) && i < *index) {
            removed++;
            i++;
        }
        if (removed > 0 && i < *index) {
            strcpy(p[i-removed].name, p[i].name);
            strcpy(p[i-removed].address, p[i].address);
            strcpy(p[i-removed].phone, p[i].phone);
            strcpy(p[i-removed].birthday, p[i].birthday);
        }
    }

    *index = *index - removed;

    printf("Contatos de %s removidos: %d.\n\n", key, removed);

    return 1;
}

/* This function prints all the contacts that correspond to the searched name
 * of the struct contacts called list:
 * */
int search(struct contacts *p, int index) {
    int i, found = 0;
    char key[51];

    scanf(" %[^\n]s", key);

    printf("Resultado da busca:\n");

    for ( i = 0 ; i < index ; i++ ) {
        if (strstr(p[i].name, key)) {
            printf("(%d) %s\t%s\t%s\t%s\n", i+1, p[i].name, p[i].address, p[i].phone, p[i].birthday);
            found = 1;
        }
    }

    if (!found)
        printf("Nenhum contato.\n");

    printf("\n");

    return 1;
}

// This function prints all the contacts of the struct contacts called list:
int print(struct contacts *p, int index) {
    int i;

    printf("Listagem:\n");

    if (index > 0) {
        for ( i = 0 ; i < index ; i++ )
            printf("(%d) %s\t%s\t%s\t%s\n", i+1, p[i].name, p[i].address, p[i].phone, p[i].birthday);
    }
    else
        printf("Nenhum contato.\n");

    printf("\n");

    return 1;
}

int main() {

     struct contacts list[1000];

     int id = 0;
     char command;

     do {
         scanf("%c", &command);
         if (command == 'i')
             insert(&list[id], &id);

         if (command == 'r')
             remove_contact(list, &id);

         if (command == 'b')
             search(list, id);

         if (command == 'p')
             print(list, id);

     } while (command != 'f');

     return 1;
}
