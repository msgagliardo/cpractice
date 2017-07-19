/* A file for testing the algorithms developed in SortingAlgs.c. */
#include <stdio.h>
#include <stdlib.h>
#include "SortingAlgs.h"

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
    INT_NODE *cursor = NULL;
    INT_NODE *myList = makeList();
    INT_NODE *myNewList = NULL;
   
    for (cursor = myList; cursor != NULL; cursor = cursor->next) 
        printf("%d%s", cursor->element,
                        (NULL == cursor->next) ? "\n": "  ");

    myNewList = linkedMergeSort(myList);

    for (cursor = myNewList; cursor != NULL; cursor = cursor->next)
        printf("%d%s", cursor->element,
                        (NULL == cursor->next) ? "\n": "  ");

    /* When you iterate over myList a second time, not all of the elements
     * are printed out (sometimes only 1 or 2).  Presumably the 
     * linkedMergeSort function destroys the original list?  (Is there any
     * way to avoid this?).  You will need to make a copy of the linked 
     * list beforehand if need be.
     */
    for (cursor = myList; cursor != NULL; cursor = cursor->next) 
        printf("%d%s", cursor->element,
                        (NULL == cursor->next) ? "\n": "  ");

    return 0;
}
