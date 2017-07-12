/* This program creates a function that calculates the harmonic mean of 
 * two doubles.  The harmonic mean of two numbers is obtained by taking the
 * inverses of the two numbers, averaging them, and taking the inverse of 
 * the result.
 */
#include <stdio.h>
#include <stdlib.h>

double harmonic_mean(double x, double y) {
    double result, inverse;

    result = ((1 / x) + (1 / y)) / 2;
    inverse =  1 / result;

    return inverse;
}
int main(void) {
    printf("The harmonic mean of 21.23 and 83.13 = %lf\n", 
            harmonic_mean(21.23, 83.13));

    return 0;
} 
