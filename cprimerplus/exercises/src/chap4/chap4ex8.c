/* This program asks the user to enter miles traveled and gallons used. It then
 * calculates and displays the miles-per-gallon and the liters-per-100-km. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const double GALL_TO_LITER = 3.785;
    const double MILE_TO_KM = 1.609;
    double miles;
    double gallons; 

    printf("Please enter the number of miles traveled followed by the number "
            "of gallons used: ");
    scanf("%lf %lf", &miles, &gallons);
    
    double km = miles * MILE_TO_KM;
    double liters = gallons * GALL_TO_LITER;
    printf("Miles-per-gallon = %.1lf\n", miles / gallons);
    printf("Liters-per-100-km = %.1lf\n", (liters / km) * 100);

    return 0;
}
