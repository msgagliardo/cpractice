/* This program creates a function that returns the difference between the
 * largest and smallest elements of an array-of-double, and then tests the
 * function.
 */
#include <float.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

/* Type 'long double' on this system is 128 bits, but the C standard only
 * guarantees that it is at least as large as type 'double' (64-bits).
 * (This system is a MacBook Pro (2015)). (Since C89)
 */
long double maxDiff(double *data, int n) {

    /* Is there any way to check that an uninitialized array has been 
     * passed to the function.  You cannot check to see if data == NULL
     * because this stack-allocated array is not a reference type like it
     * is in Java.
     */
    int i;
    long double max = -DBL_MAX;
    long double min = DBL_MAX;

    for (i = 0; i < n; i++) {
        if (data[i] > max)
            max = data[i];

        if (data[i] < min)
            min = data[i];
    }
    return max - min;
}
int main(void) {
    long double diff;
    double arr[SIZE] = {-234.34, -34.3, 1.24, 4.31, 14.45, 83.34, 132.24};

    diff = maxDiff(arr, SIZE);
    printf("The maximum difference between elements in arr = %Lf\n", 
        diff);

    return 0;
}

