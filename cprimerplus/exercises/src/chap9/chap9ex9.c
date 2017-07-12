/* This program is the same as chap9ex8.c except that the power function
 * is written to be recursive.
 */
#include <stdio.h>
#include <stdlib.h>

double power(double base, int exp) {

    if (exp == 0) {
        if (base == 0) {
            puts("0^0 is undefined.  Returning 1.");
            return 1;
        }
        return 1;
    } else if (base == 0) 
        return 0;
    else if (exp == -1) 
        return 1 / base;
    else if (exp == 1)
        return base;
    else {
        if (exp < -1)
            return (1 / base) * power(base, exp + 1);
        else
            return base * power(base, exp - 1);
    }
}
int main(void) {
    
    printf("3.124 raised to the -5 = %lf\n", power(3.124, -5));
    printf("3.124 raised to the 5 = %lf\n", power(3.124, 5));
    printf("0 raised to the 2 = %lf\n", power(0, 2));
    printf("0 raised to the 0 = %lf\n", power(0, 0));
    printf("5.84 raised to the 0 = %lf\n", power(5.84, 0));

    return 0;
}  

            
