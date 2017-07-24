/* This program prompts the user to enter three sets of five double 
 * numbers each.  The program then uses separate functions to compute the
 * average of each set, compute the average of all the values, and 
 * determine the largest value of all 15 numbers entered.  The main 
 * function then displays the results.
 */
#include <float.h>
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 5

void createArray(double (*mat)[COLS], int rows) {

    int scanResult;

    /* 'mat' is a pointer to a size 5 array of doubles.  Therefore, 
     * dereferencing it gives you an array value.  An array value is equal
     * to the address of its first element.  Therefore '*mat' is the 
     * address of a double value, and thus it can be assigned to a pointer
     * to a double.
     */
    double *pNum = *mat;
    int count = 1;

    /* Initially, this part of the code was giving me a runtime error
     * called 'Abort trap: 6'.  The reason this was happening was because
     * I had 'count' initialized to 0.  When 'count' reached a value of 15
     * the two-dimensional array had already been filled with 15 double 
     * values.  But since the 'count' check comes after the call to scanf
     * in the while loop expression, the program halts, waiting for you to
     * input a 16th value.  'pNum' now points to the address that is one
     * passed the end of the array, and the scanf function attempts to 
     * dereference it to store this 16th value.  The C standard guarantees
     * that the position one passed the end of an array is a valid pointer
     * (meaning that memory has been set aside by the program to hold that
     * pointer variable).  Even though this is a valid pointer, it is still
     * unsafe to dereference it because it contains an uninitialized 
     * garbage value.  Memory at that address has NOT been explicitly 
     * allocated by the program to hold a value of the type to which this
     * pointer points (in this case, a double).  Hence you get the runtime
     * error 'Abort trap: 6' for trying to access memory that hasn't been
     * allocated to the program.  This seems similar to a segfault
     * (what is the difference?).  Interestingly, the operating system
     * (MacBook Pro 2015) OSX Sierra version 10.12.5
     * doesn't immediately kill the program at that 
     * point.  The program actually runs to completion before displaying
     * the error (why is that?).  No warnings are generated by the clang
     * compiler for this, even when the -Weverything flag is set.  
     * (Apple LLVM version 8.1.0 (clang-802.0.42)).  
     * 
     * This error can be avoided even when 'count' is initialized to 0, if
     * you place the 'count' check before the call the scanf function in
     * the while loop expression.  This is because the '&&' logical 
     * operator is a short-circuit operator, and so if the 'count' check
     * returns false, the call to scanf will not occur.
     */ 
    while ((scanResult = scanf("%lf", pNum)) != EOF 
            && count < rows * COLS) {
        if (0 == scanResult) {
            printf("There was an error reading input.  Please only"
                    " enter numbers.\n");
            while ('\n' != getchar())
                continue;
        } else {

            /* This is why a pointer to a double value is needed.  You 
             * could, without error, pass '*mat' to the scanf function.
             * but you wouldn't be able to increase it to point to the 
             * next address in the two-dimensional array because you cannot
             * use the increment or decrement operators with an array 
             * value.  You need a pointer that you can increase by the size
             * of a double (8 bytes) each time around the loop because C
             * treats this 3 x 5 multidimensional array as a contiguous
             * sequence of 120 memory cells. 
             */ 
            pNum++;
            count++;
        }
    }
}
double avgSet(double *set, int n) {

    int i;
    double avg;
    double total = 0;
     
    for (i = 0; i < n; i++) 
        total += set[i];

    avg = total / n;

    return avg;
}
double avgAll(double (*mat)[COLS], int rows) {

    int i, j;
    double avg;
    double total = 0;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < COLS; j++)
            total += mat[i][j];
    }
    avg = total / (rows * COLS);

    return avg;
}
double maxValue(double (*mat)[COLS], int rows) {
    
    int i, j;
    double max = -DBL_MAX;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < COLS; j++) 
            if (mat[i][j] > max)
                max = mat[i][j];
    }
    return max;
}
int main(void) {

    int i, j;
    double mat[ROWS][COLS];
    double subarrayAvg, totAvg, max;

    printf("Enter 15 numbers to be stored in a 3 x 5 two-dimensional"
            " array:\n");
    createArray(mat, ROWS);
    printf("\n");

    for (i = 0; i < ROWS; i++) {
       for (j = 0; j < COLS; j++)
           printf("%7.2lf%s", mat[i][j], (COLS - 1 == j) ? "\n": " ");
    }
    printf("\n");

    for (i = 0; i < ROWS; i++) {
        subarrayAvg = avgSet(mat[i], COLS);
        printf("The average of sub array %d = %7.2lf\n", i, subarrayAvg);
    }
    totAvg = avgAll(mat, ROWS);
    printf("The average of all 15 numbers = %7.2lf\n", totAvg);

    max = maxValue(mat, ROWS);
    printf("The maximum value = %7.2lf\n", max);

    return 0;
} 
