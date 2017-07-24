/* This program creates a function that sets each element in an array to
 * the sum of the corresponding elements in two other arrays, and then it
 * tests the function.
 */
#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

void sumArrays(int arr1[], int arr2[], int arr3[], int n) {

    int i;
    for (i = 0; i < n; i++)
        arr3[i] = arr1[i] + arr2[i];

}
int main(void) {
    
    int arr1[SIZE] = {2, 4, 5, 8};
    int arr2[SIZE] = {1, 0, 4, 6};
    int arr3[SIZE];
    int i;

    sumArrays(arr1, arr2, arr3, SIZE);
    
    for (i = 0; i < SIZE; i++)
        printf("%2d  ", arr1[i]);

    printf("\n");

    for (i = 0; i < SIZE; i++)
        printf("%2d  ", arr2[i]);

    printf("\n");

    for (i = 0; i < SIZE; i++)
        printf("%2d  ", arr3[i]);

    printf("\n");

    return 0;
}


     
