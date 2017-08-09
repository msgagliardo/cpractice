/* This progarm creates a function called 'mystrncpy' which is a copy of 
 * the C standard library's 'strncpy' function from the <string.h> header
 * file.  It then tests the function 'mystrncpy'.  The prototype for the 
 * 'strncpy' function from that header file is reproduced below (The 
 * 'size_t' type is an alias for an unsigned integral type, and is defined
 * in the <stdio.h>, <stdlib.h>, <stddef.h>, <string.h>, <time.h>, and 
 * <wchar.h> header files):
 *
 * char *strncpy(char *__dst, const char *__src, size_t __n);
 *
 * Copies at most '__n' characters of the character array pointed to by 
 * '__src' (including the terminating null character, but not any of the 
 * characters that follow the null character) to character array pointed 
 * to by '__dst'. If '__n' is reached before the entire array '__src' was 
 * copied, the resulting character array is not null-terminated. If, after 
 * copying the terminating null character from '__src', '__n' is not 
 * reached, additional null characters are written to '__dst' until the 
 * total of '__n' characters have been written. '__n' includes the null
 * character, which means that if '__n' is 10, and you try to copy the 
 * string 'MGagliardo', the null character will not be copied, and '__dst'
 * will not be a proper C-style string (it will just be a regular character
 * array).
 *
 * The behavior is undefined if the character arrays overlap, if either 
 * '__dst' or '__src' is not a pointer to a character array (including if 
 * '__dst' or '__src' is a null pointer), if the size of the array pointed 
 * to by '__dst' is less than '__n', or if the size of the array pointed 
 * to by '__src' is less than '__n' and it does not contain a null 
 * character.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *s_gets(char *str, int n) {

    int i = 0;
    char *ret_val;
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
char *mystrncpy(char *dst, const char *src, size_t n) {

    int i;

    if (dst == NULL || src == NULL)
        return dst;
    for (i = 0; i < n && src[i] != '\0'; i++)
        dst[i] = src[i];
    while (i < n) {
        dst[i] = '\0';
        i++;
    }
    return dst;
}
int main(void) {

    int i;
    char dst[10];
    char src[10];

    printf("Enter a string that you would like to copy:\n");
    while (s_gets(src, 10)) {
        mystrncpy(dst, src, 10);
        printf("\nThe following characters were copied to dst:\n");

        for (i = 0; i < 10; i++)
            printf("'%c' ", dst[i]);

        printf("\n");
        printf("\nEnter another string or Ctrl+D to quit:\n");
    }
    if (feof(stdin))
        fputs("EOF encountered successfully.  Bye.\n", stdout);
    else if (ferror(stdin)) {
        perror("s_gets()");
        exit(EXIT_FAILURE);
    } 
    return 0;
}
