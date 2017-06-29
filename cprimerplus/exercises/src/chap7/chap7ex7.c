/* This program requests a user to enter the number of hours worked in a
 * week and then prints the gross pay, the taxes, and the net pay.
 */
#include <stdio.h>
#include <stdlib.h>

#define RATE 10.00
#define ORATE 15.00
#define TRATE1 0.15
#define TRATE2 0.20
#define TRATE3 0.25

int main(void) {
    double hours;
    double gross = 0;
    double taxes = 0; 
    
    printf("Enter the hours worked, and I will calculate your pay.\n");
    scanf("%lf", &hours);

    if (hours - 40 > 0)
        gross = 40 * RATE + (hours - 40) * ORATE;
    else
        gross = hours * RATE;
    
    if (gross > 450)
        taxes = (TRATE3 * (gross - 450)) + (TRATE2 * 150) + (TRATE1 * 300);
    else if (gross > 300 && gross <= 450) 
        taxes = (TRATE2 * 150) + (TRATE1 * 300);
    else
        taxes = TRATE1 * 300;

    printf("Gross pay = $%.2lf, taxes = $%.2lf, net pay = $%.2lf\n", 
            gross, taxes, gross - taxes);

    return 0;
} 

