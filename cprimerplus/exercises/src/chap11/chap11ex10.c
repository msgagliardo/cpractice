/* This program creates a function that takes a string as an argument, and
 * removes the spaces from the string.  It then tests the function by 
 * reading lines of input until the empty line is entered.
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *rmSpaces(char *str) {

    /* This is here just in case someone thinks it's a good idea to pass
     * a NULL pointer to this function.
     */
    if (str == NULL)
        return NULL;

    int i = 0;
    int numSpaces = 0;

    /* For every blank (space, or tab) that is in the string, each character
     * has to shifted to the left by one postition.  The return value of
     * 'strlen' represents the index of the last element of the string,
     * which happens to be the '\0' character.
     */
    for (i = 0; i <= strlen(str); i++) {
        if (isblank(str[i]))
            numSpaces++;
        else if (numSpaces > 0)
            str[i - numSpaces] = str[i];
    }
    return str;
}
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
int main(void) {

    char *ret_val;
    char input[80] = "\0";

    printf("Enter a string that you would like to remove spaces from:\n");
    while (s_gets(input, 80)) {

        /* If you enter just a single newline character, the 's_gets' 
         * function replaces it with the '\0' character and so the 'strlen'
         * function will return 0.  Alternatively, you can still abort the
         * program by pressing Ctrl+D like in the previous programs.
         */
        if (strlen(input) == 0) {
            printf("Goodbye\n");
            break;
        } else {
            printf("Here is the new string:\n");
            printf("%s\n\n", rmSpaces(input));

            printf("Enter a new string or an empty line to quit:\n");
        }
    }
    if (feof(stdin))
        fputs("EOF successfully encountered. Bye.\n", stdout);
    else if (ferror(stdin)) {
        perror("s_gets()");
        exit(EXIT_FAILURE);
    }
    return 0;
}
