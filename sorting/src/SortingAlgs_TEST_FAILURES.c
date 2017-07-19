/* A file for documenting failed attempts at testing the algorithms in 
 * SortingAlgs.c, and for documenting any insights gained. 
 */ 
#include <stdio.h>
#include <stdlib.h>
#include "SortingAlgs.h"

/* If you try to run this using this makeList function, you will get the
 * error "Segmentation fault: 11" on this MacBook Pro 2015 
 * Apple LLVM version 8.1.0 (clang-802.0.42).  The following describes 
 * how segmentation faults (a.k.a. segfaults) occur: 
 *
 * "There are four common mistakes that lead to segmentation faults:
 *  dereferencing NULL, dereferencing an uninitialized pointer,
 *  dereferencing a pointer that has been freed (or deleted, in C++) or
 *  that has gone out of scope (in the case of arrays declared in functions)
 *  and writing off the end of an array."
 *
 * "A fifth way of causing a segfault is a recursive function that uses 
 *  all of the stack space. On some systems, this will cause a 
 *  'stack overflow' report, and on others, it will merely appear as 
 *  another type of segmentation fault."
 * from http://www.cprogramming.com/debugging/segfaults.html
 * 
 * The reason that this function will cause a segmentation fault is because
 * when the function returns, all the nodes that you allocated have now 
 * been deallocated and all the 'next' fields inside those nodes now point
 * to deallocated memory (they are dangling pointers).  In short, there is 
 * no good reason to create a stack allocated linked list, so DON'T do it.
 */
INT_NODE makeList(void) {
    
    INT_NODE head = {-999999999};
    int num;
    INT_NODE *pCurrentNode = &head;
    
    if (scanf("%d", &num) != EOF)
        pCurrentNode->element = num;
    else
        return head;
    
    while (scanf("%d", &num) != EOF) {
        INT_NODE newNode;
             
        newNode.element = num;
        newNode.next = NULL;
        pCurrentNode->next = &newNode;
        pCurrentNode = pCurrentNode->next;
    }
    return head;
} 
int main(void) {
     
    INT_NODE head = {-999999999};
    int num;
    INT_NODE *pCurrentNode = &head;

    if (scanf("%d", &num) != EOF) {
        head.element = num;
    
        /* Even if you move the implementation of makeList into the main
         * function, it is a bad idea.  Each time execution reaches the 
         * end of this while loop, the memory for newNode is deallocated.  
         * Therefore, all the 'next' fields in the INT_NODE structs become
         * dangling pointers, and you get undefined behavior (a.k.a. UB) 
         * when you dereference pCurrentNode dangling pointer as you 
         * attemp to iterate through the list.  On this particular system,
         * the behavior that seems to result is that the first number 
         * entered gets printed, while the last number entered (regardless
         * whether it is the fifth number or not) gets printed 4 times.
         */
        while (scanf("%d", &num) != EOF) {
            INT_NODE newNode;
                 
            newNode.element = num;
            newNode.next = NULL;
            pCurrentNode->next = &newNode;
            pCurrentNode = pCurrentNode->next;
        }
    } 
    int i;
    for (pCurrentNode = &head, i = 0; i < 5;
         pCurrentNode = pCurrentNode->next, i++)

        printf("%d  ", pCurrentNode->element);

    printf("\n");

    return 0; 
}
