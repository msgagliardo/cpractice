/* A program for determining the number of water molecules in a user supplied amount
   of quarts. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	const double WATER_MOLECULE_WEIGHT = 3.0e-23;
	const int QUART_WATER_WEIGHT = 950;
	double number_of_quarts;

	printf("Enter an amount of water in quarts: ");
	scanf("%lf", &number_of_quarts);

	printf("There are %e molecules of water in %f quarts of water\n", 
		(number_of_quarts * QUART_WATER_WEIGHT) / WATER_MOLECULE_WEIGHT,
		number_of_quarts);
	
	return 0;
} 
