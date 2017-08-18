/* This program uses the character classification functions prototyped in
 * the <ctype.h> header file to prepare an implementation of the 'atoi'
 * function.
 */
#include <ctype.h>
#include <math.h>
#include <stdio.h>
/* int   atoi(const char *);
 * double    atof(const char *);
 *
 * These are the prototypes for the string conversion function 'atoi' and 
 * 'atof' from the <stdlib.h> header file.  If no conversion could be 
 * performed, 0, and 0.0 are returned respectively.
 */
#include <stdlib.h>

int my_atoi(const char *str) {

    int startIndex;
    int exp;
    int result = 0;
    int i = 0;

    /* Skip over any leading whitespace just like 'atoi' in <stdlib.h> */
    while (isspace(str[i]))
        i++;

    /* Allow a single leading '-' or '+' if it is immediately followed by
     * a digit (this is the same behavior as 'atoi' in <stdlib.h>.
     */
    if ('-' == str[i] || '+' == str[i])
        i++;

    if (isdigit(str[i])) {
        
        /* This is the index of the first digit */
        startIndex = i;
        while (isdigit(str[i]))
            i++;

        /* 'i - 1' is the index of the last digit.  Any characters after
         * 'i - 1' are ignored, just like in 'atoi' from <stdlib.h>.  
         * 48 is the ASCII code for the '0' character, so 'str[i] - 48'
         * is the numeric value of the character at index 'i' in decimal.
         */
        for (i = i - 1, exp = 0; i >= startIndex; i--, exp++)
            result = result + (str[i] - 48) * pow(10, exp);

        /* If the character immediately before the first digit was '-', then
         * negate the result.
         */
        if ('-' == str[startIndex - 1])
            result = -result;
    } 

    return result;
}
int main(void) {

    char *test = "      \n-94347bananer";

    /* This statement prints '-94347' to stdout */
    printf("the result = %d\n", my_atoi(test));

    return 0;
}
