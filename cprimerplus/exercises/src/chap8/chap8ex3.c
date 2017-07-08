/* This program reads characters from input until encountering EOF and then
 * reports the number of uppercase letters, the number of lowercase 
 * letters, and the number of other characters in the input.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
    int c;
    int total = 0;
    int lcase_count = 0;
    int ucase_count = 0;
    int space_count = 0;
    int digit_count = 0;
    int punct_count = 0;
    int cntrl_count = 0;

    puts("Enter some input and I will count the characters used:");
    while ((c = getchar()) != EOF) {
        if (isupper(c))
            ucase_count++;
        else if (islower(c))
            lcase_count++;
        else if (' ' == c)
            space_count++;
        else if (isdigit(c))
            digit_count++;
        else if (ispunct(c))
            punct_count++;
        else if (iscntrl(c)) { 
            cntrl_count++;
            /* The isspace function considers '\t', '\f', '\v', '\n', and 
             * '\r' white-space control codes as well as the ' ' character
             * to be spaces.  So here, we are counting a ' ' character to 
             * be both a control code and a space character.
             */
            if (isspace(c))
                space_count++;
        }
        total++;
    }
    printf("Upper case = %-4d Lower case%3s %-4d Spaces%14s %-4d\n", 
            ucase_count, "=", lcase_count, "=", space_count);
    printf("Digits%6s %-4d Punctuation = %-4d Control Characters = %-4d\n",
            "=", digit_count, punct_count, cntrl_count);
    printf("Total # of characters = %-4d\n", total);

    return 0;
} 

