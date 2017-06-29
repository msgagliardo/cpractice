/* This program reads input up to '#' and reports the number of times that
 * the sequence "ei" occurs.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char current_c;
    char prev_c = 0;
    int count = 0;
    
    printf("Enter some input (# to quit): ");
    while ((current_c = getchar()) != '#') {
        if ('e' == prev_c && 'i' == current_c)
            count++;

        prev_c = current_c;
    }
    printf("The sequence \"ei\" occurred %d time%s.\n", count,
            (1 == count) ? "": "s");

    return 0;
} 
         
