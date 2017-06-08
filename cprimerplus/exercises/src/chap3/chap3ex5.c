/* A program for determining the number of seconds an individual has been alive. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int age;
	const double SECONDS_IN_YEAR = 3.156e7;

	printf("What is your age to the nearest year?: ");
	scanf("%d", &age);
	printf("You are %e seconds old\n", age * SECONDS_IN_YEAR);

	return 0;
}		
