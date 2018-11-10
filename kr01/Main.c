#include <stdio.h>
#include <stdint.h>

int64_t extract(int64_t value, int bit, int length);

int main(void) {
    int b, c;
    long long a;

    while (scanf("%lld %d %d", &a, &b, &c)) {
        printf("%lld", extract(a, b, c));
    }

    return 0;
}
