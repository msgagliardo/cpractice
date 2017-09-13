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

void insertionSort(int data[], int first, int n) {

    int i, j, entry;
    for (i = first + 1; i < n; i++) {
        entry = data[i];
        for (j = i; (first < j) && (data[j - 1] > entry); j--)
            data[j] = data[j - 1];
        data[j] = entry;
    }
}

void shellSort(int data[], int first, int n) {

    int i, j, entry;
    int h = 1;

    while (h <= n / 3)
        h = 3 * h + 1;

    while (h >= 1) {
        for (i = first + h; i < n; i += h) {
            entry = data[i];
            for (j = i; j > first && data[j - h] > entry; j -= h)
                data[j] = data[j - h];
            data[j] = entry;
        }
        h = (h - 1) / 3;
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
