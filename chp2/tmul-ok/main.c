#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

bool tmul_ok1(int32_t a, int32_t b) {
    register int32_t p = a * b;
    return !a || p / a == b;
}

bool tmul_ok2(int32_t a, int32_t b) {
    register int64_t c = (int64_t) a * b;
    return c <= INT32_MAX && c >= INT32_MIN;
}

int main() {
    int32_t a = INT32_MAX;
    int32_t b = INT32_MAX;
    printf("%d %d\n", tmul_ok1(a, b), tmul_ok2(a, b));
    a = 100;
    b = 200;
    printf("%d %d\n", tmul_ok1(a, b), tmul_ok2(a, b));
}