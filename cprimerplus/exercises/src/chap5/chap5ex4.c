/* This program asks the user to enter a height in centimeters and then 
 * displays the height in centimeters and in feet and inches.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const double CM_IN_INCHES = 2.54;
    double userData;
    int feet;
    double totalInches, inches;

    printf("Enter a height in centimeters: ");
    scanf("%lf", &userData);

    while (userData > 0) {
        totalInches = userData / CM_IN_INCHES;
        feet = (int) (totalInches / 12);
        inches = totalInches - (feet * 12);

        printf("%.1lf cm = %d feet, %.1lf inches\n", userData, feet, inches);
        printf("Enter a height in centimeters (<= 0 to quit): ");
        scanf("%lf", &userData);
    }
    printf("bye\n");

    return 0;
}
