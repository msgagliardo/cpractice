/* This program creates a function to double all the values in a N x 5
 * two-dimensional array, and another function to display the values in
 * a N x 5 two-dimensional array.  These two functions are tested in main
 */
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 5

void doubleMatrix(int (*ar)[COLS], int rows) {

    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < COLS; j++)
            ar[i][j] *= 2;
    }
}
void displayMatrix(int ar[][COLS], int rows) {

    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < COLS; j++)
            printf("%3d%s", ar[i][j], (COLS - 1 == j) ? "\n": " ");
    }
}
int main(void) {

    int mat[ROWS][COLS] = {
        {14, 5, 7, 20, 11},
        {18, 3, 12, 4, 9},
        {2, 1, 17, 13, 25}
    };
    displayMatrix(mat, ROWS);
    printf("\n");

    doubleMatrix(mat, ROWS);
    displayMatrix(mat, ROWS);
    printf("\n");

    return 0;
}
