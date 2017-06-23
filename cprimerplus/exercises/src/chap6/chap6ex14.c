/* This program two eight-element arrays of doubles and uses a loop to let the
 * user enter values for the eight elements of the first array.  The second 
 * array is set to the cumulative totals of the elements of the first array.
 * The contents of both arrays are then displayed.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double nums[8], sums[8];
    double sum = 0;
    int i;

    printf("Please enter 8 floating-point numbers: ");
    for (i = 0; i < 8 && (scanf("%lf", &nums[i]) == 1); i++) {
        sum += nums[i];
        sums[i] = sum;
    } 
    for (i = 0; i < 8; i++)
        printf("%10.2lf%s", nums[i], (i == 7) ? "\n": "");
    
    for (i = 0; i < 8; i++)
        printf("%10.2lf%s", sums[i], (i == 7) ? "\n": ""); 
   
    return 0;
} 
