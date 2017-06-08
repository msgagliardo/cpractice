/* A program for converting a user-entered height in inches into centimeters. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	const double CM_IN_INCH = 2.54;
	double height;

	printf("Please enter your height in inches: ");
	scanf("%lf", &height);
	printf("Your height in centimeters is %f\n", height * CM_IN_INCH);

	return 0;
}	
