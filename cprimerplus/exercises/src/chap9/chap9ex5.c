/* This program creates a function called larger_of that replaces the 
 * contents of two double variables with the maximum of the two values.
 */
#include <stdio.h>
#include <stdlib.h>

void larger_of(double *x, double *y) {
    if (*x > *y)
        *y = *x;
    else if (*x < *y)
        *x = *y;
    else
        return;
}
int main(void) {
    double num1 = 2.34, num2 = 8.23;

    printf("Before call to larger_of, num1 = %lf, and num2 = %lf\n",
            num1, num2);
    larger_of(&num1, &num2);
    printf("After call to larger_of, num1 = %lf, and num2 = %lf\n",
            num1, num2);

    return 0;
}
