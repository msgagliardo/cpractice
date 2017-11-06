/* A file for testing the algorithms developed in SortingAlgs.c. */
#include <stdio.h>
#include <stdlib.h>
#include "SortingAlgs.h"
#include <time.h>


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
            pCurrentNode->next = NULL;
        }
    }
    return pHead;
}
int main(void) {
/*    
    INT_NODE *cursor = NULL;
    INT_NODE *myList = makeList();
    INT_NODE *myNewList = NULL;
   
    int test[14] = {35, 11, 4, 79, 43, 19, 22, 51, 2, 11, 87, 14, 29, 61};
    for (cursor = myList; cursor != NULL; cursor = cursor->next) 
        printf("%d%s", cursor->element,
                        (NULL == cursor->next) ? "\n": "  ");

    myNewList = linkedMergeSort(myList);

    for (cursor = myNewList; cursor != NULL; cursor = cursor->next)
        printf("%d%s", cursor->element,
                        (NULL == cursor->next) ? "\n": "  ");
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

    /* The following series of for loops creates an array of random integers and
     * sorts it
     */
    /*
    int test[200];
    int i;

    srand((unsigned) time(NULL));
    for (i = 0; i < 200; i++)
        test[i] = rand() % 250 + 1;
    for (i = 0; i < 200; i++)
        printf("%3d%s", test[i], ((i + 1) % 10 == 0) ? "\n": "  ");
    printf("\n");
    shellSort(test, 100, 200);
    for (i = 0; i < 200; i++)
        printf("%3d%s", test[i], ((i + 1) % 10 == 0) ? "\n": "  ");
    printf("\n");
    */

    int knuth[16] = {503, 87, 512, 61, 908, 170, 897, 275, 
                     653, 426, 154, 509, 612, 677, 765, 703};

    int knuth_sorted[16] = {61, 87, 154, 170, 275, 426, 503, 509,
                            512, 612, 653, 677, 703, 765, 897, 908};

    int knuth_reversed[16] = {908, 897, 765, 703, 677, 653, 612, 512,
                              509, 503, 426, 275, 170, 154, 87, 61};
    int knuth_one[1] = {908};

    int *links[4];

    int i, j;
    int n = 16;
/*
    for (i = 0; i < n; i++)
        printf("%4d%s", knuth[i], (0 == (i + 1) % 20) ? "\n": "");
    printf("\n");

    links[0] = listInsertion(knuth, n);
    links[1] = listInsertion(knuth_sorted, n);
    links[2] = listInsertion(knuth_reversed, n);
    links[3] = listInsertion(knuth_one, 1);

    printf("\nknuth:\n");
    for (i = 0; links[0][i] >= 0; i = links[0][i] + 1)
        printf("%4d%s", knuth[links[0][i]], (0 == (i + 1) % 20) ? "\n": "");
    printf("\n"); 

    printf("\nknuth_sorted:\n");
    for (i = 0; links[1][i] >= 0; i = links[1][i] + 1)
        printf("%4d%s", knuth_sorted[links[1][i]],
                (0 == (i + 1) % 20) ? "\n": "");
    printf("\n");

    printf("\nknuth_reversed:\n");
    for (i = 0; links[2][i] >= 0; i = links[2][i] + 1)
        printf("%4d%s", knuth_reversed[links[2][i]],
                (0 == (i + 1) % 20) ? "\n": "");
    printf("\n");

    if (!links[3])
        fputs("\nArray already sorted.  Only one element.\n", stdout);

    for (i = 0; i < 4; i++)
        free(links[i]);
*/

    return 0;
}
