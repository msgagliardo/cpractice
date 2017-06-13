/* This program accepts a user-entered floating-point number and then displays
 * it in decimal notation, and then in exponential notation. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    float num;

    printf("Please enter a floating-point number: ");
    scanf("%f", &num);
    
    printf("Decimal notation %f\n", num);
    printf("Exponential notation %g\n", num);

    return 0;
}
