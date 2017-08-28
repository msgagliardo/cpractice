/* This program completes exercise 8 from chapter 12 by providing
 * definitions for the functions 'make_array' and 'show_array'.
 */
#include <stdio.h>
#include <stdlib.h>

int *make_array(int elem, int val);
void show_array(const int ar[], int n);

int main(void) {

    int *pa;
    int size;
    int value;

    printf("Enter the number of elements: ");
    while (scanf("%d", &size) == 1 && size > 0) {
        printf("Enter the initialization value: ");
        scanf("%d", &value);
        pa = make_array(size, value);
        if (pa) {
            show_array(pa, size);
            free(pa);
        }
        printf("Enter the number of elements (< 1 to quit): ");
    }
    printf("Done.\n");

    return 0;
}
int *make_array(int elem, int val) {

    int i;
    int *arr = (int *) malloc(elem * sizeof(int));
    
    for (i = 0; i < elem; i++)
        arr[i] = val;

    return arr;
}
void show_array(const int ar[], int n) {

    int i;
    
    for (i = 0; i < n; i++)
        printf("%d%s", ar[i], (0 == (i + 1) % 8) ? "\n": " ");

    if (0 != i % 8)
        printf("\n");
}

