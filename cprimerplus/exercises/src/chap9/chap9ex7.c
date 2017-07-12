/* This program reads characters from standard input to end-of-file.  For 
 * each character, the program reports whether it is a letter, and if it 
 * is a letter, it reports its numerical location in the alphabet.  A 
 * separate function is used to check whether the character is a letter 
 * to report its numerical location.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int letter_loc(char ch) {
    char lower_ch = tolower(ch);
    int result;

    if (isalpha(lower_ch))
        result = lower_ch - 'a' + 1;
    else
        result = -1;

    return result;
}
int main(void) {
    int ch;
    int letter_count = 0;
    int loc;

    printf("Enter input and I will tell you the alphabetic position of"
            " your letters:\n");
    while ((ch = getchar()) != EOF) {

        if ((loc = letter_loc((char) ch)) > 0) {
            printf("%3d", loc);
            letter_count++;
        }
        if (letter_count > 0 && letter_count % 25 == 0)
            printf("\n");
    }
    return 0;
}


