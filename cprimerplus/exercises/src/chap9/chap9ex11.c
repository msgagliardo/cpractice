/* This program takes a positive integer n, and returns the corresponding
 * Fibonacci number in the sequence.  It uses a loop instead of recursion.
 */
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

uintmax_t Fibonacci(unsigned n) {
    int i;
    uintmax_t num1 = 1;
    uintmax_t num2 = 1;
    uintmax_t result;

    if (n > 2) {
        for (i = 3; i <= n; i++) {
            result = num1 + num2;
            num1 = num2;
            num2 = result;
        }
        return result;
    } else
        return 1;
}
int main(void) {
    unsigned pos;

    printf("Enter a postion in the Fibonacci series to find the"
            " corresponding number (q to quit):\n");
    while (scanf("%u", &pos) == 1) {
        printf("Fibonacci # = %" PRIuMAX "\n", Fibonacci(pos));
        printf("Enter a positive integer (q to quit):\n");
    }
    printf("Done.\n");

    return 0;
}
