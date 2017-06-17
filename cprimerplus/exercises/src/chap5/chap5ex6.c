/* This program asks the user for an integer, and then computes the sum of the 
 * squares of all the integers from 1 up to and including the user-entered 
 * integer.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* The inttypes.h header includes the stdint.h header file.  The stdint.h header
 * defines the typedefs for the portable integer types (like uintmax_t).  The
 * inttypes.h header defines the macros for the scanf and printf format 
 * specifiers (like SCNuMAX and PRIuMAX)
 */
#include <inttypes.h>

int main(void) {
    uintmax_t userData;
    uintmax_t sum = 0;

    printf("Enter an integer n and I will sum the squares of all the numbers"
            " in the range [1, n]: ");
    scanf("%" SCNuMAX, &userData);

    while (userData > 0) {
        /* I could have just done (userData * userData) to square the number,
         * but I wanted to use the pow function.
         */
        sum += (uintmax_t) pow(userData, 2);
        userData--;
    }
    printf("The result is %" PRIuMAX "\n", sum);

    return 0;
}
