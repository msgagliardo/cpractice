#include <math.h>
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
 * range u <= K <= v where (v - u) is small.  When the range (v - u) is small,
 * this sorting procedure is very fast.  Distribution sorting as described in 
 * TAOCP was first developed by H. Seward in 1954 for use with radix sorting
 * techniques, and it was also published under the name 'Mathsort' by 
 * W. Feurzeig.
 *
 * In Knuth's description of 'distribution counting', the array that he calls
 * 'count' is the same size as the 'data' array.  For my implementation, I 
 * decided to make the 'count' array just the size of the range of numbers.  I
 * did this to save space.  For example, using the description of the algorithm
 * in TAOCP, if you have a 'data' array whose elements range from 500000 - 
 * 500010 you would need to allocate an array of size 500010, but your 'count'
 * array only needs to hold 10 elements.   
 */
int *distCount(int data[], int low, int high, int n) {

    int i, j;

    /* cnt_size represents the range between the highest element in 'data' and
     * the lowest element in 'data'
     */
    int cnt_size = high - low + 1;
    int count[cnt_size];

    /* the 'calloc' function is used so that a heap-dynamic array will be
     * allocated, and the elements will all initially be set to zero.  The array
     * needs to be heap-dynamic so that a pointer can safely be returned from 
     * this function.
     *
     * This array is needed because 'data' cannot be sorted 'in place' using
     * this algorithm.  That is, you cannot simply overwrite the values in the
     * 'data' array with the new sorted values.  The reason for this is because
     * the values in the 'data' array are used to index into the 'count' array.
     * If you overwrite an element in 'data', the wrong key will be used when
     * you later try to index into the 'count' array.  For example, suppose 
     * values in 'data' range from 10 - 15, and there are two 10s (the first
     * element and the last element).  By the time the last 10 in 'data' is 
     * reached, the value of 'count[0]' will be 0, and the program would try
     * to insert the 10 at 'data[-1]'
     */
    int *result = (int *) calloc(n, sizeof *result);

    /* This for loop sets all the elements of 'count' to 0 because arrays that
     * are part of the automatic storage class initally have garbage values.
     */
    for (i = 0; i < cnt_size; i++)
        count[i] = 0;
    /* This loop adds up each time a number in 'data' appears.  The number at
     * the low end of the range represents index 0 in the 'count' array.  The 
     * number at the high end of the range represents the index 'high - low'
     */
    for (i = 0; i < n; i++)
        count[data[i] - low]++;
    /* For each element in 'count' starting at index 1, the element is added to
     * the element which preceded it.  After the loop has finished, each element
     * in 'count' represents the number of elements that are <= the element at
     * 'i + low' in the 'data' array.  It's sorted position in 'data' should
     * therefore be at index 'count[i] - 1'.  That is the purpose of the last
     * for loop.
     */
    for (i = 1; i < cnt_size; i++)
        count[i] = count[i] + count[i - 1];
    for (i = 0; i < n; i++) {
        j = count[data[i] - low];
        result[j - 1] = data[i];
        /* The values in the 'count' array are decreased by 1 after the elements
         * are added to 'result' so that the next time the same element is 
         * encountered in 'data', it doesn't overwrite the same element in
         * result, but instead is placed 1 index before it.
         */
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

/* This is an implementation of the algorithm that Knuth calls "Algorithm L (
 * List insertion)" on page 96 of TAOCP Vol. 3.  On that page, Knuth concludes
 * that the "right data structure for straight insertion is a one-way, linked
 * linear list.", and that "linked allocation (Section 2.2.3) is ideally suited
 * to insertion, since only a few links need to be changed."  However, the
 * MIXAL program (Program L) on page 97 does not appear to utilize a traditonal
 * linked linear list structure (a series of nodes linked by addresses).
 *
 * Instead, it appears that the key and the link are stored together in a 
 * struct-like structure and these structures are stored in an array called 
 * 'INPUT'.  
 *
 * I decided to let the keys be the elements, themselves, in the 
 * 'data' array, and I put the links in a parallel-like array called 'links'.
 * I say 'parallel-like array' because the size of the 'links' array is one
 * greater than the size of the 'data' array. I did this so I could easily 
 * determine the index of the smallest element of the 'data' array by storing
 * it as the first element in the 'links' array.  Because of this extra index
 * in 'links', the indices 0 - 15 of the data array correspond to indices 1 - 16
 * of the 'links' array.  Each element in the 'links' array corresponds to the
 * index in the 'data' array of the next element in the sorted list.
 */
int *listInsertion(int data[], int n) {

    /* This if statement is here to ensure that only arrays that have 2 or more
     * elements are sorted.  Like the other sorting functions in this file, it
     * is possible for someone to pass a NULL pointer as the argument to 'data'
     * and a number >= 2 for n.  In this case, the behavior of the function is 
     * undefined.  You could check for this case by having another if statement
     * that encloses all of the following code, and which the expression 
     * if (NULL != data).  The less that you account for in your code, the more
     * restricted your pre-condition for using the function will be.  
     */
    if (n > 1) {
        int i, j, entry;
        /* I allocated 'links' as a heap-dynamic array so that I could safely
         * return a pointer to it.  I used the 'calloc' function so that all of
         * the elements would be initialized to 0.
         */
        int *links = (int *) calloc(n + 1, sizeof *links);
        /* Because the size of the 'links' array is 1 greater than the size of 
         * the 'data' array, index n of the 'links' array corresponds to index
         * n - 1 of the 'data' array.  This element is initially set to a
         * negative number (-1 in this case) to indicate that the n - 1 element
         * in the 'data' array is the last element of the currently sorted 
         * portion of the array.  Using a negative number makes this immediately
         * obvious given the fact that a negative number cannot be used as the
         * index of an array.
         */
        links[n] = -1;
        /* This statement sets element n - 1 of 'links' (which corresponds to 
         * element n - 2 of 'data') to the index of the last element in 'data'
         */
        links[n - 1] = n - 1;

        /* This outer for loop is like the outer for loop of straight insertion
         * sort except that it starts from the end of the array (higher indices)
         * and moves toward the front of the array (lower indices).
         */
        for (i = n - 2; i >= 0; i--) {
            entry = data[i];
            /* This inner for loop differs from the inner for loop of a straight
             * insertion sort.  The first difference is in the index 'j'.  In a
             * straight insertion, this is set equal to 'i'.  In this function,
             * however, it is set equal to i + 1.  This is done because 'j' is
             * going to be used to index into 'links', whereas 'i' was used 
             * above to index into 'data'.  In order to ensure that we are 
             * indexing into the correct corresponding element in the 'links'
             * array, we must add 1 to the 'i' index.
             *
             * The first relational expression of the for loop condition is a
             * check to make sure that we are not currently on the element that
             * is the last element in the sorted portion of the 'links' array.
             *
             * A one must be added to the result of 'links[j]' in the for loop
             * postcondition because each of the elements of 'links' represent
             * a valid index for the 'data' array.  These indices range from 
             * 0 - (n - 1), while their corresponding indices in 'links' range
             * from 1 - n.  Therefore, in order to get the correct 'j' index
             * you must add one to the result of 'links[j]'.
             */
            for (j = i + 1; links[j] >= 0 && entry > data[links[j]]; 
                    j = links[j] + 1)
                continue;

            /* If j == i + 1, then we know that entry <= data[links[j]], and 
             * consequently, it is <= the smallest element in the sorted part
             * of the array so far.  In this case, we want to set the link of 
             * the element that comes before 'entry' in the 'data' array to
             * the index of 'entry'.  The index of this element in the 'data'
             * array is i - 1.  Since the corresponding index for this element
             * in the 'links' array is one greater than this index, it will
             * simply be equal to 'i'.  We then set this element equal to the
             * index of entry in 'data' which is 'i'
             */
            if (j == i + 1) {
                links[i] = i;
            } else {
                /* If it is not the case that j == i + 1, then it means that 
                 * 'entry' is > at least one of the elements in the sorted 
                 * section of the 'data' array.  In this case, we set element
                 * 'i - 1' of 'data' (element 'i' of 'links') to point to the 
                 * the element that element 'i' of 'data' was pointing to
                 * (This corresponds to element 'i + 1' in 'links').  
                 *
                 * We then set the new link of element 'i' to the element 'j'
                 * is pointing to.  'j' represents the index of the last element
                 * that 'entry' was greater than.  
                 *
                 * We then set the link of 'j' to point to 'i', the index of 
                 * entry.
                 */
                links[i] = links[i + 1];
                links[i + 1] = links[j];
                links[j] = i;
            }
        }
        /* We then return the 'links' array which contains the indices of the
         * sorted array in order.
         */
        return links;
    }
    /* If the value of n is <= 1, then NULL is returned, because no sorting can
     * be done on an array of these sizes.  You will not get an error/undefined
     * behavior if you pass the 'free()' function in 'main' a NULL pointer.  In
     * this case, the function simply does nothing. 
     */
    return NULL;
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

/* bubbleSort is part of a family of sorting methods called 'exchange' or 
 * 'transposition' methods that systematically exchange pairs of elements that 
 * are out of order until no more such pairs exist. 
 *
 * Perhaps the most obvious way to sort by exchanges is to compare K1 and K2, 
 * interchanging R1 and R2 if the keys are out of order; then do the same to 
 * records R2 and R3, R3 and R4, etc.  During this sequence of operations, 
 * records with large keys tend to move to the right, and in fact the record 
 * with the largest key will move up to become RN.  Repetitions of the process 
 * will get the appropriate records into positions RN-1, RN-2, etc., so that 
 * all records will ultimately be sorted.  
 *
 * “[...] The method is called ‘bubble sorting’ because large elements ‘bubble 
 * up’ to their proper position, by contrast with the ‘sinking sort’ (that is, 
 * straight insertion) in which elements sink down to an appropriate level.  
 * The bubble sort is also known by more prosaic names such as ‘exchange 
 * selection’ or ‘propagation.’
 *
 * The most important thing to realize about bubbleSort is “After each pass 
 * through the file, it is not hard to see that ALL RECORDS ABOVE AND INCLUDING
 * THE LAST ONE TO BE EXCHANGED MUST BE IN THEIR FINAL POSITION, SO THEY NEED 
 * NOT BE EXAMINED ON SUBSEQUENT PASSES.”  (Knuth, Vol. 3, 105-107)
 */ 
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
                /* In order to keep track of the last index of an exchange,
                 * every time an exchange happens, 'lastIndex' is set equal to
                 * the index of the for loop 'i'
                 */
                lastIndex = i;
            }
        }
        /* If there were exchanges that took place, 'lastIndex' will then be 
         * set to the index of the last exchange, and 'bound' will then be set
         * equal to this value.  This will let us know how much of the list
         * we will have to traverse in the next for loop iteration.
         */
        bound = lastIndex;
        /* 'lastIndex' is set back to 'first' so that if no exchanges take place
         * during the next for loop, 'bound' will be equal to 'first' and the 
         * program will stop.
         */
        lastIndex = first;
    }
}

