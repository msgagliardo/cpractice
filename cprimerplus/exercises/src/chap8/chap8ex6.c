/* This program modfies the get_first() function of Listing 8.8 so that it
 * returns the first non-whitespace character encountered.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char get_first(void) {
    int ch;
    
    ch = getchar();
    while (isspace(ch))
        ch = getchar();

    while ('\n' != getchar())
        continue;

    return ch;
} 
int main(void) {
    char ch;
    
    printf("Enter some text and I will return the first non-whitespace"
            " character:\n");
    ch = get_first();
    
    printf("The first non-whitespace character is %c\n", ch);

    return 0;
} 
       
