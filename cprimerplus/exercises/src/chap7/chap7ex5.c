/* This program reads reads input up to #, and replaces each period with 
 * an exclamation mark, each exclamation mark with a two exclamation marks
 * and reports the number of substituions it has made.  This program is 
 * exactly the same as chap7ex4.c except that a switch statement is used
 * instead of an if...else if...else statement.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char c;
    int subs = 0;

    printf("Enter some input and I will make substitutions (# to quit): ");
    while ((c = getchar()) != '#') {
        switch (c) {
            case '.':
                putchar('!');
                subs++;
                break;
            case '!':
                printf("!!");
                subs++;
                break;
            default:
                putchar(c);
                break;
        }
    }
    printf("\nThe number of substitutions made was %d.\n", subs);

    return 0;
}
