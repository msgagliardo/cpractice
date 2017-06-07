#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

/* A program to determine how this particular system (Macbook Pro 2015)
   handles integer overflow, floating-point overflow, and floating-point
   underflow. */

int main(void) {
    // for overflow of signed values, it loops back to the smallest negative
    // number in its range
    printf("INT_MAX = %d, INT_MAX + 1 = %d\n", INT_MAX, INT_MAX + 1);
    // for overflow of unsigned values, it loops back to 0 as mandated by
    // the C standard
    printf("UINT_MAX = %u, UINT_MAX + 1 = %u\n", UINT_MAX, UINT_MAX + 1);
    // for floating-point overflow, "inf" will be displayed
    printf("DBL_MAX = %e, DBL_MAX + 1e308 = %e\n", DBL_MAX, DBL_MAX + 1e308);
    // for floating-point underflow, all zeroes are dispayed
    printf("DBL_MIN = %e, DBL_MIN / 1e15 = %e\n", DBL_MIN, DBL_MIN / 1e16);

    return 0;

}
