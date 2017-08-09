/* This program is just like chap11ex1.c except that the 's_getsm' function
 * has been replaced by one that stops after reading n - 1 characters or 
 * after the first blank, tab, or newline.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 10

/* This version of 'scanf' only accepts one 'token' and that token is
 * always interpreted as a string.  That is, it will not convert character
 * string representations of numbers into numbers.
 */
int m_scanf(char *str, int n) {
    
    int ret_val;

    /* The usual return value of 'scanf' is the number of tokens 
     * sucessfully read. On success, the function returns the number of 
     * items of the argument list successfully filled. This count can match
     * the expected number of items or be less (even zero) due to a 
     * matching failure, a reading error, or the reach of the end-of-file.
     * If a reading error happens or the end-of-file is reached while 
     * reading, the proper indicator is set (feof or ferror). And, if 
     * either happens before any data could be successfully read, EOF is 
     * returned.
     *
     * This function, however, returns the number of characters
     * successfully read.
     */
    int i = 0;

    /* Should include this test because nothing is preventing a user from
     * entering a NULL char*
     */
    if (NULL == str)
        return 0;

    /* The while loop should terminate under the following circumstances:
     * 1. i = n - 1, in which case, 'i' equals the last index of the 
     * character array that we are storing the input in.
     * 2. 'getchar' returns EOF
     * 3. 'isspace' returns true (nonzero value).  The 'isspace' function
     * is prototyped in the <ctype.h> header file.  It returns a nonzero 
     * value when it encounters a space character, a tab character or a 
     * white-space control code such as '\n'.  The 'isblank' function, also
     * in the <ctype.h> header only returns a nonzero value when it 
     * encounters a space or a tab character.
     */
    while (i < n - 1 && (ret_val = getchar()) != EOF
                     && !isspace(ret_val)) {

        /* This (char) cast is not necessary, C will perform the necessary
         * implicit conversion of 'ret_val' (which is an int) to char, but
         * I like to be explicit.
         */
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

    /* The 'getchar' function only has two types of return values; either
     * the integer code for the read character or EOF.  EOF is returned
     * if EOF was actually reached OR an ERROR occurred.  Since 'm_scanf'
     * uses 'getchar', I decided to make it have similar return values.  It
     * returns either the number of characters read or EOF.  Since EOF can
     * be returned if EOF was actually reached OR if there was an error,
     * you should use the 'feof' and 'ferror' functions to check what the
     * reason for returning EOF was.  These functions will check if the 
     * appropriate flags were set on the file stream.
     */
    while ((result = m_scanf(input, SIZE)) != EOF)
        printf("input = %s, # of characters = %d\n", input, result);

    /* If EOF was truly encountered, only 'feof' will return true.
     * 'ferror' will still return false.
     */
    if (feof(stdin))
        fputs("EOF Sucessfully Encountered\n", stdout);
    if (ferror(stdin)) {
        /* Prints to stderr the contents of the null-terminated character 
         * string pointed to by s (unless s is a null pointer), followed 
         * by the two characters ": ", followed by the 
         * implementation-defined error message describing the error code 
         * currently stored in the system variable errno (identical to the 
         * output of strerror(errno)), followed by '\n'.
         *
         * The 'perror' function is prototyped in the <stdio.h> header file
         * and its prototype is reproduced below:
         *
         * void  perror(const char *);
         *
         * errno is a preprocessor macro that expands to a thread-local 
         * (since C11) modifiable lvalue of type int. Several standard 
         * library functions indicate errors by writing positive integers 
         * to errno. Typically, the value of errno is set to one of the 
         * error codes listed in <errno.h> as macro constants beginning 
         * with the letter E followed by uppercase letters or digits.
         * 'errno' is defined in the <errno.h> header file.
         */
        perror("m_scanf()");

        /* The 'exit' function is prototyped in the <stdlib.h> header file.
         */
        exit(EXIT_FAILURE); 
    }

    return 0;
} 
