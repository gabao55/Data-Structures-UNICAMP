#include <stdio.h>

int main(void)
{
    int triplas_number, i, j;

    scanf("%d\n", &triplas_number);

    int number, frequency;
    int numbers[triplas_number], frequencies[triplas_number];
    char character;
    char characteres[triplas_number+1];

    // Scanning the values of the triplas and inserting it into vectors:
    for ( i = 0 ; i <= triplas_number-1 ; i++ ) {
        scanf(" (%d,%d,%c)", &number, &frequency, &character);

        numbers[i] = number;
        frequencies[i] = frequency;
        characteres[i] = character;

    }

    numbers[triplas_number-1] = number;
    frequencies[triplas_number-1] = frequency;
    characteres[triplas_number-1] = character;

    // Picking up the highest value in the vector numbers:
    int maior = 0;

    for ( i=0 ; i < triplas_number ; i++ ) {
        if ( maior < numbers[i] )
            maior = numbers[i];
    }

    // Creating the graphics and printing the output:
    for ( i=0 ; i < triplas_number ; i++ ) {
        printf("%4d |", numbers[i]);

        for ( j=0 ; j < frequencies[i] ; j++ ) {
            printf("%c", characteres[i]);
        }
        printf(" %d\n", frequencies[i]);
    }

    return 0;
}