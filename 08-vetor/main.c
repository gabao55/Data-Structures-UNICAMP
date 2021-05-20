#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "darray.h"

ssize_t getdelim(char **linep, size_t *n, int delim, FILE *fp)
{
    int ch;
    size_t i = 0;
    if (!linep || !n || !fp)
    {
        errno = EINVAL;
        return -1;
    }
    if (*linep == NULL)
    {
        if (NULL == (*linep = malloc(*n = 128)))
        {
            *n = 0;
            errno = ENOMEM;
            return -1;
        }
    }
    while ((ch = fgetc(fp)) != EOF)
    {
        if (i + 1 >= *n)
        {
            char *temp = realloc(*linep, *n + 128);
            if (!temp)
            {
                errno = ENOMEM;
                return -1;
            }
            *n += 128;
            *linep = temp;
        }
        (*linep)[i++] = ch;
        if (ch == delim)
            break;
    }
    (*linep)[i] = '\0';
    return !i && ch == EOF ? -1 : i;
}

ssize_t getline(char **linep, size_t *n, FILE *fp)
{
    return getdelim(linep, n, '\n', fp);
}

int main(void) {

    char cmd[10];
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    darray *D = da_alloc(2);
    if (!D) {
        printf("Unable to allocate D.\n");
        exit(1);
    }

    while (1) {
        scanf("%s%*c", cmd);

        if (strcmp(cmd, "push") == 0) {
            read = getline(&line, &len, stdin);
            if (read == -1) {
                perror("getline at push");
                exit(errno);
            }
            line[read - 1] = '\0';

            int st = da_push(D, line);
            if (!st) {
                printf("Unable to resize at push.\n");
                exit(1);
            }
        }
        else if (strcmp(cmd, "pop") == 0) {
            if (!da_is_empty(D)) {
                char *str = da_pop(D);
                free(str);
            }
        }
        else if (strcmp(cmd, "inject") == 0) {
            read = getline(&line, &len, stdin);
            if (read == -1) {
                perror("read at inject");
                exit(errno);
            }
            line[read - 1] = '\0';

            int st = da_inject(D, line);
            if (!st) {
                printf("Unable to resize at inject.\n");
                exit(1);
            }
        }
        else if (strcmp(cmd, "eject") == 0) {
            if (!da_is_empty(D)) {
                char *str = da_eject(D);
                free(str);
            }
        }
        else if (strcmp(cmd, "print-first") == 0) {
            if (!da_is_empty(D))
                printf("%s\n", da_first(D));
        } else if (strcmp(cmd, "print-last") == 0) {
            if (!da_is_empty(D))
                printf("%s\n", da_last(D));
        }
        else if (strcmp(cmd, "is-empty") == 0) {
            if (da_is_empty(D))
                printf("-yep\n");
            else
                printf("-nope\n");
        }
        else if (strcmp(cmd, "exit") == 0) {
            da_free(D);
            free(line);
            return 0;
        }
        else {
            printf("Ups, invalid command %s\n", cmd);
            exit(1);
        }
    }
}
