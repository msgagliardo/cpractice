// compile with pe12-2b.c
#include <stdio.h>
#include <stdlib.h>

/* Exercise #2 of chapter 12 says to use ONLY 3 file-scope, internal-linkage
 * variables (mode, dist, fuel_used).  However, using only these 3
 * variables, how can the program know what the most recent mode was if the
 * user enters an incorrect mode?  This is why I created the 'prev_mode'
 * internal variable.
 */
//static int prev_mode;
static int mode;
static double dist;
static double fuel_used;

void set_mode(int m) {

    /*
    if ((0 != m && 1 != m) && (0 != mode && 1 != mode))
        mode = m;
    else {
        prev_mode = mode;
        mode = m;
    }
    */
    if (0 == m || 1 == m)
        mode = m;
    else
        printf("Invalid mode specified. Mode %s\n", (0 == mode) ? 
                "0 (metric) used.": "1 (US) used.");

}
void get_info(void) {

    if (0 == mode) {
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", &dist);
        printf("Enter fuel consumed in liters: ");
        scanf("%lf", &fuel_used);
    } else if (1 == mode) {
        printf("Enter distance traveled in miles: ");
        scanf("%lf", &dist);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf", &fuel_used);
    
    } 
   /*  else {
        if (0 == prev_mode) {
            printf("Invalid mode specified.  Mode 0 (metric) used.\n");
            printf("Enter distance traveled in kilometers: ");
            scanf("%lf", &dist);
            printf("Enter fuel consumed in liters: ");
            scanf("%lf", &fuel_used);
        } else if (1 == prev_mode) {
            printf("Invalid mode specified.  Mode 1 (US) used.\n");
            printf("Enter distance traveled in miles: ");
            scanf("%lf", &dist);
            printf("Enter fuel consumed in gallons: ");
            scanf("%lf", &fuel_used);
        }
    }
    */
    
}
void show_info(void) {

    if (0 == mode) 
        printf("Fuel consumption is %.2lf liters per 100 km.\n",
                fuel_used / (dist / 100));
    else if (1 == mode)
        printf("Fuel consumption is %.2lf miles per gallon.\n",
                dist / fuel_used);
   /* else {
        if (0 == prev_mode)
            printf("Fuel consumption is %.2lf liters per 100 km.\n",
                                    fuel_used / (dist / 100));
        else if (1 == prev_mode)
            printf("Fuel consumption is %.2lf miles per gallon.\n",
                                    dist / fuel_used);
    }*/

}
