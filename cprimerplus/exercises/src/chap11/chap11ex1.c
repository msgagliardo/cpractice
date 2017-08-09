/* This program designs and tests a function that fetches the next 'n'
 * characters from input (including blanks, tabs, and newlines), and stores
 * the results in an array whose address is passed as an argument.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

/* This function is a modification of the 's_gets' function used in chapter
 * 11 of the "C Primer Plus" text.  The only difference is that the 
 * 's_gets' function uses a while loop to set an index 'i' to the first
 * occurrence of either a '\n' or '\0' character.  This function, however,
 * uses the 'strchr' function from the <string.h> header file to find the 
 * address of the the first '\n' character and set its value to '\0'
 */
char *s_getsm(char *str, int n) {

    char *ret_val;
    char *new_line;

    /* 'fgets' at most count - 1 characters from the given file stream and 
     * stores them in the character array pointed to by str. Parsing stops 
     * if end-of-file occurs or a newline character is found, in which case
     * str will contain that newline character. If no errors occur, writes 
     * a null character at the position immediately after the last 
     * character written to str. The behavior is undefined if count is 
     * less than 1.
     *
     * On success, the function returns str.
     * If the end-of-file is encountered while attempting to read a 
     * character, the eof indicator is set (feof). If this happens before 
     * any characters could be read, the pointer returned is a null pointer
     * (and the contents of str remain unchanged). If a read error occurs, 
     * the error indicator (ferror) is set and a null pointer is also 
     * returned (but the contents pointed by str may have changed).
     *
     * The 'fgets' prototype from the header file of <stdio.h> is shown 
     * below:
     *
     * char *fgets(char * __restrict, int, FILE *);
     *
     * Therefore, if the read operation was a success and 'ret_val' equals
     * 'str' (an address, and therefore a positive integer), the 'if' 
     * statement expression will evaulate to true.  You could also test it
     * more explicitly by using this expression 'ret_val != NULL'
     */
    ret_val = fgets(str, n, stdin);

    /* The NULL macro is defined in the following header files:  <stdio.h>,
     * <stdlib.h>, <stddef.h>, <string.h>, <wchar.h>, <time.h>, <locale.h>.
     *
     * The macro NULL is an implementation-defined null pointer constant,
     * which may be either:
     * 1. An integer constant expression with the value 0.
     * 2. An integer constant expression with the value 0 cast to type
     * void*.  (only '#define NULL 0' is compatible with C++).
     *
     * A null pointer constant can be converted to any pointer type; such
     * a conversion results in the null pointer value of that type.  
     */
    if (ret_val) {

        new_line = strchr(str, '\n');
        if (new_line)
            *new_line = '\0';
        else {
            while ('\n' != getchar())
                continue;
        }
    }
    return ret_val;
}
int main(void) {

    char input[SIZE];
    int i;

    printf("Enter some input: ");

    while (s_getsm(input, SIZE)) {
        for (i = 0; i < strlen(input); i++)
            printf("'%c' ", input[i]);
        printf("\n"); 
        printf("Next:\n");
    }
    if (ferror(stdin))
        fputs("I/O Error when reading.\n", stderr);
    else if (feof(stdin))
        fputs("End of File reached successfully.\n", stdout);

    return 0;
}

         
