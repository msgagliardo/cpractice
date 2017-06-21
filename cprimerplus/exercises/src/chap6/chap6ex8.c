/* This program requests two floating-point numbers and prints the value of
 * their difference divided by their product.  The program loops through pairs
 * of input values until the user enters nonnumeric input.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double x, y;

    printf("Enter two numbers (q to quit): ");

    while (scanf("%lf %lf", &x, &y) == 2) {
        printf("The value of (x - y) / (x * y) = %lf\n\n", (x-y) / (x*y));
        printf("Enter two numbers (q to quit): ");
    }
    return 0;
} 

