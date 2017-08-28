/* This program generates a list of 100 random numbers in the range [1, 10]
 * and then sorts them in decreasing order.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define HI 10
#define LO 1

void insertionSort(int data[], int first, int n) {

    int i, j, entry;

    for (i = first + 1; i < n; i++) {
        entry = data[i];
        for (j = i; first < j && data[j - 1] < entry; j--)
            data[j] = data[j - 1];
        data[j] = entry;
    }
}
int main(void) {

    int i;
    int arr[SIZE];
    srand((unsigned) time(NULL));

    for (i = 0; i < SIZE; i++) 
        arr[i] = rand() % (HI - LO + 1) + LO; 

    insertionSort(arr, 0, SIZE);
   
    for (i = 0; i < SIZE; i++)
        printf("%2d%s", arr[i], (0 == (i + 1) % 20) ? "\n": " ");

    return 0;
}
