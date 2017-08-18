/* This program reads input up to EOF and reports the number of words, the
 * number of uppercase letters, the number of lowercase letters, the number
 * of punctuation characters, and the number of digits entered.
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 800

char *s_gets(char *str, int n) {

    char *ret_val, *find;
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
    
    char input[LEN];
    int i, lCase, uCase, wCount, punct;
    lCase = uCase = wCount = punct = 0;
    
    printf("Enter up to 800 characters of input or Ctrl+D to quit:\n");
    /* If you input >= LEN characters, this while loop will calculate the
     * wrong number of words for 'wCount'.  This is because 'fgets' reads
     * up to LEN - 1 characters or the newline character, whichever comes
     * first.  If you input > LEN characters (including the newline 
     * character), when you press the enter key, the newline is included
     * in the input buffer, and the input buffer gets flushed.  However,
     * the program will only read LEN - 1 characters from the input buffer
     * at a time and 'fgets' will add the '\0' character to these LEN - 1
     * characters to form a proper C-style string.
     *
     * If the input that you enter is > LEN - 1 characters, the processing
     * in the for loop will end, and control will transfer back to the outer
     * while loop.  Since there will still be leftover input in the buffer
     * from last time, 'fgets' will read another LEN - 1 characters or up to
     * the newline.  Because of the 'i == 0 && isgraph(input[i])' check,
     * the loop will still calculate the correct number of words even if
     * the length of the input is equal to LEN.  So, in this case input must
     * be > LEN for the behavior mentioned above to occur.
     *
     * There is no real danger of this happening for a very large value of
     * LEN.
     */ 
    while (fgets(input, LEN, stdin)) {

        for (i = 0; i < strlen(input); i++) {
            if ((i == 0 && isgraph(input[i])) || 
                    ((isspace(input[i - 1])) && isgraph(input[i])))
                wCount++;
            if (islower(input[i]))
                lCase++;
            else if (isupper(input[i]))
                uCase++;
            else if (ispunct(input[i]))
                punct++;
        }
        printf("This input contains:\n%d words\n%d lowercase letters\n%d "
            "uppercase letters\n%d punctuation characters\n", wCount, lCase,
            uCase, punct);
        wCount = lCase = uCase = punct = 0;

        printf("\nEnter some more input or Ctrl+D to quit:\n");
    }

    return 0;
}
        
