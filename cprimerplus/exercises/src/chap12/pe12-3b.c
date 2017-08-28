/* This file is a redesign of pe12-2b.c so that it uses only automatic
 * variables.
 */
// compile with pe12-3a.c
#include "pe12-3a.h"
#include <stdio.h>

int main(void) {

    double dist, fuel_used;
    int mode;
    int prev_mode = 0;

    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    while (mode >= 0) {
        set_mode(&mode, prev_mode);
        get_info(&dist, &fuel_used, mode);
        show_info(dist, fuel_used, mode);
        prev_mode = mode;
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");
    return 0;
}
