/* This program requests a user to enter the number of hours worked in a
 * week and then prints the gross pay, the taxes, and the net pay.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TRATE1 0.15
#define TRATE2 0.20
#define TRATE3 0.25

int main(void) {
    int selection;
    int scanResult;
    char again;
    double rate;
    double hours;
    double gross = 0;
    double taxes = 0; 

    do {
        do { 
            do {
                printf("Enter the number corresponding to the desired pay"
                       " rate or action\n");
                printf("1) $8.75/hr\t\t\t2) $9.33/hr\n");
                printf("3) $10.00/hr\t\t\t4) $11.20/hr\n");
                printf("5) quit\n");

                scanResult = scanf("%d", &selection);
                
                // used to dispose of any input still left in the buffer
                while ('\n' != getchar())
                    continue;

                // this do loop just ensures that an integer is entered
            } while (scanResult == 0);

            switch (selection) {
                case 1:
                    rate = 8.75;
                    break;
                case 2:
                    rate = 9.33;
                    break;
                case 3:
                    rate = 10.00;
                    break;
                case 4:
                    rate = 11.20;
                    break;
                case 5:
                    puts("Goodbye!");
                    exit(EXIT_SUCCESS);
                default:
                    puts("Please enter a number in the range [1,5]");
                    break;
            }
            // this do loop ensures the integer is in the correct range
            // it wraps the first one and goes back to the beginning of 
            // the code if the number is outside the range to get a new
            // number
        } while (selection < 1 || selection > 5);     

        printf("Enter the hours worked, and I will calculate your pay.\n");
        printf("> ");

        while (scanf("%lf", &hours) == 0) {
            printf("Please enter a valid number: ");
            while ('\n' != getchar())
                continue;
        }
        while ('\n' != getchar())
            continue;

        if (hours - 40 > 0)
            gross = 40 * rate + (hours - 40) * (rate * 1.5);
        else
            gross = hours * rate;
        
        if (gross > 450)
            taxes = (TRATE3 * (gross - 450)) + (TRATE2 * 150) + 
                (TRATE1 * 300);
        else if (gross > 300 && gross <= 450) 
            taxes = (TRATE2 * 150) + (TRATE1 * 300);
        else
            taxes = TRATE1 * 300;

        printf("Gross pay = $%.2lf, taxes = $%.2lf, net pay = $%.2lf\n", 
                gross, taxes, gross - taxes);
        printf("Make another selection? (y/n): ");
        again = getchar();

        // this do wraps the whole code.  Asks if user wants to try again
    } while ('Y' == toupper(again));

    return 0;
} 

