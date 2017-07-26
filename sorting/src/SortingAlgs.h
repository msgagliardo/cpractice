/* I originally did not have a 'heap.h' header file, and I did not have 
 * this '#include' directive.  I originally just had the prototypes for 
 * 'bubbleDown' 'deletemax' 'heapifyDown', and 'heapSort' from heap.c.  I
 * was still able to use these functions in SortingAlgs_TEST.c and compile
 * SortingAlgs_TEST.c SortingAlgs.c and heap.c without any problems.  How
 * was teh compiler able to find where these prototypes were defined?  
 * Would you ever want to do this in production?
 */
#include "heap.h"

typedef struct INT_NODE {
    int element;
    struct INT_NODE *next;
} INT_NODE;

void selectionSort(int data[], int first, int n);
void insertionSort(int data[], int first, int n);
void merge(int data[], int first, int n1, int n2);
void mergeSort(int data[], int first, int n);
int partition(int data[], int first, int n);
void quickSort(int data[], int first, int n);
INT_NODE *split(INT_NODE *pList);
INT_NODE *linkedMerge(INT_NODE *pList, INT_NODE *pList2);
INT_NODE *linkedMergeSort(INT_NODE *pList);
/*
void bubbleDown(int A[], int i, int lastI);
void deletemax(int A[], int* size);
void heapifyDown(int A[], int lastI);
void heapSort(int A[], int size);
*/
