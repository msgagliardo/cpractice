/* diceroll_ex7.c -- dice role simulation */
/* compile with manydice.c           */

/* Enclosing the filename in double quotation marks instead of in angle 
 * brackets instructs the compiler to look locally for the file instead of 
 * in the standard locations the compiler uses for the standard header 
 * files.  The meaning of “look locally” depends on the implementation.
 * Some common interpretations are placing the header file in the same 
 * directory or folder as the source code files or in the same directory or
 * folder as the project file (if your compiler uses them).
 *
 * This header file contains function prototypes and an extern declaration.
 * Because the diceroll.c file includes this header, diceroll.c actually 
 * contains two declarations of roll_count.  This is fine. You can have only
 * one defining declaration of a variable. But the declaration with extern 
 * is a reference declaration, and you can have as many of those as you 
 * want.
 */
#include "diceroll_ex7.h"
#include <stdio.h>

/* The rand() function is found in the <stdlib.h> header file of the C
 * standard library.  It produces an integer in the range [0, RAND_MAX].
 * RAND_MAX is defined in <stdlib.h> and is typically INT_MAX. On this 
 * system (MacBook Pro 2015 - Apple LLVM version 8.1.0 (clang-802.0.42))
 * RAND_MAX is defined in <stdlib.h> as the following;
 *
 * #define  RAND_MAX    0x7fffffff
 *
 * 0x7fffffff is equal to 2^(31) - 1 in decimal (which is equivalent to the
 * maximum positive value of a signed 32-bit integer.  INT_MAX on this
 * system also happens to be 0x7fffffff so it is true that RAND_MAX equals
 * INT_MAX, at least on this system).
 *
 * The rand() function of C differs from the random() function of the
 * java.lang.Math class of Java in that the random() function returns a 
 * double in the range [0.0, 1.0).  The approach in C to generate a random
 * integer in the range [low, high] is;
 *
 * rand() % (high - low + 1) + low;
 *
 * This is almost exactly how you would do it in Java, which is
 * (int) (Math.random() * (high - low + 1)) + low;
 *
 * This is the prototype of the rand() function on this system in the 
 * <stdlib.h> header file;
 *
 * int   rand(void) __swift_unavailable("Use arc4random instead.");
 * 
 * QUESTION:  What does the __swift_unavailable("Use arc4random instead.");
 * part mean?
 *
 */
#include <stdlib.h>           /* for library rand()   */

int roll_count = 0;          /* external linkage     */

/* There are only 5 geometrically possible dice:  Those with 4, 6, 8, 12,
 * and 20 sides.  You could make dice with other numbers of sides, but the
 * faces would not all be the same, so they wouldn't all necessarily have
 * equal odds of turning up.  Computer calculations, however, are not
 * limited by these geometrical considerations, so you can devise an
 * electronic die that has any number of sides.
 *
 * rollem() is a function private to this file. It’s there as a helper 
 * function for roll_n_dice().  The static storage class specifier on a 
 * function indicates that it has internal linkage and it can only be used
 * in this translation unit.  It's like declaring a method private in Java.
 */
static int rollem(int sides)  /* private to this file */
{
    int roll;
    
    /* In C, the generation algorithm used by rand is guaranteed to only be
     * advanced by calls to this function. In C++, this constraint is 
     * relaxed, and a library implementation is allowed to advance the 
     * generator on other circumstances (such as calls to elements of 
     * <random>).
     *
     * srand() seeds the pseudo-random number generator used by rand(). If 
     * rand() is used before any calls to srand(), rand() behaves as if it 
     * was seeded with srand(1). Each time rand() is seeded with srand(), it
     * must produce the same sequence of values. rand() is not guaranteed
     * to be thread-safe.
     *
     * There are no guarantees as to the quality of the random sequence 
     * produced. In the past, some implementations of rand() have had 
     * serious shortcomings in the randomness, distribution and period of 
     * the sequence produced (in one well-known example, the low-order bit 
     * simply alternated between 1 and 0 between calls). rand() is not 
     * recommended for serious random-number generation needs, like 
     * cryptography.
     *
     * Generally speaking, the pseudo-random number generator should only 
     * be seeded once, before any calls to rand(), and the start of the 
     * program. It should not be repeatedly seeded, or reseeded every time 
     * you wish to generate a new batch of pseudo-random numbers.
     *
     * Standard practice is to use the result of a call to time(0) as the 
     * seed. However, time() returns a time_t value, and time_t is not 
     * guaranteed to be an integral type. In practice, though, every major 
     * implementation defines time_t to be an integral type, and this is 
     * also what POSIX requires
     *
     * DO NOT USE TIME() TO SEED IF YOUR PROGRAM HAS A CHANCE TO BE RUN 
     * TWICE OR MORE WITHIN A SECOND (WHICH IS LIKELY TO HAPPEN IF IT IS 
     * CALLED FROM A BASH SCRIPT). SAVE THE SEED INTO A FILE INSTEAD 
     * (See the question "How to Generate a Random Number in C?" on 
     * Stack Overflow).
     */
    roll = rand() % sides + 1;
    ++roll_count;             /* count function calls */
    
    return roll;
}

int roll_n_dice(int dice, int sides)
{
    int d;
    int total = 0;
    if (sides < 2)
    {
        printf("Need at least 2 sides.\n");
        return -2;
    }
    if (dice < 1)
    {
        printf("Need at least 1 die.\n");
        return -1;
    }
    
    for (d = 0; d < dice; d++)
        total += rollem(sides);
    
    return total;
}
