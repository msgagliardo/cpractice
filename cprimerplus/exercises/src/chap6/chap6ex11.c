/* This program reads eight integers into an array and then prints them in 
 * reverse order.
 */
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main(void) {
    intmax_t nums[8];
    intmax_t temp;
    int i, j;
    
    printf("Enter eight integers and I will print them in reverse order: ");
    for (i = 0; i < 8; i++) {
        if (scanf("%" SCNdMAX, &nums[i]) != 1) {
            fprintf(stderr, "Invalid input\n");
            exit(EXIT_FAILURE);
        }
    }
    for (i = 0, j = 7; i < j; i++, j--) {
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    } 
    for (i = 0; i < 8; i++)
        printf("%" PRIdMAX "  %s", nums[i], (i == 7) ? "\n": "");

    return 0;
}
