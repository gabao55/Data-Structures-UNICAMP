#include <stdio.h>
#include <string.h>

// This function returns the max values of an integer vector with 26 elements:
int max(int V[26]) {
    int i, max = 0, max_index = 0;

    for ( i = 0 ; i < 26 ; i++ ) {
        if (V[i] > max) {
            max = V[i];
            max_index = i;
        }
    }

    return max_index;
}

int main() {
    char message[10001];
    int i, character, key;
    int occurrences[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,
                           0,0,0,0,0,0,0,0,0,0,0,0,0};

    scanf("%[^\n]s", message);

    for ( i = 0 ; i < strlen(message) ; i++ ) {
        if (message[i] >= 'a' && message[i] <= 'z')
            character = (int) message[i] - 97;
        else
            character = -1;

        if (character >= 0 && character < 26 )
            occurrences[character]++;
    }

    key = max(occurrences) + 1;

    for ( i = 0 ; i < strlen(message) ; i++ ) {
        if (message[i] == ' ')
            printf(" ");
        else {
            if (key == 1) {
                if (message[i] == 'a')
                    printf("a");
                else {
                    if (message[i] == 'b')
                        printf("z");
                    else
                        printf("%c", message[i] - key);
                }
            }
            if (key == 26) {
                if (message[i] == 'a')
                    printf("y");
                else {
                    if (message[i] == 'z')
                        printf("z");
                    else
                        printf("%c", message[i] - 1);
                }
            }
            if (key < 26 && key > 1) {
                if (message[i] == 96 + key)
                    printf("%c", message[i]);
                else {
                    if (message[i] > 95 + 2*key)
                        printf("%c", message[i] - (key - 1));
                    else {
                        if (message[i] < 96 + key)
                            printf("%c", message[i] + 22);
                        else
                           printf("%c", message[i] - key);
                    }

                }
            }
        }
    }
    printf("\n");

    return 1;
}
