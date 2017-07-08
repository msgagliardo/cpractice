/* This program counts the number of characters in its input up to the 
 * end of file.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int count = 0;

    puts("Enter some input and I will count the characters (Ctrl+D to"
            " quit):");
    while (getchar() != EOF)  
        count++;

    printf("You entered %d characters including the newline\n", count);
    
    return 0;
} 

