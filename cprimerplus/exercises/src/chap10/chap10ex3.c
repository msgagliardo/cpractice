/* This program creates a function that returns the largest value stored
 * in an array-of-int, and tests the function.
 */
#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

int arrayMax(int *data, int n) {
    int i;
    int max = data[0];

    /* Notice why you can't use sizeof(data)/sizeof(int) in place of n in
     * the for loop in order to make a function that can work with  any
     * size array.  The formal parameter of any function that gets passed
     * an array is a pointer.  So in this case, doing 
     * sizeof(data)/sizeof(int) on this system (MacBook Pro 2015) results 
     * in (8 bytes / 4 bytes) = 2.  
     */
    for (i = 1; i < n; i++)
        if (data[i] > max)
            max = data[i];

    return max;
}
int main(void) {
    int arr[SIZE] = {2, 5, 18, 22, 11, 7, 14};

    int max = arrayMax(arr, SIZE);

    printf("The largest value in arr = %d\n", max);

    return 0;
}
