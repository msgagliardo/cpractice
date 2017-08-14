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

/* Number of rows */
#define SIZE 10
/* Number of cols */
#define LEN  10

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
/* You must specify all but the leftmost size in a multi-dimensional array
 * So that the compiler knows the size of what the 'mat' pointer is 
 * pointing to.  The purpose of this function is to print the contents
 * of the original multi-dimensional array 'input' that the 'main' 
 * function reads the user input into.  Hence why this function uses a 
 * parameter of type pointer-to-char array.
 */
void printOriginal(int rows, const char mat[][LEN]) {

    int i;
    for (i = 0; i < rows; i++)
        printf("%s\n", mat[i]);

}
/* This function is passed the array of char* 'pStrings' in 'main'.  It 
 * iterates through the array and prints the char* one-by-one using 
 * pointer arithmetic.
 */
void printPointers(int rows, char **ppChars) {
    
    int i;
    for (i = 0; i < rows; i++)
        printf("%s\n", *(ppChars + i));

} 
/* Uses insertionSort to sort character pointers.  This function, like 
 * 'collatingOrder_BAD' sorts the strings according to the 'machine
 * collating sequence'.  Collation is the assembly of written information
 * into a standard order.  Many systems of collation are based on numerical
 * order or alphabetical order, or extensions and combinations thereof.  C
 * uses the ASCII collating sequence?  The Unicode collation algorithm 
 * defines an order through the process of comparing two given character 
 * strings and deciding which should come before the other.
 *
 * This function, as opposed to 'collatingOrder_BAD' uses a
 * pointer-to-pointer to char parameter 'psChars', instead of a pointer to 
 * an array parameter.  In 'main', this function is passed an array of
 * character pointers.  The function uses the insertion sort algorithm and
 * the 'strcmp' function to SORT THE CHARACTER POINTERS THAT ULTIMATELY
 * POINT TO THE CHARACTER SUBARRAYS IN THE 'input' MATRIX IN 'main'.  Not
 * only is this more efficient than 'collatingOrder_BAD', but it has the 
 * added benefit of not changing the original 'input' matrix.
 * */
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
/* This function uses the insertion sort algorithm to sort the strings
 * based on string length.  The same function applies to this function 
 * as 'collatingOrder'.  In fact, the only difference is that 'strlen' is
 * used to compare the strings instead of 'strcmp'
 */
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
/* This function, like the 'collatingOrder' and 'lengthOrder' functions,
 * also uses the insertion sort algorithm to ultimately sort the strings
 * based on the length of their first word, however, some preliminary work
 * must be done beforehand.
 *
 * Like the aforementioned functions, 'firstWordOrder' is passed an array
 * of character pointers.  The initial difference occurs with the definition
 * of the 'lengths' VLA, and the 'count' variable.  The 'lengths' VLA is
 * needed because the exercise states that the user may enter between 0
 * and 10 strings, so the number of rows in the 'input' array (which 
 * correspond to the number of char subarrays, and hence the number of
 * strings entered by the user) is not known until runtime.
 *
 * The function uses the insertion sort algorithm on a pair of parallel 
 * arrays ('length' and the parameter 'psChars').  In computing, a group 
 * of parallel arrays (also known as structure of arrays or SoA) is a form 
 * of implicit data structure that uses multiple arrays to represent a 
 * singular array of records. It keeps a separate, homogeneous data array 
 * for each field of the record, each having the same number of elements. 
 * Then, objects located at the same index in each array are implicitly 
 * the fields of a single record. Pointers from one object to another are 
 * replaced by array indices. This contrasts with the normal approach of 
 * storing all fields of each record together in memory (also known as 
 * array of structures or AoS).  The 'length' VLA is used to store the 
 * number of characters in each of the strings in 'psChars'.  That is,
 * the value at the ith index in the 'length' array, represents the 
 * number of characters in the first word of the string at the ith index
 * in the 'psChars' array.
 */ 
void firstWordOrder(int rows, char *psChars[]) {

    int i, j;
    int lengths[rows];
    int entry;
    char *pEntry;
    int count = 0;

    for (i = 0; i < rows; i++) {
        /* This nested for loop skips over any leading whitespace that 
         * may have been entered, and does not include this in the 'count'
         * The 'isspace' function of the <ctype.h> header returns a positive
         * value if the character is a space, a tab, or some other
         * whitespace control code.
         */
        for (j = 0; j < strlen(psChars[i]) && isspace(psChars[i][j]); j++)
            continue;
        for ( ; j < strlen(psChars[i]) && !isspace(psChars[i][j]); j++)
            count++;

        lengths[i] = count;
        count = 0;
    }
    for (i = 1; i < rows; i++) {
        entry = lengths[i];
        pEntry = psChars[i];
        for (j = i; j > 0 && entry < lengths[j - 1]; j--) {
            lengths[j] = lengths[j - 1];
            psChars[j] = psChars[j - 1];
        }
        lengths[j] = entry;
        psChars[j] = pEntry;
    }
}
/* NOTE: This function works, but it is less efficient.  It is here only
 * to show an alternative.  This version of the collatingOrder sort uses
 * selection sort to sort the actual character arrays that are stored in
 * the original 'input' multi-dimensional array in 'main'.  The reason it
 * is not efficient is because it uses the 'strncpy' function to copy 
 * a string that comes earlier in the collating sequence character by
 * character into earlier subarrays.
 */
