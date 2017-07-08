/* This program modfies exercise 8 from chapter 7 so that the menu choices
 * are labeled by characters instead of by numbers.  'q' is used instead of
 * 5 as the cue to terminate input.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TRATE1 0.15
#define TRATE2 0.20
#define TRATE3 0.25

int main(void) {
    char selection;
    int scanResult;
    char again;
    double rate;
    double hours;
    double gross = 0;
    double taxes = 0; 

    do {
        do { 
            do {
                printf("Enter the letter corresponding to the desired pay"
                       " rate or action\n");
                printf("a) $8.75/hr\t\t\tb) $9.33/hr\n");
                printf("c) $10.00/hr\t\t\td) $11.20/hr\n");
                printf("q) quit\n");

                scanResult = scanf(" %c", &selection);
                
                // used to dispose of any input still left in the buffer
                while ('\n' != getchar())
                    continue;

                // this do loop just ensures that a char is entered
            } while (scanResult == 0);

            switch (tolower(selection)) {
                case 'a':
                    rate = 8.75;
                    break;
                case 'b':
                    rate = 9.33;
                    break;
                case 'c':
                    rate = 10.00;
                    break;
                case 'd':
                    rate = 11.20;
                    break;
                case 'q':
                    puts("Goodbye!");
                    exit(EXIT_SUCCESS);
                default:
                    puts("Please enter a letter in the range [a,d] or q");
                    break;
            }
            // this do loop ensures the letter is in the correct range
            // it wraps the first one and goes back to the beginning of 
            // the code if the letter is outside the range to get a new
            // letter
        } while (tolower(selection) < 'a' || tolower(selection) > 'd');

        printf("Enter the hours worked, and I will calculate your pay.\n");
        printf("> ");

        while (scanf("%lf", &hours) == 0 || hours <= 0) {
            printf("Please enter a valid positive number: ");
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
            taxes = TRATE1 * gross;

        printf("Gross pay = $%.2lf, taxes = $%.2lf, net pay = $%.2lf\n", 
                gross, taxes, gross - taxes);
        printf("Make another selection? (y/n): ");
        again = getchar();

        // this do wraps the whole code.  Asks if user wants to try again
    } while ('Y' == toupper(again));

    return 0;
} 

