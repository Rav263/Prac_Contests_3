#include <stdio.h>

int parse_rwx_permissions(const char *);

int main(void) {
    char string[100];
    while (scanf("%s", string)){ 
        printf("%o\n", parse_rwx_permissions(string));
    }
}
