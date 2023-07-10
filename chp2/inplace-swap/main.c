//
// Created by cmtheit on 23-7-9.
//

#include <stdio.h>

void inplace_swap(int * a, int * b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int main() {
    int m = 10;
    inplace_swap(&m, &m);
    printf("%d\n", m);
    int a = 1, b = 2;
    inplace_swap(&a, &b);
    printf("%d, %d\n", a, b);
}