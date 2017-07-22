/* This program creates a function that returns the index of the largest
 * value stored in an array-of-double, and then tests the function.
 */
#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

int maxIndex(double *data, int n) {
    int index, i;

    index = 0;
    for (i = 0; i < n; i++)
        if (data[i] > data[index])
            index = i;

    return index;
}
int main(void) {
    int result;
    double arr[SIZE] = {8.1, 22.2, 5.4, 68.2, 15.8, 33.5, 7.7};

    result = maxIndex(arr, SIZE);
    printf("The index of the largest double in arr = %d\n", result);

    return 0;
}

