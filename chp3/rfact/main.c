//
// Created by cmtheit on 23-7-15.
//

#include <stdio.h>
#include "../asm_define.h"

ASM_DEFINE(rfact, unsigned num) {
    if (num > 0) {
        return num * rfact(num - 1);
    } else {
        return 1;
    }
}

int main() {
    unsigned a = 10;
    printf("fact %u, %u <-> %u\n", a, (unsigned ) asm_rfact(a), (unsigned ) rfact(a));
}