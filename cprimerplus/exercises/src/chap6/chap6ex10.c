/* This program requests lower and upper integer limits, calculates the 
 * sum of all the integer squares from the square of the lower limit to the 
 * square of the upper limit, and then displays the answer.  The program
 * continues to prompt for limits until the user enters an upper limit that
 * is <= the lower limit.
 */
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main(void) {
    intmax_t low, high, i, sum;

    printf("Enter lower and upper integer limits: ");
    while (scanf("%" SCNdMAX "%" SCNdMAX, &low, &high) == 2 && low < high) {
        sum = 0;
        for (i = low; i <= high; i++) 
            sum += i*i; 
        printf("The sums of the squares from %" PRIdMAX " to %" PRIdMAX 
               " is %" PRIdMAX "\n", low*low, high*high, sum);
        printf("Enter next set of limits: ");
    }
    printf("Done\n");

    return 0;
}    
