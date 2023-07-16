//
// Created by cmtheit on 23-7-16.
//

#include <stdio.h>
#include <complex.h>
#include "../asm_define.h"

ASM_DEFINE(dcl_mul, double a, float b) {
    return (long )a * (long )b;
}

ASM_DEFINE(dcla, int n, double d[n], long l[n]) {
    for (int i = 0; i < n; ++i) {
        l[i] = (long) d[i];
    }
    return 0;
}

int main(int argc, char ** argv) {
    float a = 3.14 * argc;
    double b = 4.15 / argc;
    printf("%f\n", a * b);
    printf("a: %f, b: %lf\n", a, b);
    printf("%ld <-> %ld\n", asm_dcl_mul(b, a), dcl_mul(b, a));
    int n = 10;
    double d[n];
    for (int i = 0; i < n; ++i) {
        d[i] = (double) i * i / 10;
    }
    long l[n];
    asm_dcla(n, d, l);
    for (int i = 0; i < n; ++i) {
        printf("%ld ", l[i]);
    }
    printf("\n");
    printf("%08x\n", 1077936128);
}