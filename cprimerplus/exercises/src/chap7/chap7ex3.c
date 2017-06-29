/* This program reads user-entered integers until 0 is entered.  After 
 * input terminates, the program reports the total number of even integers
 * (exluding the 0) entered, the average value of the even integers, the
 * total number of odd integers, and the average value of the odd 
 * integers.
 */
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main(void) {
    intmax_t num;
    intmax_t eCount = 0;
    intmax_t oCount = 0;
    intmax_t evenSum = 0;
    intmax_t oddSum = 0;

    printf("Please enter a list of integers (0 to quit): ");
    while (scanf("%" SCNdMAX, &num) > 0) {
        if (0 == num)
            break;
        if (num % 2 == 0) {
            evenSum += num;
            eCount++;
        } else {
            oddSum += num;
            oCount++; 
        } 
    }
    printf("Even ints total = %" PRIdMAX ", Even ints avg value = %lf\n",
            eCount, (double) evenSum / eCount);
    printf("Odd ints total = %" PRIdMAX ", Odd ints avg value = %lf\n",
            oCount, (double) oddSum / oCount);

    return 0;
} 

