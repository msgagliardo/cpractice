/* This program is a power-law program that works on a command-line basis.
 * The first command-line argument is a type double number to be raised to
 * a certain power, and the second argument is the integer power.
 */
#include <stdio.h>
/* int   atoi(const char *);
 * double    atof(const char *);
 *
 * These are the prototypes for the string conversion function 'atoi' and 
 * 'atof' from the <stdlib.h> header file.  If no conversion could be 
 * performed, 0, and 0.0 are returned respectively.
 */
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int i;
    double result = 1;
    double base = atof(argv[1]);
    int pow = atoi(argv[2]);

    if (pow > 0) {
        for (i = 1; i <= pow; i++)
            result = base * result;         
    } else if (pow < 0) {
        /* This could also be done like so;
         *
         * for (i = pow; i < 0; i++)
         *     result = (1 / base) * result;
         *
         * But I wanted to avoid the division during each iteration because
         * it is an extra step (and because it makes the result less 
         * accurate?)
         */           
        pow = -pow;
        for (i = 1; i <= pow; i++)
            result = base * result;
        result = 1.0 / result;
        pow = -pow;
    } else
        result = 1.0;
 
    printf("%.2lf^%d = %lf\n", base, pow, result);

    return 0;
}
