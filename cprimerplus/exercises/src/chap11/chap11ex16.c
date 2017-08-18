/* This program reads input until EOF and echoes it to the display.  The 
 * program recognizes and implements the following command-line arguments:
 *
 * -p   Print input as is
 * -u   Map input to all uppercase
 * -l   Map input to all lowercase
 *
 * If there are no command-line arguments, the program behaves as if the -p
 * argument had been used.
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 800

int main(int argc, char *argv[]) {

    char input[SIZE];
    char option;
    int i;
    
    /* If the number of command-line arguments equals 2, then the program 
     * name is pointed to by 'argv[0]', and the only program argument is 
     * pointed to by 'argv[1]'.  If the string pointed to by 'argv[1]' is
     * not 2 characters in length--a hyphen followed by a character--then
     * it is not a valid command-line option for this program.
     *
     * NOTE:  The 'args' array for a Java program does not store the program
     * name at 'args[0]'.  Instead, this is the first command-line option.
     */
    if ((2 == argc && 2 == strlen(argv[1])) || 1 == argc) {
    
        if (2 == argc)
            /* Equivalent to 'argv[1][1]' */
            option = *(*(argv + 1) + 1);

        while (fgets(input, SIZE, stdin)) {

            if ('p' == option || 1 == argc) {
                fputs(input, stdout);
            } else if ('u' == option) {
                for (i = 0; i < strlen(input); i++)
                    /* Neither of these casts are needed, but I think it
                     * is better to be explicit.  
                     *
                     * NOTE:  In Java the '(int)' cast would not be needed
                     * but the '(char)' would because it is a narrowing 
                     * coversion.
                     */
                    input[i] = (char) toupper((int) input[i]);
                fputs(input, stdout);
            } else if ('l' == option) {
                for (i = 0; i < strlen(input); i++)
                    input[i] = (char) tolower((int) input[i]); 
                fputs(input, stdout);
            }     
        }    
    } else {
        printf("Unknown command-line argument!  Try again.\n");
        printf("Usage = ./chap11ex16 -p | -u | -l\n");
    }
    if (feof(stdin))
        fputs("EOF encountered successfully.  Bye.\n", stdout);
    else if (ferror(stdin)) {
        perror("fgets()");
        exit(EXIT_FAILURE);
    } 
    return 0;
}
