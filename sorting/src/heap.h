#include <stdbool.h>

void bubbleUp(int A[], int lastI);
void insert(int A[], int x, int* size);
void bubbleDown(int A[], int i, int lastI);
void iBubbleDown(int A[], int root, int lastI, bool delete);
void deletemax(int A[], int size);
void heapifyDown(int A[], int lastI);
void heapSort(int A[], int size);
void heapifyUp(int A[], int size);
void heapSort2(int A[], int size);

