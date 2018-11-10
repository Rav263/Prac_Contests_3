#include <stdio.h>
#include <stdlib.h>
enum { BUFSIZE = 10 };
char
*getline2(FILE *f)
{
    char *str = NULL;
    char c, size = sizeof(char);
    
    if (!(str = calloc(BUFSIZE, size))) {
            return NULL;
        }
    
    int i = 0, j = BUFSIZE;
    while ((c = fgetc(f)) != EOF) {
        if (i == j - 1) {
            j += BUFSIZE;
            if (!(str = realloc(str, j * size))) {
                return NULL;
            }
        }
        str[i] = c;
        if (c == '\n') {
            str[i + 1] = '\0';
            return str;
        }
        i++;
    }
    if (!i)
        return NULL;
    str[i] = '\0';
    return str;
}