#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>



struct Task
{
    unsigned uid;
    int gid_count;
    unsigned *gids;
};

int myaccess(const struct stat *, const struct Task *,int); 

int main(void) {
    int a = R_OK;
    int b = W_OK;
    int c = X_OK;


    printf("%x %x %x\n", a, b, c);

    char string[100];
    unsigned gids[100];
    getgroups(100, gids);
    int size = 0;

    for(int i = 0; i < 100; i++) {
        if(gids[i] == 0)break;
        size = i + 1;
    }

    struct Task task = {};

    task.uid = getuid();
    task.gid_count = size;
    task.gids = gids;

    printf("%d %d\n", task.uid, getuid());


    for(int i = 0; scanf("%s", string); i++){
        struct stat stb = {};

        stat(string, &stb);

        int is_sys = access(string, X_OK | R_OK | W_OK);
        int is_my = myaccess(&stb, &task, X_OK | R_OK | W_OK);


        printf("%d %d\n", is_my, is_sys);
    }
    return 0;
}

