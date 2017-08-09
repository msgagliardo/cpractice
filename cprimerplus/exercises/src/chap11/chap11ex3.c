/* This program designs and tests a function that reads the first word from
 * a line of input into an array and discards the rest of the line.  It 
 * skips over leading whitespace.  A word is defined as a sequence of 
 * characters with no spaces, tabs, or newlines in it.
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 15

int m_scanf(char *str, int n) {
    
    int ret_val;
    int i = 0;

    if (NULL == str)
        return 0;

    while (i < n - 1 && (ret_val = getchar()) != EOF) {

        /* This 'm_scanf' function is a modification of the one in
         * chap11ex2.c.  It skips over whitespace that occurs before a word
         * has been entered.  However, if some characters have already been
         * entered into the 'input' character array, then the presence of
         * whitespace causes the loop to terminate.
         */
        if (isspace(ret_val)) {
            if (i == 0)
                continue;
            else
                break;
        }
        str[i] = (char) ret_val;
        i++;
    }
    str[i] = '\0';

    if (ret_val == EOF)    
        return EOF;
    
    if (ret_val != '\n') {   
        while (getchar() != '\n')
            continue;
    }
    return i;
}
int main(void) {

    char input[SIZE];
    int result;
    int c;

    while ((result = m_scanf(input, SIZE)) != EOF)
        printf("input = %s, # of characters = %d\n", input, result);

    if (feof(stdin))
        fputs("EOF Sucessfully Encountered\n", stdout);
    if (ferror(stdin)) {
        perror("m_scanf()");
        exit(EXIT_FAILURE); 
    }
    return 0;
} 
