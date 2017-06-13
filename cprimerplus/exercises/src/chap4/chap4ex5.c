/* This program requests a download speed (Mbps) and the size of a file (MB) 
 * from the user.  The program then calculates the download time for the file. */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    float downloadSpeed;
    float fileSize;

    printf("Please enter a download speed in Mbps and a file size in MB: ");
    scanf("%f%f", &downloadSpeed, &fileSize);

    printf("At %.2f megabits per second, a file of %.2f megabytes downloads\
 in %.2f seconds.\n", downloadSpeed, fileSize, (fileSize * 8) / downloadSpeed);

    return 0;
}
