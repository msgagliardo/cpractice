#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* This is a static variable with external linkage, sometimes referred to 
 * as an external variable.  An external variable has file scope, external
 * linkage (it can be used in other translation units), and static storage
 * duration by default.  
 *
 * You create an external variable by placing a DEFINING declaration 
 * outside of any function. As a matter of documentation, an external 
 * variable can additionally be declared inside a function that uses it by 
 * using the extern keyword. If a particular external variable is defined 
 * in one source code file (.c) and is used in a second source code file, 
 * (.c) declaring the variable in the second file with extern is mandatory. 
 * If you declare this extern variable in the second file outside of any
 * functions, it will have file scope, whereas if you declare it inside 
 * a function, it will have block scope.
 *
 * When you define a variable that you intend to be an external variable,
 * you can either initialize it, or simply define it and then assign to 
 * the variable in another file.  Technically speaking, you don't have 
 * to.  You could create several 'tentative definitions' of the variable 
 * over multiple files (BUT THIS IS NOT A GOOD IDEA).  Technically, you 
 * could also 'initialize' the referencing ('extern') declarations in the 
 * other file if the variable is declared there outside of any functions 
 * (file scope).  This will still generate a warning, though.  If you try 
 * to initialize the 'extern' variable inside of a function in another 
 * file, you will get an compilation error.
 */
int testNumber = 554455;
int A[MAX + 1];

/* Functions, too, have storage classes. A function can be either external 
 * (the default) or static. (C99 adds a third possibility, the inline 
 * function, discussed in Chapter 16, “The C Preprocessor and the C Library.
 * ”) An external function can be accessed by functions in other files, but
 * a static function can be used only within the defining file. Consider, 
 * for example, a file containing this function prototypes:
 *
 * static double beta(int, int);
 *
 * Because this beta() is restricted to one file, you can use a different 
 * function having the same name in the other files. One reason to use the 
 * static storage class is to create functions that are private to a 
 * particular module, thereby avoiding the possibility of name conflicts. 
 * The usual practice is to use the extern keyword when declaring functions
 * defined in other files. This practice is mostly a matter of clarity 
 * because a function declaration is assumed to be extern unless the keyword
 * static is used.
 */
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
void iBubbleDown(int A[], int root, int lastI, bool delmax) {

    if (delmax == false) {
        int child, rootValue;
        rootValue = A[root];
        child = 2 * root + 1;
        while (child <= lastI) {
            if (child < lastI && A[child + 1] > A[child])
                child++;
            if (rootValue < A[child]) {
                A[root] = A[child];
                root = child;
                child = 2 * child + 1;
            } else {
                A[root] = rootValue;
                break;
            }
        }
        if (child > lastI)
            A[root] = rootValue;
    } else {
        int child, parent;
        parent = 0;
        child = 2 * parent + 1;
        while (child <= lastI) {
            if (child < lastI && A[child + 1] > A[child])
                child++;
            A[parent] = A[child];
            parent = child;
            child = 2 * child + 1;
        }
        if (root <= A[parent])
            A[parent] = root;
        else {
            child = parent;
            parent = (parent - 1) / 2;
            while (child > 0) {
                if (root <= A[parent]) {
                    A[child] = root;
                    break;
                }
                A[child] = A[parent];
                child = parent;
                parent = (parent - 1) / 2;
            }
            if (child == 0)
                A[child] = root;
        }
    }
}

void deletemax(int A[], int size) {

    if (size > 1) { 
        int rootValue = A[(size - 1)];
        A[(size - 1)] = A[0];
        size--;
        iBubbleDown(A, rootValue, size - 1, true);
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
        iBubbleDown(A, i, lastI, false);
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
