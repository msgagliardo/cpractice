/* This program designs and tests a function that searches a string 
 * specified by the first parameter for the first occurrence of a character
 * specified by the second function parameter.  The function returns a 
 * pointer to the character if successful, and NULL if the character is
 * not found.  This duplicates the way that 'strchr' works from the 
 * <string.h> header file.
 */
#include <stdio.h>
#include <stdlib.h>

#define SIZE 81

const char *m_strchr(const char *str, int c) {
    
    int i;

    /*  It is not safe to assign a pointer to a constant value to a pointer
     *  to a non-const value, so I made 'ret_val' of type 'const char*' so
     *  that 'ret_val = str + i;' would not cause a warning.
     */
    const char *ret_val = NULL;

    for (i = 0; str[i] != '\0'; i++) {

        /* Cast not needed but I like to be explicit. */
        if ((int) str[i] == c) {
            ret_val = str + i;
            break;
        }
    }
    return ret_val;
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

    char test[SIZE];
    int c;
    const char *loc;
    
    printf("Enter a string: ");
    s_gets(test, SIZE);

    printf("Now enter characters you would like to find in the string:\n");
    while ((c = getchar()) != EOF) {

        /* If the user doesn't enter anything, print a message and give
         * them a chance to enter something else.
         */
        if (c == '\n') {
            printf("You must enter a graphic character or Ctrl+D\n");
            continue;
        }
        
        loc = m_strchr(test, c);
        
        /* If the next character is not the newline character, that means
         * that the user entered more than one character at a time.  If
         * this is the case, inform the user, and get rid of what's left in
         * the input buffer.
         */
        if (getchar() != '\n') {
            printf("Please only enter one charater at a time\n");
            while (getchar() != '\n')
                continue;
        }
        /* If 'loc' is not equal to NULL, then that means that the character
         * was found.  In this case, print the character and the address of
         * that character.  Is the '%p' specifier being used correctly
         * here?  The compiler warning says that it is expecting a 'void*'
         */
        if (loc) 
            printf("Character '%c' was found at %p\n", *loc, loc);
        else
            /* I am using 'c' as the '%c' format specifier argument here
             * becasue 'loc' equals NULL and you shouldn't dereference a 
             * NULL pointer.
             */
            printf("Character '%c' was not found in the string\n", c);

        printf("Enter another character or Ctrl+D to quit:\n");

    }
    /* If EOF was returned by getchar(), check to see why. */
    if (feof(stdin))
        fputs("EOF successfully encountered.\n", stdout);
    else if (ferror(stdin)) {
        perror("getchar()");
        exit(EXIT_FAILURE);
    }

    return 0;
}
