/* This program uses nested loops to print the sequence of letters starting at 
 * F and ending at A.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const int ROWS = 6;
    int i, j;
    char c;

    for (i = 1; i <= ROWS; i++) {
        for (j = 0, c = 'F'; j < i; j++, c--)
            printf("%c", c);
        printf("\n");
    }
    return 0;
} 
  
