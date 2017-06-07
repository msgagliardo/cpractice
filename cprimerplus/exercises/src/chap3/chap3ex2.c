#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main(void) {
    int_least8_t code;

    printf("Please enter a ASCII code value: ");
    scanf("%" SCNdLEAST8, &code);
    printf("That ASCII code corresponds to the character \"%c\"\n", code);

    return 0;
}
