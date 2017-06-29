/* This program reads input until encountering # and prints each character
 * and its ASCII decimal code.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char c;
    int count = 0; 

    printf("Type some input and I will show the ASCII codes\n");
    printf("(enter # to quit): ");

    while ((c = getchar()) != '#') {
        if (count > 0 && (count % 8 == 0))
            putchar('\n');

        if ('\n' == c)
            printf("%6s(%d)", "\\n", c);
        else if (' ' == c)
            printf("%6s(%d)", "' '", c);
        else
            printf("%4c(%d)", c, c);

        count++;
    } 
    puts("Done");

    return 0;
}  
