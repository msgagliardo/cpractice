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

    return 0;
}
