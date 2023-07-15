//
// Created by cmtheit on 23-7-13.
//
#include <stdio.h>
#include "flow.h"

int lcnt = 0;
int gcnt = 0;

int abs(int a) {
    if (a >= 0) {
        gcnt ++;
        return a;
    } else {
        lcnt ++;
        return -a;
    }
}

int main() {
    printf("%d %d\n", abs(1), abs(-1));
    lcnt += 10;
    gcnt = lcnt;
    printf("nabs %d is %ld <-> %ld\n", gcnt, asm_nabs(gcnt), nabs(gcnt));
    gcnt *= 2;
    printf("max %d, %d is %ld <-> %ld\n", lcnt, gcnt, asm_max(lcnt, gcnt), max(lcnt, gcnt));
    long a = 8;
    printf("frac %ld is %ld <-> %ld\n", a, asm_frac(a), frac(a));
    a = 13;
    printf("frac_while %ld is %ld <-> %ld\n", a, asm_frac_while(a), frac_while(a));
    a = 14;
    printf("frac_w_jtm %ld is %ld <-> %ld\n", a, asm_frac_w_jtm(a), frac_w_jtm(a));
    printf("frac_for %ld is %ld <-> %ld\n", a, asm_frac_for(a), frac_for(a));
}