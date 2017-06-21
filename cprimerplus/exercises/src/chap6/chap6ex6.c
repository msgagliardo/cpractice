/* This program prints a table with each line giving an integer, its square,
 * and its cube.  The user is asked to enter the lower and upper limits for 
 * the table.
 */
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main(void) {
    intmax_t low, high, i;
    int ok;

    printf("Please enter two numbers to produce a table of squares and cubes: ");
    ok = scanf("%" SCNdMAX "%" SCNdMAX, &low, &high);

    printf("\n");
    
    printf("%10s%15s%20s\n", "Number", "Squared", "Cubed");
    for (i = low; i <= high; i++) {
        printf("%10" PRIdMAX "%15" PRIdMAX "%20" PRIdMAX "\n", 
                i, i*i, i*i*i);
    }
    return 0;
} 
