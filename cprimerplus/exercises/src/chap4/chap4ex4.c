/* This program requests the user's name and their height in inches and then 
 * displays their name and their height in feet. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char name[20];
    float height;

    printf("Enter your name followed by your height in inches: ");
    scanf("%s%f", name, &height);

    printf("%s, you are %f feet tall\n", name, height / 12);

    return 0;
} 
