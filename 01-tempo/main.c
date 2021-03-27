#include <stdio.h>

int main() {

    // Declaring my variables:
    int seconds;
    short int minutes, hours, days;

    // Scanning the input:
    scanf("%d", &seconds);

    // Calculating the conversion from seconds to days, hours, minutes and seconds:
    days = seconds/86400;
    hours = (seconds%86400)/3600;
    minutes = ((seconds%86400)%3600)/60;
    seconds = (((seconds%86400)%3600)%60);

    // Printing the output on the correct form:
    printf("%hd dia(s), %hd hora(s), %hd minuto(s) e %d segundo(s).\n", days, hours, minutes, seconds);

}
