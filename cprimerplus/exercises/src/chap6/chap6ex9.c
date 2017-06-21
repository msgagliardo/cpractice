/* This program requests two floating-point numbers and then prints the value
 * of their difference divided by their product.  The program loops through
 * pairs of input values until the user enters nonnumeric input.  This program
 * is identical to chap6ex8.c except that the calculation is carried out in 
 * a separate function.
 */
#include <stdio.h>
#include <stdlib.h>

double calculate(double val1, double val2) {
    return (val1 - val2) / (val1 * val2);
}
int main(void) {
    double x, y;
    
    printf("Enter two numbers (q to quit): ");
    while (scanf("%lf %lf", &x, &y) == 2) {
        printf("The value of (x - y) / (x * y) = %lf\n\n", calculate(x, y));
        printf("Enter two numbers (q to quit): ");
    }
    return 0;
} 
