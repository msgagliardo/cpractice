/* This program reads input until encountering the # character and then 
 * reports the number of spaces read, number of newlines read, and the 
 * number of all other characters read.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int nlCount, spCount, tbCount, count;
    char c;
    nlCount = spCount = tbCount = count = 0;

    printf("Please enter a line of input (# to quit): ");
    while ((c = getchar()) != '#') {
        if ('\n' == c)
            nlCount++;
        else if (' ' == c)
            spCount++;
        else if ('\t' == c)
            tbCount++;
        else
            count++;
    }
    printf("#NewLines   #Spaces   #Tabs   #AllOthers\n");
    printf("%9d%10d%8d%13d\n", nlCount, spCount, tbCount, count);

    return 0;
} 
