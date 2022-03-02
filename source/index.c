#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) + secs;   // Get finishing time.
    while (time(0) < retTime);               // Loop until it arrives.
}
int definitelyNotAShell() {
    return system("/bin/bash");
}

void checkout2() {
        waitFor(5);
        printf("\e[1;1H\e[2J");
}

void checkout() {
    char in_buf[0xff] = {0};
    printf("\nPassword: ");
    gets(in_buf);
    if(strcmp(in_buf, "Sup3r_S3cr3t_p4SSW0rd") == 0) {
        printf("\nVerified");
        fflush(stdout);
        checkout2();
    }
    else {
        printf("\nUnrecognised password");
        exit(-1);
    }
}

int main() {
    checkout();
    return 1;
}
