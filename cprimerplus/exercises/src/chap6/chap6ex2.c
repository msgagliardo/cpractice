/* This program uses nested loops to print an increasing number of $ signs on 
 * sequential lines.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const int ROWS = 6;
    int i, j;

    for (i = 1; i < ROWS; i++) {
        for (j = 0; j < i; j++)
            printf("$");
        printf("\n");
    }
    return 0;
} 