void collatingOrder_BAD(int rows, char mat[][LEN]) {
    
    int i, j, smallIndex;
    char temp[LEN];

    for (i = 0; i < rows - 1; i++) {
        smallIndex = i;

        for (j = i + 1; j < rows; j++) {
            /* This if statement expression evaluates to true if the string
             * at 'mat[j]' comes before the string at 'mat[smallIndex]'
             */
            if (strcmp(mat[j], mat[smallIndex]) < 0)
                smallIndex = j;
        }
        /* If you do not include this check, the source and destination
         * array may be the same in the second statement, and one of the
         * preconditions of the 'strncpy' function is that source and 
         * destination must not overlap.  Thus, without the check here, 
         * the code causes 'Abort trap: 6'.  (See 'memmove' function for 
         * a safer alternative when src and dest overlap)
         */
        if (smallIndex != i) {
            /* The reason you have to use 'strncpy' here is because 'mat'
             * is a pointer to an array, so 'mat[smallIndex]' is an array
             * and you cannot assign an array to another array.  If, 
             * however, you declared 'mat' as an array of character pointers
             * (which the compiler would actually interpret as a pointer to
             * pointer to char), and you declared 'temp' as char*, you could
             * write the following;
             *
             * temp = mat[smallIndex];
             * mat[smallIndex] = mat[i];
             * mat[i] = temp;
             *
             * as is done in the 'collatingOrder' function with 'psChars'
             * and 'entry'
             */
            strncpy(temp, mat[smallIndex], LEN);
            strncpy(mat[smallIndex], mat[i], LEN);
            strncpy(mat[i], temp, LEN);
        }
    } 
}
int main(void) {
    
    /* We must use some sort of char ARRAY to store the input from the user
     * because if we used char pointers we would necessarily have to 
     * dereference those unitialized pointers when 'fgets' is called in
     * our 's_gets' function.
     */
    char input[SIZE][LEN];

    /* This array of char* is used to point to the char subarrays of
     * 'input' so that we can more easily sort them in our sorting functions
     */
    char *pStrings[SIZE];
    char *retVal;
    int choice, i;
    int n = 0;

    /* The 'fgets' function, and consequently, 's_gets' returns a NULL
     * pointer if EOF is encountered before any input has been entered, or
     * if there is an error reading input.  If Ctrl+D is entered at is 
     * pressed at the beginning of a line, this while loop will be skipped,
     * the 4 'printf' statements before the switch statement will execute,
     * and the program will exit without waiting for input from 'scanf'
     * (why?).
     *
     * For the user to enter less than 10 strings, they must enter a blank
     * line (is there a better way to do this?).  When a blank line is 
     * entered, 'fgets' places a '\0' after the '\n'.  Our 's_gets' function
     * subsequently replaces the first newline it encounters with '\0'.
     * Hence the if statement check to see if the first character of
     * 'input[n]' is a '\0' to break out of the loop.
     */
    printf("Please enter up to 10 strings:\n");
    while (n < SIZE && (retVal = s_gets(input[n], LEN)) != NULL) {
        if (*retVal == '\0') 
            break; 
        n++;
        if (n != SIZE)
            printf("Enter another string or empty line to stop:\n");
    }
    /* Here the character pointers of 'pStrings' are set to point to each
     * of the char subarrays of 'input' in turn.
     */
    for (i = 0; i < n; i++)
        pStrings[i] = input[i];

    printf("\nNow choose what you would like to do with the strings:\n");
    printf("1. Print the originals       2. Print in collating sequence\n");
    printf("3. Increasing length         4. Length of first word\n"); 
    printf("5. quit\n");

    /* The return value for the 'scanf' function is an 'int' that represents
     * the number of the arguments successfully filled.  This count 
     * can match the expected number of values, or be less (even zero) due
     * to a matching failure, a reading error, or the reach of EOF. 
     *
     * If a reading error happens or the end-of-file is reached while 
     * reading, the proper indicator is set (feof or ferror). And, if 
     * either happens before any data could be successfully read, EOF is 
     * returned.  If an encoding error happens interpreting wide 
     * characters, the function sets errno to EILSEQ.
     * 
     * Should be break out of the loop on EOF or when the number of 
     * successful reads is less than the number of arguments in the format
     * string? (If 'scanf' only fills some of the arguments, but not all,
     * it won't return EOF, so shouldn't we break when the number of args
     * filled is less than expected, rather than EOF?).
     */
    while (scanf("%d", &choice) == 1 && choice != 5) {

        switch (choice) {
            case 1:
                printOriginal(n, input);
                break;
            case 2:
                collatingOrder(n, pStrings);
                printPointers(n, pStrings);
                break;
            case 3:
                lengthOrder(n, pStrings);
                printPointers(n, pStrings);
                break;
            case 4:
                firstWordOrder(n, pStrings);
                printPointers(n, pStrings);
                break;
            default:
                printf("That is not a valid choice.\n");
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
     
    return 0;
}
     
