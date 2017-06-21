/* This program evaluates the infinite series's, 1.0 + 1.0/2.0 + 1.0/3.0 +
 * 1.0/4.0 + ...  and 1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ... The number of 
 * terms is determined by the user.
 */
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main(void) {
    int numOfTerms, i, icopy;
    double sum1, sum2;

    printf("Enter the number of terms to use for the infinite series's: ");
    while (scanf("%d", &numOfTerms) == 1) {
        sum1 = 0;
        sum2 = 0;
        for (i = 1; i <= numOfTerms; i++) {
            icopy = i;
            if (i % 2 == 0)
                icopy = -i;
            sum1 += 1.0 / i;
            sum2 += 1.0 / icopy;
        } 
        printf("Sum1 for %d terms is %lf\n", numOfTerms, sum1);
        printf("Sum2 for %d terms is %lf\n", numOfTerms, sum2);
        printf("Enter another number (q to quit): ");
    }
    puts("Bye");

    return 0;
} 


