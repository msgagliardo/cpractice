/* This program accepts a positive integer as input and then displays all
 * the prime numbers <= that number.
 */
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main(void) {
    uintmax_t input, i, j;
    int divisors;
    int count = 1;

    printf("Enter a positive integer and I will display all the prime\n"
            "numbers in from 0 to your number: ");
    scanf("%" SCNuMAX, &input);
    for (i = 2; i <= input; i++) {
        divisors = 0;

        for (j = 1; j <= i; j++) {
            if (i % j == 0)
                divisors++;
            if (divisors > 2)
                break;
            if (j == i) {
                count++;
                printf("%" PRIuMAX "  ", i);
            }
        }
        if ((count % 22 == 0) || i == input) {
            count = 1;
            printf("\n");
        } 
    }
    return 0;
} 
    
