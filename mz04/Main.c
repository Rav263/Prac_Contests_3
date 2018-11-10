#include <stdio.h>

void normalize_path(char*);


int main(void) {
    char string[100];

    scanf("%s", string);
    normalize_path(string);

    printf("%s\n", string);
    
    return 0;
}
