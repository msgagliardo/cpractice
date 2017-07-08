/* This program reads input as a stream of characters until encountering 
 * EOF.  The program then prints each input character and its ASCII 
 * decimal value.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int c;
    int count = 0;

    /* The non-printing characters in ASCII range from [0-31], and 127. The
     * space character (' ') is decimal 32.  Zero is decimal 48.  'A' is 
     * decimal 65 and 'a' is decimal 97.  All of the nonprinting characters
     * can be typed in terminal by typing control followed by another 
     * character.  The other character is the character that is obtained by
     * adding 64 (decimal) to the ASCII code for the control character. For
     * example, to type the null character (ASCII 0) you would type 
     * Cntrl+@ which will display as ^@ in terminal (known as caret 
     * notation).  In some terminals, you don't have to hold the shift key
     * to type @.  For example, you could just type Cntrl+2 and ^@ would
     * display in terminal.  But on this MacBook Pro (2015) you must press
     * Cntrl+Shift+2 to display ^@ in terminal.
     */
    puts("Enter some input and I will display all the ASCII codes in it:");
    while ((c = getchar()) != EOF) {
        if (count > 0 && count % 10 == 0)
            printf("\n");
        
        if (c < 32 && c >= 0) { 
            printf(" ^%c = %3d ", c + 64, c);

            if (10 == c) {
                printf("\n");
                count = 0;
                continue;
            }

        } else if (c > 32)
            printf("%3c = %3d ", c, c);
        else
            printf("'%c' = %3d ", c, c);

        count++;
    } 
    return 0;
}  
