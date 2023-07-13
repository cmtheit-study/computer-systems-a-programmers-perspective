//
// Created by cmtheit on 23-7-13.
//

#include <stdio.h>
#include "asm_func.h"

int main() {
    long a = 2, b = 3, c = 4;
    printf("scale2：\n\tres: %ld, expecting: %ld\n", asm_scale2(a, b, c), scale2(a, b, c));
    a += 10, b += 10;
    printf("add4_sub3_mul2:\n\tres: %d, expecting: %d\n", (int )asm_add4_sub3_mul2(a , b), (int )add4_sub3_mul2(a, b));
    a = 100;
    printf("shl1_add10_shr2:\n\tres: %d, expecting: %d\n", (int ) asm_shl1_add10_shr2(a, 2), (int) shl1_add10_shr2(a, 2));
    printf("arith:\n\tres: %ld, expecting: %ld\n", asm_arith(a, b, c), arith(a, b, c));
    uint64_t x = UINT64_MAX, y = UINT64_MAX;
    uint128_t z;
    uint128_mul(&z, x, y);
    uint128_t exp_res = (uint128_t) x * y;
    printf("uint128_mul:\n\tres: %016llx%016llx, expecting: %016llx%016llx\n", *((long long *)&z + 1),*(long long *)&z, *((long long *)&exp_res + 1),*(long long *)&exp_res);
    unsigned long a1 = 300, a2 = 21;
    unsigned long a3, a4, a33, a44;
    asm_uremdiv(a1, a2, &a3, &a4);
    uremdiv(a1, a2, &a33, &a44);
    printf("uremdiv:\n\tres: %ld %ld, expecting: %ld %ld\n", a3, a4, a33, a44);
}