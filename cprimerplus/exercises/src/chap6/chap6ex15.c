/* This program reads in a line of input and then prints the line in reverse
 * order.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char line[256], name[10];
    int low, high;
    char temp;
    int i = 0;
    int j;
    
    /* To read a line of input using scanf, you must use %c specifier 
     * because you cannot more than one word using the %s specifier even
     * if you use a field width modifier.  Even with a large number 
     * preceding the s specifier, input will halt at the first whitespace
     * character following a string of non-whitespace characters.  Unlike
     * the %s specifier, using the %c specifier will not automatically 
     * append a null character to the end of the entered text.  (When you
     * use the %s specifier, you must make sure that the array is 1 
     * character longer than the length of the maximum allowed string 
     * to account for this null character).  When a newline is encountered
     * the %s specifier puts it back into the input buffer.  In contrast
     * the %c specifier reads all characters including a newline.  Because
     * of this, the following while loop breaks when a newline is read.  
     * The loop can also be exited if the number of characters read is 
     * greater than 255. */
     
    /* It is better to put the (i < 256) expression first so that a 
     * character cannot be read into position 256 which is out of bounds
     * of the array. */
    printf("Enter a line of text and I will reverse it:\n");
    while (i < 256 && scanf("%c", &line[i]) == 1) { 
        if ('\n' == line[i])
            break;
        i++;
    }

    /* At this point, i is either equal to 256 (if no newline was read) or
     * the index of the newline.  high is assigned the value i - 1 which 
     * is the last index in line or the index right before the newline
     * was encountered. */
    for (low = 0, high = i - 1; low < high; low++, high--) {
        temp = line[low];
        line[low] = line[high];
        line[high] = temp;
    } 
    for (j = 0; j < i; j++)
        printf("%c%s", line[j], (i - 1 == j) ? "\n": "");
    
    return 0;
} 

