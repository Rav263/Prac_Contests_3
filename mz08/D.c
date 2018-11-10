#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int proc(int num, int n) {
    int pid = fork();

    if (!pid) {
        if (num == n) {
            printf("%d\n", num);
            fflush(stdout);
        } else {
            printf("%d ", num);
            fflush(stdout);
        }
    }

    return pid;
}


int main(void) {
    int n;

    scanf("%d", &n);
    if (n != 1) {
        printf("1 ");
        fflush(stdout);
    } else {
        printf("1\n");
        return 0;
    }


    for(int i = 2; i <= n; i++) {
        if (proc(i, n)) {
            break;
        }
    }
    for (int i = 2; i <= n; i++) {
        wait(NULL);
    }
}
