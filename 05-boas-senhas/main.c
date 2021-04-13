#include <stdio.h>
#include <string.h>
#define MAX 21

// This function checks if the character is a vowel
int contains_vowel(char element) {

    if (element == 'a' || element == 'e' || element == 'i' || element == 'o' || element == 'u' ||
        element == 'A' || element == 'E' || element == 'I' || element == 'O' || element == 'U')
        return 1;

    return 0;

}

// This function checks if the character is a digit
int contains_digit(char element) {

   if (element > 47 && element < 58)
       return 1;

    return 0;
}

// This function checks if the character is an upper character
int contains_upper(char element) {

    if (element > 64 && element < 91)
        return 1;

    return 0;
}

// This function checks if the character is a lower character
int contains_lower(char element) {

    if (element > 96 && element < 123)
        return 1;

    return 0;
}

// This function checks if the character is a consonant
int contains_consonant(char element) {

    if ( ((element > 96 && element < 123) || (element > 64 && element < 91)) && (!contains_vowel(element)) )
        return 1;

    return 0;
}

/* This function receives passwords untiil the word "fim" is inserted and evaluates each password.
 * Criteria:
 * At least 8 characters;
 * At least 1 vowel;
 * At least 1 upper and 1 lower characters;
 * No more than 3 consecutive vowels;
 * At least 3 consecutive vowels.
 */
int main() {
    char password[MAX] = {'\000'};

    int vowel, digit, upper, lower, minimum_length;
    int consecutive_vowels, consecutive_consonants;
    int vowels, consonants;
    int i;

    scanf("%s", password);

    while (password[0] != 'f' || password[1] != 'i' || password[2] != 'm' || password[3] != '\000') {
        vowel = digit = upper = lower = i = consecutive_vowels = consecutive_consonants = consonants = 0;
        vowels = 0;
        minimum_length = strlen(password);

        if (minimum_length >= 8) {
            while ((password[i] != '\000') || ( !vowel && !digit && !upper && !lower)) {
                if (vowel == 0)
                    vowel = contains_vowel(password[i]);
                if (digit == 0)
                    digit = contains_digit(password[i]);
                if (upper == 0)
                    upper = contains_upper(password[i]);
                if (lower == 0)
                    lower = contains_lower(password[i]);
                if (contains_vowel(password[i])) {
                    consecutive_vowels++;
                    if (consecutive_vowels > 2)
                        vowels = 1;
                }
                else
                    consecutive_vowels = 0;
                if (contains_consonant(password[i])) {
                    consecutive_consonants++;
                    if (consecutive_consonants > 2)
                        consonants = 1;
                }
                else
                    consecutive_consonants = 0;
                i++;
            }}

        if (vowel && digit && upper && lower && (!vowels) && consonants)
            printf("[%s] e' aceitavel.\n", password);
        else
            printf("[%s] e' inaceitavel.\n", password);

        scanf("%s", password);
    }


    return 1;
}
