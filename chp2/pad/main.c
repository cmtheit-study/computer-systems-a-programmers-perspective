//
// Created by cmtheit on 23-7-9.
//

#include <stdio.h>

int main() {
    int lval = 0xfedcba98 << 32;
    int aval = 0xfedeba98 >> 36;
    int uval = 0xfedeba98 >> 40;
    printf("%d %d %d\n", lval, aval, uval);
}