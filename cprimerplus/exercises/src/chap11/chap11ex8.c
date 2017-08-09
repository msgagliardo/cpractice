/* This program creates a function called 'string_in' that takes two 
 * string pointers as arguments.  If the second string is contained in the
 * first string, the function returns the address at which the contained 
 * string begins.  Otherwise, the function returns the NULL pointer.
 * The program then uses a loop to provide input values to test the
 * function.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *string_in(char *str1, char *str2) {

    int i = 0, j = 0;
    char *result = NULL;

    /* Either 'i' is the index of the first match between the chracters of
     * str1 and str2, or we have reached the end of str1 with no match.
     */
    while (str1[i] != str2[0] && str1[i] != '\0')
        i++;
    /* If we have reached the end of str1 with no match, return NULL. */
    if (str1[i] == '\0')
        return NULL;

    /* If we have a match, however, save the address of where that match
     * in str1 occurs.
     */
    result = str1 + i;

    /* Starting with the second character of str2 (index 1), compare the 
     * rest of the characters of str2 with str1 starting at index [i + j]
     * of str1.  If there are any characters from this point onward that 
     * don't match, return NULL, because the entirety of str2 cannot be
     * found in str1.
     */
    for (j = 1; j < str2[j] != '\0'; j++) {
        if (str1[i + j] != str2[j])
            return NULL; 
    }
    /* If executed makes it this far, all of str2 can be found in str1,
     * therefore return the address of the first matching character in 
     * str1.
     */
    return result;
}
char *s_gets(char *str, int n) {
    
    char *find;
    char *ret_val;
    ret_val = fgets(str, n, stdin);
    if (ret_val) {

        /* Reminder: 'strchr' of the <string.h> header returns the address
         * of the searched for character in 'str' if it can be found, 
         * otherwise it returns NULL.
         */
        if ((find = strchr(str, '\n')))
            *find = '\0';
        else {
            while (getchar() != '\n')
                continue;
        }
    }
    return ret_val;
}
int main(void) {

    char *match;
    char arr1[80];
    char arr2[80];

    printf("Enter a string: ");
    s_gets(arr1, 80);
    printf("Enter a string you would like to search for in that string:\n");

    while (s_gets(arr2, 80)) {
        if ((match = string_in(arr1, arr2)))
            printf("There was a match at %s\n", match);
        else
            printf("There was no match!\n");

        printf("\nEnter another string to search or Ctrl+D to quit:\n");
    }
    if (feof(stdin))
        fputs("EOF reached successfully. Bye\n", stdout);
    else if (ferror(stdin)) {
        perror("s_gets()");
        exit(EXIT_FAILURE);
    }
    return 0;
}

