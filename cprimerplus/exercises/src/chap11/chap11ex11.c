/* This program reads up to 10 strings or to EOF, whichever comes first.
 * It then offers the user a menu of five choices:  print the original
 * list of strings, print the strings in ASCII collating sequence, print
 * the strings in order of increasing length, print the strings in order
 * of the length of the first word in the string, and quit.  The menu
 * recycles until the user enters the quit request.
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10
#define LEN  80

char *s_gets(char *str, int n) {

    char *ret_val;
    int i = 0;
    ret_val = fgets(str, n, stdin);

    if (ret_val) {
        while (str[i] != '\n' && str[i] != '\0')
            i++;
        if (str[i] == '\n')
            str[i] = '\0';
        else {
            while (getchar() != '\n')
                continue;
        }
    }
    return ret_val;
}
/* I decided to use a function that takes a VLA here because the user can
 * enter anywhere between 0 and 10 strings, so I won't know the number of
 * rows that the two-dimensional array has prior to runtime.
 */
void printOriginal(int rows, const char mat[][LEN]) {

    int i;
    for (i = 0; i < rows; i++)
        printf("%s\n", mat[i]);

}
void printPointers(int rows, char **ppChars) {
    
    int i;
    for (i = 0; i < rows; i++)
        printf("%s\n", *(ppChars + i));

} 

/* Uses insertionSort to sort character pointers
 */
void collatingOrder(int rows, char *psChars[]) {

    int i, j;
    char *entry;

    for (i = 1; i < rows; i++) {
        entry = psChars[i];
        for (j = i; j > 0 && strcmp(entry, psChars[j - 1]) < 0; j--)
            psChars[j] = psChars[j - 1];
        psChars[j] = entry;
    }
}
void lengthOrder(int rows, char *psChars[]) {

    int i, j;
    char *entry;

    for (i = 1; i < rows; i++) {
        entry = psChars[i];
        for (j = i; j > 0 && strlen(entry) < strlen(psChars[j - 1]); j--)
            psChars[j] = psChars[j - 1];
        psChars[j] = entry;
    }
}
void firstWordOrder(int rows, char *psChars[]) {

    int i, j;
    int lengths[rows];
    int entry;
    int count = 0;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < strlen(psChars[i]) && isspace(psChars[i][j]); j++)
            continue;
        for ( ; j < strlen(psChars[i]) && !isspace(psChars[i][j]); j++)
            count++;

        lengths[i] = count;
        count = 0;
    }
    for (i = 1; i < rows; i++) {
        entry = lengths[i];
        for (j = i; j > 0 && entry < lengths[j - 1]; j--) {
            lengths[j] = lengths[j - 1];
            psChars[j] = psChars[j - 1];
        }
        lengths[j] = entry;
        psChars[j] = psChars[i];
    }
}
/* NOTE: This function works, but it is less efficient.  It is here only
 * to show an alternative.
 */
void collatingOrder_BAD(int rows, int cols, char mat[rows][cols]) {
    
    int i, j, smallIndex;
    char temp[cols];

    for (i = 0; i < rows - 1; i++) {
        smallIndex = i;

        for (j = i + 1; j < rows; j++) {
            if (strcmp(mat[j], mat[smallIndex]) < 0)
                smallIndex = j;
        }
        /* If you do not include this check, the source and destination
         * array will be the same in the second statement, and one of the
         * preconditions of the 'strncpy' function is that source and 
         * destination must not overlap.  Thus, without the check here, 
         * the code causes 'Abort trap: 6'.  (See 'memmove' function for 
         * a safer alternative when src and dest overlap)
         */
        if (smallIndex != i) {
            strncpy(temp, mat[smallIndex], cols);
            strncpy(mat[smallIndex], mat[i], cols);
            strncpy(mat[i], temp, cols);
        }
    } 
}
int main(void) {
    
    char input[SIZE][LEN];
    char *pStrings[SIZE];
    int choice, i;
    int n = 0;

    printf("Please enter up to 10 strings:\n");
    while (n < SIZE && s_gets(input[n], LEN) != NULL) {
        n++;
        printf("Enter another string or Ctrl+D to stop:\n");
    }
    for (i = 0; i < n; i++)
        pStrings[i] = input[i];

    firstWordOrder(n, pStrings);
    printPointers(n, pStrings);
/*    
    printf("\nNow choose what you would like to do with the strings:\n");
    printf("1. Print the originals       2. Print in collating sequence\n");
    printf("3. Increasing length         4. Length of first word\n"); 
    printf("5. quit\n");

    while (scanf("%d", &x) == 1 && x != 5) {

        switch (x) {
            case 1:
                printOriginal(n, input);
                break;
            case 2:
                collatingOrder(n, pStrings);
                printPointers(n, pStrings);
                break;
            case 3:
                lengthOrder();
                break;
            case 4:
                firstWordOrder();
                break;
            default:
                break;
        }
        while (getchar() != '\n')
            continue;

        printf("\nMake another selection:\n");
        printf("1. Print the originals       "
                "2. Print in collating sequence\n");
        printf("3. Increasing length         4. Length of first word\n"); 
        printf("5. quit\n");
    }
*/
    return 0;
}
     

