#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>


struct Node 
{
    int32_t key;
    int32_t left_idx;
    int32_t right_idx;
};

int comp(const void *a, const void *b) {
    return a - b;
}


int
main(int argc, char *argv[])
{
    if (argc < 2) {
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);

    int offset = lseek(fd, 0, SEEK_END);

    int size = offset / sizeof(struct Node);

    int32_t *keys = calloc(size, sizeof(*keys));

    lseek(fd, 0, SEEK_SET);

    for (int i = 0; i < size; i++) {
        struct Node now;

        ssize_t r = read(fd, &now, sizeof(now));

        if (r < 0) {
            close(fd);
            return 1;
        }

        if (r == 0) {
            break;
        }

        keys[i] = now.key;
    }

    qsort(keys, size, sizeof(*keys), comp);

    for (int i = 0; i < size; i++) {
        printf("%d ", keys[i]);
    }

    printf("\n");


    return 0;
}
