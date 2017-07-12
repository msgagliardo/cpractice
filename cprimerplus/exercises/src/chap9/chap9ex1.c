/* This program creates a function called min that returns the smaller of 
 * two double values and tests the function.
 */
#include <stdio.h>
#include <stdlib.h>

double min(double x, double y) {
    return x < y ? x: y;
} 
int main(void) {
    printf("%lf\n", min(5.12, 8.91));

    return 0;
} 


