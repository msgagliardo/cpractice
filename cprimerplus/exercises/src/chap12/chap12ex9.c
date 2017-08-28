/* This program asks the user how many words they wish to enter.  Then it
 * has the user enter the words, and then it displays the words.
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 80

char *s_gets(char *str, int n) {

    int i = 0;
    char *ret_val;

    ret_val = fgets(str, n, stdin);
    if (ret_val) {
        while ('\0' != str[i] && '\n' != str[i])
            i++;
        if ('\n' == str[i])
            str[i] = '\0';
        else {
            while ('\n' != getchar())
                continue;
        }
    }
    return ret_val;
}

int main(void) {

    int num_words;
    char **words;
    char *string;
    char temp[SIZE];
    char again;
    int i = 0;

    do {
        printf("How many words do you wish to enter? ");
        scanf("%d", &num_words);
        
        /* If you don't check for EOF here, the program won't end if you 
         * press Ctrl+D at the beginning of the line.
         */
        if (feof(stdin)) {
            fputs("EOF encountered successfully. Bye.\n", stdout);
            exit(EXIT_SUCCESS); 
        } else if (ferror(stdin)) {
            perror("scanf()");
            exit(EXIT_FAILURE);
        }

        /* This clearing of the input buffer is not needed if you use the
         * scanf() function, only s_gets/fgets, because the scanf function
         * skips over any leading whitespace.
         */
        while ('\n' != getchar())
            continue;

        /* Declare a heap-dynamic array of char pointers */
        words = (char **) malloc(num_words * sizeof(char *));
        printf("Enter %d words now:\n", num_words);

        /*
        while (i < num_words && s_gets(temp, SIZE)) {
            string = (char *) malloc((strlen(temp) + 1) * sizeof(char));
            words[i] = string;
            strncpy(words[i], temp, strlen(temp) + 1);
            i++;
        }
        */

        /* Using scanf() with %s and the width sub-specifier, you must 
         * specify a width that is one less than the target array because
         * the scanf() function will add the '\0' to make a C-style string
         */
        while (i < num_words && scanf("%79s", temp) == 1) {

            /* The number of bytes of the 'temp' array is 80, but our word
             * is most definitely going to be smaller than that, so we have
             * a bunch of unused space.  To save space, we create a char
             * array on the heap and make the size of it one more than the
             * number of characters in the word entered (to accomodate the 
             * '\0' character).
             */
            string = (char *) malloc((strlen(temp) + 1) * sizeof(char));

            /* We then copy those characters (including the null character
             * from temp into the space we allocated for string.
             */
            strncpy(string, temp, strlen(temp) + 1);

            /* We then assign this pointer to our array of character
             * pointers.
             */
            words[i] = string;
            i++;
        }
        if (feof(stdin)) {
            fputs("EOF successfully encountered. Bye.\n", stdout);
            exit(EXIT_SUCCESS);
        } else if (ferror(stdin)) {
            perror("scanf()");
            exit(EXIT_FAILURE);
        }
        printf("\nHere are your words:\n");

        for (i = 0; i < num_words; i++) {
            printf("%s\n", words[i]);

            /* After printing each word, we deallocate the memory used for
             * each string in the array of char* to prevent memory leaks.
             * We could a separate for loop and iterate through the array,
             * calling free() at each index, but that is additional, 
             * unnecessary, runtime overhead.
             */
            free(words[i]);
        }
        /* We then have to free the memory associated with the array of 
         * char pointers, because a new array of character pointer is 
         * allocated on the heap, and assigned to 'words' during each new
         * iteration of the program.  When this happens, the original
         * address of the first array of character pointer is lost, and
         * that section of memory cannot be reclaimed.  THerefore, a 
         * memory leak will occur.
         *
         * QUESTION:  How does the [Operating system/runtime environment?]
         * know how much memory to free?  For all the operating system knows
         * 'words' could simply be a pointer to a single character pointer.
         * Is the size of the memory that was allocated to it kept in its
         * descriptor.
         */
        free(words);

        /* Used to clear the input buffer if anything happens to be in there
         * after the strings were entered.  Not needed if you use 's_gets',
         * only 'scanf()'
         */
        while ('\n' != getchar())
            continue; 

        printf("\nEnter more words (y/n)? ");
        again = getchar();

        /* Needed to clear the input buffer of at least the newline
         * character after either 'y' or 'n' was entered.
         */
        while ('\n' != getchar())
            continue;

        /* Reset your index variable back to zero. */
        i = 0;

    } while ('y' == tolower(again));

    return 0;
}

