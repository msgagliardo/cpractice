/* This program is a modification of the guessing program of Listing 8.4.
 * It uses a "binary search strategy" to guess a number chosen by the user
 * that is between [1-100].
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
    int guess = 50;
    int c;
    int low = 1;
    int high = 100;

    printf("Pick and integer from 1 to 100.  I will try to guess it.\n");
    printf("Respond with a 'y' if my guess is right, with an 'L'\n"
            "if it is too low, or with an 'h' if it is too high.\n");
    printf("Uh...is your number %d?\n", guess);
    c = getchar();

    while (toupper(c) != 'Y' && c != EOF) {

        while ('\n' != getchar())
            continue;

        if (toupper(c) == 'H') {
            high = guess;
            if (high - low == 1) {
                if (1 == low) {
                    printf("Your number must be 1.\n");
                    break;
                } else {
                    printf("Either your guess isn't an integer or you're "
                        "trying to fool me!\n");
                    break;
                }
            } 
            guess = low + ((high - low) / 2);
        } else if (toupper(c) == 'L') {
            low = guess;
            if (high - low == 1) {
                if (100 == high) {
                    printf("Your number must be 100.\n");
                    break;
                } else {
                    printf("Either your guess isn't an integer or you're "
                        "trying to fool me!\n");
                    break;
                } 
            } 
            guess += (high - guess) / 2;
        } else 
            printf("You must enter 'y', 'L', or 'h'.  Try again.\n");

        printf("Uh...is your number %d?\n", guess);
        c = getchar();
    }
    puts("Thank you for playing!");

    return 0;
}   
