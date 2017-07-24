/* This program uses a copy function from chap10ex2.c to copy the third 
 * through fifth elements of a seven-element array into a three-element
 * array.
 */
#include <stdio.h>
#include <stdlib.h>

#define SRC_SZ 7
#define TAR_SZ 3

void arrCopy(double target[], double source[], int n) {
    int i;

    for (i = 0; i < n; i++)
        target[i] = source[i + 2];

}
int main(void) {
    int i;
    double arr[SRC_SZ] = {3.3, 1.1, 2.2, 5.5, 4.4, 6.6, 7.7};
    double arr2[TAR_SZ];

    arrCopy(arr2, arr, TAR_SZ);
    
    for (i = 0; i < TAR_SZ; i++)
        printf("%lf%s", arr2[i], (TAR_SZ - 1 == i) ? "\n": "  ");

    return 0;
}
    
