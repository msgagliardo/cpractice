/* This program initializes a two-dimensional 3 x 5 array-of-double and
 * uses a VLA-based function to copy it to a second two-dimensional array.
 * Also, a VLA-based function is used to display the contents of the two
 * arrays.
 */
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 5

void matrixCopy(int rows, int cols, double target[rows][cols], 
                                        double source[rows][cols]) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++)
            *(*(target + i) + j) = *(*(source + i) + j);
    }
}
void displayMatrix(int rows, int cols, double data[rows][cols]) {

    int i, j;
    
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++)
            printf("%10lf%s", data[i][j], (cols - 1 == j) ? "\n": "  ");
    }
}
int main(void) {

    double mat1[ROWS][COLS] = {
        {1.1, 2.2, 3.3, 4.4, 5.5},
        {6.6, 7.7, 8.8, 9.9, 10.10},
        {11.11, 12.12, 13.13, 14.14, 15.15}
    };
    double mat2[ROWS][COLS];

    matrixCopy(ROWS, COLS, mat2, mat1);
    printf("mat1:\n");
    displayMatrix(ROWS, COLS, mat1);
    printf("\n");
    printf("mat2:\n");
    displayMatrix(ROWS, COLS, mat2);
    
    return 0;
}
