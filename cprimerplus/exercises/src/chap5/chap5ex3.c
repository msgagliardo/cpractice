/* This program asks the user to enter the number of days and then converts that
 * value into weeks and days
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const int DAYS_IN_WEEK = 7;
    int userData;
    int weeks, days;

    printf("Please enter an integer number of days (enter a negative integer or "       "0 to quit): ");
    scanf("%d", &userData);

    while (userData > 0) {
       weeks = userData / DAYS_IN_WEEK;
       days = userData % DAYS_IN_WEEK;

       printf("%d day%s %s %d week%s, %d day%s\n", userData, 
               (userData == 1) ? "": "s", (userData == 1) ? "is": "are", weeks,
               (weeks == 1) ? "": "s", days, (days == 1) ? "": "s");

       printf("Please enter an integer number of days (enter a negative integer"
               " or 0 to quit): ");
       scanf("%d", &userData);
    } 
    printf("Thank you for using the days converter.  Goodbye!\n");

    return 0;
}
