/* This program is a rewrite of Listing 12.4 (global.c) that does NOT use
 * global variables.
 */
#include <stdio.h>

/* The 'critic' function has been changed from accepting no parameters to
 * accepting a single int* parameter.  The reason for this change is because
 * we want the 'critic' function to be able to change the value of the
 * 'units' variable.  If the formal parameter of 'critic' was simply of type
 * int, the VALUE of 'units' would be copied to the 'critic' parameter, but
 * then when you use the 'scanf' function inside 'critic' you would be 
 * passing the address of the 'critic' parameter, and hence storing the
 * next input in THAT variable.  When 'critic' returns, it's parameters are
 * deallocated, and so you have no more access to them, and the value of 
 * the 'units' variable in 'main' hasn't changed.
 */
void critic(int*);

int main(void)
{
    int units;
    
    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    while (units != 56) 
        critic(&units);
    
    printf("You must have looked it up!\n");
    
    return 0;
}

void critic(int *input)
{
    printf("No luck, my friend. Try again.\n");
    scanf("%d", input);
}
