#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>
#include <string.h>


int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 1;
    } 
    int n = atoi(argv[1]);

    int counter = 0;

    for (int i = 0; i < n && i < argc - 2 ; i++) {
        FILE *file = fopen(argv[i + 2], "r");
        char name[PATH_MAX + 1];
        fgets(name, PATH_MAX + 1, file);

        name[strlen(name) - 1] = 0;
        fclose(file);
        if (!fork()) {
            execlp(name, name, NULL);
            exit(1);
        }
    }
    int status;

    while (wait(&status) != -1) {
        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
            counter += 1;
        }
    }

    if (argc - 2 <= n) {
        printf("%d\n", counter);
        fflush(stdout);
        return 0;
    }

    for (int i = n; i < argc - 2; i++) {
        int pid;

        FILE *file = fopen(argv[i + 2], "r");
        char name[PATH_MAX + 1];
        fgets(name, PATH_MAX + 1, file);

        name[strlen(name) - 1] = 0;
        fclose(file);
        if ((pid =fork()) == 0) {
            execlp(name, name, NULL);
            exit(1);
        } else {
            waitpid(pid, &status, 0);
            
            if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
                counter += 1;
            }
        }
    }

    printf("%d\n", counter);
    fflush(stdout);
}
