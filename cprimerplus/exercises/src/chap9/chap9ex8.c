/* This program improves on the power() function of listing 6.20.  The 
 * function has been improved to correctly handle negative integers for 
 * powers.  It also reports that 0 to any power other than 0 is 0, and that
 * any number to the 0 power is 1.
 */
#include <stdio.h>
#include <stdlib.h>

double power(double base, int exp) {
    int i;
    double result = 1;

    if (0 == base) {
        if (0 == exp) {
            puts("0^0 is undefined.  Returning 1.");
            return 1;
        }
        return 0;
    }
    if (0 != base && 0 == exp)
        return 1;

    if (exp > 0) {
        for (i = 1; i <= exp; i++)
            result *= base;
    } else {
        for (i = exp; i < 0; i++)
            result *= (1 / base);
    }
    return result;
}    
int main(void) {

    printf("3.124 raised to the -5 = %lf\n", power(3.124, -5));
    printf("3.124 raised to the 5 = %lf\n", power(3.124, 5));
    printf("0 raised to the 2 = %lf\n", power(0, 2));
    printf("0 raised to the 0 = %lf\n", power(0, 0));
    printf("5.84 raised to the 0 = %lf\n", power(5.84, 0));

    return 0;
} 
