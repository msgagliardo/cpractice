/* This program creates a function called chline that prints a character 
 * in a range of columns.
 */
#include <stdio.h>
#include <stdlib.h>

void chline(char c, int i, int j) {
    int k, m;

    for (k = 0; k < i; k++)
        printf(" ");

    for (m = k; m <= j; m++)
        printf("%c", c);
}
int main(void) {
    chline('A', 25, 50);
    printf("\n");

    return 0;
} 