/* This method is also known as Batcher's parallel method and it is described 
 * by Knuth on pg. 111 of TAOCP, Vol. 3.  It is similar to shellsort, but has 
 * a worst-case running time of O(nlog^2(n)) which is in between O(n^1.5) and
 * O(n^2).  
 *
 * If we're going to have an exchange algorithm whose running time is faster
 * than order N^2, we need to select some nonadjacent pairs of keys for
 * comparisons; otherwise we will need as many exchanges as the original 
 * permutation has inversions, and the average number of inversions is 
 * ((N^2) - N) / 4.  An ingeneous way to program a sequence of comparisons,
 * looking for potential exchanges, was discovered in 1964 by K. E. Batcher.
 *
 * All comparisons/exchanges specified by a given iteration of the for loop can
 * be done simultaneously, on computers or networks that allow parallel 
 * computations.  With such parallel operations, sorting is completed in 
 * 0.5ceil(lgN)*(ceil(lgN) + 1) steps, and this is about as fast as any general
 * method known.  What are the average and best-case running times?
 */
void mergeExchangeSort(int data[], int n) {

    if (n > 1) {
        double t, intpart, eo2, dpo2;
        int po2, i, q, r, d, p, temp;

        /* 'log10' computes the common (base-10) logarithm of the argument.
         * This function is defined in the math.h header file.  It takes a 
         * double as an argument and returns a double.  Additionally, C99 adds
         * 'log10f' which takes a float and returns a float, and 'log10l' which
         * takes a long double and returns a long double.  Header <tgmath.h>
         * provides a type-generic macro version of this function.  If the 
         * argument is negative, a "domain error" is caused.  If the argument 
         * is 0, it may cause a "pole error" (depending on the library 
         * implementation).  If a "domain error" occurs, the global variable 
         * 'errno' is set to 'EDOM'.  If a "pole error" occurs, the global 
         * variable 'errno' is set to 'ERANGE'. 
         *
         * errno is a preprocessor macro that expands to a thread-local (since 
         * C11) modifiable lvalue of type int. Several standard library 
         * functions indicate errors by writing positive integers to errno. 
         * Typically, the value of errno is set to one of the error codes listed
         * in <errno.h> as macro constants beginning with the letter E followed
         * by uppercase letters or digits. The value of errno is 0 at program 
         * startup, and although library functions are allowed to write positive
         * integers to errno whether or not an error occurred, library functions
         * never store 0 in errno. Library functions perror and strerror can be
         * used to obtain textual descriptions of the error conditions that 
         * correspond to the current errno value.
         *
         * There is a 'log2' function, that I could have used instead of
         * converting the base 10 logarithm of 'n' to the base 2 logarithm of
         * 'n', but the 'log2' function is a C99 addition, so I decided to use
         * 'log10' to make the code more portable.
         */
        t = log10(n) / log10(2);
        /* The 'modf' function of part of the <math.h> header file, and it takes
         * a double, and a double* as arguments, and returns a double.  It
         * breaks its first argument into an integral and a fractional part.  
         * The integer part is stored in the object pointed to by the second
         * argument, and the fractional part is returned by the function.  Both
         * parts have the same sign as the first argument.  Alternatively, 
         * you could simple use the 'ceil' function when calculating 't'.  Then
         * you would not need to use the 'modf' function, and the if-statement
         * below would not be necessary.  (See SortingAlgs.c on the master 
         * branch).
         */
        if (modf(t, &intpart) != 0)
            t = intpart + 1;
        eo2 =  t - 1;
        dpo2 = pow(2, eo2);
        po2 = (int) dpo2;
        p = po2;

        do {
            q = po2;
            r = 0;
            d = p;

            while (1) {
                for (i = 0; i < n - d; i++) {
                    /* The expression 'i&p' MUST BE IN PARENTHESES BECAUSE
                     * the bitwise AND operator '&' has a lower precedence than
                     * the relational equality operator '=='.  Without the 
                     * parentheses, 'p == r' would be evaluated.
                     */
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

void quick_sort(int data[], int n) {

    if (n > 1) {
        int m = 4;
        int capacity = 0;
        int size = 0;
        int a = (n - 1) / 2;

        while (a > m) {
            capacity++;
            a = (a - 1) / 2;
        }

        int stack[2 * capacity];
        
        int pivotIndex;
        int n1, n2;
        int low = 0;
        int high = n - 1;
        
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
            if (size <= 0) {
                break;
            }
            else {
                size--;
                high = stack[size];
                size--;
                low = stack[size];
            }
        }
        for (int i = 0; i < n; i++)
            printf("%4d%s", data[i], (0 == (i + 1) % 20) ? "\n": "");
        printf("\n");
        insertionSort(data, 0, n);
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
/*
int main(void) {

    double t, fractpart, intpart, eo2, dpo2;
    int po2, i, q, r, d, p, temp;

    t = log10(16) / log10(2);
    if (modf(t, &intpart) != 0)
        t = intpart + 1;
    eo2 =  t - 1;
    dpo2 = pow(2, eo2);
    po2 = (int) dpo2;
    p = 4;
    d = p;
    r = 0;

    printf("p = %d\n", p);
    for (i = 0; ((i&p) == r) && (i < (16 - d)); i++)
        printf("i = %d\n", i);

    return 0;
}
*/
