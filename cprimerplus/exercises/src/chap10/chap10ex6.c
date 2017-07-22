/* This program creates a function that reverses the contents of an array
 * of double values, and then tests the function.
 */
#include <stdio.h>
#include <stdlib.h>

#define SIZE 7
double arr[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};

void arrayReverse(double *data, int n) {

    if (n > 1) {
        double temp;
        int low = 0;
        int high = n - 1;

        while (low < high) {
            temp = data[high];
            data[high] = data[low];
            data[low] = temp;
            low++;
            high--;
        }
    }
}
int main(void) {
    int i;
    double arr[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};

    arrayReverse(arr, SIZE);
    for (i = 0; i < SIZE; i++)
        printf("%lf  ", arr[i]);

    printf("\n");

    return 0;
}


            


    


