/* This program requests a double number from the user and then prints that 
 * number cubed.  It uses a function called cube instead of the pow function
 * of the math.h header
 */
#include <stdio.h>
#include <stdlib.h>

double cube(double x) {
    return x * x * x;
}
int main(void) {
    double userData;

    printf("Please enter any number, and I will cube it: ");
    scanf("%lf", &userData);

    printf("%lf cubed is %lf\n", userData, cube(userData));

    return 0;
} 
