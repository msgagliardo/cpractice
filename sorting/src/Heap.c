#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int A[MAX + 1];

void bubbleUp(int A[], int lastI) {
    if (lastI > 0 && A[lastI] > A[(lastI - 1) / 2]) {
        int temp = A[lastI];
        A[lastI] = A[(lastI - 1) / 2];
        A[(lastI - 1) / 2] = temp;
        bubbleUp(A, (lastI - 1)/2);
    }
}
void insert(int A[], int x, int* size) {
    (*size)++;
    A[*size - 1] = x;
    bubbleUp(A, *size - 1);
}
void bubbleDown(int A[], int i, int lastI) {
    int child, temp;
    child = 2 * i + 1;
    if (child < lastI && A[child + 1] > A[child])
        child++;
    if (child <= lastI && A[i] < A[child]) {
        temp = A[i];
        A[i] = A[child];
        A[child] = temp;
        bubbleDown(A, child, lastI);
    }
}
void deletemax(int A[], int* size) {
    int temp = A[0];
    A[0] = A[(*size - 1)];
    A[(*size - 1)] = temp;
    (*size)--;
    bubbleDown(A, 0, *size - 1);
}
/* This is the more efficient way to create a heap as outlined in 
 * the foundations book and Programming Project #5 at the end of 
 * chapter 12 of the DS book.  I have named it heapify down because it 
 * uses the 'bubbleDown' function.
 */
void heapifyDown(int A[], int lastI) {
    int i;
    for (i = (lastI - 1)/2; i >= 0; i--)
        bubbleDown(A, i, lastI);
}
void heapSort(int A[], int size) {
    /* You don't need an extra int variable.
     * You could just use size in place of i here.
     */
    int i = size;
    heapifyDown(A, size - 1);
    while (i > 0)
        deletemax(A, &i);
}
/* The other way you can heapify an array is by 
 * starting at the front of the heap and adding elements one-by-one
 * and then bubblingUp (reheapifying up) those elements.  That process 
 * is detailed on page 656 of chapter 12 of the DS book and it is 
 * reproduced in this 'heapifyUp' function.  This is a LESS efficient way
 * of heapifying an array.
 */
void heapifyUp(int A[], int size) {

    int i, k, temp;
    for (i = 1; i < size; i++) {
        k = i;
        while (k > 0 && A[k] > A[(k - 1) / 2]) {
            temp = A[(k - 1) / 2];
            A[(k - 1) / 2] = A[k];
            A[k] = temp;
            k = (k - 1) / 2; 
        }
    }
}
void bd(int A[], int root, int size) {

    int temp;
    int greaterChildIndex = -1;

    if ((2 * root + 2) < size) {
        if (A[2 * root + 2] > A[2 * root + 1])
            greaterChildIndex = 2 * root + 2;
        else
            greaterChildIndex = 2 * root + 1;
    } else if ((2 * root + 1) < size)
        greaterChildIndex = 2 * root + 1;

    if (-1 != greaterChildIndex && A[root] < A[greaterChildIndex]) {
        temp = A[root];
        A[root] = A[greaterChildIndex];
        A[greaterChildIndex] = temp;
        bd(A, greaterChildIndex, size);
    }
}

void dm(int A[], int size) {
    
    if (size > 1) {
        int temp = A[0];
        A[0] = A[size - 1];
        A[size - 1] = temp;
        size--;
        bd(A, 0, size);
    }
} 
void heapSort2(int A[], int size) {

    if (NULL != A && size > 1) {
        heapifyUp(A, size);
        while (size > 1) {
            dm(A, size);
            size--;
        }
    }
}
int main(void) {
    /*int i, n, x;
    n = 0;
    // EOF is equal to a negative number, usually -1 (it is on this Mac)
    // to cause scanf to return EOF when reading from
    // stdin, use Ctrl+D on Unix, and Ctrl+Z on Windows
    while (n < MAX && scanf("%d", &x) != EOF)
        A[n++] = x;
    heapSort(A, n);
    for(i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    */
    int i;
    int test[14] = {35, 11, 4, 79, 43, 19, 22, 51, 2, 11, 87, 14, 29, 61};
    heapSort2(test, 14);
    for (i = 0; i < 14; i++)
        printf("%d  ", test[i]);
    printf("\n");

    return 0;
}

