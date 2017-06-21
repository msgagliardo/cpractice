/* This program creates a character array with the 26 lowercase letters in the
 * English alphabet.  It then loops through the array, and prints out the 
 * contents to the console.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char alphabet[26];
    char i;
    int k;

    for (i = 'a', k = 0; i <= 'z'; i++, k++)
        alphabet[k] = i;

    for (i = 0; i < 26; i++)
        printf("%c%s", alphabet[i], (i == 25) ? "\n": "  ");

    return 0;
} 

