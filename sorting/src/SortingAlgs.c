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
        double t, eo2, dpo2;
        int po2, i, q, r, d, p, temp;

        t = ceil(log10(n) / log10(2));
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

void natural_mergeSort(int data[], int n) {

    if (n > 1) {

        int d, i, j, k, l, f, s, t;
        int *temp;
        s = 0;
        temp = (int *) malloc(n * sizeof(*temp));

        do {

            d = 1;
            i = 0;
            k = 0;
            j = n - 1;
            l = n - 1;
            f = 1;

            if (s == 0) {

                while (i != j) {
                    if (data[i] > data[j]) {
                        temp[k] = data[j];
                        k += d;
                        j--;
                        if (data[j] >= data[j + 1])
                            continue;
                        else {
                            temp[k] = data[i];
                            k += d;
                            i++;
                            while (data[i - 1] <= data[i]) {
                                temp[k] = data[i];
                                k += d;
                                i++;
                            }
                            f = 0;
                            d = -d;
                            t = k;
                            k = l;
                            l = t;
                        }
                    } else {
                        temp[k] = data[i];
                        k += d;
                        i++;
                        if (data[i - 1] <= data[i])
                            continue;
                        else {
                            temp[k] = data[j];
                            k += d;
                            j--;
                            while (data[j] >= data[j + 1]) {
                                temp[k] = data[j];
                                k += d;
                                j--;
                            }
                            f = 0;
                            d = -d;
                            t = k;
                            k = l;
                            l = t;
                        }
                    }
                }
                temp[k] = data[i];
            } else {

                while (i != j) {
                    if (temp[i] > temp[j]) {
                        data[k] = temp[j];
                        k += d;
                        j--;
                        if (temp[j] >= temp[j + 1])
                            continue;
                        else {
                            data[k] = temp[i];
                            k += d;
                            i++;
                            while (temp[i - 1] <= temp[i]) {
                                data[k] = temp[i];
                                k += d;
                                i++;
                            }
                            f = 0;
                            d = -d;
                            t = k;
                            k = l;
                            l = t;
                        }
                    } else {
                        data[k] = temp[i];
                        k += d;
                        i++;
                        if (temp[i - 1] <= temp[i])
                            continue;
                        else {
                            data[k] = temp[j];
                            k += d;
                            j--;
                            while (temp[j] >= temp[j + 1]) {
                                data[k] = temp[j];
                                k += d;
                                j--;
                            }
                            f = 0;
                            d = -d;
                            t = k;
                            k = l;
                            l = t;
                        }
                    }
                }
                data[k] = temp[i];
            }
            if (f == 0)
                s = 1 - s;

        } while (f == 0);
        
        if (s == 0) {
            for (i = 0; i < n; i++)
                data[i] = temp[i];
        }
        free(temp);
    }
}

int partition(int data[], int first, int n) {

    int low = first + 1;
    int high = first + n - 1;
    int middle = (high + first) / 2;
    int pivot, pivotIndex;
    int temp;

    if (data[first] <= data[middle]) {
        if (data[middle] <= data[high]) {
            pivot = data[middle];
            pivotIndex = middle;
        } else if (data[first] <= data[high]) {
            pivot = data[high];
            pivotIndex = high;
        } else {
            pivot = data[first];
            pivotIndex = first;
        }
    } else {
        if (data[middle] >= data[high]) {
            pivot = data[middle];
            pivotIndex = middle;
        } else if (data[first] >= data[high]) {
            pivot = data[high];
            pivotIndex = high;
        } else {
            pivot = data[first];
            pivotIndex = first;
        }
    }

    if (pivotIndex != first) {
        data[pivotIndex] = data[first];
        data[first] = pivot;
    }

    while (high > low) {
        while (low < first + n && data[low] < pivot)
            low++;
        while (high > first && data[high] > pivot)
            high--;

        if (high > low && data[high] < data[low]) {
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

void quick_sort(int data[], int first, int n) {

    if (n > 1 && first < n - 1) {
        int m = 9;
        int capacity = 0;
        int size = 0;
        int a = (n - 1 - first) / 2;

        while (a > m) {
            capacity++;
            a = (a - 1 - first) / 2;
        }

        int pivotIndex;
        int n1, n2;
        int low = first;
        int high = n - 1;

        if (0 == capacity) {
            pivotIndex = partition(data, low, high - low + 1);
            n1 = pivotIndex - low;
            n2 = high - pivotIndex;

            while (n1 > m || n2 > m) {
                if (n1 > m)
                    high = pivotIndex - 1;
                else if (n2 > m)
                    low = pivotIndex + 1;

                pivotIndex = partition(data, low, high - low + 1);
                n1 = pivotIndex - low;
                n2 = high - pivotIndex;
            }

        } else {

            int stack[2 * capacity];

            while (1) {
                pivotIndex = partition(data, low, high - low + 1);
                n1 = pivotIndex - low;
                n2 = high - pivotIndex;

                while (n1 > m || n2 > m) {
                    
                    if (n1 >= n2) {
                        if (n2 > m) {
                            stack[size] = low;
                            size++;
                            stack[size] = pivotIndex - 1;
                            size++;
                            low = pivotIndex + 1;
                        } else
                            high = pivotIndex - 1;
                    } else {
                        if (n1 > m) {
                            stack[size] = pivotIndex + 1;
                            size++;
                            stack[size] = high;
                            size++;
                            high = pivotIndex - 1;
                        } else
                            low = pivotIndex + 1;
                    }
                    pivotIndex = partition(data, low, high - low + 1);
                    n1 = pivotIndex - low;
                    n2 = high - pivotIndex;
                }
                if (size == 0)
                    break;
                else {
                    size--;
                    high = stack[size];
                    size--;
                    low = stack[size];
                }
            }
        }
        insertionSort(data, first, n);
    }
}

void radixExchangeSort(int data[], int n) {
    
    if (n > 1) {

        int L = 0;
        int r = n - 1;
        int b = 1;
        int size = 0;
        int i, j, temp;
        int m = 9;
        
        int max = data[0];
        for (i = 1; i < n; i++) {
            if (data[i] > max)
                max = data[i];
        }
        int bits = log10(max) / log10(2) + 1;
        int stack[2 * (bits - 1)];
                

        while (1) {
            while (r - L > m) {

                for (i = L; i < r && data[i] == data[i + 1]; i++)
                    continue;

                if (i < r) {
                    i = L;
                    j = r;

                    do {

                        while (i <= j && (data[i] >> bits - b) % 2 == 0)
                            i++;

                        while (i <= j && (data[j] >> bits - b) % 2 == 1)
                            j--;

                        if (i < j) {
                            temp = data[i];
                            data[i] = data[j];
                            data[j] = temp;
                            i++;
                            j--;
                        }
                    } while (i <= j);

                    b++;
                    if (b > bits)
                        break;
                    else if (j < L || j == r)
                        continue;
                    else if (j == L) {
                        L++;
                        continue;
                    } else {
                        if (r - j > m) {
                            stack[size++] = r;
                            stack[size++] = b;
                        }
                        r = j;
                    }
                } else
                    break;
            }
            if (0 == size) {
                insertionSort(data, 0, n);
                break;
            } else {
                L = r + 1;
                b = stack[--size];
                r = stack[--size];
            }
        }
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
