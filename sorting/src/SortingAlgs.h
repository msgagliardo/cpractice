#include "heap.h"

typedef struct INT_NODE {
    int element;
    struct INT_NODE *next;
} INT_NODE;

void selectionSort(int data[], int first, int n);
int *compCount(int data[], int first, int n);
int *distCount(int data[], int low, int high, int n);
void insertionSort(int data[], int first, int n);
int *listInsertion(int data[], int n);
void shellSort(int data[], int first, int n);
void bubbleSort(int data[], int first, int n);
void mergeExchangeSort(int data[], int n);
void merge(int data[], int first, int n1, int n2);
void mergeSort(int data[], int first, int n);
void natural_mergeSort(int data[], int n);
int partition(int data[], int first, int n);
void quickSort(int data[], int first, int n);
void quick_sort(int data[], int first, int n);
void radixExchangeSort(int data[], int n);
INT_NODE *split(INT_NODE *pList);
INT_NODE *linkedMerge(INT_NODE *pList, INT_NODE *pList2);
INT_NODE *linkedMergeSort(INT_NODE *pList);

