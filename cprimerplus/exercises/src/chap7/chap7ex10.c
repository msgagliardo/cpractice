/* This program lets a user enter a tax category and then calculates the 
 * tax for their income based on the 1988 U.S. Federal Tax Schedule.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
    char again;
    int selection;
    int scanResult;
    double income;
    double tax;

    do {
        do {
            printf("Please enter a tax category:\n");
            printf("******************************************\n");
            printf("1) Single\t\t\t\t2) Head of Household\n");
            printf("3) Maried, Joint\t\t\t4) Married, Seperate\n");
            printf("5) quit\n");
            printf(">  ");
             
            scanResult = scanf("%d", &selection);
            while ('\n' != getchar())
                continue;
        } while (0 == scanResult || (selection > 5 || selection < 1));
        
        if (5 == selection)
            exit(EXIT_SUCCESS);

        do {
            printf("Now enter your gross income: ");
            scanResult = scanf("%lf", &income);
            if (0 == scanResult)
                printf("Please enter a number.\n");
            while ('\n' != getchar())
                continue;
        } while (0 == scanResult); 

        switch (selection) {
            case 1:
                if (income > 17850)
                    tax = (0.15 * 17850) + (0.28 * (income - 17859));
                else
                    tax = 0.15 * income;
                break;
            case 2:
                if (income > 23900)
                    tax = (0.15 * 23900) + (0.28 * (income - 23900));
                else
                    tax = 0.15 * income;
                break;
            case 3:
                if (income > 29750)
                    tax = (0.15 * 29750) + (0.28 * (income - 29750));
                else
                    tax = 0.15 * income;
                break;
            case 4:
                if (income > 14875)
                    tax = (0.15 * 14875) + (0.28 * (income - 14875));
                else
                    tax = 0.15 * income;
                break;
        }
        printf("Your total taxes are $%.2lf\n", tax);
        printf("Would you like to make another selection (y/n): ");

        again = getchar();
        while ('\n' != getchar())
            continue;
    } while ('Y' == toupper(again));

    return 0;
} 


