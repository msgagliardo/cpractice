/* This program creates and tests in a loop a function that returns the 
 * number of times it has been called.
 */
#include <stdio.h>
#include <stdlib.h>

/* Alternatively, this definition could be placed inside the 'how_many()'
 * function, but then it would only be in scope while that function was 
 * executing.
 */
static int calls;

int how_many(void) {
    
    calls++;
    return calls;
}
int main(void) {

    int i = 0;
    while (i < 10) {
        printf("The how_many() function has been called %d time%s\n", 
                how_many(), (0 == i) ? "": "s");
        i++;
    }
    return 0;
}

