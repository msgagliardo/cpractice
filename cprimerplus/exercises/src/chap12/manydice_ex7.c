/* manydice_ex7.c -- multiple dice rolls.  This program makes use of 
 * 'automated reseeding' by using the 'time' function in the <time.h> 
 * standard library. To make use of automated reseeding, you need acess to 
 * some changing quantity so that every time you run the program, a new seed
 * is generated. The ANSI C time() function returns the system time.
 */

/* compile with diceroll_ex7.c */
#include <stdio.h>
#include <stdlib.h>              /* for library srand() */

/* If your C implementation gives you access to some changing quantity, such
 * as the system clock, you can use that value (possibly truncated) to 
 * initialize the seed value. For instance, ANSI C has a time() function 
 * that returns the system time. The time units are system dependent, but 
 * what matters here is that the return value is an arithmetic type and that
 * its value changes with time. The exact type is system dependent and is 
 * given the label time_t, but you can use a type cast. Here’s the basic 
 * setup:
 *
 * srand((unsigned int) time(0));
 *
 * In general, time() takes an argument that is the address of a type
 * 'time_t' object.  In that case, the time value is also stored at that
 * address.  However, you can pass the NULL pointer (0) as an argument, in
 * which case the value is supplied only through the return value mechanism.
 *
 * The following is the prototype of the time() function in the <time.h>
 * header file.  On this system, the time_t type takes up 8 bytes (64 bits).
 *
 * time_t time(time_t *);
 *
 * time_t is an alias of a 'fundamental arithmetic type' which is capable of
 * representing times.  For historical resons, it is generally represented
 * as an integral value representing the number of seconds (not counting 
 * leap seconds) elapsed since 00:00:00, Thursday, January 1, 1970 UTC 
 * (i.e., a Unix timestamp).  The standard uses the term 'calendar time' 
 * when referring to a value of type 'time_t'.  Although libraries may use 
 * a different representation of time: Portable programs should not use the
 * value returned by this function directly, but always rely on calls to 
 * other elements of the standard library to translate them to portable 
 * types (such as localtime, gmtime or difftime).  If the object is not a 
 * NULL pointer, it also sets the return value to the object pointed to by
 * the time_t argument.  The return value is (time_t)(-1) on error.  
 * Implementations in which time_t is a 32-bit signed integer (many 
 * historical implementations) fail on January 19, 2038.
 */
#include <time.h>                /* for time()          */

/* QUESTION: How does the compiler know to look in diceroll.c for the actual
 * definition of the roll_n_dice function when the manydice.c file uses it?
 */
#include "diceroll_ex7.h"        /* for roll_n_dice() and for roll_count */

int main(void)
{
    int i;
    int dice, roll;
    int sides, sets;
    int status;
    
    srand((unsigned int) time(0)); /* randomize seed      */
    printf("Enter the number of sets; enter q to stop: ");

    /* This while loop can terminate for 3 different reasons: sets is < 1,
     * there is a type mismatch for input (scanf() return value is 0), or
     * EOF is encountered (return value is EOF).
     */
    while (scanf("%d", &sets) == 1 && sets > 0 )
    {
        printf("How many sides and how many dice? ");

        if ((status = scanf("%d%d", &sides, &dice)) != 2)
        {
            if (status == EOF)
                break;             /* exit loop           */
            else
            {
                printf("You should have entered an integer.");
                printf(" Let's begin again.\n");
                while (getchar() != '\n')
                    continue;     /* dispose of bad input */
                printf("How many sides and how many dice? ");
                continue;         /* new loop cycle       */
             }
        }
        int set_sums[sets];
        for (i = 0; i < sets; i++)
            set_sums[i] =  roll_n_dice(dice, sides);
        printf("Here are %d sets of %d %d-sided throws.\n", sets, dice,
                sides);
        for (i = 0; i < sets; i++)
            printf("%3d%s", set_sums[i], (0 == (i + 1) % 20) ? "\n": " ");
        printf("\n");
        printf("How many sets? Enter q to stop: ");
    }
    printf("The rollem() function was called %d times.\n",
           roll_count);           /* use extern variable */
    
    printf("GOOD FORTUNE TO YOU!\n");
    
    return 0;
}
