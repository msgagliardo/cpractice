/* This program creates a function that takes the addresses of three double
 * variables as arguments and moves the value of the smallest variable into
 * the first variable, the middle value into the second variable, and the 
 * largest value into the third variable.
 */
#include <stdio.h>
#include <stdlib.h>

void low_middle_high(double *x, double *y, double *z) {
    double high, middle, low;
    
    if (*x <= *y) {
        low = *x;
        high = *y;
    } else {
        low = *y;
        high = *x;
    }
    if (high <= *z) {
        middle = high;
        high = *z;
    } else if (low <= *z) {
        middle = *z;
    } else {
        middle = low;
        low = *z;
    }
    *x = low; 
    *y = middle;
    *z = high;
}
int main(void) {
    double x = 3.14, y = 5.12, z = 7.86;
    
    printf("Before: x = %.2lf y = %.2lf z = %.2lf\n", x, y, z);
    low_middle_high(&x, &y, &z);
    printf("After: x = %.2lf y = %.2lf z = %.2lf\n", x, y, z);

    printf("\n");

    x = 3.14, y = 7.86, z = 5.12;
    printf("Before: x = %.2lf y = %.2lf z = %.2lf\n", x, y, z);
    low_middle_high(&x, &y, &z);
    printf("After: x = %.2lf y = %.2lf z = %.2lf\n", x, y, z);

    printf("\n");

    x = 7.86, y = 3.14, z = 5.12;
    printf("Before: x = %.2lf y = %.2lf z = %.2lf\n", x, y, z);
    low_middle_high(&x, &y, &z);
    printf("After: x = %.2lf y = %.2lf z = %.2lf\n", x, y, z);
    
    printf("\n");

    x = 7.86, y = 5.12, z = 3.14;
    printf("Before: x = %.2lf y = %.2lf z = %.2lf\n", x, y, z);
    low_middle_high(&x, &y, &z);
    printf("After: x = %.2lf y = %.2lf z = %.2lf\n", x, y, z);
 
    printf("\n");

    x = 5.12, y = 7.86, z = 3.14;
    printf("Before: x = %.2lf y = %.2lf z = %.2lf\n", x, y, z);
    low_middle_high(&x, &y, &z);
    printf("After: x = %.2lf y = %.2lf z = %.2lf\n", x, y, z);
 
    printf("\n");

    x = 5.12, y = 3.14, z = 7.86;
    printf("Before: x = %.2lf y = %.2lf z = %.2lf\n", x, y, z);
    low_middle_high(&x, &y, &z);
    printf("After: x = %.2lf y = %.2lf z = %.2lf\n", x, y, z);

    return 0;
}

