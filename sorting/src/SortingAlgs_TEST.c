/* A file for testing the algorithms developed in SortingAlgs.c. */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
/* If you don't include the SortingAlgs.h header file, then you need to 
 * directly declare the INT_NODE type in this file because it is used in
 * the 'makeList' function.
 *
 * These headers are not just here for documentation purposes.  If you 
 * leave off these headers and try to compile and link the SortingAlgs.c,
 * heap.c, and SortingAlgs_TEST.c files using only the C standard library
 * headers, you will get the following warning on this 2015 MacBook Pro;
 *
 * SortingAlgs_TEST.c:51:17: warning: implicit declaration of function
 * 'linkedMergeSort' is invalid in C99 [-Wimplicit-function-declaration]
 *      myNewList = linkedMergeSort(myList);
 * 
 * Due to trying to use the 'linkedMergeSort' function in this file prior
 * to it first being declared.  This raises the question, why does the 
 * compiler require that you prototype this function in a header file
 * if it is already declared and defined in one of the other source (.c)
 * files that you are compiling and linking?
 */
#include "SortingAlgs.h"

/* Unlike automatic variables, static variables are initialized 
 * automatically to zero if you don't initialize them.  This rule applies
 * to elements of a statically defined array too.  Unlike the case for 
 * automatic variables, you can use only constant expressions to 
 * initialize static variables (This includes constants declared using
 * the 'const' keyword, see below).  In Java, you can initialize fields with
 * other variables.
 */
const int x = 3;

/* This initialization below is allowed because x is considered a 
 * compile-time constant.
 */
int z = x;

/* This initialization below is NOT allowed because z is NOT a compile-time
 * constant.
 */
//int w = z;

/* This array is viewed as a VLA by C even though x is declared using the 
 * const keyword (arrays must be initialized with integer literals or 
 * integer literal expressions).  Because it is viewed as a VLA, it must
 * have automatic storage duration (externally defined variables have
 * static storage duration).
 *
 * The C99 and C11 standards require compilers to recognize the first 63 
 * characters for local identifiers and the first 31 characters for 
 * external identifiers. This revises the previous requirement of 
 * recognizing the first 31 characters for local identifiers and the first 
 * six characters for external identifiers.
 *
 * QUESTION:  Why is the following definition of 'external_array' only 
 * considered a warning when compiled with '-std=c89' and '-std=c99'?
 * (MacBook Pro 2015: Apple LLVM version 8.1.0 (clang-802.0.42)).
 */
int external_array[x];

/* This is called a 'referencing declaration' as opposed to a 'defining
 * declaration'.  The keyword 'extern' indicates that a declaration is not
 * a definition because it instructs the compiler to look elsware for 
 * the place where 'testNumber' is actually defined.  That is, the place
 * where memory is actually allocated for the variable.  In this case, 
 * the 'testNumber' variable was defined in the 'heap.c' file.  
 *
 * Note that an external variable defined in one file is not available to 
 * a second file unless it is also declared (by using extern) in the 
 * second file. An external declaration by itself only makes a variable 
 * potentially available to other files. Historically, however, many 
 * compilers have followed different rules in this regard. Many Unix 
 * systems, for example, enable you to declare a variable in several files 
 * without using the extern keyword, provided that no more than one 
 * declaration includes an initialization. If there is a declaration with 
 * an initialization, it is taken to be the definition.
 *
 * Alternatively, you can put the 'extern' referencing declaration in a 
 * header file and include that header file in all the source files that 
 * you wish to use that external variable.  See question on Stack Overflow 
 * entitled, "How do I use extern to share variables between source files?"
 *
 * Note 1: if the header defines the variable without the extern keyword, 
 * then each file that includes the header creates a 'tentative definition' 
 * of the variable.  (Look up why tentative definitions are possible.  
 * But you can, for whatever reason, define a variable twice in the
 * same file if they are outside of any function.)
 *
 * Note 2: if the header defines and initializes the variable, then only 
 * one source file in a given program can use the header (because there can
 * be only one initialized definition of a particular global variable in a 
 * program)
 *
 * The C language has six keywords that are grouped together as 
 * storage-class specifiers. They are auto, register, static, extern, 
 * _Thread_local, and typedef. The typedef keyword doesn’t say anything 
 * about memory storage, but it is thrown in for syntax reasons. In 
 * particular, in most cases you can use no more than one storage-class 
 * specifier in a declaration, so that means you can’t use one of the other
 * storage-class specifiers as part of a typedef. The one exception is that
 * _Thread_local may be used together with static and extern.
 */
extern int testNumber;

/* Both c89 and c99 allow you to have redefinitions of external variables.
 * (I've heard these called 'tentative definitions'.  You can only have one
 * initializaton, however).  NO WARNING IS GENERATED FOR THIS.  The
 * following 3 defintions of 'dragon', however, are not allowed for local 
 * variables.  This would produce an error at compile-time (This holds 
 * even if the local variable has static storage duration).  You are allowed
 * to the following with the 'dragon' variable only if each of the
 * identifiers use the same type ('declaration specifier').  If you
 * initialize a external variable, you cannot then assign to it externally.
 * For example, you cannot have the statement 'dragon = 7.7;' after 
 * 'double dragon = 5.5'.  The compiler will think that you are trying to
 * redefine dragon with an implicit type of 'int'.
 *
 * QUESTION:  Why does the compiler think that an external assignment is 
 * a definition?
 */
double dragon;
double dragon = 5.5;
double dragon;

/* You can have multiple declarations of the same function, and they won't
 * cause an error (They won't even cause a warning), even if they are 
 * declared in header files.
 */
INT_NODE* makeList(void);
INT_NODE* makeList(void);

