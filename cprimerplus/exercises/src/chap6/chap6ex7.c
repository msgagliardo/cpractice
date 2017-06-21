/* This program reads a single word into a character array and then prints
 * the word backward.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char word[50];
    char temp;
    int low, high, size;
    
    printf("Please enter a word and I will reverse it: ");
    scanf("%s", word);
    
    size = strlen(word);

    for (low = 0, high = size; low < high; low++, high--) {
        temp = word[low];
        word[low] = word[high];
        word[high] = temp;
    }
    for (low = 0; low <= size; low++)
       printf("%c%s", word[low], (low == size) ? "\n": "");
    
    return 0;
} 
