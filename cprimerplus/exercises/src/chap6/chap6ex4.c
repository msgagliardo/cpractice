/* This program uses nested loops to print the sequence of letters starting at
 * A and ending at U.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const int ROWS = 6;
    char c = 'A';
    int i, j;

    for (i = 1; i <= 6; i++) {
        for (j = 0; j < i; j++) {
            printf("%c", c);
            c++;
        }
        printf("\n");
    }
    return 0;
} 
