/* This program generates 1,000 random numbers in the range [1, 10].  It
 * then prints how many times each number was produced.  The purpose is to
 * examine the randomness of a particular random-number generator by
 * checking to see if the numbers appear in roughly equal amounts.  When
 * this program is used to generate 1,000 random numbers, each number
 * appears ~100 times (you rarely see a number appearing less then 70 time
 * or greater than 130 times).
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define NUMS 1000
#define HI 10
#define LO 1

int main(void) {

    int i;
    int rand_num;

    /* I used an array with static storage duration because it guarantees
     * that each array element is initialized to 0 if not explicitly
     * initialized.  Alternatively, you could declare the array to be an
     * automatic array, but you would have to explicitly initialize each
     * element to zero before adding to its value.
     */
    static int counts[SIZE];
    srand((unsigned) time(NULL));
    
    for (i = 0; i < NUMS; i++) {
        int rand_num = rand() % (HI - LO + 1) + LO;

        /* Every time that the ith number in the range appears, it is added
         * to the ith - 1 element in the 'counts' array.
         */
        counts[rand_num - 1]++;
    }
    for (i = 0; i < SIZE; i++)
        printf("Number %2d appears %3d times.\n", i + 1, counts[i]);

    return 0;
}
    
