/* This program shows a menu offering a choice of addition, subtraction,
 * multiplication, or division.  After getting your choice, the program 
 * asks for two numbers and then performs the requested operation.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
    char operation;
    float operand1, operand2;
    int scanResult;

    do {
        printf("Enter the operation of your choice:\n");
        printf("a. add           s. subtract\n");
        printf("m. multiply      d. divide\n");
        printf("q. quit\n");

        /* Under what conditions would scanf with the %c format specifier 
         * return zero?  Return EOF?
         */
        scanResult = scanf(" %c", &operation);
        while (scanResult == 0 || (tolower(operation) != 'a' && 
                    tolower(operation) != 's' && tolower(operation) != 'm'
                    && tolower(operation) != 'd' 
                    && tolower(operation) != 'q'))  {

            if (1 == scanResult) 
                printf("Please enter only the 'a', 's', 'm', 'd', or 'q'"
                        " characters.\n");
            else {
                printf("There was an error reading the input.\n");
                exit(EXIT_FAILURE);
            }
            while ('\n' != getchar())
                continue;

            printf("Enter the operation of your choice:\n");
            printf("a. add           s. subtract\n");
            printf("m. multiply      d. divide\n");
            printf("q. quit\n");

            scanResult = scanf(" %c", &operation);
        } 
        while ('\n' != getchar())
            continue;

        if ('q' == tolower(operation)) {
            puts("Bye.");
            return 0;
        }
        printf("Enter first number: ");
        scanResult = scanf("%f", &operand1);
        while (scanResult == 0) {
            printf("Please enter a number.  Try again: ");

            while ('\n' != getchar())
                continue;

            scanResult = scanf("%f", &operand1);
        }
        while ('\n' != getchar())
            continue;

        printf("Enter second number: ");
        scanResult = scanf("%f", &operand2);
        while (scanResult == 0 || (operand2 == 0 
                    && tolower(operation) == 'd')) {
            if (operand2 == 0 && tolower(operation) == 'd') 
                printf("Enter a number other than 0: ");
            else
                printf("Please enter a number.  Try again: ");

            while ('\n' != getchar())
                continue;
            
            scanResult = scanf("%f", &operand2);
        }
        while ('\n' != getchar())
            continue;

        switch (tolower(operation)) {
            case 'a':
                printf("%f + %f = %f\n", operand1, operand2, 
                        operand1 + operand2);
                break;
            case 's':
                printf("%f - %f = %f\n", operand1, operand2,
                        operand1 - operand2);
                break;
            case 'm':
                printf("%f * %f = %f\n", operand1, operand2,
                        operand1 * operand2);
                break;
            case 'd':
                printf("%f / %f = %f\n", operand1, operand2,
                        operand1 / operand2);
                break;
        }
    } while (1);
}    
            
    

        
        

