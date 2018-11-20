#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

volatile int counter = 0;

void sig_func(int sig) {
    signal(SIGHUP, sig_func);
    if (counter < 5) {
        printf("%d\n", counter);
        fflush(stdout);
        counter ++;
    } else {
        exit(0);
    }
}


int main(void) {
    signal(SIGHUP, sig_func);
    int pid = getpid();

    printf("%d\n", pid);
    fflush(stdout);

    while (1) {
        pause();
    }

    return 0;
}
