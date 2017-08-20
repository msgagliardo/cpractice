#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int A[MAX + 1];

void bubbleUp(int A[], int lastI) {
    if (lastI > 0 && A[lastI] > A[(lastI - 1) / 2]) {
        int temp = A[lastI];
        A[lastI] = A[(lastI - 1) / 2];
        A[(lastI - 1) / 2] = temp;
        bubbleUp(A, (lastI - 1) / 2);
    }
}
void insert(int A[], int x, int* size) {
    (*size)++;
    A[*size - 1] = x;
    bubbleUp(A, *size - 1);
}
void bubbleDown(int A[], int root, int lastI) {
    int child, temp;
    child = 2 * root + 1;
    if (child < lastI && A[child + 1] > A[child])
        child++;
    if (child <= lastI && A[root] < A[child]) {
        temp = A[root];
        A[root] = A[child];
        A[child] = temp;
        bubbleDown(A, child, lastI);
    }
}
void deletemax(int A[], int size) {

    if (size > 1) { 
        int temp = A[0];
        A[0] = A[(size - 1)];
        A[(size - 1)] = temp;
        size--;
        bubbleDown(A, 0, size - 1);
    }
}
/* This is the more efficient way to create a heap as outlined in 
 * the foundations book and Programming Project #5 at the end of 
 * chapter 12 of the DS book.  I have named it heapify down because it 
 * uses the 'bubbleDown' function.
 */
void heapifyDown(int A[], int lastI) {

    int i;
    for (i = (lastI - 1) / 2; i >= 0; i--)
        bubbleDown(A, i, lastI);
}
void heapSort(int A[], int size) {
    /* You don't need an extra int variable.
     * You could just use size in place of i here.
     */
    if (NULL != A && size > 1) {
        heapifyDown(A, size - 1);
        
        /* The only purpose to passing an address to deletemax is so you
         * don't need the statement 'size--' in this function.  The 
         * deletemax function decreases it for you with this statement 
         * '(*size)--;'  See the 'heapSort2' function which looks exactly 
         * the same, except that it doesn't pass an address to dm.
         * See the 'heapSort' implementation in FOCS book chapter 5.
         */
        while (size > 1) {
            deletemax(A, size);
            size--;
        } 
    }
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
void heapSort2(int A[], int size) {

    if (NULL != A && size > 1) {
        heapifyUp(A, size);
        while (size > 1) {
            deletemax(A, size);
            size--;
        }
    }
}
