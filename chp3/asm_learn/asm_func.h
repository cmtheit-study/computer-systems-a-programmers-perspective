//
// Created by cmtheit on 23-7-13.
//

#ifndef COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_ASM_FUNC_H
#define COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_ASM_FUNC_H

#include <stdint.h>

typedef __int128 int128_t;
typedef unsigned __int128 uint128_t;

#define ASM_DEFINE(name, ...) \
long asm_##name(__VA_ARGS__);  \
long name(__VA_ARGS__)                              \

// return x * 4 + y * 2 + z + 1
long asm_scale2(long x, long y, long z);
long scale2(long x, long y, long z) {
    return x * 4 + y * 2 + z + 1;
}

ASM_DEFINE(add4_sub3_mul2, char a, char b) {
    char c = a + 4;
    char d = b - 3;
    char e = c * d;
    e *= 2;
    e++;
    return e;
}

ASM_DEFINE(shl1_add10_shr2, int x, unsigned char bits) {
    x <<= 1;
    x += 10;
    x >>= 2 * bits;
    return x;
}

ASM_DEFINE(arith, long x, long y, long z) {
    long t1 = x ^ y;
    long t2 = z * 48;
    long t3 = t1 & 0x0f0f0f0f;
    long t4 = t2 - t3;
    return t4;
}

ASM_DEFINE(uint128_mul, uint128_t * dest, uint64_t x, uint64_t y) {
    *dest = (uint128_t) x * y;
    return 0;
}

ASM_DEFINE(uremdiv, unsigned long x, unsigned long y, unsigned long * qp, unsigned long * rp) {
    unsigned long q = x / y;
    unsigned long r = x % y;
    *qp = q;
    *rp = r;
    return 0;
}

#endif //COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_ASM_FUNC_H
