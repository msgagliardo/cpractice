/* This program requests the user to enter an uppercase letter and then it uses
 * nested loops to produce a pyramid pattern.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char letter;
    int i, j, k, m;

    printf("Please enter an uppercase letter: ");
    scanf(" %c", &letter);

    while (letter < 'A' || letter > 'Z') {
        printf("That was not valid input\n"
                "Please enter an uppercase letter: ");
        scanf(" %c", &letter);
    }
    
    for (i = 'A'; i <= letter; i++) {
        for (j = 0; j <= letter - i; j++)
            printf(" ");

        for (k = 'A'; k <= i; k++)
            printf("%c", k);

        for (m = i - 1; m >= 'A'; m--)
            printf("%c", m);

        printf("\n");
    } 
    return 0;
} 
        
