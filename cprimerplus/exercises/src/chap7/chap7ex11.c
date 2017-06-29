/* This program allows a user to enter the number of pounds of artichokes
 * beets and carrots from a mail order grocery.  
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
    // in C89 (ANSI C) these single line comments are not allowd, and all
    // the declarations must come before the assignments.
    char selection;
    double pounds, a_pounds, b_pounds, c_pounds;
    double a_sum, b_sum, c_sum;
    char done;
    double subtotal, total_pounds, shipping, grand_total;
    a_pounds = b_pounds = c_pounds = 0;
    a_sum = b_sum = c_sum = 0;
    
    do {
        printf("Select what you would like to order\n");
        printf("===================================\n");
        printf("%s%22s\n", "a) artichokes", "b) beets");
        printf("%s%24s\n", "c) carrots", "q) quit");
        printf("> ");

        /* This while loop ensures that an character is entered and that 
         * the character is either 'a', 'b', 'c', or 'q'.  THe use of the 
         * toupper function from ctype.h ensures that the user can enter
         * either lower or upper case characters.  The inner while loop 
         * will consume any characters entered after the first one all 
         * the way up to the first newline character.  This may be left
         * in the buffer if the user accidently (or intentionally) enters
         * more than one character.  The space before the %c specifier 
         * causes scanf to skip over white space preceding the first 
         * non-whitespace character.
         */
        while (scanf(" %c", &selection) == 0 || (toupper(selection) != 'A' 
                && toupper(selection) != 'B' && toupper(selection) != 'C' 
                && toupper(selection) != 'Q')) {
            printf("Enter a, b, c or q, please: ");
            while ('\n' != getchar())
                continue;
        }

        if (selection == 'q' || selection == 'Q')
            exit(EXIT_SUCCESS);

        while ('\n' != getchar())
            continue;
        
        printf("Now enter the number of pounds that you want: ");

        while (scanf("%lf", &pounds) == 0)
            printf("Please enter a number: ");

        while ('\n' != getchar())
            continue;

        /* The statements under each case statement will run whether or not
         * the character entered by the user is upper or lowercase.  This 
         * is due to C's default fallthrough for switch statements.
         */
        switch (selection) {
            case 'a':
            case 'A':
                a_pounds += pounds;
                a_sum += 2.05 * pounds;
                break;
            case 'b':
            case 'B':
                b_pounds += pounds;
                b_sum += 1.15 * pounds;
                break;
            case 'c':
            case 'C':
                c_pounds += pounds;
                c_sum += 1.09 * pounds;
                break;
        }
        printf("Would you like to make another selection? (y/n): ");
        while (scanf(" %c", &done) == 0)
            printf("Would you like to make another selection? (y/n): ");

        while ('\n' != getchar())
            continue;

        /* When the user is done "shopping", they can enter 'n' and this 
         * will take them to "check out" and calculate their grand total.
         */
    } while ('Y' == toupper(done));

    subtotal = a_sum + b_sum + c_sum;
    if (subtotal >= 100)
        subtotal *= 0.95;

    total_pounds = a_pounds + b_pounds + c_pounds;
    if (total_pounds <= 5)
        shipping = 6.50;
    else if (total_pounds > 5 && total_pounds < 20)
        shipping = 14.00;
    else
        shipping = 14.00 + (0.50 * total_pounds);

    grand_total = subtotal + shipping;

    printf("Here is a summary of your order\n");
    printf("================================\n");
    printf("%.2lf lbs artichokes @ $2.05/lb = $%.2lf\n", a_pounds, a_sum);
    printf("%.2lf lbs beets @ $1.15/lb = $%.2lf\n", b_pounds, b_sum);
    printf("%.2lf lbs carrots @ $1.09/lb = $%.2lf\n", c_pounds, c_sum);
    printf("5%% discount = $%.2lf\n", (a_sum + b_sum + c_sum) - subtotal);
    printf("Subtotal = $%.2lf\n", subtotal);
    printf("Shipping = $%.2lf\n", shipping);
    printf("Grand total = $%.2lf\n", grand_total);

    return 0;
} 
