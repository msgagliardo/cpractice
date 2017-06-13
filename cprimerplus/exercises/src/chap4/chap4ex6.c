/* This program requests the first name and last name of the user, and then it
 * prints the names with the number of letters in each name on the following 
 * line aligned to the right, and then aligned to the left. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char first[20];
    char last[40];

    printf("Please enter your first name followed by your last name: ");
    scanf("%s%s", first, last);

    /* Specifying the width width using astericks in front of the format 
     * specifier indicates that the field width will be determined at runtime.
     * The sizes of these field widths must be of type int, hence the casts. */

    printf("%s %s\n", first, last);
    printf("%*zd %*zd\n", (int)strlen(first), strlen(first), (int)strlen(last),
            strlen(last));

    printf("\n");
    printf("%s %s\n", first, last);
    printf("%-*zd %-*zd\n", (int)strlen(first), strlen(first), (int)strlen(last),
            strlen(last));

    return 0;

}
