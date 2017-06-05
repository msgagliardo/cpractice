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
    child = 2*i + 1;
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
void heapify(int A[], int lastI) {
    int i;
    for (i = (lastI - 1)/2; i >= 0; i--)
        bubbleDown(A, i, lastI);
}
void heapSort(int A[], int size) {
    // you don't need an extra int variable.
    // You could just use size in place of i here
    int i = size;
    heapify(A, size - 1);
    while (i > 0)
        deletemax(A, &i);
}
int main(void) {
    int i, n, x;
    n = 0;
    // EOF is equal to a negative number, usually -1 (it is on this Mac)
    // to cause scanf to return EOF when reading from
    // stdin, use ctrl-d on Unix, and ctrl-z on Windows
    while (n < MAX && scanf("%d", &x) != -1)
        A[n++] = x;
    heapSort(A, n);
    for(i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}
