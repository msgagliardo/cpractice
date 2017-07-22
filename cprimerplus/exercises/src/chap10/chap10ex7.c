/* This program initializes a two-dimensional array-of-double and uses one
 * of the copy functions from chap10ex2.c to copy it to a second 
 * two-dimensional array.
 */
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 4

void arrCopy(double target[], double source[], int n) {
    int i;

    for (i = 0; i < n; i++)
        target[i] = source[i];

}
int main(void) {

    double matrix[ROWS][COLS] = {
        {1.1, 2.2, 3.3, 4.4},
        {5.5, 6.6, 7.7, 8.8},
        {9.9, 10.10, 11.11, 12.12},
        {13.13, 14.14, 15.15, 16.16},
        {17.17, 18.18, 19.19, 20.20}
    };
    double matrixCopy[ROWS][COLS];
    int i, j;
    
    /* Because a two-dimensional array is an array of arrays, a 
     * one-dimensional copy function can be used with each subarray.
     * Alternatively, you could just write a function to copy a 
     * two-dimensional array, and then you wouldn't need this loop here,
     * you could simply make a single call to the function.  However,
     * unless you are using VLAs (a C99 feature), that two-dimensional 
     * array function would only be able to work on arrays with a fixed
     * column size.
     */
    for (i = 0; i < ROWS; i++) 
        arrCopy(matrixCopy[i], matrix[i], COLS);

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++)
            printf("%9lf%s", matrixCopy[i][j], (COLS - 1 == j) ? "\n": " ");
    }
    return 0;
}
