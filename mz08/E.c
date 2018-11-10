#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int proc(int num) {
    int pid = fork();
    if (pid == -1) {
        return -1;
    } else if (!pid) {
        int now;
        if (scanf("%d", &now) == 0) {
            return 0;
        }
        int pid_son = proc(now);
        
        if(pid_son == -1) {
            return -1;
        }

        printf("%d\n", num);
    }
    return pid;
}



int main(void) {
    int now;
    scanf("%d",&now);

    proc(now);
    wait(NULL);
    return 0;
}
