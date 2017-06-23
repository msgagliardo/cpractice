/* This program calculates how long it will take Chuckie to empty his 
 * bank account if he has a million dollars in it that earns 8% annually
 * and he withdraws $100,000 on the last day of each year.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double sum = 1000000;
    int t;

    for (t = 0; sum > 0; t++) {
        sum -= 100000;
        sum *= 1.08;
    }
    printf("Chuckie will run out of money after %d years\n", t);

    return 0;
} 
