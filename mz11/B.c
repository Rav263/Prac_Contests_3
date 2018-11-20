#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

volatile int mode = 0;

void sig_func(int sig) {
    signal(SIGINT, sig_func);
    signal(SIGQUIT, sig_func);
    if (sig == SIGINT) {
        mode = 0;
    } else {
        mode = 1;
    }
}


int main(void) {
    signal(SIGINT, sig_func);
    signal(SIGQUIT, sig_func);

    printf("%d\n", getpid());
    fflush(stdout);
    int now;
    int sum = 0;


    while (scanf("%d", &now) == 1) {
        if (!mode) {
            sum += (long long) now;
        } else {
            sum *= (long long) now;
        }
        printf("%d\n", sum);
        fflush(stdout);
    }
}
