#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int userData;
    int lastNumber; 

    printf("Please enter an integer: ");
    scanf("%d", &userData);
    lastNumber = userData + 10; 

    while (userData <= lastNumber) {
        printf("%d%s", userData, (userData == lastNumber) ? "\n": "  ");
        userData++;
    }
    return 0;
}
