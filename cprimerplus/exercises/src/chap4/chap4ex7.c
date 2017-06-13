/* This program sets the value 1.0/3.0 to a float and a double variable.  It then
 * displays both variables showing 4 digits, 12 digits, and 16 digits to the 
 * right of the decimal point. */
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main(void) {
    float dx = 1.0 / 3.0;
    double dy = 1.0 / 3.0;

    printf("float precision = %d double precision = %d\n", FLT_DIG, DBL_DIG);
    printf("%19.4f %21.4lf\n", dx, dy);
    printf("%19.12f %21.12lf\n", dx, dy);
    printf("%19.16f %21.16lf\n", dx, dy);

    return 0;
}

