/* This program echoes the command-line arguments in reverse order. */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int i;
    printf("Here are your command-line arguments in reverse order:\n");
    for (i = argc - 1; i >= 1; i--)
        printf("%s ", argv[i]);
    printf("\n");

    return 0;
}

