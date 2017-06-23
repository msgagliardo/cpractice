/* This program calculates the number of years it will take for an amount
 * of money compounded annually at 5% interest will surpase the same 
 * amount of money at 10% simple interest.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double daphne = 100;
    double deirdre = 100;
    int t;

    for (t = 1; deirdre <= daphne; t++) {
        daphne = 100 + (100 * 0.10) * t;
        deirdre *= 1.05;
    }

    /* When the loop finishes, t = 28, but it has not calculated the 
     * new amount for t = 28, so it takes t - 1 or 27 years for Deirdre's
     * amount to surpass Daphne's. */
    printf("After %d years, Deirdre = $%.2lf, and Daphne = $%.2lf\n", 
            t - 1, deirdre, daphne);

    return 0;
} 

    
