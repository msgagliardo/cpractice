#include <stdio.h>
#include <stdlib.h>

void two() {
    printf("two\n");
}
void one_three() {
    printf("one\n");
    two();
    printf("three\n");
}
int main(void) {
    printf("Starting now:\n");
    one_three();
    printf("done!\n");

    return 0;
}
