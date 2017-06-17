/* This program asks the user to enter a Fahrenheit temperature.  It then 
 * passes that number to a function called temperatures which converts it to
 * Celsius and Kelvin.
 */
#include <stdio.h>
#include <stdlib.h>

double *convertTemp(double tempF) {
    double *conversion = (double*) malloc(sizeof(double) * 2);
    if (conversion == NULL) {
        puts("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    conversion[0] = 5.0 / 9.0 * (tempF - 32.0);
    conversion[1] = conversion[0] + 273.16;

    return conversion;
}
int main(void) {
    double userTemp;
    double *result;

    printf("Enter a Fahrenheit temperature to convert: ");

    while (scanf("%lf", &userTemp) > 0) {
        result = convertTemp(userTemp);
        printf("%.2lf F is %.2lf C, and %.2lf K\n", userTemp, result[0], 
                result[1]);
        free(result);
        printf("Enter another temperature or q to quit: ");
    }
    puts("Goodbye!");

    return 0;
}
