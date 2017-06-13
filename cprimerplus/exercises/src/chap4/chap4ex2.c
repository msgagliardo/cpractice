/* This program requests the user's first name, and then prints it in various
 * formats. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char name[20];

    printf("Hello user, what is your name?: ");
    scanf("%s", name);

    printf("\"%s\"\n", name);
    printf("\"" "%20s" "\"\n", name);
    printf("\"" "%-20s" "\"\n", name);
    printf("%*s\n", (int)(strlen(name) + 3), name);

    return 0;
}
