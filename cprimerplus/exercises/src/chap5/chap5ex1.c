#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const int MINS_IN_HR = 60;

    double minutes, userData;
    int hours;

    printf("Please enter the number of minutes to be converted to hours and"
            " minutes (enter 0 or a negative number to quit): ");
    scanf("%lg", &userData);
    while (userData > 0) {
        hours = (int) (userData / MINS_IN_HR);
        minutes = userData - (hours * MINS_IN_HR);

        /* For the %g specifier, the ".<digits>" modifier specifies the number
         * of significant digits that you want in the result.  Wheres for the 
         * %f specifier it specifies the number of digits to be placed after 
         * the decimal place.  The default behavior with no modifier is to have
         * 6 significant digits (the default for %f is to have 6 digits after 
         * the decimal point).  Trailing zeroes are never shown with the %g 
         * specifier.
         */
        printf("%d hrs, %.7lg mins\n", hours, minutes);
        printf("Please enter the number of minutes to be converted to hours and"
            " minutes (enter 0 or a negative number to quit): ");
        scanf("%lg", &userData);
    } 
    printf("Thank you for using this time converter.  Goodbye!\n");

    return 0;
}
