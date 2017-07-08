/* This program reads input as a stream of letters until encountering
 * EOF.  It then reports the average number of letters per word.  
 * whitespace is not counted as being letters in a word.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
    
    int letters = 0;
    int words = 0;
    double avg;
    char prev_c = ' ';
    char c;

    puts("Enter some input, and I will calculate the average number of "
            "letters in each of your words:");
    while ((c = getchar()) != EOF) {
        if (ispunct(c))
            continue;
        else if (!isspace(c))
            letters++;
        else if (!isspace(prev_c))
            words++;

        prev_c = c;
    }
    printf("Total # of letters%7s %d\n", "=", letters);
    printf("Total # of words%9s %d\n", "=", words);
    printf("Avg. # letters per word = %lf\n", 
            (double) letters / words);
    
    return 0;
} 
             
