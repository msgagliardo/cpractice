#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    int toes = 10;

    printf("The value of toes = %d\n", toes);
    printf("The value of toes * 10 = %d\n", toes * 10);
    // the header for pow in math.h is "double pow(double x, double y)"
    // toes is an int but gets coerced to double
    printf("The value of toes^2 = %f\n", pow(toes, 2));

    return 0;
}
