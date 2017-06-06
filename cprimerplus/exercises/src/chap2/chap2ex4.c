#include <stdio.h>
#include <stdlib.h>


// alternatively, these functions can be forward-declared by
// writing the prototypes here, and defining them after the main function
void jolly() {
    printf("jolly good");
}
void deny() {
    printf("Which nobody can deny!\n");
}
int main(void) {
    printf("For he's a ");
    jolly();
    printf(" fellow!\n");

    printf("For he's a ");
    jolly();
    printf(" fellow!\n");

    printf("For he's a ");
    jolly();
    printf(" fellow!\n");

    deny();

    return 0;
}
