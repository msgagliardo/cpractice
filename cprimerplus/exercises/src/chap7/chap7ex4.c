/* This program reads input up to #, replaces each period with an 
 * exclamation mark, replaces each exclamation mark initially present with 
 * two exclamation marks, and then reports at the end the number of 
 * substitutions made. 
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char c;
    int subs = 0;

    printf("Enter some input and I will make substitutions (# to quit): ");
    while ((c = getchar()) != '#') {
        if ('.' == c) {
            putchar('!');
            subs++;
        } else if ('!' == c) {
            printf("!!");
            subs++;
        } else
            putchar(c);
    }
    printf("\nThe number of substitutions made was %d.\n", subs);

    return 0;
} 
