/* This program calculates how long it takes for the number of friends 
 * in a social media group to surpass Dunbar's number (~150) when the 
 * initial number of friends is 5 and every week 2 friends are lost and
 * the number of friends doubles.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int numFriends = 5;
    int week = 0;

    printf("%9s%9s\n", "Weeks", "Friends");
    printf("%9d%9d\n", week, numFriends);
    while (numFriends <= 150) {
        numFriends = (numFriends - 2) * 2;
        week++;
        printf("%9d%9d\n", week, numFriends);
    }
    return 0;
}   
