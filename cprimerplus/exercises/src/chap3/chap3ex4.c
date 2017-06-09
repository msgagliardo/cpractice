/* A program for displaying a user entered float-point value in fixed point notation,
   exponential notation, and hexadecimal exponential notation (available in C99) */
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main(void) {
	double entry;
	printf("Enter a floating point value: ");

	/* If you don't place an "l" before the %f specifier, you
	   get the following warning from the clang compiler: 
	   "warning: format specifies type 'float *' but the argument has type
      	   'double *' [-Wformat]".  Why is this not a problem when printing?*/
	
	/* Why is the "l" modifier needed before the %f format specifier? The "l"
	   modifier is needed for the scanf function because it needs to know 
	   that the pointer that was passed to it is actually a double */	

	scanf("%lf", &entry);

	/* "%lf" is not needed in the printf function but it can be used without
	   error.  The reason is that printf is a variadic function, and there is 
	   a "default argument promotion" to double */

	printf("fixed point notation: %f\n", entry);
	printf("exponential notation: %e\n", entry);
	printf("p notation: %a\n", entry);

	return 0;
}
