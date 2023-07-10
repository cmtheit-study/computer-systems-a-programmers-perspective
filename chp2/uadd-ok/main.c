//
// Created by cmtheit on 23-7-9.
//

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

bool uadd_ok(unsigned a, unsigned b) {
    return a + b > a;
}

int tadd_ok(int a, int b) {
    register int x = (a ^ b) & INT32_MIN;
    return x || !((a ^ (a + b)) & INT32_MIN);
}

int main() {
    int a = INT32_MIN;
    int b = INT32_MIN;
    int c = INT32_MAX;
    int m = 10;
    int d = -190;
    printf("%d %d %d %d %d\n", tadd_ok(a, b), tadd_ok(a, c), tadd_ok(m, m), tadd_ok(m, d), tadd_ok(d, d));
    uint32_t e = UINT32_MAX;
    uint32_t f = 0u;
    printf("%d %d\n", uadd_ok(e, e), uadd_ok(10u, 20u));
    printf("%d", -0x80000000);
}