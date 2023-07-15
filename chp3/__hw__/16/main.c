//
// Created by cmtheit on 23-7-13.
//
#include <stdio.h>
#include "A.c"

int main() {
    long a = 30;
    long b = 20;
    A_cond(a, &b);
    printf("%ld\n",b);
}