INT_NODE* makeList(void) {
    int num;
    INT_NODE *pHead = NULL, *pCurrentNode = NULL;

    while (scanf("%d", &num) != EOF) {
        if (NULL == pHead) {
            pHead = (INT_NODE *)malloc(sizeof(INT_NODE));
            pHead->element = num;
            pHead->next = NULL;
            pCurrentNode = pHead;
        } else {
            pCurrentNode->next = (INT_NODE *)malloc(sizeof(INT_NODE));
            pCurrentNode = pCurrentNode->next;
            pCurrentNode->element = num;
            /* If you don't set the next field to NULL, at runtime you may
             * get a "Segmentation fault: 11."  (What determines if you 
             * get a segmentation fault?  Sometimes it doesn't happen). 
             * This presumably occurs when you try to iterate over the 
             * linked list and your stopping case is cursor == NULL.  
             * This is because the uninitalized pointer 'next' in the 
             * struct object has a garbage value by default.
             */
            pCurrentNode->next = NULL;
        }
    }
    return pHead;
}

int main(void) {
    /* This is considered a variable length array even though it uses x
     * (a constant declared using the 'const' keyword) for its size.  As 
     * such it must use the automatic storage class.  Static arrays, both in
     * functions, and those externally defined, must use literal integer
     * constants or literal integer constant expressions for their size.
     * The return value of the 'sizeof' operator is considered a 
     * a constant expression.
     */
    /*
    testNumber = 88;
    //static int external_array[sizeof(int)];
    printf("The external variable 'testNumber' = %d\n", testNumber);
    INT_NODE *cursor = NULL;
    INT_NODE *myList = makeList();
    INT_NODE *myNewList = NULL;
    */
   
    int test[16] = {35, 11, 4, 79, 43, 19, 22, 51, 
                    2, 11, 87, 14, 29, 61, 3, 17};

    int knuth[16] = {503, 87, 512, 61, 908, 170, 897, 275, 
                     653, 426, 154, 509, 612, 677, 765, 703};

    int knuth_sorted[16] = {61, 87, 154, 170, 275, 426, 503, 509,
                            512, 612, 653, 677, 703, 765, 897, 908};

    int knuth_reversed[16] = {908, 897, 765, 703, 677, 653, 612, 512,
                              509, 503, 426, 275, 170, 154, 87, 61};
    int knuth_one[1] = {908};
    /*
    3 [11, 10, 12, 1, -1, 7, 4, 9, 13, 11, 5, 2, 8, 15, 6, 14] 
    */

    int similar[30] = {11, 12, 14, 12, 15, 10, 11, 13, 13, 11,
                       10, 11, 13, 12, 12, 15, 14, 12, 13, 11,
                       10, 13, 12, 11, 14, 14, 11, 15, 13, 10};
    int *distSorted;
    int *links;
    /*
    for (cursor = myList; cursor != NULL; cursor = cursor->next) 
        printf("%d%s", cursor->element,
                        (NULL == cursor->next) ? "\n": "  ");
    
    myNewList = linkedMergeSort(myList);

    for (cursor = myNewList; cursor != NULL; cursor = cursor->next)
        printf("%d%s", cursor->element, (NULL == cursor->next) ? "\n": "  ");
    */
    /* When you iterate over myList a second time, not all of the elements
     * are printed out (sometimes only 1 or 2).  Presumably the 
     * linkedMergeSort function destroys the original list?  (Is there any
     * way to avoid this?).  You will need to make a copy of the linked 
     * list beforehand if need be.
     */

    /*
    for (cursor = myList; cursor != NULL; cursor = cursor->next) 
        printf("%d%s", cursor->element,
                        (NULL == cursor->next) ? "\n": "  ");
    */

    /*
    int i;
    int *counts;
    int sorted[16];

    for (i = 0; i < 16; i++)
        printf("%4d", knuth[i]);
    printf("\n");
    //shellSort(test, 0, 16);
    counts = compCount(knuth, 0, 16);
    for (i = 0; i < 16; i++)
        printf("%4d", counts[i]);
    printf("\n");

    for (i = 0; i < 16; i++)
        sorted[counts[i]] = knuth[i];
    for (i = 0; i < 16; i++)
        printf("%4d", sorted[i]);
    printf("\n");

    free(counts);
    */

    int i;
    /*
    for (i = 0; i < 1; i++)
        printf("%4d%s", knuth_one[i], (0 == (i + 1) % 20) ? "\n": "");
    printf("\n");
    links = listInsertion(knuth_one, 1);
    
    if (links) {
        for (i = 0; i < 17; i++)
            printf("%4d%s", links[i], (0 == (i + 1) % 20) ? "\n": "");
        printf("\n\n");

        for (i = 0; links[i] >= 0; i = links[i] + 1)
            printf("%4d%s", knuth_one[links[i]], (0 == (i + 1) % 20) ? "\n": "");
        printf("\n");
    }
    free(links);
    */
    quick_sort(knuth, 16);
    for (i = 0; i < 16; i++)
        printf("%4d%s", knuth[i], (0 == (i + 1) % 20) ? "\n": "");
    printf("\n\n");

    quick_sort(knuth_sorted, 16);
    for (i = 0; i < 16; i++)
        printf("%4d%s", knuth_sorted[i], (0 == (i + 1) % 20) ? "\n": "");
    printf("\n\n");

    quick_sort(knuth_reversed, 16);
    for (i = 0; i < 16; i++)
        printf("%4d%s", knuth_reversed[i], (0 == (i + 1) % 20) ? "\n": "");
    printf("\n\n");

    printf("Ceil of 4.341 = %lf\n", ceil(4.341));
    
    return 0;
}
