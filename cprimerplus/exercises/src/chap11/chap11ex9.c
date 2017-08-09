/* This program creates a function that replaces the contents of a string
 * with the string reversed.  It then tests the function by using a loop
 * to provide input values to the function.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strReverse(char *str) {
    
    char temp;
    int first = 0;

    /* The 'strlen' function of the <string.h> header returns the number
     * of characters in the string (not including the null character).  
     * Therefore, 'strlen' returns the index of the null character in the
     * string.  To obtain the last printing character in the string, you
     * therefore subract 1 from the return value of 'strlen'
     */
    int last = strlen(str) - 1;

    /* When the string has been completely reversed, last will either equal
     * first, or be 1 less than first.  The final value of the 2 indices 
     * depends on whether 'strlen' returns an even number, or an odd number.
     * 'last' will equal 'first' only when 'strlen' returns an odd number,
     * and that is when this while loop will terminate.  If 'strlen'
     * returns an even number, this while loop will terminate when 'last'
     * is 1 less than 'first'.
     */
    while (last > first) {
        temp = str[first];
        str[first] = str[last];
        str[last] = temp;
        first++;
        last--;
    }
}
char *s_gets(char *str, int n) {

    char *ret_val;
    char *find;
    ret_val = fgets(str, n, stdin);

    if (ret_val) {
        find = strchr(str, '\n');
        if (find)
            *find = '\0';
        else {
            while (getchar() != '\n')
                continue;
        }
    }
    return ret_val;
}

int main(void) {
    
    char input[80];

    printf("Enter a string that you would like to reverse:\n");
    while (s_gets(input, 80)) {
        strReverse(input);
        printf("The reversed string is:\n%s\n", input);

        printf("\nEnter another string to reverse or Ctrl+D to quit:\n");
    }
    if (feof(stdin))
        fputs("EOF reached successfully. Bye!\n", stdout);
    else if (ferror(stdin)) {
        perror("s_gets()");
        exit(EXIT_FAILURE);
    }
    return 0;
}
         
