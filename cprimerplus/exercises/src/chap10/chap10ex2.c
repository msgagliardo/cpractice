/* This program initializes an array-of-double and then copies the contents
 * of the array into three other arrays.  Three separate functions are used
 * to make the three separate arrays.
 */
#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

void arrCopy1(double target[], double source[], int n) {
    int i;

    for (i = 0; i < n; i++)
        target[i] = source[i];

}
void arrCopy2(double *target, double *source, int n) {
    int i;

    for (i = 0; i < n; i++)
        *(target + i) = *(source + i);

}
void arrCopy3(double target[], double source[], double *n) {

    while (source < n)
        *target++ = *source++;

}
int main(void) {
    double arr1[SIZE] = {4.12, 74.4, 6.45, 8.91, 11.15, 83.1, 42.1};
    double arr2[SIZE], arr3[SIZE], arr4[SIZE];
    int i;

    arrCopy1(arr2, arr1, SIZE);
    for (i = 0; i < SIZE; i++)
        printf("%lf%s", arr2[i], (SIZE - 1 == i) ? "\n": "  ");

    arrCopy2(arr3, arr1, SIZE);
    for (i = 0; i < SIZE; i++)
        printf("%lf%s", arr3[i], (SIZE - 1 == i) ? "\n": "  ");

    arrCopy3(arr4, arr1, arr1 + SIZE);
    for (i = 0; i < SIZE; i++)
        printf("%lf%s", arr4[i], (SIZE - 1 == i) ? "\n": "  ");

    return 0;
}
