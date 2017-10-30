#include <math.h>
#include <stdio.h>
#include <stdlib.h>
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

int *compCount(int data[], int first, int n) {
    
    int *counts = (int*) calloc(n, sizeof *counts);
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

int *distCount(int data[], int low, int high, int n) {

    int i, j;
    int cnt_size = high - low + 1;
    int count[cnt_size];
    int *result = (int *) calloc(n, sizeof *result);

    for (i = 0; i < cnt_size; i++)
        count[i] = 0;
    for (i = 0; i < n; i++)
        count[data[i] - low]++;
    for (i = 1; i < cnt_size; i++)
        count[i] = count[i] + count[i - 1];
    for (i = 0; i < n; i++) {
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

int *listInsertion(int data[], int n) {
    
    if (n > 1) {
        int i, j, entry;
        int *links = (int *) calloc(n + 1, sizeof *links);
        links[n] = -1;
        links[n - 1] = n - 1;

        for (i = n - 2; i >= 0; i--) {
            entry = data[i];
            for (j = i + 1; links[j] >= 0 && entry > data[links[j]]; 
                    j = links[j] + 1)
                continue;

            if (j == i + 1) {
                links[i] = i;
            } else {
                links[i] = links[i + 1];
                links[i + 1] = links[j];
                links[j] = i;
            }
        }
        return links;
    }
    return NULL;
}

void shellSort(int data[], int first, int n) {

    int i, j, entry;
    int h = 1;

    while (h < (n - first) / 3)
        h = 3 * h + 1;

    while (h >= 1) {
        for (i = first + h; i < n; i++) {
            entry = data[i];
            for (j = i; j >= first + h && data[j - h] > entry; j -= h)
                data[j] = data[j - h];
            data[j] = entry;
        }
        h = h / 3;
    }
}

void bubbleSort(int data[], int first, int n) {

    int i, temp;
    int lastIndex = first;
    int bound = n - 1;

    while (bound > first) {

        for (i = first; i < bound; i++) {
            if (data[i] > data[i + 1]) {
                temp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = temp;
                lastIndex = i;
            }
        }
        bound = lastIndex;
        lastIndex = first;
    }
}

void mergeExchangeSort(int data[], int n) {

    if (n > 1) {
        double t, fractpart, intpart, eo2, dpo2;
        int po2, i, q, r, d, p, temp;

        t = log10(n) / log10(2);
        if (modf(t, &intpart) != 0)
            t = intpart + 1;
        eo2 = t - 1;
        dpo2 = pow(2, eo2);
        po2 = (int) dpo2;
        p = po2;

        do {

            q = po2;
            r = 0;
            d = p;

            while (1) {
                for (i = 0; i < n - d; i++) {
                    if ((i&p) == r) {
                        if (data[i] > data[i + d]) {
                            temp = data[i];
                            data[i] = data[i + d];
                            data[i + d] = temp;
                        }
                    }
                }
                if (q == p)
                    break;
                d = q - p;
                q = q / 2;
                r = p;
            }
            p = p / 2;

        } while (p > 0);
    }
}

void merge(int data[], int first, int n1, int n2) {

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
