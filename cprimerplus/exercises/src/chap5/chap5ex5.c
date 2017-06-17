/* This program asks the user for an integer, and then sums all the integers 
 * from 1 up to and including the user-entered integer.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int userData;
    int sum = 0;
    
    printf("Enter a positive integer and I will sum all the integers "
        "from 1 up to and including your integer: ");    
    scanf("%d", &userData);

    /* Note:  You could easily do this without a loop by using the following
     * formula for an arithmetic series ( n*(n+1)/2 )
     */
    while (userData >= 1) {
        sum += userData;
        userData--;
    }
    printf("The sum is %d\n", sum);

    return 0;
}
