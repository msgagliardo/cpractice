#include <stdio.h>
#include <stdlib.h>
/* If you do not include the SortingAlgs.h header file, then you have to 
 * place the INT_NODE type directly in this file because the linked list
 * mergesort functions use this type.
 */
#include "SortingAlgs.h"


void selectionSort(int data[], int first, int n) {

    int i, j, temp, small;
    for (i = first; i < n - 1; i++) {
        small = i;

        for (j = i + 1; j < n; j++)
            if (data[j] < data[small])
                small = j;

        temp = data[small];
        data[small] = data[i];
        data[i] = temp;
    }
}

/* This algorithm is the one described in (Knuth, Vol. 3, 75). Knuth calls this
 * algorithm "Comparison counting". This implemention is a rewrite of Program
 * C on page 76.  THIS ALGORITHM DOES NOT ACTUALLY SORT THE ELEMENTS IN 'DATA',
 * it only returns a heap-allocated int array indicating the number of elements
 * of the 'data' array that each element of the 'data' array is greater than.
 * 'counts' and 'data' are parallel arrays in the sense that identical indices
 * correspond to the same element.  The numbers in the returned counts array
 * indicate the indices where the corresponding elements in the 'data' array
 * should be placed.  
 *
 * The easiest (and most efficient?) way to actually sort the elements of 'data'
 * using the information in 'counts' is to allocate a new array in 'main' and 
 * place the elements of 'data' in the positions specified by 'counts'.  This
 * is shown in the SortingAlgs_TEST.c file.
 */
int *compCount(int data[], int first, int n) {
    
    /* 'calloc()' is used instead of 'malloc' because it initializes all the 
     * elements in the array to 0.
     */
    int *counts = (int *) calloc(n, sizeof *counts);
    if (counts) {
        int i, j;
        for (i = first; i < n - 1; i++) {
            for (j = i + 1; j < n; j++) {
                if (data[i] >= data[j])
                    counts[i]++;
                else
                    counts[j]++;
            }
        }
    }
    return counts;
}

/* This algorithm is the one described in (Knuth, Vol. 3, 78).  Knuth calls this
 * algorithm 'Distribution counting'. This algortihm is not implemented in MIXAL
 * in TAOCP.  This 'distribution counting' algorithm is "primarily applicable
 * in the case that many equal keys are present, and when all keys fall into the
 * range u <= K <= v where (v - u) is small.
 */
int *distCount(int data[], int low, int high, int n) {

    int i, j;
    int count[high - low + 1];
    int *result = (int *) calloc(n, sizeof *result);

    for (i = 0; i < (high - low + 1); i++)
        count[i] = 0;
    for (i = 0; i < n; i++)
        count[data[i] - low]++;
    for (i = 1; i < (high - low + 1); i++)
        count[i] = count[i] + count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        j = count[data[i] - low];
        result[j - 1] = data[i];
        count[data[i] - low] = j - 1;
    }
    return result;
}

void insertionSort(int data[], int first, int n) {

    int i, j, entry;
    for (i = first + 1; i < n; i++) {
        entry = data[i];
        for (j = i; (first < j) && (data[j - 1] > entry); j--)
            data[j] = data[j - 1];
        data[j] = entry;
    }
}

/* As can be seen from the following implementation, shellSort is a modification
 * of insertionSort that can achieve running times of O(n^1.5) if properly 
 * optimized.  Increment sequences have been found that lower the worst-case # 
 * of compares to n^1.2, but these are primarily of academic interest.
 *
 * Average-number of compares for randomly ordered input is unknown.
 *
 * Best case running time is still O(n)?
 */
