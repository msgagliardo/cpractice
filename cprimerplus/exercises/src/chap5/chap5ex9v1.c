/* This program asks the user to enter a Fahrenheit temperature.  It then 
 * passes that number to a function called temperatures which converts it to
 * Celsius and Kelvin.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Temperature {
    double celsius;
    double kelvin;
} Temperature;

/* This function allocates a Temperature struct on the heap because it needs 
 * to return a pointer to this struct.  If it were instead allocated on the 
 * stack, the conversions variable would be deallocated when the temConvert
 * function returned, leaving you with a dangling pointer.  I made tempConvert
 * like this because you can't return multiple values from a C function, and 
 * you can't return an array from a C function (although you can return a 
 * pointer to an array).  Alternatively, you could create the struct in main
 * and then make tempConver a void function that accepts a pointer to the 
 * struct.  Also, functions can accept struct value arguments, as well as 
 * return struct values, instead of struct pointers.
 */
Temperature* tempConvert(double tempF) {
    Temperature* conversions = (Temperature*) malloc(sizeof(Temperature));
    if (conversions == NULL) {
        puts("Memory allocation failed!  Exiting.");
        exit(EXIT_FAILURE);
    }
    conversions->celsius = 5.0 / 9.0 * (tempF - 32.0);
    conversions->kelvin = conversions->celsius + 273.16;

    return conversions;
}
int main(void) {
    double userTemp;
    Temperature *result;

    printf("Enter a temperature in Fahrenheit, and I will convert it to "
            "Celsius and Kelvin\n");
    printf("Enter 'q' to quit: ");

    /* scanf returns an int which equals the number of items successfully read
     * or 0 if none were read.  It will return a negative value if it reaches
     * EOF or you simulate EOF by pressing Ctrl+d (EOF is usually defined to 
     * be equivalent to -1).
     */
    while (scanf("%lf", &userTemp) > 0) {
        result = tempConvert(userTemp);
        printf("%.2lf degrees F is %.2lf C and %.2lf K.\n", userTemp, 
                result->celsius, result->kelvin);

        /* Every call of tempConvert allocates a new section of memory on the 
         * heap and returns the address of that location.  Therefore, after you
         * display the result of the conversion, you should deallocate this 
         * memory using the free function.  At this point, we have a dangling
         * pointer.  You could set it to NULL to protect yourself if you 
         * accidently dereference it (?), but I immediately assign a new 
         * address to it.
         */
        free(result);
        printf("Enter another Fahrenheit temperature: ");
    }
    printf("Goodbye!\n");

    return 0;
}
