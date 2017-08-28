/* This file is a redesign of pe12-2a.c so that it uses only automatic 
 * variables.
 */
// compile with pe12-3b.c
#include <stdio.h>
#include <stdlib.h>

void set_mode(int *pMode, int prev_mode) {
    
    if (0 != *pMode && 1 != *pMode) {
        *pMode = prev_mode;
        printf("Invalid mode specified. Mode %s\n", (0 == *pMode) ? 
                "0 (metric) used.": "1 (US) used.");
    }

}
void get_info(double *pDist, double *pFuel_used, int mode) {

    if (0 == mode) {
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", pDist);
        printf("Enter fuel consumed in liters: ");
        scanf("%lf", pFuel_used);
    } else if (1 == mode) {
        printf("Enter distance traveled in miles: ");
        scanf("%lf", pDist);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf", pFuel_used);
    
    } 
}
void show_info(double dist, double fuel_used, int mode) {

    if (0 == mode) 
        printf("Fuel consumption is %.2lf liters per 100 km.\n",
                fuel_used / (dist / 100));
    else if (1 == mode)
        printf("Fuel consumption is %.2lf miles per gallon.\n",
                dist / fuel_used);
   
}