void shellSort(int data[], int first, int n) {

    int i, j, entry;

    /* h is the current value in the 'increment sequence'.  Each value in the
     * increment sequence represents the distance between sequential elements
     * in a subarray. Any increment sequence that ends with a value of 1 can
     * be used (when h = 1 shellsort becomes 'straight insertion sort'). You
     * can store the values of the increment sequence in a local array, or if
     * you want to save space, you can calculate them as shown below.
     */ 
    int h = 1;

    /* This while loop calculates the increment sequence 1, 4, 13, 40, 121,
     * 364... Notice that the difference between the ith + 1 term, and the ith 
     * term is 3^i.  That is, the value of the ith term in the sequence can
     * be found by doing the following summation; (3^(i-1) + 3^(i-2) + ... +
     * 3^0).  
     *
     * Originally, the while loop expression had a '<=' sign. The '<' sign must
     * be used (The problem occurs if 'n' is equal to one of the values in the
     * increment sequence.  'h' will then have the same value of 'n', and you
     * will get a "java.lang.IndexOutOfBoundsException" at the 
     * 'entry = data[i];' assignment (if you are compiling this in Java).
     */
    while (h < (n - first) / 3)
        h = 3 * h + 1;

    while (h >= 1) {

        /* Each time i is increased, the program begins sorting the next
         * subarray.  That is, if 'first' equals 0, then initially i = h.  For
         * each value of i, insertion sort is done on the subarrays;
         *
         * [0, h, 2h, 3h,...]
         * [1, 1+h, 1+2h, 1+3h,...]
         * [2, 2+h, 2+2h, 2+3h,...]
         * .
         * .
         * .
         * [h-1, (h-1)+h, (h-1)+2h, (h-1)+3h,...]
         */
        for (i = first + h; i < n; i++) {
            entry = data[i];

            /* Initially I had the first conditional expression inside the 
             * for loop as 'j > first + i % h'.  Both will work, but why 
             * perform an extra calculation if you don't have to? If 'first' is
             * 0, the value of 'j' cannot be < 'h'.  If 'j' were allowed to be
             * < 'h', then you would get a 'java.lang.IndexOutOfBoundsException'
             * in the second relational expression in the for loop condition;
             * 'data[j - h] > entry' if you were compiling this code in Java
             * because the index would be negative.
             *
             * Because of this last point, the short circuit logical operator
             * '&&' is REQUIRED so that when the first relational expression
             * is false, the second one does not get checked.  Because of the 
             * way that '&&' operates, you MUST have the 'data[j - h] > entry'
             * expression second.
             */
            for (j = i; j >= first + h && data[j - h] > entry; j -= h)
                data[j] = data[j - h];
            data[j] = entry;
        }
        /* This decreases h to the next value in the increment sequence. Because
         * the value of each subsequent increment decreases, Knuth states that
         * shellsort is also known as 'the diminishing increment sort'.  
         *
         * I initially used the expression statement 'h = (h - 1) / 3'. However,
         * since integer division is used, 'h = h / 3' can be used since the 
         * result will be truncated to an integer.  This also saves us one 
         * subtraction operation.
         */
        h = h / 3;
    }
}

void merge(int data[], int first, int n1, int n2) {

    /* This would be considered a variable length array which is a C99 
     * feature and is not ANSI C compliant (pretty sure ANSI C requires
     * the size of stack dynamic arrays to be integer literal or manifest
     * constants). The easiest way to modify this code to be ANSI C 
     * compliant if you still want to keep the same function header is to
     * declare temp to be an integer pointer to heap allocated memory like
     * so, int *temp = (int *) malloc(sizeof(int) * (n1 + n2));.  The other
     * alternative is to modify the merge function (see the algorithms pdf
     * on Google Drive in the "sync" folder).
     */
    int temp[n1 + n2];
    int copied = 0, copied1 = 0, copied2 = 0;
    int i;

    while (copied1 < n1 && copied2 < n2) {
        if (data[first + copied1] <= data[first + n1 + copied2])
            temp[copied++] = data[first + copied1++];
        else
            temp[copied++] = data[first + n1 + copied2++];
    }
    while (copied1 < n1)
        temp[copied++] = data[first + copied1++];

    for (i = 0; i < copied; i++)
        data[first + i] = temp[i];
}

void mergeSort(int data[], int first, int n) {

    int n1, n2;

    if (n > 1) {
        n1 = n / 2;
        n2 = n - n1;

        mergeSort(data, first, n1);
        mergeSort(data, first + n1, n2);
        merge(data, first, n1, n2);
    }
}

int partition(int data[], int first, int n) {

    int pivot = data[first];
    int low = first + 1;
    int high = first + n - 1;
    int temp;

    while (high > low) {
        while (low < first + n && data[low] <= pivot)
            low++;
        while (high >= first && data[high] > pivot)
            high--;

        if (high > low) {
            temp = data[low];
            data[low] = data[high];
            data[high] = temp;
            low++;
            high--;
        }
    }
    if (data[high] < pivot) {
        data[first] = data[high];
        data[high] = pivot;
    }
    return high;
}

void quickSort(int data[], int first, int n) {

    if (n > 1) {
        int pivotIndex = partition(data, first, n);
        int n1 = pivotIndex - first;
        int n2 = n - n1 - 1;
        quickSort(data, first, n1);
        quickSort(data, pivotIndex + 1, n2);
    }
} 
/* the split function is needed when you are using a linked list because 
 * we cannot do the splitting inside the mergeSort function simply by 
 * passing the size as an argument and dividing it by 2.  This is because 
 * we cannot index into a linked list like we can an array.
 */
INT_NODE *split(INT_NODE *pList) {

    INT_NODE *pList2;

    if (NULL == pList)
        return NULL;
    else if (NULL == pList->next)
        return NULL;
    else {
        pList2 = pList->next;
        pList->next = pList2->next;
        pList2->next = split(pList2->next);
        return pList2;
    }
}

INT_NODE *linkedMerge(INT_NODE *pList, INT_NODE *pList2) {
    
    if (NULL == pList)
        return pList2;
    else if (NULL == pList2)
        return pList;
    else if (pList->element <= pList2->element) {
        pList->next = linkedMerge(pList->next, pList2);
        return pList;
    } else {
        pList2->next = linkedMerge(pList, pList2->next);
        return pList2;
    }
} 

INT_NODE *linkedMergeSort(INT_NODE *pList) {
    
    INT_NODE *pList2;

    if (NULL == pList)
        return NULL;
    else if (NULL == pList->next)
        return pList;
    else {
        pList2 = split(pList);
        return linkedMerge(linkedMergeSort(pList), linkedMergeSort(pList2));
    } 
} 
