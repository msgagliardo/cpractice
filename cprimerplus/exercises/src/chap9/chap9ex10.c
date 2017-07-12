/* This program generalizes the to_binary function of listing 9.8 to 
 * workd with any base in the range [2-10].  The function is called 
 * to_base_n and it converts the value of its first argument to the 
 * equivalent value in the base given by its second argument.
 */
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

void to_base_n(uintmax_t  n, int base) {
    int small_n;
    
    if (base >= 2 && base <= 36) {
        if (n >= base) {
            int r = (int) (n % base);
            to_base_n(n/base, base);
            if (r >= 10)
                printf("%c", 'A' + (r - 10));
            else
                printf("%d", r);
        } else {
            small_n = (int) n;
            if (n >= 10)
                printf("%c", 'A' + (small_n - 10));
            else
                printf("%d", small_n);
        }
    }
    else
        printf("The base must be in the range [2, 36]");
}
int main(void) {
    uintmax_t num;
    int base;

    printf("Enter a decimal integer and the base you want to convert it to"
            " (q to quit):\n");
    while (scanf("%" SCNuMAX "%d", &num, &base) == 2) {
        to_base_n(num, base);
        putchar('\n');
        printf("Enter another integer (q to quit):\n");
    }
    puts("Done.");

    return 0;
} 
