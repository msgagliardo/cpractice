/* This program creates a function that takes a character and two integers.
 * The first integer specifies the number of times a character is to be 
 * printed on a line, and the second integer specifies the number of lines
 * to be printed.
 */
#include <stdio.h>
#include <stdlib.h>

void printch(char ch, int cols, int lines) {
    int i, j;

    for (i = 0; i < lines; i++) {
        for (j = 0; j < cols; j++)
            printf("%c", ch);
        printf("\n");
    }
}
int main(void) {
    printch('B', 25, 10);

    return 0;
} 
