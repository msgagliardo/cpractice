/* This program creates an eight-element array of ints and sets the elements 
 * to the first eight powers of 2 and then prints the values.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    int nums[8];
    int i;

    for (i = 0; i < 8; i++) 
        nums[i] = (int) pow(2, i + 1);
    
    i--;
    do {
        printf("%d%s", nums[i], (i == 0) ? "\n": "  ");
        i--;
    } while (i >= 0);

    return 0;
}
