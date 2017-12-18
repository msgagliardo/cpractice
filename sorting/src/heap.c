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

/* Initially I was using a bubbleDown() function that was recursive, while 
 * Knuth’s was iterative.  It was easy to convert to an iterative function 
 * because the bubbleDown() function was tail recursive.  Also, one thing that 
 * I was doing in my recursive bubbleDown() function that Knuth wasn’t doing 
 * in the function described above, was swapping the last element with the 
 * first, and then swapping the root element with the children that it was 
 * less than.
 *
 * Knuth, on the other hand, saves the last element in a variable, copies the 
 * old root to the last array position, and then compares the children with the
 * saved value in the variable.  If the saved value is less than the greater 
 * child, he simply copies the greater child over its parent.  This speeds up 
 * the function by eliminating swaps throughout the reheapification process.
 *
 * The explanation of exercise 18 on how to speed up heapsort even more is 
 * given on page 642.  In this modification, the saved key is not even 
 * compared with the children during the bubble down process.  Knuth simply 
 * copies the greater child over its parent until reaching the bottom of the 
 * heap (a leaf node).  This eliminates the comparisons on the way down the 
 * heap.  However, if the element’s correct position is not at this leaf node, 
 * you must “siftup” the heap by setting the current parent index to the child,
 * and setting the parent to the parent of this new child.  If the saved key is
 * <= the parent key, or the child has index 0, the child will be set equal to 
 * the saved element.  However, if the saved key is > the parent key, you must 
 * set the child key equal to the parent key, and “siftup” the heap again.
 *
 * This may seem like you’re not saving any time, because you have to go back 
 * up the heap if the saved key is not <= the leaf node.  However, you do 
 * eliminate a considerable number of comparisons.  The reason for this, as 
 * Knuth explains on page 642 is that 83.7% of the time, the node that you are
 * bubbling down will end up as a leaf node.
 *
 * If you do this during the heap creation phase, this will not be the case 
 * because the array is in random order, and it is less likely that the leaves 
 * are low numbers.  However, when done on the 16 numbers given by Knuth, you 
 * only make 8 comparisons as opposed to 13 if you use my original bubbleDown()
 * function for heap creation.  Also, when used on the following 16 numbers, 9 
 * comparisons are made if you use the “siftup” method, while my original 
 * function makes 12 comparisons.  This is in line with C. J. H. McDiarmid and 
 * B. A. Reed's assertion that 0.232N comparisons on the average are saved
 * during the heap creation phase.  
 *
 * You will, however, end up making more assignments using the “siftup” method 
 * if a key’s correct position is at a high node.  You will then end up making 
 * unnecessary assignments as you go down the heap, assigning children records 
 * to parent records, and then back up the heap assigning parent records to 
 * children records.  You are, in effect, trading excess comparisons for excess
 * assignments.  This is fine if comparisons take more machine level 
 * instructions than assignments on a particular machine.  
 *
 * For this reason, I have NOT chosen to use the modificaton suggested in 
 * exercise 18 for the heap creation phase.  Therefore, the 'heapifyDown()' 
 * function passes a boolean argument of 'false' to the 'iBubbleDown()' 
 * function.
 */
void iBubbleDown(int A[], int root, int lastI, bool delmax) {

    /* When 'delmax' is false, the iBubbleDown function has been called by
     * the 'heapifyDown()' function.  In this case, the 'root' parameter 
     * equals the index that we start at.  However, when 'delmax' is true, 
     * the iBubbleDown function has been called from the 'deletemax()' function.
     * In the case, the root parameter equals the VALUE of the key of the new
     * node that we are bubbling down (that is, it is equal to the key of the
     * record that was at index 'size - 1').
     */ 
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

/* Originally, this heapSort function was implemented according to the
 * descriptions in the DS book and the FOCS book.  I have since updated to 
 * conform to the description in Knuth's TAOCP, Vol 3., pg. 144.  That is,
 * I've included an iterative bubbleDown() function (iBubbleDown()) to replace
 * the recursive one.  
 *
 * The average running time of heapsort according to Knuth is 16NlgN + 0.01N.
 * For small values of N, heapsort is slower than insertion sort and is even 
 * slower than straight selection sort.  As N gets larger, heapsort will be 
 * superior to shellsort, but its aymptotic running time of 16NlgN (23.08NlnN)
 * will never beat quicksort's 8.09NlgN (11.67NlnN).  On the other hand, 
 * quicksort is faster only on the average.  It has a worst-case running time
 * of order N^2 whereas heapsort has a worst-case running time of 
 * 18Nfloor(lgN) + 38N.  Heapsort and mergesort are the only algorithms that 
 * guarantee O(NllogN) running time in the worst case.  Records are rearranged
 * in place.
 *
 * Implementing the modifcation that Knuth suggests on pg. 642 exercise 18 will
 * speed up the algorithm to have an average-case running time of 
 * 13NlgN + O(N), which is still slower than quicksort's average case.
 * Heapsort was discovered by J. W. J. Williams in 1964.
 */
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
