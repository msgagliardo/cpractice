/* A program for computing various volume measurements in the U.S. system of 
   volume measurements */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	double cups;

	printf("Enter the number of cups you wish to convert: ");
	scanf("%lf", &cups);
	
	printf("%f cups is %f pints\n", cups, cups / 2);
	printf("%f cups is %f ounces\n", cups, cups * 8);
	printf("%f cups is %f tablespoons\n", cups, (cups * 8) * 2);
	printf("%f cups is %f teaspoons\n", cups, ((cups * 8) * 2) * 3);

	return 0;
} 
